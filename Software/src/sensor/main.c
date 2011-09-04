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
//         Interrupt Handlers
//------------------------------------------------------------------------------

//updates time since speed sensor last triggered
void TIMER_ISR(void)
{
    // Clear status bit to acknowledge interrupt
    AT91C_BASE_TC0->TC_SR;

    speed_update_time(TIMER_RES);
}

//------------------------------------------------------------------------------
//         Local Functions
//------------------------------------------------------------------------------

// Configure Timer Counter 0 to generate an interrupt every ms.
void timer_init(void){
    unsigned int div;
    unsigned int tcclks;

    // Enable peripheral clock
    AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_TC0;

    // Configure TC for a 4Hz frequency and trigger on RC compare
    TC_FindMckDivisor((1000/TIMER_RES), BOARD_MCK, &div, &tcclks);
    TC_Configure(AT91C_BASE_TC0, tcclks | AT91C_TC_CPCTRG);
    AT91C_BASE_TC0->TC_RC = (BOARD_MCK / div) / (1000/TIMER_RES); // timerFreq / desiredFreq

    // Configure and enable interrupt on RC compare
    AIC_ConfigureIT(AT91C_ID_TC0, AT91C_AIC_PRIOR_LOWEST, TIMER_ISR);
    AT91C_BASE_TC0->TC_IER = AT91C_TC_CPCS;
    AIC_EnableIT(AT91C_ID_TC0);

    // Start the counter
    TC_Start(AT91C_BASE_TC0);
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
    proto_init(ADDR_SENSOR);

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //Main initialisations
    char_display_init();
    switches_init();
    timer_init();
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
                if (proto_msg_buff_length()) {
                    msg = proto_msg_buff_pop();
                    if (msg.command == CMD_GET) {
                        proto_refresh();
                        id = msg.data[0];
                        var = msg.data[1];
                        send_data(msg.from, id, var);
                    } else {
                        proto_state_error();
                    }
                }
                char_display_tick();
                break;
            default: // ERROR
                break;
        }
    }

    return 0;
}

