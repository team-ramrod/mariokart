//-----------------------------------------------------------------------------
//         Headers
//-----------------------------------------------------------------------------
#include <board.h>
#include <components/switches.h>
#include <pio/pio.h>
#include <dbgu/dbgu.h>
#include <utility/trace.h>
#include <utility/assert.h>

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Initialisation Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    TRACE_CONFIGURE(DBGU_STANDARD, 115200, BOARD_MCK);   
    printf("-- Mariokart - Switch test %s --\n\r", SOFTPACK_VERSION);
    printf("-- %s\n\r", BOARD_NAME);
    printf("-- Compiled: %s %s --\n\r", __DATE__, __TIME__);

    //Main initialisations
    switches_init();

    while(1) {
        if ( switches_pressed(0) ) {
            TRACE_INFO("Switch 0 is pressed\n\r");
        }
        if ( switches_pressed(1) ) {
            TRACE_INFO("Switch 1 is pressed\n\r");
        }
        if ( switches_pressed(2) ) {
            TRACE_INFO("Switch 2 is pressed\n\r");
        }
        if ( switches_pressed(3) ) {
            TRACE_INFO("Switch 3 is pressed\n\r");
        }
    }

    return 0;
}
