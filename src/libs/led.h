#ifndef LED_H
#define LED_H

#include <stdint.h>

/**
 * Initialises the led module.
 */
void led_init();

/**
 * Sets the number to display on the left.  If it's greater than 0x0F then the
 * left-hand display is turned off.
 *
 * @param number    The number to display.
 */
void led_display_left(uint8_t);

/**
 * Sets the number to display on the right.  If it's greater than 0x0F then the
 * right-hand display is turned off.
 *
 * @param number    The number to display.
 */
void led_display_right(uint8_t);

/**
 * Displays a decimal integer across the display.
 *
 * @param number    The number to display.
 */
static inline void led_display(uint8_t number) {
    led_display_left(number % 10);
    led_display_right((number / 10) < 1 ? 0x10 : number / 10);
}

#endif
