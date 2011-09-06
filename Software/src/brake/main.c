/* ----------------------------------------------------------------------------
 *          Mariokart project
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2011, University of Canterbury
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include <actuator_driver.h>
#include <char_display.h>
#include <debug.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <protocol/protocol_master.h>
#include <potentiometer.h>
#include <switches.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Brake"
#define ACT_MAX_LENGTH 101.6 //mm


//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
//minimum distance for linear actuator in mm
int brake_min_distance = 0;

//maximum distance for Actuator in mm
int brake_max_distance = 101;

//desired length of actuator in adc units
int brake_location_in_adc = 0;

//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    debug_init(SOFTWARE_NAME);
    //TODO:reenable PWM commands

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //Main initialisations
    char_display_init();
    switches_init();
    pot_init();
//    act_driver_init();

    //drives the actuator out 30mm
//    set_act(30);
    int speed;

    message_t msg;

    proto_init(ADDR_BRAKE);
    char_display_number(11);

    while (1) {
        char_display_tick();
        switch (proto_state()) {
            case STARTUP:
                break;
            case CALIBRATING:
                char_display_number(22);
                proto_calibration_complete();
                // return to off position here?
                break;
            case RUNNING: 
                char_display_number(33);
                proto_refresh();
                msg = proto_read();
                switch(msg.command) {
                    case CMD_SET:
                        set_act(msg.data[0]);
                        proto_refresh();
                    case CMD_NONE:
                        break;
                    default:
                        break;//ERROR
                }
//                speed = act_driver_pid(brake_location_in_adc, pot_current_value);
//                act_driver_drive(speed);
                break;
            default: // ERROR
                char_display_number(44);
                //TODO put the brake on
                break;
        }
    }
    return 0;
}

