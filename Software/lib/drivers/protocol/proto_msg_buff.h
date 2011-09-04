/**
 * This is part of the internal implementation of the protocol.
 *
 * DO NOT INCLUDE.
 *
 */
#ifndef PROTO_MSG_BUFF_H
#define PROTO_MSG_BUFF_H

#include <stdbool.h>

#include "definitions.h"

/**
 * A simple ring buffer used to store recieved messages until they are read.
 */

/**
 * Returns how many messages are currently in the buffer.
 */
unsigned int proto_msg_buff_length();

/**
 * Returns and removes the first message from the buffer.
 */
message_t proto_msg_buff_pop();

/**
 * Returns without removing the first message from the buffer.
 */
message_t proto_msg_buff_peek();

/**
 * Pushes a new message onto the buffer.  Returns whether a message was deleted
 * when pushing the message, i.e. true is an error state.
 */
bool proto_msg_buff_push(message_t);

#endif /* PROTO_MSG_BUFF_H */
