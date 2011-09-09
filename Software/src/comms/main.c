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
#define ALL_CLIENTS ((1<<ADDR_BRAKE) | (1<<ADDR_MOTOR)| (1<<ADDR_STEERING) )

volatile bool timeout = false;

message_t brake_msg = {
    .from = ADDR_COMMS,
    .to   = ADDR_BRAKE,
    .command = CMD_SET,
    .data = {
        VAR_BRK_POS,
        0
    }
};
message_t steering_msg = {
    .from = ADDR_COMMS,
    .to   = ADDR_STEERING,
    .command = CMD_SET,
    .data = {
        VAR_STEERING_ANGLE,
        0
    }
};
message_t motor_msg = {
    .from = ADDR_COMMS,
    .to   = ADDR_MOTOR,
    .command = CMD_SET,
    .data = {
        VAR_SPEED,
        0
    }
};

typedef bool(*output_send_t)(void);

static volatile message_t received_ack;

static unsigned int transmission_wait = 0;

/**
 * Blocks until the most recent message sent or times out
 * @return true if the message sent, false otherwise
 */
bool wait_on_ack(message_t msg) {
    transmission_wait = 0;
    while ( (received_ack.from != msg.to) && (received_ack.data[0] != msg.data[0]) ) {
        if (transmission_wait > 3) {
            BCAN_AbortTransfer(0, msg.to);
            return false;
        }
    }
    return true;
}

bool send_brake_value(void) {
    proto_write(brake_msg);
    return wait_on_ack(brake_msg);
}

bool send_steering_value(void){
    proto_write(steering_msg);
    return wait_on_ack(steering_msg);
}

bool send_motor_value(void){
    proto_write(motor_msg);
    return wait_on_ack(motor_msg);
}

bool check_speed_timeout(void){
    return true;
}


void timer_callback(void) {
    static int i = 0;

    // Update the display
    char_display_tick();
    transmission_wait++;
    AT91C_BASE_TC1->TC_SR;
    if (i++ > 10) {
        // A flag used to run periodic events in the background
        timeout = true;
        i = 0;
    }
}


int main(int argc, char *argv[]) {
    debug_init(SOFTWARE_NAME);

    unsigned int num_output_boards = 3;
    output_send_t output_board_send[] = {
        send_motor_value,
        send_brake_value,
        send_steering_value,
    };

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    TC_PeriodicCallback(100, timer_callback);

    //Main initialisations
    char_display_init();
    switches_init();

    UsbInit();

    proto_init(ADDR_COMMS);

    unsigned int responses;

    message_t msg, usb_msg;
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
                        TRACE_ERROR("Invalid command %i received in startup state\n\r", msg.command);
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
                        TRACE_ERROR("Invalid command %i received in calibrating state\n\r", msg.command);
                        proto_state_error();
                        break;
                }

                // Check if all clients have acked
                if (responses == ALL_CLIENTS) {
                    broadcast_message.command = CMD_RUN;
                    proto_write(broadcast_message);
                    proto_state_transition(RUNNING);
                }

                break;

            case RUNNING: // Normal state

                usb_msg = UsbRead();
                if (usb_msg.command != CMD_NONE) {
                    proto_write(usb_msg);
                    // TODO
                    // Set setpoints
                    // Send set points
                    // Check for acks
                    // Receive data from sensor
                    // Forward sensor data to laptop

                    // Clear message
                    usb_msg.command = CMD_NONE;
                }

                if (timeout) {
                    for (int i = 0; i < num_output_boards; i++) {
                        
                        if (!output_board_send[i]()) {
                            TRACE_WARNING("Message not sent\n\r");
                            proto_state_error();
                        }
                    }
                    //TODO
                    //sensor req
                    //wait on sensor receive
                    proto_refresh();
                }

                // Check any responses
                msg = proto_read();
                switch(msg.command) {
                    case CMD_NONE:
                        break;
                        
                    // A board is refusing the transition
                    case CMD_REPLY:
                        // TODO: sensor data retrieved
                        break;

                    case CMD_ACK_SET:
                        received_ack = msg;
                        break;

                    // Invalid response
                    default:
                        TRACE_ERROR("Invalid command %i received in calibrating state\n\r", msg.command);
                        proto_state_error();
                        break;
                }

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

