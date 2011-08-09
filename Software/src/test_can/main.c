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
CanTransfer canTransfer2;
CanTransfer canTransfer1;


//------------------------------------------------------------------------------
/// Test CAN0 Mailbox 0 transmitting to CAN1 Mailbox 0
//------------------------------------------------------------------------------
void Test1(void )
{
    CAN_ResetAllMailbox();

    TRACE_INFO("With Interrupt ");
    TRACE_INFO("CAN0 Mailbox 0 transmitting to CAN1 Mailbox 0\n\r");
    // Init CAN1 Mailbox 0, receive, 
    CAN_ResetTransfer( &canTransfer2 );
    canTransfer2.can_number = 1;
    canTransfer2.mailbox_number = 0;
    canTransfer2.mode_reg = AT91C_CAN_MOT_RX;
    canTransfer2.acceptance_mask_reg = AT91C_CAN_MIDvA | AT91C_CAN_MIDvB;
    canTransfer2.identifier = AT91C_CAN_MIDvA & (0x07<<18);
    canTransfer2.data_low_reg = 0x00000000;
    canTransfer2.data_high_reg = 0x00000000;
    canTransfer2.control_reg = 0x00000000;
    CAN_InitMailboxRegisters( &canTransfer2 );

    // Init CAN0 Mailbox 0, transmit
    CAN_ResetTransfer( &canTransfer1 );
    canTransfer1.can_number = 0;
    canTransfer1.mailbox_number = 0;
    canTransfer1.mode_reg = AT91C_CAN_MOT_TX | AT91C_CAN_PRIOR;
    canTransfer1.acceptance_mask_reg = 0x00000000;
    canTransfer1.identifier = AT91C_CAN_MIDvA & (0x07<<18);
    canTransfer1.data_low_reg = 0x11223344;
    canTransfer1.data_high_reg = 0x01234567;
    canTransfer1.control_reg = (AT91C_CAN_MDLC & (0x8<<16));
    CAN_InitMailboxRegisters( &canTransfer1 );

    while( CAN_STATUS_SUCCESS !=  CAN_Read( &canTransfer2 ) ){}
    while( CAN_STATUS_SUCCESS !=  CAN_Write( &canTransfer1 ) ){}

    // wait answer
    while( CAN_IsInIdle(&canTransfer2) ) {}
    while( CAN_IsInIdle(&canTransfer1) ) {}

    TRACE_DEBUG("Read data low 0x%X\n\r", canTransfer2.data_low_reg);
    TRACE_DEBUG("Read data high 0x%X\n\r", canTransfer2.data_high_reg);
    if( (canTransfer2.data_low_reg == 0x11223344)
      &&(canTransfer2.data_high_reg == 0x01234567) 
      &&(canTransfer2.size == 8)) {
        TRACE_INFO("Test passed\n\r");
    }
    else {
        TRACE_INFO("Test ERROR\n\r");
    }
}


//------------------------------------------------------------------------------
/// Test CAN0 Mailboxes 1 & 2 transmitting to CAN1 Mailbox 15
//------------------------------------------------------------------------------
void Test2(void )
{
    CAN_ResetAllMailbox();

    TRACE_INFO("With Interrupt ");
    TRACE_INFO("CAN0 Mailboxes 1 & 2 transmitting to CAN1 Mailbox 15\n\r");

    // Init CAN1 Mailbox 15, reception
    CAN_ResetTransfer( &canTransfer2 );
    canTransfer2.can_number = 1;
    canTransfer2.mailbox_number = 15;
    canTransfer2.mode_reg = AT91C_CAN_MOT_RX;
    canTransfer2.acceptance_mask_reg = 0;
    canTransfer2.identifier = 0x0;
    canTransfer2.data_low_reg = 0x00000000;
    canTransfer2.data_high_reg = 0x00000000;
    canTransfer2.control_reg = 0x00000000;
    CAN_InitMailboxRegisters( &canTransfer2 );

    // Init CAN0 Mailbox 1, transmit
    CAN_ResetTransfer( &canTransfer1 );
    canTransfer1.can_number = 0;
    canTransfer1.mailbox_number = 1;
    canTransfer1.mode_reg = AT91C_CAN_MOT_TX | AT91C_CAN_PRIOR;
    canTransfer1.acceptance_mask_reg = 0x00000000;
    canTransfer1.identifier = AT91C_CAN_MIDvA & (0x09<<18);      // ID 9
    canTransfer1.data_low_reg = 0xAABBCCDD;
    canTransfer1.data_high_reg = 0xCAFEDECA;
    canTransfer1.control_reg = (AT91C_CAN_MDLC & (0x8<<16)); // Mailbox Data Length Code
    CAN_InitMailboxRegisters( &canTransfer1 );

    // Init CAN0 Mailbox 2, transmit
    canTransfer1.can_number = 0;
    canTransfer1.mailbox_number = 2;
    canTransfer1.mode_reg = AT91C_CAN_MOT_TX | (AT91C_CAN_PRIOR-(1<<16));
    canTransfer1.acceptance_mask_reg = 0x00000000;
    canTransfer1.identifier = AT91C_CAN_MIDvA & (0x0A<<18);      // ID 10
    canTransfer1.data_low_reg = 0x55667788;
    canTransfer1.data_high_reg = 0x99AABBCC;
    canTransfer1.control_reg = (AT91C_CAN_MDLC & (0x8<<16)); // Mailbox Data Length Code
    CAN_InitMailboxRegisters( &canTransfer1 );

    while( CAN_STATUS_SUCCESS !=  CAN_Read( &canTransfer2 ) ){}
    while( CAN_STATUS_SUCCESS !=  CAN_Write( &canTransfer1 ) ){}
    // wait answer
    while( CAN_IsInIdle(&canTransfer1) ) {}
    while( CAN_IsInIdle(&canTransfer2) ) {}

    TRACE_DEBUG("canTransfer2.data_low_reg 0x%X\n\r", canTransfer2.data_low_reg);
    TRACE_DEBUG("canTransfer2.data_high_reg 0x%X\n\r", canTransfer2.data_high_reg);
    if( (canTransfer2.data_low_reg == 0x55667788)
      &&(canTransfer2.data_high_reg == 0x99AABBCC) ) {
        TRACE_INFO("Test passed\n\r");
    }
    else {
        TRACE_INFO("Test ERROR\n\r");
    }
}

//------------------------------------------------------------------------------
/// Test CAN0 Mailboxes 1 & 2 transmitting to CAN1 Mailbox 15
//------------------------------------------------------------------------------
void Test3(void )
{
    CAN_ResetAllMailbox();

    TRACE_INFO("With Interrupt ");
    TRACE_INFO("CAN0 Mailboxes 1 & 2 transmitting to CAN1 Mailbox 15\n\r");

    // Init CAN1 Mailbox 15, reception with overwrite
    CAN_ResetTransfer( &canTransfer2 );
    canTransfer2.can_number = 1;
    canTransfer2.mailbox_number = 15;
    canTransfer2.mode_reg = AT91C_CAN_MOT_RXOVERWRITE;
    canTransfer2.acceptance_mask_reg = 0;
    canTransfer2.identifier = 0x0;
    canTransfer2.data_low_reg = 0x00000000;
    canTransfer2.data_high_reg = 0x00000000;
    canTransfer2.control_reg = 0x00000000;
    CAN_InitMailboxRegisters( &canTransfer2 );

    // Init CAN0 Mailbox 1, transmit
    CAN_ResetTransfer( &canTransfer1 );
    canTransfer1.can_number = 0;
    canTransfer1.mailbox_number = 1;
    canTransfer1.mode_reg = AT91C_CAN_MOT_TX | AT91C_CAN_PRIOR;
    canTransfer1.acceptance_mask_reg = 0x00000000;
    canTransfer1.identifier = AT91C_CAN_MIDvA & (0x09<<18);      // ID 9
    canTransfer1.data_low_reg = 0xAABBCCDD;
    canTransfer1.data_high_reg = 0x43424140;
    canTransfer1.control_reg = (AT91C_CAN_MDLC & (0x8<<16)); // Mailbox Data Length Code
    CAN_InitMailboxRegisters( &canTransfer1 );

    // Init CAN0 Mailbox 2, transmit
    canTransfer1.can_number = 0;
    canTransfer1.mailbox_number = 2;
    canTransfer1.mode_reg = AT91C_CAN_MOT_TX | (AT91C_CAN_PRIOR-(1<<16));
    canTransfer1.acceptance_mask_reg = 0x00000000;
    canTransfer1.identifier = AT91C_CAN_MIDvA & (0x0A<<18);      // ID 10
    canTransfer1.data_low_reg = 0x55667788;
    canTransfer1.data_high_reg = 0x99AABBCC;
    canTransfer1.control_reg = (AT91C_CAN_MDLC & (0x8<<16)); // Mailbox Data Length Code
    CAN_InitMailboxRegisters( &canTransfer1 );

    while( CAN_STATUS_SUCCESS !=  CAN_Write( &canTransfer1 ) ){}
    TRACE_INFO("Wait, wait, wait, wait\n\r");
    while( CAN_STATUS_SUCCESS !=  CAN_Read( &canTransfer2 ) ){}

    // wait answer
    while( CAN_IsInIdle(&canTransfer1) ) {}
    while( CAN_IsInIdle(&canTransfer2) ) {}

    TRACE_DEBUG("canTransfer2.data_low_reg 0x%X\n\r", canTransfer2.data_low_reg);
    TRACE_DEBUG("canTransfer2.data_high_reg 0x%X\n\r", canTransfer2.data_high_reg);
    if( (canTransfer2.data_low_reg == 0xAABBCCDD)
      &&(canTransfer2.data_high_reg == 0x43424140) ) {
        TRACE_INFO("Test passed\n\r");
    }
    else {
        TRACE_INFO("Test ERROR\n\r");
    }
}


//------------------------------------------------------------------------------
/// Test CAN0 Mailbox 3 asking for CAN1 Mailbox 3 transmission
//------------------------------------------------------------------------------
void Test4(void )
{
    CAN_ResetAllMailbox();

    TRACE_INFO("With Interrupt ");
    TRACE_INFO("CAN0 Mailbox 3 asking for CAN1 Mailbox 3 transmission\n\r");
    // Init CAN0 Mailbox 3, consumer mailbox
    // Sends a remote frame and waits for an answer
    // Init CAN1 Mailbox 15, reception with overwrite
    CAN_ResetTransfer( &canTransfer2 );
    canTransfer2.can_number = 1;
    canTransfer2.mailbox_number = 3;
    canTransfer2.mode_reg = AT91C_CAN_MOT_PRODUCER | AT91C_CAN_PRIOR;
    canTransfer2.acceptance_mask_reg = 0;
    canTransfer2.identifier = AT91C_CAN_MIDvA & (0x0B<<18);     // ID 11
    canTransfer2.data_low_reg = 0xEEDDFF00;
    canTransfer2.data_high_reg = 0x34560022;
    canTransfer2.control_reg = (AT91C_CAN_MDLC & (0x8<<16));
    CAN_InitMailboxRegisters( &canTransfer2 );

    // Init CAN0 Mailbox 1, transmit
    CAN_ResetTransfer( &canTransfer1 );
    canTransfer1.can_number = 0;
    canTransfer1.mailbox_number = 3;
    canTransfer1.mode_reg = AT91C_CAN_MOT_CONSUMER | AT91C_CAN_PRIOR;
    canTransfer1.acceptance_mask_reg = AT91C_CAN_MIDvA | AT91C_CAN_MIDvB;
    canTransfer1.identifier = AT91C_CAN_MIDvA & (0x0B<<18);     // ID 11
    canTransfer1.data_low_reg = 0x00000000;
    canTransfer1.data_high_reg = 0x00000000;
    canTransfer1.control_reg = 0x00000000;
    CAN_InitMailboxRegisters( &canTransfer1 );

    while( CAN_STATUS_SUCCESS !=  CAN_Write( &canTransfer2 ) ){}
    while( CAN_STATUS_SUCCESS !=  CAN_Write( &canTransfer1 ) ){}
    // wait answer
    while( CAN_IsInIdle(&canTransfer1) ) {}
    while( CAN_IsInIdle(&canTransfer2) ) {}

    TRACE_DEBUG("canTransfer2.data_low_reg 0x%X\n\r", canTransfer2.data_low_reg);
    TRACE_DEBUG("canTransfer2.data_high_reg 0x%X\n\r", canTransfer2.data_high_reg);
    if( (canTransfer2.data_low_reg == 0xEEDDFF00)
      &&(canTransfer2.data_high_reg == 0x34560022) ) {
        TRACE_INFO("Test passed\n\r");
    }
    else {
        TRACE_INFO("Test ERROR\n\r");
    }

}

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
    for( i=0; i<8; i++ ) {
        canTransfer1.can_number = 0;
        canTransfer1.mailbox_number = i+8;
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
    unsigned char CharReceive = 0;
    unsigned char dummy = 0;    
    unsigned int time;

    TRACE_CONFIGURE(DBGU_STANDARD, 115200, BOARD_MCK);   
    printf("-- Basic CAN Project %s --\n\r", SOFTPACK_VERSION);
    printf("-- %s\n\r", BOARD_NAME);
    printf("-- Compiled: %s %s --\n\r", __DATE__, __TIME__);
        
    printf("IP version: 0x%X\n\r", *(unsigned int*)AT91C_CAN_VR);

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
               
                CharReceive = 0;
                if ( DBGU_IsRxReady() ) {
                    
                    CharReceive = DBGU_GetChar();
                    
                    switch(CharReceive) {

                        case '1': {
                            while(!DBGU_IsRxReady()) {                        
                                
                                // Transmit, with acceptance mask
                                Test_TransmitWithAccMask(1, 0xAABBCCDD, 0x11223344);
                                
                                // Wait for the next second
                                time = RTT_GetTime(AT91C_BASE_RTTC);
                                while (time == RTT_GetTime(AT91C_BASE_RTTC));
                            }
                            dummy = DBGU_GetChar();                           
                        }
                        break;
                        case '2': {                           
                            while(!DBGU_IsRxReady()) {                        
                                
                                // Transmit, no acceptance mask
                                Test_TransmitWithoutAccMask(2, 0x12345678, 0xABCDEFAB);                            
                                
                                // Wait for the next second
                                time = RTT_GetTime(AT91C_BASE_RTTC);
                                while (time == RTT_GetTime(AT91C_BASE_RTTC));
                            }   
                            dummy = DBGU_GetChar();
                        }
                        break;
                        case '3': {
                            
                            DumpRegisters();
                        }
                        break;
                        default:
                            // nothing
                        break;
                    }
                
                    DisplayMenu();    
                }
            }
            if( CharReceive == 0 ) {
                printf("Receive - Maibox Number: %02d - Data (Low/High): %08X %08X\n\r", 
                    canTransfer1.mailbox_number, 
                    canTransfer1.data_low_reg,
                    canTransfer1.data_high_reg);
            }
        }
    }
    else {
        printf("INIT PB\n\r");
    }

    return 0;
}
