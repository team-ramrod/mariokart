#include "char_display.h"

#include <utility/interrupts.h>
#include <board.h>
#include <pio/pio.h>

#define _BV(x) (1 << x)

#ifdef PIN_CHAR_DISPLAY_VALUE
static const Pin pinCharDisplayValue = PIN_CHAR_DISPLAY_VALUE;
#endif
#ifdef PIN_CHAR_DISPLAY_VALUE_A
static const Pin pinCharDisplayValueA = PIN_CHAR_DISPLAY_VALUE_A;
#endif
#ifdef PIN_CHAR_DISPLAY_VALUE_B
static const Pin pinCharDisplayValueB = PIN_CHAR_DISPLAY_VALUE_B;
#endif
#ifdef PIN_CHAR_DISPLAY_VALUE_C
static const Pin pinCharDisplayValueC = PIN_CHAR_DISPLAY_VALUE_C;
#endif
#ifdef PIN_CHAR_DISPLAY_VALUE_D
static const Pin pinCharDisplayValueD = PIN_CHAR_DISPLAY_VALUE_D;
#endif
#ifdef PIN_CHAR_DISPLAY_ENABLE
static const Pin pinCharDisplayEnable = PIN_CHAR_DISPLAY_ENABLE;
#endif
#ifdef PIN_CHAR_DISPLAY_SELECT_LEFT
static const Pin pinCharDisplaySelectLeft = PIN_CHAR_DISPLAY_SELECT_LEFT;
#endif
#ifdef PIN_CHAR_DISPLAY_SELECT_RIGHT
static const Pin pinCharDisplaySelectRight = PIN_CHAR_DISPLAY_SELECT_RIGHT;
#endif
#ifdef PINS_CHAR_DISPLAY
static const Pin pinsCharDisplay[] = { PINS_CHAR_DISPLAY };
static const unsigned int numCharDisplayPins = PIO_LISTSIZE(pinsCharDisplay);
#endif

static unsigned int char_display_values[] = { 0x10, 0x10 };

typedef enum {
    CHAR_DISPLAY_LEFT  = 0,
    CHAR_DISPLAY_RIGHT = 1
} char_display_side;

static void char_display_clear() {
#ifdef PIN_CHAR_DISPLAY_SELECT_LEFT
    PIO_Set(&pinCharDisplaySelectLeft);
#endif
#ifdef PIN_CHAR_DISPLAY_SELECT_RIGHT
    PIO_Set(&pinCharDisplaySelectRight);
#endif
#ifdef PIN_CHAR_DISPLAY_VALUE
    PIO_Clear(&pinCharDisplayValue);
#endif
#ifdef PIN_CHAR_DISPLAY_ENABLE
    PIO_Clear(&pinCharDisplayEnable);
#endif
}

static void char_display_show(char_display_side side) {
#ifdef PIN_CHAR_DISPLAY_VALUE_A
    if (char_display_values[side] & _BV(0))
        PIO_Set(&pinCharDisplayValueA);
#endif
#ifdef PIN_CHAR_DISPLAY_VALUE_B
    if (char_display_values[side] & _BV(1))
        PIO_Set(&pinCharDisplayValueB);
#endif
#ifdef PIN_CHAR_DISPLAY_VALUE_C
    if (char_display_values[side] & _BV(2))
        PIO_Set(&pinCharDisplayValueC);
#endif
#ifdef PIN_CHAR_DISPLAY_VALUE_D
    if (char_display_values[side] & _BV(3))
        PIO_Set(&pinCharDisplayValueD);
#endif
#ifdef PIN_CHAR_DISPLAY_ENABLE
    if (char_display_values[side] < 0x10)
        PIO_Set(&pinCharDisplayEnable);
#endif
#ifdef PIN_CHAR_DISPLAY_SELECT_LEFT
    if (side == CHAR_DISPLAY_LEFT && char_display_values[side] < 0x10)
        PIO_Clear(&pinCharDisplaySelectLeft);
#endif
#ifdef PIN_CHAR_DISPLAY_SELECT_RIGHT
    if (side == CHAR_DISPLAY_RIGHT && char_display_values[side] < 0x10)
        PIO_Clear(&pinCharDisplaySelectRight);
#endif
}

void char_display_init() {
#ifdef PINS_CHAR_DISPLAY
    PIO_Configure(pinsCharDisplay, numCharDisplayPins);
#else
#endif
}

void char_display_left(unsigned int number) {
    char_display_values[CHAR_DISPLAY_LEFT] = number;
}

void char_display_right(unsigned int number) {
    char_display_values[CHAR_DISPLAY_RIGHT] = number;
}

void char_display_number(unsigned int number) {
    char_display_left((number / 10) < 1 ? 0x10 : number / 10);
    char_display_right(number % 10);
}

void char_display_tick() {
    static char_display_side current = CHAR_DISPLAY_LEFT;
    char_display_side next;

    next = (current == CHAR_DISPLAY_LEFT) ? CHAR_DISPLAY_RIGHT
                                          : CHAR_DISPLAY_LEFT;
    disable_interrupts();
    char_display_clear();
    char_display_show(current);
    enable_interrupts();
    current = next;
}
