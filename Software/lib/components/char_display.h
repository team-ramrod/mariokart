#ifndef CHAR_H
#define CHAR_H

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
void char_display_left(unsigned int);

/**
 * Sets the number to display on the right.  If it's greater than 0x0F then the
 * right-hand display is turned off.
 *
 * @param number    The number to display.
 */
void char_display_right(unsigned int);

/**
 * Displays a decimal integer across the display.
 *
 * @param number    The number to display.
 */
void char_display_number(unsigned int number);

/**
 * Must be called at a frequency of at least 100Hz to provide nice output.
 */
void char_display_tick();

#endif
