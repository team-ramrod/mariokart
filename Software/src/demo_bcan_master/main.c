#include <board.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <aic/aic.h>
#include <debug.h>
#include <switches.h>
#include <better_can/can.h>
#include <char_display.h>
#include <utility/led.h>

#define SOFTWARE_NAME "Demo BCAN master"

static void DisplayMenu(void) {
    printf("\n\r");	
    printf("Menu :\n\r");
    printf("------\n\r");
    printf("1: transmit, with acceptance mask\n\r");    
    printf("2: transmit, no acceptance mask\n\r");    
    printf("3: dump registers\n\r");  
    printf("Press any key to stop transmission\n\r");              
    printf("\n\r");
}

int main(void)
{
    unsigned int switchPressed;

    debug_init(SOFTWARE_NAME);

    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);
    switches_init();
    char_display_init();
    LED_Configure(0);
    LED_Configure(1);

    if (! BCAN_Init(1000, 0)) {
        printf("INIT FAIL");
        LED_Set(0);
        return 1;
    }

    printf("INIT OK\n\r");
    LED_Set(1);

    BCAN_InitMailboxRegisters( 0, 1, 0x0, (0x5AC << 18), AT91C_CAN_MOT_TX, 0x0);

    while(1) {
        DisplayMenu();

        switchPressed = -1;
        while (switchPressed == -1) {
            if (switches_pressed(0)) {
                TRACE_INFO("Switch 0 is pressed\n\r");
                switchPressed = 0;
            } else if (switches_pressed(1)) {
                TRACE_INFO("Switch 1 is pressed\n\r");
                switchPressed = 1;
            } else if (switches_pressed(2)) {
                TRACE_INFO("Switch 2 is pressed\n\r");
                switchPressed = 2;
            } else if (switches_pressed(3)) {
                TRACE_INFO("Switch 3 is pressed\n\r");
                switchPressed = 3;
            } else {
                //TRACE_INFO("No Switch is pressed\n\r");
            }
            char_display_tick();
            for (volatile unsigned int i = 0xFF; i > 0; i--) ;
        }

        unsigned int result = -1;
        while (result != CAN_STATUS_SUCCESS) {
            result = BCAN_Write(0, 1, 0, switchPressed, 0x1);
        }
        char_display_number(switchPressed);
    }

    return 0;
}
