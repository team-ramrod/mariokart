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
/// Interface for displaying on segment LCD of AT91SAM7L-EK board..
/// 
/// !!!Usage
/// 
/// -# call corresponding function to display symbol, pixel of the matrix, char, 
/// clock number and string.
//------------------------------------------------------------------------------

#ifndef _S7LEKLCD_H
#define _S7LEKLCD_H

//------------------------------------------------------------------------------
//         Global Constants
//------------------------------------------------------------------------------

/// Maximum number of characters that can be displayed on the LCD.
#define S7LEKLCD_MAX_CHARS          12

//------------------------------------------------------------------------------
/// \page "SAM7L-EK SLCD Segments"
/// This page lists the segment constants used to describe letters on the
/// SAM7L-EK segment LCD display.
/// 
/// !Constants
/// - A
/// - B
/// - C
/// - D
/// - E
/// - F
/// - G
/// - H
/// - I
/// - J
/// - K
/// - L
/// - M
/// - N
/// - P

/// A segment definition.
#define A           (1 << 0)
/// B segment definition.
#define B           (1 << 1)
/// C segment definition.
#define C           (1 << 2)
/// D segment definition.
#define D           (1 << 3)
/// E segment definition.
#define E           (1 << 4)
/// F segment definition.
#define F           (1 << 5)
/// G segment definition.
#define G           (1 << 6)
/// H segment definition.
#define H           (1 << 7)
/// I segment definition.
#define I           (1 << 8)
/// J segment definition.
#define J           (1 << 9)
/// K segment definition.
#define K           (1 << 10)
/// L segment definition.
#define L           (1 << 11)
/// M segment definition.
#define M           (1 << 12)
/// N segment definition.
#define N           (1 << 13)
/// P segment definition.
#define P           (1 << 14)
//------------------------------------------------------------------------------

/// Enables all the segments of one LCD slot.
#define S7LEKLCD_ALL    (A | B | C | D | E | F | G | H | I |J | K | L | M | N)
/// Disables all the segments of one LCD slot.
#define S7LEKLCD_NONE   0
/// Dot definition.
#define S7LEKLCD_DOT    P

// Upper-case letters.
#define S7LEKLCD_A      (A | B | C | E | F | G | H)
#define S7LEKLCD_B      (A | B | C | D | H | J | M)
#define S7LEKLCD_C      (A | D | E | F)
#define S7LEKLCD_D      (A | B | C | D | J | M)
#define S7LEKLCD_E      (A | D | E | F | G | H)
#define S7LEKLCD_F      (A | E | F | G | H)
#define S7LEKLCD_G      (A | C | D | E | F | H)
#define S7LEKLCD_H      (B | C | E | F | G | H)
#define S7LEKLCD_I      (A | J | M | D)
#define S7LEKLCD_J      (B | C | D | E)
#define S7LEKLCD_K      (E | F | G | K | N)
#define S7LEKLCD_L      (D | E | F )    
#define S7LEKLCD_M      (B | C | E | F | I | K )
#define S7LEKLCD_N      (B | C | E | F | I | N)
#define S7LEKLCD_O      (A | B | C | D | E | F)
#define S7LEKLCD_P      (A | B | E | F | G | H)
#define S7LEKLCD_Q      (A | B | C | D | E | F | N)    
#define S7LEKLCD_R      (A | B | E | F | G | H | N)
#define S7LEKLCD_S      (A | C | D | F | G | H)
#define S7LEKLCD_T      (A | J | M )
#define S7LEKLCD_U      (B | C | D | E | F)            
#define S7LEKLCD_V      (E | F | K | L)          
#define S7LEKLCD_W      (B | C | E | F | J | L | N)
#define S7LEKLCD_X      (I | K | L | N)
#define S7LEKLCD_Y      (I | K | M)
#define S7LEKLCD_Z      (A | D | K | L)

// Lower-case letters.
#define S7LEKLCD_a     (D | E | G | M)
#define S7LEKLCD_b     (E | F | G | L)
#define S7LEKLCD_c     (D | E | G )
#define S7LEKLCD_d     (B | C | H | N)
#define S7LEKLCD_e     (D | E | G | L)
#define S7LEKLCD_f     (A | E | F | G)
#define S7LEKLCD_g     (A | B | C | D | H | J)
#define S7LEKLCD_h     (E | F | G | M)
#define S7LEKLCD_i     (M)
#define S7LEKLCD_j     (J | L)
#define S7LEKLCD_k     (J | K | M | N)
#define S7LEKLCD_l     (J | M )
#define S7LEKLCD_m     (C | E | G | H | M)
#define S7LEKLCD_n     (C | E | G | H)
#define S7LEKLCD_o     (C | D | E | G | H)
#define S7LEKLCD_p     (A | E | F | G | K)   
#define S7LEKLCD_q     (A | B | C | F | H | I)
#define S7LEKLCD_r     (J | K | M)
#define S7LEKLCD_s     (D | H | N)      
#define S7LEKLCD_t     (G | H | J | N)
#define S7LEKLCD_u     (C | D | E)
#define S7LEKLCD_v     (E | H | L)
#define S7LEKLCD_w     (C | E | L | N)
#define S7LEKLCD_x     (I | J | L | N)
#define S7LEKLCD_y     (I | K | L)
#define S7LEKLCD_z     (D | G | L)                     

// Numbers.
#define S7LEKLCD_0     (A | B | C | D | E | F)
#define S7LEKLCD_1     (J | M)
#define S7LEKLCD_2     (A | B | D | E | G | H)
#define S7LEKLCD_3     (A | B | C | D | G | H)
#define S7LEKLCD_4     (F | G | H | J | M)
#define S7LEKLCD_5     (A | C | D | F | G | H)
#define S7LEKLCD_6     (A | C | D | E | F | G| H)
#define S7LEKLCD_7     (A | B | C)
#define S7LEKLCD_8     (A | B | C | D | E | F | G | H)
#define S7LEKLCD_9     (A | B | C | D | F | G | H)

// Clock numbers.
#define S7LEKLCD_C0    (A | B | C | D | E | F)
#define S7LEKLCD_C1    (B | C)
#define S7LEKLCD_C2    (A | B | D | E | G )
#define S7LEKLCD_C3    (A | B | C | D | G )
#define S7LEKLCD_C4    (B | C | F | G)
#define S7LEKLCD_C5    (A | C | D | F | G )
#define S7LEKLCD_C6    (A | C | D | E | F | G)
#define S7LEKLCD_C7    (A | B | C)
#define S7LEKLCD_C8    (A | B | C | D | E | F | G )
#define S7LEKLCD_C9    (A | B | C | D | F | G )

// Symbols
#define S7LEKLCD_PLUS       (G | H | J | M)
#define S7LEKLCD_MINUS      (G | H)
#define S7LEKLCD_LARGE      (I | L)
#define S7LEKLCD_LESS       (K | N)
#define S7LEKLCD_SLASH      (K | L)
#define S7LEKLCD_BACKSLASH  (I | M)
#define S7LEKLCD_DOLLAR     (A | C | D | F | G | H | J | M)
#define S7LEKLCD_OR         (J | M)
#define S7LEKLCD_COMMA      L
#define S7LEKLCD_UNDERSCORE D
#define S7LEKLCD_INVCOMMA1  I
#define S7LEKLCD_INVCOMMA2  K
#define S7LEKLCD_EQUAL      (D | G |H)
#define S7LEKLCD_MULTIPLY   (G | H | I | J | K | L | M | N)
#define S7LEKLCD_AT         (A | B | C | D | E | G |M)

/// Symbols definitions
/// Each symbol is defined by the bit offset in the 400 bits matrix
#define S7LEKLCD_ARROW1     (40 * 0 )
#define S7LEKLCD_ARROW2     (40 * 1 )
#define S7LEKLCD_ARROW3     (40 * 2 )
#define S7LEKLCD_Q2         (40 * 3 )
#define S7LEKLCD_Q1         (40 * 4 )
#define S7LEKLCD_Q0         (40 * 5 )
#define S7LEKLCD_Q4         (40 * 6 )
#define S7LEKLCD_Q3         (40 * 7 )
#define S7LEKLCD_KEY        (40 * 8 )
#define S7LEKLCD_SOUND      (40 * 9 )
                        
#define S7LEKLCD_S0         (40 * 1 + 39)
#define S7LEKLCD_S1         (40 * 0 + 39)
#define S7LEKLCD_S2         (40 * 1 + 39)
#define S7LEKLCD_S3         (40 * 2 + 39)
#define S7LEKLCD_S4         (40 * 3 + 39)
#define S7LEKLCD_S5         (40 * 4 + 39)
#define S7LEKLCD_S6         (40 * 5 + 39)
#define S7LEKLCD_S7         (40 * 6 + 39)
#define S7LEKLCD_S8         (40 * 7 + 39)
#define S7LEKLCD_S9         (40 * 8 + 39)
#define S7LEKLCD_S10        (40 * 9 + 39)
#define S7LEKLCD_COLON      (40 * 0 + 38)
#define S7LEKLCD_LINE       (40 * 1 + 38)
#define S7LEKLCD_HEX        (40 * 9 + 38)

#define S7LEKLCD_ATMEL      (40 * 0 + 37)
                        
#define S7LEKLCD_SNOW       (40 * 0 + 36)
#define S7LEKLCD_FIRE       (40 * 1 + 36)
                        
#define S7LEKLCD_BIN        (40 * 9 + 36)
#define S7LEKLCD_DEC        (40 * 9 + 34)
#define S7LEKLCD_AUTO       (40 * 9 + 32)
#define S7LEKLCD_TIME       (40 * 9 + 30)
#define S7LEKLCD_DATE       (40 * 9 + 26)
#define S7LEKLCD_PROG       (40 * 9 + 24)
#define S7LEKLCD_SETUP      (40 * 9 + 20)
#define S7LEKLCD_2NDF       (40 * 9 + 16)
                        
#define S7LEKLCD_1P         (40 * 9 + 37)
#define S7LEKLCD_2P         (40 * 9 + 35)
#define S7LEKLCD_3P         (40 * 9 + 33)
#define S7LEKLCD_4P         (40 * 9 + 31)
#define S7LEKLCD_5P         (40 * 9 + 29)
#define S7LEKLCD_6P         (40 * 9 + 27)
#define S7LEKLCD_7P         (40 * 9 + 25)
#define S7LEKLCD_8P         (40 * 9 + 23)
#define S7LEKLCD_9P         (40 * 9 + 21)
#define S7LEKLCD_10P        (40 * 9 + 19)
#define S7LEKLCD_11P        (40 * 9 + 17)
#define S7LEKLCD_12P        (40 * 9 + 15)
                        
#define S7LEKLCD_V0         (40 * 0 + 35)
#define S7LEKLCD_VOL        (40 * 1 + 35)
#define S7LEKLCD_V1         (40 * 0 + 34)
#define S7LEKLCD_V2         (40 * 1 + 34)
#define S7LEKLCD_V4         (40 * 0 + 33)
#define S7LEKLCD_V3         (40 * 1 + 33)
                        
#define S7LEKLCD_CLOCK      (40 * 0 + 32)
#define S7LEKLCD_TOOL       (40 * 1 + 32)
                        
#define S7LEKLCD_AM         (40 * 0 + 31)
#define S7LEKLCD_PM         (40 * 1 + 31)
                        
#define S7LEKLCD_COL1       (40 * 9 + 28)
#define S7LEKLCD_COL2       (40 * 9 + 22)
#define S7LEKLCD_COL3       (40 * 9 + 18)
#define S7LEKLCD_COL4       (40 * 1 + 30)
                        
#define S7LEKLCD_DMM        (40 * 0 + 13)
#define S7LEKLCD_TMP        (40 * 1 + 13)
#define S7LEKLCD_BARO       (40 * 2 + 13)
#define S7LEKLCD_HZ         (40 * 3 + 13)
#define S7LEKLCD_MHZ        (40 * 4 + 13)
#define S7LEKLCD_INHG       (40 * 5 + 13)
#define S7LEKLCD_KHZ        (40 * 6 + 13)
#define S7LEKLCD_HPA        (40 * 7 + 13)
#define S7LEKLCD_OHM        (40 * 8 + 13)
#define S7LEKLCD_SUN        (40 * 9 + 13)

#define S7LEKLCD_CALC       (40 * 0 + 14)
#define S7LEKLCD_FAHRENHEIT (40 * 1 + 14)
#define S7LEKLCD_CELSIUS    (40 * 2 + 14)
#define S7LEKLCD_PENSENT    (40 * 3 + 14)
#define S7LEKLCD_AMPS       (40 * 4 + 14)
#define S7LEKLCD_VOLTS      (40 * 5 + 14)
#define S7LEKLCD_KWH        (40 * 6 + 14)
#define S7LEKLCD_FINE       (40 * 7 + 14)
#define S7LEKLCD_CLOUD      (40 * 8 + 14)
#define S7LEKLCD_RAIN       (40 * 9 + 14)

//------------------------------------------------------------------------------
//         Global functions
//------------------------------------------------------------------------------

extern void S7LEKLCD_Symbol(unsigned short symbol, unsigned char set);

extern void S7LEKLCD_Pixel(unsigned char x, unsigned char y, unsigned char set);

extern void S7LEKLCD_Char(unsigned short c, unsigned char index);

extern void S7LEKLCD_ClockNumber(unsigned short c, unsigned char index);

extern void S7LEKLCD_PutString(const char *pString, unsigned char index);

#endif //#ifndef _S7LEKLCD_H

