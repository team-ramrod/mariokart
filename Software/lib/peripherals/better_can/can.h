#ifndef BCAN_H
#define BCAN_H

//------------------------------------------------------------------------------
//      Definitions
//------------------------------------------------------------------------------
#define AT91C_CAN_TIMEOUT         100000

#define AT91C_TEST_NOK                 0
#define AT91C_TEST_OK                  1

#define CAN_STATUS_SUCCESS             0
#define CAN_STATUS_LOCKED              1
#define CAN_STATUS_ABORTED             2
#define CAN_STATUS_RESET               3

#if defined (AT91C_BASE_CAN)
    #define AT91C_BASE_CAN0      AT91C_BASE_CAN
#endif
#if defined (AT91C_ID_CAN)
    #define AT91C_ID_CAN0        AT91C_ID_CAN
#endif
#if defined (AT91C_BASE_CAN_MB0)
    #define AT91C_BASE_CAN0_MB0  AT91C_BASE_CAN_MB0
    #define AT91C_BASE_CAN0_MB1  AT91C_BASE_CAN_MB1
    #define AT91C_BASE_CAN0_MB2  AT91C_BASE_CAN_MB2
    #define AT91C_BASE_CAN0_MB3  AT91C_BASE_CAN_MB3
    #define AT91C_BASE_CAN0_MB4  AT91C_BASE_CAN_MB4
    #define AT91C_BASE_CAN0_MB5  AT91C_BASE_CAN_MB5
    #define AT91C_BASE_CAN0_MB6  AT91C_BASE_CAN_MB6
    #define AT91C_BASE_CAN0_MB7  AT91C_BASE_CAN_MB7
    #define NUM_MAILBOX_MAX 8
#endif
#if defined (AT91C_BASE_CAN_MB8)
    #define AT91C_BASE_CAN0_MB8   AT91C_BASE_CAN_MB8
    #define AT91C_BASE_CAN0_MB9   AT91C_BASE_CAN_MB9
    #define AT91C_BASE_CAN0_MB10  AT91C_BASE_CAN_MB10
    #define AT91C_BASE_CAN0_MB11  AT91C_BASE_CAN_MB11
    #define AT91C_BASE_CAN0_MB12  AT91C_BASE_CAN_MB12
    #define AT91C_BASE_CAN0_MB13  AT91C_BASE_CAN_MB13
    #define AT91C_BASE_CAN0_MB14  AT91C_BASE_CAN_MB14
    #define AT91C_BASE_CAN0_MB15  AT91C_BASE_CAN_MB15
    #define NUM_MAILBOX_MAX 16
#endif


//------------------------------------------------------------------------------
//         Types
//------------------------------------------------------------------------------
typedef struct
{
    volatile unsigned char state;
    volatile unsigned char can_number;
    volatile unsigned char mailbox_number;
    volatile unsigned char test_can;
    volatile unsigned int  mode_reg;
    volatile unsigned int  acceptance_mask_reg;
    volatile unsigned int  identifier;
    volatile unsigned int  data_low_reg;
    volatile unsigned int  data_high_reg;
    volatile unsigned int  control_reg;
    volatile unsigned int  mailbox_in_use;
    volatile int           size;
} CanTransfer;

typedef struct {
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
unsigned int BCAN_Init(unsigned int baudrate, unsigned int initCan1, CAN_Callback callback);

/**
 * Disable CAN and enter low power mode.
 */
void BCAN_disable();


void BCAN_ResetAllMailbox( void );

void BCAN_InitMailboxRegisters(
    unsigned int can_number, unsigned int mailbox_number,
    unsigned int acceptance_mask, unsigned int identifier,
    unsigned int mode_reg, unsigned int control_reg
);

unsigned int BCAN_IsInIdle(unsigned int can_number);

unsigned int BCAN_Write(
    unsigned int can_number, unsigned int mailbox,
    unsigned int data_high, unsigned int data_low, unsigned int size
);

/**
 * Reads a value from the mailbox specified.
 *
 * @param can_number    The CAN peripheral to read from.
 * @param mailbox       Which mailbox to read from.
 *
 * @return  A packet containing either {CAN_STATUS_LOCKED,0,0}
 *          or {CAN_STATUS_SUCCESS,data,size}.
 */
CAN_Packet BCAN_Read(unsigned int can_number, unsigned int mailbox);
CAN_Packet BCAN_ReadAny(unsigned int can_number);

CAN_Packet BCAN_ReadAndClear(unsigned int can_number, unsigned int mailbox);
CAN_Packet BCAN_ReadAndClearAny(unsigned int can_number);
#endif /* BCAN_H */
