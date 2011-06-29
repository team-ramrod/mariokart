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
/// Interface for configuration the Omnivision captor.
/// 
/// !!!Usage
/// 
/// -# Initialize captor
/// -# Write Omnivision configuration
//------------------------------------------------------------------------------


#ifndef OMNIVISION_H
#define OMNIVISION_H

/// define a structure for monivision register initialization values
struct ov_reg
{
    /// Register to be written
    unsigned char reg;
    /// Value to be written in the register
    unsigned char val;
};

/// Captor capture size
struct capture_size {
    unsigned long width;
    unsigned long height;
};

/// Omnivision sensor type
#define BOARD_OV9655            0
#define BOARD_OV2640            1

/// Omnivision power control
#define OV_CTRL2_POWER_OFF      0
#define OV_CTRL2_POWER_ON       1

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
extern unsigned char ov_init(Twid *pTwid, const Pin *pCtrl1, unsigned char ovType);
extern void ov_DumpRegisters(Twid *pTwid, unsigned char ovType);
extern int ov_write_regs(Twid *pTwid, const struct ov_reg* pReglist);
extern unsigned char ov_read_reg(Twid *pTwid, unsigned char reg, unsigned char *pData);
extern unsigned char ov_write_reg(Twid *pTwid, unsigned char reg, unsigned char val);
extern void ov_configure(Twid *pTwid, unsigned int width, unsigned int heigth);
extern void ov_pwd(const Pin *pCtrl2, unsigned char power);

#endif

