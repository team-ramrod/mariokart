/**
 * This file will be closer to completion once I can work out
 * timers, the CAN lib and interrupts.
 */

#include "protocol.h"

// The structures for reading and writing to CAN
static CanTransfer read_transfer, write_transfer;

// The current state as per our state diagram
static state state_t state;

// The watchdog timer
static volatile int wait_timer = 0;

/**
 * Initialises the protocol handler and the can bus. 
 * 
 */
void proto_init() {
    state = INITIALISING;
    if (!CAN_Init(BAUD_RATE, &read_transfer, &write_transfer)) {
        state = ERROR;
    }
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
 * Depending on demand this function may need a different
 * signature. For now it is written assuming CAN writes are
 * asynchronous.
 */
void proto_write(int msg) {
    write_transfer.data_low_reg = msg;
    if (!CAN_Write(write_transfer)) {
        state = ERROR;
    }
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
    
