#include "potentiometer.h"
#include <peripherals/adc/adc.h>
#include <peripherals/irq/irq.h>
#include <peripherals/aic/aic.h>
#include <boards/mariokartv1/board.h>
#include <char_display.h>

#define BOARD_ADC_FREQ 5000000

#define POT_CHANNEL ADC_CHANNEL_7

// Interrupt handler for the ADC. Signals that the conversion is finished by
// setting a flag variable.

static void ISR_ADC(void) {
    int status = ADC_GetStatus(AT91C_BASE_ADC);

    char_display_number(33);

    if (ADC_IsChannelInterruptStatusSet(status, POT_CHANNEL)) {

        //gets the new value from ADC
        pot_current_value = ADC_GetConvertedData(AT91C_BASE_ADC, POT_CHANNEL);

        char_display_number((pot_current_value - 25) / 10);
        //char_display_number(44);

        //starts the converter running again
        ADC_StartConversion(AT91C_BASE_ADC);
    }
}

//Sets up pins and adc for pot

void pot_init(void) {

    //sets up interrupts to trigger on every sucessful conversion
    IRQ_ConfigureIT(AT91C_ID_ADC, 0, ISR_ADC);

    //initilize ADC
    ADC_Initialize(AT91C_BASE_ADC,
            AT91C_ID_ADC,
            AT91C_ADC_TRGEN_DIS,
            0,
            AT91C_ADC_SLEEP_NORMAL_MODE,
            AT91C_ADC_LOWRES_10_BIT,
            BOARD_MCK,
            BOARD_ADC_FREQ,
            10,
            1200);

    ADC_EnableDataReadyIt(AT91C_BASE_ADC);

    ADC_EnableChannel(AT91C_BASE_ADC, POT_CHANNEL);

    IRQ_EnableIT(AT91C_ID_ADC);

    ADC_EnableIt(AT91C_BASE_ADC, POT_CHANNEL);

    //Starts the adc
    ADC_StartConversion(AT91C_BASE_ADC);
}
