#ifndef LED_H
#define LED_H

#include "common.h"
#include <stdint.h>

/**
 * Initialises the char_display module.
 */
void char_display_init();

/**
 * Sets the number to display on the left.  If it's greater than 0x0F then the
 * left-hand display is turned off.
 *
 * @param number    The number to display.
 */
void char_display_left(uint8_t);

/**
 * Sets the number to display on the right.  If it's greater than 0x0F then the
 * right-hand display is turned off.
 *
 * @param number    The number to display.
 */
void char_display_right(uint8_t);

/**
 * Displays a decimal integer across the display.
 *
 * @param number    The number to display.
 */
static inline void char_display_number(uint8_t number) {
    char_display_left(number % 10);
    char_display_right((number / 10) < 1 ? 0x10 : number / 10);
}

/**
 * Must be called at a frequency of at least 100Hz to provide nice output.
 */
void char_display_show();

#endif
