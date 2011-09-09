/**
 * This was stolen from the getting started project in the atmel project library
 */
//-----------------------------------------------------------------------------
//         Headers
//-----------------------------------------------------------------------------

#include <board.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <aic/aic.h>
#include <dbgu/dbgu.h>
#include <rtt/rtt.h>
#include <utility/trace.h>
#include <utility/assert.h>
#include <better_can/can.h>

//-----------------------------------------------------------------------------
//         Local Define
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//         Local variables
//-----------------------------------------------------------------------------
const Pin s0 = PIN_PUSHBUTTON_0;
const Pin s1 = PIN_PUSHBUTTON_1;
const Pin s2 = PIN_PUSHBUTTON_2;
const Pin s3 = PIN_PUSHBUTTON_3;

//------------------------------------------------------------------------------
/// Configures the RTT to generate a one second tick
//------------------------------------------------------------------------------
void ConfigureRtt(void)
{
    unsigned int previousTime;

    // Configure RTT for a 1 second tick interrupt
    RTT_SetPrescaler(AT91C_BASE_RTTC, 32768);
    previousTime = RTT_GetTime(AT91C_BASE_RTTC);
    while (previousTime == RTT_GetTime(AT91C_BASE_RTTC));
}

//-----------------------------------------------------------------------------
/// Init CAN in recept
//-----------------------------------------------------------------------------
void InitCANInRecept( void )
{
    unsigned char i;

    for( i=0; i<8; i++ ) {
        BCAN_InitMailboxRegisters(0, i, AT91C_CAN_MIDvA & (1<<(18+i)),
                AT91C_CAN_MIDvA & (1<<(18+i)), AT91C_CAN_MOT_RX, 0x0);
    }
}

//-----------------------------------------------------------------------------
/// Test Transmit with acceptance mask
//-----------------------------------------------------------------------------
void Test_TransmitWithAccMask(
    unsigned char mailboxNumber, 
    unsigned int dataLow, 
    unsigned int dataHigh
    )
{
    printf("Transmit, with acceptance mask - Maibox Number: %02d - Data (Low/High): %08X %08X\n\r", 
         mailboxNumber, 
         dataLow,
         dataHigh);	
	
    BCAN_InitMailboxRegisters(0, mailboxNumber, AT91C_CAN_MIDvA & (1<<(18+5)),
            AT91C_CAN_MIDvA & (1<<(18+5)), AT91C_CAN_MOT_TX | AT91C_CAN_PRIOR, 0x0);
    while( CAN_STATUS_SUCCESS !=
            BCAN_Write(0, mailboxNumber, dataHigh, dataLow, 0x8)){
    }
    // wait answer
    while( ! BCAN_ReadyToTransmit(0,mailboxNumber) ) {}
    // return in recept
    BCAN_InitMailboxRegisters(0, mailboxNumber, 0,
            AT91C_CAN_MIDvA & (0x0B<<18), AT91C_CAN_MOT_RX, 0x0);
}
    
//-----------------------------------------------------------------------------
/// Transmit without acceptance mask
//-----------------------------------------------------------------------------
void Test_TransmitWithoutAccMask(
    unsigned char mailboxNumber,
    unsigned int dataLow,
    unsigned int dataHigh
    )
{
    printf("Transmit, no acceptance mask - Maibox Number: %02d - Data (Low/High): %08X %08X\n\r", 
         mailboxNumber, 
         dataLow,
         dataHigh);
         
    BCAN_InitMailboxRegisters(0, mailboxNumber, 0x0,
            AT91C_CAN_MIDvA & (0xB<<18), AT91C_CAN_MOT_TX | AT91C_CAN_PRIOR, 0x0);
    while( CAN_STATUS_SUCCESS !=
            BCAN_Write(0, mailboxNumber, dataHigh, dataLow, 0x8)){
    }
    // wait answer
    while( ! BCAN_ReadyToTransmit(0, mailboxNumber) ) {}

    // return in recept for all mailbox
    InitCANInRecept();
}                   
    
//-----------------------------------------------------------------------------
/// Dump registers
//-----------------------------------------------------------------------------
void DumpRegisters(void)
{    
    printf("Dump registers\n\r");
    printf("CAN_MR:     0x%X\n\r", AT91C_BASE_CAN->CAN_MR);
    printf("CAN_IMR:    0x%X\n\r", AT91C_BASE_CAN->CAN_IMR);
    printf("CAN_SR:     0x%X\n\r", AT91C_BASE_CAN->CAN_SR);
    printf("CAN_BR:     0x%X\n\r", AT91C_BASE_CAN->CAN_BR);
    printf("CAN_ECR:    0x%X\n\r", AT91C_BASE_CAN->CAN_ECR);
    printf("CAN_MB_MMR: 0x%X\n\r", AT91C_BASE_CAN_MB1->CAN_MB_MMR);
    printf("CAN_MB_MAM: 0x%X\n\r", AT91C_BASE_CAN_MB1->CAN_MB_MAM);
    printf("CAN_MB_MID: 0x%X\n\r", AT91C_BASE_CAN_MB1->CAN_MB_MID);
    printf("CAN_MB_MSR: 0x%X\n\r", AT91C_BASE_CAN_MB1->CAN_MB_MSR);
    printf("CAN_MB_MDL: 0x%X\n\r", AT91C_BASE_CAN_MB1->CAN_MB_MDL);
    printf("CAN_MB_MDH: 0x%X\n\r", AT91C_BASE_CAN_MB1->CAN_MB_MDH);
}

//-----------------------------------------------------------------------------
//         Global functions
//-----------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Displays the user menu on the DBGU.
//------------------------------------------------------------------------------
static void DisplayMenu(void)
{
    printf("\n\r");	
    printf("Menu :\n\r");
    printf("------\n\r");
    printf("1: transmit, with acceptance mask\n\r");    
    printf("2: transmit, no acceptance mask\n\r");    
    printf("3: dump registers\n\r");  
    printf("Press any key to stop transmission\n\r");              
    printf("\n\r");
}

//-----------------------------------------------------------------------------
/// main function
//-----------------------------------------------------------------------------
int main(void)
{    
    int CharReceive = -1;
    unsigned int time;
    CAN_Packet packet;

    TRACE_CONFIGURE(DBGU_STANDARD, 115200, BOARD_MCK);   
    printf("-- Basic CAN Project %s --\n\r", SOFTPACK_VERSION);
    printf("-- %s\n\r", BOARD_NAME);
    printf("-- Compiled: %s %s --\n\r", __DATE__, __TIME__);
        
    printf("IP version: 0x%X\n\r", *(unsigned int*)AT91C_CAN_VR);

    PIO_Configure(&s0, 1);
    PIO_Configure(&s1, 1);
    PIO_Configure(&s2, 1);
    PIO_Configure(&s3, 1);
    PIO_InitializeInterrupts(0); 

    if( BCAN_Init( 1000, 0, NULL ) == 1 ) {
        printf("INIT OK\n\r");

        InitCANInRecept();
        ConfigureRtt();
        DisplayMenu();
                 
        while(1) {
            
            packet = BCAN_ReadAndClearAny(0);
            
            while(CharReceive == -1) {
            //while(1) {
                if ( !PIO_Get(&s0) ) {
                    TRACE_INFO("Switch 0 is pressed\n\r");
                    CharReceive = '0';
                } else if ( !PIO_Get(&s1) ) {
                    TRACE_INFO("Switch 1 is pressed\n\r");
                    CharReceive = '1';
                } else if ( !PIO_Get(&s2) ) {
                    TRACE_INFO("Switch 2 is pressed\n\r");
                    CharReceive = '2';
                } else if ( !PIO_Get(&s3) ) {
                    TRACE_INFO("Switch 3 is pressed\n\r");
                    CharReceive = '3';
                } else {
                    //TRACE_INFO("No Switch is pressed\n\r");
                }
            }
            if (CharReceive) {

                switch(CharReceive) {

                    case '0': {
                                  while(!PIO_Get(&s1));

                                  // Transmit, with acceptance mask
                                  Test_TransmitWithAccMask(1, 0xAABBCCDD, 0x11223344);

                                  // Wait for the next second
                                  time = RTT_GetTime(AT91C_BASE_RTTC);
                                  while (time == RTT_GetTime(AT91C_BASE_RTTC));
                              }
                              break;
                    case '1': {                           
                                  while(!PIO_Get(&s2));

                                  // Transmit, no acceptance mask
                                  Test_TransmitWithoutAccMask(2, 0x12345678, 0xABCDEFAB);                            

                                  // Wait for the next second
                                  time = RTT_GetTime(AT91C_BASE_RTTC);
                                  while (time == RTT_GetTime(AT91C_BASE_RTTC));
                              }
                              break;
                    case '2': {
                                  while(!PIO_Get(&s3));

                                  DumpRegisters();
                              }
                              break;
                    default:
                              // nothing
                              break;
                }

                CharReceive = -1;
                DisplayMenu();    
            }
            if (packet.valid) {
                printf("Data (Low/High): %8X%8X\n\r", 
                    packet.data_low,packet.data_high);
                    CharReceive = -1;
            }
        }
    }
    else {
        printf("INIT PB\n\r");
    }

    return 0;
}
