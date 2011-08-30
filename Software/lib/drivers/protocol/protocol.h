#include <peripherals/can/can.h>

#define BAUD_RATE 1000 // allowed values: 1000, 800, 500, 250, 125, 50, 25, 10
#define TIMEOUT 2000 // May be replaced by a variable

typedef enum {INITIALISING, WAITING, RUNNING, ERROR} state_t;


/**
 * Initialises the protocol handler and the can bus. 
 * 
 */
void proto_init();


/**
 * Depending on demand this function may need a different
 * signature. For now it is designed to pop an int off the end of a queue
 * or return 0 if no data has been receieved
 */
int proto_read();

/**
 * Depending on demand this function may need a different
 * signature. For now it is written assuming CAN writes are
 * asynchronous.
 */
void proto_write(unsigned int hi, unsigned int lo);

/**
 * To be called when an arbitrary 'heartbeat' message is received
 */
void proto_refresh();

/**
 * Blocks until all other boards are ready.
 */
void wait_on_others();

/**
 * A getter for the can handler's state
 */
state_t proto_state();
