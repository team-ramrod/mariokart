#include "protocol.h"

/**
 * The structure of the entry point function for one of
 * the 3 'output' boards. The sensor board will differ slightly in
 * its running state.
 */
void main(void) {
    // initialise stuff
    proto_init();

    
    switch (proto_state()) {
        case WAITING: // waiting for comms board to give the go ahead to calibrate
            proto_wait();
            // run calibration routine();
            break;
        case INITIALISING: // Waiting for all boards to finish calibration
            proto_comms_wait();
            break;
        case RUNNING: // Normal state
            while (1) {
                // if (incoming data) {
                //     if (data is valid) {
                //         setpoint = data;
                //         proto_refresh();
                //     } else {
                //         proto_set_error();
                //     }
                // }
                // run iteration of PID loop using setpoint
                // Any issues => state = ERROR; break;
            }
            break;
        default: // ERROR
            while(1) {
                //broadcast ERROR signal
                // If reset signal received 
                // then transition to WAITING state.
            }
            break;
    }
}
