/* ----------------------------------------------------------------------------
 *          Mariokart project
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2011, University of Canterbury
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include <can/can.h>
#include <components/char_display.h>
#include <components/debug.h>
#include <components/switches.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <peripherals/tc/tc.h>
#include <aic/aic.h>
#include <speed_sensor.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Sensor"

//the timer resolution in ms
#define TIMER_RES 1

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
CanTransfer canTransfer; //Can transfer structure

//------------------------------------------------------------------------------
//         Interrupt Handlers
//------------------------------------------------------------------------------

//updates time since speed sensor last triggered
void TIMER_ISR(void)
{
    // Clear status bit to acknowledge interrupt
    AT91C_BASE_TC0->TC_SR;

    speed_update_time(TIMER_RES);
}

//------------------------------------------------------------------------------
//         Local Functions
//------------------------------------------------------------------------------

// Configure Timer Counter 0 to generate an interrupt every ms.
void timer_init(void){
    unsigned int div;
    unsigned int tcclks;

    // Enable peripheral clock
    AT91C_BASE_PMC->PMC_PCER = 1 << AT91C_ID_TC0;

    // Configure TC for a 4Hz frequency and trigger on RC compare
    TC_FindMckDivisor((1000/TIMER_RES), BOARD_MCK, &div, &tcclks);
    TC_Configure(AT91C_BASE_TC0, tcclks | AT91C_TC_CPCTRG);
    AT91C_BASE_TC0->TC_RC = (BOARD_MCK / div) / (1000/TIMER_RES); // timerFreq / desiredFreq

    // Configure and enable interrupt on RC compare
    AIC_ConfigureIT(AT91C_ID_TC0, AT91C_AIC_PRIOR_LOWEST, TIMER_ISR);
    AT91C_BASE_TC0->TC_IER = AT91C_TC_CPCS;
    AIC_EnableIT(AT91C_ID_TC0);

    // Start the counter
    TC_Start(AT91C_BASE_TC0);
}

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    debug_init(SOFTWARE_NAME);

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //Main initialisations
    char_display_init();
    switches_init();
    timer_init();
    speed_init();

    //Init CAN Bus
    /* The third pram in CAN_Init is if you have two CAN controllers */
    if( CAN_Init( CAN_BUS_SPEED, &canTransfer, NULL ) != 1 ) {
        TRACE_ERROR("CAN Bus did not init\n\r");
    }
    TRACE_INFO("CAN Init OK\n\r");
    CAN_ResetTransfer(&canTransfer);

    while(1){        
        int display = speed_output;
        TRACE_INFO("Current kart speed = %i\n\r",display);
        char_display_number(display);
        char_display_tick();
    }

    return 0;
}

