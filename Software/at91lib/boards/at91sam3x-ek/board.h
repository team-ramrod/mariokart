/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

//------------------------------------------------------------------------------
/// \dir
/// !Purpose
/// 
/// Definition and functions for using AT91SAM3X-related features, such
/// has PIO pins, memories, etc.
/// 
/// !Usage
/// -# The code for booting the board is provided by board_cstartup.S and
///    board_lowlevel.c.
/// -# For using board PIOs, board characteristics (clock, etc.) and external
///    components, see board.h.
/// -# For manipulating memories (remapping, SDRAM, etc.), see board_memories.h.
//------------------------------------------------------------------------------
 
//------------------------------------------------------------------------------
/// \unit
/// !Purpose
/// 
/// Definition of AT91SAM3X-EK characteristics, AT91SAM3X-dependant PIOs and
/// external components interfacing.
/// 
/// !Usage
/// -# For operating frequency information, see "SAM3X-EK - Operating frequencies".
/// -# For using portable PIO definitions, see "SAM3X-EK - PIO definitions".
/// -# Several USB definitions are included here (see "SAM3X-EK - USB device").
//------------------------------------------------------------------------------

#ifndef BOARD_H 
#define BOARD_H

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#if defined(at91sam3x2)
    #include "at91sam3x2/at91sam3x2.h"
#elif defined(at91sam3x4)
    #include "at91sam3x4/at91sam3x4.h"
#elif defined(at91sam3x8)
    #include "at91sam3x8/at91sam3x8.h"
#else
    #error Board does not support the specified chip.
#endif

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM3X-EK - Board Description"
/// This page lists several definition related to the board description.
///
/// !Definitions
/// - BOARD_NAME

/// Name of the board.
#define BOARD_NAME "AT91SAM3X-EK"
/// Board definition.
#define at91sam3xek
/// Family definition (already defined).
#define at91sam3x
/// Core definition
#define cortexm3
// Chip type
#define fpgasimulation
//------------------------------------------------------------------------------

#if defined(fpgasimulation)
#define PMC_BY_HARD
#endif

//------------------------------------------------------------------------------
/// \page "SAM3X-EK - Operating frequencies"
/// This page lists several definition related to the board operating frequency
/// (when using the initialization done by board_lowlevel.c).
/// 
/// !Definitions
/// - BOARD_MAINOSC
/// - BOARD_MCK

/// Frequency of the board main oscillator.
#define BOARD_MAINOSC           12000000

/// Master clock frequency (when using board_lowlevel.c).
#if !defined(fpgasimulation)
#define BOARD_MCK               48000000
#else
#define BOARD_MCK               22579200
#endif

#if defined (fpgasimulation)
//#define BOARD_ConfigureSdram(...) { }
#endif // fpgasimulation
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM3X-EK - USB device"
/// 
/// !Constants
/// - BOARD_USB_BMATTRIBUTES

/// USB attributes configuration descriptor (bus or self powered, remote wakeup)
#define BOARD_USB_BMATTRIBUTES   USBConfigurationDescriptor_SELFPOWERED_RWAKEUP
//#define BOARD_USB_BMATTRIBUTES USBConfigurationDescriptor_SELFPOWERED_NORWAKEUP
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM3X-EK - PIO definitions"
/// This pages lists all the pio definitions contained in board.h. The constants
/// are named using the following convention: PIN_* for a constant which defines
/// a single Pin instance (but may include several PIOs sharing the same
/// controller), and PINS_* for a list of Pin instances.
///  
/// !DBGU
/// - PINS_DBGU
/// 
/// !LEDs
/// - PIN_LED_DS1
/// - PIN_LED_DS2
/// - PIN_LED_DS3
/// - PIN_LED_DS4
/// - PINS_LEDS
/// - LED_DS1
/// - LED_DS2
/// - LED_DS3
/// - LED_DS4
///
/// !Push buttons
/// - PIN_PUSHBUTTON_1
/// - PIN_PUSHBUTTON_2
/// - PIN_PUSHBUTTON_3
/// - PIN_PUSHBUTTON_4
/// - PINS_PUSHBUTTONS
/// - PUSHBUTTON_BP1
/// - PUSHBUTTON_BP2 
/// - PUSHBUTTON_BP3
/// - PUSHBUTTON_BP4
///
/// !Joystick buttons
/// - PIN_JOYSTICK_UP
/// - PIN_JOYSTICK_DOWN
/// - PIN_JOYSTICK_LEFT
/// - PIN_JOYSTICK_RIGHT
/// - PIN_JOYSTICK_LCLIC, PIN_JOYSTICK_PUSH
/// - PINS_JOYSTICK_MOVE, PINS_JOYSTICK_CLIC, PINS_JOYSTICK
/// - JOYSTICK_UP
/// - JOYSTICK_DOWN
/// - JOYSTICK_LEFT
/// - JOYSTICK_RIGHT
/// - JOYSTICK_LCLIC, JOYSTICK_PUSH
///
/// !USART0
/// - PIN_USART0_RXD
/// - PIN_USART0_TXD
/// - PIN_USART0_SCK
/// 
/// !SPI0
/// - PIN_SPI0_MISO
/// - PIN_SPI0_MOSI
/// - PIN_SPI0_SPCK
/// - PINS_SPI0
/// - PIN_SPI0_NPCS3
/// 
/// !SPI1
/// - PIN_SPI1_MISO
/// - PIN_SPI1_MOSI
/// - PIN_SPI1_SPCK
/// - PINS_SPI1
/// - PIN_SPI1_NPCS3
///
/// !PWMC
/// - PIN_PWMC_PWM0
/// - PIN_PWMC_PWM1
/// - PIN_PWMC_PWM2
/// - PIN_PWMC_PWM3
/// - PIN_PWMC_PWM4
/// - PIN_PWMC_PWM5
/// - PIN_PWMC_PWM6
/// - PIN_PWMC_PWM7
/// - PIN_PWM_LED0
/// - PIN_PWM_LED1
/// - CHANNEL_PWM_LED0
/// - CHANNEL_PWM_LED1
/// 
/// !USB
/// - PIN_USB_PULLUP
///
/// !TWI
/// - PINS_TWI
///
/// !MCI
/// - PINS_MCI
///
/// !CAN
/// - PIN_CAN_TRANSCEIVER_RS
/// - PIN_CAN1_TRANSCEIVER_TXD
/// - PIN_CAN1_TRANSCEIVER_RXD
/// - PIN_CAN2_TRANSCEIVER_TXD
/// - PIN_CAN2_TRANSCEIVER_RXD
/// - PINS_CAN_TRANSCEIVER_TXD
/// - PINS_CAN_TRANSCEIVER_RXD

/// DBGU pins (DTXD and DRXD) definitions, PA11,12.
#define PINS_DBGU  {0x00001800, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

/// Push button #0 definition.
#define PIN_PUSHBUTTON_1    {1 << 3, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #1 definition.
#define PIN_PUSHBUTTON_2    {1 << 4, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #2 definition
/// List of all push button definitions.
#define PINS_PUSHBUTTONS    PIN_PUSHBUTTON_1, PIN_PUSHBUTTON_2

/// Push button #1 index.
#define PUSHBUTTON_BP1   0
/// Push button #2 index.
#define PUSHBUTTON_BP2   1

/// USB VBus monitoring pin definition.
#define PIN_USB_VBUS    {1 << 5, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEFAULT}

/// SPI0 MISO pin definition.
//#define PIN_SPI0_MISO   {1 << 15, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
///// SPI0 MOSI pin definition.
//#define PIN_SPI0_MOSI   {1 << 16, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
///// SPI0 SPCK pin definition.
//#define PIN_SPI0_SPCK   {1 << 17, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
///// List of SPI0 pin definitions (MISO, MOSI & SPCK).
//#define PINS_SPI0       PIN_SPI0_MISO, PIN_SPI0_MOSI, PIN_SPI0_SPCK 
///// SPI0 chip select 2 pin definition.
//#define PIN_SPI0_NPCS2  {1 << 14, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
///// SPI0 chip select 3 pin definition.
//#define PIN_SPI0_NPCS3  {1 << 14, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
//
///// SPI1 MISO pin definition.
//#define PIN_SPI1_MISO   {1 << 8, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_PULLUP}
///// SPI1 MOSI pin definition.
//#define PIN_SPI1_MOSI   {1 << 9, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
///// SPI1 SPCK pin definition.
//#define PIN_SPI1_SPCK   {1 << 10, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
///// List of SPI1 pin definitions (MISO, MOSI & SPCK).
//#define PINS_SPI1       PIN_SPI1_MISO, PIN_SPI1_MOSI, PIN_SPI1_SPCK
///// SPI1 chip select 3 pin definition.
//#define PIN_SPI1_NPCS3  {1 << 7, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
//
/// Enable ADS7843 support
//#define BOARD_TSC_ADS7843
//#define PIN_ADS7843_BUSY    {1 << 1, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_PULLUP}
//#define PIN_ADS7843_IRQ     {1 << 2, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_PULLUP}
///// Touchscreen controller IRQ pin definition.
//#define PIN_TCS_IRQ         PIN_ADS7843_IRQ
///// Touchscreen controller Busy pin definition.
//#define PIN_TCS_BUSY        PIN_ADS7843_BUSY
///// Base address of SPI peripheral connected to the touchscreen controller.
//#define BOARD_TSC_SPI_BASE         AT91C_BASE_SPI0
///// Identifier of SPI peripheral connected to the touchscreen controller.
//#define BOARD_TSC_SPI_ID           AT91C_ID_SPI0
///// Pins of the SPI peripheral connected to the touchscreen controller.
//#define BOARD_TSC_SPI_PINS         PINS_SPI0
///// Touchscreen controller SPI number.
//#define BOARD_TSC_SPI              0
///// Chip select connected to the touchscreen controller.
//#define BOARD_TSC_NPCS             2
///// Chip select pin connected to the touchscreen controller.
//#define BOARD_TSC_NPCS_PIN         PIN_SPI0_NPCS2

/// TWI pins definition.
//#define PINS_TWI  {0x00000003, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

///// MCI pins definition.
////#define PINS_MCI  {0x0003F000, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
//#define PINS_MCI  {0x003f0000, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}



/// CAN Definition
/// RS: Select input for high speed mode or silent mode
//#define PIN_CAN_TRANSCEIVER_RS  {1<<23, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}
//
///// TXD: Transmit data input
//#define PIN_CAN1_TRANSCEIVER_TXD  {1<<27, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
///// RXD: Receive data output
//#define PIN_CAN1_TRANSCEIVER_RXD  {1<<26, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/// TXD: Transmit data input
//#define PIN_CAN2_TRANSCEIVER_TXD  {1<<29, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
///// RXD: Receive data output
//#define PIN_CAN2_TRANSCEIVER_RXD  {1<<28, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
///// TXD pins
//#define PINS_CAN_TRANSCEIVER_TXD  PIN_CAN1_TRANSCEIVER_TXD, PIN_CAN2_TRANSCEIVER_TXD
///// RXD pins
//#define PINS_CAN_TRANSCEIVER_RXD  PIN_CAN1_TRANSCEIVER_RXD, PIN_CAN2_TRANSCEIVER_RXD
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM3X-EK - External components"
/// This page lists the definitions related to external on-board components
/// located in the board.h file for the AT91SAM3X-EK.
/// 
/// !AT45 Dataflash Card
/// - BOARD_AT45_A_SPI_BASE
/// - BOARD_AT45_A_SPI_ID
/// - BOARD_AT45_A_SPI_PINS
/// - BOARD_AT45_A_SPI
/// - BOARD_AT45_A_NPCS
/// - BOARD_AT45_A_NPCS_PIN
///
/// !AT45 Dataflash (serial onboard DataFlash)
/// - BOARD_AT45_B_SPI_BASE
/// - BOARD_AT45_B_SPI_ID
/// - BOARD_AT45_B_SPI_PINS
/// - BOARD_AT45_B_SPI
/// - BOARD_AT45_B_NPCS
/// - BOARD_AT45_B_NPCS_PIN
///
/// !AT26 Serial Flash
/// - BOARD_AT26_A_SPI_BASE
/// - BOARD_AT26_A_SPI_ID
/// - BOARD_AT26_A_SPI_PINS
/// - BOARD_AT26_A_SPI
/// - BOARD_AT26_A_NPCS
/// - BOARD_AT26_A_NPCS_PIN
///
/// !SD Card
/// - BOARD_SD_MCI_BASE
/// - BOARD_SD_MCI_ID
/// - BOARD_SD_PINS
/// - BOARD_SD_SLOT

/// Base address of SPI peripheral connected to the dataflash.
//#define BOARD_AT45_A_SPI_BASE         AT91C_BASE_SPI0
///// Identifier of SPI peripheral connected to the dataflash.
//#define BOARD_AT45_A_SPI_ID           AT91C_ID_SPI0
///// Pins of the SPI peripheral connected to the dataflash.
//#define BOARD_AT45_A_SPI_PINS         PINS_SPI0
///// Dataflahs SPI number.
//#define BOARD_AT45_A_SPI              0
///// Chip select connected to the dataflash.
//#define BOARD_AT45_A_NPCS             3
///// Chip select pin connected to the dataflash.
//#define BOARD_AT45_A_NPCS_PIN         PIN_SPI0_NPCS3

/// Base address of SPI peripheral connected to the dataflash.
//#define BOARD_AT45_B_SPI_BASE         AT91C_BASE_SPI1
///// Identifier of SPI peripheral connected to the dataflash.
//#define BOARD_AT45_B_SPI_ID           AT91C_ID_SPI1
///// Pins of the SPI peripheral connected to the dataflash.
//#define BOARD_AT45_B_SPI_PINS         PINS_SPI1
///// Dataflahs SPI number.
//#define BOARD_AT45_B_SPI              1
///// Chip select connected to the dataflash.
//#define BOARD_AT45_B_NPCS             3
///// Chip select pin connected to the dataflash.
//#define BOARD_AT45_B_NPCS_PIN         PIN_SPI1_NPCS3

/// Base address of SPI peripheral connected to the serialflash.
//#define BOARD_AT26_A_SPI_BASE         AT91C_BASE_SPI0
///// Identifier of SPI peripheral connected to the serialflash.
//#define BOARD_AT26_A_SPI_ID           AT91C_ID_SPI0
///// Pins of the SPI peripheral connected to the serialflash.
//#define BOARD_AT26_A_SPI_PINS         PINS_SPI0
///// Serialflash SPI number.
//#define BOARD_AT26_A_SPI              0
///// Chip select connected to the serialflash.
//#define BOARD_AT26_A_NPCS             3
///// Chip select pin connected to the serialflash.
//#define BOARD_AT26_A_NPCS_PIN         PIN_SPI0_NPCS3

/// Base address of the MCI peripheral connected to the SD card.
//#define BOARD_SD_MCI_BASE           AT91C_BASE_MCI0//AT91C_BASE_MCI
///// Peripheral identifier of the MCI connected to the SD card.
//#define BOARD_SD_MCI_ID             AT91C_ID_MCI0 //AT91C_ID_MCI
///// MCI pins that shall be configured to access the SD card.
//#define BOARD_SD_PINS               PINS_MCI
///// MCI slot to which the SD card is connected to.
//#define BOARD_SD_SLOT               MCI_SD_SLOTA
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM3X-EK - Memories"
/// This page lists definitions related to internal & external on-board memories.
/// 
/// Indicates chip has an Enhanced EFC.
#define BOARD_FLASH_EEFC
//------------------------------------------------------------------------------

//#if defined (AT91C_IFLASH0)
#define AT91C_IFLASH                  AT91C_IFLASH0
#define AT91C_IFLASH_SIZE             AT91C_IFLASH0_SIZE
#define AT91C_IFLASH_PAGE_SIZE        AT91C_IFLASH0_PAGE_SIZE
#define AT91C_IFLASH_LOCK_REGION_SIZE AT91C_IFLASH0_LOCK_REGION_SIZE
#define AT91C_IFLASH_NB_OF_PAGES      AT91C_IFLASH0_NB_OF_PAGES
#define AT91C_IFLASH_NB_OF_LOCK_BITS  AT91C_IFLASH0_NB_OF_LOCK_BITS
//#endif


//------------------------------------------------------------------------------
/// \page "SAM3X-EK - External components"
/// This page lists the definitions related to external on-board components
/// located in the board.h file for the SAM3X-EK.
/// 
/// !ISO7816
/// - PIN_SMARTCARD_CONNECT
/// - PIN_ISO7816_RSTMC
/// - PINS_ISO7816

/// Smartcard detection pin
//#define PIN_SMARTCARD_CONNECT   {1 << 5, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEFAULT}
/// PIN used for reset the smartcard
//#define PIN_ISO7816_RSTMC       {1 << 7, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
/// Pins used for connect the smartcard
//#define PINS_ISO7816            PIN_USART0_TXD, PIN_USART0_SCK, PIN_ISO7816_RSTMC
//------------------------------------------------------------------------------

#endif //#ifndef BOARD_H

