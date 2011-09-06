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
#include <pmc/pmc.h>
#include <usb/device/cdc-serial/CDCDSerialDriver.h>
#include <usb/device/cdc-serial/CDCDSerialDriverDescriptors.h>
#include <utility/trace.h>
#include <pit/pit.h>
#include <better_can/can.h>
#include <string.h>

#include "usb.c"

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Comms"
#define ALL_CLIENTS (1<<ADDR_BRAKE)//((1<<ADDR_SENSOR) | (1<<ADDR_STEERING) | (1<<ADDR_BRAKE) | (1<<ADDR_MOTOR))

/// PIT period value in µseconds.
#define PIT_PERIOD          1000

//------------------------------------------------------------------------------
//         Local Variables
//------------------------------------------------------------------------------
unsigned int milisecond_counter;
#define BUFFER_LENGTH 8
static unsigned char message_buffer[BUFFER_LENGTH] = {0};
static unsigned int current_char = 0;

static message_t usb_msg;

//------------------------------------------------------------------------------
//         Local Functions
//------------------------------------------------------------------------------
volatile bool timeout = false;

unsigned int brake_position;

void send_brake_value(void) {
    message_t msg = {
        .from = ADDR_COMMS,
        .to   = ADDR_BRAKE,
        .command = CMD_SET,
        .data = {
            VAR_BRK_POS,
            brake_position
        }
    };
    proto_write(msg);
}

void send_steering_value(void){
}

void send_motor_value(void){
}

void check_speed_timeout(void){
}

void send_messages(void) {
    milisecond_counter++;
    if (milisecond_counter > 1000) {
        milisecond_counter = milisecond_counter % 10;
    }

    switch(milisecond_counter % 10) {
        case 0:
            send_brake_value();
            break;
        case 1:
            send_steering_value();
            break;
        case 2:
            send_motor_value();
            break;
        case 3:
            check_speed_timeout();
            break;
        default:
            break;
    }
}

// Message format:
//   to address (1 byte)
//   command (1 byte)
//   data (0-5 bytes)
//   0xFF (message delimiter)
static message_t parse_usb_message(unsigned char message[], unsigned int length) {
    message_t msg = {
        .from     = ADDR_ERROR_RX,
        .to       = ADDR_ERROR_RX,
        .command  = CMD_NONE,
        .data     = {0},
        .data_len = 0
    };

    if (length > 1) {
        msg.from     = ADDR_COMMS_USB;
        msg.to       = message[0];
        msg.command  = message[1];
        msg.data_len = length - 2;

        for (unsigned int i = 0; i < (length - 2); i++) {
            msg.data[i] = message[i+2];
        }
    }

    return msg;
}

//------------------------------------------------------------------------------
/// Interrupt handler for TC1 interrupt.
//------------------------------------------------------------------------------
void ISR_Tc1(void)
{
    static int i = 0;

    char_display_tick();
    AT91C_BASE_TC1->TC_SR;
    if (i++ > 10) {
        timeout = true;
        i = 0;
    }
}

//------------------------------------------------------------------------------
/// Configure Timer Counter 1 to generate an interrupt every 100ms.
//------------------------------------------------------------------------------
void ConfigureTimer1(void)
{
    unsigned int div;
    unsigned int tcclks;

    // Enable peripheral clock
    AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_TC1;

    // Configure TC for a 4Hz frequency and trigger on RC compare
    TC_FindMckDivisor(100, BOARD_MCK, &div, &tcclks);
    TC_Configure(AT91C_BASE_TC1, tcclks | AT91C_TC_CPCTRG);
    AT91C_BASE_TC1->TC_RC = (BOARD_MCK / div) / 100; // timerFreq / desiredFreq

    // Configure and enable interrupt on RC compare
    AIC_ConfigureIT(AT91C_ID_TC1, AT91C_AIC_PRIOR_LOWEST, ISR_Tc1);
    AT91C_BASE_TC1->TC_IER = AT91C_TC_CPCS;
    AIC_EnableIT(AT91C_ID_TC1);

    TC_Start(AT91C_BASE_TC1);
}


static void UsbHandler(const unsigned char data[], unsigned int length) {
    if (length > (BUFFER_LENGTH - current_char)) {
        TRACE_WARNING("Invalid USB message received.\n\r");
        current_char = 0;
    } else {
        memcpy(&message_buffer[current_char], data, length);
        current_char += length;
        if (data[length-1] == 0xFF) {
            usb_msg = parse_usb_message(message_buffer, current_char);
            if (usb_msg.command == CMD_NONE) {
                TRACE_WARNING("Invalid USB message received.\n\r");
            } else {
                TRANE_INFO("USB message received:" "\n\r"
                           "    to: %2x
            current_char = 0;")
        }
    }
}


//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    debug_init(SOFTWARE_NAME);


    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    milisecond_counter = 0;
    ConfigureTimer1();

    //Main initialisations
    char_display_init();
    switches_init();

    CDCDSerialDriver_Initialize();
    VBus_Configure();

    proto_init(ADDR_COMMS);

    unsigned int responses;

    message_t broadcast_message, msg;
    broadcast_message.from     = ADDR_COMMS;
    broadcast_message.to       = ADDR_BRAKE;
    broadcast_message.command  = CMD_NONE;
    broadcast_message.data_len = 0;
    char_display_number(11);
   
    while(1)TRACE_ERROR("test\n");

    while(1) {    
        switch (proto_state()) {
            case STARTUP:
                if (timeout) {
                    timeout = false;
                    responses = 0;
                    broadcast_message.command = CMD_REQ_CALIBRATE;
                    if (CAN_STATUS_SUCCESS == proto_write(broadcast_message)) {
                    }
                } 

                msg = proto_read();
                switch(msg.command) {
                    case CMD_ACK_CALIBRATE:
                        char_display_number(23);
                        responses |= 1 << msg.from; 
                        break;
                    case CMD_NONE:
                        break;
                    default:
                        TRACE_ERROR("Invalid command %i received in startup state", msg.command);
                        proto_state_error();
                        break;
                }

                if (responses == ALL_CLIENTS) {
                    char_display_number(24);
                    broadcast_message.command = CMD_CALIBRATE;
                    proto_write(broadcast_message);
                    proto_state_transition(CALIBRATING);
                    responses = 0;
                }

                break;
            case CALIBRATING: // Waiting for all boards to finish calibration
                if (timeout) {
                    responses = 0;
                    broadcast_message.command = CMD_REQ_RUN;
                    proto_write(broadcast_message);
                    timeout = false;
                } 

                msg = proto_read();
                switch(msg.command) {
                    case CMD_NONE:
                        break;
                    case CMD_ACK_RUN:
                        responses |= 1 << msg.from; 
                        break;
                    case CMD_NO:
                        break;// A board is refusing the transition
                    default:
                        TRACE_ERROR("Invalid command %i received in calibrating state", msg.command);
                        proto_state_error();
                        break;
                }

                if (responses == ALL_CLIENTS) {
                    char_display_number(72);
                    while(1);
                    broadcast_message.command = CMD_RUN;
                    proto_write(broadcast_message);
                    proto_state_transition(RUNNING);
                }

                break;
            case RUNNING: // Normal state
                
                char_display_number(33);
                CDCDSerialDriver_Read(usbBuffer, DATABUFFERSIZE, UsbDataReceived, 0);
                if (usb_msg.command != CMD_NONE) {
                    // Send set points
                    // Check for acks
                    // Receive data from sensor
                    // Forward sensor data to latptop
                }
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
}

