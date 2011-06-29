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

//------------------------------------------------------------------------------
//         Internal definitions
//------------------------------------------------------------------------------

#define NORMAL_POWER_MODE   0
#define LOW_POWER_MODE      1

//------------------------------------------------------------------------------
//         Internal variables
//------------------------------------------------------------------------------

static volatile unsigned char powerMode = NORMAL_POWER_MODE;
static unsigned int oldFmr0;
static unsigned int oldFmr1;
static unsigned int oldPll;
static unsigned int oldMck;

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Save and restore working clock.
/// Here working clock must be running from PLL
/// and external crystal oscillator is used.
//------------------------------------------------------------------------------
static void SaveWorkingClock(unsigned int *pOldPll, unsigned int *pOldMck)
{
    // Save previous values for PLL A and Master Clock configuration
    *pOldPll = AT91C_BASE_CKGR->CKGR_PLLAR;
    *pOldMck = AT91C_BASE_PMC->PMC_MCKR;
}

static void RestoreWorkingClock(unsigned int oldPll, unsigned int oldMck)
{

    // Switch to slow clock first
    AT91C_BASE_PMC->PMC_MCKR = (AT91C_BASE_PMC->PMC_MCKR & ~AT91C_PMC_CSS)
        | AT91C_PMC_CSS_SLOW_CLK;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    AT91C_BASE_PMC->PMC_MCKR = (AT91C_BASE_PMC->PMC_MCKR & ~AT91C_PMC_PRES)
        | AT91C_PMC_PRES_CLK;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));
    
    // Restart Main Oscillator
    AT91C_BASE_PMC->PMC_MOR = (0x37 << 16)
                            | (0x3F<<8)
                            | AT91C_CKGR_MOSCRCEN
                            | AT91C_CKGR_MOSCXTEN;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MOSCXTS));
    // Switch to moscsel
    AT91C_BASE_PMC->PMC_MOR = (0x37 << 16)
                            | (0x3F<<8)
                            | AT91C_CKGR_MOSCRCEN
                            | AT91C_CKGR_MOSCXTEN
                            | AT91C_CKGR_MOSCSEL;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MOSCSELS));

    // Switch to main oscillator
    AT91C_BASE_PMC->PMC_MCKR = (AT91C_BASE_PMC->PMC_MCKR & ~AT91C_PMC_CSS)
                             | AT91C_PMC_CSS_MAIN_CLK;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    AT91C_BASE_PMC->PMC_MCKR = (AT91C_BASE_PMC->PMC_MCKR & ~AT91C_PMC_PRES)
                             | AT91C_PMC_PRES_CLK;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    // Restart PLL A
    AT91C_BASE_CKGR->CKGR_PLLAR = oldPll;
    while(!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_LOCKA));

    // Switch to fast clock
    AT91C_BASE_PMC->PMC_MCKR = (oldMck & ~AT91C_PMC_CSS)
                             | AT91C_PMC_CSS_MAIN_CLK;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    AT91C_BASE_PMC->PMC_MCKR = oldMck;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    // Setup Flash waitstates
    AT91C_BASE_EFC0->EFC_FMR = oldFmr0;
    AT91C_BASE_EFC1->EFC_FMR = oldFmr1;
}

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Put the CPU in 32kHz, disable PLL, main oscillator
/// Put voltage regulator in standby mode
/// USB clock is automatically disabled.
//------------------------------------------------------------------------------
void LowPowerMode(void)
{
    if (powerMode == LOW_POWER_MODE)
        return;

    powerMode = LOW_POWER_MODE;

    SaveWorkingClock(&oldPll, &oldMck);

    oldFmr0 = AT91C_BASE_EFC0->EFC_FMR;
    AT91C_BASE_EFC0->EFC_FMR = AT91C_EFC_FWS_3WS;
    oldFmr1 = AT91C_BASE_EFC1->EFC_FMR;
    AT91C_BASE_EFC1->EFC_FMR = AT91C_EFC_FWS_3WS;

    AT91C_BASE_PMC->PMC_MCKR = (AT91C_BASE_PMC->PMC_MCKR & ~AT91C_PMC_CSS)
                             | AT91C_PMC_CSS_SLOW_CLK;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    AT91C_BASE_PMC->PMC_MCKR = (AT91C_BASE_PMC->PMC_MCKR & ~AT91C_PMC_PRES)
                             | AT91C_PMC_PRES_CLK;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    // Stop PLL A
    // MULA: PLL A Multiplier 0 = The PLL A is deactivated.
    // STMODE must be set at 2 when the PLLA is Off
    AT91C_BASE_PMC->PMC_PLLAR = 0x2 << 14;

    // Stop Main Oscillator
    AT91C_BASE_PMC->PMC_MOR = (0x37 << 16) | (0x3F << 8);
}

//------------------------------------------------------------------------------
/// Put voltage regulator in normal mode
/// Return the CPU to normal speed enable PLLs, main oscillator
/// USB clock is automatically enabled.
//------------------------------------------------------------------------------
void NormalPowerMode(void)
{
    if (powerMode == NORMAL_POWER_MODE)
        return;

    RestoreWorkingClock(oldPll, oldMck);

    powerMode = NORMAL_POWER_MODE;
}
