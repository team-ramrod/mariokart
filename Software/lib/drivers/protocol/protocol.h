#include <peripherals/can/can.h>
#include <board.h>
#include <pio/pio.h>
#include <irq/irq.h>

#define BAUD_RATE 1000 // allowed values: 1000, 800, 500, 250, 125, 50, 25, 10
#define TIMEOUT 2000 // May be replaced by a variable

typedef enum {INITIALISING, WAITING, RUNNING, ERROR} state_t;

// Needs to be only 8 bit
typedef enum {
    ADDR_ERROR_RX     = 0x0,
    ADDR_BROADCAST_RX = 0x1,
    ADDR_BROADCAST_TX = 0x2,
    ADDR_BRAKE        = 0x3,
    ADDR_COMMS        = 0x4,
    ADDR_STEERING     = 0x5,
    ADDR_MOTOR        = 0x6,
    ADDR_SENSOR       = 0x7,
} address_t;

// Needs to be only 8 bit
typedef enum {
    CMD_NONE  = 0x0,
    CMD_GET   = 0x1,
    CMD_REPLY = 0x2,
} command_t;

typedef struct {
    address_t     from,
                  to;
    command_t     command;
    unsigned char data[8];
} message_t;

typedef enum {
    VAR_SPEED = 0x1,
} variable_t;

/**
 * Initialises the protocol handler and the can bus. 
 * 
 * Make sure when giving any of the masks you put the identifier in the lowest
 * 11 bits.
 *
 * @param host boards address
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
 * Blocks until comms board gives the OK.
 */
void proto_wait();

/**
 * Blocks until all other boards are ready.
 */
void proto_comms_wait();

/**
 * A getter for the can handler's state
 */
state_t proto_state();
