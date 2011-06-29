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
** This file contains the exception handlers that use registry calling methodology
*/

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include <board.h>
#include <rtc/rtc.h>

#include "dfm_it.h"

//------------------------------------------------------------------------------
//         Variables
//------------------------------------------------------------------------------

static volatile TDFM_ItServList *gpItHandlerFirst = NULL;

//------------------------------------------------------------------------------
//         Exported Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Register It handler into the list
//------------------------------------------------------------------------------
int DFM_RegisterItHandler(TDFM_ItServList *pItHandler)
{
  volatile TDFM_ItServList *pTmpItHandler;
  
  pTmpItHandler = gpItHandlerFirst;
  
  if(pTmpItHandler == NULL) {
    gpItHandlerFirst = pItHandler;
    gpItHandlerFirst->next = NULL;
    
    return 0;
  }
  
  while(pTmpItHandler->next != NULL)
    pTmpItHandler = pTmpItHandler->next;
  
  pTmpItHandler->next = pItHandler;
  pItHandler->next = NULL;
  
  return 0;  
}

//------------------------------------------------------------------------------
//         UnRegister It handler into the list
//------------------------------------------------------------------------------
int DFM_UnRegisterItHandler(TDFM_ItServList *pItHandler)
{
  volatile TDFM_ItServList *pTmpItHandler;
  volatile TDFM_ItServList *pTmpPreItHandler;
  
  pTmpPreItHandler = gpItHandlerFirst;
  pTmpItHandler = gpItHandlerFirst;

  while(pTmpItHandler != NULL) {
    
    if(pItHandler == gpItHandlerFirst){
      gpItHandlerFirst = gpItHandlerFirst->next;
      pTmpPreItHandler = gpItHandlerFirst;
      pTmpItHandler = gpItHandlerFirst;
      continue;
    }
    
    if(pTmpItHandler == pItHandler) {
      if(pTmpPreItHandler != NULL && pTmpItHandler != NULL)
        pTmpPreItHandler->next = pTmpItHandler->next;
    }
    
    //proceed to next
      pTmpPreItHandler = pTmpItHandler;
      pTmpItHandler = pTmpItHandler->next;
    }
  
  return 0;
}

////------------------------------------------------------------------------------
//// Default irq handler
////------------------------------------------------------------------------------
//void IrqHandlerNotUsed(void)
//{
//    while(1);
//}
//
//------------------------------------------------------------------------------
// Provide weak aliases for each Exception handler to the IrqHandlerNotUsed. 
// As they are weak aliases, any function with the same name will override 
// this definition.
//------------------------------------------------------------------------------

////------------------------------------------------------------------------------
//// System interrupt
////------------------------------------------------------------------------------
//void NMI_Handler(void)
//{   
//    while(1);
//}
//
////------------------------------------------------------------------------------
////------------------------------------------------------------------------------
//void HardFault_Handler(void)
//{
//    while(1);
//}
//
////------------------------------------------------------------------------------
////------------------------------------------------------------------------------
//void MemManage_Handler(void)
//{
//    while(1);
//}
//
////------------------------------------------------------------------------------
////------------------------------------------------------------------------------
//void BusFault_Handler(void)
//{
//    while(1);
//}
//
////------------------------------------------------------------------------------
////------------------------------------------------------------------------------
//void UsageFault_Handler(void)
//{
//    while(1);
//}
//
////------------------------------------------------------------------------------
////------------------------------------------------------------------------------
//void SVC_Handler(void)
//{
//    while(1);
//}
//
////------------------------------------------------------------------------------
////------------------------------------------------------------------------------
//void DebugMon_Handler(void)
//{
//    while(1);
//}
//
////------------------------------------------------------------------------------
////------------------------------------------------------------------------------
//void PendSV_Handler(void)
//{
//    while(1);
//}
//

#if defined(cortexm3)
//------------------------------------------------------------------------------
// for Cortex M3
//------------------------------------------------------------------------------
void SysTick_Handler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == SysTick_IRQn)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}
#endif

//------------------------------------------------------------------------------
// External interrupt
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// for SAM7/9
//------------------------------------------------------------------------------
//void SYS_IrqHandler( void )
//{
//    while(1);
//}
//
////------------------------------------------------------------------------------
//// SUPPLY CONTROLLER
////------------------------------------------------------------------------------
//void SUPC_IrqHandler(void)
//{
//    while(1);
//}
//
////------------------------------------------------------------------------------
//// RESET CONTROLLER
////------------------------------------------------------------------------------
//void RSTC_IrqHandler(void)
//{
//    while(1);
//}

//------------------------------------------------------------------------------
// REAL TIME CLOCK
//------------------------------------------------------------------------------
void RTC_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  unsigned int status;
  
  status = AT91C_BASE_RTC->RTC_SR;
  if ((status & AT91C_RTC_SECEV) == AT91C_RTC_SECEV) {
    // Disable RTC interrupt
    RTC_DisableIt(AT91C_RTC_SECEV);
  }
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_RTC)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
  
  AT91C_BASE_RTC->RTC_SCCR = AT91C_RTC_SECEV;
  
  RTC_EnableIt(AT91C_RTC_SECEV);
}

//------------------------------------------------------------------------------
// REAL TIME TIMER
//------------------------------------------------------------------------------
void RTT_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_RTT)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}
//
////------------------------------------------------------------------------------
//// WATCHDOG TIMER
////------------------------------------------------------------------------------
//void WDT_IrqHandler(void)
//{
//    while(1);
//}

//------------------------------------------------------------------------------
// PMC
//------------------------------------------------------------------------------
void PMC_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_PMC)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// EFC0
//------------------------------------------------------------------------------
void EFC0_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_EFC0)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// EFC1
//------------------------------------------------------------------------------
void EFC1_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_EFC1)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// DBGU
//------------------------------------------------------------------------------
void DBGU_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_DBGU)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// HSMC4
//------------------------------------------------------------------------------
void HSMC4_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_HSMC4)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

////------------------------------------------------------------------------------
//// Parallel IO Controller A
////------------------------------------------------------------------------------
//void PIOA_IrqHandler(void)
//{
//    while(1);
//}
//
////------------------------------------------------------------------------------
//// Parallel IO Controller B
////------------------------------------------------------------------------------
//void PIOB_IrqHandler(void)
//{
//    while(1);
//}
//
////------------------------------------------------------------------------------
//// Parallel IO Controller C
////------------------------------------------------------------------------------
//void PIOC_IrqHandler(void)
//{
//    while(1);
//}
//
//------------------------------------------------------------------------------
// USART 0
//------------------------------------------------------------------------------
void USART0_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_HSMC4)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// USART 1
//------------------------------------------------------------------------------
void USART1_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_HSMC4)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// USART 2
//------------------------------------------------------------------------------
void USART2_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_HSMC4)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// USART 3
//------------------------------------------------------------------------------
void USART3_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_HSMC4)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

////------------------------------------------------------------------------------
//// Multimedia Card Interface
////------------------------------------------------------------------------------
//void MCI0_IrqHandler(void)
//{
//  while(1);
//}

//------------------------------------------------------------------------------
// TWI 0
//------------------------------------------------------------------------------
void TWI0_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_TWI0)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// TWI 1
//------------------------------------------------------------------------------
void TWI1_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_TWI1)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// Serial Peripheral Interface 0
//------------------------------------------------------------------------------
void SPI0_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_SPI0)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// Serial Synchronous Controller 0
//------------------------------------------------------------------------------
void SSC0_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_SSC0)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// Timer Counter 0
//------------------------------------------------------------------------------
void TC0_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_TC0)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// Timer Counter 1
//------------------------------------------------------------------------------
void TC1_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_TC1)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// Timer Counter 2
//------------------------------------------------------------------------------
void TC2_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_TC2)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// PWM Controller
//------------------------------------------------------------------------------
void PWM_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_PWMC)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// ADC controller0
//------------------------------------------------------------------------------
void ADCC0_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_ADC12B)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// ADC controller1
//------------------------------------------------------------------------------
void ADCC1_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_ADC)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

//------------------------------------------------------------------------------
// HDMA
//------------------------------------------------------------------------------
void HDMA_IrqHandler(void)
{
  volatile TDFM_ItServList *pTmpItServ;
  
  pTmpItServ = gpItHandlerFirst;
  while(pTmpItServ != NULL) {
    if(pTmpItServ->itID == AT91C_ID_HDMA)
      pTmpItServ->ItHandler();
    
    pTmpItServ = pTmpItServ->next;
  }
}

////------------------------------------------------------------------------------
//// USB Device High Speed UDP_HS
////------------------------------------------------------------------------------
//void UDPD_IrqHandler(void)
//{
//    while(1);
//}
