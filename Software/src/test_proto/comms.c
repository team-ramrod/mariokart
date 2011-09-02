#include "protocol.h"

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
