#include "led.h"

#define LED_NUM_PINS     (AT91C_PIO_PB0 | AT91C_PIO_PB1 | AT91C_PIO_PB2 | AT91C_PIO_PB3)
#define LED_SELECT_LEFT   AT91C_PIO_PB7
#define LED_SELECT_RIGHT  AT91C_PIO_PB17
#define LED_ENABLE_PIN    AT91C_PIO_PB12

static struct {
    uint32_t value; // The value to be displayed
    uint32_t enabled; // if the display is actually displaying anything
    uint32_t selected;  // Display pin number
} __left_display, __right_display;

void led_init() {
    // Set the LED pins as outputs.
    *AT91C_PIOB_OER = LED_NUM_PINS
                    | LED_ENABLE_PIN
                    | LED_SELECT_LEFT
                    | LED_SELECT_RIGHT;

    // Set the default values for the structs.
    __left_display.value     = 0x00;
    __left_display.enabled   = 0x00;
    __left_display.selected  = LED_SELECT_LEFT;

    __right_display.value    = 0x00;
    __right_display.enabled  = 0x00;
    __right_display.selected = LED_SELECT_RIGHT;
}

void led_display_left(uint8_t number) {
    if (number < 0x10) {
        __left_display.value   = number;
        __left_display.enabled = LED_ENABLE_PIN;
    } else {
        __left_display.value   = 0x00;
        __left_display.enabled = 0x00;
    }
}

void led_display_right(uint8_t number) {
    if (number < 0x10) {
        __right_display.value   = number;
        __right_display.enabled = LED_ENABLE_PIN;
    } else {
        __right_display.value   = 0x00;
        __right_display.enabled = 0x00;
    }
}

void led_show() {
    static enum { __L_D, __R_D } __current = __L_D;

    switch (__current) {
        case __L_D:
            __current = __R_D;
            *AT91C_PIOB_CODR = LED_NUM_PINS
                | LED_SELECT_LEFT
                | LED_ENABLE_PIN;

            *AT91C_PIOB_SODR = __right_display.value
                | __right_display.enabled
                | __right_display.selected;
            break;
        case __R_D:
            __current = __L_D;
            *AT91C_PIOB_CODR = LED_NUM_PINS
                | LED_SELECT_RIGHT
                | LED_ENABLE_PIN;

            *AT91C_PIOB_SODR = __left_display.value
                | __left_display.enabled
                | __left_display.selected;
            break;
    }
}
