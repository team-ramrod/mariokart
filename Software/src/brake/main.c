#include <potentiometer.h>
#include <actuator_driver.h>
#include <peripherals/pio/pio.h>

#define ACT_MAX_LENGTH 101.6 //mm

//minimum distance for linear actuator in mm
int brake_min_distance = 0;

//maximum distance for Actuator in mm
int brake_max_distance = 101;

//desired length of actuator in adc units
int brake_location_in_adc = 0;

//sets actuator to a distance (in mm) between min_distance and max_distance
void set_act(int distance){

    if(distance > brake_max_distance){
        distance = brake_max_distance;
    }
    else if(distance < brake_min_distance){
        distance = brake_min_distance;
    }

    //convert distance to adc output
    brake_location_in_adc = (1024 * distance) / ACT_MAX_LENGTH;
}

int main(int argc, char *argv[]) {

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //initilizes brake
    pot_init();
    act_driver_init();
    char_display_init();

    //drives the actuator out 30mm
    set_act(30);

    //infinite loop running PID controller
    while(1){
        int speed = act_driver_pid(brake_location_in_adc, pot_current_value);
        act_driver_drive(speed);
    }
    
    return 0;
}

