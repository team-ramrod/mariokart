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
#include <can/can.h>

//-----------------------------------------------------------------------------
//         Local Define
//-----------------------------------------------------------------------------


//-----------------------------------------------------------------------------
//         Local variables
//-----------------------------------------------------------------------------
CanTransfer canTransfer1;

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

    CAN_ResetTransfer( &canTransfer1 );
    for( i=0; i<8; i++ ) {
        canTransfer1.can_number = 0;
        canTransfer1.mailbox_number = i;
        canTransfer1.mode_reg = AT91C_CAN_MOT_RX;
        canTransfer1.acceptance_mask_reg = AT91C_CAN_MIDvA & (1<<(18+i));
        canTransfer1.identifier = AT91C_CAN_MIDvA & (1<<(18+i));
        canTransfer1.data_low_reg = 0x00000000;
        canTransfer1.data_high_reg = 0x00000000;
        canTransfer1.control_reg = 0x00000000;
        CAN_InitMailboxRegisters( &canTransfer1 );
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
	
    canTransfer1.can_number = 0;
    canTransfer1.mailbox_number = mailboxNumber;
    canTransfer1.mode_reg = AT91C_CAN_MOT_TX | AT91C_CAN_PRIOR;
    canTransfer1.acceptance_mask_reg = AT91C_CAN_MIDvA & (1<<(18+5));// ID 11
    canTransfer1.identifier = AT91C_CAN_MIDvA & (1<<(18+5));     // ID 11
    canTransfer1.data_low_reg = dataLow;
    canTransfer1.data_high_reg = dataHigh;
    canTransfer1.control_reg = (AT91C_CAN_MDLC & (0x8<<16)); // Mailbox Data Length Code
    CAN_InitMailboxRegisters( &canTransfer1 );
    while( CAN_STATUS_SUCCESS != CAN_Write( &canTransfer1 ) ){}
    // wait answer
    while( CAN_IsInIdle(&canTransfer1) ) {}
    // return in recept
    canTransfer1.can_number = 0;
    canTransfer1.mailbox_number = 1;
    canTransfer1.mode_reg = AT91C_CAN_MOT_RX;
    canTransfer1.acceptance_mask_reg = 0;
    canTransfer1.identifier = AT91C_CAN_MIDvA & (0x0B<<18);  // ID 11
    canTransfer1.data_low_reg = 0x00000000;
    canTransfer1.data_high_reg = 0x00000000;
    canTransfer1.control_reg = 0x00000000;
    CAN_InitMailboxRegisters( &canTransfer1 );
    //InitCANInRecept();
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
         
    canTransfer1.can_number = 0;
    canTransfer1.mailbox_number = mailboxNumber;
    canTransfer1.mode_reg = AT91C_CAN_MOT_TX | AT91C_CAN_PRIOR;
    canTransfer1.acceptance_mask_reg = 0x00000000;
    canTransfer1.identifier = AT91C_CAN_MIDvA & (0x0B<<18);     // ID 11
    canTransfer1.data_low_reg = dataLow;
    canTransfer1.data_high_reg = dataHigh;
    canTransfer1.control_reg = (AT91C_CAN_MDLC & (0x8<<16)); // Mailbox Data Length Code
    CAN_InitMailboxRegisters( &canTransfer1 );
    while( CAN_STATUS_SUCCESS != CAN_Write( &canTransfer1 ) ){}
    // wait answer
    while( CAN_IsInIdle(&canTransfer1) ) {}
    // return in recept for all mailbox
    InitCANInRecept();
}                   
    
//-----------------------------------------------------------------------------
/// Dump registers
//-----------------------------------------------------------------------------
void DumpRegisters(void)
{    
    printf("Dump registers\n\r");
    printf("CAN_MR:     0x%X\n\r", AT91C_BASE_CAN0->CAN_MR);
    printf("CAN_IMR:    0x%X\n\r", AT91C_BASE_CAN0->CAN_IMR);
    printf("CAN_SR:     0x%X\n\r", AT91C_BASE_CAN0->CAN_SR);
    printf("CAN_BR:     0x%X\n\r", AT91C_BASE_CAN0->CAN_BR);
    printf("CAN_ECR:    0x%X\n\r", AT91C_BASE_CAN0->CAN_ECR);
    printf("CAN_MB_MMR: 0x%X\n\r", AT91C_BASE_CAN0_MB1->CAN_MB_MMR);
    printf("CAN_MB_MAM: 0x%X\n\r", AT91C_BASE_CAN0_MB1->CAN_MB_MAM);
    printf("CAN_MB_MID: 0x%X\n\r", AT91C_BASE_CAN0_MB1->CAN_MB_MID);
    printf("CAN_MB_MSR: 0x%X\n\r", AT91C_BASE_CAN0_MB1->CAN_MB_MSR);
    printf("CAN_MB_MDL: 0x%X\n\r", AT91C_BASE_CAN0_MB1->CAN_MB_MDL);
    printf("CAN_MB_MDH: 0x%X\n\r", AT91C_BASE_CAN0_MB1->CAN_MB_MDH);    
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

    if( CAN_Init( 1000, &canTransfer1, NULL ) == 1 ) {
        printf("INIT OK\n\r");

        InitCANInRecept();
        ConfigureRtt();
        DisplayMenu();
                 
        while(1) {
            
            while( CAN_STATUS_SUCCESS != CAN_Read( &canTransfer1 ) ){}
            // wait answer
            
            while( CAN_IsInIdle(&canTransfer1) ) {
                TRACE_INFO("CAN is in idle\n\r");

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
            }
            if( CharReceive == '3' ) {
                printf("Receive - Maibox Number: %02d - Data (Low/High): %08X %08X\n\r", 
                    canTransfer1.mailbox_number, 
                    canTransfer1.data_low_reg,
                    canTransfer1.data_high_reg);
                    CharReceive = -1;
            }
        }
    }
    else {
        printf("INIT PB\n\r");
    }

    return 0;
}
