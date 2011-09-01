/* ----------------------------------------------------------------------------
 *          Mariokart project
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2011, University of Canterbury
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include <components/char_display.h>
#include <components/debug.h>
#include <components/switches.h>
#include <board_powermode.h>
#include <protocol/protocol.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <pmc/pmc.h>
#include <usb/device/cdc-serial/CDCDSerialDriver.h>
#include <usb/device/cdc-serial/CDCDSerialDriverDescriptors.h>
#include <utility/trace.h>

#include "usb.c"

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Comms"

/// PIT period value in µseconds.
#define PIT_PERIOD          1000

//------------------------------------------------------------------------------
//         Local Variables
//------------------------------------------------------------------------------
unsigned int milisecond_counter;

//------------------------------------------------------------------------------
//         Local Functions
//------------------------------------------------------------------------------
void send_brake_value(void) {
    message_t msg = {
        .from = ADDR_COMMS,
        .to   = ADDR_BRAKE,
        .command = CMD_SET,
        .data = {
            VAR_BRK_POS,
            brake_possition
        }
    }
    proto_write(msg);
}

void send_messages(void) {
    milisecond_counter++;
    if (milisecond_counter > 1000) {
        milisecond_counter = milisecond_counter % 10;
    }

    switch(milisecond_counter % 10) {
        case 0:
            send_brake_value();
            break;
        case 1:
            send_steering_value();
            break;
        case 2:
            send_motor_value();
            break;
        case 3:
            check_speed_timeout();
            break;
        default:
            break;
    }
}

void ISR_Pit(void)
{
    // Check to see if it has got to PIV
    if (PIT_GetStatus() & AT91C_PITC_PITS) {
        send_messages();
    }
}

void ConfigurePit(void)
{
    // Initialize the PIT to the desired frequency
    PIT_Init(PIT_PERIOD, BOARD_MCK / 10000000);

    // Configure interrupt on PIT
    AIC_DisableIT(AT91C_ID_SYS);
    AIC_ConfigureIT(AT91C_ID_SYS, AT91C_AIC_PRIOR_LOWEST, ISR_Pit);
    AIC_EnableIT(AT91C_ID_SYS);
    PIT_EnableIT();

    // Enable the pit
    PIT_Enable();
}

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    debug_init(SOFTWARE_NAME);

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    milisecond_counter = 0;
    ConfigurePit();

    //Main initialisations
    char_display_init();
    switches_init();
    VBus_Configure();

    //Init CAN Bus
    proto_init();

    while(1) {
        char_display_tick();
    }
}

