/**
 * This was stolen from the getting started project in the atmel project library
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include <board.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <pit/pit.h>
#include <aic/aic.h>
#include <tc/tc.h>
#include <utility/led.h>
#include <utility/trace.h>
//#include <dbgu/dbgu.h>

#include <stdio.h>

//------------------------------------------------------------------------------
//         Local definitions
//------------------------------------------------------------------------------
#ifndef AT91C_ID_TC0
#if defined(AT91C_ID_TC012)
#define AT91C_ID_TC0 AT91C_ID_TC012
#elif defined(AT91C_ID_TC)
#define AT91C_ID_TC0 AT91C_ID_TC
#else
#error Pb define ID_TC
#endif
#endif


/// PIT period value in µseconds.
#define PIT_PERIOD          1000

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------

/// Indicates the current state (on or off) for each LED.
unsigned char pLedStates[2] = {1, 1};

/// Global timestamp in milliseconds since start of application.
volatile unsigned int timestamp = 0;

//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Handler for PIT interrupt. Increments the timestamp counter.
//------------------------------------------------------------------------------
void ISR_Pit(void)
{
    unsigned int status;

    // Read the PIT status register
    status = PIT_GetStatus() & AT91C_PITC_PITS;
    if (status != 0) {

        // Read the PIVR to acknowledge interrupt and get number of ticks
        timestamp += (PIT_GetPIVR() >> 20);
    }
}

//------------------------------------------------------------------------------
/// Configure the periodic interval timer to generate an interrupt every
/// millisecond.
//------------------------------------------------------------------------------
void ConfigurePit(void)
{
    // Initialize the PIT to the desired frequency
    PIT_Init(PIT_PERIOD, BOARD_MCK / 1000000);

    // Configure interrupt on PIT
    AIC_DisableIT(AT91C_ID_SYS);
    AIC_ConfigureIT(AT91C_ID_SYS, AT91C_AIC_PRIOR_LOWEST, ISR_Pit);
    AIC_EnableIT(AT91C_ID_SYS);
    PIT_EnableIT();

    // Enable the pit
    PIT_Enable();
}

//------------------------------------------------------------------------------
/// Configures LEDs \#1 and \#2 (cleared by default).
//------------------------------------------------------------------------------
void ConfigureLeds(void)
{
    LED_Configure(0);
    LED_Configure(1);
}

//------------------------------------------------------------------------------
/// Interrupt handler for TC0 interrupt. Toggles the state of LED\#2.
//------------------------------------------------------------------------------
void ISR_Tc0(void)
{
    // Clear status bit to acknowledge interrupt
    AT91C_BASE_TC0->TC_SR;

    // Toggle LED state
    LED_Toggle(1);
    TRACE_INFO("Toggling LED 1\n\r");
}

//------------------------------------------------------------------------------
/// Configure Timer Counter 0 to generate an interrupt every 250ms.
//------------------------------------------------------------------------------
void ConfigureTc(void)
{
    unsigned int div;
    unsigned int tcclks;

    // Enable peripheral clock
    AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_TC0;

    // Configure TC for a 4Hz frequency and trigger on RC compare
    TC_FindMckDivisor(4, BOARD_MCK, &div, &tcclks);
    TC_Configure(AT91C_BASE_TC0, tcclks | AT91C_TC_CPCTRG);
    AT91C_BASE_TC0->TC_RC = (BOARD_MCK / div) / 4; // timerFreq / desiredFreq

    // Configure and enable interrupt on RC compare
    AIC_ConfigureIT(AT91C_ID_TC0, AT91C_AIC_PRIOR_LOWEST, ISR_Tc0);
    AT91C_BASE_TC0->TC_IER = AT91C_TC_CPCS;
    AIC_EnableIT(AT91C_ID_TC0);

    // Start the counter if LED is enabled.
    if (pLedStates[1]) {

        TC_Start(AT91C_BASE_TC0);
    }
}

//------------------------------------------------------------------------------
/// Waits for the given number of milliseconds (using the timestamp generated
/// by the PIT).
/// \param delay  Delay to wait for, in milliseconds.
//------------------------------------------------------------------------------
void Wait(unsigned long delay)
{
    volatile unsigned int start = timestamp;
    unsigned int elapsed;
    do {
        elapsed = timestamp;
        elapsed -= start;
    }
    while (elapsed < delay);
}

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Application entry point. Configures the DBGU, PIT, TC0, LEDs and buttons
/// and makes LED\#1 blink in its infinite loop, using the Wait function.
/// \return Unused (ANSI-C compatibility).
//------------------------------------------------------------------------------
int main(void)
{
    //configure UART GND pin
    const Pin pinUsartGnd[] = {PIN_USART0_GND};
    PIO_Configure(pinUsartGnd, PIO_LISTSIZE(pinUsartGnd));
    PIO_Clear(&pinUsartGnd[0]);

    // DBGU configuration
    TRACE_CONFIGURE(DBGU_STANDARD, 115200, BOARD_MCK);
    TRACE_INFO("-- Getting Started Project %s --\n\r", SOFTPACK_VERSION);
    TRACE_INFO("-- %s\n\r", BOARD_NAME);
    TRACE_INFO("-- Compiled: %s %s --\n\r", __DATE__, __TIME__);

    // Configuration
    ConfigurePit();
    ConfigureTc();
    ConfigureLeds();
    
    // Main loop
    while (1) {

        // Wait for LED to be active
        while (!pLedStates[0]);
        
        // Toggle LED state if active
        if (pLedStates[0]) {

            LED_Toggle(0);
            TRACE_INFO("Toggling LED 0\n\r");
        }

        // Wait for 500ms
        Wait(500);
    }
}


