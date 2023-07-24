#include <pgmspace.h>

#define SECRET
//const char* WIFI_SSID = "seogau";
//const char* WIFI_PASSWORD = "1234567890";
const char AWS_IOT_ENDPOINT[] = "a1s6tkbm4cenud-ats.iot.ap-northeast-2.amazonaws.com";       //change this

//String DEVICE_NAME_LIST[9] = { "Supervisor", "Ord_Verifier","Ord_Sch","Ord_Motor","Div_Verifier","Div_Motor","Div_Servo1","Div_Servo2","Div_Servo3" };
//String DEVICE_VALUE_LIST[9] = { "SUP","ORD_VERI","ORD_SCHE","ORD_MOTO","DIV_VERI","DIV_MOTO","DIV_SER1","DIV_SER2","DIV_SER3" };


const char CERT_ARR[10][1500] = {};
/*
AWS_CERT_CA[]
SUP_CERT[]		    SUP_PRIKEY[]
ORD_VERI_CERT[]		ORD_VERI_PRIKEY[]
ORD_SCHE_CERT[]		ORD_SCHE_PRIKEY[]
ORD_MOTO_CERT[]	  ORD_MOTO_PRIKEY[]
DIV_VERI_CERT[]		DIV_VERI_PRIKEY[]
DIV_MOTO_CERT[]		DIV_MOTO_PRIKEY[]
DIV_SER1_CERT[]		DIV_SER1_PRIKEY[]
DIV_SER2_CERT[]		DIV_SER2_PRIKEY[]
DIV_SER3_CERT[]		DIV_SER3_PRIKEY[]
*/

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate                                               //change this
static const char SUP_CERT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAOeI8jJXa50ubvdJtvE1vNAngXqWMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzA3MjEwMDE4
NTZaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDIwmDL5ZcclY4Ty4Rs
yZPmxC/jgYZPHnurqnFANn0cECIyJrLLWllZtw8LeuWQ6Yj2/Rj4uxdLP5oF/oM4
QwouJHPr82pUpK9V17OYxF4HkWxIaSYwEMgPck39Ki6JgDiEEVOvpwLqBRSkguYc
XhPuQVpTkdinFoZOLWW5KhFAxkRUBYXWE4DA5+1GoPm9QEdlrSbhLWYNAnkbbY5W
GhYA66e9aSMa/7MN8wD4f3ZHAmBiMlgFlvIQdJeSmKNiUkqSDFLmtZ+OPKA/PBIr
xqbwTWiLXSDAvt9xcAtnkXZ0sKvNB1dCSddYC1ZjmNQCQsnENO6/qAZBmUQWkBxN
t1+rAgMBAAGjYDBeMB8GA1UdIwQYMBaAFNQUctrmDpDURSy9WZiMqmy2dktAMB0G
A1UdDgQWBBS6N+ejIOKJTEf6aovsTPLBZE5PADAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAjQozRHmvp0okaYCdWTVCrHxV
ZqylIa4iJzdY1FqhvHRJWKVqjtWcjrPR3t0OzjOSdMwTyTUgYg9EkpVKflDASr/x
vu40/9JrQ/WtlbRc6C8t4gEPI9YXB12sVUOLwLAk0FP8fkP+uZiP6ShDXzipx8MF
C/wugZ6FRPTchVYGPqyQFhveHNxauDTcWhC78jzBvhmizVxuqk2XfPRdGaxWydeu
KYF0mE6HU3eu6WQ6DZk6wY/Nc6cMDugt9k8xb/ceRthgNptH+BE5Uuuby1yNWZqb
ULRpwx2wRQ3ygDFu//NYO+RGD8FBIyyAZpsp9cHvyKrNFSm/npHtbkubQFCh+Q==
-----END CERTIFICATE-----
 
 
)KEY";

// Device Private Key                                               //change this
static const char SUP_PRIKEY[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEAyMJgy+WXHJWOE8uEbMmT5sQv44GGTx57q6pxQDZ9HBAiMiay
y1pZWbcPC3rlkOmI9v0Y+LsXSz+aBf6DOEMKLiRz6/NqVKSvVdezmMReB5FsSGkm
MBDID3JN/SouiYA4hBFTr6cC6gUUpILmHF4T7kFaU5HYpxaGTi1luSoRQMZEVAWF
1hOAwOftRqD5vUBHZa0m4S1mDQJ5G22OVhoWAOunvWkjGv+zDfMA+H92RwJgYjJY
BZbyEHSXkpijYlJKkgxS5rWfjjygPzwSK8am8E1oi10gwL7fcXALZ5F2dLCrzQdX
QknXWAtWY5jUAkLJxDTuv6gGQZlEFpAcTbdfqwIDAQABAoIBAQC1gnCryK+AK4Ni
SE45YWM0cEpv4mqBXCkqQxbTnLAu0DNqrmxWySAhqg2TLpEiHNM1pA2QzO65nQ5v
vvX6xzoMD+8y9Eg9sQvJjBUX2Oq+4u9I5LCfIn0O4iS68QlUTjZKybOlC1XqKZ/J
QYQ1P6W7cyDsj9+W6hmR0x+2ct9YdI/WQRcv4lkjF8lT7bkzHRsNpEhkSPAP4InY
M3eCxo4muhoIwGeIp1F0ZZes3y4CyYt5AoxDDDUulZogabQiju48BWjb0tN+KBJX
A7oE7+1scSPgxVCT751ca+GBwYumVdTecn0a4PIhEyvE2gawPAVAE58alFdRIaVE
X3hxHKv5AoGBAOXed0IP5KCfXPiGpUmEBnr0BXGz8eeG2MXVI4EwLS0po6Ddhio5
X5ljn1fuZBLDrjv9KF+2yxooev5IrMyZneNFcIF3qtD9JF72w8jevCzoLHKbjpe/
QZZSe5aqMaklnyurJ1vnGT4fX2iHYDLv6KFFKbSci2M+rgbu3cpt6jFfAoGBAN+U
xpEob8Xi/LvDrC/l5m9HWzxJsbNO0c95rgPXQQMI3tZ1zNvehiEogoUI/RXmhQbp
76PRlmBySWUApaRl0EEKtLnedaIVW9eS+LY1SHBprqYPfxoiGFUizarSCesPXqrU
h1CoX+PkSHxiI5LBw5NCNl7SP484v2SnEJNg4zk1AoGBAJFOs+yax1eR5d9kng9+
2enXX6mkqoJFB7rnJO6BWc12yOzjm/ANHJWGGDApjjEeaYGaYm8+ydzbQgSERFeB
tAD64Ee3Mc+ydc9iBhlwU1u/2HkKRHVAfWFc+qsfIw1druSX6OV7jMVsZ49YJEOO
zGtFoTt+yc4OzUusq59PI//ZAoGBAJtHbJEsEFTTTMvrHg82EFCAsnCwjeYGe9ko
nR61xMUiyAESV3DsnyMwS1Wx5HPtYb5ngrO3wETDmw224VPIElbZ5KKiSfiD9QFH
ZczGPMU14MIcSR4RR+z4+vYEYjcKuajTahcumUphJaadUi9+uyHu/mvkgZgqxWJW
VUDGLYlxAoGAbOaFW4sv4eik6Q/GglEaiLVMP5MgJo8U/ZFEoPbFZ0ZUwWNpKf1y
hB2HrFuOVWyFe4zrWE3xHX8DTJauWxKj+kgrjmzGtW5yoIT76Ovcgg64aaz2Ezgu
PBm/d3P4cg5/6mwIwQH4957HaVmjaNKm0rMIkPwj8JaXZBdmVUzMQhk=
-----END RSA PRIVATE KEY-----
 
)KEY";

static const char ORD_VERI_CERT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAICqtW+EGSlaqVmJU8JMfeoh7nvvMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzA3MjEwMDIz
NDBaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDoLVLbRDFl5CplxCS3
yN6rUnVhE9rpLpdX8SNT3TxQIWAO8CG/NcfF+9QnW+11475BRJpo7DHLKbiXEEeL
JiAPY8EM93CaTSnIFow9RCjhj9OMSnDpQon0GWNMjE6Sh7xC6sSDF8g0Tiq8oS80
BzwlRm6XpWdiAxLYyFoa14V0eqIAI1Kmst28Ig+meQ3JRKQdgKa8HZoygH4xHYQO
DThoSVHKQuTwlXgSbUaiTqvnKjb3bci9wil0XFjkdTnhT9YIob/55fTwBsEVl1p3
931l6l6J7p5mspVCWla0dakg9TjB4xx1yb4aYRIjmgaWZVoaYYU7nDM7Zzhup9xB
IgKrAgMBAAGjYDBeMB8GA1UdIwQYMBaAFNQUctrmDpDURSy9WZiMqmy2dktAMB0G
A1UdDgQWBBTYAt3NjGRE9o3zttTIQfJJ97g2BDAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEASeAb++jQmxTIq8OW+onEWr2m
SPGiAeBn3+to2n5bcmIz/dyFTNpOG6pUTafSLzwWSrpM7BAiyiwdYnHeuDXAcJXF
prfzF7PC41ZpVwuMe+gGg7b1w3esU4WbaqcxzVVJMXh4/KxtZ1lPohapmmncHmwd
hBywPF7Nd4r/nb0RL8zyVap2ORAHMROFM19UpXDUbbESDeX5KKUquCCYDIiCB8zz
BeoKijkOwptCCoDmGmH64ePfw1mofBwuqZ+mK1BL0ALhlhycsdq4ZeVSirnYcw83
BFuU058d6ZzRlq0Vxv1+0irVOIvGOTc2xICLsLsL5knfVY4pPNAduuRbyatejQ==
-----END CERTIFICATE-----
 
 
)KEY";

static const char ORD_VERI_PRIKEY[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEA6C1S20QxZeQqZcQkt8jeq1J1YRPa6S6XV/EjU908UCFgDvAh
vzXHxfvUJ1vtdeO+QUSaaOwxyym4lxBHiyYgD2PBDPdwmk0pyBaMPUQo4Y/TjEpw
6UKJ9BljTIxOkoe8QurEgxfINE4qvKEvNAc8JUZul6VnYgMS2MhaGteFdHqiACNS
prLdvCIPpnkNyUSkHYCmvB2aMoB+MR2EDg04aElRykLk8JV4Em1Gok6r5yo2923I
vcIpdFxY5HU54U/WCKG/+eX08AbBFZdad/d9Zepeie6eZrKVQlpWtHWpIPU4weMc
dcm+GmESI5oGlmVaGmGFO5wzO2c4bqfcQSICqwIDAQABAoIBAF+d+teOWAGsW8GZ
a728nedUiD64nJkXtQBksLXjEOm3NQYx4tQKZAGnWpHzC/JXHo1moWjAjSksP3cH
H0+xHdb4sBKU/OyvBpv+nTbGEUgDoY3PQnzuCD5dDkYCKoGyINg2M0QB0VOpNXSF
tRjqOdzoCretSMxWk7ZvnJwdUjrLVVVQ/Sf3XB08TSYNncjiCZ2UkhoyLd4zlkB9
KVE866yCm1ePkPUchYodEpha5i3k2/9QvdgyzgpsORTxC/oy/lD/aNFgvpCxWp3r
GzCRYbpbn/ke9LgWUNyOliF23e5gxdr8eobDj8XzgtA8M05uSBxUdmInD707O7gP
MyaOFMECgYEA/wLN781GoOyeUjzZ7uhSCtVCHg0SvZq5JA9+sxigrpAW9oASjcYi
gsqBpnFaR4LscG6OnuO8wVxHLrAbX83eMBTwnY2ozOOi5XhEopfGj6LhldOcX824
1N31k52UDSBuO/8oLQj4pbmMnYQQuQXA8KmqaueJh+0szkKF4V6A13sCgYEA6RPZ
DWZASIdF4AeKGnkR1m0VDLBKsfHaeDKy7SAV0WebbsoTbOFJaF2nepREcMCiX9kz
31j7KRohAb/a5V7IlTOV4FfGQMpk7T6bzJM5dmLc09JP6ai1+1LaAlDc8tDeNYpF
uWy4mZGIXBQUDcgr2jrkVumoE+wbLl3h3nObApECgYA0qIKX+x6Timji+HfUMpsG
a6UciXyONI34mU6DcxlzEoP7YNTz+68SrPh6wztuOuXSDbJbsxE+KGz2gh0U+nDg
IuLQ1fi+Xl873Urm/EpfTLYidzD6Q4PgSPk2AzsYPtMkhnroWcrmhds4h5XgbwS5
bX+oVal7rQksimYU9KvMUwKBgBj3U0yoI0Khms6AgD6NsWdyj8qoJ5gf+/LcG2Zj
BXNE0dVwN9x11VMklQgAUcRyHfJ+ZZwK//xLHDX/wwbGvF2fBPLe9BGEnIL9Ldsf
+gvAUz8tS/oPZE7jdQ7Ccqhfzy2U/hr6llt8x0p1rCA9zNS3cjYNGT/pDpBM5iDZ
6UTBAoGARYaqv0GrwpMHmmK75RWztuUCy5ZrFW185WG9059hxlElnz4az2ESuxDw
cRqUKp6VFxVixPwhlBqu31AeMks++tgU6JVtGR3mL42ndEbgLKoluoyVmVUtNx/8
PuVpiR0gAfoHRI2nDtPfzT0wKfS3gYUz/1jpSAIyqZ2Wds5s7d8=
-----END RSA PRIVATE KEY-----
 
)KEY";

static const char ORD_SCHE_CERT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAPd5/AsnOO+d9FAEM6iMzKUwK8vUMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzA3MjEwMDI3
MDhaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDsqFd3UmjmV37zVaYe
DnRgmNLEe6axa06o8IODZ9I5dvU3Z8tkTVpVfT8PNAgEvcKxGi5I60Ktmu4DZuVC
tW7unYH1LIO6IQL3y6i+cQNvpUefoVBuLJvviNwoswcdJFUl1NX2tqL4ysJOHTft
T8rIhqEB3vXXMi6HNjPWufdDvMGy3nGOTwF/StVX9XPH0C2PfRLwkiMHYNc6LBTZ
oRlWcO018HvjiiPYbGrPUDHhmXOrXpLCy5I9/yMslOcC1bOCfFCMXdY2AfUVKHuz
QffZRxidH9wcLcn4Zu+vyMAtCMnE/ub4BQ+1TRtipUYe56dON6MwxksFp9wipxCo
iNpNAgMBAAGjYDBeMB8GA1UdIwQYMBaAFJ1ibdW7q0LjnGgUkc2CbABIN3poMB0G
A1UdDgQWBBRXG/HO72HXBd6hL4tYeTbqBXI0PjAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEALZz52ImykrL4+qH84qIXgf+M
Uj68ANOvjg9pL4sMD/joHfcKTETVAbaQd0KU2Zqg+0uzJM88dukNAT24gC4pXC8s
DQO94z8loM23ynqRM9ah1EhjcZKT5mnAhxiO4REaoD5mYKdSluOMdumikdQp1kBz
mpm9B9R1zNO+5qCEh228DwGz8iBotdiqdCHCQKjbJvuC0jRKZUzF5/xyPaTyFrnt
MquUkMYwDNFVCzO3KeMAk7PdXz/+ItlKe3EBH6Wd4G5eCbL5s1uZhlJIoYc8RVfD
/hxvKjCcV0haEwg31eaDasw4EgwjITLdmrpeRlngdSMQfT3Kc8z0Opqq6Wk5VA==
-----END CERTIFICATE-----
 
 
)KEY";

static const char ORD_SCHE_PRIKEY[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA7KhXd1Jo5ld+81WmHg50YJjSxHumsWtOqPCDg2fSOXb1N2fL
ZE1aVX0/DzQIBL3CsRouSOtCrZruA2blQrVu7p2B9SyDuiEC98uovnEDb6VHn6FQ
biyb74jcKLMHHSRVJdTV9rai+MrCTh037U/KyIahAd711zIuhzYz1rn3Q7zBst5x
jk8Bf0rVV/Vzx9Atj30S8JIjB2DXOiwU2aEZVnDtNfB744oj2Gxqz1Ax4Zlzq16S
wsuSPf8jLJTnAtWzgnxQjF3WNgH1FSh7s0H32UcYnR/cHC3J+Gbvr8jALQjJxP7m
+AUPtU0bYqVGHuenTjejMMZLBafcIqcQqIjaTQIDAQABAoIBAGOLwBbp7EQPw8+5
VEHKVLuZLPcHCCwS9ihr2vX4Qt53Ilim6VAMlZXmNBNCEKll5LI4UAXOJ+L8i2eU
7ZSs2re2O0cU7WfqoOP4n8dTpF1fCYyk/z8ItqMAT5MzEyf383URXNsFIfJC346a
Db9d0++babhuv7xAWH/5lb6ZxN+RhFOHCRogH9yqSQVzH70DJeku1merVMFR8qFq
Pcqx4MB/VQxpw24eqwJEAmx8cmAnQIzJEyPxabIstgETQ7Vj6Da7LtnSonLtnWjj
huvvadQcD7PeMHsqmFLg0sN8G9h6/B97nLvybAp/n6gPQtd/9fdiO1O005OmcVpi
YJU34+ECgYEA+iPuiwAqGPycsZlkA4fd1ZfbA8Wj/lLf3HBpzmcgxbKKydOz40Et
qMnRjGyPizNI4tyjdHNsiRtkqrQsSlBjYcsJtnsb+cOfsD5vzGZhMNtHgatt5ttT
YdFsMCHYLyZhhanp2PwJJQZjOeBaIQpPe3VY1oHV0Oi1jt9GXcPxvckCgYEA8jOO
D9UEMTA0rPHy447+fbRWG+wvHekfqs9JGBvAC9o0mDD25xsfHVHw4gC8L4LsKcO6
3kxbdrgju2/hlGEsy4yRgHSNjXXPWpee16CLxW1c2vfYAr5Gg+x2zzomLJi/6B53
CLt10f3EoaYcuQQc3tvxOgETpGiTRfv1QTPWKmUCgYEAp0JLiWqMu7R+WksFE09Q
SDiIXFdVtwNXaSFJvpg607b1EsuaZ4T3sPtyQQF+Ykfinr+GFKHxmyRUBckALJjg
O032qqxbIoFqUAEP5I84weB+SfiFPm69rJTKUMzwr2Zso2HgWhT9UGKbCuI3ogww
5Y6r3pNmk5BnhqdJd/1DsfECgYEA4L1N+QrkVPAyMLhhdR5ery4DKO3D2rFTHSAy
5xf44Aad/wqQUGouOPqr1kpwVHXbxfVFFLkttb+wCGEMpK527nmFGfkM0FKdEabX
UaY7i/qqytRnsEP3Err8k9WVTpR+nliGg6fO8AfVyVlmFZfnYjQcZoJRQ6F15t6g
+NuswrECgYATzT+XN+qpW/xlXCSZcMQI0VKSkBjiM5eIi7ryl2/hfkx1o8MhEULl
7oDfsgYx5gLAwulXmnghIVJITOxJIxB5hzna582lU7mBU2P+tjQqjzjjmxyAUuIw
AqdAdSo2f6fwScfyCpDgJoHdKp4dduJIrDoOI263DgPYAgvHrMHOEg==
-----END RSA PRIVATE KEY-----
 
)KEY";


static const char ORD_MOTO_CERT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUNrqMyUBY8WK/fV97j1eqbevNkIEwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIzMDcyMTAwMjkw
NFoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAN+yZ1lB5gUyyTHoRKg8
jRNUjzc3dzO6GXRhHoHvZery/2aLE12TJIzzeec4R7gdd23j8OM/0y8BbUT+Dvkx
PKgnzDzwnPqOB8vCSczrajrgJybpWXGKG64uXCyWWRToWAZRzhbdjNc7SfpOi5xA
MltlBUriz6Av2ERSEifNkXx2Z2pbDv5EYRakekINOHnQHNQgvpwjsQfhvXNrhQUJ
k3FoveyhrSvjGUIVGJ5yGIuNHh/kk7n3RM9PL4lGcjrM481nnUwEyG8RLvYtOnc4
lkmRtC2yBdon+2nGcphGeiwgwieTQ/FSdbEJ60GWSxyczmPoq2+UE0DcyyG4X5OL
LFsCAwEAAaNgMF4wHwYDVR0jBBgwFoAU1BRy2uYOkNRFLL1ZmIyqbLZ2S0AwHQYD
VR0OBBYEFLI6lyYOiKVdgQR/vD21CwQgw8WIMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQBJJrMf572K7GftTMy343wpSHIo
Hy3eNNR2lRk8cuIVhSjX1dwyq+4Qa5Wfca5QY2xqbhJAS8MJHF/Czht4T6YrbS7Z
T+o0mL5BJr63rMPIAVt6YrVPOmcyGIEYkVxRqIza4UkAMD4TrsPSeNNC1DgwgiCk
ysUloIELDU1I3r9gax1FM99hg07C5fVuCSDzRCMBvxMsUjDUxaAVUCZpD+0fqmsj
g3mrkoKqV9OnJlLA+upFR0WN3AHuqSMtFbV962czM3Aaxv3Q6SSYB1nLzmyN5e6n
Re0+ovnWCVyknQEu2jzb3wkK5K9oQlUjgzIQvuKWS5VVcs4QEj5NM3lD15/q
-----END CERTIFICATE-----
 
 
)KEY";

static const char ORD_MOTO_PRIKEY[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpQIBAAKCAQEA37JnWUHmBTLJMehEqDyNE1SPNzd3M7oZdGEege9l6vL/ZosT
XZMkjPN55zhHuB13bePw4z/TLwFtRP4O+TE8qCfMPPCc+o4Hy8JJzOtqOuAnJulZ
cYobri5cLJZZFOhYBlHOFt2M1ztJ+k6LnEAyW2UFSuLPoC/YRFISJ82RfHZnalsO
/kRhFqR6Qg04edAc1CC+nCOxB+G9c2uFBQmTcWi97KGtK+MZQhUYnnIYi40eH+ST
ufdEz08viUZyOszjzWedTATIbxEu9i06dziWSZG0LbIF2if7acZymEZ6LCDCJ5ND
8VJ1sQnrQZZLHJzOY+irb5QTQNzLIbhfk4ssWwIDAQABAoIBAQChTGrpGXNa3Dvn
GKwpA0BWZ+q8zenOCqrAGCd/WbgLqhwvPKlCGA+K8yU7bIGKaPTs8CeKNUN56XV5
AhiZ5r7uIYRLjNQkdrV4XygH8tgui+KvVCOCkytSdWtRWzfws3iFVgdcxXQA3meB
bZGNoVyuOjGOxe0gfF9dJDCjMr9tFjpp+pOblxO+tDyE6+FAPi/x+re8MVXhThyN
qWngNYY7eVmsrRADJZzkpSO6pXPdVU0ej8jFQGyXvgL/KNgG7YA1rymLn6r2Er3t
W96zH/YcVcJq90XNOPSHea4EJ2LgxUsXt0idfUNyDMcdvlymKHgxjaipNIZjFyH9
hnBlAXHBAoGBAPIDHcFVK2g0n+qSVAQDwMMa/4sBtjx2Cu0bL24snLh/VsfITo6R
E2bcFTDIyzLOwbSak/KLnNlvoyvMzw2hUXRvb9ZGUs5LXvJDqJA6WvGeSWVrQxu4
6/G+uunsCY39jVcyZH+K3xUuvJ2Boveqb2PlkoiRPo6W/cl8LJY2GnhdAoGBAOyg
SgO8MftolWyTdvNNG7NuyjZLzk4zbSqZH5M3xeF7+aoBynK5NFQU8h844/gkJn8J
/ZjKGuAVSgL4r5t3mtwsLOocfBJguqqaXnY8sx8ewiOA+6xvVkqWNX/Bv3aPheAT
B6yU4Kvg0mPAhw27vQFM2wsJ3G7StZc5wtZvPgwXAoGBAK8lvjUbNIz3+PxE5nT5
WlpZgbPSi1b6fzHWSN9NfiawUdfIicH4ELiScuuZhiXBKMNSU9xnWh6rAsZCNV9B
7rd7ps7GmkselRp0CNxIv2S6D5hMpoa7sFaGmLOO1eNjKxV+LOl5UbX82xiKp6zi
NjdwADrCEyoS8J0PNx2HDmUpAoGAXvnjW2ZxZWjP+Rmjd/quMLI6Zdq9fvPzUFLP
sqaDPYMmbc90M+IUl98kY9XQ4uuXrAwVhvswGFtTLqgkzDEQrmjoyjsOrc23fvyh
B7JLbyVIZTnDSq4Ro7Rw2suoju0CnjLlNKc5GqQNrk47pw6AyYHQtbiKisz2aDGd
+7YA4JcCgYEAt1OF8pxlJpW/JV22skCbovwqfU3fO4r6w6Tk/p6bD7Olau+IYFUN
EMon0sAEYuce31J7fc1Qxf8BtBWkVK4sAux+aFAVbTFnQFcy/l1+Ryaog+aqlgXS
Twhiu6843mI4xdKbpc7zwzvjUA2gzGOYzUHNl21tTcxNSzWYnsR16EE=
-----END RSA PRIVATE KEY-----
 
)KEY";

static const char DIV_VERI_CERT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUPKoNKDP2wvXx7Ygyf5MY+U+j804wDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTIzMDcyMTAxMTAx
N1oXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAN7WLJqkwCup8Yfu0AQ/
4iWkaDgL3kEOXRuP0HiJI8euORHC2kH/SaphBGQnmEq2shKjpTA/xsYJaND6aRnN
ipv8BN2Qnusqn2Ze7LgEMal8HcUFCB/SbGE9lRiNMRqdOHEwLTD4bUohKB8/bmXR
YxU8OUSjLYG3dnKja94wOjEc/qJ+DQbN9opc9FDu/Frl+CeBo6XtcILYGZfZsYkf
/tku6aEPLSMYBE8LsvYqXeLsAWImhOnJF+1yv2E2P0PVJrVcm24Zi1ZAX/BdhlSs
+8ipP8NfpsSyhOLn1DFcJu1XhhWdWK8oVUJkA3N5QVswSJnCczA5yjnpYgGNX3yY
e3ECAwEAAaNgMF4wHwYDVR0jBBgwFoAUp2kpuaE3nMXzc/1fEvT+l0HRAKowHQYD
VR0OBBYEFDDhyqioes9g0lGAMyKj3gP1L2ChMAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQAL8v/PobzZsGyG1ZO9hKYRmipr
7bqdsC9XpleGTuBnlSQrug0NmO+RPDmaaYtbigNTw0PWtzWyc71eCv/QMz4Vx0Gx
QO40q9GTIGfDydUxlnTAQcdiQmhM6RX2bZ3ikdwdBO6x2x9czIU8Sr/TRSZbaJ2B
XR6pq0CJHv2f42KSirg5inX8hpFpxuuWIJVEkB2Z/VDCAn72UsEwNcJEwKWZyfDq
rykxvWzzTOTsQdjj5d60aiqwLjgdAYWLwTGLr/arH7WMevArMuqESfprS3WVCBhn
GFNbZauh2fDUr8MIx1D5zaCEN7Olvxmpj11fzbivd0bc1NHC77yogqOf+a5Z
-----END CERTIFICATE-----
 
 
)KEY";

static const char DIV_VERI_PRIKEY[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEA3tYsmqTAK6nxh+7QBD/iJaRoOAveQQ5dG4/QeIkjx645EcLa
Qf9JqmEEZCeYSrayEqOlMD/Gxglo0PppGc2Km/wE3ZCe6yqfZl7suAQxqXwdxQUI
H9JsYT2VGI0xGp04cTAtMPhtSiEoHz9uZdFjFTw5RKMtgbd2cqNr3jA6MRz+on4N
Bs32ilz0UO78WuX4J4Gjpe1wgtgZl9mxiR/+2S7poQ8tIxgETwuy9ipd4uwBYiaE
6ckX7XK/YTY/Q9UmtVybbhmLVkBf8F2GVKz7yKk/w1+mxLKE4ufUMVwm7VeGFZ1Y
ryhVQmQDc3lBWzBImcJzMDnKOeliAY1ffJh7cQIDAQABAoIBACrJpTbse5nmv+IC
ER8/xQTFVN2uKbcEMwyfyL/cVWp6IasvZwlVI6f7iQRSNgPioL7DfWyOUnSkSeQW
sSerN/pLogOJSXqObJ0TjRCofYC1vGGgXbb+iKEDWiWkttENb1EMlyDYEuQxCas2
WtRiKExji/uJ+ar2t1+70XKQgBv9wYxNf5dpSpni14wqoksREuLTTSskylp4i/Wg
iNowAn0qUQ24ZwxCJ/OfuyZqcSQExTKuERWy+AKMJsE4IMBpkl3KmhwyrDLHQfrX
c9heDkW9EyoF3AXrjnYGT3+bMPPw++kM7zHGBKHL4qIGBrTvFSKPjWmlO7jHdRR6
DJ0jGiECgYEA8ZeUWe5vqSsw7UUTgDEmdtHOzeyBa669OsfK7ez5r+bGHW16+C5h
ylWiCFSNbmC1ZvuB+4PBLJ2G7bV7aXvR3/4yGPFRLAKkSuPgyjcUHbokSxzTGRMW
i+BRqYbPauE58I9vawW57aF036za9GPYQLNAUjGI3aetDQj2DnFjFvsCgYEA7CBA
huQb3Fx1EkvFtVV1VaOw4cyWDu8P1eYZiUqYn7oAWcpAnvjBiHaSNx59C9uagS+7
FPVT9+Tpg5snBXR6Bkfowx9E3YHCZMB0n80pafD+gkIdHKvCSq013wgS/Snb1msl
deglM424NEF6e0nmt6IPOwKLDsnUixXnM+3B24MCgYA/kjBSPcCaFihott17xPMn
Huw5GXuwtylJ91q5orrNA3+sLKvH9IR89m2NnZodqkrxj0rTwQaq08S2diPETPWb
6EqMb6t5VjSfFDmJXFbpv5pfPXV6yqALLHqwji20JRHW8BdUZQxYsDyNwvFWj5NO
6xwIxMoL8VxC6tG8WS/G0wKBgCx06hE7k29KzRPzxjac72l/V0c8EKihI/ceyoIJ
1HCGQZimNsJ3jWCXCnJsQBjicNWP2gZZJkUPCVQo+xDQ3ESgd1d9ZKbbznDPt2V6
6Cg1IoX90qNaR0tuDy19xK17mxNkuvnXCmIJdbwI8/mQcWrzjTCMCwhuwaCqMAyb
4BrnAoGBAIgT0kywe3J6tHfpX4RtO92nFd0rx62zsm9mSDxfl/+O+GxwnVS0sqKJ
QTGrDxBz3841H5Sh7WLXq6ZXuhVcV6QK9xCSJ+RLfGwW1yzZI2ak9bkl+9IcwyGt
+mfwwKFjQVjfE8nMMSUgmS2BH9bd8+6/8YHk7NGiefeM09RwOGOM
-----END RSA PRIVATE KEY-----
 
)KEY";

static const char DIV_MOTO_CERT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVALbIDd3N5NvGQbsaOYQ4RFKTDVXXMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzA3MjEwMTE1
MzBaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDwjQP8udALUqwLP6aI
FIvfYl+8WFeK4dskyUgOVaU05Mqv4/yUMQ1xbittg9qMitCUis30nEDPO1Tc1f/4
TPFWSPdYOS9LyU1rGEAIvZqpUhE4n0+12IDAu3XE7DQvLg23ZCGdwsfqa1/BAMOq
/m+8XebbKtiYWMJzboBY1cvZqpFKn1tsIptU2ExJeROz37DzsXruxlsOFzdGZpBX
tMRdxfQVoeJjFp8PO23xPz+mICKFIGY43rDrvQcBgwJSmEuBPn6WUi509CHmbQ8i
t0UYuovy+/uykFUb2kgLSbo7pEPibBrpDRUxwbbi9H9HHDwEUjOTHAnwl88rSxhh
K1MVAgMBAAGjYDBeMB8GA1UdIwQYMBaAFNQUctrmDpDURSy9WZiMqmy2dktAMB0G
A1UdDgQWBBQT1Ig5R0N+JhsfmmkXgV5e0URQADAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEASLRnM6dasxBMKyYFhSqSVQ9E
xim6xGhOTL1MiDEwi7v7KKn/66iB0jy2E3MGesGDCBVayl9HSP8pO/x+QnUbUP6m
9RRuj7TDqK3Z76kAZ+IMYW4/unpbx92njzMw1VBv4rtiZ1eUvtrQKxxsm6f2RTiq
NCQLK31LSDkYuH81IA8+e5oxZq+BnWgfOrp+wvW+EXPWBH1MFvTs02K0CFzTwR/y
S+GpUwWi6ecKv+JPp/5blNT6Ud9D3S/isZm3ERcIWCiKeEp2kdC8x4SEJAXW/pUl
8JF5WBD3VGGT5/7fNAcHkwycjQ/6ypA2OvQV9Pw+BwQSHhJF0DH8+9fqUy/3MQ==
-----END CERTIFICATE-----
 
 
)KEY";

static const char DIV_MOTO_PRIKEY[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA8I0D/LnQC1KsCz+miBSL32JfvFhXiuHbJMlIDlWlNOTKr+P8
lDENcW4rbYPajIrQlIrN9JxAzztU3NX/+EzxVkj3WDkvS8lNaxhACL2aqVIROJ9P
tdiAwLt1xOw0Ly4Nt2QhncLH6mtfwQDDqv5vvF3m2yrYmFjCc26AWNXL2aqRSp9b
bCKbVNhMSXkTs9+w87F67sZbDhc3RmaQV7TEXcX0FaHiYxafDztt8T8/piAihSBm
ON6w670HAYMCUphLgT5+llIudPQh5m0PIrdFGLqL8vv7spBVG9pIC0m6O6RD4mwa
6Q0VMcG24vR/Rxw8BFIzkxwJ8JfPK0sYYStTFQIDAQABAoIBAGcjz4XZFf8E34ej
LwBB7wdE4s+bAU4nMRNAyoh66G8Zel6YXoAb2Cu+lRhL5LVF/9DxAwXSyWcRhX16
tFn+g6v/dS56tnDES1GUAEC/K0VWTtP8Wu0Ze3sn5YMd0/I2yOLNKCzAi39TsqbK
cRssJTSa/pUSdfQ8eoOL6bQtV05oIzpb8eUFfxTsxxAiy/xd0PZvlUjo4OcObG8r
TkOqD1PVIPdgHJ7HPx9gEMQrI2kmCdMod4GVSXk7GOC+dxsjBk9ta/KFz3MARyQS
B2Nlh4eJeVh35cgbjDwa7qJ7EPwByK3AxUAlk+zZDBJboMNiqgfY3VVB6f6yGO0L
E+8RFAECgYEA+w9GTanpXYQOXwCYqEvxhzKSCYX2HLpDl0MQCOZCeDJa1OpWg4kI
Wv6ERLy3oKk0zb8zjRr6LLh+Q7mvIDI8vkwuV+hvhb4bJHVKs3tO0wRYqKubBVnz
JgKMeLjxu8+QS6Cp39QY8036Vop5/cFV5To13RtNgxgEyIjLXf9p2EECgYEA9UjN
XzuKy84hPYUiMejFMOUDNBxXBfQQqzjyDCKe+9X1oLaZgCtSLNQMUqxZfX7ttYzf
qyVIcm4qX3gnoHHSJ5+CsRVvfJOTL3j+r9tUFbD2H3ZNxg+4JbyRh3unE4e2Mzkb
4qq87FXeG3od2AG3fpjQ0hgLwUF86NVoSZOZJdUCgYEA2lNOL/uylUBhvvwlxTVF
tOylUuLMQ+83GDOZniOfaidgFggzc++W9IqhO6VhirWa1dGQYwUyyfEm3H59bOJD
MLnPE2NumD/aGrplW++/fIIrF4MkLGMsr8FHpzQuA8VdFmeBUsR/bhZBvUBvFd0r
dUxJyx4TKg2ZG0raj8OtqAECgYAG5smAiHhbS617wac4qEgEHC1+5d08+aUObEfD
N6Yph9elcf3XsWBaiozeNqM9+LhPh2szsZTcQ2VF0merCAjVvJM80FGWu8BEca8Y
257+DUCfmgCONhsEVM3zdfM5hXQG9PBn7E3siG37b/AvB71V/o7BmpOaGHGfS4Hn
sBN7EQKBgQCe1XaowCSf4OcudKZAs7s7ly2EKu4ZER2310L1cIbDiT3OE+uPzmeO
aTDWGHRKgLF+Y5bzNQGpSeq4b7OcxayuGVFhTqFGNa6gCGW+WnEn2lzb8NiWslRh
Tt0IPKbSVR7cwoTmeI2RoO+FegmStvTss62e6UwJenyRM6j84MVSvw==2
-----END RSA PRIVATE KEY-----
 
)KEY";

static const char DIV_SER1_CERT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAPbFXSqq4i74IVV52xfuwuj7E3B1MA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzA3MjEwMTQ0
NTNaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDZ/p1JDj1Ro5ZLPkkR
BgQ5Yu8kTXi68EO8H0DE0FEOUEtxQN7yL+neERTIoN3kNgD0nNEXlhasdf0ugVor
FZFQoilH4eO59xRsaWMYPFOCt240Udd/w7UfVnit45solnNRi4xKWPtpF7H0EyZg
QPFcsfj3SP9RwN4MP9sKRxBf2vxpSPUAZMBRPth2zQpbsP3ZVafCyGpTj9BaSWNG
r7r+jo5BGg8Ue66myF7LStpXctx5Ha0lypZMlC45e3o/8nkNf2Pqcoq6EGpeHbUE
htzL+2lceCeup1ywzco9OaYATZKkCttLzl5E2+hiMUjKR0atdEFMI3hYMmXxdqUy
+LsBAgMBAAGjYDBeMB8GA1UdIwQYMBaAFP91j3TATrn7r5aB4Jda5lOKeroqMB0G
A1UdDgQWBBTTNWH5QgWlVsw8oR/SIcuyMBs/UzAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAOjHJV7h1zsofzOEs04wFiXCK
H9Y4ZOTm+4x9YA7cNUqhH8C50wwm/SjK+YGvGnI2u3s86l+KZEcRjEk9syty+huV
KzNhaRmh3Xkjfj+l9GlYkyKkgAj8rJOMdS4cBuWZVvXNgBqnD6qNNBDZDfFMD3U6
mjr1Ji47/XpA3GN/m4phiJgNhSLayS80SxqLl77TJ2azcQjpcvsuEvEvdAk7nPBX
xvl7URIeHlh+OGrkaOm1cXhnU7RUiw8Bd/E1xEWfULY9kgHxcExxcNRdcV81NGGA
HwyDHxZaiPxcwH4o0ZlU9/UkwLPHucN17S7wvUfleM4LN+i8tp5kI4XYIJXWZA==
-----END CERTIFICATE-----
 
 
)KEY";

static const char DIV_SER1_PRIKEY[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEA2f6dSQ49UaOWSz5JEQYEOWLvJE14uvBDvB9AxNBRDlBLcUDe
8i/p3hEUyKDd5DYA9JzRF5YWrHX9LoFaKxWRUKIpR+HjufcUbGljGDxTgrduNFHX
f8O1H1Z4reObKJZzUYuMSlj7aRex9BMmYEDxXLH490j/UcDeDD/bCkcQX9r8aUj1
AGTAUT7Yds0KW7D92VWnwshqU4/QWkljRq+6/o6OQRoPFHuupshey0raV3LceR2t
JcqWTJQuOXt6P/J5DX9j6nKKuhBqXh21BIbcy/tpXHgnrqdcsM3KPTmmAE2SpArb
S85eRNvoYjFIykdGrXRBTCN4WDJl8XalMvi7AQIDAQABAoIBAQDBRFo/5c75bTYX
OX5gCFyAYDUykzjBS7hRtcefdi0WqptoKiI+x7no9m3dvblb1YEdXVaHObqaZfT0
YRwG7JUrzskYgK18NxE1WG3Rk9JaJrQe0JxlGqaexPQy/oKWBmTw2+6iD6e9sZNE
mCHC3nDeRK881cv+uCZk58wTnZNn1sRSWh0Qz0GJwI5yJam48a1dYlhYVhnvzwmy
IHqKoXnK6Ck6us1vouPkFjytiMEzJkXna3vsaCLthJtVksVBMCb0q6y2zMD37p+T
9rZ7NeDzOR5i56jnovXpiYpbM+7+fWT9fCQYn3FPryylbMoz5pebNjWyMP5bZkOh
wDLSksZBAoGBAPDMUSBOTlHAwaOMaJoUmru1O3RYyEzrhs7uiFk39DEYUqEdwR7c
H9uYvo+L/bvhpt2OxfE3O6dTXXuytePiVXQmz0D1k/Kw3gJ/WHZzVuGASembO21g
9ohVJwHPFJGxRRQTYIlmMhxjrXxix6Xtpqy5SX2qTzMFwme5pff+XOQpAoGBAOfB
wYnlV0Fgc00cLebuoYZ38L3qxrDQGG/7yxB3vo4NcEgnFEHkQ9Ki6TlbcvaInxlE
0420dgHoT1zVf0lXORCQg2js9W952Jnd1cuwzrb57VV1GhR+CtzyjK2TtpgqDnwB
eaPknd2lzeqeQlUJQZ2CoERym30Ybz+QGSk66TsZAoGBALgzQ5fX7veA4V/Pp7C+
NEOE9o8g31BgF0ayl6DQOb9YoNTY4wNNVh1w8czzRMz1Z+UyM187ZimwjuFyKsvB
NqdcjMxfT6al/56fdbdescZcka3e7o3UT6KoqOcsVsrAdVxPGljg0VKAOZTeJ2VZ
r1ePgZVcs6sPK9CW5kwXy01JAoGAaeL9wTo2lpkxtP51/nfy9tQf+zWkWC6Lq8Z4
Ler39kEvlte8Cqr3Teq+8kTVDsy3HD11Bt53uEFi2UB2apTebrIISE1Tif46t3pC
b1E18SXZiNz68HfyEKcFHV1K5NT6TzABWp9efWF+5n4uQln7T7LZ9MwEPLCIS5tT
06Gl5CkCgYAEHtoitcCnfx5jyrQ7gzcaeNV+gu16aA7VSEDDZWxEW9MJN8Bl6+7u
jS1CrFVqnxeQHHKKgIOrnxUXVBLGtITn01RXY8yFstx5oiRvBSOlCSbGvVvmRXmu
eYumVuypuETvhc+MJcBbpB88Z8i2AEPqNBHZ9lhAzuhAU2syu9ljUg==
-----END RSA PRIVATE KEY-----
 
)KEY";

static const char DIV_SER2_CERT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAMfPKeVqhbL3PKa20RAAHVxGuxd0MA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzA3MjEwMTU0
MzZaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDiAOVZHoCKJvesTCbo
zEA42Fyv4U7pndsE2GRbsUTiQOU8d5pUkHoEJzwFflwbUcXOT6K7NjEK96pjdFl1
aFT7h4nvt4Ygr3u7V9KDFUi2nFWtwAp6F845JUNgOeHDF2L2fz5dOFgEvJe+yjqE
CVc15xCd/kGhyvArhiuwUtWPLik9JVD5d0kJnuoKHHkPQFEdt01p95ERmt02fPa2
mTHwZIkLZT79AmqWGHR7MVFGx92YHtGvsfA4u8bpw8D80PXnglKq5d92o6vn2CJR
q9VkrsVEapV+nIiQOmTvl+4u+0ytc/jMMWB7L+dGqxiwy7VlQTaW+1ViDoe6If3E
thLbAgMBAAGjYDBeMB8GA1UdIwQYMBaAFOlLbR7smy+Wx+w43llPEz6UHUsCMB0G
A1UdDgQWBBTGDHxRRwfweNr/2Yd3gdkIqP0z3TAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAPxVEhVnxK7iW/VadcrP4itst
Fc3rmERkMiWrbjGEGi/0FTvJphcFVUQEEWgPTqVIHrvXgCkeSntdU196BzmexsOf
Q14b8nniw1Q9KDbAL3m8sQlIPGBBeyafyGty/KmO7Q/IxckTQPHCjpVeODW4pfSx
V/0Z1a7K3PGnScoE226TjgMOEBOesHwgHs9dvbbTMtAv0mtXrrRGdhRmW+7mXpZ/
nOmcLiWSdgNsaBqDmcmJ9WZQaYMQCFzOK1tjN55rJxZai4vBKUZlOO5HFl9A2adK
+6cyrCbxZmutSyNzZpUaHSp9kZjF8BBsyvN+pQrVGPVeLMHatG3eps8Tz5uffg==
-----END CERTIFICATE-----
 
 
)KEY";

static const char DIV_SER2_PRIKEY[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEowIBAAKCAQEA4gDlWR6Aiib3rEwm6MxAONhcr+FO6Z3bBNhkW7FE4kDlPHea
VJB6BCc8BX5cG1HFzk+iuzYxCveqY3RZdWhU+4eJ77eGIK97u1fSgxVItpxVrcAK
ehfOOSVDYDnhwxdi9n8+XThYBLyXvso6hAlXNecQnf5BocrwK4YrsFLVjy4pPSVQ
+XdJCZ7qChx5D0BRHbdNafeREZrdNnz2tpkx8GSJC2U+/QJqlhh0ezFRRsfdmB7R
r7HwOLvG6cPA/ND154JSquXfdqOr59giUavVZK7FRGqVfpyIkDpk75fuLvtMrXP4
zDFgey/nRqsYsMu1ZUE2lvtVYg6HuiH9xLYS2wIDAQABAoIBAQDdFuNGe4BjphtE
gnrN4oIxGfgSVudLwxEvfEExMgmhDLs0nAxuDahPx9H/zc1tLGHFokIfwrPXdtFI
2dlp8daw+bcGuxKLhyAT9aYKdhfcDLQEdYnKRt+HJ9zxla41m/tECNaJe0Uf3R7V
liAIatrV8GVhKgoqrMymx2qV43LnzPlgxTzG5p19CoD0uxngQ5+lDHCRuD4Y32fH
VXiwRRPlQ6Rcy0A/+zSXs/reTCRipdE+S7oiuVNUT/6cIcS9VFYIZbOzuVR6k75d
9MDZ/rKM/Px5X2xr8CE4OMtJ4Puh4M2V4wgswg2P5WxaKibOojlumr62aoahqKTJ
XN2yxUwBAoGBAP2+uSAMOJqOs2qHydakZzK8CY0yWYyFZB4eRssid+LV6OacJ2bd
fHVP63D8qMw+TBkSEV3ubxH/PgiT8u/RY5Z20VkF2fzIQG4uC9mj5mdSXrWpFphy
87UVCMu3O1Y4FHoyBO2qGthwjxdvebue/TdaW1SNUr2qTKopowiF5bp7AoGBAOQD
D18Rxn2G9n6ufDsxS3qZ+tdqgD8g9J6cymQIamFl56GJ0hOfQQElTZYbzEtY0Gds
D+j+9qASH27PVFwAlf4GFDWIwXyi2t40xTJzYRNNuwkxSkEa4O5ooE2AgaBzPggf
HOQZKq3KqgbZmDg8IOA8RFIHcxDtz0Ga94z7NUshAoGAK7tWLpbMnp6ff2m9uJeH
DbBouQQHePd4ZNR1AQeEv/x78lrRU6IylAldG5EACotmFCAQDC9OxzxFVbch9IES
99ishfpDMpTUveiDtFPSHtaMaiSlN0sAg6IHbQy8VkS+Cr1aKhfaHplvn+tfgJ2L
KKITAYSF0RhrtBwO9CYXjMcCgYBN0j2M1SRJ86Zt1l/QVCLO1X8nxtG+uiDDggAR
5E1qsL0+BSwORmyJV5IDiblQfh+jLN7BR0QlngncaCcCv7Bx4uFC5Eoln+/Tp28m
qPqY/A66NHiDgAkFVfBgg1u6x5qEaxoRQAWxC1q8u8eYae1Om0M2PBSp0oDKg3m6
RIMMAQKBgDsEp9KrqxTUiW4i+bJC0e0yGMfBfDhfjcDlOzKwoie2TbJgggHaMeFM
RM2upMj6T0NeXt8dhV6d75wO7X+QxP/zffh0s2zt1VeiucKvmmeBglVsg9DRof0D
CpFkc6uY8B1LBkDO+SbIyp6uCQF1y3WH2J12Nv+jtMqeYtpZxiQT
-----END RSA PRIVATE KEY-----
 
)KEY";

static const char DIV_SER3_CERT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAIiePXiHHW2LwzCEg1Ubg7kfLF3ZMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMzA3MjEwMTU1
MjZaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDH2LSo18BpwAHkTL7D
Eg6iOaYA+1uHPsdH2dMRjLowzWPduXe65Q2DLR2HPWNM3syKsEIsFcnQRy8fc9a0
5HXsCfX4Rhs3b8SLXqvKxA02S8XQh1nv++JD9HoHt0Vmb1rR138HhF9d8nQ3C8a8
LTfO28WyIbgA/ONp5eJ8y77mC+ATMrgI6HplRW97Jnz/MRuLawtqiKnmv6zbdREt
Twl6D9rrQfjaMLORPXYcGrDY/19lg5A25Ua2kSX8aBhcBLwuV8dE1/3rVoNL+tID
dFfN+qsx5Dl2RZbT0tj8ebTxmaUoVP7kmv/7PVtn4rHpxs4hpsoA/RLrqU80eBuY
J8UxAgMBAAGjYDBeMB8GA1UdIwQYMBaAFJ1ibdW7q0LjnGgUkc2CbABIN3poMB0G
A1UdDgQWBBRxpYkavRyDSZyci2PrxJBHNiQnZTAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAOrc17rtnzOaWPc2k8GYm0o3C
+pQuocipgMxEQwv9rLfjUTZ2QSzdGa92ciSBrqL8hIUrfetY3x2JMghvAyWx1DPd
loBjLplehFHoAVlZfO/Twz7o0uCVkEASHtaXDm82jpkq54nPSDQ1P/ethSdcRlfa
u/74pmZjrL3LEcdJvBSlgv5F+fIhS6gBAvDTYdw3NB9QA6dy0JP88MKScIE2HqZS
MerFfHBpSHAJl4kE0bKHgYjdMwxIqA3yUqQjssgX5+ekHOm2SSPRg+gMVGGI0ImN
IPAdwY6ZqOkF+pvfxViOGEO1sIlnK3Oue8VxU0fbMBO0FCi/0slHoKtjuo2C0g==
-----END CERTIFICATE-----
 
 
)KEY";

static const char DIV_SER3_PRIKEY[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAx9i0qNfAacAB5Ey+wxIOojmmAPtbhz7HR9nTEYy6MM1j3bl3
uuUNgy0dhz1jTN7MirBCLBXJ0EcvH3PWtOR17An1+EYbN2/Ei16rysQNNkvF0IdZ
7/viQ/R6B7dFZm9a0dd/B4RfXfJ0NwvGvC03ztvFsiG4APzjaeXifMu+5gvgEzK4
COh6ZUVveyZ8/zEbi2sLaoip5r+s23URLU8Jeg/a60H42jCzkT12HBqw2P9fZYOQ
NuVGtpEl/GgYXAS8LlfHRNf961aDS/rSA3RXzfqrMeQ5dkWW09LY/Hm08ZmlKFT+
5Jr/+z1bZ+Kx6cbOIabKAP0S66lPNHgbmCfFMQIDAQABAoIBAAfOb0ApLVr0JR7F
4K2+BtRPbCydpPWjfiVQXO5SkPNXEo+Wrxad2+lD2eNugnJ+QX8pY2xVbYy1OyH/
ZGOsiO6vdOw90NJZi1PmXs+M2PdF/nQm1VyKekwtQJcMkalusB2CTXP9t7vzvJZp
31l6arOp4g8TQhzHxBpe4Hn/e3WA75EQQfZg/+2jHZDR3s8XwPu6LxpIq0WlDSCw
tgm3l6OHnBrb5gyV6tPw8y+iZf8dTaY5b/LoG7MCpOJjJGPurqEkJaXBQW/e2DWa
3Sd6+7uFHYTjiHPabxiaOiEe0I0BUMZSilSHdQ8kBUawWZwdVER66sGjSh10umep
J3O4YAECgYEA6pUBInF0GFFGlo7nvgC0f7HxbFs7aiOnDchGkWTwOwEFiYLLyyuH
y5zHo6+3mQUaQPnLLJAT2QB97DoaLzg1cUGl39a7vpfUCNAoZhm/VPmR77ug1svi
FAwqxnS+u+KqLdNafxtmnqAJP5NXICk6KHclMW5woy55m534OHhE/wUCgYEA2hfP
rocojWoXU7qzlUw7AE0oidAf5LsQWBnMOfCbeI+D9Fx2Fm8QKitITyo6h60qPhFp
XzecxJlw1g5NO6HnCVeeBnCeumnhq6ODvuDksJRTB0L1QFOzN0a5ZjIJNK0mFpFy
bxQ50kvlRFv7ihsONXwwEoRYD6oaHYyLLQmAzT0CgYBHt241XYIkvRRbiy0GRajp
MTmh6vJrLKMx73zDjpxzLYjH1ZkAcDp/4VqXjG0Q9yJjovqekR3ARgo5YjoHHaQZ
D/zqRff3+Or2Fs2DCXQZQoN/S1mM0aA4iM+7BI4bWty0Td1o5rOk40Bwk1cbmf8R
x/sy9ZSyDs9W6CCvAvX1EQKBgQDPxgeRmipEL2Jx3ljgT3OWYevQ/3qjCqQTiuBK
ArPbM77euoe177FSu1F0OiLwx0SLRUNB91Ve51/cTlu+CAx3lgVy1TAjIGRihLEq
1E6K+4PuUxgbZKJEcxiGB/1FNgAnWAHRWU+MzclqSsdlV0k+I0YZHgRXSBMBO7gL
/BW9cQKBgQCAtNhv5H/llf8rszCJX2mJbsAEro8SWPp5xwetdDlyHLE+gJ6zriQG
CzMcmTSTyM3iwUWunZJCSznNoOwpawfva+A2W1XdPF33kTN9+F9gAG8h1K8g54M9
aC1Kw+9uuYdyhZ/cr4q+75jl12Nljm8fpnQPMOVgfvhCWygIB86D4Q==
-----END RSA PRIVATE KEY-----
 
)KEY";
