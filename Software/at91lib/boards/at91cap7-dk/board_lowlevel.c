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
//         Internal definitions
//------------------------------------------------------------------------------
/*
    Constants: Clock and PLL settings

        BOARD_OSCOUNT - Startup time of main oscillator (in number of slow clock
                        ticks).
        BOARD_USBDIV - USB PLL divisor value to obtain a 48MHz clock.
        BOARD_CKGR_PLL - PLL frequency range.
        BOARD_PLLCOUNT - PLL startup time (in number of slow clock ticks).
        BOARD_MUL - PLL MUL value.
        BOARD_DIV - PLL DIV value.
        BOARD_PRESCALER - Master clock prescaler value.
*/
#define BOARD_OSCOUNT           (AT91C_CKGR_OSCOUNT & (0xf << 8))

#define BOARD_CKGR_PLLA         (AT91C_CKGR_SRCA | AT91C_CKGR_OUTA_0)
#define BOARD_PLLACOUNT         (40 << 8)                               // maximum
#define BOARD_MULA              (AT91C_CKGR_MULA & (7 << 16))
#define BOARD_DIVA              (AT91C_CKGR_DIVA & 1)

#define BOARD_USBDIV            AT91C_CKGR_USBDIV_1
#define BOARD_CKGR_PLLB         AT91C_CKGR_OUTB_0
#define BOARD_PLLBCOUNT         BOARD_PLLACOUNT
#define BOARD_MULB              (7 << 16)
#define BOARD_DIVB              1

#define BOARD_PRESCALER         AT91C_PMC_PRES_CLK_2

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------
/*!
    Default spurious interrupt handler
 */
void defaultSpuriousHandler(void)
{
    //while (1);
}

/*!
    Default handler for fast interrupt requests.
 */
void defaultFiqHandler(void)
{
    while (1);
}

/*!
    Default handler for standard interrupt requests.
 */
void defaultIrqHandler(void)
{
    while (1);
}

#include <board.h>
#include <pio/pio.h>

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
/*!
    Performs the low-level initialization of the chip.
 */

void LowLevelInit( void )
{
    unsigned char i;

#if !defined (sdram)
    // Initialize main oscillator
    AT91C_BASE_PMC->PMC_MOR = BOARD_OSCOUNT | AT91C_CKGR_MOSCEN;

    // Wait for the main oscillator to stabilize
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MOSCS));

    // Initialize PLLA at 96MHz
    AT91C_BASE_PMC->PMC_PLLAR =   BOARD_CKGR_PLLA
                                | BOARD_PLLACOUNT
                                | BOARD_MULA
                                | BOARD_DIVA ;

    // Wait for the PLLA  to lock
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_LOCKA));

    // Initialize PLLB for USB usage (if not already locked)
    if (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_LOCKB)) {
        AT91C_BASE_PMC->PMC_PLLBR =   BOARD_USBDIV
                                    | BOARD_CKGR_PLLB
                                    | BOARD_PLLBCOUNT
                                    | BOARD_MULB
                                    | BOARD_DIVB;
        while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_LOCKB));
    }

    // Select PLLA
    AT91C_BASE_PMC->PMC_MCKR = AT91C_PMC_PRES_CLK_2;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));

    AT91C_BASE_PMC->PMC_MCKR = AT91C_PMC_CSS_PLLA_CLK | AT91C_PMC_PRES_CLK_2;
    while (!(AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY));
#endif  //#if !defined (sdram)
    
    /* Initialize AIC
     ****************/
    AT91C_BASE_AIC->AIC_IDCR = 0xFFFFFFFF;
    AT91C_BASE_AIC->AIC_SVR[0] = (unsigned int) defaultFiqHandler;
    for (i = 1; i < 31; i++) {

        AT91C_BASE_AIC->AIC_SVR[i] = (unsigned int) defaultIrqHandler;
    }
    AT91C_BASE_AIC->AIC_SPU = (unsigned int) defaultSpuriousHandler;

    // Unstack nested interrupts
    for (i = 0; i < 8 ; i++) {

        AT91C_BASE_AIC->AIC_EOICR = 0;
    }

    // Enable Debug mode
    AT91C_BASE_AIC->AIC_DCR = AT91C_AIC_DCR_PROT;

    /* Watchdog initialization
     *************************/
    AT91C_BASE_WDTC->WDTC_WDMR = AT91C_WDTC_KEY | AT91C_WDTC_WDDIS;

    /* Remap
     *******/
    BOARD_RemapRam();

    // Disable RTT and PIT interrupts (potential problem when program A
    // configures RTT, then program B wants to use PIT only, interrupts
    // from the RTT will still occur since they both use AT91C_ID_SYS)
    AT91C_BASE_RTTC->RTTC_RTMR &= ~(AT91C_RTTC_ALMIEN | AT91C_RTTC_RTTINCIEN);
    AT91C_BASE_PITC->PITC_PIMR &= ~AT91C_PITC_PITIEN;
}

