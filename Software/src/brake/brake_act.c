#include "brake_act.h"
#include <boards/mariokartv1/board.h>
#include <peripherals/pio/pio.h>
#include <peripherals/pio/pio_it.h>
#include <peripherals/pwmc/pwmc.h>

#define DRIVER_PWM_CLOCKWISE   PIN_PWMC_PWM0
#define DRIVER_CHANNEL_CLOCKWISE   0

#define DRIVER_PWM_ANTICLOCKWISE   PIN_PWMC_PWM1
#define DRIVER_CHANNEL_ANTICLOCKWISE   1

//priority 0 as can result in brake failure
#define DRIVER_ERROR_PRIORITY 0

//Specify pin locations
const Pin pin_driver_otw = PIN_DRIVER_OTW;
const Pin pin_driver_fault = PIN_DRIVER_FAULT;
const Pin pin_driver_reset1 = PIN_DRIVER_RESET1;
const Pin pin_driver_reset2 = PIN_DRIVER_RESET2;


/// Pio pins to configure.
static const Pin pins[] = {DRIVER_PWM_CLOCKWISE,
    DRIVER_PWM_ANTICLOCKWISE,
    PIN_DRIVER_OTW,
    PIN_DRIVER_FAULT,
    PIN_DRIVER_RESET1,
    PIN_DRIVER_RESET2};

#define P_GAIN 1
#define I_GAIN 0.1
#define D_GAIN 0.1

#define PWM_PERIOD 0x0999
#define SPEED_DIVISIONS 100

/// Wait time in us

void UTIL_Loop(unsigned int loop) {
    while (loop--);
}

void UTIL_WaitTimeInUs(unsigned int mck, unsigned int time_ms) {
    register unsigned int i = 0;
    i = (mck / 1000000) * time_ms;
    i = i / 3;
    UTIL_Loop(i);
}

//Interrupt occurs to indicate shit has just hit the fan
//indicates that a short/ loss of power / overheating has caused the loss of
//control of either the brakes or steering

void DRIVER_ERROR(void) {
    /*Overtemperature warning and (overtemperature shut down or overcurrent
    shut down or undervoltage protection) occurred*/
    if ((PIO_Get(&pin_driver_otw) == 0) && (PIO_Get(&pin_driver_fault) == 0)) {

        //attemmpt to solve problem by reseting driver
        PIO_Clear(&pin_driver_reset1);
        PIO_Clear(&pin_driver_reset2);

        //pauses
        UTIL_WaitTimeInUs(BOARD_MCK, 20);

        //release reset buttons
        PIO_Set(&pin_driver_reset1);
        PIO_Set(&pin_driver_reset2);

    }

    //Overcurrent shut-down or GVDD undervoltage protection occurred
    else if ((PIO_Get(&pin_driver_otw) == 1) && (PIO_Get(&pin_driver_fault) == 0)) {

        //attemmpt to solve problem by reseting driver
        PIO_Clear(&pin_driver_reset1);
        PIO_Clear(&pin_driver_reset2);

        //pauses
        UTIL_WaitTimeInUs(BOARD_MCK, 20);

        //release reset buttons
        PIO_Set(&pin_driver_reset1);
        PIO_Set(&pin_driver_reset2);
    }

    //Overtemperature warning
    else if ((PIO_Get(&pin_driver_otw) == 0) && (PIO_Get(&pin_driver_fault) == 1)) {
        /*TO DO*/
    }
}

int pid(int desired, int current) {

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

    return P_GAIN * P_err + I_GAIN * I_err + D_GAIN*D_err;

}

//Sets up PWM output

void init_driver(void) {

    PIO_Configure(pins, PIO_LISTSIZE(pins));

    //activate motor driver
    PIO_Set(&pin_driver_reset1);
    PIO_Set(&pin_driver_reset2);

    // Initialize interrupts
    PIO_InitializeInterrupts(DRIVER_ERROR_PRIORITY);
    PIO_ConfigureIt(&pin_driver_otw, (void (*)(const Pin *)) DRIVER_ERROR);
    PIO_ConfigureIt(&pin_driver_fault, (void (*)(const Pin *)) DRIVER_ERROR);
    PIO_EnableIt(&pin_driver_otw);
    PIO_EnableIt(&pin_driver_fault);

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

void drive_motor(int speed) {
    static int prev_speed = 0;

    //ensuring speed is within limits
    if (speed > SPEED_DIVISIONS) {
        speed = SPEED_DIVISIONS;
    } else if (speed < -SPEED_DIVISIONS) {
        speed = -SPEED_DIVISIONS;
    }

    //finding new duty cycle
    int new_duty = abs((speed * PWM_PERIOD) / SPEED_DIVISIONS);

    //if changing directions switch PWM pins
    if ((prev_speed > 0) && (speed <= 0)) {
        //disables PWM channel
        PWMC_DisableChannel(DRIVER_CHANNEL_CLOCKWISE);

        //sets the duty cycle to 0
        PWMC_SetDutyCycle(DRIVER_CHANNEL_CLOCKWISE, 0x0000);

        //pauses
        UTIL_WaitTimeInUs(BOARD_MCK, 20);

        //enables the other channel
        PWMC_EnableChannel(DRIVER_CHANNEL_ANTICLOCKWISE);
    } else if ((prev_speed <= 0) && (speed > 0)) {
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
    if (speed > 0) {
        PWMC_SetDutyCycle(DRIVER_CHANNEL_CLOCKWISE, new_duty);
    } else {
        PWMC_SetDutyCycle(DRIVER_CHANNEL_ANTICLOCKWISE, new_duty);
    }

    prev_speed = speed;
}
