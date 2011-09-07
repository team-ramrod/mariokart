#include <aic/aic.h>
#include <better_can/can.h>
#include <board.h>
#include <char_display.h>
#include <debug.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <utility/led.h>

#define SOFTWARE_NAME "Demo BCAN client"

int main(void)
{
    debug_init(SOFTWARE_NAME);

    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);
    char_display_init();
    LED_Configure(0);
    LED_Configure(1);

    if (! BCAN_Init(1000, 0, NULL)) {
        printf("INIT FAIL");
        LED_Set(1);
        return 1;
    }

    printf("INIT OK\n\r");
    LED_Set(0);

    BCAN_InitMailboxRegisters( 0, 2, AT91C_CAN_MIDvA, (0x5AC << 18), AT91C_CAN_MOT_RX, 0x0);

    char_display_number(6);
    while(1) {
        CAN_Packet packet = BCAN_ReadAndClear(0,2);
        if (packet.valid) {
            char_display_number(packet.data_low);
        }
        char_display_tick();
        for (unsigned volatile int i = 0xFF; i > 0; i--) ;
    }

    return 0;
}
