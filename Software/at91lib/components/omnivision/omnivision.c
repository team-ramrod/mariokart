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
#include <peripherals/pio/pio.h>
#include <omnivision/omnivision.h>
#include <utility/trace.h>

/// Slave address of OMNIVISION chips.
#define OV_CAPTOR_ADDRESS   (0x60>>1)


/// terminating list entry for register in configuration file
#define OV_REG_TERM 0xFF
/// terminating list entry for value in configuration file
#define OV_VAL_TERM 0xFF 

//-----------------------------------------------------------------------------
//         Local Functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/// Reset using ctrl signal
/// \param pCtrl1 PIO interface
//-----------------------------------------------------------------------------
static void ov_reset(const Pin *pCtrl1)
{
  volatile unsigned int i;

  if(pCtrl1->id == 0)
      return;

  pCtrl1->pio->PIO_CODR = pCtrl1->mask;
  for(i=0; i<6000; i++ );
  pCtrl1->pio->PIO_SODR = pCtrl1->mask;
  for(i=0; i<6000; i++ );
}

//-----------------------------------------------------------------------------
/// Read PID and VER
/// \param pTwid TWI interface
/// \return VER | (PID<<8)
//-----------------------------------------------------------------------------
static unsigned short ov_id(Twid *pTwid)
{
    unsigned char id=0;
    unsigned char ver=0;

    // OV_PID
    ov_read_reg(pTwid, 0x0A, &id);
    TRACE_INFO("PID  = 0x%X\n\r", id);

    // OV_VER
    ov_read_reg(pTwid, 0x0B, &ver);
    TRACE_INFO("VER  = 0x%X\n\r", ver);

    return((unsigned short)(id <<8) | ver);
}

//-----------------------------------------------------------------------------
/// Read Manufacturer
/// \param pTwid TWI interface
/// \return 0 if error; 1 if the good captor is present
//-----------------------------------------------------------------------------
static unsigned char ov_Manufacturer(Twid *pTwid)
{
    unsigned char midh=0;
    unsigned char midl=0;
    unsigned status = 0;

    // OV_MIDH
    ov_read_reg(pTwid, 0x1C, &midh);
    TRACE_DEBUG("MIDH = 0x%X\n\r", midh);

    // OV_MIDL
    ov_read_reg(pTwid, 0x1D, &midl);
    TRACE_DEBUG("MIDL = 0x%X\n\r", midl);

    if(( midh == 0x7F) && (midl == 0xA2)) {
        status = 1;
    }
    return(status);
}
//-----------------------------------------------------------------------------
/// ov_TestWrite
/// \param pTwid TWI interface
/// \return 1 if  the write is correct; 0 otherwise
//-----------------------------------------------------------------------------
static unsigned char ov_TestWrite(Twid *pTwid)
{
    unsigned char value=0;
    unsigned char oldvalue=0;

    // OV_BLUE
    ov_read_reg(pTwid, 0x01, &oldvalue);
    ov_write_reg(pTwid, 0x01, 0xAD);
    ov_read_reg(pTwid, 0x01, &value);
    if( value != 0xAD ) {
        return(0);
    }
    // return old value
    ov_write_reg(pTwid, 0x01, oldvalue);
    ov_read_reg(pTwid, 0x01, &value);
    if( value != oldvalue ) {
        return(0);
    }
    return(1);
}

//-----------------------------------------------------------------------------
//         Global Functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/// Read a value from a register in an OV9650 sensor device.
/// \param pTwid TWI interface
/// \param reg Register to be read
/// \param pData Data read
/// \return 0 if no error, otherwize TWID_ERROR_BUSY
//-----------------------------------------------------------------------------
unsigned char ov_read_reg(Twid *pTwid, unsigned char reg, unsigned char *pData)
{
    unsigned char status;

    status = TWID_Write( pTwid, OV_CAPTOR_ADDRESS, 0, 0, &reg, 1, 0);
    status |= TWID_Read( pTwid, OV_CAPTOR_ADDRESS, 0, 0, pData, 1, 0);
    //status = TWID_Read(pTwid, OV_CAPTOR_ADDRESS, reg, 1, pData, 1, 0);
    if( status != 0 ) {
        TRACE_ERROR("ov_read_reg pb");
    }
    return status;
}

//-----------------------------------------------------------------------------
/// Write a value to a register in an OV9650 sensor device.
/// \param pTwid TWI interface
/// \param reg Register to be write
/// \param val Value to be writte
/// \return 0 if no error, otherwize TWID_ERROR_BUSY
//-----------------------------------------------------------------------------
unsigned char ov_write_reg(Twid *pTwid, unsigned char reg, unsigned char val)
{
    unsigned char status;

    status = TWID_Write(pTwid, OV_CAPTOR_ADDRESS, reg, 1, &val, 1, 0);
    if( status != 0 ) {
        TRACE_ERROR("ov_write_reg pb");
    }

    return status;
}

//-----------------------------------------------------------------------------
/// Initialize a list of OV registers.
/// The list of registers is terminated by the pair of values
/// { OV_REG_TERM, OV_VAL_TERM }.
/// Returns zero if successful, or non-zero otherwise.
/// \param pTwid TWI interface
/// \param pReglist Register list to be written
/// \return 0 if no error, otherwize TWID_ERROR_BUSY
//-----------------------------------------------------------------------------
int ov_write_regs(Twid *pTwid, const struct ov_reg* pReglist)
{
    int err;
    int size=0;
    const struct ov_reg *pNext = pReglist;
    unsigned int i=0;

    TRACE_DEBUG("ov_write_regs:");
    while (!((pNext->reg == OV_REG_TERM) && (pNext->val == OV_VAL_TERM))) {
        err = ov_write_reg(pTwid, pNext->reg, pNext->val);
        TRACE_DEBUG_WP("+(%d) ", size);
        size++;

        //delay(1);
        for(i=0; i<6000; i++ ) {
            *(unsigned int*)0x20400000 = 0;
        }

        if (err == TWID_ERROR_BUSY){
            TRACE_ERROR("ov_write_regs: TWI ERROR\n\r");
            return err;
        }
        pNext++;
    }
    TRACE_DEBUG_WP("\n\r");
    return 0;
}

//-----------------------------------------------------------------------------
/// Dump all register
/// \param pTwid TWI interface
/// \param ovType Sensor type
//-----------------------------------------------------------------------------
void ov_DumpRegisters(Twid *pTwid, unsigned char ovType)
{
    int i;
    unsigned char value;
    unsigned char regNum;

    switch(ovType){

        case BOARD_OV9655:
            regNum = 0xDA;
        break;

        case BOARD_OV2640:
            regNum = 0x5C;
        break;

        default:
            printf("Omnivision type %d not supported. \r\n", ovType);
            return ;
        break;
    }
    TRACE_INFO_WP("Dump all camera register\n\r");
    for(i = 0; i <= regNum; i++) {
        value = 0;
        ov_read_reg(pTwid, i, &value);
        TRACE_INFO_WP("[0x%02x]=0x%02x ", i, value);
        if( ((i+1)%5) == 0 ) {
            TRACE_INFO_WP("\n\r");
        }        
    }
    TRACE_INFO_WP("\n\r");
}

//-----------------------------------------------------------------------------
/// Sequence For correct operation of the sensor
/// \param pTwid TWI interface
/// \param pCtrl1 Ctrl1 signal
/// \param ovType Sensor type
/// \return 1 if initialization ok, otherwise 0
//-----------------------------------------------------------------------------
unsigned char ov_init(Twid *pTwid, const Pin *pCtrl1, unsigned char ovType)
{
    unsigned short id=0;
    unsigned short bdId;

    switch(ovType){

        case BOARD_OV9655:
            bdId = 0x96;
        break;

        case BOARD_OV2640:
            bdId = 0x26;
            ov_reset(pCtrl1);
        break;

        default:
            printf("Omnivision type %d not supported. \r\n", ovType);
            return 0;
        break;
    }
    
    id = ov_id(pTwid);
    if( (id>>8) == bdId ) {
        TRACE_DEBUG("ID and PID OK\n\r");
        if( ov_Manufacturer(pTwid) == 1 ) {
            TRACE_DEBUG("Manufacturer OK\n\r");
            if( ov_TestWrite(pTwid) == 1 ) {
                return 1;
            }
            else {
                TRACE_ERROR("Problem captor: bad write\n\r");
            }
        }
        else {
            TRACE_ERROR("Problem captor: bad Manufacturer\n\r");
        }
    }
    else {
        TRACE_ERROR("Problem captor: bad PID\n\r");
    }
    TRACE_INFO("Problem: captor not responding\n\r");
    return 0;
}

//-----------------------------------------------------------------------------
/// Power control using ctrl2 signal
/// \param pCtrl2 PIO interface
/// \param power on, off
//-----------------------------------------------------------------------------
void ov_pwd(const Pin *pCtrl2, unsigned char power)
{
  volatile unsigned int i;

  if(pCtrl2->id == 0)
      return;

  if(power == OV_CTRL2_POWER_OFF)
      pCtrl2->pio->PIO_CODR = pCtrl2->mask;
  else if (power == OV_CTRL2_POWER_ON)
      pCtrl2->pio->PIO_SODR = pCtrl2->mask;
}

