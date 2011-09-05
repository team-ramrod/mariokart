/* ----------------------------------------------------------------------------
 *          Mariokart project
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2011, University of Canterbury
 */

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------
#include <board.h>
#include <usb/device/cdc-serial/CDCDSerialDriver.h>
#include <usb/device/cdc-serial/CDCDSerialDriverDescriptors.h>

//------------------------------------------------------------------------------
//         Local defines
//------------------------------------------------------------------------------
// Size in bytes of the buffer used for reading data from the USB.
#define DATABUFFERSIZE \
    BOARD_USB_ENDPOINTS_MAXPACKETSIZE(CDCDSerialDriverDescriptors_DATAIN)

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------
// Buffer for storing incoming USB data.
static unsigned char usbBuffer[DATABUFFERSIZE];

#ifdef PIN_USB_VBUS
static const Pin pinVBus = PIN_USB_VBUS;
#endif

//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------
#ifdef PIN_USB_VBUS
/**
 * Handles interrupts coming from the PIO controller for the VBus pin
 */
static void ISR_VBus(const Pin *pPin) {
    if (PIO_Get(&pinVBus)) {
        TRACE_INFO("VBUS connected\n\r");
        USBD_Connect();
    } else {
        TRACE_INFO("VBUS disconnected\n\r");
        USBD_Disconnect();
    }
}
#endif

/* If PIN_USB_VBUS defined configures the PIO controller to
 * trigger an interrupt when the level on the VBus pin changes */
static void VBus_Configure() {
#ifdef PIN_USB_VBUS
    TRACE_INFO("VBus configuration\n\r");

    PIO_Configure(&pinVBus, 1);
    PIO_ConfigureIt(&pinVBus, ISR_VBus);
    PIO_EnableIt(&pinVBus);

    ISR_VBus(&pinVBus);
#else
    USBD_Connect();
#endif
}

void UsbDataReceived(unsigned int unused,
                            unsigned char status,
                            unsigned int received,
                            unsigned int remaining)
{
    // Check that data has been received successfully
    if (status == USBD_STATUS_SUCCESS) {

        // Send data through USART
        while (!USART_WriteBuffer(AT91C_BASE_US0, usbBuffer, received));
        AT91C_BASE_US0->US_IER = AT91C_US_TXBUFE;

        // Check if bytes have been discarded
        if ((received == DATABUFFERSIZE) && (remaining > 0)) {

            TRACE_WARNING(
                      "UsbDataReceived: %u bytes discarded\n\r",
                      remaining);
        }
    }
    else {

        TRACE_WARNING( "UsbDataReceived: Transfer error\n\r");
    }
}
