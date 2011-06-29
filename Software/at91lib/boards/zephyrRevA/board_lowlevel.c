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
/// !Purpose
///
/// Provides the low-level initialization function that gets called on chip
/// startup.
///
/// !Usage
///
/// LowLevelInit() is called in #board_cstartup.S#.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "board.h"
#include "board_memories.h"

//------------------------------------------------------------------------------
//         Local definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Global variables
//------------------------------------------------------------------------------

// SUPC status value read during LowLevelInit(), discarded by read.
//unsigned int gLowLevelInitSupcStatus;

//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Performs the low-level initialization of the chip. This includes EFC, master
/// clock, AIC & watchdog configuration, as well as memory remapping.
//------------------------------------------------------------------------------
void LowLevelInit(void)
{
    unsigned int tmp;

    // Setup the PSRAM (HSMC4_EBI.CS1, 0x61000000 ~ 0x61FFFFFF)
    AT91C_BASE_HSMC4_CS1->HSMC4_SETUP = 0
                        | ((0 <<  0) & AT91C_HSMC4_NWE_SETUP)
                        | ((0 <<  8) & AT91C_HSMC4_NCS_WR_SETUP)
                        | ((0 << 16) & AT91C_HSMC4_NRD_SETUP)
                        | ((0 << 24) & AT91C_HSMC4_NCS_RD_SETUP)
                        ;
    AT91C_BASE_HSMC4_CS1->HSMC4_PULSE = 0
                        | ((2 <<  0) & AT91C_HSMC4_NWE_PULSE)
                        | ((2 <<  8) & AT91C_HSMC4_NCS_WR_PULSE)
                        | ((2 << 16) & AT91C_HSMC4_NRD_PULSE)
                        | ((2 << 24) & AT91C_HSMC4_NCS_RD_PULSE)
                        ;
    AT91C_BASE_HSMC4_CS1->HSMC4_CYCLE = 0
                        | ((2 <<  0) & AT91C_HSMC4_NWE_CYCLE)
                        | ((2 << 16) & AT91C_HSMC4_NRD_CYCLE)
                        ;

    tmp = AT91C_BASE_HSMC4_CS1->HSMC4_TIMINGS
        & (unsigned int)(AT91C_HSMC4_OCMSEN | AT91C_HSMC4_RBNSEL | AT91C_HSMC4_NFSEL);
    AT91C_BASE_HSMC4_CS1->HSMC4_TIMINGS = tmp
                        | ((0 <<  0) & AT91C_HSMC4_TCLR) // CLE to REN
                        | ((0 <<  4) & AT91C_HSMC4_TADL) // ALE to Data
                        | ((0 <<  8) & AT91C_HSMC4_TAR)  // ALE to REN
                        | ((0 << 16) & AT91C_HSMC4_TRR)  // Ready to REN
                        | ((0 << 24) & AT91C_HSMC4_TWB)  // WEN to REN
                        ;
    tmp = AT91C_BASE_HSMC4_CS1->HSMC4_MODE & ~(unsigned int)AT91C_HSMC4_DBW;
    AT91C_BASE_HSMC4_CS1->HSMC4_MODE = tmp
                        | (AT91C_HSMC4_READ_MODE)
                        | (AT91C_HSMC4_WRITE_MODE)
                        | (AT91C_HSMC4_DBW_WIDTH_SIXTEEN_BITS)
                        | (AT91C_HSMC4_PMEN)
                        ;
}
