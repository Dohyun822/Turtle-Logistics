package class2.a204.controller;

import class2.a204.dto.NewOrderDto;
import class2.a204.dto.OrderUpdateDto;
import class2.a204.entity.Log;
import class2.a204.entity.OrderNow;
import class2.a204.service.MachineService;
import class2.a204.service.OrderService;
import class2.a204.util.ErrorHandler;
import io.swagger.annotations.Api;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

@RestController
@Api(tags = "Order")
@RequestMapping("/order")
public class OrderController {

    private final OrderService OS;

    private final ErrorHandler ER;

    private final MachineService MS;

    @Autowired
    public OrderController(OrderService os, ErrorHandler er, MachineService ms) {
        OS = os;
        ER = er;
        MS = ms;
    }

    // 분석 형태에 따라서 세분화 예정
    @GetMapping("/analysis")
    public ResponseEntity<?> dataAnalysis() {
        try {
            return new ResponseEntity<>(OS.data(), HttpStatus.OK);
        } catch (Exception e) {
            return ER.errorMessage(e);
        }
    }

    @PostMapping
    public ResponseEntity<?> newOrder(NewOrderDto newOrderDto) {
        try {
            OS.addNewOrder(newOrderDto);
            return new ResponseEntity<>(HttpStatus.CREATED);
        } catch (Exception e) {
            return ER.errorMessage(e);
        }
    }


    @PutMapping("/update")
    public ResponseEntity<?> orderUpdate(OrderUpdateDto orderUpdateDto) {
        try {
            OrderNow orderNow = OS.findByOrderNum(orderUpdateDto.getOrderNum());

            if (orderUpdateDto.getType() == 0) {
                if (orderUpdateDto.getResult() == 1) {
                    orderNow.setStatus(0);
                    Log l = new Log();
                    l.setErrorMessage(orderUpdateDto.getOrderNum() + " 포장이상");
                    MS.addLog(l);
                    return new ResponseEntity<>("문제기록 완료", HttpStatus.ACCEPTED);
                }
                if (orderNow.getStatus() != 1) {
                    orderNow.setStatus(3);
                    OS.updateStatus(orderNow);
                    return new ResponseEntity<>(HttpStatus.OK);
                } else {
                    orderNow.setStatus(3);
                    return new ResponseEntity<>("과정 누락 확인 필요", HttpStatus.ACCEPTED);
                }
            } else if (orderUpdateDto.getType() == 1) {
                if (orderUpdateDto.getResult() == 1) {
                    orderNow.setStatus(0);
                    Log l = new Log();
                    l.setErrorMessage(orderUpdateDto.getOrderNum() + " 분류이상");
                    MS.addLog(l);
                    return new ResponseEntity<>("문제기록 완료", HttpStatus.ACCEPTED);
                }
                if (orderNow.getStatus() != 3) {
                    orderNow.setStatus(4);
                    OS.updateStatus(orderNow);
                    return new ResponseEntity<>(HttpStatus.OK);
                } else {
                    orderNow.setStatus(4);
                    return new ResponseEntity<>("과정 누락 확인 필요", HttpStatus.ACCEPTED);
                }
            } else
                return new ResponseEntity<>(HttpStatus.BAD_REQUEST);
        } catch (Exception e) {
            return ER.errorMessage(e);
        }
    }

}
