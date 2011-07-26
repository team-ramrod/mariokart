
#include <board.h>
#include <pio/pio.h>

static const Pin pinsLeds[] = {PINS_LEDS};
static const unsigned int numLeds = PIO_LISTSIZE(pinsLeds);

unsigned char LED_Configure(unsigned int led) {
    // Check that LED exists                                                                             
    if (led >= numLeds) {                                                                                

        return 0;                                                                                        
    }                                                                                                    

    // Configure LED
    return (PIO_Configure(&pinsLeds[led], 1));                                                           
}

//------------------------------------------------------------------------------
/// Turns the given LED on if it exists; otherwise does nothing.
/// \param led  Number of the LED to turn on.
/// \return 1 if the LED has been turned on; 0 otherwise.
//------------------------------------------------------------------------------
unsigned char LED_Set(unsigned int led) {
    // Check if LED exists
    if (led >= numLeds) {

        return 0;
    }

    // Turn LED on
    if (pinsLeds[led].type == PIO_OUTPUT_0) {

        PIO_Set(&pinsLeds[led]);
    }
    else {

        PIO_Clear(&pinsLeds[led]);
    }

    return 1;
}

unsigned char LED_Clear(unsigned int led)
{
    // Check if LED exists
    if (led >= numLeds) {

        return 0;
    }

    // Turn LED off
    if (pinsLeds[led].type == PIO_OUTPUT_0) {

        PIO_Clear(&pinsLeds[led]);
    }
    else {

        PIO_Set(&pinsLeds[led]);
    }

    return 1;
}

int main(int argc, char *argv[]) {

    LED_Configure(0);
    LED_Configure(1);

    while(1) {
        LED_Clear(0);
        LED_Set(1);
    }
    return 0;
}
