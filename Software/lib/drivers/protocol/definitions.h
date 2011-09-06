/**
 * This header is automatically included as part of `protocol.h`, do not include
 * it yourself.
 */

#ifndef PROTOCOL_DEFINITIONS_H
#define PROTOCOL_DEFINITIONS_H

/**
 * See
 * https://github.com/team-ramrod/mariokart/wiki/Protocol
 * for a more in-depth decription of the protocol.
 */

// Needs to be only 3 bit
typedef enum {
    ADDR_ERROR_RX         = 0x00,
    ADDR_BROADCAST_RX     = 0x01,
    ADDR_BROADCAST_TX     = 0x02,
    ADDR_BRAKE            = 0x03,
    ADDR_COMMS            = 0x04,
    ADDR_COMMS_USB        = 0x04,
    ADDR_STEERING         = 0x05,
    ADDR_MOTOR            = 0x06,
    ADDR_SENSOR           = 0x07,
} address_t;

// Needs to be only 8 bit
typedef enum {
    CMD_NONE              = 0x00,
    CMD_GET               = 0x01,
    CMD_REPLY             = 0x02,
    CMD_SET               = 0x03,
    CMD_REQ_CALIBRATE     = 0x04,
    CMD_ACK_CALIBRATE     = 0x05,
    CMD_REQ_RUN           = 0x06,
    CMD_ACK_RUN           = 0x07,
    CMD_NO                = 0x08,
    CMD_ERROR             = 0x09,
    CMD_RUN               = 0x0A,
    CMD_CALIBRATE         = 0x0B,
} command_t;

typedef enum {STARTUP, CALIBRATING, RUNNING, ERROR} state_t;

typedef enum {
    VAR_SPEED   = 0x01,
    VAR_BRK_POS = 0x02,
} variable_t;

typedef struct {
    address_t     from,
                  to;
    command_t     command;
    unsigned char data_len;
    unsigned char data[5];
} message_t;

#endif
