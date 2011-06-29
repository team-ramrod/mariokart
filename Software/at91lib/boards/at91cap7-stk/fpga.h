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

#ifndef FPGA_H
#define FPGA_H


//------------------------------------------------------------------------------
//     Definitions - PIOA connection to FPGA I/Os.  
//     This fpga.h file is used in conjuction with the verilog (*.v) file for 
//     FPGA interface I/O conneciton.
//------------------------------------------------------------------------------


/************/
/*  LEDs    */
/************/

/// LED #0 pin definition.
    #define PIN_LED_DS1   {1 << 10, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_1, PIO_DEFAULT}

/// LED #1 pin definition.
    #define PIN_LED_DS2   {1 << 11, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_1, PIO_DEFAULT}



    #define PINS_LEDS   PIN_LED_DS1, PIN_LED_DS2    //, PIN_LED_DS3, PIN_LED_DS4, PIN_LED_DS5, PIN_LED_DS6, PIN_LED_DS7



/// LED DS1 index.
    #define LED_DS1      0

/// LED DS2 index.
    #define LED_DS2      1



/********************/
/*  Push Buttons    */
/********************/


/// Push button #0 definition.
    #define PIN_PUSHBUTTON_1    {1 << 8, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}

/// Push button #1 definition.
    #define PIN_PUSHBUTTON_2    {1 << 9, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}



/// List of all push button definitions.


   #define PINS_PUSHBUTTONS    PIN_PUSHBUTTON_1, PIN_PUSHBUTTON_2  // , PIN_PUSHBUTTON_3, PIN_PUSHBUTTON_4
   

/// Push button #0 index.
    #define PUSHBUTTON_BP1   0

/// Push button #1 index.
    #define PUSHBUTTON_BP2   1


/// Push button #2 index.
/// #define PUSHBUTTON_BP3   2

/// Push button #3 index.
/// #define PUSHBUTTON_BP4   3


/***********************/
/*  Joystick control   */
/***********************/

// Joystick UP.
#define PIN_JOYSTICK_UP    {1 << 20, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
// Joystick DOWN.
#define PIN_JOYSTICK_DOWN  {1 << 23, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
// Joystick LEFT.
#define PIN_JOYSTICK_LEFT  {1 << 22, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
// Joystick RIGHT.
#define PIN_JOYSTICK_RIGHT {1 << 21, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
// Joystick LEFT clic.
#define PIN_JOYSTICK_LCLIC {1 << 24, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_PULLUP}
// Joystick PUSH button.
#define PIN_JOYSTICK_PUSH  PIN_JOYSTICK_LCLIC
// List of all Joystick click definitions
#define PINS_JOYSTICK_CLIC  PIN_JOYSTICK_LCLIC
// List of all Joystick movement direction definitions
#define PINS_JOYSTICK_MOVE  PIN_JOYSTICK_UP, PIN_JOYSTICK_DOWN, \
                            PIN_JOYSTICK_LEFT, PIN_JOYSTICK_RIGHT
// List of all Joystick definitions
#define PINS_JOYSTICK  PINS_JOYSTICK_MOVE, \
                       PINS_JOYSTICK_CLIC
// Joystick UP index.
#define JOYSTICK_UP         0
// Joystick DOWN index.
#define JOYSTICK_DOWN       1
// Joystick LEFT index.
#define JOYSTICK_LEFT       2
// Joystick RIGHT index.
#define JOYSTICK_RIGHT      3
// Joystick LEFT CLICK index.
#define JOYSTICK_LCLIC      4
// Joystick PUSH button index.
#define JOYSTICK_PUSH       4


#endif  //#ifndef FPGA_H








