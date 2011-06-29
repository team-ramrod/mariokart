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
/// Interface for configuration the Chrontel TV Encoder.
///
/// !!!Usage
///
/// -# Configure pins
/// -# Configure clock
/// -# Initialize TV Encoder
/// -# Reset
/// -# Enable interrupt if needed
/// -# Enable
//------------------------------------------------------------------------------

#ifndef CH7024_H
#define CH7024_H

//------------------------------------------------------------------------------
//         Types
//------------------------------------------------------------------------------
/// define a structure for ch7024 register initialization values
struct ch7024_reg
{
    /// Register to be written
    unsigned char reg;
    /// Value to be written in the register
    unsigned char val;
};

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
extern unsigned char ch7024_read_reg(Twid *pTwid, unsigned char reg, unsigned char *pData);
extern unsigned char ch7024_write_reg(Twid *pTwid, unsigned char reg, unsigned char val);
extern unsigned char ch7024_init(Twid *pTwid);
extern void ch7024_configure(Twid *pTwid);
extern void ch7024_DumpRegisters(Twid *pTwid);
extern void ch7024_reset(Twid *pTwid);

#endif //#ifndef CH7024_H

