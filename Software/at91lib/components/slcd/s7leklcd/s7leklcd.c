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
//         Headers
//------------------------------------------------------------------------------

#include "s7leklcd.h"
#include <board.h>
#include <utility/assert.h>

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------

/// List of the 26 SLCD upper chars ( A ~ Z )
static const unsigned short pLcdUpperChars[26] = {
    S7LEKLCD_A, S7LEKLCD_B, S7LEKLCD_C, S7LEKLCD_D,
    S7LEKLCD_E, S7LEKLCD_F, S7LEKLCD_G, S7LEKLCD_H,
    S7LEKLCD_I, S7LEKLCD_J, S7LEKLCD_K, S7LEKLCD_L,
    S7LEKLCD_M, S7LEKLCD_N, S7LEKLCD_O, S7LEKLCD_P,
    S7LEKLCD_Q, S7LEKLCD_R, S7LEKLCD_S, S7LEKLCD_T,
    S7LEKLCD_U, S7LEKLCD_V, S7LEKLCD_W, S7LEKLCD_X,
    S7LEKLCD_Y, S7LEKLCD_Z 
};

/// List of the 26 SLCD lower chars ( a ~ z )
static const unsigned short pLcdLowerChars[26] = {
    S7LEKLCD_a, S7LEKLCD_b, S7LEKLCD_c, S7LEKLCD_d,
    S7LEKLCD_e, S7LEKLCD_f, S7LEKLCD_g, S7LEKLCD_h,
    S7LEKLCD_i, S7LEKLCD_j, S7LEKLCD_k, S7LEKLCD_l,
    S7LEKLCD_m, S7LEKLCD_n, S7LEKLCD_o, S7LEKLCD_p,
    S7LEKLCD_q, S7LEKLCD_r, S7LEKLCD_s, S7LEKLCD_t,
    S7LEKLCD_u, S7LEKLCD_v, S7LEKLCD_w, S7LEKLCD_x,
    S7LEKLCD_y, S7LEKLCD_z 
};

/// List of the 10 SLCD numbers ( 0 ~ 9 )
static const unsigned short pLcdNumbers[10] = {
    S7LEKLCD_0, S7LEKLCD_1, S7LEKLCD_2, S7LEKLCD_3,
    S7LEKLCD_4, S7LEKLCD_5, S7LEKLCD_6, S7LEKLCD_7,
    S7LEKLCD_8, S7LEKLCD_9
};

//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Returns the LCD character code to display given an input character.
/// \param c  Character to display.
/// \param dot  Indicates if the character should be dotted or not.
//------------------------------------------------------------------------------
static unsigned short GetSLcdChar(unsigned char c, unsigned char dot)
{
    unsigned short symbol = 0;

    // Add dot if needed
    if (dot) {

        symbol = S7LEKLCD_DOT;
    }

    // Find corresponding symbol for character
    // Space
    if (c == ' ') {
    
        symbol |= S7LEKLCD_NONE;
    }
    // Single dot
    else if (c == '.') {
    
        symbol |= S7LEKLCD_NONE | S7LEKLCD_DOT;
    }
    // Number
    else if ((c >= '0') && (c <= '9')) {
    
        symbol |= pLcdNumbers[c - '0'];
    }
    // Lower-case letter
    else if ((c >= 'a') && (c <= 'z')) {
    
        symbol |= pLcdLowerChars[c - 'a'];
    }
    // Upper case letter
    else if ((c >= 'A') && (c <= 'Z')) {
    
        symbol |= pLcdUpperChars[c - 'A'];
    }
    // Special characters
    else {
        switch (c) {
            case '+': symbol |= S7LEKLCD_PLUS; break;
            case '-': symbol |= S7LEKLCD_MINUS; break;
            case '=': symbol |= S7LEKLCD_EQUAL; break;
            case '>': symbol |= S7LEKLCD_LARGE; break;
            case '<': symbol |= S7LEKLCD_LESS; break;
            case '\\': symbol |= S7LEKLCD_SLASH; break;
            case '/': symbol |= S7LEKLCD_BACKSLASH; break;
            case '$': symbol |= S7LEKLCD_DOLLAR; break;
            case '|': symbol |= S7LEKLCD_OR; break;
            case ',': symbol |= S7LEKLCD_COMMA; break;
            case '\'': symbol |= S7LEKLCD_INVCOMMA1; break;
            case '"': symbol |= S7LEKLCD_INVCOMMA2; break;
            case '_': symbol |= D; break;
            default: symbol = S7LEKLCD_NONE;
        }
    }

    return symbol;
}

//------------------------------------------------------------------------------
//         Global functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Switches a symbol of the LCD on or off.
/// \param symbol  Symbol Index in the LCD buffer matrix.
/// \param set  If 1, the symbol is turned on; otherwise it is turned off.
//------------------------------------------------------------------------------
void S7LEKLCD_Symbol(unsigned short symbol, unsigned char set)
{
    unsigned int common = symbol / 40;
    unsigned int reg = (symbol % 40) / 32;
    unsigned int bit = (symbol % 40) % 32;
    
    if (set) {

        AT91C_BASE_SLCDC->SLCDC_MEM[common * 2 + reg] |= 1 << bit;
    }
    else {

        AT91C_BASE_SLCDC->SLCDC_MEM[common * 2 + reg] &= ~(1 << bit);
    }
}

//------------------------------------------------------------------------------
/// Switches a pixel of the matrix on or off.
/// \param x  Horizontal pixel coordinate.
/// \param y  Vertical pixel coordinate.
/// \param set  If true, the pixel is switched on; otherwise it is switched off.
//------------------------------------------------------------------------------
void S7LEKLCD_Pixel(unsigned char x, unsigned char y, unsigned char set)
{
    SANITY_CHECK(x < 12);
    SANITY_CHECK(y < 10);

    S7LEKLCD_Symbol((x + 1) + (40 * (9 - y)), set);
}

//------------------------------------------------------------------------------
/// Displays a character at the given position on the LCD.
/// \param c  Character definition.
/// \param index  Position of the character on the LCD ([0...11]).
//------------------------------------------------------------------------------
void S7LEKLCD_Char(unsigned short c, unsigned char index)
{
    SANITY_CHECK(index < 12);

    S7LEKLCD_Symbol((40 * 2) + 37 - index * 2 , (c & A) != 0);
    S7LEKLCD_Symbol((40 * 4) + 37 - index * 2 , (c & B) != 0);
    S7LEKLCD_Symbol((40 * 6) + 37 - index * 2 , (c & C) != 0);
    S7LEKLCD_Symbol((40 * 8) + 38 - index * 2 , (c & D) != 0);
    S7LEKLCD_Symbol((40 * 6) + 38 - index * 2 , (c & E) != 0);
    S7LEKLCD_Symbol((40 * 4) + 38 - index * 2 , (c & F) != 0);
    S7LEKLCD_Symbol((40 * 5) + 38 - index * 2 , (c & G) != 0);
    S7LEKLCD_Symbol((40 * 5) + 37 - index * 2 , (c & H) != 0);
    S7LEKLCD_Symbol((40 * 3) + 38 - index * 2 , (c & I) != 0);
    S7LEKLCD_Symbol((40 * 2) + 38 - index * 2 , (c & J) != 0);
    S7LEKLCD_Symbol((40 * 3) + 37 - index * 2 , (c & K) != 0);
    S7LEKLCD_Symbol((40 * 7) + 38 - index * 2 , (c & L) != 0);
    S7LEKLCD_Symbol((40 * 8) + 37 - index * 2 , (c & M) != 0);
    S7LEKLCD_Symbol((40 * 7) + 37 - index * 2 , (c & N) != 0);
    S7LEKLCD_Symbol((40 * 9) + 37 - index * 2 , (c & P) != 0);
}

//------------------------------------------------------------------------------
/// Displays a clock number at the given position.
/// \param c  Number definition.
/// \param index  Position of the character to be displayed ([0..3]).
//------------------------------------------------------------------------------
void S7LEKLCD_ClockNumber(unsigned short c, unsigned char index)
{
    SANITY_CHECK(index < 4);

    S7LEKLCD_Symbol((40 * 0) + 30 - index * 4 , (c & A) != 0);
    S7LEKLCD_Symbol((40 * 0) + 29 - index * 4 , (c & B) != 0);
    S7LEKLCD_Symbol((40 * 0) + 27 - index * 4 , (c & C) != 0);
    S7LEKLCD_Symbol((40 * 1) + 27 - index * 4 , (c & D) != 0);
    S7LEKLCD_Symbol((40 * 1) + 28 - index * 4 , (c & E) != 0);
    S7LEKLCD_Symbol((40 * 1) + 29 - index * 4 , (c & F) != 0);
    S7LEKLCD_Symbol((40 * 0) + 28 - index * 4 , (c & G) != 0);
}

//------------------------------------------------------------------------------
/// Displays a string on the SLCD starting at the specified character index.
/// \param pString  String to display.
/// \param index  Starting index of string.
//------------------------------------------------------------------------------
void S7LEKLCD_PutString(const char *pString, unsigned char index)
{
    unsigned char i;
    unsigned char j;
    unsigned char dot;

    // Clear characters before index
    for (i=0; i < index; i++) {

        S7LEKLCD_Char(S7LEKLCD_NONE, i);
    }

    // Display string
    j = 0;
    dot = 0;
    while ((i < S7LEKLCD_MAX_CHARS) && (pString[j] != 0)) {

        // Check if next character is a dot
        if (pString[j+1] == '.') {

            dot = 1;
        }

        // Skip dots
        if (pString[j] == '.') {

            j++;
        }
        // Display character
        else {

            S7LEKLCD_Char(GetSLcdChar(pString[j], dot), i);
            dot = 0;
            i++;
            j++;
        }
    }

    // Clear characters at end of string
    for (; i < S7LEKLCD_MAX_CHARS; i++) {

        S7LEKLCD_Char(S7LEKLCD_NONE, i);
    }
}

