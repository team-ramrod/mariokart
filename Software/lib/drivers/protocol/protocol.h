#ifndef PROTOCOL_H
#define PROTOCOL_H

#include <board.h>
#include <pio/pio.h>
#include <irq/irq.h>

#include "definitions.h"

#define BAUD_RATE 1000 // allowed values: 1000, 800, 500, 250, 125, 50, 25, 10
#define TIMEOUT 200000 // May be replaced by a variable


// For error state callback
typedef void(*error_callback)( void );

/**
 * Initialises the protocol handler and the can bus. 
 * 
 * @param host boards address e.g. ADDR_SENSOR
 */
void proto_init(address_t board_address);

/**
 * Depending on demand this function may need a different
 * signature. For now it is designed to pop an int off the end of a queue
 * or return 0 if no data has been receieved
 */
message_t proto_read();

/**
 * Depending on demand this function may need a different
 * signature. For now it is written assuming CAN writes are
 * asynchronous.
 */
int proto_write(message_t msg);


/**
 * To be called when an arbitrary 'heartbeat' message is received
 */
void proto_refresh();


/**
 * A getter for the can handler's state
 */
state_t proto_state();

/**
 * To be called by the client when it is ready to move
 * past the calibration state. Nilpotent.
 */
void proto_calibration_complete();

/**
 * Set the callback function that is called when error state is set
 */
void proto_set_error_callback(error_callback callback);

/**
 * Drop the can handler into error state then calls the error state callback
 */
void proto_state_error();

#endif /* PROTOCOL_H */
