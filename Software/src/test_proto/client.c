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
            case STARTUP:
                break;
            case CALIBRATING:
                break;
            case RUNNING: 
                if (proto_msg_buff_length()) {
                    msg = proto_msg_buff_pop();
                    if (msg.command == CMD_SET) {
                        set_steering(msg.data[0]);
                        proto_refresh();
                    } else {
                        proto_state_error();
                    }
                }
                break;
            default: // ERROR
                //broadcast ERROR signal
                break;
        }
    }
}
