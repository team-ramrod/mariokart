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
/// Definition of AT91SAM7L-VB characteristics, AT91SAM7L-dependant PIOs and
/// external components interfacing.
/// 
/// !Usage
/// -# For operating frequency information, see "SAM7L-VB - Operating frequencies".
/// -# For using portable PIO definitions, see "SAM7L-VB - PIO definitions".
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
/// \page "SAM7L-VB - Board Description"
/// This page lists several definition related to the board description
///
/// !Definitions
/// - BOARD_NAME

/// Name of the board.
#define BOARD_NAME "AT91SAM7L-VB"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7l-VB - Operating frequencies"
/// This page lists several definition related to the board operating frequency
/// (when using the initialization done by board_lowlevel.c).
/// 
/// !Definitions
/// - BOARD_MAINOSC
/// - BOARD_MCK

/// Frequency of the board main oscillator.
#define BOARD_MAINOSC           18432000

/// Master clock frequency (when using board_lowlevel.c).
#define BOARD_MCK               (32768 * 915)
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
/// \page "SAM7L-VB - PIO definitions"
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
/// !USART
/// - PIN_USART0_RXD
/// - PIN_USART0_TXD
/// - PIN_USART0_SCK

/// DBGU pins (DTXD and DRXD) definitions.
#define PINS_DBGU   {0x00000600, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}

/// LED #0 pin definition.
#define PIN_LED_USR1   {1 << 7, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT}
/// LED #1 pin definition.
#define PIN_LED_USR2   {1 << 8, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT}
/// List of all led definitions.
#define PINS_LEDS   PIN_LED_USR1, PIN_LED_USR2

/// LED DS1 index.
#define LED_DS1      0
/// LED DS2 index.
#define LED_DS2      1

/// Push button #0 definition.
#define PIN_JOYSTICK_LEFT    {1 << 18, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #1 definition.
#define PIN_JOYSTICK_RIGHT   {1 << 22, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #2 definition
#define PIN_JOYSTICK_UP      {1 << 10, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #3 definition
#define PIN_JOYSTICK_DOWN    {1 << 11, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// Push button #4 definition
#define PIN_JOYSTICK_PUSH    {1 << 24, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
/// List of all push button definitions.
#define PINS_PUSHBUTTONS    PIN_JOYSTICK_LEFT, PIN_JOYSTICK_RIGHT, PIN_JOYSTICK_UP, PIN_JOYSTICK_DOWN, PIN_JOYSTICK_PUSH

/// Push button #1 index.
#define PUSHBUTTON_BP1   0
/// Push button #2 index.
#define PUSHBUTTON_BP2   1
/// Push button #3 index.
#define PUSHBUTTON_BP3   2

/// Push button #1 alias.
#define PIN_PUSHBUTTON_1 PIN_JOYSTICK_LEFT
/// Push button #2 alias.
#define PIN_PUSHBUTTON_2 PIN_JOYSTICK_RIGHT


/// USART0 TXD pin definition.
#define PIN_USART0_RXD  {1 << 12, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
/// USART0 RXD pin definition.
#define PIN_USART0_TXD  {1 << 13, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_A, PIO_DEFAULT}
/// SCK0 pin definition
#define PIN_USART0_SCK  {1 << 9, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_PERIPH_B, PIO_DEFAULT}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7L-VB - External components"
/// This page lists the definitions related to external on-board components
/// located in the board.h file for the AT91SAM7L-VB.
/// 
/// !IRDA
/// - PIN_IRDA_SD

/// IRDA transceiver shutdown pin definition.
#define PIN_IRDA_SD  {1 << 14, AT91C_BASE_PIOC, AT91C_ID_PIOC, PIO_OUTPUT_1, PIO_DEFAULT}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "SAM7L-VB- Individual chip definition"
/// This page lists the definitions related to different chip's definition
/// located in the board.h file for the SSAM7L-VB.

/// RTC
#define BOARD_RTC_ID                AT91C_ID_SYS
//------------------------------------------------------------------------------

#endif //#ifndef BOARD_H

