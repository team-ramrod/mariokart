#include "encoder.h"
#include "actuator_driver.h"
#include <peripherals/pio/pio.h>
#include <char_display.h>

//angle in degrees that the wheel may come within the end of its travel
//due to some round processes in converting from pulses to degrees this 
//must not be set to 0
#define SAFTEY_MARGIN 10

//minimum angle wheel can be turned to in degrees
int steering_min_angle;

//maximum angle wheel can be turned to in degrees
int steering_max_angle;

//location of wheel measured in pulses from encoder
int steering_loc_in_pulses = 0;

//sets steering to an angle (in degrees) between min_angle and max_angle
void set_steering(int angle){

    if(angle > steering_max_angle - SAFTEY_MARGIN){
        angle = steering_max_angle;
    }
    else if(angle < steering_min_angle + SAFTEY_MARGIN){
        angle = steering_min_angle;
    }
    //convert angle to pulses and account for any offset
    steering_loc_in_pulses = ((angle + steering_max_angle + steering_min_angle)
            * ENCODER_PULSES_PER_REV)/360 ;
}

//calibrates steering position by finding locaiton of limit switches and
//assuming straight ahead is halfway between them
void cal_steering(void){

    //sets pins of limit switches
    const Pin pin_lim_up = LIM_SW_UP;
    const Pin pin_lim_down = LIM_SW_DOWN;

    //drive steering anticlockwise until limit hit
    act_driver_drive(-50);
    while(!PIO_Get(&pin_lim_down)){
        continue;
    }

    //stop motor
    act_driver_drive(0);

    //record value in degrees
    steering_min_angle = 360 * encoder_position_output / ENCODER_PULSES_PER_REV;

    //drive steering clockwise until limit hit
    act_driver_drive(50);
    while(!PIO_Get(&pin_lim_up)){
        continue;
    }

    //stop motor
    act_driver_drive(0);

    //record value in degrees
    steering_max_angle = 360 * encoder_position_output / ENCODER_PULSES_PER_REV;

    //drive motor to center position
    set_steering(0);
}

int main(int argc, char *argv[]) {

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //initilize steering
    encoder_init();
    act_driver_init();
    char_display_init();

    //calibrate steering (commented out till limit switches in place)
    //cal_steering();
 
    //replaces what calibrating does (these 2 lines should not be in final code)
    steering_min_angle = -270;
    steering_max_angle = 270;

    //sets positon to turn wheel to in degrees (used until can bus in place)
    set_steering(200);

    //infinite loop running PID controller
    while(1){
        int speed = act_driver_pid(steering_loc_in_pulses, encoder_position_output);
        act_driver_drive(speed);
    }
    
    return 0;
}

