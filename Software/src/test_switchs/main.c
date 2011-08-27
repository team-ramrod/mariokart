//-----------------------------------------------------------------------------
//         Headers
//-----------------------------------------------------------------------------
#include <board.h>
#include <pio/pio.h>
#include <dbgu/dbgu.h>
#include <utility/trace.h>
#include <utility/assert.h>

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    TRACE_CONFIGURE(DBGU_STANDARD, 115200, BOARD_MCK);   
    printf("-- Mariokart - Switch test %s --\n\r", SOFTPACK_VERSION);
    printf("-- %s\n\r", BOARD_NAME);
    printf("-- Compiled: %s %s --\n\r", __DATE__, __TIME__);

    //Main initialisations
    switch_init();

    while(1) {
        if ( !PIO_Get(&switchs[0]) ) {
            TRACE_INFO("Switch 0 is pressed\n\r");
        }
        if ( !PIO_Get(&switchs[1]) ) {
            TRACE_INFO("Switch 1 is pressed\n\r");
        }
        if ( !PIO_Get(&switchs[2]) ) {
            TRACE_INFO("Switch 2 is pressed\n\r");
        }
        if ( !PIO_Get(&switchs[3]) ) {
            TRACE_INFO("Switch 3 is pressed\n\r");
        }
    }

    return 0;
}