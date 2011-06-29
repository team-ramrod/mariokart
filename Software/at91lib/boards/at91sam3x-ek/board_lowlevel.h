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

//------------------------------------------------------------------------------
/// \unit
///
/// !!!Purpose
/// 
/// Collection of methods for lowlevel.
/// 
//------------------------------------------------------------------------------

#ifndef BOARD_LOWLEVEL_H
#define BOARD_LOWLEVEL_H



// System Controller
extern void SYS_IrqHandler(void);
// Parallel IO Controller A
extern void PIOA_IrqHandler(void);
// Parallel IO Controller B
extern void PIOB_IrqHandler(void);
// Parallel IO Controller C
extern void PIOC_IrqHandler(void);
// USART 0
extern void USART0_IrqHandler(void);
// USART 1
extern void USART1_IrqHandler(void);
// USART 2
extern void USART2_IrqHandler(void);
// USART 3
extern void USART3_IrqHandler(void);
// Serial Peripheral Interface 0
extern void SPI0_IrqHandler(void);
// Serial Peripheral Interface 1
extern void SPI1_IrqHandler(void);
// Timer Counter 0
extern void TC0_IrqHandler(void);
// Timer Counter 1
extern void TC1_IrqHandler(void);
// Timer Counter 2
extern void TC2_IrqHandler(void);
// USB Device Port
extern void UDP_IrqHandler(void);
// USB Device High Speed UDP_HS
extern void UDPHS_IrqHandler(void);
// ADC controller0
extern void ADCC0_IrqHandler(void);
// ADC controller1
extern void ADCC1_IrqHandler(void);
// TWI 0
extern void TWI0_IrqHandler(void);
// TWI 1
extern void TWI1_IrqHandler(void);
// PWM Controller
extern void PWM_IrqHandler(void);
// Serial Synchronous Controller 0
extern void SSC0_IrqHandler(void);
// Control Area Network Controller
extern void CAN_IrqHandler(void);
// Ethernet MAC
extern void MAC_IrqHandler(void);
// Advanced Interrupt Controller (IRQ0)
extern void AIC0_IrqHandler(void);
// Advanced Interrupt Controller (IRQ1)
extern void AIC1_IrqHandler(void);
// SUPPLY CONTROLLER
extern void SUPC_IrqHandler(void);
// RESET CONTROLLER
extern void RSTC_IrqHandler(void);
// REAL TIME CLOCK
extern void RTC_IrqHandler(void);
// REAL TIME TIMER
extern void RTT_IrqHandler(void);
// WATCHDOG TIMER
extern void WDT_IrqHandler(void);
// PMC
extern void PMC_IrqHandler(void);
// EFC0
extern void EFC0_IrqHandler(void);
// EFC1
extern void EFC1_IrqHandler(void);
// DBGU
extern void DBGU_IrqHandler(void);
// HSMC4
extern void HSMC4_IrqHandler(void);
// Multimedia Card Interface
extern void MCI0_IrqHandler(void);
// HDMA
extern void HDMA_IrqHandler(void);

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
extern void LowLevelInit(void);
extern void SysTick_Handler(void);

#endif // BOARD_LOWLEVEL_H

