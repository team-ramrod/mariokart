#include <board.h>
#include <can/can.h>
#include <stdio.h>
#include <stdlib.h>

struct pair { unsigned int low, high; };

#undef ASDF
#ifdef ASDF

CAN_Mailbox  = AT91C_BASE_CAN0_MB0;
can_msr      = *(unsigned int*)((unsigned int)CAN_Mailbox+(unsigned int)(0x10+(0x20*numMailbox)));
message_mode =  ((*(unsigned int*)((unsigned int)CAN_Mailbox+(unsigned int)(0x00+(0x20*numMailbox))))>>24)&0x7;
TRACE_DEBUG("CAN_MB_MID 0x%X\n\r", ((*(unsigned int*)((unsigned int)CAN_Mailbox+(unsigned int)(0x08+(0x20*numMailbox)))&AT91C_CAN_MIDvA)>>18));

#endif

CanTransfer canTransferRx, canTransferTx;

void init() {
    unsigned int id = AT91C_CAN_MIDvA & (0xAB << 18);
    unsigned int accMask = AT91C_CAN_MIDvA;

    // Init peripheral
    CAN_Init( 1000, &canTransferRx, &canTransferTx );

    // Init mailbox 0 in reception.
    canTransferRx.can_number          = 0;
    canTransferRx.mailbox_number      = 0;
    canTransferRx.mode_reg            = AT91C_CAN_MOT_RX;
    canTransferRx.acceptance_mask_reg = accMask;
    canTransferRx.identifier          = id;
    canTransferRx.data_low_reg        = 0;
    canTransferRx.data_high_reg       = 0;
    canTransferRx.control_reg         = 0;

    CAN_InitMailboxRegisters( &canTransferRx );
}

void send_message(unsigned int mailboxNumber, unsigned int dataLow, unsigned int dataHigh) {
    unsigned int id = AT91C_CAN_MIDvA & (0xAB << 18);

    canTransferTx.can_number          = 0;
    canTransferTx.mailbox_number      = mailboxNumber;
    canTransferTx.mode_reg            = AT91C_CAN_MOT_TX | AT91C_CAN_PRIOR;
    canTransferTx.acceptance_mask_reg = 0;
    canTransferTx.identifier          = id;
    canTransferTx.data_low_reg        = dataLow;
    canTransferTx.data_high_reg       = dataHigh;
    canTransferTx.control_reg         = AT91C_CAN_MDLC & (0x8 << 16);

    CAN_InitMailboxRegisters( &canTransferTx );

    while (CAN_Write( &canTransferTx ) != CAN_STATUS_SUCCESS) {
        // Wait till the CAN peripheral is available.
    }
}

struct pair read_message(unsigned int mailboxNumber) {
    while (CAN_Read( &canTransferRx ) != CAN_STATUS_SUCCESS) {
        // Keep trying to initiate read.
    }

    while (! CAN_IsInIdle( &canTransferRx )) {
        // Wait till the read finishes
        // (or someone tries to write over CAN and overrides your read,
        // no way to tell the difference)
    }

    struct pair data = { canTransferRx.data_low_reg, canTransferRx.data_high_reg };
    return data;
}

int main() {
    init();
    send_message(1, 0x12345678, 0x9ABCDEF0);
    struct pair data = read_message(0);
    printf("Received [0x%08X%08X].\n\r", data.high, data.low);
    return EXIT_SUCCESS;
}
