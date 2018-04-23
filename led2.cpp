#include "led2.h"
#include "mbed.h"
#define LED_PIN2(pin) (sizeof(pin) / sizeof(pin[0]))

DigitalOut leds2[] = {LED4, LED3, LED2, LED1};

const int _size = LED_PIN2(leds2);

void led2::led2_on() {
    for (int i = 0; i < _size; i++) {
        leds2[i] = 1;
        wait_ms(5);
        leds2[i] = 0;
        wait_ms(5);
    }
}