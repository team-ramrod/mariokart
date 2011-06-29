#include "../common.h"

#define DRIVER_PWM_CLOCKWISE   AT91C_PIO_PB19
#define DRIVER_CHANNEL_CLOCKWISE   0

#define DRIVER_PWM_ANTICLOCKWISE   AT91C_PIO_PB20
#define DRIVER_CHANNEL_ANTICLOCKWISE   1

#define DRIVER_PWM_PINS   (DRIVER_PWM_CLOCKWISE | DRIVER_PWM_ANTICLOCKWISE)

#define P_GAIN 1
#define I_GAIN 0.1
#define D_GAIN 0.1

#define PWM_PERIOD 0x0999
#define SPEED_DIVISIONS 100


int16_t pid(int16_t desired, int16_t current) {
    
    static int16_t err = 0;
    static int16_t err_old = 0;
    static int16_t I_err;
    
    int16_t P_err;
    int16_t D_err;

    err_old = err;
    err = desired - current;

    P_err = err;
    I_err += err;
    D_err = err - err_old;

    return P_GAIN * P_err + I_GAIN * I_err + D_GAIN*D_err;

}

//Sets up PWM output (note PWM channels are left disabled by function)
void init_driver(void) {
    //disables PWM channels
    AT91C_BASE_PWMC->PWMC_DIS = 1 << DRIVER_CHANNEL_CLOCKWISE;
     AT91C_BASE_PWMC->PWMC_DIS = 1 << DRIVER_CHANNEL_ANTICLOCKWISE;
    
    //sets PWM pins as outputs
    AT91C_BASE_PIOB->PIO_OER  |= DRIVER_PWM_PINS; 
    AT91C_BASE_PIOB->PIO_PER  |= DRIVER_PWM_PINS;
    
    //sets pins to output PWM
    AT91C_BASE_PIOB->PIO_ASR  |= DRIVER_PWM_PINS; 
    
    //sets prescaler to divide by 1 giving a frequency of 31.25 KHz
    AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_CLOCKWISE].PWMC_CMR = 0x00;
    AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_ANTICLOCKWISE].PWMC_CMR = 0x00;
    
    //sets PWM period of the output.
    //8 kHz at 32 MHz clock = period of 4096 - 1 = 0x0999.
    AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_CLOCKWISE].PWMC_CMR = PWM_PERIOD;
    AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_ANTICLOCKWISE].PWMC_CMR = PWM_PERIOD;
    
    //sets up to allow the duty cycle to be modified while running
    AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_CLOCKWISE].PWMC_CMR = 0x0;
    AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_ANTICLOCKWISE].PWMC_CMR = 0x0;
    
    //sets the duty cycle to 0
    AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_CLOCKWISE].PWMC_CDTYR = 0x0000;
    AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_ANTICLOCKWISE].PWMC_CDTYR = 0x0000;
}

//takes in a number between SPEED_DIVISIONS and -SPEED_DIVISIONS and uses it
//to set PWM for driving the steering motor where
//SPEED_DIVISIONS = full speed clockwise
//0.5*SPEED_DIVISIONS = half speed clockwise
//0 = stopped
//-SPEED_DIVISIONS = full speed anticlockwise etc
void drive_motor(int8_t speed){
    static int8_t prev_speed = 0;
    
    //ensuring speed is within limits
    if(speed > SPEED_DIVISIONS){
        speed = SPEED_DIVISIONS;
    }
    else if(speed < -SPEED_DIVISIONS){
        speed = -SPEED_DIVISIONS;
    }
    
    //finding new duty cycle
    uint16_t new_duty = abs((speed*PWM_PERIOD)/SPEED_DIVISIONS);
    
    //if changing directions switch PWM pins
    if((prev_speed > 0) && (speed =< 0)){
        //disables PWM channel
        AT91C_BASE_PWMC->PWMC_DIS |= 1 << DRIVER_CHANNEL_CLOCKWISE;
        
        //sets the duty cycle to 0
        AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_CLOCKWISE].PWMC_CDTYR = 0x0000;
        
        //pauses
        
        //enables the other channel
        AT91C_BASE_PWMC->PWMC_ENA = 1 << DRIVER_CHANNEL_ANTICLOCKWISE;     
    }
    else if((prev_speed =< 0) && (speed > 0)){
        //disables PWM channels
        AT91C_BASE_PWMC->PWMC_DIS |= 1 << DRIVER_CHANNEL_ANTICLOCKWISE;
        
        //sets the duty cycle to 0
        AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_ANTICLOCKWISE].PWMC_CDTYR = 0x0000;
        
        //pauses
        
        //enables the other channel
        AT91C_BASE_PWMC->PWMC_ENA = 1 << DRIVER_CHANNEL_CLOCKWISE;    
    }
    
    //sets the duty cycle
    if(speed > 0){
        AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_CLOCKWISE].PWMC_CUPDR = new_duty;
    }
    else{
        AT91C_BASE_PWMC->PWMC_CH[DRIVER_CHANNEL_ANTICLOCKWISE].PWMC_CUPDR = new_duty;
    }
    
    prev_speed = speed;
}
