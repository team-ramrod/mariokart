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
#include <protocol/protocol.h>
#include <pio/pio.h>
#include <pio/pio_it.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Comms"

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    debug_init(SOFTWARE_NAME);

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //Main initialisations
    char_display_init();
    switches_init();

    while(1) {
        char_display_tick();
    }

    return 0;
}


/**
 * Basic structure of entry point function for the
 * comms board
 */
void main(void) {
    // initialise USB and shit
    proto_init();

    
    switch (proto_state()) {
        case CALIBRATING: // waiting for all boards to acknowledge startup state
            proto_comms_wait();
            break;
        case STARTUP: // Waiting for all boards to finish calibration
            proto_comms_wait();
            break;
        case RUNNING: // Normal state
            while (1) {
                // Read USB input
                // Send set points
                // Check for acks
                // Receive data from sensor
                // Forward sensor data to latptop
                proto_refresh();
                // Any issues => state = ERROR; break;
            }
            break;
        default: // ERROR
            while(1) {
                //broadcast ERROR signal
                //send ERROR signal through USB
                // If reset signal received through USB
                // then broadcast it, pause momentarily
                // abd transition to CALIBRATING state.
                // (If boards still aren't ready it will send
                // us straight back to here)
            }
            break;
    }
}
