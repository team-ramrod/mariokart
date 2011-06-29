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

#include "s7lekkbm.h"

//------------------------------------------------------------------------------
//         Global variables
//------------------------------------------------------------------------------

/// Keyboard matrix natural key mapping.
const unsigned char gpKeyboardMatrix[S7LEKKBM_NUMKEYS] = {

    S7LEKKBM_SQUAREROOT,
    S7LEKKBM_PERCENTAGE,
    S7LEKKBM_SIGN,
    S7LEKKBM_INVERSE,
    S7LEKKBM_X_POWER_Y,
    S7LEKKBM_MODE,
    S7LEKKBM_2NDF,
    '7',
    '8',
    '9',
    S7LEKKBM_DIVIDE,
    S7LEKKBM_EXP,
    S7LEKKBM_HEXDECBIN,
    S7LEKKBM_2NDF_LOCK,
    '4',
    '5',
    '6',
    S7LEKKBM_MULTIPLY,
    S7LEKKBM_LOG,
    S7LEKKBM_UPARROW,
    S7LEKKBM_ESCAPE,
    '1',
    '2',
    '3',
    S7LEKKBM_MINUS,
    S7LEKKBM_LEFTARROW,
    S7LEKKBM_OK,
    S7LEKKBM_RIGHTARROW,
    '0',
    S7LEKKBM_DOT,
    S7LEKKBM_EQUAL,
    S7LEKKBM_PLUS,
    S7LEKKBM_LN,
    S7LEKKBM_DOWNARROW,
    S7LEKKBM_DELETE
};

/// Keyboard matrix alternative key mapping (2ndF key pressed).
const unsigned char gpKeyboardMatrixAlt[S7LEKKBM_NUMKEYS] = {

    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    S7LEKKBM_2NDF,
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    S7LEKKBM_2NDF_LOCK,
    'M',
    'N', 
    'O',
    'P',
    'Q',
    S7LEKKBM_PAUSE,
    S7LEKKBM_ESCAPE,
    'R',
    'S',
    'T',
    'U',
    S7LEKKBM_LEFTARROW,
    S7LEKKBM_PLAY,
    S7LEKKBM_RIGHTARROW,
    'V',
    'W',
    'X',
    'Y',
    'Z',
    S7LEKKBM_STOP,
    S7LEKKBM_DELETE
};

