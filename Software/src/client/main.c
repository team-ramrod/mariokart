/* ----------------------------------------------------------------------------
 *          Mariokart project
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2011, University of Canterbury
 *  This is a template for client modules.
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include <char_display.h>
#include <debug.h>
#include <protocol/protocol.h>
#include <components/switches.h>
#include <tc/tc.h>
#include <pio/pio_it.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Client"

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------
void timer_callback(void) {
    char_display_tick();
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

    //Initialises the CAN bus and state machine controller
    proto_init(ADDR_BRAKE);

    while (1) {
        switch (proto_state()) {

            // A holding state until instructions are received from the master board
            case STARTUP:
                break;

            // A state to calibrate and reposition actuators before running
            case CALIBRATING:
                //must be called by all boards before any can progress
                proto_calibration_complete(); 
                break;

            // The normal running state
            case RUNNING: 
                // Retrieve a message from the protocol handler, in all other states
                // the handler intercepts messages pre-emptively.
                msg = proto_read();

                switch(msg.command) {
                    // If the command is expected (e.g. CMD_SET) then call proto_refresh
                    case CMD_SET:
                        proto_refresh();

                    // This represents no message
                    case CMD_NONE:
                        break;

                    // Unexpected messages force a transition to the error state
                    default:
                        TRACE_WARNING("Invalid command %i received in running state", msg.command);
                        proto_state_error();
                        break;
                }
                break;
            default: 
                // ERROR state: move any actuators into the safest position
                break;
        }
    }
    return 0;
}

