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
/// Definition and functions for using AT91SAM7L-related features, such
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
/// Definition of AT91SAM7L-STK characteristics, AT91SAM7L-dependant PIOs and
/// external components interfacing.
/// 
/// !Usage
/// -# For operating frequency information, see "SAM7L-STK - Operating frequencies".
/// -# For using portable PIO definitions, see "SAM7L-STK - PIO definitions".
//------------------------------------------------------------------------------

#ifndef BOARD_H 
#define BOARD_H

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#if defined(at91sam7l64)
    #include "at91sam7l64/chip.h"
    #include "at91sam7l64/AT91SAM7L64.h"
#elif defined(at91sam7l128)
    #include "at91sam7l128/chip.h"
    #include "at91sam7l128/AT91SAM7L128.h"
#else
    #error Board does not support the specified chip.
#endif

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7L-STK - Board Description"
/// This page lists several definition related to the board description
///
/// !Definitions
/// - BOARD_NAME

/// Name of the board.
#define BOARD_NAME              "AT91SAM7L-STK"
/// Board definition.
#define at91sam7lstk
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7L-STK - Operating frequencies"
/// This page lists several definition related to the board operating frequency
/// (when using the initialization done by board_lowlevel.c).
/// 
/// !Definitions
/// - BOARD_MCK

/// Master clock frequency (when using board_lowlevel.c).
#define BOARD_MCK               (32768 * 915)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7L-STK - PIO definitions"
/// This pages lists all the pio definitions contained in board.h. The constants
/// are named using the following convention: PIN_* for a constant which defines
/// a single Pin instance (but may include several PIOs sharing the same
/// controller), and PINS_* for a list of Pin instances.
///  
/// !PCK
/// - PIN_PCK0
/// 
/// !DBGU
/// - PINS_DBGU
///
/// !Push buttons
/// - PIN_PUSHBUTTON_1
/// - PIN_PUSHBUTTON_2
/// - PIN_PUSHBUTTON_3
/// - PIN_PUSHBUTTON_4
/// - PIN_PUSHBUTTON_5
/// - PINS_PUSHBUTTONS
/// - PUSHBUTTON_BP1
/// - PUSHBUTTON_BP2
/// - PUSHBUTTON_BP3
/// - PUSHBUTTON_BP4
/// - PUSHBUTTON_BP5
/// 
/// !SPI
/// - PIN_SPI_MOSI
/// - PIN_SPI_MISO
/// - PIN_SPI_SPCK
/// - PIN_SPI_NPCS3
/// - PINS_SPI
/// 
/// !USB
/// - PIN_USB_VBUS
/// - PIN_USB_PULLUP
///
/// !PWMC
/// - PIN_PWMC_PWM0
/// - PIN_PWMC_PWM1
/// - PIN_PWMC_PWM2
/// - PIN_PWM_LED0
/// - PIN_PWM_LED1
/// - CHANNEL_PWM_LED0
/// - CHANNEL_PWM_LED1
///
/// !TWI
/// - PINS_TWI

/// PCK0 pin definition.
#define PIN_PCK0  {1 << 23, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}

/// DBGU pins (DTXD and DRXD) definitions.
#define PINS_DBGU   {0x00030000, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}

/// Push button #1 pin definition
#define PIN_PUSHBUTTON_1 {1 << 0, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #2 pin definition
#define PIN_PUSHBUTTON_2 {1 << 1, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #3 pin definition
#define PIN_PUSHBUTTON_3 {1 << 2, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #4 pin definition
#define PIN_PUSHBUTTON_4 {1 << 3, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #5 pin definition
#define PIN_PUSHBUTTON_5 {1 << 4, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// List of all pushbuttons definitions.
#define PINS_PUSHBUTTONS PIN_PUSHBUTTON_1, PIN_PUSHBUTTON_2, PIN_PUSHBUTTON_3, PIN_PUSHBUTTON_4, PIN_PUSHBUTTON_5
/// Pushbutton #1 index.
#define PUSHBUTTON_BP1   0
/// Pushbutton #2 index.
#define PUSHBUTTON_BP2   1
/// Pushbutton #3 index.
#define PUSHBUTTON_BP3   2
/// Pushbutton #4 index.
#define PUSHBUTTON_BP4   3
/// Pushbutton #5 index.
#define PUSHBUTTON_BP5   4

/// SPI MISO pin definition.
#define PIN_SPI_MISO  {1 << 19, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
/// SPI MOSI pin definition.
#define PIN_SPI_MOSI  {1 << 20, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
/// SPI SPCK pin definition.
#define PIN_SPI_SPCK  {1 << 21, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
/// SPI NPCS0 pin definition.
#define PIN_SPI_NPCS0 {1 << 18, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
/// SPI NPCS3 pin definition.
#define PIN_SPI_NPCS3 {1 << 22, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
/// List of SPI pin definitions (does not include NPCS pins).
#define PINS_SPI      PIN_SPI_MISO, PIN_SPI_MOSI, PIN_SPI_SPCK

/// PWMC PWM0 pin definition.
#define PIN_PWMC_PWM0  {1 << 7, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
/// PWMC PWM1 pin definition.
#define PIN_PWMC_PWM1  {1 << 8, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
/// PWMC PWM2 pin definition.
#define PIN_PWMC_PWM2  {1 << 9, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}

/// PWM pin definition for LED0
#define PIN_PWM_LED0 PIN_PWMC_PWM1
/// PWM pin definition for LED1
#define PIN_PWM_LED1 PIN_PWMC_PWM2
/// PWM channel for LED0
#define CHANNEL_PWM_LED0 1
/// PWM channel for LED1
#define CHANNEL_PWM_LED1 2

/// TWI pins definition.
#define PINS_TWI  {0x00000C00, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
//------------------------------------------------------------------------------

/// MAX3318E pin definition for setting the /FORCEOFF input of the transceiver to 0
#define BOARD_MAX3318E_ENABLE_FORCEOFF {1 << 7, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT}
/// MAX3318E pin definition for setting the /FORCEOFF input of the transceiver to 1.
#define BOARD_MAX3318E_DISABLE_FORCEOFF {1 << 7, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT}
/// MAX3318E pin definition for setting the FORCEON input of the transceiver to 0.
#define BOARD_MAX3318E_DISABLE_FORCEON {1 << 12, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_OUTPUT_0, PIO_DEFAULT}
/// MAX3318E pin definition  to disable pull-ups on /INVALID and READY.
#define BOARD_MAX3318E_DISABLE_PULLUPS {(1 << 13) | (1 << 14), AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEFAULT}

//------------------------------------------------------------------------------
/// \page "SAM7L-STK - Memories"
/// This page lists definitions related to internal & external on-board memories.
/// 
/// !Embedded Flash
/// - BOARD_FLASH_EEFC
/// - BOARD_FLASH_IAP_ADDRESS

/// Indicates chip has an Enhanced EFC.
#define BOARD_FLASH_EEFC
/// Address of the IAP function in ROM.
#define BOARD_FLASH_IAP_ADDRESS         0x400008
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7L-STK- Individual chip definition"
/// This page lists the definitions related to different chip's definition
/// located in the board.h file for the SSAM7L-STK.

/// RTC
#define BOARD_RTC_ID                AT91C_ID_SYS

/// Twi eeprom
#define BOARD_ID_TWI_EEPROM         AT91C_ID_TWI
#define BOARD_BASE_TWI_EEPROM       AT91C_BASE_TWI
#define BOARD_PINS_TWI_EEPROM       PINS_TWI
//------------------------------------------------------------------------------

#endif //#ifndef BOARD_H

