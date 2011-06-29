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

#ifndef KBMATRIX_H
#define KBMATRIX_H

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include <pio/pio.h>

//-----------------------------------------------------------------------------
//         Definitions
//-----------------------------------------------------------------------------

/// Size of circular key buffer.
#define KBMATRIX_BUFFER_SIZE        10

/// Maximum number of keys that can be handled by the driver.
#define KBMATRIX_MAX_NUMKEYS        40

/// Number of samples that are necessary to debounce a keypress.
#define KBMATRIX_NUM_SAMPLES        10

//-----------------------------------------------------------------------------
//         Types
//-----------------------------------------------------------------------------

/// Key event callback.
typedef void (*KeyEventCallback)(unsigned int key, unsigned char pressed);

/// Key mapping structure, indicating the state of each key in keyboard matrix.
typedef struct _KeyState {

    unsigned char pState[KBMATRIX_MAX_NUMKEYS / 8];

} KeyState;

/// Keyboard matrix driver structure. Holds information about the row & column
/// pins used to create the matrix and stores the internal debouncing status.
typedef struct _KbMatrix {

    /// List of keyboard matrix row pins.
    const Pin *pRows;
    /// Number of rows in matrix.
    unsigned char numRows;
    /// List of keyboard matrix column pins.
    const Pin *pCols;
    /// Number of columns in matrix.
    unsigned char numCols;

    /// Current debounced key state mapping.
    KeyState currentKeyState;
    /// Debouncing samples.
    KeyState sampledKeyStates[KBMATRIX_NUM_SAMPLES];
    /// Current debouncing sample.
    unsigned char sample;

    /// Key pressed/released callback.
    KeyEventCallback callback;

} KbMatrix;

//------------------------------------------------------------------------------
//         Global functions
//------------------------------------------------------------------------------

extern void KBMATRIX_Initialize(
    KbMatrix * pKbMatrix,
    const Pin * pRows,
    unsigned char numRows,
    const Pin * pCols,
    unsigned char numCols,
    KeyEventCallback callback);

extern unsigned char KBMATRIX_Scan(KbMatrix *pKbMatrix);

#endif //#ifndef KBMATRIX_H

