#include "potentiometer.h"
#include "brake_act.h"
#include <peripherals/pio/pio.h>

#define ACT_MAX_LENGTH 101.6 //mm

int min_distance;
int max_distance;
int adc_dist; //desired length of actuator in adc units

//sets actuator to a distance (in mm) between min_distance and max_distance
void set_act(int distance){

    if(distance > max_distance){
        distance = max_distance;
    }
    else if(distance < min_distance){
        distance = min_distance;
    }

    //convert distance to adc output
    //int adc_dist = (1024 * distance) / ACT_MAX_LENGTH;
}

//calibrates steering position
void cal_adc(void){

    //not sure how this will be implemented
}

int main(int argc, char *argv[]) {

    int speed;
    adc_dist = 0;

    init_pot();
    init_driver();

    cal_adc();

    //infinite loop running PID controller
    while(1){
        speed = pid(adc_dist, current_adc_value);

        drive_motor(speed);
    }
    
    return 0;
}

