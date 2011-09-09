#ifndef BCAN_H
#define BCAN_H

#define CAN_STATUS_SUCCESS             0
#define CAN_STATUS_LOCKED              1
#define CAN_STATUS_ABORTED             2
#define CAN_STATUS_RESET               3

typedef struct {
    unsigned int valid;
    unsigned int mailbox;
    unsigned int data_low;
    unsigned int data_high;
    unsigned int size;
} CAN_Packet;

/**
 * Return one if the packet has been dealt with and should be deleted.
 */
typedef unsigned int (*CAN_Callback)(CAN_Packet);

/**
 * Initialises the CAN peripheral(s)
 *
 * @param baudrate  Baudrate value (kB/s)
 *                  allowed values: 1000, 800, 500, 250, 125, 50, 25, 10
 * @param initCan1  Whether to initialise CAN1 if it exists.
 * @param callback  A callback that will be run whenever a message is received.
 *
 * @return 1 if CAN perpherial(s) have good baudrates and are synchronised,
 *         otherwise 0
 */
unsigned int BCAN_Init(
    unsigned int baudrate,
    unsigned int initCan1,
    CAN_Callback callback
);

/**
 * Disable CAN and enter low power mode.
 */
void BCAN_disable();

/**
 * Reset the configuration of all the mailboxes.
 */
void BCAN_ResetAllMailbox( void );

/**
 * Initialises all the registers for a mailbox.
 */
void BCAN_InitMailboxRegisters(
    unsigned int can_number, unsigned int mailbox_number,
    unsigned int acceptance_mask, unsigned int identifier,
    unsigned int mode_reg, unsigned int control_reg
);

/**
 * Returns a value > 0 if the mailbox is ready for a new transmission, 0
 * otherwise.
 */
unsigned int BCAN_ReadyToTransmit(unsigned int can_number, unsigned int mailbox);

/**
 * Queues the given data up to be written out of the specified can peripheral
 * and mailbox.  The destination should have been previously set up using
 * BCAN_InitMailboxRegisters.
 *
 * @param   can_number  The CAN peripheral to write to.
 * @param   mailbox     The mailbox of the CAN peripheral to write to.
 * @param   data_high   The high 4 bytes of data to write.
 * @param   data_low    The low 4 bytes of data to write.
 * @param   size        The number of bytes to write.
 *                      (Unknown what order the bytes are read from the data
 *                      params.)
 *
 * @return  Returns CAN_STATUS_SUCCESS if the message was successfully queued
 *          or CAN_STATUS_LOCKED if the mailbox was in use.
 */
unsigned int BCAN_Write(
    unsigned int can_number, unsigned int mailbox,
    unsigned int data_high, unsigned int data_low, unsigned int size
);

/**
 * Tells the specified mailbox to abort its transfer.
 */
void BCAN_AbortTransfer(unsigned int can_number, unsigned int mailbox);

/**
 * Tells all the mailboxes to abort their transfers.
 */
void BCAN_AbortAllTransfers(unsigned int can_number);

/**
 * Reads a value from the mailbox specified.
 *
 * @param can_number    The CAN peripheral to read from.
 * @param mailbox       Which mailbox to read from.
 *
 * @return  A packet with either valid set to 0 if there has been no data or
 *          valid set to 1 and the data filled in.
 */
CAN_Packet BCAN_Read(unsigned int can_number, unsigned int mailbox);

/**
 * Reads a value from the first mailbox that contains a received message.
 *
 * @param can_number    The CAN peripheral to read from.
 *
 * @return  A packet with either valid set to 0 if there has been no data or
 *          valid set to 1 and the data filled in.
 */
CAN_Packet BCAN_ReadAny(unsigned int can_number);

/**
 * Reads a value from the mailbox specified then clears that mailboxes
 * reception buffer.
 *
 * @param can_number    The CAN peripheral to read from.
 * @param mailbox       Which mailbox to read from.
 *
 * @return  A packet with either valid set to 0 if there has been no data or
 *          valid set to 1 and the data filled in.
 */
CAN_Packet BCAN_ReadAndClear(unsigned int can_number, unsigned int mailbox);

/**
 * Reads a value from the first mailbox that contains a received message then
 * clears that mailboxes reception buffer.
 *
 * @param can_number    The CAN peripheral to read from.
 *
 * @return  A packet with either valid set to 0 if there has been no data or
 *          valid set to 1 and the data filled in.
 */
CAN_Packet BCAN_ReadAndClearAny(unsigned int can_number);

#endif /* BCAN_H */
