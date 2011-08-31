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
#include <speed_sensor.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Sensor"

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
CanTransfer canTransfer; //Can transfer structure

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

