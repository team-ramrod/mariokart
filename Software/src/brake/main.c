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
#include <tc/tc.h>
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

void timer_callback(void) {
    char_display_tick();
}


//TODO:reenable PWM commands
//#define DISABLE_PWM

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    debug_init(SOFTWARE_NAME);

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //Starts a timer running at 100Hz to maintain the display
    TC_PeriodicCallback(100, timer_callback);

    //Main initialisations
    char_display_init();
    switches_init();
    pot_init();
#ifndef DISABLE_PWM
    act_driver_init();
    //drive the actuator out 30mm
    set_act(30);
    int speed;
#endif

    message_t msg;

    proto_init(ADDR_BRAKE);

    while (1) {
        switch (RUNNING){//proto_state()) {
            case STARTUP:
                break;
            case CALIBRATING:
                proto_calibration_complete();
                // return to off position here?
                break;
            case RUNNING: 
                msg = proto_read();
                switch(msg.command) {
                    case CMD_SET:
#ifndef DISABLE_PWM
                        set_act(msg.data[0]);
#endif
                        proto_refresh();
                    case CMD_NONE:
                        break;
                    default:
                        TRACE_WARNING("Invalid command %i received in running state", msg.command);
                        proto_state_error();
                        break;
                }

                //demo program remove
                if (switches_pressed(0)) {
                    TRACE_INFO("Switch 0 is pressed\n\r");
                    set_act(10);
                    char_display_number(0);
                } else if (switches_pressed(1)) {
                    TRACE_INFO("Switch 1 is pressed\n\r");
                    set_act(50);
                    char_display_number(1);
                } else if (switches_pressed(2)) {
                    TRACE_INFO("Switch 2 is pressed\n\r");
                    set_act(80);
                    char_display_number(3);
                } else if (switches_pressed(3)) {
                    TRACE_INFO("Switch 3 is pressed\n\r");
                    set_act(95);
                    char_display_number(4);
                }

#ifndef DISABLE_PWM
                speed = act_driver_pid(brake_location_in_adc, pot_current_value);
                act_driver_drive(speed);
#endif
                break;
            default: // ERROR
                //TODO put the brake on
                break;
        }
    }
    return 0;
}

