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
/// Definition of methods for UDA1342 driver.
///
/// !!!Usage
///
/// -# UDA1342_Read
/// -# UDA1342_Write
/// -# UDA1342_DAC_Init
//------------------------------------------------------------------------------

#ifndef UDA1342_H
#define UDA1342_H

#include <board.h>
#include <twi/twid.h>

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

// Master Clock Selector
#define UDA1342_MCK_SEL_256_FS 0
#define UDA1342_MCK_SEL_384_FS 1

//------------------------------------------------------------------------------
//         Register definition
//------------------------------------------------------------------------------

// DAC user interface register addresses

/// \internal UDA1342 system register address
#define UDA1342_REG_SYSTEM              0x00
/// \internal UDA1342 sub system register address
#define UDA1342_REG_SUB_SYSTEM          0x01
/// \internal UDA1342 DAC feature register address
#define UDA1342_REG_DAC_FEATURE         0x10
/// \internal UDA1342 DAC master volume register address
#define UDA1342_REG_DAC_MASTER_VOLUME   0x11
/// \internal UDA1342 DAC mixer volume register address
#define UDA1342_REG_DAC_MIXER_VOLUME    0x12
/// \internal UDA1342 DAC ADC input and mixer gain channel 1 register address
#define UDA1342_REG_GAIN_CH1            0x20
/// \internal UDA1342 DAC ADC input and mixer gain channel 2 register address
#define UDA1342_REG_GAIN_CH2            0x21
/// \internal UDA1342 DAC evaluation register address
#define UDA1342_REG_EVALUATION          0x30

// Register field values
// REG_SYSTEM
#define UDA1342_BIT_SYSTEM_RST  (1 << 15)
#define UDA1342_BIT_SYSTEM_QS   (1 << 14)
#define UDA1342_BIT_SYSTEM_MDC  (1 << 13)
#define UDA1342_BIT_SYSTEM_DC   (1 << 12)
#define UDA1342_BIT_SYSTEM_AM2  (1 << 11)
#define UDA1342_BIT_SYSTEM_AM1  (1 << 10)
#define UDA1342_BIT_SYSTEM_AM0  (1 << 9)
#define UDA1342_BIT_SYSTEM_PAD  (1 << 8)
#define UDA1342_BIT_SYSTEM_SC1  (1 << 6)
#define UDA1342_BIT_SYSTEM_SC0  (1 << 5)
#define UDA1342_BIT_SYSTEM_IF2  (1 << 4)
#define UDA1342_BIT_SYSTEM_IF1  (1 << 3)
#define UDA1342_BIT_SYSTEM_IF0  (1 << 2)
#define UDA1342_BIT_SYSTEM_DP   (1 << 1)
#define UDA1342_BIT_SYSTEM_PDA  (1 << 0)

#define UDA1342_BIT_DAC_FEATURE_DM  (1 << 5)

/*
RST FUNCTION
0 no reset
1 reset registers to default

SC1 SC0 FUNCTION
0 0 256fs
0 1 384fs
1 0 512fs
1 1 768fs

IF2 IF1 IF0 FUNCTION

0 0 0 I S-bus
0 0 1 LSB-justified16 bits
0 1 0 LSB-justified 20 bits
0 1 1 LSB-justified 24 bits
1 0 0 MSB-justified
1 0 1 LSB-justified 16 bits input and MSB-justified output
1 1 0 LSB-justified 20 bits input and MSB-justified output
1 1 1 LSB-justified 24 bits input and MSB-justified output

MT/MTA/MTB FUNCTION (mute)
0 no muting
1 muting

QM FUNCTION (quick mute mode)
0 soft mute mode
1 quick mute mode
*/

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

extern unsigned short UDA1342_Read(
    Twid *pTwid,
    unsigned char device,
    unsigned char regAddr);

extern void UDA1342_Write(
    Twid *pTwid,
    unsigned char device,
    unsigned char regAddr,
    unsigned short data);

extern unsigned char UDA1342_DAC_Init(
    Twid *pTwid, 
    unsigned int device,
    unsigned char isClock384);

void UDA1342_DisplayRegisters(
    Twid *pTwid, 
    unsigned int device);

#endif // UDA1342_H

