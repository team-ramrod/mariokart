#include "encoder.h"
#include <peripherals/pio/pio.h>
#include <peripherals/pio/pio_it.h>
#include <boards/mariokartv1/board.h>

/// Pio pins for encoder
const Pin pin_encoder_cw = ENCODER_CLOCKWISE;
const Pin pin_encoder_acw = ENCODER_ANTICLOCKWISE;

//priority of interrupt
#define ENCODER_PRIORITY AT91C_AIC_PRIOR_LOWEST

//updates position value if turning clockwise
void ENCODER_ISR_UP ( void )
{
//only updates on change from high to low
    if(!PIO_Get(&pin_encoder_cw)){
        encoder_position_output++;
    }
}

//updates position value if turning anticlockwise
void ENCODER_ISR_DOWN ( void )
{
//only updates on change from high to low
    if(!PIO_Get(&pin_encoder_acw)){
        encoder_position_output--;
    }
}

//Sets up pins for encoder 
void encoder_init(void){

    //initilise pulse counter
    encoder_position_output = 0;
    
    //sets pins as inputs
    PIO_Configure(&pin_encoder_cw, 1);
    PIO_Configure(&pin_encoder_acw, 1);

    // Initialize interrupts
    PIO_InitializeInterrupts(ENCODER_PRIORITY);
    PIO_ConfigureIt(&pin_encoder_cw, (void (*)(const Pin *)) ENCODER_ISR_UP);
    PIO_ConfigureIt(&pin_encoder_acw, (void (*)(const Pin *)) ENCODER_ISR_DOWN);
    PIO_EnableIt(&pin_encoder_cw);
    PIO_EnableIt(&pin_encoder_acw);
}
