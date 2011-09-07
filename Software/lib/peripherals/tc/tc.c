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

#include "tc.h"
#include <aic/aic.h>

//------------------------------------------------------------------------------
//         Global Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Configures a Timer Counter to operate in the given mode. Timer is stopped
/// after configuration and must be restarted with TC_Start(). All the
/// interrupts of the timer are also disabled.
/// \param pTc  Pointer to an AT91S_TC instance.
/// \param mode  Operating mode (TC_CMR value).
//------------------------------------------------------------------------------
void TC_Configure(AT91S_TC *pTc, unsigned int mode)
{
    // Disable TC clock
    pTc->TC_CCR = AT91C_TC_CLKDIS;

    // Disable interrupts
    pTc->TC_IDR = 0xFFFFFFFF;

    // Clear status register
    pTc->TC_SR;

    // Set mode
    pTc->TC_CMR = mode;
}

//------------------------------------------------------------------------------
/// Enables the timer clock and performs a software reset to start the counting.
/// \param pTc  Pointer to an AT91S_TC instance.
//------------------------------------------------------------------------------
void TC_Start(AT91S_TC *pTc)
{
    pTc->TC_CCR = AT91C_TC_CLKEN | AT91C_TC_SWTRG;
}

//------------------------------------------------------------------------------
/// Disables the timer clock, stopping the counting.
/// \param pTc  Pointer to an AT91S_TC instance.
//------------------------------------------------------------------------------
void TC_Stop(AT91S_TC *pTc)
{
    pTc->TC_CCR = AT91C_TC_CLKDIS;
}

//------------------------------------------------------------------------------
/// Finds the best MCK divisor given the timer frequency and MCK. The result
/// is guaranteed to satisfy the following equation:
/// \pre
///   (MCK / (DIV * 65536)) <= freq <= (MCK / DIV)
/// \endpre
/// with DIV being the highest possible value.
/// \param freq  Desired timer frequency.
/// \param mck  Master clock frequency.
/// \param div  Divisor value.
/// \param tcclks  TCCLKS field value for divisor.
/// \return 1 if a proper divisor has been found; otherwise 0.
//------------------------------------------------------------------------------
unsigned char TC_FindMckDivisor(
    unsigned int freq,
    unsigned int mck,
    unsigned int *div,
    unsigned int *tcclks)
{
    unsigned int index = 0;
    unsigned int divisors[5] = {2, 8, 32, 128,
#if defined(at91sam9260) || defined(at91sam9261) || defined(at91sam9g10) || defined(at91sam9263) \
    || defined(at91sam9xe) || defined(at91sam9rl64) || defined(at91cap9) \
    || defined(at91sam9m10) || defined(at91sam9g45) || defined(at91sam9m11) || defined(at91sam3u4)
        0};
    divisors[4] = mck / 32768;
#else
        1024};
#endif

    // Satisfy lower bound
    while (freq < ((mck / divisors[index]) / 65536)) {

        index++;

        // If no divisor can be found, return 0
        if (index == 5) {

            return 0;
        }
    }

    // Try to maximise DIV while satisfying upper bound
    while (index < 4) {

        if (freq > (mck / divisors[index + 1])) {

            break;
        }
        index++;
    }

    // Store results
    if (div) {

        *div = divisors[index];
    }
    if (tcclks) {

        *tcclks = index;
    }

    return 1;
}

static timer_callback_t TC_FinalCallback;

void TC1_ISR() {
    AT91C_BASE_TC1->TC_SR;
    TC_FinalCallback();
}

/**
 * Starts a timer which runs a callback at the given speed.
 * @param frequency the required frequency
 * @param callback the function to call
 */
void TC_PeriodicCallback(
        unsigned int frequency, 
        timer_callback_t callback) {
    unsigned int div;
    unsigned int tcclks;
    TC_FinalCallback = callback;

    // Enable peripheral clock
    AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_TC1;

    // Configure TC for a 4Hz frequency and trigger on RC compare
    TC_FindMckDivisor(frequency, BOARD_MCK, &div, &tcclks);
    TC_Configure(AT91C_BASE_TC1, tcclks | AT91C_TC_CPCTRG);
    AT91C_BASE_TC1->TC_RC = (BOARD_MCK / div) / frequency; // timerFreq / desiredFreq

    // Configure and enable interrupt on RC compare
    AIC_ConfigureIT(AT91C_ID_TC1, AT91C_AIC_PRIOR_LOWEST, TC1_ISR);
    AT91C_BASE_TC1->TC_IER = AT91C_TC_CPCS;
    AIC_EnableIT(AT91C_ID_TC1);

    TC_Start(AT91C_BASE_TC1);
}

