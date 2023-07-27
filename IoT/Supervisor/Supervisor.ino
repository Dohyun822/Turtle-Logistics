// Supervisor 
// 1. Rest(Get) -> Polling Every 1 min For get Order List , OrderNo, OrderList, OrderAddress
// 2. Rest(Post) -> When Order Finish or Divide Finish, Polling
// 3. MQTT -> Pub : /sup/add(OrderNo,OrderList), /sup/init(On,Off), /sup/div/info(OrderNo,OrderAddress)
// 4. MQTT -> Sub : /ord/res(OrderNo,Result), /div/res(OrderNo,Result), /web/power(on,off)
#include "TLClient.h"
#include <HTTPClient.h>

#define THINGNAME "Supervisor"
// PUBLISH TOPIC
#define TOPIC_INIT "/mod/ord/motor/power"
#define TOPIC_INIT2 "/mod/div/motor/power"
#define TOPIC_ORD_SCH "/sup/ord/sch/info"
#define TOPIC_ORD_VERI "/sup/ord/veri/info"
#define TOPIC_DIV_VERI "/sup/div/veri/info"
#define TOPIC_LOG "/log"

// SUBSCRIBE TOPIC
#define TOPIC_ORDER_RES "/ord/res"
#define TOPIC_DIV_RES "/div/res"
#define TOPIC_POWER "/mod/web/power"

int order_motor=-1,div_motor=-1;
unsigned long previousMillis = 0;
const long interval = 60000; // 1min

HTTPClient http;
TLClient supervisor(THINGNAME);

void checkmotor();
void GETorder();
void POSTres(const char* jsonData);
void Subscribe_callback(char *topic, byte *payload, unsigned int length);

void setup() 
{
  Serial.begin(115200);
  
  supervisor.setCallback(Subscribe_callback);
  supervisor.connect_AWS();
  supervisor.subscribe(TOPIC_ORDER_RES);
  supervisor.subscribe(TOPIC_DIV_RES);
  supervisor.subscribe(TOPIC_POWER);
  supervisor.publish(TOPIC_LOG, "{\"dev\":\"Supervisor\",\"content\":\"AWS Connect Success\"}");
}

void loop() 
{
  supervisor.mqttLoop();
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    GETorder();
    supervisor.publish(TOPIC_LOG, "{\"dev\":\"Supervisor\",\"content\":\"Get Order Lists\"}");
  }
}

void GETorder(){
  if (WiFi.status() == WL_CONNECTED) 
  {
    http.begin("http://i9A204.p.ssafy.io:8080/order/start");
    int httpCode = http.GET();

    if (httpCode == 200) 
    {
      checkmotor();
      String response = http.getString();
      DynamicJsonDocument jsonDoc(1024);
      DeserializationError error = deserializeJson(jsonDoc, response);
      if (error) 
      {
          supervisor.publish(TOPIC_LOG,error.c_str());
      } 
      else 
      {
        if (jsonDoc.is<JsonArray>())
        {
            JsonArray ordersArray = jsonDoc.as<JsonArray>();
            for(JsonObject order:ordersArray)
            {
              StaticJsonDocument<200> Data;
              Data["order_num"] = order["order_num"];
              Data["ProductA"] = order["productA"];
              Data["ProductB"] = order["productB"];
              Data["ProductC"] = order["productC"];

              char buf1[200];
              serializeJson(Data,buf1);

              supervisor.publish(TOPIC_ORD_SCH, buf1);
              supervisor.publish(TOPIC_ORD_VERI, buf1);
              supervisor.publish(TOPIC_LOG, "{\"dev\":\"Supervisor\",\"content\":\"Pub Ord Sch OrderLists\"}");
              supervisor.publish(TOPIC_LOG, "{\"dev\":\"Supervisor\",\"content\":\"Pub Ord Veri OrderLists\"}");
              StaticJsonDocument<100> Data2;
              Data2["order_num"] = order["order_num"];
              Data2["address"] = order["address"];
              
              char buf2[100];
              serializeJson(Data2,buf2);
              supervisor.publish(TOPIC_DIV_VERI,buf2);
              supervisor.publish(TOPIC_LOG, "{\"dev\":\"Supervisor\",\"content\":\"Pub Div Veri OrderLists\"}");
            }
        }
        else
        {
          StaticJsonDocument<200> Data;
          Data["order_num"] = jsonDoc["order_num"];
          Data["ProductA"] = jsonDoc["소고기"];
          Data["ProductB"] = jsonDoc["USB"];
          Data["ProductC"] = jsonDoc["휴지"];

          char buf1[200];
          serializeJson(Data,buf1);

          supervisor.publish(TOPIC_ORD_SCH, buf1);
          supervisor.publish(TOPIC_ORD_VERI, buf1);
          supervisor.publish(TOPIC_LOG, "{\"dev\":\"Supervisor\",\"content\":\"Pub Ord Sch OrderLists\"}");
          supervisor.publish(TOPIC_LOG, "{\"dev\":\"Supervisor\",\"content\":\"Pub Ord Veri OrderLists\"}");
          StaticJsonDocument<100> Data2;
          Data2["order_num"] = jsonDoc["order_num"];
          Data2["address"] = jsonDoc["adderess"];
          
          char buf2[100];
          serializeJson(Data2,buf2);
          supervisor.publish(TOPIC_DIV_VERI,buf2);
          supervisor.publish(TOPIC_LOG, "{\"dev\":\"Supervisor\",\"content\":\"Pub Div Veri OrderLists\"}");
        }
      }
    }
    http.end(); 
  }
  else
  {
    Serial.println("Wifi is not connected!");
  }

}

void POSTres(const char* jsonData){
  http.begin("http://i9A204.p.ssafy.io:8080/order/update");
  http.addHeader("Content-Type","application/json");

  int httpCode = http.PUT(jsonData);
  if(httpCode==200){
    supervisor.publish(TOPIC_LOG, "{\"dev\":\"Supervisor\",\"content\":\"Post Success\"}");
  }
  else{
    supervisor.publish(TOPIC_LOG, "{\"dev\":\"Supervisor\",\"content\":\"Post Fail\"}");
  }
  http.end();
  StaticJsonDocument<100> jsondoc;
  DeserializationError error = deserializeJson(jsondoc, jsonData);
  if(div_motor==-1 && jsondoc["type"].as<int>()==0 && jsondoc["result"].as<int>()==0){
    StaticJsonDocument<20> Motor;
    Motor["power"]="1";
    char buf[20];
    serializeJson(Motor,buf);
    supervisor.publish(TOPIC_INIT2,buf);
    div_motor=1;
  }
  
}

void Subscribe_callback(char *topic, byte *payload, unsigned int length)
{

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, payload, length);
  char res[100];
  serializeJson(doc,res);
  

  if(strcmp(topic,TOPIC_ORDER_RES)==0){ // orderno, res
      POSTres(res);
  }
  else if(strcmp(topic,TOPIC_DIV_RES)==0){ // orderno, res
      POSTres(res);
  }
  else if(strcmp(topic,TOPIC_POWER)==0){ // type : 0(on),1(off)
      int val = doc["power"].as<int>();

      if((val!=order_motor) && (val!=div_motor)){
        if(val==1 or val==-1){
          order_motor*=-1;
          div_motor*=-1;
          StaticJsonDocument<20> temp;
          char buffer[20];
          temp["power"] = val;
          serializeJson(temp,buffer);
        }

      }
  }
}

void checkmotor(){
  if(order_motor==-1)
    {
      order_motor=1;
      StaticJsonDocument<20> Motor;
      Motor["power"]="1";
      char buf3[20];
      serializeJson(Motor,buf3); 
      supervisor.publish(TOPIC_INIT,buf3);    

      supervisor.publish(TOPIC_LOG,"{\"dev\":\"Supervisor\",\"content\":\"Ord_Motor INIT For Order\"}");
    } 
}