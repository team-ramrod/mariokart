#include "../common.h"

#define ENCODER_UP   AT91C_PIO_PB23
#define ENCODER_DOWN   AT91C_PIO_PB24
#define ENCODER_PINS   (ENCODER_UP | ENCODER_DOWN)

//priority of interrupt
#define ENCODER_PRIORITY 5

int16_t pulse_position = 0;

//updates position value
void encoder_interrupt ( void )
{
    //if turning clockwise
    if(AT91C_BASE_PIOB->PIO_PDSR & ENCODER_UP){
        pulse_position++;
    }
    //if turning counter-clockwise
    else if(AT91C_BASE_PIOB->PIO_PDSR & ENCODER_DOWN){
        pulse_position--;
    }
}

//Sets up pins for encoder 
void init_encoder(void){
    
    // Disable output
    AT91C_BASE_PIOB->PIO_ODR  |= ENCODER_PINS; 
    AT91C_BASE_PIOB->PIO_PER  |= ENCODER_PINS;
    
    // Sets the interrupt handler routine pointer
    AT91C_BASE_PIOB->AIC_SVR[AT91C_ID_PIOB] = encoder_interrupt;
    // Sets interrupt priority
    AT91C_BASE_PIOB->AIC_SMR[AT91C_ID_PIOB] = (ENCODER_PRIORITY | AT91C_AIC_SRCTYPE_INT_HIGH_LEVEL);
    // Enable interrupt on pin
    AT91C_BASE_PIOB->PIO_IER |= ENCODER_PINS;
    // Enable interrupt
    AT91C_BASE_AIC->AIC_IECR = 0x1 << AT91C_ID_PIOB ;
}
