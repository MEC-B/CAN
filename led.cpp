#include "led.h"
#include "mbed.h"
#define LED_PIN(pin) (sizeof(pin) / sizeof(pin[0]))

DigitalOut leds[] = {LED1, LED2, LED3, LED4};

const int size = LED_PIN(leds);

void led::led_on() {
    for (int i = 0; i < size; i++) {
        leds[i] = 1;
        wait_ms(5);
        leds[i] = 0;
        wait_ms(5);
    }
}