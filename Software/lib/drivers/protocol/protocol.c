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

#define PROTO_ADDR_PRIORITY 0x0001
#define PROTO_ADDR_SUFFEX 0x1000

// The current state as per our state diagram
static state_t state;

// The watchdog timer
static volatile int wait_timer = 0;

static error_callback error_callback_function = NULL;

static bool ready_to_run = false;

//------------------------------------------------------------------------------
/// Interrupt handler for TC0 interrupt.
//------------------------------------------------------------------------------
void ISR_Tc0(void)
{
    // Clear status bit to acknowledge interrupt
    AT91C_BASE_TC0->TC_SR;

    wait_timer += 250;

    if (wait_timer >= TIMEOUT) {
        state = ERROR;
    }
}

//------------------------------------------------------------------------------
/// Internal function for setting up a tx mailbox
//------------------------------------------------------------------------------
void proto_set_tx_mailbox(address_t from_address, address_t dest_address) {
    unsigned int full_address, can_number, mailbox_number, acceptance_mask;
    unsigned int identifier, mode_reg, control_reg;

    full_address = (PROTO_ADDR_PRIORITY << 7) + (dest_address << 4) +
        (PROTO_ADDR_SUFFEX << 0);

    can_number = 0;
    mailbox_number = from_address;
    acceptance_mask = AT91C_CAN_MIDvA & (full_address << 18); //0b00001111111
    identifier = AT91C_CAN_MIDvA & (full_address << 18);
    mode_reg = AT91C_CAN_MOT_TX;
    control_reg = 0x00000000;
    BCAN_InitMailboxRegisters(can_number, mailbox_number, acceptance_mask, identifier,
            mode_reg, control_reg);
}

//------------------------------------------------------------------------------
/// Internal function for setting up a rx mailbox
//------------------------------------------------------------------------------
void proto_set_rx_mailbox(address_t rx_address) {
    unsigned int full_address, can_number, mailbox_number, acceptance_mask;
    unsigned int identifier, mode_reg, control_reg;
    
    full_address = (PROTO_ADDR_PRIORITY << 7) + (rx_address << 4) + (PROTO_ADDR_SUFFEX << 0);

    can_number = 0;
    mailbox_number = rx_address;
    acceptance_mask = 0x07F; // ignore the first 3 bits
    identifier = AT91C_CAN_MIDvA & (full_address << 18);
    mode_reg = AT91C_CAN_MOT_RXOVERWRITE;
    control_reg = 0x0;
    BCAN_InitMailboxRegisters(can_number, mailbox_number, acceptance_mask, identifier, mode_reg, control_reg);
}

//------------------------------------------------------------------------------
/// Configure Timer Counter 0 to generate an interrupt every 250ms.
// TODO: change this to a higher frequency for better accuracy
//------------------------------------------------------------------------------
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
 *
 */
void proto_init(address_t board_address) {
    TRACE_INFO("Running proto_init\n\r");
    state = STARTUP;

    // Init incoming mailbox
    BCAN_Init(BAUD_RATE, 0); // 0 for no CAN1

    // Init Error rx mailbox
    proto_set_rx_mailbox(ADDR_ERROR_RX);

    // Init ADDR_BROADCAST_RX mailbox
    proto_set_rx_mailbox(ADDR_BROADCAST_RX);

    // Init ADDR_BROADCAST_TX mailbox
    proto_set_tx_mailbox(ADDR_BROADCAST_TX,ADDR_BROADCAST_RX);

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
            TRACE_WARNING("An incorrect address was passed to proto_init();\n\r");
            break;
    }

    ConfigureTc();
}

/**
 * Depending on demand this function may need a different
 * signature. For now it is designed to pop an int off the end of a queue
 * or return 0 if no data has been receieved
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
 * To be called asynchronously when a new can frame is
 * received. Decodes packets and intercepts state transition
 * commands.
 */
void message_handler(CAN_Packet packet) {
    message_t msg = {
        .from    = (packet.data_high >> 0x18) & 0xFF,
        .to      = (packet.data_high >> 0x10) & 0xFF,
        .command = (packet.data_high >> 0x08) & 0xFF,
        .data    = {0x0}
    };
    msg.data[0] = packet.data_high & 0xFF;
    msg.data[1] = (packet.data_low >> 0x18) & 0xFF;
    msg.data[2] = (packet.data_low >> 0x10) & 0xFF;
    msg.data[3] = (packet.data_low >> 0x08) & 0xFF;
    msg.data[4] =  packet.data_low          & 0xFF;
    
    msg.data_len = packet.msg_len;

    switch (state) {
        case STARTUP:
            switch (msg.command) {
                case CMD_REQ_CALIBRATE:
                    //send CMD_ACK_CALIBRATE
                    break;
                case CMD_CALIBRATE:
                    state = CALIBRATING;
                    break;
                default:
                    state = ERROR;
                    break;
            }
            break;
        case CALIBRATING:
            switch(msg.command) {
                case CMD_REQ_CALIBRATE:
                    if (ready_to_run) 
                        //send CMD_ACK_RUN
                    else 
                        //send CMD_NO
                    break;
                case CMD_RUN:
                    state = RUNNING;
                    break;
                default:
                    state = ERROR;
                    break;
            }
            break;
        case RUNNING:
            proto_msg_buff_push(msg);
            break;
        case ERROR:
            break;
        default:
            state = ERROR;
            break;
    }
}

void proto_calibration_complete() {
    ready_to_run = true;
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

    can_data_high = ((msg.to & 0xFF) << 0x18)
                  | ((msg.from & 0xFF) << 0x10)
                  | ((msg.command & 0xFF) << 0x08)
                  |  msg.data[0];
    can_data_low  = (msg.data[1] << 0x18)
                  | (msg.data[2] << 0x10)
                  | (msg.data[3] << 0x08)
                  |  msg.data[4];

    return BCAN_Write(can_num, msg.to, can_data_high, can_data_low, msg.data_len + 3);
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
    state = ERROR;
    if (error_callback_function != NULL) {
        error_callback_function();
    }
}

