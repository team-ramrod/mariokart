#include "../../lib/peripherals/pio/pio.h"
#include "../../lib/peripherals/pwmc/pwmc.h"

#define DRIVER_PWM_CLOCKWISE   AT91C_PIO_PB19
#define DRIVER_CHANNEL_CLOCKWISE   0

#define BOARD_MCK 32000000

#define DRIVER_PWM_ANTICLOCKWISE   AT91C_PIO_PB20
#define DRIVER_CHANNEL_ANTICLOCKWISE   1

/// Pio pins to configure.
static const Pin pins[] = { DRIVER_PWM_CLOCKWISE, DRIVER_PWM_ANTICLOCKWISE };

#define P_GAIN 1
#define I_GAIN 0.1
#define D_GAIN 0.1

#define PWM_PERIOD 0x0999
#define SPEED_DIVISIONS 100

/// Wait time in us
void UTIL_Loop(unsigned int loop)
{
    while(loop--);
}


void UTIL_WaitTimeInUs(unsigned int mck, unsigned int time_ms)
{
    register unsigned int i = 0;
    i = (mck / 1000000) * time_ms;
    i = i / 3;
    UTIL_Loop(i);
}

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

//Sets up PWM output
void init_driver(void) {

    PIO_Configure(pins, PIO_LISTSIZE(pins));

    //sets up a pwm wave on channel 0
    PWMC_ConfigureChannel(DRIVER_CHANNEL_CLOCKWISE,
    //sets prescaler to divide by 1
            1,
    //sets wave to a low polarity
            0,
    //sets the wave to be left aligned
            0);

    //sets up a pwm wave on channel 1
    PWMC_ConfigureChannel(DRIVER_CHANNEL_ANTICLOCKWISE,
    //sets prescaler to divide by 1
            1,
    //sets wave to a low polarity
            0,
    //sets the wave to be left aligned
            0);
       
    //sets PWM period of the output.
    //8 kHz at 32 MHz clock = period of 4096 - 1 = 0x0999.
    PWMC_SetPeriod(DRIVER_CHANNEL_CLOCKWISE, PWM_PERIOD);
    PWMC_SetPeriod(DRIVER_CHANNEL_ANTICLOCKWISE, PWM_PERIOD);
    
    //sets the duty cycle to 0
    PWMC_SetDutyCycle(DRIVER_CHANNEL_CLOCKWISE, 0x0000);
    PWMC_SetDutyCycle(DRIVER_CHANNEL_ANTICLOCKWISE, 0x0000);
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
        PWMC_DisableChannel(DRIVER_CHANNEL_CLOCKWISE);
        
        //sets the duty cycle to 0
        PWMC_SetDutyCycle(DRIVER_CHANNEL_CLOCKWISE, 0x0000);
        
        //pauses
        UTIL_WaitTimeInUs(BOARD_MCK, 20);
        
        //enables the other channel
        PWMC_EnableChannel(DRIVER_CHANNEL_ANTICLOCKWISE);
    }
    else if((prev_speed =< 0) && (speed > 0)){
        //disables PWM channels
        PWMC_DisableChannel(DRIVER_CHANNEL_ANTICLOCKWISE);
        
        //sets the duty cycle to 0
        PWMC_SetDutyCycle(DRIVER_CHANNEL_ANTICLOCKWISE, 0x0000);
        
        //pauses
        UTIL_WaitTimeInUs(BOARD_MCK, 20);
        
        //enables the other channel
        PWMC_EnableChannel(DRIVER_CHANNEL_CLOCKWISE);
    }
    
    //sets the duty cycle
    if(speed > 0){
        PWMC_SetDutyCycle(DRIVER_CHANNEL_CLOCKWISE, new_duty);
    }
    else{
        PWMC_SetDutyCycle(DRIVER_CHANNEL_ANTICLOCKWISE, new_duty);
    }
    
    prev_speed = speed;
}
