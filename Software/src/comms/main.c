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
#include <protocol/protocol_master.h>
#include <tc/tc.h>
#include <aic/aic.h>
#include <pio/pio.h>
#include <pio/pio_it.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Comms"
#define ALL_CLIENTS (1<<ADDR_BRAKE)//((1<<ADDR_SENSOR) | (1<<ADDR_STEERING) | (1<<ADDR_BRAKE) | (1<<ADDR_MOTOR))

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
volatile bool timeout = false;

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

    proto_init(ADDR_COMMS);

    unsigned int responses;

    message_t broadcast_message, msg;
    broadcast_message.from     = ADDR_COMMS;
    broadcast_message.to       = ADDR_BROADCAST_RX;
    broadcast_message.command  = CMD_NONE;
    broadcast_message.data_len = 0;
    char_display_number(0);

    while(1) {    
        char_display_tick();
        switch (proto_state()) {
            case STARTUP:
                char_display_number(11);
                if (timeout) {
                    timeout = false;
                    responses = 0;
                    broadcast_message.command = CMD_REQ_CALIBRATE;
                    proto_write(broadcast_message);
                } 

                msg = proto_read();
                switch(msg.command) {
                    case CMD_ACK_CALIBRATE:
                        responses |= 1 << msg.from; 
                        break;
                    default:
                        proto_state_error();
                        break;
                }

                if (responses == ALL_CLIENTS) {
                    broadcast_message.command = CMD_CALIBRATE;
                    proto_write(broadcast_message);
                    proto_state_transition(CALIBRATING);
                    responses = 0;
                }

                break;
            case CALIBRATING: // Waiting for all boards to finish calibration
                char_display_number(22);
                if (timeout) {
                    responses = 0;
                    broadcast_message.command = CMD_REQ_RUN;
                    proto_write(broadcast_message);
                    timeout = false;
                } 

                msg = proto_read();
                switch(msg.command) {
                    case CMD_ACK_RUN:
                        responses |= 1 << msg.from; 
                        break;
                    case CMD_NO:
                        break;// A board is refusing the transition
                    default:
                        proto_state_error();
                        break;
                }

                if (responses == ALL_CLIENTS) {
                    broadcast_message.command = CMD_RUN;
                    proto_write(broadcast_message);
                    proto_state_transition(RUNNING);
                }

                break;
            case RUNNING: // Normal state
                char_display_number(33);
                // Read USB input
                // Send set points
                // Check for acks
                // Receive data from sensor
                // Forward sensor data to latptop
                proto_refresh();
                // Any issues => state = ERROR; break;
                break;
            default: // ERROR
                char_display_number(44);
                //broadcast ERROR signal
                //send ERROR signal through USB
                break;
        }
    }

    return 0;
}

//------------------------------------------------------------------------------
/// Interrupt handler for TC1 interrupt.
//------------------------------------------------------------------------------
void ISR_Tc1(void)
{
    AT91C_BASE_TC1->TC_SR;
    timeout = true;
}

//------------------------------------------------------------------------------
/// Configure Timer Counter 1 to generate an interrupt every 100ms.
//------------------------------------------------------------------------------
void ConfigureTimer(void)
{
    unsigned int div;
    unsigned int tcclks;

    // Enable peripheral clock
    AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_TC1;

    // Configure TC for a 4Hz frequency and trigger on RC compare
    TC_FindMckDivisor(10, BOARD_MCK, &div, &tcclks);
    TC_Configure(AT91C_BASE_TC1, tcclks | AT91C_TC_CPCTRG);
    AT91C_BASE_TC1->TC_RC = (BOARD_MCK / div) / 10; // timerFreq / desiredFreq

    // Configure and enable interrupt on RC compare
    AIC_ConfigureIT(AT91C_ID_TC1, AT91C_AIC_PRIOR_LOWEST, ISR_Tc1);
    AT91C_BASE_TC1->TC_IER = AT91C_TC_CPCS;
    AIC_EnableIT(AT91C_ID_TC1);

    TC_Start(AT91C_BASE_TC1);
}
