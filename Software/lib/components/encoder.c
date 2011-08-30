#include "encoder.h"
#include <peripherals/pio/pio.h>
#include <peripherals/pio/pio_it.h>
#include <boards/mariokartv1/board.h>

//updates position value if turning clockwise
void ENCODER_ISR_UP (const Pin *encoder_pin_cw )
{
//only updates on change from high to low
    if(!PIO_Get(encoder_pin_cw)){
        encoder_position_output++;
    }
}

//updates position value if turning anticlockwise
void ENCODER_ISR_DOWN ( const Pin *encoder_pin_acw )
{
//only updates on change from high to low
    if(!PIO_Get(encoder_pin_acw)){
        encoder_position_output--;
    }
}

//Sets up pins for encoder 
void encoder_init(void){
    // Pio pins for encoder
    static const Pin encoder_pin_cw = ENCODER_CLOCKWISE;
    static const Pin encoder_pin_acw = ENCODER_ANTICLOCKWISE;


    //initilise pulse counter
    encoder_position_output = 0;
    
    //sets pins as inputs
    PIO_Configure(&encoder_pin_cw, 1);
    PIO_Configure(&encoder_pin_acw, 1);

    // Initialize interrupts
    PIO_ConfigureIt(&encoder_pin_cw, ENCODER_ISR_UP);
    PIO_ConfigureIt(&encoder_pin_acw, ENCODER_ISR_DOWN);
    PIO_EnableIt(&encoder_pin_cw);
    PIO_EnableIt(&encoder_pin_acw);
}
