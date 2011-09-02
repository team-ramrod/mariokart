/* ----------------------------------------------------------------------------
 *          Mariokart project
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2011, University of Canterbury
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include "switches.h"
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <stdbool.h>
#include <utility/trace.h>

//------------------------------------------------------------------------------
//         Global variable init
//------------------------------------------------------------------------------
const Pin switches[] = {
    PIN_PUSHBUTTON_0,
    PIN_PUSHBUTTON_1,
    PIN_PUSHBUTTON_2,
    PIN_PUSHBUTTON_3
    };

//------------------------------------------------------------------------------
//         Local Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Global Functions
//------------------------------------------------------------------------------

void switches_init_interupt(unsigned int switch_no, void (*handler)(const Pin *)) {
    if (switch_no < SWITCHES_NUMBER_OF ) {
        PIO_ConfigureIt(&switches[switch_no], handler);
    }
    else {
        TRACE_WARNING("An incorrect switch number was passed\n\r");
    }
}

bool switches_pressed(unsigned int switch_no) {
    bool return_val = false;
    if (switch_no < SWITCHES_NUMBER_OF ) {
        if (PIO_Get(&switches[switch_no])) {
            return_val = true;
        }
    }
    else {
        TRACE_WARNING("An incorrect switch number was passed\n\r");
    }
    return !return_val;
}

void switches_init(){
    PIO_Configure(switches, PIO_LISTSIZE(switches));
}

