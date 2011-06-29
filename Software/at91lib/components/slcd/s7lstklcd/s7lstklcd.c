/* ---------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation

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

#include "s7lstklcd.h"
#include "font.h"
#include <board.h>
#include <utility/assert.h>
#include <utility/trace.h>

//-----------------------------------------------------------------------------
//         Global functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/// Switches a pixel on the SLCD on or off.
/// \param x  X-coordinate of pixel.
/// \param y  Y-coordinate of pixel.
/// \param set  If 1, pixel is displayed; otherwise it is hidden.
//-----------------------------------------------------------------------------
void S7LSTKLCD_Pixel(unsigned char x, unsigned char y, unsigned char set)
{
    unsigned int symbol = y * S7LSTKLCD_WIDTH + x;
    unsigned int common  = symbol / S7LSTKLCD_NUM_SEGMENTS;
    unsigned int segment = symbol % S7LSTKLCD_NUM_SEGMENTS;
    unsigned int reg = segment / 32;
    unsigned int bit = segment % 32;

    SANITY_CHECK(x < S7LSTKLCD_WIDTH);
    SANITY_CHECK(y < S7LSTKLCD_HEIGHT);

    if (set) {

        AT91C_BASE_SLCDC->SLCDC_MEM[common * 2 + reg] |=  (1 << bit);
    }
    else {

        AT91C_BASE_SLCDC->SLCDC_MEM[common * 2 + reg] &= ~(1 << bit);
    }
}

//-----------------------------------------------------------------------------
/// Displays a character at the given position on the SLCD. The character is
/// clipped according to the SLCD dimensions.
/// Note that x and y can be negative (upper-left part of character will be
/// clipped).
/// \param x  X-coordinate of upper-left corner of character.
/// \param y  Y-coordinate of upper-left corner of character.
/// \param c  Character to display.
//-----------------------------------------------------------------------------
void S7LSTKLCD_Char(signed int x, signed int y, unsigned char c)
{
    const unsigned char *pChar;
    signed int i, j;

    SANITY_CHECK(c >= gFont.firstCharacter);
    SANITY_CHECK(c <= gFont.lastCharacter);

    // Optimization: return if coordinates are out of bounds
    if ((x > S7LSTKLCD_WIDTH) || ((x+gFont.width) < 0)
        || (y > S7LSTKLCD_HEIGHT) || ((y+gFont.height) < 0)) {

        return;
    }

    // Get pointer to character in font data
    pChar = &(gFont.pData[(c - gFont.firstCharacter) * gFont.height]);

    // Display character at requested location
    for (j=0; j < gFont.height; j++) {
        for (i=0; i < gFont.width; i++) {

            if (((x+i) >= 0) && ((x+i) < S7LSTKLCD_WIDTH)
                && ((y+i >= 0)) && ((y+i) < S7LSTKLCD_HEIGHT)) {

                S7LSTKLCD_Pixel(x+i, y+j, (pChar[j] & (1 << (FONT_CHAR_MAX_WIDTH-i-1))));
            }
        }
    }
}

//-----------------------------------------------------------------------------
/// Displays a string on the SLCD given the top-left corner coordinates. String
/// is clipped according to the SLCD dimensions.
/// X and Y can be negative (top-left clipping).
/// \param x  X-coordinate of top-left corner.
/// \param y  Y-coordinate of top-left corner.
/// \param pString  String to display.
//-----------------------------------------------------------------------------
void S7LSTKLCD_String(signed int x, signed int y, const char *pString)
{
    signed int j;
    while (*pString != 0) {

        // Display character
        S7LSTKLCD_Char(x, y, *pString);
        x += gFont.width + 1;
        pString++;

        // Vertical blank line
        if ((*pString != 0) && ((x-1) < S7LSTKLCD_WIDTH) && ((x-1) > 0)) {

            for (j=0; j < gFont.height; j++) {

                if (((j+y) >= 0) && ((j+y) < S7LSTKLCD_HEIGHT)) {

                    S7LSTKLCD_Pixel(x-1, y+j, 0);
                }
            }
        }
    }
}

//-----------------------------------------------------------------------------
/// Returns the height and width in pixels of the given string.
/// \param pString  String to examinate.
/// \param pWidth  Width of string in pixels.
/// \param pHeight  Height of string in pixels.
//-----------------------------------------------------------------------------
void S7LSTKLCD_GetStringSize(
    const char *pString,
    signed int *pWidth,
    signed int *pHeight)
{
    unsigned int size = 0;

    // Get string size
    while (*pString != 0) {

        size++;
        pString++;
    }

    // Return size in pixel
    if (pWidth) {

        *pWidth = size * (gFont.width + 1) - 1;
    }
    if (pHeight) {

        *pHeight = gFont.height;
    }
}

//-----------------------------------------------------------------------------
/// Displays the given string on the SLCD, centered along the X and Y axis
/// (this may result in the string being clipped).
/// \param pString  String to display.
//-----------------------------------------------------------------------------
void S7LSTKLCD_PutString(const char *pString)
{
    signed int width, height;
    SANITY_CHECK(pString);

    S7LSTKLCD_GetStringSize(pString, &width, &height);
    S7LSTKLCD_String((S7LSTKLCD_WIDTH - width) / 2, (S7LSTKLCD_HEIGHT - height) / 2, pString);
}

