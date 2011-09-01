#include "proto_msg_buff.h"

#include <utility/atomic.h>

#define BUFFER_SIZE 10
#define increment(pos) ((pos + 1) % BUFFER_SIZE)

message_t proto_msg_buff[BUFFER_SIZE] = { { 0x0 } };

unsigned int proto_msg_buff_read  = 0,
             proto_msg_buff_write = 0;

unsigned int proto_msg_buff_mutex = unlocked;

unsigned int proto_msg_buff_length() {
    unsigned int tmp = 0x0;

    lock_mutex(&proto_msg_buff_mutex);

    tmp = ((proto_msg_buff_write - proto_msg_buff_read) + BUFFER_SIZE) % BUFFER_SIZE;

    unlock_mutex(&proto_msg_buff_mutex);

    return tmp;
}

message_t proto_msg_buff_pop() {
    message_t tmp = { 0x0 };

    lock_mutex(&proto_msg_buff_mutex);

    if (proto_msg_buff_read != proto_msg_buff_write) {
        tmp = proto_msg_buff[proto_msg_buff_read];
        proto_msg_buff_read = increment(proto_msg_buff_read);
    }

    unlock_mutex(&proto_msg_buff_mutex);

    return tmp;
}

message_t proto_msg_buff_peek() {
    message_t tmp = { 0x0 };

    lock_mutex(&proto_msg_buff_mutex);

    if (proto_msg_buff_read != proto_msg_buff_write) {
        tmp = proto_msg_buff[proto_msg_buff_read];
    }

    unlock_mutex(&proto_msg_buff_mutex);

    return tmp;
}

bool proto_msg_buff_push(message_t msg) {
    bool tmp = false;

    lock_mutex(&proto_msg_buff_mutex);

    if (proto_msg_buff_read == increment(proto_msg_buff_write)) {
        proto_msg_buff_read = increment(proto_msg_buff_read);
        tmp = true;
    }
    proto_msg_buff[proto_msg_buff_write] = msg;
    proto_msg_buff_write = increment(proto_msg_buff_write);

    unlock_mutex(&proto_msg_buff_mutex);

    return tmp;
}
