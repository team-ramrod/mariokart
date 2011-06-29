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

/*
    Title: Board definitions

    About: Purpose
        Definitions for the AT91SAM9265-mistralRevB.
 */

#ifndef BOARD_H 
#define BOARD_H

#if defined(at91sam9265)
    #include "at91sam9265/chip.h"
    #include "at91sam9265/AT91SAM9265.h"
#else
    #error Board does not support the specified chip.
#endif

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "AT91SAM9265-EK - Board Description"
/// This page lists several definition related to the board description
///
/// !Definitions
/// - BOARD_NAME

/// Name of the board.
#define BOARD_NAME "AT91SAM9265-EK"
//------------------------------------------------------------------------------



// for compile only
#define AT91C_ID_TC0    (0)  // not used



//------------------------------------------------------------------------------
//         Clocks
//------------------------------------------------------------------------------
/*
    Constants: Operating frequencies
        BOARD_MAINOSC - Frequency of the board main oscillator.
        BOARD_MCK - Master clock frequency (when using board_lowlevel.c).
 */

//#define BOARD_MAINOSC           16367660
//#define BOARD_MCK               ((16367660*73/7)/2)// Output PLLA Clock (198,656 MHz)
#define BOARD_MCK      25000000  // SW22=ON  SW23=ON  ratio=4 RC1=2


//------------------------------------------------------------------------------
//         SDRAM Settings
//------------------------------------------------------------------------------
/*
    Constants: Operating frequencies
        BOARD_SDRAMC_CR - Configuration of the SDRAM Controller.
        BOARD_SDRAMC_TR - Refresh Timer Register.
 */
#define BOARD_SDRAMC_CR (\
				AT91C_SDRAMC_NC_9  | \
				AT91C_SDRAMC_NR_13 | \
				AT91C_SDRAMC_CAS_2 | \
				AT91C_SDRAMC_NB_4_BANKS | \
				AT91C_SDRAMC_DBW_32_BITS | \
				AT91C_SDRAMC_TWR_2 | \
				AT91C_SDRAMC_TRC_7 | \
				AT91C_SDRAMC_TRP_2 | \
				AT91C_SDRAMC_TRCD_2 | \
				AT91C_SDRAMC_TRAS_5 | \
				AT91C_SDRAMC_TXSR_8 )
#define BOARD_SDRAMC_TR (\
				(BOARD_MCK * 7)/1000000)

#define AT91C_EBI_SDRAM 0x20000000

//------------------------------------------------------------------------------
//         USB
//------------------------------------------------------------------------------
/// \page "MISTRALREVB - USB device"

#define BOARD_USB_BMATTRIBUTES USBConfigurationDescriptor_SELFPOWERED_NORWAKEUP

/// PMC is automatic
#define PMC_BY_HARD

//------------------------------------------------------------------------------
//         Pins
//------------------------------------------------------------------------------

/*
    Constants: SPI pins
        PIN_SPI - SPI pins (minus chip selects).
        PIN_SPI_NPCS1 - Chip select 1 pin.
*/
#define PIN_SPI0 {\
	AT91C_PA1_SPI0_MOSI | \
	AT91C_PA0_SPI0_MISO | \
	AT91C_PA2_SPI0_SPCK, \
	AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}	
#define PIN_SPI0_NPCS0 {AT91C_PA3_SPI0_NPCS0,  AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_SPI0_NPCS1 {AT91C_PC11_SPI0_NPCS1, AT91C_BASE_PIOC, AT91C_ID_PIOCDE, PIO_PERIPH_B, PIO_DEFAULT}
	
/*
    Constants: SSC pins
        PIN_SSC_TRANSMITTER - SSC pins for the transmitter.
*/
#define PIN_SSC_TRANSMITTER  {0x00038000, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

/*
    Constants: DBGU pins
        PINS_DBGU - List of all DBGU pin definitions (RXD PC30, TXD PC31).
*/
#define PINS_DBGU  {(AT91C_PC30_DRXD | AT91C_PC31_DTXD), AT91C_BASE_PIOC, AT91C_ID_PIOCDE, PIO_PERIPH_A, PIO_DEFAULT}

/*
    Constants: Pushbuttons pins
        PIN_PUSHBUTTON_L - Left click.
        PIN_PUSHBUTTON_R - Right click.
        PINS_PUSHBUTTONS - List of all pushbutton pin definitions.
*/
#define PIN_PUSHBUTTON_1  {1 << 4, AT91C_BASE_PIOC, AT91C_ID_PIOCDE, PIO_INPUT, PIO_PULLUP}
#define PIN_PUSHBUTTON_2  {1 << 5, AT91C_BASE_PIOC, AT91C_ID_PIOCDE, PIO_INPUT, PIO_PULLUP}
#define PINS_PUSHBUTTONS  PIN_PUSHBUTTON_1, PIN_PUSHBUTTON_2

/// Push button #1 index.
#define PUSHBUTTON_BP1   0
/// Push button #2 index.
#define PUSHBUTTON_BP2   1

/*
    Constants: LED pins
        PIN_LED_0    - LED #0 pin definition (PA9).
        PIN_POWERLED - LED #1 pin definition (PA6).
*/
#define PIN_LED_0    {1 << 29, AT91C_BASE_PIOC, AT91C_ID_PIOCDE, PIO_OUTPUT_0, PIO_DEFAULT}
#define PIN_LED_1    {1 << 8, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
#define PINS_LEDS  PIN_LED_0, PIN_LED_1

/// LED DS1 index.
#define LED_DS1      0
/// LED DS2 index.
#define LED_DS2      1

//------------------------------------------------------------------------------
//  Constants: USB pins
//      PIN_USB_VBUS - USB VBus monitoring pin definition.
//------------------------------------------------------------------------------
#define PIN_USB_VBUS {AT91C_PIO_PC13, AT91C_BASE_PIOC, AT91C_ID_PIOCDE, PIO_INPUT, PIO_DEFAULT}

/*
    Constants: SDRAM pins
        PINS_SDRAM - List of all SDRAM pins definitions.
*/
#define PINS_SDRAM  {0xFFFF0000, AT91C_BASE_PIOD, AT91C_ID_PIOCDE, PIO_PERIPH_A, PIO_DEFAULT}

/// Board SDRAM size
#define BOARD_SDRAM_SIZE   (128*1024*1024)  // 128 MB
/// SDRAM bus width.
#define BOARD_SDRAM_BUSWIDTH    32

/// Source type definition
#define AIC_SRCTYPE   0

#endif //#ifndef BOARD_H

