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

//-----------------------------------------------------------------------------
//         Headers
//-----------------------------------------------------------------------------
#include <drivers/twi/twid.h>
#include <utility/trace.h>
#include "CH7024.h"

/// Slave address of Chrontel CH7024 chip.
#define CH7024_ADDRESS  0x76

/// terminating list entry for register in configuration file
#define CH7024_REG_TERM 0xFF
/// terminating list entry for value in configuration file
#define CH7024_VAL_TERM 0xFF

/// CH7024 register configure value
const struct ch7024_reg ch7024_config[]= {
    //POWER ON&DAC OFF
    {0x04,0x0C},    // Power Management: DAC1 and DAC2 are power down

    //HUE
    {0x05,0x30},    // adjust hue setting of the image
    //SATURATION
    {0x06,0x30},    // adjust the color saturation of the image
    //CONTRAST
    {0x07,0x48},    // adjust the contrast level of the image
    //BRIGHTNESS
    {0x08,0x80},    // adjusts the brightness level of the image
    //SHARPNESS
    {0x09,0x04},    // control the sharpness adjustment of the image

    {0x0B,0x04},    // Crystal Register: 4: 13MHz
    {0x0C,0x00},    // Outputs are not dual CVBS

    //RGB888
    {0x0D,0x00},    // IDF[2:0] (bits 2-0) define the input data format

    //SLAVE
    {0x0E,0x0C},    // SYNC Control: Horizontal and vertical polarity are positive

    {0x0F,0x00},    // auxiliary bit to help latch input data correctly
    //{0x10, 0x01},  // TV Adaptive Flicker Filter Control

    //output setting
    {0x1E,0x05},    // Horizontal Scaling
    {0x1F,0x00},    // Horizontal Scaling
    {0x20,0x00},    // TV vertical position adjustment
    {0x21,0x81},    // TV vertical position adjustment
    {0x22,0x00},    // TV horizontal position adjustment
    {0x23,0x76},    // TV horizontal position adjustment

    //REG[34]TO[37] will be use to
    //set calculate the sub-carrier frequency
    {0x1C,0x90},    // Disables Dot Crawl reduction

    //NTSC_M
    {0x0A,0x10},
    //HTI=1002=720+;  (LCDC)1002=07+250+720+25
    {0x11,0x1A},    // Input Horizontal Total Pixels  //HT[10][9][8]HA[10][9][8]
    {0x12,0xD0},    // Input Horizontal Active Pixels //HA(0x2D0)
    {0x13,0xEA},    // Input Horizontal Total Pixels  //HT(0x3EA)
    {0x14,0x00},    // Input Horizontal Sync Offset
    {0x15,0x19},    // Input Horizontal Sync Offset   //HO
    {0x16,0x07},    // Input Horizontal Sync Offset   //HW

    //VTI=555=480+ ;  (LCDC)VW=08 555=70+480+05
    {0x17,0x09},    // Input Vertical Active Pixels + Input Vertical Sync Offset //VT[9][8]VA[9][8]
    {0x18,0xE0},    // Input Vertical Active Pixels //VA(0X1E0)
    {0x19,0x2B},    // VTI                          //VTI(0X22B)
    {0x1A,0x05},    // Input Vertical Sync Offset   //VO
    {0x1B,0x08},    // Input Vertical Sync Offset   //VW

    //PLL ratio R1,R2,R3,R4,R5
    {0x30,0x1B},
    {0x31,0x12},

    //P
    {0x28,0x00},
    {0x29,0xAB},
    {0x2A,0x90},

    //N
    {0x2B,0x36},
    {0x2C,0xFC},
    {0x2D,0x90},

    //T
    {0x2E,0x4F},

    //sub carrier frequency r1-r4
    {0x34,0x01},    // SCFREQ[26:0], the Sub-carrier Frequency Value
    {0x35,0x19},    // SCFREQ[26:0], the Sub-carrier Frequency Value
    {0x36,0xF5},    // SCFREQ[26:0], the Sub-carrier Frequency Value
    {0x37,0x8D},    // SCFREQ[26:0], the Sub-carrier Frequency Value

    //enable test mode
    //{0x02,0x01},
    //{0x04,0x44},
    //{0x02,0x00},

    //POWER ON&DAC ON
    {0x04,0x00},

    //register end
    {0xFF,0xFF}
};

//-----------------------------------------------------------------------------
//         Local Functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//         Global Functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/// Read a value from a register in an CH7024 device.
/// \param pTwid TWI interface
/// \param reg Register to be read
/// \param pData Data read
/// \return 0 if no error, otherwize TWID_ERROR_BUSY
//-----------------------------------------------------------------------------
unsigned char ch7024_read_reg(Twid *pTwid, unsigned char reg, unsigned char *pData)
{
    unsigned char status;

    status = TWID_Read( pTwid, CH7024_ADDRESS, reg, 1, pData, 1, 0);
    if( status != 0 ) {
        TRACE_INFO("ch7023_read_reg pb");
    }
    return status;
}

//-----------------------------------------------------------------------------
/// Write a value to a register in an CH7024 device.
/// \param pTwid TWI interface
/// \param reg Register to be write
/// \param val Value to be writte
/// \return 0 if no error, otherwize TWID_ERROR_BUSY
//-----------------------------------------------------------------------------
unsigned char ch7024_write_reg(Twid *pTwid, unsigned char reg, unsigned char val)
{
    unsigned char status = 0;

    status = TWID_Write(pTwid, CH7024_ADDRESS, reg, 1, &val, 1, 0);
    if( status != 0 ) {
        TRACE_INFO("ch7024_write_reg pb");
    }
    return status;
}

//-----------------------------------------------------------------------------
/// Sequence For correct operation of the TV encoder
/// Following the steps below to identify CH7023/CH7024 chip.
///   Step 1: Read the value of register 0x00;
///           If value is 0x45, CH7023/CH7024 is present.
///           Other value, none of CH7023/CH7024 is present;
///   Step 2: Write '1' to bit 1 of register 0x40(set 0x40[1]=1) and read back;
///           If the bit is '0' the chip present is CH7024;
///           Else the bit is '1' the chip present is CH7023.
///
/// \param pTwid TWI interface
/// \return 1 if initialization ok, otherwise 0
//-----------------------------------------------------------------------------
unsigned char ch7024_init(Twid *pTwid)
{
    unsigned char id=0;

    // Device ID Register [0x00]
    if( 0 == ch7024_read_reg(pTwid, 0x00, &id) ) {
        TRACE_DEBUG("[0x00]= 0x%X\n\r", id);
        if( id == 0x45 ) {
            TRACE_INFO("TV encoder detected!\n\r");
            return 1;
        }
        else {
            TRACE_INFO("Problem captor: bad PID\n\r");
        }
    }
    else {
        TRACE_INFO("Problem: TV encoder not responding\n\r");
    }
    return 0;
}

//-----------------------------------------------------------------------------
/// Initialize a list of ch7024 registers.
/// The list of registers is terminated by the pair of values
/// { CH7024_REG_TERM, CH7024_VAL_TERM }.
/// Returns zero if successful, or non-zero otherwise.
/// \param pTwid TWI interface
/// \param pReglist Register list to be written
/// \return 0 if no error, otherwize TWID_ERROR_BUSY
//-----------------------------------------------------------------------------
int ch7024_write_regs(Twid *pTwid, const struct ch7024_reg* pReglist)
{
    int err;
    int size=0;
    const struct ch7024_reg *pNext = pReglist;
    unsigned int i=0;

    TRACE_DEBUG("ch7024_write_regs:");
    while (!((pNext->reg == CH7024_REG_TERM) && (pNext->val == CH7024_VAL_TERM))) {
        err = ch7024_write_reg(pTwid, pNext->reg, pNext->val);
        TRACE_DEBUG("+(%d) ", size);
        size++;

        //delay
        for(i=0; i<6000; i++ );

        if (err == TWID_ERROR_BUSY){
            TRACE_INFO("-\n\rE- ch7024_write_regs: TWI ERROR\n\r");
            return err;
        }
        pNext++;
    }
    TRACE_DEBUG("\n\r");
    return 0;
}

//-----------------------------------------------------------------------------
/// Configure the CH7024
//-----------------------------------------------------------------------------
void ch7024_configure(Twid *pTwid)
{
    const struct ch7024_reg *reg_conf;
    reg_conf = ch7024_config;
    TRACE_INFO("TV encoder configure\n\r");
    ch7024_write_regs(pTwid, reg_conf);
}

//-----------------------------------------------------------------------------
/// Reset the CH7024
//-----------------------------------------------------------------------------
void ch7024_reset(Twid *pTwid)
{
    int i;
    TRACE_INFO("TV encoder reset\n\r");
    ch7024_write_reg(pTwid, 0x03, 0x00);
    for(i=0;i<10000;i++);
    ch7024_write_reg(pTwid, 0x03, 0x03);
}

//-----------------------------------------------------------------------------
/// Dump all register
/// \param pTwid TWI interface
//-----------------------------------------------------------------------------
void ch7024_DumpRegisters(Twid *pTwid)
{
    int i;
    unsigned char value;

    TRACE_INFO("Dump all TV encoder register\n\r");
    for(i = 0; i <= 0x7F; i++) {
        value = 0;
        ch7024_read_reg(pTwid, i, &value);
        TRACE_INFO("[0x%02x]=0x%02x ", i, value);
        if( ((i+1)%5) == 0 ) {
            TRACE_INFO("\n\r");
        }
    }
    TRACE_INFO("\n\r");
}
