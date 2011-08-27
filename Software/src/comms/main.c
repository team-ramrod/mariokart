//-----------------------------------------------------------------------------
//         Headers
//-----------------------------------------------------------------------------
#include <board.h>
#include <components/char_display.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <aic/aic.h>
#include <dbgu/dbgu.h>
#include <rtt/rtt.h>
#include <utility/trace.h>
#include <utility/assert.h>
#include <can/can.h>

#define SOFTWARE_NAME Comms

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
CanTransfer canTransfer; //Can transfer structure
const Pin switchs[] = {
    PIN_PUSHBUTTON_0,
    PIN_PUSHBUTTON_1,
    PIN_PUSHBUTTON_2,
    PIN_PUSHBUTTON_3
};

//------------------------------------------------------------------------------
//         Initialisation Functions
//------------------------------------------------------------------------------
void switch_init(){
    PIO_Configure(switchs, PIO_LISTSIZE(switchs));
}
void debug_init(){
    TRACE_CONFIGURE(DBGU_STANDARD, 115200, BOARD_MCK);   
    printf("-- Mariokart - %s Board %s --\n\r", SOFTWARE_NAME, SOFTPACK_VERSION);
    printf("-- %s\n\r", BOARD_NAME);
    printf("-- Compiled: %s %s --\n\r", __DATE__, __TIME__);
}

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {

    //Main initialisations
    char_display_init();
    switch_init();
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
