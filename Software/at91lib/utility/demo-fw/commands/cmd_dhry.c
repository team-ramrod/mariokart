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

#include <board.h>
#include <rtt/rtt.h>
#include <pio/pio.h>
#include <dbgu/dbgu.h>
#include <utility/trace.h>
#include <cp15/cp15.h>
#include <stdio.h>
#include <utility/assert.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#include "dfm_cmd.h"
#include "dfm_init.h"
#include "dfm_fatfs.h"
#include "dfm_dispboxmgr.h"

//------------------------------------------------------------------------------
//         Local definitions
//------------------------------------------------------------------------------
/// Number of consecutive runs of the testloop() function.
#define NUM_RUNS            25

#if defined (AT91C_IRAM_1)
#define SRAM_ADDRESS  AT91C_IRAM_1
#define SRAM_SIZE     AT91C_IRAM_1_SIZE
#elif defined(AT91C_IRAM)
#define SRAM_ADDRESS  AT91C_IRAM
#define SRAM_SIZE     AT91C_IRAM_SIZE
#elif defined(AT91C_ISRAM)
#define SRAM_ADDRESS  AT91C_ISRAM
#define SRAM_SIZE     AT91C_ISRAM_SIZE
#else
#error SRAM define
#endif

//------------------------------------------------------------------------------
//         Imported functions
//------------------------------------------------------------------------------

extern void DHRY_testloop(int);

//------------------------------------------------------------------------------
//         Internal types
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Describes a possible clock configuration (processor clock & master clock),
/// including the necessary register values.
//------------------------------------------------------------------------------
struct ClockConfiguration {

    /// Processor clock frequency (in MHz).
    unsigned short pck;
    /// Master clock frequency (in MHz).
    unsigned short mck;
    /// CKGR_PLL reqister value.
    unsigned int pllr;
    /// PMC_MCKR register value.
    unsigned int mckr;
};

//------------------------------------------------------------------------------
//         Internal variables
//------------------------------------------------------------------------------

#define CLKCFGNUM  sizeof(clockConfigurations) / sizeof(struct ClockConfiguration)

#if defined(CP15_PRESENT)
// This base address must be on a 16KB boundary.
static unsigned char *BufMMU = (unsigned char *) (SRAM_ADDRESS + 0x4000);
#endif

// Clock configurations for the AT91SAM9263-EK
#if defined(at91sam9263)

#define AT91C_CKGR_PLLR     AT91C_CKGR_PLLAR
#define AT91C_PMC_LOCK      AT91C_PMC_LOCKA

#define AT91C_CKGR_MULA_SHIFT        16
#define AT91C_CKGR_OUTA_SHIFT        14
#define AT91C_CKGR_PLLACOUNT_SHIFT    8
#define AT91C_CKGR_DIVA_SHIFT         0

static const struct ClockConfiguration clockConfigurations[] = {

    // PCK = 240 MHz, MCK = 120 MHz
    //{240, 120, 0x202BC003, 0x00000102},
    {240, 120, (AT91C_CKGR_SRCA | (0x2b << AT91C_CKGR_MULA_SHIFT) | (0x3 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x0 << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x3 << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_2 | AT91C_PMC_PRES_CLK | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 120 MHz, MCK = 120 MHz
    //{120, 120, 0x20156003, 0x00000002},
    {120, 120, (AT91C_CKGR_SRCA | (0x15 << AT91C_CKGR_MULA_SHIFT) | (0x1 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x20 << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x3 << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_1 | AT91C_PMC_PRES_CLK | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 96 MHz, MCK = 48 MHz
    //{96, 48, 0x2057400F, 0x00000102},
    {96, 48, (AT91C_CKGR_SRCA | (0x57 << AT91C_CKGR_MULA_SHIFT) | (0x1 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x0 << AT91C_CKGR_PLLACOUNT_SHIFT) | (0xf << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_2 | AT91C_PMC_PRES_CLK | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 48 MHz, MCK = 48 MHz
    //{48, 48, 0x2057400F, 0x00000006}
    {48, 48, (AT91C_CKGR_SRCA | (0x57 << AT91C_CKGR_MULA_SHIFT) | (0x1 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x0 << AT91C_CKGR_PLLACOUNT_SHIFT) | (0xf << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_1 | AT91C_PMC_PRES_CLK_2 | AT91C_PMC_CSS_PLLA_CLK)}
};

// Clock configurations for the AT91SAM9G20-EK
#elif defined(at91sam9g20)

#define AT91C_CKGR_PLLR     AT91C_CKGR_PLLAR
#define AT91C_PMC_LOCK      AT91C_PMC_LOCKA

#define AT91C_CKGR_MULA_SHIFT        16
#define AT91C_CKGR_OUTA_SHIFT        14
#define AT91C_CKGR_PLLACOUNT_SHIFT    8
#define AT91C_CKGR_DIVA_SHIFT         0

#define AT91_PMC_MCKR_PDIV_SHIFT     12

static const struct ClockConfiguration clockConfigurations[] = {

    // PCK = 400 MHz, MCK = 133 MHz
    //{400, 133, 0x202A0101, 0x00001302},
    {400, 133, (AT91C_CKGR_SRCA | (0x2a << AT91C_CKGR_MULA_SHIFT) | (0x0 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x1 << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x1 << AT91C_CKGR_DIVA_SHIFT)),
        ((0x1 << AT91_PMC_MCKR_PDIV_SHIFT) | AT91C_PMC_MDIV_3 | AT91C_PMC_PRES_CLK | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 200 MHz, MCK = 100 MHz
    //{200, 100, 0x202A3F01, 0x0000010A},
    {200, 100, (AT91C_CKGR_SRCA | (0x2a << AT91C_CKGR_MULA_SHIFT) | (0x0 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x1 << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_2 | AT91C_PMC_PRES_CLK_4 | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 96 MHz, MCK = 48 MHz
    //{96, 48, 0x207C3F03, 0x0000010E},
    {96, 48, (AT91C_CKGR_SRCA | (0x7c << AT91C_CKGR_MULA_SHIFT) | (0x0 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x3 << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_2 | AT91C_PMC_PRES_CLK_8 | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 48 MHz, MCK = 48 MHz
    //{48, 48, 0x207C3F03, 0x00000012}
    {48, 48, (AT91C_CKGR_SRCA | (0x7c << AT91C_CKGR_MULA_SHIFT) | (0x0 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x3 << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_1 | AT91C_PMC_PRES_CLK_16 | AT91C_PMC_CSS_PLLA_CLK)}
};

// Clock configurations for the AT91SAM9XE-EK, AT91SAM9261-EK
#elif defined(at91sam9xe128) || defined(at91sam9xe256) || defined(at91sam9xe512) \
      || defined(at91sam9261)

#define AT91C_CKGR_PLLR     AT91C_CKGR_PLLAR
#define AT91C_PMC_LOCK      AT91C_PMC_LOCKA

#define AT91C_CKGR_MULA_SHIFT        16
#define AT91C_CKGR_OUTA_SHIFT        14
#define AT91C_CKGR_PLLACOUNT_SHIFT    8
#define AT91C_CKGR_DIVA_SHIFT         0


static const struct ClockConfiguration clockConfigurations[] = {

    // PCK = 200 MHz, MCK = 100 MHz
    //{200, 100, 0x208CBF0D, 0x00000102},
    {200, 100, (AT91C_CKGR_SRCA | (0x8c << AT91C_CKGR_MULA_SHIFT) | (0x2 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0xd << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_2 | AT91C_PMC_PRES_CLK | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 100 MHz, MCK = 100 MHz
    //{100, 100, 0x201A3F05, 0x00000002},
    {100, 100, (AT91C_CKGR_SRCA | (0x1a << AT91C_CKGR_MULA_SHIFT) | (0x0 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x5 << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_1 | AT91C_PMC_PRES_CLK | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 96 MHz, MCK = 48 MHz
    //{96, 48, 0x20483F0E, 0x00000102},
    {96, 48, (AT91C_CKGR_SRCA | (0x48 << AT91C_CKGR_MULA_SHIFT) | (0x0 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0xe << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_2 | AT91C_PMC_PRES_CLK | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 48 MHz, MCK = 48 MHz
    //{48, 48, 0x20483F0E, 0x00000006}
    {48, 48, (AT91C_CKGR_SRCA | (0x48 << AT91C_CKGR_MULA_SHIFT) | (0x0 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0xe << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_1 | AT91C_PMC_PRES_CLK_2 | AT91C_PMC_CSS_PLLA_CLK)}
};

// Clock configurations for the AT91SAM9RL64-EK, AT91CAP9-DK, AT91CAP9-STK
#elif defined(at91sam9rl64) || defined(at91cap9)

#define AT91C_CKGR_PLLR     AT91C_CKGR_PLLAR
#define AT91C_PMC_LOCK      AT91C_PMC_LOCKA

#define AT91C_CKGR_MULA_SHIFT        16
#define AT91C_CKGR_OUTA_SHIFT        14
#define AT91C_CKGR_PLLACOUNT_SHIFT    8
#define AT91C_CKGR_DIVA_SHIFT         0


static const struct ClockConfiguration clockConfigurations[] = {

    // PCK = 200 MHz, MCK = 100 MHz
    //{200, 100, 0x2031BF03, 0x00000102},
    {200, 100, (AT91C_CKGR_SRCA | (0x31 << AT91C_CKGR_MULA_SHIFT) | (0x2 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x3 << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_2 | AT91C_PMC_PRES_CLK | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 100 MHz, MCK = 100 MHz
    //{100, 100, 0x20183F03, 0x00000002},
    {100, 100, (AT91C_CKGR_SRCA | (0x18 << AT91C_CKGR_MULA_SHIFT) | (0x0 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x3 << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_1 | AT91C_PMC_PRES_CLK | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 96 MHz, MCK = 48 MHz
    //{96, 48, 0x20073F01, 0x00000102},
    {96, 48, (AT91C_CKGR_SRCA | (0x7 << AT91C_CKGR_MULA_SHIFT) | (0x0 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x1 << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_2 | AT91C_PMC_PRES_CLK | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 48 MHz, MCK = 48 MHz
    //{48, 48, 0x20073F01, 0x00000006}
    {48, 48, (AT91C_CKGR_SRCA | (0x7 << AT91C_CKGR_MULA_SHIFT) | (0x0 << AT91C_CKGR_OUTA_SHIFT) \
        | (0x3f << AT91C_CKGR_PLLACOUNT_SHIFT) | (0x1 << AT91C_CKGR_DIVA_SHIFT)),
        (AT91C_PMC_MDIV_1 | AT91C_PMC_PRES_CLK_2 | AT91C_PMC_CSS_PLLA_CLK)},
};

// Clock configuration for the AT91SAM7X-EK, AT91SAM7S-EK, AT91SAM7SE-EK
#elif defined(at91sam7x128) || defined(at91sam7x256) || defined(at91sam7x512) \
      || defined(at91sam7xc128) || defined(at91sam7xc256) || defined(at91sam7xc512) \
      || defined(at91sam7s16) || defined(at91sam7s161) || defined(at91sam7s32) \
      || defined(at91sam7s321) || defined(at91sam7s64) || defined(at91sam7s128) \
      || defined(at91sam7s256) || defined(at91sam7s512) || defined(at91sam7se32) \
      || defined(at91sam7se256) || defined(at91sam7se512)

#define AT91C_CKGR_USBDIV_SHIFT     28
#define AT91C_CKGR_MUL_SHIFT        16
#define AT91C_CKGR_OUT_SHIFT        14
#define AT91C_CKGR_PLLCOUNT_SHIFT    8
#define AT91C_CKGR_DIV_SHIFT         0


static const struct ClockConfiguration clockConfigurations[] = {

    // PCK = 55 MHz, MCK = 55 MHz
    //{55, 55, 0x006A3F12, 0x00000007},
    {55, 55, ((0x0 << AT91C_CKGR_USBDIV_SHIFT) | (0x6a << AT91C_CKGR_MUL_SHIFT) \
        | (0x0 << AT91C_CKGR_OUT_SHIFT) |(0x3f << AT91C_CKGR_PLLCOUNT_SHIFT) \
        | (0x12 << AT91C_CKGR_DIV_SHIFT)),
         AT91C_PMC_PRES_CLK_2 | AT91C_PMC_CSS_PLL_CLK},
    // PCK = 48 MHz, MCK = 48 MHz
    //{48, 48, 0x00483F0E, 0x00000007},
    {48, 48, ((0x0 << AT91C_CKGR_USBDIV_SHIFT) | (0x48 << AT91C_CKGR_MUL_SHIFT) \
        | (0x0 << AT91C_CKGR_OUT_SHIFT) |(0x3f << AT91C_CKGR_PLLCOUNT_SHIFT) \
        | (0xe << AT91C_CKGR_DIV_SHIFT)),
        ( AT91C_PMC_PRES_CLK_2 | AT91C_PMC_CSS_PLL_CLK)}
};

// Clock configuration for the AT91SAM7A3
#elif defined(at91sam7a3)

#define AT91C_CKGR_USBDIV_SHIFT      28
#define AT91C_CKGR_MUL_SHIFT         16
#define AT91C_CKGR_OUT_SHIFT         14
#define AT91C_CKGR_PLLCOUNT_SHIFT     8
#define AT91C_CKGR_DIV_SHIFT          0

static const struct ClockConfiguration clockConfigurations[] = {

    // PCK = 60 MHz, MCK = 60 MHz
    //{60, 60, 0x000C3F02, 0x00000007},
    {60, 60, ((0x0 << AT91C_CKGR_USBDIV_SHIFT) | (0x6a << AT91C_CKGR_MUL_SHIFT) \
        | (0x0 << AT91C_CKGR_OUT_SHIFT) |(0x3f << AT91C_CKGR_PLLCOUNT_SHIFT) \
        | (0x2 << AT91C_CKGR_DIV_SHIFT)), 
        ( AT91C_PMC_PRES_CLK_2 | AT91C_PMC_CSS_PLL_CLK)},
    // PCK = 48 MHz, MCK = 48 MHz
    //{48, 48, 0x00483F0E, 0x00000007}
    {48, 48, ((0x0 << AT91C_CKGR_USBDIV_SHIFT) | (0x48 << AT91C_CKGR_MUL_SHIFT) \
        | (0x0 << AT91C_CKGR_OUT_SHIFT) |(0x3f << AT91C_CKGR_PLLCOUNT_SHIFT) \
        | (0x12 << AT91C_CKGR_DIV_SHIFT)), 
        ( AT91C_PMC_PRES_CLK_2 | AT91C_PMC_CSS_PLL_CLK)}
};

// Clock configuration for the AT91SAM3U4
#elif defined(at91sam3u4)

#define AT91C_CKGR_PLLR     AT91C_CKGR_PLLAR
#define AT91C_PMC_LOCK      AT91C_PMC_LOCKA

#define AT91C_CKGR_MUL_SHIFT         16
#define AT91C_CKGR_OUT_SHIFT         14
#define AT91C_CKGR_PLLCOUNT_SHIFT     8
#define AT91C_CKGR_DIV_SHIFT          0

static const struct ClockConfiguration clockConfigurations[] = {

    // PCK = 84 MHz, MCK = 84 MHz
    //{84, 84, 0x200d3f01, 0x00000012},
    {84, 84, ((1 << 29) | (0xd << AT91C_CKGR_MUL_SHIFT) \
        | (0x0 << AT91C_CKGR_OUT_SHIFT) |(0x3f << AT91C_CKGR_PLLCOUNT_SHIFT) \
        | (0x1 << AT91C_CKGR_DIV_SHIFT)), 
        ( AT91C_PMC_PRES_CLK_2 | AT91C_PMC_CSS_PLLA_CLK)},
    // PCK = 48 MHz, MCK = 48 MHz
    //{48, 48, 0x20073f01, 0x00000012}
    {48, 48, ((1 << 29) | (0x7 << AT91C_CKGR_MUL_SHIFT) \
        | (0x0 << AT91C_CKGR_OUT_SHIFT) |(0x3f << AT91C_CKGR_PLLCOUNT_SHIFT) \
        | (0x1 << AT91C_CKGR_DIV_SHIFT)), 
        ( AT91C_PMC_PRES_CLK_2 | AT91C_PMC_CSS_PLLA_CLK)}
};

// No clock configuration
#else
    #error No clock configuration for this board.
#endif

/// Number of available clock configurations
const unsigned char numConfigurations = sizeof(clockConfigurations)
                                        / sizeof(struct ClockConfiguration);

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Sets the specified clock configuration.
/// \param configuration  Index of the configuration to set.
//------------------------------------------------------------------------------
static void SetClockConfiguration(unsigned char configuration)
{
    printf("Setting clock configuration #%d ... ", configuration);

    // Switch to main oscillator in two operations
    AT91C_BASE_PMC->PMC_MCKR = (AT91C_BASE_PMC->PMC_MCKR & ~AT91C_PMC_CSS) | AT91C_PMC_CSS_MAIN_CLK;
    while ((AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY) == 0);

    // Configure PLL
    *AT91C_CKGR_PLLR = clockConfigurations[configuration].pllr;
    while ((AT91C_BASE_PMC->PMC_SR & AT91C_PMC_LOCK) == 0);

    // Configure master clock in two operations
    AT91C_BASE_PMC->PMC_MCKR = (clockConfigurations[configuration].mckr & ~AT91C_PMC_CSS) | AT91C_PMC_CSS_MAIN_CLK;
    while ((AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY) == 0);
    AT91C_BASE_PMC->PMC_MCKR = clockConfigurations[configuration].mckr;
    while ((AT91C_BASE_PMC->PMC_SR & AT91C_PMC_MCKRDY) == 0);

    // DBGU reconfiguration
    DBGU_Configure(DBGU_STANDARD, 115200, clockConfigurations[configuration].mck*1000000);
    printf("done.\n\r");
}

//------------------------------------------------------------------------------
/// Displays the user menu on the DBGU.
//------------------------------------------------------------------------------
static void DisplayMenu(void)
{
    unsigned int i;

    printf("\n\rMenu :\n\r");
    printf("------\n\r");

    for (i = 0; i < numConfigurations; i++) {

        printf("  %u: Set PCK = %3d MHz, MCK = %3d MHz\n\r",
               i,
               clockConfigurations[i].pck,
               clockConfigurations[i].mck);
    }
}

//------------------------------------------------------------------------------
/// Computes the number of dhrystones per second that the device can produce
/// under the current configuration. Outputs four measures on the DBGU.
//------------------------------------------------------------------------------
static void ComputeDhrystonesPerSecond(void)
{
    unsigned int startTime;
    unsigned int dhrystonesPerSecond;
    unsigned char i;
    char dhrystr[50];

    printf("Computing dhrystones per second ...\n\r");

    // Configure the RTT
    RTT_SetPrescaler(AT91C_BASE_RTTC, 32768);

    // Perform measures
    for (i=0; i < 4; i++) {
    
        dhrystonesPerSecond = 0;  
        
        // Wait for the next second
        startTime = RTT_GetTime(AT91C_BASE_RTTC);
        while (startTime == RTT_GetTime(AT91C_BASE_RTTC));
    
        // Go through test loop
        startTime = RTT_GetTime(AT91C_BASE_RTTC);
        while (RTT_GetTime(AT91C_BASE_RTTC) == startTime) {
    
            DHRY_testloop(NUM_RUNS);
            dhrystonesPerSecond += NUM_RUNS;
        }
        //printf(" - %u dhrystones per second\n\r", dhrystonesPerSecond);
        sprintf(dhrystr,"- %u dhrystones per second\n\r", dhrystonesPerSecond);
        DrawStrInDispBoxDefault((void *)BOARD_LCD_BASE, 1, dhrystr);
    }
    printf("\n\rFinished\n\r");
}

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Portal for 'dhry' command
//  \param argc, number of argument
//  \param argv, argument string array
//  \return 0 succeed, other value failure
//------------------------------------------------------------------------------
int DFM_Dhry(int argc, char** argv)
{
  unsigned int cfgnum = 0;
    
  printf("\n\r Dhrystone test! \n\r");
  
  if(argc == 2 && strcmp(argv[1], "menu") == 0) {
    DisplayMenu();
    return 0;
  }
  
//#if defined(at91sam3u)
//    OptimizeCpuSpeed();
//#endif
  if(argc == 2) {
    errno = 0;
    cfgnum = atoi(argv[1]);
    
  }
  
  if(argc == 2 && cfgnum < CLKCFGNUM) {
    SetClockConfiguration(cfgnum);
  }else {
    //default set as 0, in sam3u4, it is PCK=84MHZ, MCK=84MHZ
    SetClockConfiguration(0);
  }

  ComputeDhrystonesPerSecond();
 
  return 0;
}

//define a new command for dhrystone test
DFM_CMD(dhry, DFM_Dhry, "Perform Dhrystone test", "default");




