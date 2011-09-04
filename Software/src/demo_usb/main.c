#include <board.h>
#include <pio/pio.h>
#include <pio/pio_it.h>
#include <aic/aic.h>
#include <debug.h>
#include <utility/led.h>
#include <components/char_display.h>
#include <usb/device/cdc-serial/CDCDSerialDriver.h>
#include <usb/device/cdc-serial/CDCDSerialDriverDescriptors.h>

#define DATABUFFERSIZE BOARD_USB_ENDPOINTS_MAXPACKETSIZE(CDCDSerialDriverDescriptors_DATAIN)

static unsigned char usbBuffer[DATABUFFERSIZE];

static void ISR_VBus(const Pin *pPin) {
    if (PIO_Get(pPin)) {
        USBD_Connect();
        LED_Set(0);
    } else {
        USBD_Disconnect();
        LED_Clear(0);
    }
}

static void VBus_Configure( void ) {
    static const Pin pinVbus = PIN_USB_VBUS;

    PIO_Configure(&pinVbus, 1);
    PIO_ConfigureIt(&pinVbus, ISR_VBus);
    PIO_EnableIt(&pinVbus);

    ISR_VBus(&pinVbus);
}

static void UsbDataReceived(void *unused,
                            unsigned char status,
                            unsigned int received,
                            unsigned int remaining)
{
    if (status == USBD_STATUS_SUCCESS) {
        CDCDSerialDriver_Write(usbBuffer, received, NULL, 0);
        char_display_number(usbBuffer[0]);
    }
}

int main() {
    PIO_InitializeInterrupts(0);

    debug_init("Demo USB");

    LED_Configure(0);
    LED_Configure(1);
    LED_Set(1);

    char_display_init();
    char_display_number(11);

    CDCDSerialDriver_Initialize();

    VBus_Configure();

    for (;;) {
        if (USBD_GetState() == USBD_STATE_CONFIGURED) {
            CDCDSerialDriver_Read(usbBuffer, DATABUFFERSIZE, UsbDataReceived, 0);
        }
        char_display_tick();
    }
}
