/**
 * This file will be closer to completion once I can work out
 * timers, the CAN lib and interrupts.
 */

#include "protocol.h"

// The structures for reading and writing to CAN
static CanTransfer read_transfer, write_transfer;

// The current state as per our state diagram
static state_t state;

// The watchdog timer
static volatile int wait_timer = 0;

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
    CAN_InitMailboxRegisters( &read_transfer );

    // Init outgoing mailbox
    write_transfer.can_number = 0;
    write_transfer.mailbox_number = 1;
    write_transfer.mode_reg = AT91C_CAN_MOT_TX | AT91C_CAN_PRIOR;
    write_transfer.acceptance_mask_reg = AT91C_CAN_MIDvA & (1<<(18+5));// ID 11 TODO: these too
    write_transfer.identifier = AT91C_CAN_MIDvA & (1<<(18+5));     // ID 11
    write_transfer.control_reg = (AT91C_CAN_MDLC & (0x8<<16)); // Mailbox Data Length Code
    CAN_InitMailboxRegisters( &write_transfer );

    ConfigureTc();
}

//------------------------------------------------------------------------------
/// Interrupt handler for TC0 interrupt. 
//------------------------------------------------------------------------------
void ISR_Tc0(void)
{
    // Clear status bit to acknowledge interrupt
    AT91C_BASE_TC0->TC_SR;

    wait_timer += 250;

    if (wait_timer >= TIMEOUT) {
        state = error;
    }
}

//------------------------------------------------------------------------------
/// Configure Timer Counter 0 to generate an interrupt every 250ms.
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
 * Depending on demand this function may need a different
 * signature. For now it is designed to pop an int off the end of a queue
 * or return 0 if no data has been receieved
 */
int proto_read() {
    return 0;
}


/**
 * Attempts a write and returns status code (success == 0)
 */
int proto_write(unsigned int hi, unsigned int lo) {
    write_transfer.data_high_reg = hi;
    write_transfer.data_low_reg = lo;
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
 */
void wait_on_others() {
    int ready_count = 0; // May be better of as a bit mask or something else
    state = WAITING;
    while (ready_count < 5) {
        //listen for waiting messages and note how many are ready
    }
}

/**
 * A getter for the can handler's state
 */
state_t proto_state() {
    return state;
}

/**
 * An timer driven interrupt that needs to repeat somewhere near millisecond intervals
 */ 
void timer_interrupt(void) {
    if (wait_timer++ > TIMEOUT) {
        state = ERROR;
    }
}

