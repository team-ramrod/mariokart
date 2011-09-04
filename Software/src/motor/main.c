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
#include <protocol/proto_msg_buff.h>
#include <pio/pio.h>
#include <pio/pio_it.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Motor"

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------



void set_motor(unsigned char setpoint) {

}

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

    message_t msg;

    proto_init(ADDR_MOTOR);

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
                        set_motor(msg.data[0]);
                        proto_refresh();
                    } else {
                        proto_state_error();
                    }
                }
                char_display_tick();
                break;
            default: // ERROR
                set_motor(0);
                break;
        }
    }

    return 0;
}

