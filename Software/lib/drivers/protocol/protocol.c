/**
 * This file will be closer to completion once I can work out
 * the CAN lib.
 */

#include "protocol.h"
#include "proto_msg_buff.h"
#include <tc/tc.h>
#include <aic/aic.h>
#include <utility/trace.h>

#define PROTO_ADDR_PRIORITY 0x0001
#define PROTO_ADDR_SUFFEX 0x1000

// The structures for reading and writing to CAN
static CanTransfer canTransfer;

// The current state as per our state diagram
static state_t state;

// The watchdog timer
static volatile int wait_timer = 0;


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
void proto_set_tx_mailbox(address_t mailbox_num, address_t dest_addr) {
    unsigned int full_address;
    full_address = (PROTO_ADDR_PRIORITY << 7) + (dest_addr << 4) + (PROTO_ADDR_SUFFEX << 0);
    canTransfer.can_number = 0;
    canTransfer.mailbox_number = mailbox_num;
    canTransfer.mode_reg = AT91C_CAN_MOT_TX;
    canTransfer.acceptance_mask_reg = AT91C_CAN_MIDvA & (full_address << 18); //0b00001111111
    canTransfer.identifier = AT91C_CAN_MIDvA & (full_address << 18);
    canTransfer.data_low_reg = 0x00000000;
    canTransfer.data_high_reg = 0x00000000;
    canTransfer.control_reg = 0x00000000;
    CAN_InitMailboxRegisters( &canTransfer );
}

//------------------------------------------------------------------------------
/// Internal function for setting up a rx mailbox
//------------------------------------------------------------------------------
void proto_set_rx_mailbox(address_t addr, unsigned int acceptance_mask) {
    unsigned int full_address;
    full_address = (PROTO_ADDR_PRIORITY << 7) + (addr << 4) + (PROTO_ADDR_SUFFEX << 0);
    canTransfer.can_number = 0;
    canTransfer.mailbox_number = addr;
    canTransfer.mode_reg = AT91C_CAN_MOT_RXOVERWRITE;
    canTransfer.acceptance_mask_reg = AT91C_CAN_MIDvA & (acceptance_mask<<18); //0b00001111111
    canTransfer.identifier = AT91C_CAN_MIDvA & (full_address << 18);
    canTransfer.data_low_reg = 0x00000000;
    canTransfer.data_high_reg = 0x00000000;
    canTransfer.control_reg = 0x00000000;
    CAN_InitMailboxRegisters( &canTransfer );
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
    unsigned int address, acceptance_mask;

    state = INITIALISING;
    TRACE_INFO("Running proto_init\n\r");

    // Init incoming mailbox
    CAN_Init(BAUD_RATE, &canTransfer, NULL);
    CAN_ResetTransfer( &canTransfer );

    // Init Error rx mailbox
    address = (PROTO_ADDR_PRIORITY << 7) + (ADDR_ERROR_RX << 4) + (PROTO_ADDR_SUFFEX << 0);
    acceptance_mask = 0x07F;
    proto_set_rx_mailbox(address, acceptance_mask);

    // Init ADDR_BROADCAST_RX mailbox
    acceptance_mask = 0x07F;
    proto_set_rx_mailbox(ADDR_BROADCAST_RX, acceptance_mask);

    // Init ADDR_BROADCAST_TX mailbox
    proto_set_tx_mailbox(ADDR_BROADCAST_TX,ADDR_BROADCAST_RX);

    switch (board_address) {
        case ADDR_BRAKE:
            proto_set_rx_mailbox(ADDR_BRAKE,acceptance_mask);
            proto_set_tx_mailbox(ADDR_COMMS,ADDR_COMMS);
            proto_set_tx_mailbox(ADDR_STEERING,ADDR_STEERING);
            proto_set_tx_mailbox(ADDR_MOTOR,ADDR_MOTOR);
            proto_set_tx_mailbox(ADDR_SENSOR,ADDR_SENSOR);
            break;
        case ADDR_COMMS:
            proto_set_tx_mailbox(ADDR_BRAKE,ADDR_BRAKE);
            proto_set_rx_mailbox(ADDR_COMMS,acceptance_mask);
            proto_set_tx_mailbox(ADDR_STEERING,ADDR_STEERING);
            proto_set_tx_mailbox(ADDR_MOTOR,ADDR_MOTOR);
            proto_set_tx_mailbox(ADDR_SENSOR,ADDR_SENSOR);
            break;
        case ADDR_STEERING:
            proto_set_tx_mailbox(ADDR_BRAKE,ADDR_BRAKE);
            proto_set_tx_mailbox(ADDR_COMMS,ADDR_COMMS);
            proto_set_rx_mailbox(ADDR_STEERING,acceptance_mask);
            proto_set_tx_mailbox(ADDR_MOTOR,ADDR_MOTOR);
            proto_set_tx_mailbox(ADDR_SENSOR,ADDR_SENSOR);
            break;
        case ADDR_MOTOR:
            proto_set_tx_mailbox(ADDR_BRAKE,ADDR_BRAKE);
            proto_set_tx_mailbox(ADDR_COMMS,ADDR_COMMS);
            proto_set_tx_mailbox(ADDR_STEERING,ADDR_STEERING);
            proto_set_rx_mailbox(ADDR_MOTOR,acceptance_mask);
            proto_set_tx_mailbox(ADDR_SENSOR,ADDR_SENSOR);
            break;
        case ADDR_SENSOR:
            proto_set_tx_mailbox(ADDR_BRAKE,ADDR_BRAKE);
            proto_set_tx_mailbox(ADDR_COMMS,ADDR_COMMS);
            proto_set_tx_mailbox(ADDR_STEERING,ADDR_STEERING);
            proto_set_tx_mailbox(ADDR_MOTOR,ADDR_MOTOR);
            proto_set_rx_mailbox(ADDR_SENSOR,acceptance_mask);
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
 * Attempts a write and returns status code (success == 0)
 */
int proto_write(message_t* msg) {
    // TODO: someone check my endianness
    canTransfer.data_high_reg = hi;
    canTransfer.data_low_reg = 
        (unsigned char)(msg->from) |
        (unsigned char)(msg->to) << 8 |
        (unsigned char)(msg->command) << 16;

    if (msg->len > 0) {
        canTransfer.data_low_reg |=
            data[0];
    }

    for (int i = 1; i < msg->len; i++) {
        canTransfer.data_high_reg |= msg->data[i] << i*8;
    }

    canTransfer.size = msg->len;


    TRACE_INFO("Proto Transmit to: %02d - Command: %d\n\r",
            msg.to,
            msg.command);

    return CAN_Write(&canTransfer);
}

/**
 * To be called when an arbitrary 'heartbeat' message is received
 */
void proto_refresh() {
    wait_timer = 0;
}

/**
 * Blocks until all other boards are ready.
 * To be used before and after calibration routine.
 * On exit the board may be in error state so check state after this
 * method returns.
 */
void proto_wait() {
    //TODO: depending on the current state, wait on the correct signal from comms
    //if another signal is received then transition to error state and return
    int ready_count = 0; // May be better of as a bit mask or something else
    state = WAITING;
    while (ready_count < 5) {
        //listen for waiting messages and note how many are ready
    }
}

/**
 * TODO: a seperate function for the comms board to wait on other boards
 */
void proto_comms_wait() {
    // TODO: Depending on the current state, transmit state to client boards
    // and return once the have all ok'd, else return if incorrect reply is
    // received and transition into error state.
}

/**
 * A getter for the can handler's state
 */
state_t proto_state() {
    return state;
}


