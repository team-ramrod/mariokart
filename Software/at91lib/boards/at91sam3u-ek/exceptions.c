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

/*
** This file contains the default exception handlers
** and exception table.
*/

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "exceptions.h"
#include <board.h>
#include <stdio.h>
#include <core_cm3.h>

//------------------------------------------------------------------------------
//         Local definitions
//------------------------------------------------------------------------------
/* define compiler specific symbols */
#if defined ( __CC_ARM   )      /*------------------RealView Compiler -----------------*/
  #define __ASM            __asm                                      /*!< asm keyword for ARM Compiler          */
  #define __INLINE         __inline                                   /*!< inline keyword for ARM Compiler       */

#elif defined ( __ICCARM__ )    /*------------------ ICC Compiler -------------------*/
  #define __ASM           __asm                                       /*!< asm keyword for IAR Compiler           */
  #define __INLINE        inline                                      /*!< inline keyword for IAR Compiler. Only avaiable in High optimization mode! */
  #define __NOP           __no_operation                              /*!< no operation intrinsic in IAR Compiler */

#elif defined   (  __GNUC__  )  /*------------------ GNU Compiler ---------------------*/
  #define __ASM            asm                                        /*!< asm keyword for GNU Compiler          */
  #define __INLINE         inline                                     /*!< inline keyword for GNU Compiler       */

#endif

// Memory Manage Address Register (MMAR) address valid flag
#define CFSR_MMARVALID    (0x01 << 7)
// Bus Fault Address Register (BFAR) address valid flag
#define CFSR_BFARVALID    (0x01 << 15)

//------------------------------------------------------------------------------
//         Types
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Fault status report.
/// Note: assume printf() function is avaliable here.
/// \param pFaultName pointer to fault name string.
/// \param pSP        SP pointer when the fault happened
//------------------------------------------------------------------------------
void FaultReport(char *pFaultName, unsigned int *pSP)
{
    unsigned int cfsr;
    unsigned int mmfar;
    unsigned int bfar;
    
    // Report fault
    printf("\n\rEnter %s exception.\n\r", pFaultName);
    cfsr = SCB->CFSR;
    mmfar = SCB->MMFAR;
    bfar = SCB->BFAR;
    printf("MMSR: 0x%02x\n\r", (cfsr & 0xFF));
    if ((cfsr & CFSR_MMARVALID) != 0) {
        printf("MMAR: 0x%08x\n\r", mmfar);
    }
    printf("BFSR: 0x%02x\n\r", ((cfsr >> 8) & 0xFF));
    if ((cfsr & CFSR_BFARVALID) != 0) {
        printf("BFAR: 0x%08x\n\r", bfar); 
    }
    printf("UFSR: 0x%04x\n\r", ((cfsr >> 16) & 0xFFFF));
    printf("HFSR: 0x%08x\n\r", (unsigned int)SCB->HFSR);
    printf("DFSR: 0x%08x\n\r", (unsigned int)SCB->DFSR);
    printf("AFSR: 0x%08x\n\r", (unsigned int)SCB->AFSR);
    printf("Stacked LR: 0x%08x\n\r", (unsigned int)(pSP[5]));
    printf("Stacked PC: 0x%08x\n\r", (unsigned int)(pSP[6]));

    // Clear fault status bits (write-clear)
    SCB->CFSR = SCB->CFSR;
    SCB->HFSR = SCB->HFSR;
    SCB->DFSR = SCB->DFSR;
    SCB->AFSR = SCB->AFSR;
}

//------------------------------------------------------------------------------
//         Exception Handlers
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Default irq handler
//------------------------------------------------------------------------------
void IrqHandlerNotUsed(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Provide weak aliases for each Exception handler to the IrqHandlerNotUsed. 
// As they are weak aliases, any function with the same name will override 
// this definition.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// System interrupt
//------------------------------------------------------------------------------
WEAK void NMI_Handler(void)
{   
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
WEAK void HardFault_HandlerBody(unsigned int *pSP)
{
    FaultReport("HardFault", pSP);
    while(1);
}

#if defined ( __CC_ARM   )
WEAK __ASM void HardFault_Handler(void)
{
    import HardFault_HandlerBody
    tst lr, #0x4
    ite eq
    mrseq r0, msp
    mrsne r0, psp
    b HardFault_HandlerBody
}

#elif defined ( __ICCARM__ )
WEAK void HardFault_Handler(void)
{
    __ASM("tst lr, #0x4");
    __ASM("ite eq");
    __ASM("mrseq r0, msp");
    __ASM("mrsne r0, psp");
    __ASM("b HardFault_HandlerBody");
}

#elif defined   (  __GNUC__  )
WEAK void HardFault_Handler(void)
{
    __ASM volatile ("tst lr, #0x4");
    __ASM volatile ("ite eq");
    __ASM volatile ("mrseq r0, msp");
    __ASM volatile ("mrsne r0, psp");
    __ASM volatile ("add r0, r0, #4"); // because one word has been pushed to sp in this function
    __ASM volatile ("b HardFault_HandlerBody");
}

#endif

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
WEAK void MemManage_HandlerBody(unsigned int *pSP)
{
    FaultReport("MenManage", pSP);
    while(1);
}

#if defined ( __CC_ARM   )
WEAK __ASM void MemManage_Handler(void)
{
    import MemManage_HandlerBody
    tst lr, #0x4
    ite eq
    mrseq r0, msp
    mrsne r0, psp
    b MemManage_HandlerBody
}

#elif defined ( __ICCARM__ )
WEAK void MemManage_Handler(void)
{
    __ASM("tst lr, #0x4");
    __ASM("ite eq");
    __ASM("mrseq r0, msp");
    __ASM("mrsne r0, psp");
    __ASM("b MemManage_HandlerBody");
}

#elif defined   (  __GNUC__  )
WEAK void MemManage_Handler(void)
{
    __ASM volatile ("tst lr, #0x4");
    __ASM volatile ("ite eq");
    __ASM volatile ("mrseq r0, msp");
    __ASM volatile ("mrsne r0, psp");
    __ASM volatile ("add r0, r0, #4"); // because one word has been pushed to sp in this function
    __ASM volatile ("b MemManage_HandlerBody");
}

#endif

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
WEAK void BusFault_HandlerBody(unsigned int *pSP)
{
    FaultReport("BusFault", pSP);
    while(1);
}

#if defined ( __CC_ARM   )
WEAK __ASM void BusFault_Handler(void)
{
    import BusFault_HandlerBody
    tst lr, #0x4
    ite eq
    mrseq r0, msp
    mrsne r0, psp
    b BusFault_HandlerBody
}

#elif defined ( __ICCARM__ )
WEAK void BusFault_Handler(void)
{
    __ASM("tst lr, #0x4");
    __ASM("ite eq");
    __ASM("mrseq r0, msp");
    __ASM("mrsne r0, psp");
    __ASM("b BusFault_HandlerBody");
}

#elif defined   (  __GNUC__  )
WEAK void BusFault_Handler(void)
{
    __ASM volatile ("tst lr, #0x4");
    __ASM volatile ("ite eq");
    __ASM volatile ("mrseq r0, msp");
    __ASM volatile ("mrsne r0, psp");
    __ASM volatile ("add r0, r0, #4"); // because one word has been pushed to sp in this function
    __ASM volatile ("b BusFault_HandlerBody");
}

#endif

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
WEAK void UsageFault_HandlerBody(unsigned int *pSP)
{
    FaultReport("UsageFault", pSP);
    while(1); 
}

#if defined ( __CC_ARM   )
WEAK __ASM void UsageFault_Handler(void)
{
    import UsageFault_HandlerBody
    tst lr, #0x4
    ite eq
    mrseq r0, msp
    mrsne r0, psp
    b UsageFault_HandlerBody
}

#elif defined ( __ICCARM__ )
WEAK void UsageFault_Handler(void)
{
    __ASM("tst lr, #0x4");
    __ASM("ite eq");
    __ASM("mrseq r0, msp");
    __ASM("mrsne r0, psp");
    __ASM("b UsageFault_HandlerBody");
}

#elif defined   (  __GNUC__  )
WEAK void UsageFault_Handler(void)
{
    __ASM volatile ("tst lr, #0x4");
    __ASM volatile ("ite eq");
    __ASM volatile ("mrseq r0, msp");
    __ASM volatile ("mrsne r0, psp");
    __ASM volatile ("add r0, r0, #4"); // because one word has been pushed to sp in this function
    __ASM volatile ("b UsageFault_HandlerBody");
}

#endif

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
WEAK void SVC_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
WEAK void DebugMon_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
WEAK void PendSV_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// for Cortex M3
//------------------------------------------------------------------------------
WEAK void SysTick_Handler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// External interrupt
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// for SAM7/9
//------------------------------------------------------------------------------
void SYS_IrqHandler( void )
{
    while(1);
}

//------------------------------------------------------------------------------
// SUPPLY CONTROLLER
//------------------------------------------------------------------------------
WEAK void SUPC_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// RESET CONTROLLER
//------------------------------------------------------------------------------
WEAK void RSTC_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// REAL TIME CLOCK
//------------------------------------------------------------------------------
WEAK void RTC_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// REAL TIME TIMER
//------------------------------------------------------------------------------
WEAK void RTT_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// WATCHDOG TIMER
//------------------------------------------------------------------------------
WEAK void WDT_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// PMC
//------------------------------------------------------------------------------
WEAK void PMC_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// EFC0
//------------------------------------------------------------------------------
WEAK void EFC0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// EFC1
//------------------------------------------------------------------------------
WEAK void EFC1_IrqHandler(void)
{
    while(1);
}
//------------------------------------------------------------------------------
// DBGU
//------------------------------------------------------------------------------
WEAK void DBGU_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// HSMC4
//------------------------------------------------------------------------------
WEAK void HSMC4_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Parallel IO Controller A
//------------------------------------------------------------------------------
WEAK void PIOA_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Parallel IO Controller B
//------------------------------------------------------------------------------
WEAK void PIOB_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Parallel IO Controller C
//------------------------------------------------------------------------------
WEAK void PIOC_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// USART 0
//------------------------------------------------------------------------------
WEAK void USART0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// USART 1
//------------------------------------------------------------------------------
WEAK void USART1_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// USART 2
//------------------------------------------------------------------------------
WEAK void USART2_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// USART 3
//------------------------------------------------------------------------------
WEAK void USART3_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Multimedia Card Interface
//------------------------------------------------------------------------------
WEAK void MCI0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// TWI 0
//------------------------------------------------------------------------------
WEAK void TWI0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// TWI 1
//------------------------------------------------------------------------------
WEAK void TWI1_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Serial Peripheral Interface 0
//------------------------------------------------------------------------------
WEAK void SPI0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Serial Synchronous Controller 0
//------------------------------------------------------------------------------
WEAK void SSC0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Timer Counter 0
//------------------------------------------------------------------------------
WEAK void TC0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Timer Counter 1
//------------------------------------------------------------------------------
WEAK void TC1_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// Timer Counter 2
//------------------------------------------------------------------------------
WEAK void TC2_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// PWM Controller
//------------------------------------------------------------------------------
WEAK void PWM_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// ADC controller0
//------------------------------------------------------------------------------
WEAK void ADCC0_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// ADC controller1
//------------------------------------------------------------------------------
WEAK void ADCC1_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// HDMA
//------------------------------------------------------------------------------
WEAK void HDMA_IrqHandler(void)
{
    while(1);
}

//------------------------------------------------------------------------------
// USB Device
//------------------------------------------------------------------------------
WEAK void USBD_IrqHandler(void)
{
    while(1);
}

