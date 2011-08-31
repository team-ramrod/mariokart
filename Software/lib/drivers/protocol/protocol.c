/**
 * This file will be closer to completion once I can work out
 * the CAN lib.
 */

#include "protocol.h"
#include <tc/tc.h>
#include <aic/aic.h>

// The structures for reading and writing to CAN
static CanTransfer read_transfer, write_transfer;

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
void proto_init(unsigned int acceptance_mask, 
                unsigned int* identifier_list, 
                unsigned int num_identifiers) {
    state = INITIALISING;

    // Init incoming mailbox
    CAN_ResetTransfer( &read_transfer );
    read_transfer.can_number = 0;
    read_transfer.mailbox_number = 0; //TODO: make a #define for these
    read_transfer.mode_reg = AT91C_CAN_MOT_RX;
    read_transfer.acceptance_mask_reg = AT91C_CAN_MIDvA;    // TODO: add in hash-definable values for these two
    read_transfer.identifier = AT91C_CAN_MIDvA;
    read_transfer.data_low_reg = 0x00000000;
    read_transfer.data_high_reg = 0x00000000;
    read_transfer.control_reg = 0x00000000;
    CAN_InitMailboxRegisters( &read_transfer ); //TODO: the two calls to this method will change the same
    // mailbox it registers it seems

    // Init outgoing mailbox
    write_transfer.can_number = 0;
    write_transfer.mailbox_number = 1;
    write_transfer.mode_reg = AT91C_CAN_MOT_TX;
    write_transfer.acceptance_mask_reg = AT91C_CAN_MIDvA & (1<<(18+5));// ID 11 TODO: these too
    write_transfer.identifier = AT91C_CAN_MIDvA & (1<<(18+5));     // ID 11
    write_transfer.control_reg = (AT91C_CAN_MDLC & (0x8<<16)); // Mailbox Data Length Code
    CAN_InitMailboxRegisters( &write_transfer );

    ConfigureTc();
}



/**
 * Depending on demand this function may need a different
 * signature. For now it is designed to pop an int off the end of a queue
 * or return 0 if no data has been receieved
 */
int proto_read(unsigned int* data) { //TODO: pick a max data size
    if (1) { //TODO: if read_transfer has new data
        *data = read_transfer.data_high_reg;
        return read_transfer.size;
    } else {
        return 0;
    }
}


/**
 * Attempts a write and returns status code (success == 0)
 */
int proto_write(unsigned int address, 
                unsigned char* data,
                unsigned char num_bytes) {
    // TODO: prepend DATA identifier and the to and from addresses
    //write_transfer.data_high_reg = hi;
    //write_transfer.data_low_reg = lo;
    return CAN_Write(&write_transfer);
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


