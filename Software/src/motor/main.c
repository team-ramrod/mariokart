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
#include <board.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <protocol/protocol.h>
#include <spi/spi.h>
#include <tc/tc.h>
#include <utility/trace.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
#define SOFTWARE_NAME "Motor"

#define TOP_ACCELERATOR 3200

//Sets the chip select for the student board SPI
#define STUDENT_CS 0x0

//The Student board SPI baud rate
#define STUDENT_BAUD 128000

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
const Pin student_spi_pins[] = {PINS_SPI1,PIN_SPI1_NPCS0,PIN_SPI1_NPCS1,PIN_SPI1_NPCS2};
AT91PS_SPI student_spi = AT91C_BASE_SPI1;

//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------
void set_motor(unsigned int setpoint) {
    // Make sure the value is valid else error
    if (setpoint > TOP_ACCELERATOR) {
        TRACE_WARNING("The accelerator value (%d) sent to the student board is invalid!\n\r", setpoint);
        SPI_Write(student_spi, STUDENT_CS, 0x0000);
        proto_state_error();
        return;
    }
    TRACE_DEBUG("Setting the motor board accelerator value to: %d\n\r", setpoint);
    SPI_Write(student_spi, STUDENT_CS, setpoint);

}

void init_student_spi() {
    TRACE_DEBUG("Configuring SPI for student board\n\r");
    PIO_Configure(student_spi_pins, PIO_LISTSIZE(student_spi_pins));
    //set 12 bits per transmit for max value of `TOP_ACCELERATOR'
    SPI_Configure(
            student_spi,
            AT91C_ID_SPI1,
            AT91C_SPI_MSTR | AT91C_SPI_MODFDIS | (AT91C_SPI_PCS & 0x00)
            );
    SPI_ConfigureNPCS(
            student_spi,
            STUDENT_CS,
            (AT91C_SPI_BITS & AT91C_SPI_BITS_12) | SPI_SCBR(STUDENT_BAUD, BOARD_MCK)
            );
    SPI_Enable(student_spi);
}

void timer_callback(void) {
    char_display_tick();
}


//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    unsigned int i = 0;
    debug_init(SOFTWARE_NAME);

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //Main initialisations
    char_display_init();
    switches_init();
    init_student_spi();

    //Starts a timer running at 100Hz to maintain the display
    TC_PeriodicCallback(100, timer_callback);

    char_display_number(87);
    while(1) {
        if (i > 3100) {
            i = 0;
        }
        if (SPI_IsFinished(student_spi)) {
            set_motor(i);
        }
        i++;
    }
/*
    message_t msg;

    proto_init(ADDR_MOTOR);

    while (1) {
        switch (proto_state()) {
            case STARTUP:
                break;
            case CALIBRATING:
                proto_calibration_complete();
                break;
            case RUNNING: 
                msg = proto_read();
                switch(msg.command) {
                    case CMD_SET:
                        set_motor(msg.data[1]);
                        proto_refresh();
                        break;
                    case CMD_NONE:
                        break;
                    default:
                        TRACE_WARNING("Invalid command %i received in running state", msg.command);
                        proto_state_error();
                        break; 

                }
                break;
            default: // ERROR
                set_motor(0);
                break;
        }
    }
*/
    return 0;
}

