#include "../../lib/peripherals/pio/pio.h"
#include "../../lib/peripherals/pio/pio_it.h"

#define ENCODER_UP   AT91C_PIO_PB23
#define ENCODER_DOWN   AT91C_PIO_PB24

/// Pio pins to configure.
static const Pin pins[] = { ENCODER_UP , ENCODER_DOWN};

#define PULSES_PER_REV 4356  // NOTE PROBABLY WRONG

//priority of interrupt
#define ENCODER_PRIORITY 5

int16_t pulse_position = 0;

//updates position value if turning clockwise
void ISR_UP ( void )
{
    pulse_position++;
}

//updates position value if turning anticlockwise
void ISR_DOWN ( void )
{
    pulse_position--;
}

//Sets up pins for encoder 
void init_encoder(void){

    //sets pins as inputs
    PIO_Configure(pins, PIO_LISTSIZE(pins));

    // Initialize interrupts
    PIO_InitializeInterrupts(ENCODER_PRIORITY);
    PIO_ConfigureIt(ENCODER_UP, (void (*)(const Pin *)) ISR_UP);
    PIO_ConfigureIt(ENCODER_DOWN, (void (*)(const Pin *)) ISR_DOWN);
    PIO_EnableIt(ENCODER_UP);
    PIO_EnableIt(ENCODER_DOWN);
}
