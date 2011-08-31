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
#include <drivers/protocol/protocol.h>
#include <pio/pio.h>
#include <pio/pio_it.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Demo-CAN"

//------------------------------------------------------------------------------
//         Local Variables
//------------------------------------------------------------------------------
unsigned int counter = 0;

//------------------------------------------------------------------------------
//         Local Functions
//------------------------------------------------------------------------------
void switch_0_handler(const Pin *pin) {
    if (switches_pressed(0)) {
        counter++;
    }
}
void switch_1_handler(const Pin *pin) {
    if (switches_pressed(1)) {
        //TODO: send 'counter' value to brake
    }
    counter = 0;
}
void switch_2_handler(const Pin *pin) {
    if (switches_pressed(2)) {
        //TODO: send 'counter' value to steering
    }
    counter = 0;
}
void switch_3_handler(const Pin *pin) {
    if (switches_pressed(3)) {
        //TODO: send 'counter' value to sensor
    }
    counter = 0;
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
    switches_init_interupt(0, switch_0_handler);

    //Init CAN Bus
    //TODO
    while(1) {
        char_display_tick();
    }

    return 0;
}

