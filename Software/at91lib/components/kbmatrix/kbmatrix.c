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

//-----------------------------------------------------------------------------
//         Headers
//-----------------------------------------------------------------------------

#include "kbmatrix.h"
#include <pio/pio_it.h>
#include <irq/irq.h>
#include <utility/trace.h>
#include <utility/assert.h>

#include <string.h>

//-----------------------------------------------------------------------------
//         Local functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/// Initializes a KeyState instance by setting all keys are released.
/// \param pKeyState  Pointer to a KeyState instance to initialize.
//-----------------------------------------------------------------------------
static void KEYSTATE_Initialize(KeyState *pKeyState)
{
    SANITY_CHECK(pKeyState);

    memset(pKeyState->pState, 0, sizeof(KeyState));
}

//-----------------------------------------------------------------------------
/// Sets the status of a key given its index in the key state.
/// \param pKeyState  Pointer to a KeyState instance.
/// \param key  Key index.
/// \param state  New key state.
//-----------------------------------------------------------------------------
static void KEYSTATE_SetKeyState(
    KeyState *pKeyState,
    unsigned int key,
    unsigned char state)
{
    unsigned int byte = key / 8;
    unsigned int bit = key % 8;

    SANITY_CHECK(pKeyState);
    SANITY_CHECK(key < KBMATRIX_MAX_NUMKEYS);

    if (state) {
    
        pKeyState->pState[byte] |= (1 << bit);
    }
    else {

        pKeyState->pState[byte] &= ~(1 << bit);
    }
}

//-----------------------------------------------------------------------------
/// Returns 1 if the given key is currently pressed; otherwise returns 0.
/// \param pKeyState  Pointer to a KeyState instance.
/// \param key  Key index.
//-----------------------------------------------------------------------------
static unsigned char KEYSTATE_GetKeyState(KeyState *pKeyState, unsigned int key)
{
    unsigned int byte = key / 8;
    unsigned int bit = key % 8;

    SANITY_CHECK(pKeyState);
    SANITY_CHECK(key < KBMATRIX_MAX_NUMKEYS);

    return ((pKeyState->pState[byte] >> bit) & 1);
}

//-----------------------------------------------------------------------------
/// Performs a AND operation between two KeyState instance, storing the result
/// in a third instance.
/// \param pA  Pointer to the first state to AND.
/// \param pB  Pointer to the second state to AND.
/// \param pResult  Pointer to the resulting KeyState.
//-----------------------------------------------------------------------------
static void KEYSTATE_And(KeyState *pA, KeyState *pB, KeyState *pResult)
{
    unsigned int i;

    for (i=0; i < sizeof(KeyState); i++) {

        pResult->pState[i] = pA->pState[i] & pB->pState[i];
    }
}

//-----------------------------------------------------------------------------
/// Performs a OR operation between two KeyState instance, storing the result
/// in a third instance.
/// \param pA  Pointer to the first state to OR.
/// \param pB  Pointer to the second state to OR.
/// \param pResult  Pointer to the resulting KeyState.
//-----------------------------------------------------------------------------
static void KEYSTATE_Or(KeyState *pA, KeyState *pB, KeyState *pResult)
{
    unsigned int i;

    for (i=0; i < sizeof(KeyState); i++) {

        pResult->pState[i] = pA->pState[i] | pB->pState[i];
    }
}

//-----------------------------------------------------------------------------
/// Performs a XOR operation between two KeyState instance, storing the result
/// in a third instance.
/// \param pA  Pointer to the first state to XOR.
/// \param pB  Pointer to the second state to XOR.
/// \param pResult  Pointer to the resulting KeyState.
//-----------------------------------------------------------------------------
static void KEYSTATE_Xor(KeyState *pA, KeyState *pB, KeyState *pResult)
{
    unsigned int i;

    for (i=0; i < sizeof(KeyState); i++) {

        pResult->pState[i] = pA->pState[i] ^ pB->pState[i];
    }
}

//-----------------------------------------------------------------------------
/// Computes the new debounced key state and trigger key events if necessary.
/// The debouncing is done both when the key is pressed and when it is released.
/// Returns 1 if changes have been detected; otherwise returns 0.
/// \param pKbMatrix  Pointer to a KbMatrix instance.
//-----------------------------------------------------------------------------
unsigned char Debounce(KbMatrix *pKbMatrix)
{
    KeyState pressed;
    KeyState released;
    KeyState new;
    KeyState changed;
    unsigned int i;
    unsigned char event = 0;

    SANITY_CHECK(pKbMatrix);

    // Debounce pressed keys
    memcpy(&pressed, &(pKbMatrix->sampledKeyStates[0]), sizeof(KeyState));
    for (i=1; i < KBMATRIX_NUM_SAMPLES; i++) {

        KEYSTATE_And(&pressed, &(pKbMatrix->sampledKeyStates[i]), &pressed);
    }

    // Debounce released keys
    memcpy(&released, &(pKbMatrix->sampledKeyStates[0]), sizeof(KeyState));
    for (i=1; i < KBMATRIX_NUM_SAMPLES; i++) {

        KEYSTATE_And(&released, &(pKbMatrix->sampledKeyStates[i]), &released);
    }

    // Compute new key status
    KEYSTATE_Or(&(pKbMatrix->currentKeyState), &pressed, &new);
    KEYSTATE_And(&new, &released, &new);

    // Compare with existing status
    KEYSTATE_Xor(&new, &(pKbMatrix->currentKeyState), &changed);
    
    // Process each pending event
    for (i=0; i < (pKbMatrix->numRows * pKbMatrix->numCols); i++) {
    
        if (KEYSTATE_GetKeyState(&changed, i)) {

            event = 1;

            // Trigger callback
            if (pKbMatrix->callback) {

                pKbMatrix->callback(i, KEYSTATE_GetKeyState(&new, i));
            }
        }
    }

    // Save new key state
    memcpy(&(pKbMatrix->currentKeyState), &new, sizeof(KeyState));

    return event;
}

//-----------------------------------------------------------------------------
/// Retrieves a new debounce sample by reading the current state of the
/// keyboard.
/// \param pKbMatrix  Pointer to a KbMatrix instance.
//-----------------------------------------------------------------------------
void Fetch(KbMatrix *pKbMatrix)
{
    KeyState *pKeyState = &(pKbMatrix->sampledKeyStates[pKbMatrix->sample]);
    unsigned int row;
    unsigned int col;
    volatile unsigned int i;

    SANITY_CHECK(pKbMatrix);

    // Scan the current keyboard status
    for (row=0; row < pKbMatrix->numRows; row++) {

        // Enable row
        PIO_Clear(&(pKbMatrix->pRows[row]));

        // Scan each column
        for (col=0; col < pKbMatrix->numCols; col++) {

            KEYSTATE_SetKeyState(pKeyState,
                                 row * pKbMatrix->numCols + col,
                                 !PIO_Get(&(pKbMatrix->pCols[col])));
        }

        // Disable row (and wait for level to become 1)
        PIO_Set(&(pKbMatrix->pRows[row]));
        for (i=0; i < 100; i++); // Dirty but works    
    }

    // Update sample index
    pKbMatrix->sample = (pKbMatrix->sample + 1) % KBMATRIX_NUM_SAMPLES;
}

//-----------------------------------------------------------------------------
//         Exported functions
//-----------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Initializes a keyboard matrix driver instance.
/// \param pKbMatrix  Pointer to a KbMatrix instance.
/// \param pRows  Pointer to the list of row pins.
/// \param numRows  Number of rows in matrix.
/// \param pCols  Pointer to the list of column pins.
/// \param numCols  Number of columns in matrix.
/// \param callback  Optional callback for receiving key events.
//------------------------------------------------------------------------------
void KBMATRIX_Initialize(
    KbMatrix * pKbMatrix,
    const Pin * pRows,
    unsigned char numRows,
    const Pin * pCols,
    unsigned char numCols,
    KeyEventCallback callback)
{
    unsigned int i;

    ASSERT(numRows * numCols <= KBMATRIX_MAX_NUMKEYS,
           "KBMATRIX_Initialize: too many keys (change KBMATRIX_MAX_NUMKEYS)\n\r");

    // Initialize structure members
    pKbMatrix->pRows = pRows;
    pKbMatrix->numRows = numRows;
    pKbMatrix->pCols = pCols;
    pKbMatrix->numCols = numCols;
    pKbMatrix->callback = callback;

    // Initialize key states
    KEYSTATE_Initialize(&(pKbMatrix->currentKeyState));
    for (i=0; i < KBMATRIX_NUM_SAMPLES; i++) {

        KEYSTATE_Initialize(&(pKbMatrix->sampledKeyStates[i]));
    }
    pKbMatrix->sample = 0;
}

//-----------------------------------------------------------------------------
/// Scans the keyboard matrix for key events (key pressed or released). Takes
/// care of debouncing.
/// Returns 1 if changes have been detected on the keyboard; otherwise return
/// 0.
/// \param pKbMatrix  Pointer to a KbMatrix instance.
//-----------------------------------------------------------------------------
unsigned char KBMATRIX_Scan(KbMatrix *pKbMatrix)
{
    // Fetch new debounce sample
    Fetch(pKbMatrix);

    // Compute the new debounced key state, triggering events if necessary
    return Debounce(pKbMatrix);
}

