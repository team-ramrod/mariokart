/* ----------------------------------------------------------------------------
 *          Mariokart project
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2011, University of Canterbury
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include <can/can.h>
#include <components/char_display.h>
#include <components/debug.h>
#include <components/switches.h>
#include <protocol/protocol.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <speed_sensor.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Sensor"

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
                .from    = SENSOR_BOARD,
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
    proto_init(SENSOR_BOARD, NULL, 0);

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //Main initialisations
    char_display_init();
    switches_init();
    speed_init();

    proto_wait();

    for (;;) {
        // Need to add a delay to aim for ~100 Hz here.
        msg = proto_read();

        switch (msg.command) {
            case CMD_GET:
                id = msg.data[0];
                var = msg.data[1];
                send_data(msg.from, id, var);
                break;
            default:
                break;
        }

        char_display_tick();
        proto_refresh();
    }

    return 0;
}

