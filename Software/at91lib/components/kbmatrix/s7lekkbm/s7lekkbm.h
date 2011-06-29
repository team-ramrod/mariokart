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

#ifndef S7LEKKBM_H
#define S7LEKKBM_H

//------------------------------------------------------------------------------
//         Global definitions
//------------------------------------------------------------------------------

/// Number of keys in keyboard matrix.
#define S7LEKKBM_NUMKEYS        35

/// Square root key.
#define S7LEKKBM_SQUAREROOT     128
/// Percentage key.
#define S7LEKKBM_PERCENTAGE     129
/// Plus/minus sign key.
#define S7LEKKBM_SIGN           130
/// Inverse (1/x) key.
#define S7LEKKBM_INVERSE        131
/// Power key (x^y).
#define S7LEKKBM_X_POWER_Y      132
/// Mode key.
#define S7LEKKBM_MODE           133
/// 2nd function key.
#define S7LEKKBM_2NDF           134
/// Divide key.
#define S7LEKKBM_DIVIDE         135
/// Exponential key.
#define S7LEKKBM_EXP            136
/// Hex/dec/bin key.
#define S7LEKKBM_HEXDECBIN      137
/// 2nd function lock key.
#define S7LEKKBM_2NDF_LOCK      138
/// Multiply key.
#define S7LEKKBM_MULTIPLY       139
/// Logarithm key.
#define S7LEKKBM_LOG            140
/// Up arrow key.
#define S7LEKKBM_UPARROW        141
/// Pause key.
#define S7LEKKBM_PAUSE          142
/// Escape key.
#define S7LEKKBM_ESCAPE         143
/// Minus key.
#define S7LEKKBM_MINUS          144
/// Left arrow key.
#define S7LEKKBM_LEFTARROW      145
/// Ok key.
#define S7LEKKBM_OK             146
/// Play key.
#define S7LEKKBM_PLAY           147
/// Right arrow key.
#define S7LEKKBM_RIGHTARROW     148
/// Dot key.
#define S7LEKKBM_DOT            149
/// Equal key.
#define S7LEKKBM_EQUAL          150
/// Plus key.
#define S7LEKKBM_PLUS           151
/// Natural logarithm key.
#define S7LEKKBM_LN             152
/// Down arrow key.
#define S7LEKKBM_DOWNARROW      153
/// Stop key.
#define S7LEKKBM_STOP           154
/// Delete key.
#define S7LEKKBM_DELETE         155

//------------------------------------------------------------------------------
//         Global macros
//------------------------------------------------------------------------------

/// Returns 1 if the key is a special key; otherwise returns 0.
#define S7LEKKBM_SPECIALKEY(key)    ((key >= 128) ? 1 : 0)

//------------------------------------------------------------------------------
//         Global variables
//------------------------------------------------------------------------------

extern const unsigned char gpKeyboardMatrix[S7LEKKBM_NUMKEYS];

extern const unsigned char gpKeyboardMatrixAlt[S7LEKKBM_NUMKEYS];

#endif //#ifndef S7LEKKBM_H

