#include "mbed.h"
#include "led.h"
#include "led2.h"

Serial pc(USBTX, USBRX);

CAN can1 (p9, p10);
CAN can2 (p30, p29);

AnalogIn swich (p15);
AnalogIn swich2 (p16);

char r = 0;
char s = 0;
char t = 0;
char u = 0;

CANMessage can_1 (0, &r);
CANMessage can_2 (1, &s);

led led1;
led2 led2;

int main() {
    can1.frequency(450000);
    can2.frequency(450000);
    while(1) {
        
        static int i = 0;
        static int j = 0;
        
        while(1) {
            while(1) {
                if (swich.read() == 0) {
                    can1.write(can_1);
                    pc.printf("message1 sent, ");
                    break;
                }
                if (swich2.read() == 0) {
                    can2.write(can_2);
                    pc.printf("message2 sent\n");
                    break;
                }
            }
            while(1) {
                i = can1.read(can_1);
                if (i > 0) {
                    led2.led2_on();
                    break;
                }
                j = can2.read(can_2);
                if (j > 0) {
                    led1.led_on();
                    break;
                }
            }
        }
    }
}