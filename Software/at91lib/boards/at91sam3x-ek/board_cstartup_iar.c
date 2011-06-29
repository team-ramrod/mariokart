/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

// Based on IAR software example

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include "board.h"
#include "board_lowlevel.h"

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void NMI_Handler(void)
{   
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void HardFault_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void MemManage_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void BusFault_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void UsageFault_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void SVC_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void DebugMon_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void PendSV_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//void SysTick_Handler(void)
//{
//    while(1);
//}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
void IrqHandlerNotUsed(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//         Exception Table
//------------------------------------------------------------------------------

#pragma language=extended
#pragma segment="CSTACK"

extern void __iar_program_start( void );
extern void __low_level_init( void );

void NMI_Handler( void );
void HardFault_Handler( void );
void MemManage_Handler( void );
void BusFault_Handler( void );
void UsageFault_Handler( void );
void SVC_Handler( void );
void DebugMon_Handler( void );
void PendSV_Handler( void );
void SysTick_Handler( void );

typedef void( *intfunc )( void );
typedef union { intfunc __fun; void * __ptr; } intvec_elem;

// The vector table is normally located at address 0.
// When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
// If you need to define interrupt service routines,
// make a copy of this file and include it in your project.
// The name "__vector_table" has special meaning for C-SPY:
// it is where the SP start value is found, and the NVIC vector
// table register (VTOR) is initialized to this address if != 0.

#pragma location = ".intvec"
const intvec_elem __vector_table[] =
{
    { .__ptr = __sfe( "CSTACK" ) },
    __iar_program_start,

    NMI_Handler,
    HardFault_Handler,
    MemManage_Handler,
    BusFault_Handler,
    UsageFault_Handler,
    0, 0, 0, 0,             // Reserved
    SVC_Handler,
    DebugMon_Handler,
    0,                      // Reserved
    PendSV_Handler,
    SysTick_Handler,

    // Configurable interrupts
    SUPC_IrqHandler,    // 0  SUPPLY CONTROLLER
    RSTC_IrqHandler,    // 1  RESET CONTROLLER
    RTC_IrqHandler,     // 2  REAL TIME CLOCK
    RTT_IrqHandler,     // 3  REAL TIME TIMER
    WDT_IrqHandler,     // 4  WATCHDOG TIMER
    PMC_IrqHandler,     // 5  PMC
    EFC0_IrqHandler,    // 6  EFC0
    EFC1_IrqHandler,    // 7  EFC1
    DBGU_IrqHandler,    // 8  DBGU
    HSMC4_IrqHandler,   // 9  HSMC4
    PIOA_IrqHandler,    // 10 Parallel IO Controller A
    PIOB_IrqHandler,    // 11 Parallel IO Controller B
    PIOC_IrqHandler,    // 12 Parallel IO Controller C
    USART0_IrqHandler,  // 13 USART 0
    USART1_IrqHandler,  // 14 USART 1
    USART2_IrqHandler,  // 15 USART 2
    USART3_IrqHandler,  // 16 USART 3
    MCI0_IrqHandler,    // 17 Multimedia Card Interface
    TWI0_IrqHandler,    // 18 TWI 0
    TWI1_IrqHandler,    // 19 TWI 1
    SPI0_IrqHandler,    // 20 Serial Peripheral Interface
    SSC0_IrqHandler,    // 21 Serial Synchronous Controller 0
    TC0_IrqHandler,     // 22 Timer Counter 0
    TC1_IrqHandler,     // 23 Timer Counter 1
    TC2_IrqHandler,     // 24 Timer Counter 2
    PWM_IrqHandler,     // 25 Pulse Width Modulation Controller
    ADCC0_IrqHandler,   // 26 ADC controller0
    ADCC1_IrqHandler,   // 27 ADC controller1
    HDMA_IrqHandler,    // 28 HDMA
    UDPHS_IrqHandler,   // 29 USB Device High Speed UDP_HS
    IrqHandlerNotUsed   // 30 not used
};

//------------------------------------------------------------------------------
/// This is the code that gets called on processor reset. To initialize the
/// device.
//------------------------------------------------------------------------------
void __low_level_init( void )
{
    LowLevelInit();

    // Setup the Vector table
    // Copy the vector table to SRAM (0x20000000)
    {
/*
        unsigned int * src = __section_begin(".intvec");
        unsigned int * src_end = __section_end(".intvec");
        unsigned int * des = &__ICFEDIT_region_RAM_VECT_start__;
        if (src != des) {
            for (; src < src_end; ) {
                
                *des ++ = *src ++;
            }
        }
*/
        // Table base is in RAM
        AT91C_BASE_NVIC->NVIC_VTOFFR |= AT91C_NVIC_TBLBASE_RAM;
    }
}

//------------------------------------------------------------------------------
/// Returns the address of the exception table (in RAM)
//------------------------------------------------------------------------------
//IrqHandler * GetExceptionTable( void )
//{
//    return (IrqHandler *)&__ICFEDIT_region_RAM_VECT_start__;
//}


