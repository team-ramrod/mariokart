//-----------------------------------------------------------------------------
//         Headers
//-----------------------------------------------------------------------------
#define SOFTWARE_NAME "Comms"

#include <board.h>
#include <components/char_display.h>
#include <components/switches.h>
#include <components/debug.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <aic/aic.h>
#include <rtt/rtt.h>
#include <can/can.h>


//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
CanTransfer canTransfer; //Can transfer structure

//------------------------------------------------------------------------------
//         Initialisation Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    debug_init();

    //Main initialisations
    char_display_init();
    switches_init();
    PIO_InitializeInterrupts(0); 

    /* The third pram in CAN_Init is if you have two CAN controllers */
    if( CAN_Init( CAN_BUS_SPEED, &canTransfer, NULL ) != 1 ) {
        // CAN Init error
        TRACE_ERROR("CAN Bus did not init\n\r");
    }
    TRACE_INFO("CAN Init OK\n\r");
    CAN_ResetTransfer(&canTransfer);

    while(1) {
    }

    return 0;
}
