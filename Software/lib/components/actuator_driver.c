#include "actuator_driver.h"
#include <boards/mariokartv1/board.h>
#include <peripherals/pio/pio.h>
#include <peripherals/pio/pio_it.h>
#include <peripherals/pwmc/pwmc.h>
#include <peripherals/aic/aic.h>
#include <stdlib.h>
#include <stdio.h>

//defining actuator pins (note for linar actuator clockwise == extending
//  anticlockwise == retracting)
#define ACT_DRIVER_CHANNEL_CLOCKWISE   0
#define ACT_DRIVER_CHANNEL_ANTICLOCKWISE   1

//Period of PWM note above a maximum value driver wont behave correctly
// above around 0x3000 problems start
#define ACT_PWM_PERIOD 0x0999

//number of speeds the actuator can be driven at
#define ACT_SPEED_DIVISIONS 100

//Specify pin locations
const Pin act_driver_otw = ACT_DRIVER_OTW;
const Pin act_driver_fault = ACT_DRIVER_FAULT;
const Pin act_driver_reset1 = ACT_DRIVER_RESET1;
const Pin act_driver_reset2 = ACT_DRIVER_RESET2;


// Pio pins to configure.
static const Pin act_driver_pins[] = {ACT_DRIVER_PWM_CLOCKWISE,
    ACT_DRIVER_PWM_ANTICLOCKWISE,
    ACT_DRIVER_OTW,
    ACT_DRIVER_FAULT,
    ACT_DRIVER_RESET1,
    ACT_DRIVER_RESET2};

/// Wait time in us
void act_driver_loop(unsigned int loop) {
    while (loop--);
}

void act_driver_WaitTimeInUs(unsigned int mck, unsigned int time_ms) {
    register unsigned int i = 0;
    i = (mck / 1000000) * time_ms;
    i = i / 3;
    act_driver_loop(i);
}

//Interrupt occurs to indicate shit has just hit the fan
//indicates that a short/ loss of power / overheating has caused the loss of
//control of either the brakes or steering
void ACT_DRIVER_ERROR(void) {
    /*Overtemperature warning and (overtemperature shut down or overcurrent
    shut down or undervoltage protection) occurred*/
    if ((PIO_Get(&act_driver_otw) == 0) && (PIO_Get(&act_driver_fault) == 0)) {

        //attemmpt to solve problem by reseting driver
        PIO_Clear(&act_driver_reset1);
        PIO_Clear(&act_driver_reset2);

        //pauses
        act_driver_WaitTimeInUs(BOARD_MCK, 20);

        //release reset buttons
        PIO_Set(&act_driver_reset1);
        PIO_Set(&act_driver_reset2);

    }

    //Overcurrent shut-down or GVDD undervoltage protection occurred
    else if ((PIO_Get(&act_driver_otw) == 1) && (PIO_Get(&act_driver_fault) == 0)) {

        //attemmpt to solve problem by reseting driver
        PIO_Clear(&act_driver_reset1);
        PIO_Clear(&act_driver_reset2);

        //pauses
        act_driver_WaitTimeInUs(BOARD_MCK, 20);

        //release reset buttons
        PIO_Set(&act_driver_reset1);
        PIO_Set(&act_driver_reset2);
    }

    //Overtemperature warning
    else if ((PIO_Get(&act_driver_otw) == 0) && (PIO_Get(&act_driver_fault) == 1)) {
        /*TO DO probably send a shutdown message to everything*/
    }
}

//pid controller
int act_driver_pid(int desired, int current) {

    static int err = 0;
    static int err_old = 0;
    static int I_err;

    int P_err;
    int D_err;

    err_old = err;
    err = desired - current;

    P_err = err;
    I_err += err;
    D_err = err - err_old;

    return ACT_DRIVER_P_GAIN * P_err + ACT_DRIVER_I_GAIN * I_err + ACT_DRIVER_D_GAIN*D_err;
}

//Sets up PWM output
void act_driver_init(void) {

    //sets up driver pins
    PIO_Configure(act_driver_pins, PIO_LISTSIZE(act_driver_pins));

    //activate actuator driver
    PIO_Set(&act_driver_reset1);
    PIO_Set(&act_driver_reset2);

    // Initialize interrupts
    PIO_ConfigureIt(&act_driver_otw, (void (*)(const Pin *)) ACT_DRIVER_ERROR);
    PIO_ConfigureIt(&act_driver_fault, (void (*)(const Pin *)) ACT_DRIVER_ERROR);
    PIO_EnableIt(&act_driver_otw);
    PIO_EnableIt(&act_driver_fault);

    //disables the PWM while initilizing
    PWMC_DisableChannel(ACT_DRIVER_CHANNEL_CLOCKWISE);
    PWMC_DisableChannel(ACT_DRIVER_CHANNEL_ANTICLOCKWISE);

    //sets up a pwm wave on channel 0
    PWMC_ConfigureChannel(ACT_DRIVER_CHANNEL_CLOCKWISE,
            //sets prescaler to divide by 1
            1,
            //sets wave to a low polarity
            0,
            //sets the wave to be left aligned
            0);

    //sets up a pwm wave on channel 1
    PWMC_ConfigureChannel(ACT_DRIVER_CHANNEL_ANTICLOCKWISE,
            //sets prescaler to divide by 1
            1,
            //sets wave to a low polarity
            0,
            //sets the wave to be left aligned
            0);

    //sets PWM period of the output.
    //8 kHz at 32 MHz clock = period of 4096 - 1 = 0x0999.
    PWMC_SetPeriod(ACT_DRIVER_CHANNEL_CLOCKWISE, ACT_PWM_PERIOD);
    PWMC_SetPeriod(ACT_DRIVER_CHANNEL_ANTICLOCKWISE, ACT_PWM_PERIOD);

    //sets the duty cycle to 0
    PWMC_SetDutyCycle(ACT_DRIVER_CHANNEL_CLOCKWISE, 0x0000);
    PWMC_SetDutyCycle(ACT_DRIVER_CHANNEL_ANTICLOCKWISE, 0x0000);

}

//takes in a number between ACT_SPEED_DIVISIONS and -ACT_SPEED_DIVISIONS and
//uses it to set PWM for driving the steering motor where
//SPEED_DIVISIONS = full speed clockwise
//0.5*SPEED_DIVISIONS = half speed clockwise
//0 = stopped
//-SPEED_DIVISIONS = full speed anticlockwise etc

void act_driver_drive(int speed) {
    static int prev_speed = 0;

    //ensuring speed is within limits (/2 as full speed current limits power supplys)
    if (speed > ACT_SPEED_DIVISIONS/2) {
        speed = ACT_SPEED_DIVISIONS/2;
    } else if (speed < -ACT_SPEED_DIVISIONS/2) {
        speed = -ACT_SPEED_DIVISIONS/2;
    }

    //finding new duty cycle
    int new_duty = abs((speed * ACT_PWM_PERIOD) / ACT_SPEED_DIVISIONS);

    //sets duty cycle note cannot be 100% for motor driver to function
    //correctly thus the 10 ( this still allows a duty of 99.9%)
    new_duty = abs((ACT_SPEED_DIVISIONS * ACT_PWM_PERIOD) / ACT_SPEED_DIVISIONS) - new_duty;
    if(new_duty < 10){
        new_duty = 10;
    }

    //if changing directions switch PWM pins
    if ((prev_speed >= 0) && (speed <= 0)) {
        //disables PWM channel
        PWMC_DisableChannel(ACT_DRIVER_CHANNEL_CLOCKWISE);

        //sets the duty cycle to 0
        PWMC_SetDutyCycle(ACT_DRIVER_CHANNEL_CLOCKWISE, 0x0000);

        //pauses
        act_driver_WaitTimeInUs(BOARD_MCK, 20);

        //enables the other channel
        PWMC_EnableChannel(ACT_DRIVER_CHANNEL_ANTICLOCKWISE);

    } else if ((prev_speed <= 0) && (speed > 0)) {

        //disables PWM channels
        PWMC_DisableChannel(ACT_DRIVER_CHANNEL_ANTICLOCKWISE);

        //sets the duty cycle to 0
        PWMC_SetDutyCycle(ACT_DRIVER_CHANNEL_ANTICLOCKWISE, 0x0000);

        //pauses
        act_driver_WaitTimeInUs(BOARD_MCK, 20);

        //enables the other channel
        PWMC_EnableChannel(ACT_DRIVER_CHANNEL_CLOCKWISE);
    }

    //sets the duty cycle
    if (speed > 0) {
        PWMC_SetDutyCycle(ACT_DRIVER_CHANNEL_CLOCKWISE, new_duty);
    } else {
        PWMC_SetDutyCycle(ACT_DRIVER_CHANNEL_ANTICLOCKWISE, new_duty);
    }

    prev_speed = speed;
}
