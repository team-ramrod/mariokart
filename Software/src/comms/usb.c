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

static void UsbHandler(const unsigned char data[], unsigned int length);

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
#define BUFFER_LENGTH 8
static unsigned char message_buffer[BUFFER_LENGTH] = {0};
static unsigned int current_char = 0;

static message_t usb_msg;

//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------
#ifdef PIN_USB_VBUS
/**
 * Handles interrupts coming from the PIO controller for the VBus pin
 */
static void ISR_VBus(const Pin *pPin) {
    if (PIO_Get(pPin)) {
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
    static const Pin pinVBus = PIN_USB_VBUS;

    TRACE_INFO("VBus configuration\n\r");

    PIO_Configure(&pinVBus, 1);
    PIO_ConfigureIt(&pinVBus, ISR_VBus);
    PIO_EnableIt(&pinVBus);

    ISR_VBus(&pinVBus);
#else
    USBD_Connect();
#endif
}

void UsbDataReceived(void *unused,
                     unsigned char status,
                     unsigned int received,
                     unsigned int remaining)
{
    // Check that data has been received successfully
    if (status == USBD_STATUS_SUCCESS) {

        TRACE_INFO("UsbDataReceived:\n\r[\n\r");
        for (unsigned int i = 0; i < received; i++) {
            TRACE_INFO("\t%c\n\r", usbBuffer[i]);
        }
        TRACE_INFO("]\n\r");

        UsbHandler(usbBuffer, received);

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


// Message format:
//   to address (1 byte)
//   command (1 byte)
//   data (0-5 bytes)
//   0xFF (message delimiter)
static message_t parse_usb_message(unsigned char message[], unsigned int length) {
    message_t msg = {
        .from     = ADDR_ERROR_RX,
        .to       = ADDR_ERROR_RX,
        .command  = CMD_NONE,
        .data     = {0},
        .data_len = 0
    };

    if (length > 1) {
        msg.from     = ADDR_COMMS_USB;
        msg.to       = message[0];
        msg.command  = message[1];
        msg.data_len = length - 2;

        for (unsigned int i = 0; i < (length - 2); i++) {
            msg.data[i] = message[i+2];
        }
    }

    return msg;
}

static void UsbHandler(const unsigned char data[], unsigned int length) {
    if (length > (BUFFER_LENGTH - current_char)) {
        TRACE_WARNING("Invalid USB message received.\n\r");
        current_char = 0;
    } else {
        memcpy(&message_buffer[current_char], data, length);
        current_char += length;
        if (data[length-1] == 0xFF) {
            usb_msg = parse_usb_message(message_buffer, current_char);
            if (usb_msg.command == CMD_NONE) {
                TRACE_WARNING("Invalid USB message received.\n\r");
            } else {
                TRACE_DEBUG(
                    "USB message received:" "\n\r"
                    "    to:      0x%2X" "\n\r"
                    "    command: 0x%2X" "\n\r"
                    "    data:         " "\n\r"
                    "             0x%2X" "\n\r"
                    "             0x%2X" "\n\r"
                    "             0x%2X" "\n\r"
                    "             0x%2X" "\n\r"
                    "             0x%2X" "\n\r"
                    "             0x%2X" "\n\r"
                    "             0x%2X" "\n\r"
                    "             0x%2X" "\n\r",
                    usb_msg.to, usb_msg.command,
                    usb_msg.data[0], usb_msg.data[1], usb_msg.data[2], usb_msg.data[3],
                    usb_msg.data[4], usb_msg.data[5], usb_msg.data[6], usb_msg.data[7]
                );
            }
            current_char = 0;
        }
    }
}
