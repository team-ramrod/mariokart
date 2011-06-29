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
/// !Purpose
/// 
/// UDA1342 driver
/// 
/// !Usage
/// 
/// Explanation on the usage of the code made available through the header file.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include "uda1342.h"
#include <board.h>
#include <utility/trace.h>

#define TWITIMEOUTMAX 50000

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

typedef struct {
    const char*    name;
    unsigned char  address;
    unsigned short defvalue;   
} t_register;

t_register tab_uda1342_register[] = 
{
    { "SYSTEM           ", UDA1342_REG_SYSTEM           , 0x1A02 },
    { "SUB_SYSTEM       ", UDA1342_REG_SUB_SYSTEM       , 0x0000 },
    { "DAC_FEATURE      ", UDA1342_REG_DAC_FEATURE      , 0x0000 },
    { "DAC_MASTER_VOLUME", UDA1342_REG_DAC_MASTER_VOLUME, 0x0000 },
    { "DAC_MIXER_VOLUME ", UDA1342_REG_DAC_MIXER_VOLUME , 0x0000 },
    { "GAIN_CH1         ", UDA1342_REG_GAIN_CH1         , 0x0000 },
    { "GAIN_CH2         ", UDA1342_REG_GAIN_CH2         , 0x0000 },
    { "EVALUATION       ", UDA1342_REG_EVALUATION       , 0x0000 },
};

#define TAB_UDA1342_SIZE (sizeof(tab_uda1342_register)/sizeof(tab_uda1342_register[0]))

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Read data from UDA1342 Register.
/// \param pTwid   pointer to twi driver structure
/// \param device   twi slave address
/// \param regAddr       register address to read.
//------------------------------------------------------------------------------
unsigned short UDA1342_Read(
    Twid *pTwid,
    unsigned char device,
    unsigned char regAddr)
{
    unsigned short bitsDataRegister;
    unsigned char Tdata[2]={0,0};

    TWID_Read(pTwid, device, regAddr, 1, Tdata, 2, 0);
    bitsDataRegister = (Tdata[0] << 8) | Tdata[1];
    return bitsDataRegister;  
}

//------------------------------------------------------------------------------
/// Write data to UDA1342 Register.
/// \param pTwid   pointer to twi driver structure
/// \param device   twi slave address
/// \param regAddr       register address to read.
/// \param data    data to write
//------------------------------------------------------------------------------
void UDA1342_Write(
    Twid *pTwid,
    unsigned char device,
    unsigned char regAddr,
    unsigned short data)
{
    unsigned char tmpData[2];
    tmpData[0] = (data & 0xff00) >> 8;
    tmpData[1] = data & 0xff;      
    TWID_Write(pTwid, device, regAddr, 1, tmpData, 2, 0);
}

//------------------------------------------------------------------------------
/// Init UDA1342 to DAC mode.
/// \param pTwid   pointer to twi driver structure
/// \param device   twi slave address
//------------------------------------------------------------------------------
unsigned char UDA1342_DAC_Init(
    Twid *pTwid, 
    unsigned int device,
    unsigned char isClock384)
{
    // reset all registers to default values 
    // and set system register
    if(isClock384)
        UDA1342_Write(pTwid, device, UDA1342_REG_SYSTEM, 0x9A22);
    else
        UDA1342_Write(pTwid, device, UDA1342_REG_SYSTEM, 0x9A02);
    
    return 0;
}

//------------------------------------------------------------------------------
/// Display component registers
/// \param pTwid   pointer to twi driver structure
/// \param device   twi slave address
//------------------------------------------------------------------------------
void UDA1342_DisplayRegisters(
    Twid *pTwid, 
    unsigned int device)
{
    unsigned int i;
    
    TRACE_PERM_WP("UDA1342 registers values\n\r");    
    TRACE_PERM_WP("------------------------------------\n\r");      
    
    for(i=0;i<TAB_UDA1342_SIZE;i++) {

        TRACE_PERM_WP("  %s %02x val %04x (%04x)\n\r", 
               tab_uda1342_register[i].name,
               tab_uda1342_register[i].address,
               UDA1342_Read(pTwid, device, tab_uda1342_register[i].address),
               tab_uda1342_register[i].defvalue
               );
    }
}
