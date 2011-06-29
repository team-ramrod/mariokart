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
/// Interface for displaying on segment LCD of AT91SAM7L-STK board.
/// 
/// !!!Usage
/// 
/// -# call corresponding function to display pixel, char and string. 
//------------------------------------------------------------------------------

#ifndef S7LSTKLCD_H
#define S7LSTKLCD_H

//-----------------------------------------------------------------------------
//         Defines
//-----------------------------------------------------------------------------

/// Number of segments in SLCD
#define S7LSTKLCD_NUM_SEGMENTS      40
/// Number of commons in SLCD
#define S7LSTKLCD_NUM_COMMONS       10

/// SLCD width in pixels.
#define S7LSTKLCD_WIDTH             40
/// SLCD height in pixels.
#define S7LSTKLCD_HEIGHT            10

//-----------------------------------------------------------------------------
//         Global Functions
//-----------------------------------------------------------------------------

extern void S7LSTKLCD_Pixel(
    unsigned char x,
    unsigned char y,
    unsigned char set);

extern void S7LSTKLCD_Char(
    signed int x,
    signed int y,
    unsigned char c);

extern void S7LSTKLCD_String(signed int x, signed int y, const char *pString);

extern void S7LSTKLCD_GetStringSize(
    const char *pString,
    signed int *pWidth,
    signed int *pHeight);

extern void S7LSTKLCD_PutString(const char *pString);

#endif

