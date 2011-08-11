#include "potentiometer.h"
#include <peripherals/adc/adc.h>
#include <peripherals/irq/irq.h>
#include <boards/mariokartv1/board.h>

// Pio pin to configure.
const Pin pot_pin = PIN_POT;

#define BOARD_ADC_FREQ 5000000

#define POT_CHANNEL ADC_CHANNEL_7

// Interrupt handler for the ADC. Signals that the conversion is finished by
// setting a flag variable.
static void ISR_ADC(void)
{
    //gets the new value from ADC
    pot_current_value = AT91C_BASE_ADC->ADC_CDR7;

    //starts the converter running again
    ADC_StartConversion(AT91C_BASE_ADC);
}

//Sets up pins and adc for pot
void pot_init(void){

    //configures pots pin
    PIO_Configure(&pot_pin, 1);

    //initilize ADC
    ADC_Initialize( AT91C_BASE_ADC,
                    AT91C_ID_ADC,
                    AT91C_ADC_TRGEN_DIS,
                    0,
                    AT91C_ADC_SLEEP_NORMAL_MODE,
                    AT91C_ADC_LOWRES_10_BIT,
                    BOARD_MCK,
                    BOARD_ADC_FREQ,
                    10,
                    1200);

    //sets up interrupts to trigger on every sucessful conversion
    IRQ_ConfigureIT(AT91C_ID_ADC, 0, ISR_ADC);
    IRQ_EnableIT(AT91C_ID_ADC);

    //Starts the adc
    ADC_StartConversion(AT91C_BASE_ADC);
}
