/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the disclaimer below in the documentation and/or
 * other materials provided with the distribution.
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
/// Definition and functions for using AT91CAP7 related features, such
/// as PIO pins, memories, etc.
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
/// Definition of AT91CAP7-DK characteristics, AT91CAP7 dependant PIOs and
/// external components interfacing.
///
/// !Usage
/// -# For operating frequency information, see "AT91CAP7-DK - Operating frequencies".
/// -# For using portable PIO definitions, see "AT91CAP7-DK - PIO definitions".
/// -# Several USB definitions are included here (see "AT91CAP7-DK - USB device").
/// -# For external components definitions, see "AT91CAP7-DK - External components".
/// -# For memory-related definitions, see "AT91CAP7-DK - Memories".
//------------------------------------------------------------------------------

#ifndef BOARD_H
#define BOARD_H

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#if defined(at91cap7)
    #include "at91cap7/chip.h"
    #include "at91cap7/at91cap7.h"
#else
    #error Board does not support the specified chip.
#endif

#include "fpga.h"

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "AT91CAP7-DK - Board Description"
/// This page lists several definition related to the board description
///
/// !Definitions
/// - BOARD_NAME

/// Name of the board.
#define BOARD_NAME "AT91CAP7-DK"

/// Board definition.
#define at91cap7dk

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "AT91CAP7-DK - Operating frequencies"
/// This page lists several definition related to the board operating frequency
/// (when using the initialization done by board_lowlevel.c).
///
/// !Definitions
/// - BOARD_MAINOSC
/// - BOARD_MCK

/// Frequency of the board main oscillator.
#define BOARD_MAINOSC           12000000

/// Master clock frequency (when using board_lowlevel.c).
#define BOARD_MCK               ((12000000 * 8 / 1) / 2)

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "AT91CAP7-DK - USB device"
/// This page lists constants describing several characteristics (controller
/// type, D+ pull-up type, etc.) of the USB device controller of the chip/board.
///
/// !Constants
/// - BOARD_USB_UDP
/// - BOARD_USB_PULLUP_MATRIX
/// - BOARD_USB_NUMENDPOINTS
/// - BOARD_USB_ENDPOINTS_MAXPACKETSIZE
/// - BOARD_USB_ENDPOINTS_BANKS
/// - BOARD_USB_BMATTRIBUTES

/// Chip has a UDP controller.
#define BOARD_USB_UDP

/// Indicates the D+ pull-up is always connected.
#define BOARD_USB_PULLUP_MATRIX

/// Number of endpoints in the USB controller.
#define BOARD_USB_NUMENDPOINTS                  6

/// Returns the maximum packet size of the given endpoint.
#define BOARD_USB_ENDPOINTS_MAXPACKETSIZE(i)    ((((i) == 4) || ((i) == 5)) ? 256 : (((i) == 0) ? 8 : 64))

/// Returns the number of FIFO banks for the given endpoint.
#define BOARD_USB_ENDPOINTS_BANKS(i)            ((((i) == 0) || ((i) == 3)) ? 1 : 2)

/// USB attributes configuration descriptor (bus or self powered, remote wakeup)
#define BOARD_USB_BMATTRIBUTES USBConfigurationDescriptor_SELFPOWERED_NORWAKEUP

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "AT91CAP7-DK - PIO definitions"
/// This pages lists all the pio definitions contained in board.h. The constants
/// are named using the following convention: PIN_* for a constant which defines
/// a single Pin instance (but may include several PIOs sharing the same
/// controller), and PINS_* for a list of Pin instances.
///
/// !DBGU
/// - PINS_DBGU
///
/// !USART0
/// - PIN_USART0_RXD
/// - PIN_USART0_TXD
/// - PIN_USART0_SCK
///
/// !SPI
/// - PIN_SPI_MISO
/// - PIN_SPI_MOSI
/// - PIN_SPI_SPCK
/// - PINS_SPI
/// - PIN_SPI_NPCS0
/// - PIN_SPI_NPCS1

/// List of all DBGU pin definitions.
#define PINS_DBGU   {(1<<0)|(1<<1), AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}

/// USART0 SCK pin definition.
#define PIN_USART0_SCK  {AT91C_PIO_PA2, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/// USART0 RTS pin definition
#define PIN_USART0_RTS  {AT91C_PIO_PA3, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/// USART0 CTS pin definition
#define PIN_USART0_CTS  {AT91C_PIO_PA4, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/// USART0 TXD pin definition.
#define PIN_USART0_TXD  {AT91C_PIO_PA5, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/// USART0 RXD pin definition.
#define PIN_USART0_RXD  {AT91C_PIO_PA6, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}

/// SPI MISO pin definition.
#define PIN_SPI_MISO  {AT91C_PIO_PA7, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/// SPI MOSI pin definition.
#define PIN_SPI_MOSI  {AT91C_PIO_PA8, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/// SPI SPCK pin definition.
#define PIN_SPI_SPCK  {AT91C_PIO_PA9, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/// List of SPI pin definitions (MISO, MOSI & SPCK).
#define PINS_SPI      PIN_SPI_MISO, PIN_SPI_MOSI, PIN_SPI_SPCK
/// SPI chip select 0 pin definition.
#define PIN_SPI_NPCS0 {AT91C_PIO_PA10, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}
/// SPI chip select 1 pin definition.
#define PIN_SPI_NPCS1 {AT91C_PIO_PA11, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_B, PIO_DEFAULT}

//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "AT91CAP7-DK - Memories"
/// This page lists definitions related to external on-board memories.
///
/// !AT26 Serial Flash
/// - BOARD_AT26_A_SPI_BASE
/// - BOARD_AT26_A_SPI_ID
/// - BOARD_AT26_A_SPI_PINS
/// - BOARD_AT26_A_SPI
/// - BOARD_AT26_A_NPCS
/// - BOARD_AT26_A_NPCS_PIN
///
/// !SDRAM
/// - BOARD_SDRAM_SIZE
/// - PINS_SDRAM
/// - BOARD_SDRAM_BUSWIDTH
///
/// !Nandflash
/// - PINS_NANDFLASH
/// - BOARD_NF_EBI_COMMAND_ADDR
/// - BOARD_NF_EBI_ADDRESS_ADDR
/// - BOARD_NF_EBI_DATA_ADDR
/// - BOARD_NF_CE_PIN
/// - BOARD_NF_RB_PIN
///
/// !NorFlash
/// - BOARD_NORFLASH_ADDR

#define BOARD_AT26F004

/// Base address of SPI peripheral connected to the serialflash.
#define BOARD_AT26_A_SPI_BASE         AT91C_BASE_SPI
/// Identifier of SPI peripheral connected to the serialflash.
#define BOARD_AT26_A_SPI_ID           AT91C_ID_SPI
/// Pins of the SPI peripheral connected to the serialflash.
#define BOARD_AT26_A_SPI_PINS         PINS_SPI
/// Serialflash SPI number.
#define BOARD_AT26_A_SPI              0
/// Chip select connected to the serialflash.
#define BOARD_AT26_A_NPCS             0
/// Chip select pin connected to the serialflash.
#define BOARD_AT26_A_NPCS_PIN         PIN_SPI_NPCS0

/// Board SDRAM size
#define BOARD_SDRAM_SIZE        (64*1024*1024)  // with AT91CAP-MEM33 extension
/// List of all SDRAM pins definitions.
#define PINS_SDRAM              {0xFFFF0000, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/// SDRAM bus width.
#define BOARD_SDRAM_BUSWIDTH    32

/// Nandflash controller peripheral pins definition.
#define PINS_NANDFLASH         BOARD_NF_OE_PIN, BOARD_NF_WE_PIN
/// Nandflash output enable pin definition.
#define BOARD_NF_OE_PIN        {1 << 5, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/// Nandflash write enable pin definition
#define BOARD_NF_WE_PIN        {1 << 6, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
/// Nandflash chip enable pin definition.
#define BOARD_NF_CE_PIN        {0, 0, 0, 0, 0}
/// Nandflash ready/busy pin definition.
#define BOARD_NF_RB_PIN        {0, 0, 0, 0, 0}// Not used on the DK board. Use Read Status Register Command
/// Address for transferring command bytes to the nandflash.
#define BOARD_NF_COMMAND_ADDR  0x40400000
/// Address for transferring address bytes to the nandflash.
#define BOARD_NF_ADDRESS_ADDR  0x40200000
/// Address for transferring data bytes to the nandflash.
#define BOARD_NF_DATA_ADDR     0x40000000

/// Address for transferring command bytes to the norflash.
#define BOARD_NORFLASH_ADDR  0x10000000


//------------------------------------------------------------------------------
//    Constants: Operating frequencies
//        AT91C_AIC_SRCTYPE_INT - Interrupt triggering mode.
//------------------------------------------------------------------------------

#if defined(at91cap7)
#define AT91C_AIC_SRCTYPE_INT  AT91C_AIC_SRCTYPE_INT_LEVEL_SENSITIVE
#else
    #error Board does not support the specified chip.
#endif

//------------------------------------------------------------------------------
/// \page "AT91CAP7-DK - Individual chip definition"
/// This page lists the definitions related to different chip's definition
/// located in the board.h file for the AT91CAP7-DK

/// USART
#define BOARD_PIN_USART_RXD        PIN_USART0_RXD
#define BOARD_PIN_USART_TXD        PIN_USART0_TXD
#define BOARD_PIN_USART_CTS        PIN_USART0_CTS
#define BOARD_PIN_USART_RTS        PIN_USART0_RTS
#define BOARD_USART_BASE           AT91C_BASE_US0
#define BOARD_ID_USART             AT91C_ID_US0

//------------------------------------------------------------------------------

#endif //#ifndef BOARD_H



















