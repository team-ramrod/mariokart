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
#include <tc/tc.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <peripherals/tc/tc.h>
#include <aic/aic.h>
#include <speed_sensor.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Sensor"

//the timer resolution in ms
#define TIMER_RES 1

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
void send_data(address_t to, unsigned char id, variable_t var) {
    unsigned char speed;

    switch (var) {
        case VAR_SPEED:
            speed = speed_output;
            TRACE_INFO("Current kart speed = %i\n\r", speed);

            message_t msg = {
                .from    = ADDR_SENSOR,
                .to      = to,
                .command = CMD_REPLY,
                .data    = {id, var, speed}
            };

            proto_write(msg);

            char_display_number(speed);
            break;

        default:
            break;
    }

}

//------------------------------------------------------------------------------
//         Local Functions
//------------------------------------------------------------------------------

//updates time since speed sensor last triggered
void timer_callback(void) {
    // Clear status bit to acknowledge interrupt
    AT91C_BASE_TC0->TC_SR;

    speed_update_time(TIMER_RES);
}

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    unsigned char id = 0x0;
    variable_t var = 0x0;

    message_t msg = {
        .from    = 0x0,
        .to      = 0x0,
        .command = CMD_NONE,
        .data    = {0x0}
    };

    debug_init(SOFTWARE_NAME);

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    TC_PeriodicCallback(1000, timer_callback);

    //Main initialisations
    char_display_init();
    switches_init();
    //timer_init(); Can i delete this
    speed_init();

    proto_init(ADDR_SENSOR);

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
                    case CMD_GET:
                        proto_refresh();
                        id = msg.data[0];
                        var = msg.data[1];
                        send_data(msg.from, id, var);
                        break;
                    case CMD_NONE:
                        break;
                    default:
                        TRACE_WARNING("Invalid command %i received in running state", msg.command);
                        proto_state_error();
                        break; //Go to error state  
                }
                break;
            default: // ERROR
                break;
        }
    }

    return 0;
}

