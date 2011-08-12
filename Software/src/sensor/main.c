#include <peripherals/pio/pio.h>
#include <peripherals/pio/pio_it.h>
#include <char_display.h>
#include <speed_sensor.h>
#include <utility/trace.h>

int main(int argc, char *argv[]) {

    //configure UART GND pin
    const Pin pinUsartGnd[] = {PIN_USART0_GND};
    PIO_Configure(pinUsartGnd, PIO_LISTSIZE(pinUsartGnd)); \
    PIO_Clear(&pinUsartGnd[0]);

    // DBGU configuration
    TRACE_CONFIGURE(DBGU_STANDARD, 115200, BOARD_MCK);
    TRACE_INFO("-- Sensor Board\n\r");
    TRACE_INFO("-- %s\n\r", BOARD_NAME);
    TRACE_INFO("-- Compiled: %s %s --\n\r", __DATE__, __TIME__);

    
    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //initilizes sensors
    speed_init();
    char_display_init();

    while(1){
        int display = speed_output;
        char_display_number(display);
        char_display_tick();
    }

    return 0;
}
