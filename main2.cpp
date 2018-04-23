#include "mbed.h"
#include "led.h"

Serial pc(USBTX, USBRX);

CAN can1 (p30, p29);

char r = 0;
char s = 0;

CANMessage can_1 (0, &r);

led led1;

int main() {
    can1.frequency(450000);
    while(1) {
        while(1) {
            if (can1.read(can_1)) {
                pc.printf("massage1 received\n");
                led1.led_on();
                break;
            }
        }
        while(1) {
            if (can1.write(can_1)) {
                break;
            }
        }
    }
}