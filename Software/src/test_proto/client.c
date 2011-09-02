#include "protocol.h"

/**
 * The structure of the entry point function for one of
 * the 3 'output' boards. The sensor board will differ slightly in
 * its running state.
 */
void main(void) {
    // initialise stuff
    proto_init();


    while (1) {
        switch (proto_state()) {
            case WAITING: // waiting for comms board to give the go ahead to calibrate
                proto_wait();
                break;
            case INITIALISING: // Waiting for all boards to finish calibration
                // run calibration routine();
                proto_comms_wait();
                break;
            case RUNNING: // Normal state
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
                break;
            default: // ERROR
                //broadcast ERROR signal
                // If reset signal received 
                // then transition to WAITING state.
                break;
        }
    }
}
