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

//------------------------------------------------------------------------------
/// Interrupt handler for TC1 interrupt.
//------------------------------------------------------------------------------
void timer_callback(void) {
    static int i = 0;

    // Update the display
    char_display_tick();
    AT91C_BASE_TC1->TC_SR;
    if (i++ > 10) {
        // A flag used to run periodic events in the background
        timeout = true;
        i = 0;
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

    TC_PeriodicCallback(100, timer_callback);

    //Main initialisations
    char_display_init();
    switches_init();

    CDCDSerialDriver_Initialize();
    VBus_Configure();

    proto_init(ADDR_COMMS);

    unsigned int responses;

    message_t msg;
    message_t broadcast_message = {
        .from     = ADDR_COMMS,
        .to       = ADDR_BROADCAST_RX,
        .command  = CMD_NONE,
        .data_len = 0
    };


    while(1) {    
        switch (proto_state()) {
            case STARTUP:
                // Probe all board periodically
                if (timeout) {
                    responses = 0;
                    broadcast_message.command = CMD_REQ_CALIBRATE;
                    proto_write(broadcast_message);
                    timeout = false;
                } 

                // Check any responses
                msg = proto_read();
                switch(msg.command) {
                    case CMD_ACK_CALIBRATE:
                        responses |= 1 << msg.from; 
                        break;
                    case CMD_NONE:
                        break;
                    default:
                        TRACE_ERROR("Invalid command %i received in startup state", msg.command);
                        proto_state_error();
                        break;
                }

                // Check to see if all boards have acked
                if (responses == ALL_CLIENTS) {
                    char_display_number(24);
                    broadcast_message.command = CMD_CALIBRATE;
                    proto_write(broadcast_message);
                    proto_state_transition(CALIBRATING);
                    responses = 0;
                }

                break;

            case CALIBRATING:
                // Request a transition periodically
                if (timeout) {
                    responses = 0;
                    broadcast_message.command = CMD_REQ_RUN;
                    proto_write(broadcast_message);
                    timeout = false;
                } 

                // Check any responses
                msg = proto_read();
                switch(msg.command) {
                    case CMD_NONE:
                        break;

                    // A board acked, add its bit to the response list
                    case CMD_ACK_RUN: 
                        responses |= 1 << msg.from; 
                        break;
                        
                    // A board is refusing the transition
                    case CMD_NO:
                        break;

                    // Invalid response
                    default:
                        TRACE_ERROR("Invalid command %i received in calibrating state", msg.command);
                        proto_state_error();
                        break;
                }

                // Check if all clients have acked
                if (responses == ALL_CLIENTS) {
                    char_display_number(72);
                    broadcast_message.command = CMD_RUN;
                    proto_write(broadcast_message);
                    proto_state_transition(RUNNING);
                }

                break;

            case RUNNING: // Normal state

                CDCDSerialDriver_Read(usbBuffer, DATABUFFERSIZE, UsbDataReceived, 0);
                if (usb_msg.command != CMD_NONE) {
                    // TODO
                    // Set setpoints
                    // Send set points
                    // Check for acks
                    // Receive data from sensor
                    // Forward sensor data to laptop
                }

                // TODO Valid reponses received so refresh the protocol timer
                proto_refresh();

                break;
            default: // ERROR
                if (timeout) {
                    responses = 0;
                    broadcast_message.to = ADDR_BROADCAST_RX;
                    broadcast_message.command = CMD_ERROR;
                    proto_write(broadcast_message);
                    timeout = false;
                } 
                //TODO send ERROR signal through USB
                break;
        }
    }
}

