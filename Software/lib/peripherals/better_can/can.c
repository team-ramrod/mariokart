#include <board.h>
#include <pio/pio.h>
#include <utility/trace.h>
#include <irq/irq.h>
#include "can.h"

#define AT91C_CAN_TIMEOUT         100000

#define AT91C_TEST_NOK                 0
#define AT91C_TEST_OK                  1

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

// CAN state
typedef enum {
    CAN_DISABLED  = 0x00,
    CAN_HALTED    = 0x01,
    CAN_IDLE      = 0x02,
    CAN_SENDING   = 0x03,
    CAN_RECIEVING = 0x04
} CAN_state_t;

// MOT: Mailbox Object Type
typedef enum {
    CAN_MOT_DISABLE   = 0x00,
    CAN_MOT_RECEPT    = 0x01,
    CAN_MOT_RECEPT_OW = 0x02,
    CAN_MOT_TRANSMIT  = 0x03,
    CAN_MOT_CONSUMER  = 0x04,
    CAN_MOT_PRODUCER  = 0x05
} CAN_mot_t;

typedef struct {
    CAN_state_t state;
    CAN_mot_t mot;
    unsigned long long data;
    unsigned int size;
    volatile unsigned int test_status;
    unsigned int mailbox_number;
    unsigned int active_mailboxes;
    CAN_Callback callback;
} CAN_t;

static CAN_t can0;
#ifdef AT91C_BASE_CAN1
static CAN_t can1;
#endif

#if defined (PINS_CAN_TRANSCEIVER_TXD)
static const Pin pins_can_transceiver_txd[] = {PINS_CAN_TRANSCEIVER_TXD};
#endif
#if defined (PINS_CAN_TRANSCEIVER_RXD)
static const Pin pins_can_transceiver_rxd[] = {PINS_CAN_TRANSCEIVER_RXD};
#endif
#if defined (PIN_CAN_TRANSCEIVER_RS)
static const Pin pin_can_transceiver_rs   = PIN_CAN_TRANSCEIVER_RS;
#endif
#if defined (PIN_CAN_TRANSCEIVER_RXEN)
static const Pin pin_can_transceiver_rxen = PIN_CAN_TRANSCEIVER_RXEN;
#endif

static AT91PS_CAN_MB CAN_Mailboxes[2][NUM_MAILBOX_MAX] = {
    {
        AT91C_BASE_CAN0_MB0,  AT91C_BASE_CAN0_MB1,
        AT91C_BASE_CAN0_MB2,  AT91C_BASE_CAN0_MB3,
        AT91C_BASE_CAN0_MB4,  AT91C_BASE_CAN0_MB5,
        AT91C_BASE_CAN0_MB6,  AT91C_BASE_CAN0_MB7,
#ifdef AT91C_BASE_CAN0_MB8
        AT91C_BASE_CAN0_MB8,  AT91C_BASE_CAN0_MB9,
        AT91C_BASE_CAN0_MB10, AT91C_BASE_CAN0_MB11,
        AT91C_BASE_CAN0_MB12, AT91C_BASE_CAN0_MB13,
        AT91C_BASE_CAN0_MB14, AT91C_BASE_CAN0_MB15,
#endif /* AT91C_BASE_CAN0 */
    },
#ifdef AT91C_BASE_CAN1
    {
        AT91C_BASE_CAN1_MB0,  AT91C_BASE_CAN1_MB1,
        AT91C_BASE_CAN1_MB2,  AT91C_BASE_CAN1_MB3,
        AT91C_BASE_CAN1_MB4,  AT91C_BASE_CAN1_MB5,
        AT91C_BASE_CAN1_MB6,  AT91C_BASE_CAN1_MB7,
#ifdef AT91C_BASE_CAN1_MB8
        AT91C_BASE_CAN1_MB8,  AT91C_BASE_CAN1_MB9,
        AT91C_BASE_CAN1_MB10, AT91C_BASE_CAN1_MB11,
        AT91C_BASE_CAN1_MB12, AT91C_BASE_CAN1_MB13,
        AT91C_BASE_CAN1_MB14, AT91C_BASE_CAN1_MB15,
#endif /* AT91C_BASE_CAN1_MB8 */
    },
#endif /* AT91C_BASE_CAN1 */
};

static CAN_Packet BCAN_Received_Packets[2][NUM_MAILBOX_MAX];

static void BCAN_ErrorHandling( unsigned int status, unsigned char can_number)
{
    if( (status&AT91C_CAN_ERRA) == AT91C_CAN_ERRA) {
        TRACE_ERROR("(CAN) CAN is in Error Active mode\n\r");
    }
    else if( (status&AT91C_CAN_ERRP) == AT91C_CAN_ERRP) {
        TRACE_ERROR("(CAN) CAN is in Error Passive mode\n\r");
    }
    else if( (status&AT91C_CAN_BOFF) == AT91C_CAN_BOFF) {
        TRACE_ERROR("(CAN) CAN is in Buff Off mode\n\r");
        // CAN reset
        TRACE_ERROR("(CAN) CAN%d reset\n\r", can_number);
        // CAN Controller Disable
        if (can_number == 0) {
            AT91C_BASE_CAN0->CAN_MR &= ~AT91C_CAN_CANEN;
            // CAN Controller Enable
            AT91C_BASE_CAN0->CAN_MR |= AT91C_CAN_CANEN;
        }
#ifdef AT91C_BASE_CAN1
        else if (can_number == 1) {
            AT91C_BASE_CAN1->CAN_MR &= ~AT91C_CAN_CANEN;
            // CAN Controller Enable
            AT91C_BASE_CAN1->CAN_MR |= AT91C_CAN_CANEN;
        }
#endif
    }

    // Error for Frame dataframe
    // CRC error
    if( (status&AT91C_CAN_CERR) ==  AT91C_CAN_CERR) {
        TRACE_ERROR("(CAN) CRC Error\n\r");
    }
    // Bit-stuffing error
    else if( (status&AT91C_CAN_SERR) ==  AT91C_CAN_SERR) {
        TRACE_ERROR("(CAN) Stuffing Error\n\r");
    }
    // Bit error
    else if( (status&AT91C_CAN_BERR) ==  AT91C_CAN_BERR) {
        TRACE_ERROR("(CAN) Bit Error\n\r");
    }
    // Form error
    else if( (status&AT91C_CAN_FERR) ==  AT91C_CAN_FERR) {
        TRACE_ERROR("(CAN) Form Error\n\r");
    }
    // Acknowledgment error
    else if( (status&AT91C_CAN_AERR) ==  AT91C_CAN_AERR) {
        TRACE_ERROR("(CAN) Acknowledgment Error\n\r");
    }
}

static void BCAN_Handler(unsigned int can_number) {
    CAN_t *can;
    AT91PS_CAN base_can;
    unsigned int status;

    switch (can_number) {
    case 0:
        base_can = AT91C_BASE_CAN0;
        can = &can0;
        break;
#ifdef AT91C_BASE_CAN1
    case 1:
        base_can = AT91C_BASE_CAN1;
        can = &can1;
        break;
#endif
    default:
        TRACE_ERROR("Unkown CAN %X\n\r", can_number);
        break;
    }

    status = (base_can->CAN_SR) & (base_can->CAN_IMR);

    TRACE_DEBUG("CAN%d status=0x%X\n\r", can_number, status);
    if (status & AT91C_CAN_WAKEUP) {
        can->test_status = AT91C_TEST_OK;
        can->state = CAN_IDLE;
        base_can->CAN_IDR = status;
    }
    // Mailbox event ?
    else if (status & 0x0000FFFF) {
        TRACE_DEBUG("Mailbox event\n\r");

        // Handle Mailbox interrupts
        for (unsigned int numMailbox = 0; numMailbox < NUM_MAILBOX_MAX; numMailbox++) {
            AT91PS_CAN_MB mailbox = CAN_Mailboxes[can_number][numMailbox];
            unsigned int can_msr = mailbox->CAN_MB_MSR;

            if ((AT91C_CAN_MRDY & can_msr) == AT91C_CAN_MRDY) {
                // Mailbox object type
                CAN_mot_t message_mode = (mailbox->CAN_MB_MMR >> 24) & 0x07;
                TRACE_DEBUG("message_mode 0x%X\n\r", message_mode);
                TRACE_DEBUG("numMailbox 0x%X\n\r", numMailbox);

                switch (message_mode) {
                case CAN_MOT_RECEPT:
                case CAN_MOT_RECEPT_OW:
                case CAN_MOT_PRODUCER:
                    TRACE_DEBUG("Mailbox is in RECEPTION\n\r");
                    TRACE_DEBUG("Length 0x%X\n\r", (can_msr >> 16) & 0xF);
                    TRACE_DEBUG("CAN_MB_MID 0x%X\n\r", (mailbox->CAN_MB_MID & AT91C_CAN_MIDvA) >> 18);
                    TRACE_DEBUG("CAN_MB_MAM 0x%X\n\r", (mailbox->CAN_MB_MAM & AT91C_CAN_MIDvA) >> 18);
                    TRACE_DEBUG("CAN_MB_MFID 0x%X\n\r", (mailbox->CAN_MB_MFID & AT91C_CAN_MIDvA) >> 18);

                    TRACE_DEBUG("can_number %d\n\r", can_number);
                    BCAN_Received_Packets[can_number][numMailbox].valid = 1;
                    BCAN_Received_Packets[can_number][numMailbox].mailbox = numMailbox;
                    BCAN_Received_Packets[can_number][numMailbox].data_low = mailbox->CAN_MB_MDL;
                    BCAN_Received_Packets[can_number][numMailbox].data_high = mailbox->CAN_MB_MDH;
                    BCAN_Received_Packets[can_number][numMailbox].size = (can_msr >> 16) & 0x0F;
                    can->state = CAN_IDLE;
                    // Message Data has been received
                    mailbox->CAN_MB_MCR = AT91C_CAN_MTCR;
                    if (can->callback && can->callback(BCAN_Received_Packets[can_number][numMailbox])) {
                        BCAN_Received_Packets[can_number][numMailbox].valid = 0;
                        BCAN_Received_Packets[can_number][numMailbox].mailbox = 0;
                        BCAN_Received_Packets[can_number][numMailbox].data_low = 0;
                        BCAN_Received_Packets[can_number][numMailbox].data_high = 0;
                        BCAN_Received_Packets[can_number][numMailbox].size = 0;
                    }

                    break;
                case CAN_MOT_TRANSMIT:
                case CAN_MOT_CONSUMER:
                    TRACE_DEBUG("Mailbox is in TRANSMIT\n\r");
                    TRACE_DEBUG("Length 0x%X\n\r", (can_msr>>16)&0xF);
                    TRACE_DEBUG("can_number %d\n\r", can_number);
                    can->state = CAN_IDLE;
                    base_can->CAN_IDR = (1 << numMailbox);
                    break;
                default:
                    TRACE_ERROR("Error in MOT\n\r");
                    break;
                }
            }
        }
    }

    if (status & 0xFFCF0000) {
        BCAN_ErrorHandling(status, can_number);
        base_can->CAN_IDR = status & 0xFFCF0000;
    }
}

static void BCAN0_Handler(void)
{
    BCAN_Handler( 0 );
}

#if defined AT91C_BASE_CAN1
static void BCAN1_Handler(void)
{
    BCAN_Handler( 1 );
}
#endif


void BCAN_InitMailboxRegisters(
        unsigned int can_number, unsigned int mailbox_number,
        unsigned int acceptance_mask, unsigned int identifier,
        unsigned int mode_reg, unsigned int control_reg
) {
    AT91PS_CAN_MB CAN_Mailbox = CAN_Mailboxes[can_number][mailbox_number];

    AT91PS_CAN base_can;

    switch (can_number) {
        case 0:
            base_can = AT91C_BASE_CAN0;
            break;
#ifdef AT91_BASE_CAN1
        case 1:
            base_can = AT91C_BASE_CAN1;
            break;
#endif
        default:
            TRACE_ERROR("Unknown CAN: %X\n\r", can_number);
            break;
    }

    base_can->CAN_IDR = (1 << mailbox_number);

    // MailBox Control Register
    CAN_Mailbox->CAN_MB_MCR = 0x0;
    // MailBox Mode Register
    CAN_Mailbox->CAN_MB_MMR = 0x0;
    // CAN Message Acceptance Mask Register
    CAN_Mailbox->CAN_MB_MAM = acceptance_mask;
    // MailBox ID Register
    // Disable the mailbox before writing to CAN_MIDx registers
    if( (identifier & AT91C_CAN_MIDE) == AT91C_CAN_MIDE ) {
        // Extended
        CAN_Mailbox->CAN_MB_MAM |= AT91C_CAN_MIDE;
    }
    else {
        CAN_Mailbox->CAN_MB_MAM &= ~AT91C_CAN_MIDE;
    }
    CAN_Mailbox->CAN_MB_MID = identifier;

    // MailBox Mode Register
    CAN_Mailbox->CAN_MB_MMR = mode_reg;
    // MailBox Control Register
    CAN_Mailbox->CAN_MB_MCR = control_reg;

    if ( ((mode_reg & AT91C_CAN_MOT) == AT91C_CAN_MOT_RXOVERWRITE)
      || ((mode_reg & AT91C_CAN_MOT) == AT91C_CAN_MOT_RX)) {
        base_can->CAN_IER = (1 << mailbox_number);
    }
}


void BCAN_ResetAllMailbox( void )
{
    for (unsigned int i = 0; i < NUM_MAILBOX_MAX; i++) {
        BCAN_InitMailboxRegisters(0, i, 0, 0, AT91C_CAN_MOT_DIS, 0);
    }
#if defined (AT91C_BASE_CAN1_MB0)
    for (unsigned int i = 0; i < NUM_MAILBOX_MAX; i++) {
        BCAN_InitMailboxRegisters(0, i, 0, 0, AT91C_CAN_MOT_DIS, 0);
    }
#endif
}


static unsigned char BCAN_Synchronisation( unsigned int syncCan1 ) {
    unsigned int tick=0;

    TRACE_INFO("CAN_Synchronisation\n\r");

    can0.test_status = AT91C_TEST_NOK;
    // Enable CAN and Wait for WakeUp Interrupt
    AT91C_BASE_CAN0->CAN_IER = AT91C_CAN_WAKEUP;
    // CAN Controller Enable
    AT91C_BASE_CAN0->CAN_MR = AT91C_CAN_CANEN;
    // Enable Autobaud/Listen mode
    // dangerous, CAN not answer in this mode

    while ((can0.test_status != AT91C_TEST_OK) && (tick < AT91C_CAN_TIMEOUT)) {
        tick++;
    }
    if (tick == AT91C_CAN_TIMEOUT) {
        TRACE_ERROR("CAN0 Initialisations FAILED\n\r");
        return 0;
    } else {
        TRACE_INFO("CAN0 Initialisations Completed\n\r");
    }

#if defined AT91C_BASE_CAN1
    if (syncCan1) {
        can1.test_status = AT91C_TEST_NOK;
        // Enable CAN and Wait for WakeUp Interrupt
        AT91C_BASE_CAN1->CAN_IER = AT91C_CAN_WAKEUP;
        // CAN Controller Enable
        AT91C_BASE_CAN1->CAN_MR = AT91C_CAN_CANEN;

        tick = 0;
        // Wait for WAKEUP flag raising <=> 11-recessive-bit were scanned by the transceiver
        while ((can1.test_status != AT91C_TEST_OK) && (tick < AT91C_CAN_TIMEOUT)) {
            tick++;
        }

        if (tick == AT91C_CAN_TIMEOUT) {
            TRACE_ERROR("CAN1 Initialisations FAILED\n\r");
            return 0;
        } else {
            TRACE_INFO("CAN1 Initialisations Completed\n\r");
        }
    }
#endif
    return 1;
}

unsigned int BCAN_Write(
        unsigned int can_number, unsigned int mailbox_number,
        unsigned int data_high, unsigned int data_low, unsigned int size
) {
    CAN_t *can;
    AT91PS_CAN base_can;
    AT91PS_CAN_MB mailbox;

    switch (can_number) {
        case 0:
            can = &can0;
            base_can = AT91C_BASE_CAN0;
            break;
#ifdef AT91_BASE_CAN1
        case 1:
            can = &can1;
            base_can = AT91C_BASE_CAN1;
            break;
#endif
        default:
            TRACE_ERROR("Unknown CAN: %X\n\r", can_number);
            break;
    }

    mailbox = CAN_Mailboxes[can_number][mailbox_number];

    if (! (mailbox->CAN_MB_MSR & AT91C_CAN_MRDY)) {
        return CAN_STATUS_LOCKED;
    }

    TRACE_DEBUG("CAN_Write\n\r");
    can->state = CAN_SENDING;
    mailbox->CAN_MB_MDL = data_low;
    mailbox->CAN_MB_MDH = data_high;
    mailbox->CAN_MB_MCR = ((size << 0x10) & AT91C_CAN_MDLC) | AT91C_CAN_MTCR;
    base_can->CAN_IER = (1 << mailbox_number);

    return CAN_STATUS_SUCCESS;
}


CAN_Packet BCAN_Read(unsigned int can_number, unsigned int mailbox) {
    return BCAN_Received_Packets[can_number][mailbox];
}

CAN_Packet BCAN_ReadAny(unsigned int can_number) {
    CAN_Packet packet = { 0 };
    for (unsigned int i = 0; i < NUM_MAILBOX_MAX; i++) {
        if (BCAN_Received_Packets[can_number][i].valid) {
            packet = BCAN_Received_Packets[can_number][i];
        }
    }
    return packet;
}

CAN_Packet BCAN_ReadAndClear(unsigned int can_number, unsigned int mailbox) {
    CAN_Packet packet = BCAN_Received_Packets[can_number][mailbox];
    BCAN_Received_Packets[can_number][mailbox].valid = 0;
    BCAN_Received_Packets[can_number][mailbox].mailbox = 0;
    BCAN_Received_Packets[can_number][mailbox].data_low = 0;
    BCAN_Received_Packets[can_number][mailbox].data_high = 0;
    BCAN_Received_Packets[can_number][mailbox].size = 0;
    return packet;
}

CAN_Packet BCAN_ReadAndClearAny(unsigned int can_number) {
    CAN_Packet packet = { 0 };
    for (unsigned int i = 0; i < NUM_MAILBOX_MAX; i++) {
        if ((!packet.valid) && BCAN_Received_Packets[can_number][i].valid) {
            packet = BCAN_Received_Packets[can_number][i];
            BCAN_Received_Packets[can_number][i].valid = 0;
            BCAN_Received_Packets[can_number][i].mailbox = 0;
            BCAN_Received_Packets[can_number][i].data_low = 0;
            BCAN_Received_Packets[can_number][i].data_high = 0;
            BCAN_Received_Packets[can_number][i].size = 0;
        }
    }
    return packet;
}

void BCAN_AbortTransfer(unsigned int can_number, unsigned int mailbox) {
    CAN_Mailboxes[can_number][mailbox]->CAN_MB_MCR = AT91C_CAN_MACR;
}

void BCAN_AbortAllTransfers(unsigned int can_number) {
    for (unsigned int i = 0; i < NUM_MAILBOX_MAX; i++) {
        BCAN_AbortTransfer(can_number, i);
    }
}

unsigned int BCAN_ReadyToTransmit(unsigned int can_number, unsigned int mailbox) {
    return (CAN_Mailboxes[can_number][mailbox]->CAN_MB_MSR & AT91C_CAN_MRDY);
}

void BCAN_disable() {
    // Disable the interrupt on the interrupt controller
    IRQ_DisableIT(AT91C_ID_CAN0);
    // disable all IT
    AT91C_BASE_CAN0->CAN_IDR = 0x1FFFFFFF;
#if defined AT91C_BASE_CAN1
    IRQ_DisableIT(AT91C_ID_CAN1);
    // disable all IT
    AT91C_BASE_CAN1->CAN_IDR = 0x1FFFFFFF;
#endif

    // Enable Low Power mode
    AT91C_BASE_CAN0->CAN_MR |= AT91C_CAN_LPM;

#if defined (PIN_CAN_TRANSCEIVER_RS)
    // Disable CANs Transceivers
    // Enter standby mode
    PIO_Set(&pin_can_transceiver_rs);
#endif
#if defined (PIN_CAN_TRANSCEIVER_RXEN)
    // Enable ultra Low Power mode
    PIO_Clear(&pin_can_transceiver_rxen);
#endif

    // Disable clock for CAN PIO
#if defined(AT91C_ID_PIOA)
    AT91C_BASE_PMC->PMC_PCDR = (1 << AT91C_ID_PIOA);
#elif defined(AT91C_ID_PIOABCD)
    AT91C_BASE_PMC->PMC_PCDR = (1 << AT91C_ID_PIOABCD);
#elif defined(AT91C_ID_PIOABCDE)
    AT91C_BASE_PMC->PMC_PCDR = (1 << AT91C_ID_PIOABCDE);
#endif

    // Disable the CAN0 controller peripheral clock
    AT91C_BASE_PMC->PMC_PCDR = (1 << AT91C_ID_CAN0);
}

//------------------------------------------------------------------------------
/// baudrate calcul
/// \param base_CAN CAN base address
/// \param baudrate Baudrate value (kB/s)
///                 allowed values: 1000, 800, 500, 250, 125, 50, 25, 10
/// \return return 1 in success, otherwise return 0
//------------------------------------------------------------------------------
static unsigned char BCAN_BaudRateCalculate( AT91PS_CAN   base_CAN,
                                     unsigned int baudrate )
{
    unsigned int BRP;
    unsigned int PROPAG;
    unsigned int PHASE1;
    unsigned int PHASE2;
    unsigned int SJW;
    unsigned int t1t2;
    unsigned char TimeQuanta;

    base_CAN->CAN_BR = 0;

    if( baudrate == 1000) {
        TimeQuanta = 8;
    }
    else {
        TimeQuanta = 16;
    }

    BRP = (BOARD_MCK / (baudrate*1000*TimeQuanta))-1;
    //TRACE_DEBUG("BRP = 0x%X\n\r", BRP);
    // timing Delay:
    // Delay Bus Driver: 50 ns
    // Delay Receiver:   30 ns
    // Delay Bus Line (20m):  110 ns
    if( (TimeQuanta*baudrate*2*(50+30+110)/1000000) >= 1) {
        PROPAG = (TimeQuanta*baudrate*2*(50+30+110)/1000000)-1;
    }
    else {
        PROPAG = 0;
    }
    //TRACE_DEBUG("PROPAG = 0x%X\n\r", PROPAG);

    t1t2 = TimeQuanta-1-(PROPAG+1);
    //TRACE_DEBUG("t1t2 = 0x%X\n\r", t1t2);

    if( (t1t2 & 0x01) == 0x01 ) {
        // ODD
        //TRACE_DEBUG("ODD\n\r");
        PHASE1 = ((t1t2-1)/2)-1;
        PHASE2 = PHASE1+1;
    }
    else {
        // EVEN
        //TRACE_DEBUG("EVEN\n\r");
        PHASE1 = (t1t2/2)-1;
        PHASE2 = PHASE1;
    }
    //TRACE_DEBUG("PHASE1 = 0x%X\n\r", PHASE1);
    //TRACE_DEBUG("PHASE2 = 0x%X\n\r", PHASE2);

    if( 1 > (4/(PHASE1+1)) ) {
        //TRACE_DEBUG("4*Tcsc\n\r");
        SJW = 3;
    }
    else {
        //TRACE_DEBUG("Tphs1\n\r");
        SJW = PHASE1;
    }
    //TRACE_DEBUG("SJW = 0x%X\n\r", SJW);
    // Verif
    if( BRP == 0 ) {
        TRACE_DEBUG("BRP = 0 is not authorized\n\r");
        return 0;
    }

    if( (PROPAG + PHASE1 + PHASE2) != (TimeQuanta-4) ) {
        TRACE_DEBUG("Pb (PROPAG + PHASE1 + PHASE2) = %d\n\r", PROPAG + PHASE1 + PHASE2);
        TRACE_DEBUG("with TimeQuanta-4 = %d\n\r", TimeQuanta-4);
        return 0;
    }
    base_CAN->CAN_BR = (AT91C_CAN_PHASE2 & (PHASE2 <<  0))
                     + (AT91C_CAN_PHASE1 & (PHASE1 <<  4))
                     + (AT91C_CAN_PROPAG & (PROPAG <<  8))
                     + (AT91C_CAN_SYNC   & (SJW << 12))
                     + (AT91C_CAN_BRP    & (BRP << 16))
                     + (AT91C_CAN_SMP    & (0 << 24));
    return 1;
}

unsigned int BCAN_Init(unsigned int baudrate, unsigned int initCan1, CAN_Callback callback) {
    can0.callback = callback;

    // CAN Transmit Serial Data
#if defined (PINS_CAN_TRANSCEIVER_TXD)
    PIO_Configure(pins_can_transceiver_txd, PIO_LISTSIZE(pins_can_transceiver_txd));
#endif
#if defined (PINS_CAN_TRANSCEIVER_RXD)
    // CAN Receive Serial Data
    PIO_Configure(pins_can_transceiver_rxd, PIO_LISTSIZE(pins_can_transceiver_rxd));
#endif
#if defined (PIN_CAN_TRANSCEIVER_RS)
    // CAN RS
    PIO_Configure(&pin_can_transceiver_rs, PIO_LISTSIZE(pin_can_transceiver_rs));
#endif
#if defined (PIN_CAN_TRANSCEIVER_RXEN)
    // CAN RXEN
    PIO_Configure(&pin_can_transceiver_rxen, PIO_LISTSIZE(pin_can_transceiver_rxen));
#endif

    // Enable clock for CAN PIO
#if defined(AT91C_ID_PIOA)
    AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_PIOA);
#elif defined(AT91C_ID_PIOABCD)
    AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_PIOABCD);
#elif defined(AT91C_ID_PIOABCDE)
    AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_PIOABCDE);
#endif

    // Enable the CAN0 controller peripheral clock
    AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_CAN0);

    // disable all IT
    AT91C_BASE_CAN0->CAN_IDR = 0x1FFFFFFF;

    // Enable CANs Transceivers
#if defined (PIN_CAN_TRANSCEIVER_RXEN)
    // Disable ultra Low Power mode
    PIO_Set(&pin_can_transceiver_rxen);
#endif
#if defined (PIN_CAN_TRANSCEIVER_RS)
    // Normal Mode (versus Standby mode)
    PIO_Clear(&pin_can_transceiver_rs);
#endif

    // Configure the AIC for CAN interrupts
    IRQ_ConfigureIT(AT91C_ID_CAN0, 0x7, BCAN0_Handler);

    // Enable the interrupt on the interrupt controller
    IRQ_EnableIT(AT91C_ID_CAN0);

    if (! BCAN_BaudRateCalculate(AT91C_BASE_CAN0, baudrate)) {
        // Baudrate problem
        TRACE_DEBUG("Baudrate CAN0 problem\n\r");
        return 0;
    }

#if defined AT91C_BASE_CAN1
    if (initCan1) {
        can1.callback = callback;
        // Enable CAN1 Clocks
        AT91C_BASE_PMC->PMC_PCER = (1 << AT91C_ID_CAN1);

        // disable all IT
        AT91C_BASE_CAN1->CAN_IDR = 0x1FFFFFFF;

        // Configure the AIC for CAN interrupts
        IRQ_ConfigureIT(AT91C_ID_CAN1, 0x7, BCAN1_Handler);

        // Enable the interrupt on the interrupt controller
        IRQ_EnableIT(AT91C_ID_CAN1);

        if (! BCAN_BaudRateCalculate(AT91C_BASE_CAN1, baudrate)) {
            // Baudrate problem
            TRACE_DEBUG("Baudrate CAN1 problem\n\r");
            return 0;
        }
    }
#endif
    // Reset all mailbox
    BCAN_ResetAllMailbox();

    // Enable the interrupt with all error cases
    AT91C_BASE_CAN0->CAN_IER =  AT91C_CAN_CERR  // (CAN) CRC Error
                             |  AT91C_CAN_SERR  // (CAN) Stuffing Error
                             |  AT91C_CAN_BERR  // (CAN) Bit Error
                             |  AT91C_CAN_FERR  // (CAN) Form Error
                             |  AT91C_CAN_AERR; // (CAN) Acknowledgment Error

#if defined AT91C_BASE_CAN1
    if (initCan1) {
        AT91C_BASE_CAN1->CAN_IER =  AT91C_CAN_CERR  // (CAN) CRC Error
                                 |  AT91C_CAN_SERR  // (CAN) Stuffing Error
                                 |  AT91C_CAN_BERR  // (CAN) Bit Error
                                 |  AT91C_CAN_FERR  // (CAN) Form Error
                                 |  AT91C_CAN_AERR; // (CAN) Acknowledgment Error
    }
#endif

    // Wait for CAN synchronisation
    return BCAN_Synchronisation(initCan1);
}

