#include "proto_msg_buff.h"

#include <utility/interrupts.h>

#define BUFFER_SIZE 10
#define increment(pos) ((pos + 1) % BUFFER_SIZE)

message_t proto_msg_buff[BUFFER_SIZE] = { { 0x0 } };

volatile unsigned int proto_msg_buff_read  = 0,
                      proto_msg_buff_write = 0;

unsigned int proto_msg_buff_length() {
    unsigned int tmp = 0x0;

    disable_interrupts();

        tmp = ((proto_msg_buff_write - proto_msg_buff_read) + BUFFER_SIZE) % BUFFER_SIZE;

    enable_interrupts();

    return tmp;
}

message_t proto_msg_buff_pop() {
    message_t tmp = { 0x0 };

    disable_interrupts();

        if (proto_msg_buff_read != proto_msg_buff_write) {
            tmp = proto_msg_buff[proto_msg_buff_read];
            proto_msg_buff_read = increment(proto_msg_buff_read);
        }

    enable_interrupts();

    return tmp;
}

message_t proto_msg_buff_peek() {
    message_t tmp = { 0x0 };

    disable_interrupts();

        if (proto_msg_buff_read != proto_msg_buff_write) {
            tmp = proto_msg_buff[proto_msg_buff_read];
        }

    enable_interrupts();

    return tmp;
}

bool proto_msg_buff_push(message_t msg) {
    bool tmp = false;

    disable_interrupts();

        if (proto_msg_buff_read == increment(proto_msg_buff_write)) {
            proto_msg_buff_read = increment(proto_msg_buff_read);
            tmp = true;
        }
        proto_msg_buff[proto_msg_buff_write] = msg;
        proto_msg_buff_write = increment(proto_msg_buff_write);

    enable_interrupts();

    return tmp;
}
