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
#include <protocol/definitions.h>
#include <tc/tc.h>
#include <aic/aic.h>
#include <pio/pio.h>
#include <pio/pio_it.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Comms"
#define ALL_CLIENTS ((1<<ADDR_SENSOR) | (1<<ADDR_STEERING) | (1<<ADDR_BRAKE) | (1<<ADDR_MOTOR))

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

    message_t broadcast_message;
    broadcast_message.from     = ADDR_COMMS;
    broadcast_message.to       = ADDR_BROADCAST_RX;
    broadcast_message.command  = CMD_NONE;
    broadcast_message.data_len = 0;
    
    //TODO protocol needs it's own message handler, one that just decodes and passes on messages
    while(1) {    
        switch (proto_state()) {
            case STARTUP:
                if (timeout) {
                    timeout = false;
                    responses = 0;
                    broadcast_message.command = CMD_REQ_CALIBRATE;
                    proto_write(broadcast_message);
                } 

                if (0) { //new message  
                    if (0) { //command =! CMD_ACK_CALIBRATION 
                        proto_state_error();
                        break;
                    } else {
                        responses |= 0; // |= sender address
                    }
                }

                if (responses == ALL_CLIENTS) {
                    broadcast_message.command = CMD_CALIBRATE;
                    proto_write(broadcast_message);
                    // set state = CALIBRATE
                }

                break;
            case CALIBRATING: // Waiting for all boards to finish calibration
                break;
            case RUNNING: // Normal state
                // Read USB input
                // Send set points
                // Check for acks
                // Receive data from sensor
                // Forward sensor data to latptop
                proto_refresh();
                // Any issues => state = ERROR; break;
                break;
            default: // ERROR
                //broadcast ERROR signal
                //send ERROR signal through USB
                // If reset signal received through USB
                // then broadcast it, pause momentarily
                // abd transition to CALIBRATING state.
                // (If boards still aren't ready it will send
                // us straight back to here)
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
