/**
 * This file will be closer to completion once I can work out
 * the CAN lib.
 */

#include "protocol.h"
#include "proto_msg_buff.h"
#include <better_can/can.h>
#include <tc/tc.h>
#include <aic/aic.h>
#include <utility/trace.h>
#include <components/char_display.h>

#define PROTO_ADDR_PRIORITY 0b0001
#define PROTO_ADDR_SUFFEX 0b1000

#define ACK_TIMEOUT 500

#define DEBUG_STATES //TODO: deleteme

// The current state as per our state diagram
static state_t state;

// The watchdog timer
static volatile int wait_timer = 0;

// The client function to call when entering the error state 
static error_callback error_callback_function = NULL;

// Set by the client when it is finished calibration
static bool ready_to_run = false;

// The address of current board
static address_t local_address;

// The message to broadcast when in error state
static message_t error_message;

// Forward declarations
unsigned int message_handler(CAN_Packet packet);

/**
 * Interrupt handler for TC0, increments a counter and checks
 * to see if the the program has timed out. Sends the board into
 * and error state if this happens.
 */
void ISR_Tc0(void)
{
    // Clear status bit to acknowledge interrupt
    AT91C_BASE_TC0->TC_SR;

    if (state == RUNNING) {
        wait_timer += 250;
        if (wait_timer >= TIMEOUT ) {
            TRACE_WARNING("Timeout while running\n\r");
            proto_state_error();
        }
    }

    // broadcast the error message
    if (state == ERROR) 
        proto_write(error_message);
}

/**
 * A setter function to drive state changes.
 * Only available through protocol_master.h
 */
void proto_state_transition(state_t new_state) {
    state = new_state;

#ifdef DEBUG_STATES
    switch (state) {
        case STARTUP:
            char_display_number(11);
            break;
        case CALIBRATING:
            char_display_number(22);
            break;
        case RUNNING:
            char_display_number(33);
            break;
        default:
            char_display_number(44);
            break;
    }
#endif
}

/*
 * Internal function for setting up a tx mailbox
 */
void proto_set_tx_mailbox(address_t from_address, address_t dest_address) {
    unsigned int full_address, can_number, mailbox_number, acceptance_mask;
    unsigned int identifier, mode_reg, control_reg;

    full_address = ((PROTO_ADDR_PRIORITY & 0b1111) << 7) | ((dest_address & 0b111) << 4) |
        ((PROTO_ADDR_SUFFEX & 0b1111) << 0);

    can_number = 0;
    mailbox_number = from_address;
    acceptance_mask = AT91C_CAN_MIDvA & (full_address << 18); //0b00001111111
    identifier = AT91C_CAN_MIDvA & (full_address << 18);
    mode_reg = AT91C_CAN_MOT_TX;
    control_reg = 0x00000000;
    BCAN_InitMailboxRegisters(can_number, mailbox_number, acceptance_mask, identifier,
            mode_reg, control_reg);
}

/**
 * Internal function for setting up a rx mailbox
 */
void proto_set_rx_mailbox(address_t rx_address) {
    unsigned int full_address, can_number, mailbox_number, acceptance_mask;
    unsigned int identifier, mode_reg, control_reg;

    full_address = ((PROTO_ADDR_PRIORITY & 0b1111) << 7) | ((rx_address & 0b111) << 4) |
        ((PROTO_ADDR_SUFFEX & 0b1111) << 0);

    can_number = 0;
    mailbox_number = rx_address;
    acceptance_mask = 0x07F; // ignore the first 3 bits
    identifier = AT91C_CAN_MIDvA & (full_address << 18);
    mode_reg = AT91C_CAN_MOT_RXOVERWRITE;
    control_reg = 0x0;
    BCAN_InitMailboxRegisters(can_number, mailbox_number, acceptance_mask, identifier, mode_reg, control_reg);
}



/**
 * Configure Timer Counter 0 to generate an interrupt every 250ms.
 * TODO: change this to a higher frequency for better accuracy
 */
void ConfigureTc(void)
{
    unsigned int div;
    unsigned int tcclks;

    // Enable peripheral clock
    AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_TC0;

    // Configure TC for a 4Hz frequency and trigger on RC compare
    TC_FindMckDivisor(4, BOARD_MCK, &div, &tcclks);
    TC_Configure(AT91C_BASE_TC0, tcclks | AT91C_TC_CPCTRG);
    AT91C_BASE_TC0->TC_RC = (BOARD_MCK / div) / 4; // timerFreq / desiredFreq

    // Configure and enable interrupt on RC compare
    AIC_ConfigureIT(AT91C_ID_TC0, AT91C_AIC_PRIOR_LOWEST, ISR_Tc0);
    AT91C_BASE_TC0->TC_IER = AT91C_TC_CPCS;
    AIC_EnableIT(AT91C_ID_TC0);

    TC_Start(AT91C_BASE_TC0);
}



/**
 * Initialises the protocol handler and the can bus.
 * @param board_address the address of the local board
 */
void proto_init(address_t board_address) {
    TRACE_INFO("Running proto_init\n\r");
    proto_state_transition(STARTUP);

    local_address = board_address;

    // Init incoming mailbox
    BCAN_Init(BAUD_RATE, 0, message_handler); // 0 for no CAN1

    // Init Error rx mailbox
    proto_set_rx_mailbox(ADDR_ERROR_RX);

    // Init ADDR_BROADCAST_RX mailbox
    proto_set_rx_mailbox(ADDR_BROADCAST_RX);

    // Init ADDR_BROADCAST_TX mailbox
    proto_set_tx_mailbox(ADDR_BROADCAST_TX,ADDR_BROADCAST_RX);

    // Set up the error broadcast message
    error_message.from     = board_address;
    error_message.to       = ADDR_BROADCAST_RX;
    error_message.command  = CMD_ERROR;
    error_message.data_len = 0;
                                
    switch (board_address) {
        case ADDR_BRAKE:
            proto_set_rx_mailbox(ADDR_BRAKE);
            proto_set_tx_mailbox(ADDR_COMMS,ADDR_COMMS);
            proto_set_tx_mailbox(ADDR_STEERING,ADDR_STEERING);
            proto_set_tx_mailbox(ADDR_MOTOR,ADDR_MOTOR);
            proto_set_tx_mailbox(ADDR_SENSOR,ADDR_SENSOR);
            break;
        case ADDR_COMMS:
            proto_set_tx_mailbox(ADDR_BRAKE,ADDR_BRAKE);
            proto_set_rx_mailbox(ADDR_COMMS);
            proto_set_tx_mailbox(ADDR_STEERING,ADDR_STEERING);
            proto_set_tx_mailbox(ADDR_MOTOR,ADDR_MOTOR);
            proto_set_tx_mailbox(ADDR_SENSOR,ADDR_SENSOR);
            break;
        case ADDR_STEERING:
            proto_set_tx_mailbox(ADDR_BRAKE,ADDR_BRAKE);
            proto_set_tx_mailbox(ADDR_COMMS,ADDR_COMMS);
            proto_set_rx_mailbox(ADDR_STEERING);
            proto_set_tx_mailbox(ADDR_MOTOR,ADDR_MOTOR);
            proto_set_tx_mailbox(ADDR_SENSOR,ADDR_SENSOR);
            break;
        case ADDR_MOTOR:
            proto_set_tx_mailbox(ADDR_BRAKE,ADDR_BRAKE);
            proto_set_tx_mailbox(ADDR_COMMS,ADDR_COMMS);
            proto_set_tx_mailbox(ADDR_STEERING,ADDR_STEERING);
            proto_set_rx_mailbox(ADDR_MOTOR);
            proto_set_tx_mailbox(ADDR_SENSOR,ADDR_SENSOR);
            break;
        case ADDR_SENSOR:
            proto_set_tx_mailbox(ADDR_BRAKE,ADDR_BRAKE);
            proto_set_tx_mailbox(ADDR_COMMS,ADDR_COMMS);
            proto_set_tx_mailbox(ADDR_STEERING,ADDR_STEERING);
            proto_set_tx_mailbox(ADDR_MOTOR,ADDR_MOTOR);
            proto_set_rx_mailbox(ADDR_SENSOR);
            break;
        default:
            TRACE_ERROR("An incorrect address was passed to proto_init();\n\r");
            break;
    }

    ConfigureTc();
}

/**
 * Sends a command without data back to the comms board.
 * Times out and clears sending buffer if connection unavailable
 */
unsigned int reply_to_comms(command_t cmd) { 
    message_t reply = {
        .from     = local_address,
        .to       = ADDR_COMMS,
        .command  = cmd,
        .data_len = 0,
    };

    wait_timer = 0;
    while (CAN_STATUS_SUCCESS != proto_write(reply) && wait_timer < ACK_TIMEOUT);
    return (wait_timer > ACK_TIMEOUT) ? CAN_STATUS_ABORTED : CAN_STATUS_SUCCESS;
}


/**
 * Returns the most recent message available to the
 * client. The command field reads: CMD_NONE if the
 * buffer is empty
 */
message_t proto_read() {
    message_t msg = {
        .from    = 0x0,
        .to      = 0x0,
        .command = CMD_NONE,
        .data    = {0x0}
    };
    if (proto_msg_buff_length()) {
        msg = proto_msg_buff_pop();
    }
    return msg;
}



/**
 * To be called when a new can frame is received.
 * Decodes packets and intercepts state transition commands.
 */
unsigned int message_handler(CAN_Packet packet) {
    message_t msg = {
        .from     = (packet.data_high >> 0x10) & 0xFF,
        .to       = (packet.data_high >> 0x18) & 0xFF,
        .command  = (packet.data_high >> 0x08) & 0xFF,
        .data_len = packet.size - 3,
        .data[0]  = packet.data_high & 0xFF,
        .data[1]  = (packet.data_low >> 0x18) & 0xFF,
        .data[2]  = (packet.data_low >> 0x10) & 0xFF,
        .data[3]  = (packet.data_low >> 0x08) & 0xFF,
        .data[4]  =  packet.data_low          & 0xFF,
    };

    TRACE_DEBUG("Incoming Packet\n\r\n\r"
            "from\t%i\n\r" 
            "to\t%i\n\r"
            "command\t%i\n\r"
            "data_len\t%i\n\r"
            "packet-mailbox\t%i\n\r"
            "packet-hi\t%i\n\r"
            "packet-low\t%i\n\r\n\r",
            msg.from, msg.to, msg.command, msg.data_len,
            packet.mailbox, packet.data_high,packet.data_low);

    // Short circuit the message handling for the comms board.
    if (local_address == ADDR_COMMS) {
        proto_msg_buff_push(msg);
        return 1;
    }

    unsigned int result;

    //For all client boards: control the boards state based on incoming messages while not in RUNNING mode
    switch (state) {
        case STARTUP:
            switch (msg.command) {
                // Ackknowledge master requests to transition to calibration state
                case CMD_REQ_CALIBRATE:
                    if (CAN_STATUS_SUCCESS != reply_to_comms(CMD_ACK_CALIBRATE)) {
                        TRACE_WARNING("Failed to ack CMD_REQ_CALIBRATE\n\r");
                        proto_state_error();
                    }

                    break;

                    // Transition to calibration state at master boards command
                case CMD_CALIBRATE:
                    proto_state_transition(CALIBRATING);
                    break;

                default:
                    TRACE_WARNING("Unknown command %i during startup\n\r", msg.command);
                    proto_state_error();
                    break;
            }
            break;
        case CALIBRATING:
            switch(msg.command) {
                // Respond to master requests to transition to run state
                case CMD_REQ_RUN:
                    if (ready_to_run)
                        result = reply_to_comms(CMD_ACK_RUN);
                    else 
                        result = reply_to_comms(CMD_NO);

                    if (CAN_STATUS_SUCCESS != result) {
                        TRACE_WARNING("Failed to ack/deny CMD_REQ_CALIBRATE\n\r");
                        proto_state_error();
                    }
                    break;

                    // Transition to run state at master boards command
                case CMD_RUN:
                    proto_refresh();
                    proto_state_transition(RUNNING);
                    break;

                default:
                    TRACE_WARNING("Unknown command %i during calibration\n\r", msg.command);
                    proto_state_error();
                    break;
            }
            break;
        case RUNNING:
            // Pass all messages on to the client
            proto_msg_buff_push(msg);
            break;
        case ERROR:
            break;
        default:
            TRACE_WARNING("Unknown state\n\r");
            proto_state_error();
            break;
    }
    return 1;
}

/**
 * Called by the client once they are
 * ready to move past the calibration state.
 */
void proto_calibration_complete() {
    ready_to_run = true;
}   

/**
 * Blocks until the most recent message sent or times out
 * @return true if the message sent, false otherwise
 */
bool proto_wait_on_send() {
    //TODO 
    return true;
}

/**
 * Attempts a write and returns status code (success == 0)
 */
int proto_write(message_t msg) {
    unsigned int can_data_low = 0, can_data_high;
    int can_num = 0;

    TRACE_INFO("Proto Transmit to: %02d - Command: %d\n\r",
            msg.to,
            msg.command);

    can_data_high =
        ((msg.from & 0xFF)     << 0x10)
        | ((msg.to & 0xFF)       << 0x18)
        | ((msg.command & 0xFF)  << 0x08)
        |  msg.data[0];
    can_data_low  = (msg.data[1] << 0x18)
        | (msg.data[2]           << 0x10)
        | (msg.data[3]           << 0x08)
        |  msg.data[4];

    return (msg.to == ADDR_BROADCAST_RX) ?
        BCAN_Write(
                can_num,
                ADDR_BROADCAST_TX, 
                can_data_high, 
                can_data_low,
                8) :
        BCAN_Write(
                can_num, 
                msg.to, 
                can_data_high, 
                can_data_low,
                8);
}


/**
 * To be called when an arbitrary 'heartbeat' message is received
 */
void proto_refresh() {
    wait_timer = 0;
}


/**
 * A getter for the can handler's state
 */
state_t proto_state() {
    return state;
}

/**
 * Set the callback function that is called when error state is set
 */
void proto_set_error_callback(error_callback callback) {
    error_callback_function = callback;
}

/**
 * Drop the can handler into error state then calls the error state callback
 */
void proto_state_error() {
    BCAN_AbortAllTransfers(0);
    proto_state_transition(ERROR);
    if (error_callback_function != NULL) {
        error_callback_function();
    }
}

