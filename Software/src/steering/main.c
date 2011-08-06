#include "encoder.h"
#include "actuator_driver.h"
#include <peripherals/pio/pio.h>
#include <char_display.h>

int min_angle;
int max_angle;
int pulses;

//sets steering to an angle (in degrees) between min_angle and max_angle
void set_steering(int angle){

    if(angle > max_angle){
        angle = max_angle;
    }
    else if(angle < min_angle){
        angle = min_angle;
    }
    //convert angle to pulses and account for any offset
    pulses = ((angle + max_angle + min_angle) * ENCODER_PULSES_PER_REV)/360 ;
}

//calibrates steering position
void cal_steering(void){

    const Pin pin_lim_up = LIM_SW_UP;
    const Pin pin_lim_down = LIM_SW_DOWN;

    //drive steering anticlockwise until limit hit
    act_driver_drive(-50);
    while(!PIO_Get(&pin_lim_down)){
        continue;
    }

    act_driver_drive(0);

    min_angle = 360 * encoder_position_output / ENCODER_PULSES_PER_REV;

    //drive steering clockwise until limit hit
    act_driver_drive(50);
    while(!PIO_Get(&pin_lim_up)){
        continue;
    }

    act_driver_drive(0);

    max_angle = 360 * encoder_position_output / ENCODER_PULSES_PER_REV;
}

int main(int argc, char *argv[]) {

    int speed;
    pulses = 0;

    encoder_init();
    act_driver_init();

    //cal_steering();
    char_display_init();
    min_angle = -270;
    max_angle = 270;
    set_steering(200);

    char_display_number(33);
    char_display_tick();
    //infinite loop running PID controller
    while(1){

        speed = act_driver_pid(pulses, encoder_position_output);

        act_driver_drive(100);
    }
    
    return 0;
}

