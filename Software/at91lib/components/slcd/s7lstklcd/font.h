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

#ifndef FONT_H
#define FONT_H

//-----------------------------------------------------------------------------
//         Definitions
//-----------------------------------------------------------------------------

/// Maximum character width in pixels.
#define FONT_CHAR_MAX_WIDTH     8

//-----------------------------------------------------------------------------
//         Types
//-----------------------------------------------------------------------------

/// Font information structure.
typedef struct _Font {

    // Font width in pixels.
    unsigned char width;
    // Font height in pixels.
    unsigned char height;
    // First character in font data.
    unsigned char firstCharacter;
    // Last character in font data.
    unsigned char lastCharacter;
    // Font data, containing (lastCharacter - firstCharacter) characters,
    // (height) bytes per character, each byte corresponding
    // to one line of the character. Bits are ordered as follow:
    // MSB ------------------------------------ LSB
    // Leftmost bit - ... - Rightmost bit - Padding
    const unsigned char *pData;

} Font;

//-----------------------------------------------------------------------------
//         Global variables
//-----------------------------------------------------------------------------

extern const Font gFont;

#endif //#ifndef FONT_H

