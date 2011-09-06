/* ----------------------------------------------------------------------------
 *          Mariokart project
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2011, University of Canterbury
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include <components/char_display.h>
#include <components/debug.h>
#include <components/switches.h>
#include <tc/tc.h>
#include <protocol/protocol.h>
#include <pio/pio.h>
#include <pio/pio_it.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Motor"

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------
void timer_callback(void) {
    char_display_tick();
}

void set_motor(unsigned char setpoint) {

}

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

    message_t msg;

    proto_init(ADDR_MOTOR);

    while (1) {
        switch (proto_state()) {
            case STARTUP:
                break;
            case CALIBRATING:
                proto_calibration_complete();
                break;
            case RUNNING: 
                msg = proto_read();
                switch(msg.command) {
                    case CMD_SET:
                        set_motor(msg.data[0]);
                        proto_refresh();
                    case CMD_NONE:
                        break;
                    default:
                        TRACE_WARNING("Invalid command %i received in running state", msg.command);
                        proto_state_error();
                        break; 

                }
                break;
            default: // ERROR
                set_motor(0);
                break;
        }
    }

    return 0;
}

