#include <board.h>
#include <better_can/can.h>
#include <stdio.h>
#include <stdlib.h>

struct pair { unsigned int low, high; };

#undef ASDF
#ifdef ASDF

mailbox      = CAN_Mailboxes[can_number][numMailbox];
can_ms       = mailbox->CAN_MB_MSR;
message_mode = (mailbox->CAN_MB_MMR >> 24) & 0x07;
TRACE_DEBUG("CAN_MB_MID 0x%X\n\r", (mailbox->CAN_MB_MID & AT91C_CAN_MIDvA) >> 18);

#endif



void init() {
    unsigned int id = AT91C_CAN_MIDvA & (0xAB << 18);
    unsigned int accMask = AT91C_CAN_MIDvA;

    // Init peripheral
    BCAN_Init(1000, 0, NULL);

    // Init mailbox 0 in reception.
    BCAN_InitMailboxRegisters(0, 0, accMask, id, AT91C_CAN_MOT_RX, 0);

    // Init mailbox 1 in transmission.
    BCAN_InitMailboxRegisters(0, 1, 0, id, AT91C_CAN_MOT_TX, 0);
}

void send_message(unsigned int mailboxNumber, unsigned int dataLow, unsigned int dataHigh) {
    // Wait till the mailbox is available.
    while (BCAN_Write(0, mailboxNumber, dataHigh, dataLow, 8) != CAN_STATUS_SUCCESS) ;
}

struct pair read_message(unsigned int mailboxNumber) {
    CAN_Packet result = { 0 };

    while (result.size < 0) {
        result = BCAN_ReadAndClear(0, mailboxNumber);
    }

    struct pair data = { result.data_low, result.data_high };
    return data;
}

int main() {
    init();
    send_message(1, 0x12345678, 0x9ABCDEF0);
    struct pair data = read_message(0);
    printf("Received [0x%08X%08X].\n\r", data.high, data.low);
    return EXIT_SUCCESS;
}
