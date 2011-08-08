#include "potentiometer.h"
#include <peripherals/adc/adc.h>
#include <peripherals/irq/irq.h>
#include <boards/mariokartv1/board.h>

/// Pio pins to configure.
//static const Pin pins[] = {PIN_POT};

//priority of interrupt
#define ADC_PRIORITY 5

#define BOARD_ADC_FREQ 5000000
#define ADC_VREF       3300  // 3.3 * 1000

#define POT_CHANNEL ADC_CHANNEL_7

// Interrupt handler for the ADC. Signals that the conversion is finished by
// setting a flag variable.
static void ISR_Adc(void)
{
    current_adc_value = AT91C_BASE_ADC->ADC_CDR7;
    ADC_StartConversion(AT91C_BASE_ADC);
}

//Sets up pins and adc for pot
void init_pot(void){

//    PIO_Configure(pins, PIO_LISTSIZE(pins));

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

    IRQ_ConfigureIT(AT91C_ID_ADC, 0, ISR_Adc);
    IRQ_EnableIT(AT91C_ID_ADC);

    //Starts the adc
    ADC_StartConversion(AT91C_BASE_ADC);
}
