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

#include "board.h"
#include "board_memories.h"

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/// Default spurious interrupt handler. Infinite loop.
//------------------------------------------------------------------------------
void defaultSpuriousHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
/// Default handler for fast interrupt requests. Infinite loop.
//------------------------------------------------------------------------------
void defaultFiqHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
/// Default handler for standard interrupt requests. Infinite loop.
//------------------------------------------------------------------------------
void defaultIrqHandler( void )
{
    while (1);
}

//------------------------------------------------------------------------------
//         Global Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Initialization in already done in the chip. 
/// Initialize watchdog, remap if needed.
//------------------------------------------------------------------------------
void LowLevelInit( void )
{
    // Watchdog initialization
    AT91C_BASE_WDTC->WDTC_WDMR = AT91C_WDTC_WDDIS;

    // Remap
    BOARD_RemapRam();
}

