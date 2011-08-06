#include "encoder.h"
#include <peripherals/pio/pio.h>
#include <peripherals/pio/pio_it.h>
#include <boards/mariokartv1/board.h>

/// Pio pins to configure.
static const Pin pins[] = {ENCODER_CLOCKWISE , ENCODER_ANTICLOCKWISE, LIM_SW_UP, LIM_SW_DOWN};

//priority of interrupt
#define ENCODER_PRIORITY AT91C_AIC_PRIOR_LOWEST

//updates position value if turning clockwise
void ISR_UP ( void )
{
    char_display_number(11);
    char_display_tick();
    pulse_position++;
}

//updates position value if turning anticlockwise
void ISR_DOWN ( void )
{
    char_display_number(22);
    char_display_tick();
    pulse_position--;
}

//Sets up pins for encoder 
void init_encoder(void){

    //must be static or interrupts will not work
    static const Pin pin_encoder_cw = ENCODER_CLOCKWISE;
    static const Pin pin_encoder_acw = ENCODER_ANTICLOCKWISE;

    //initilise pulse counter
    pulse_position = 0;
    
    //sets pins as inputs
    PIO_Configure(pins, PIO_LISTSIZE(pins));

    // Initialize interrupts
    PIO_InitializeInterrupts(ENCODER_PRIORITY);
    PIO_ConfigureIt(&pin_encoder_cw, (void (*)(const Pin *)) ISR_UP);
    PIO_ConfigureIt(&pin_encoder_acw, (void (*)(const Pin *)) ISR_DOWN);
    PIO_EnableIt(&pin_encoder_cw);
    PIO_EnableIt(&pin_encoder_acw);
}
