#include "mbed.h"
#include "led2.h"

Serial pc(USBTX, USBRX);

CAN can1 (p9, p10);

char r = 0;
char s = 0;

CANMessage can_1 (1, &r);
CANMessage can_2 (1, &s);

led2 led2;

int main() {
    can1.frequency(450000);
    while(1) {
        while(1) {
            if (can1.read(can_1)) {
                pc.printf("massage2 received\n");
                led2.led2_on();
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