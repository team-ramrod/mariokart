/**
 * Board.h
 *
 * Board definitions file for mariokart PCBs
 *
 * All documentation and designs can be found at
 * https://github.com/Nemo157/mariokart/wiki and
 * https://github.com/Nemo157/mariokart
 *
 * Copyright (c) 2011 University of Canterbury.
 * All rights reserved.
 *
 *
 */

#ifndef BOARD_H
#define BOARD_H

/*************/
/*  Headers  */
/*************/

#include "at91sam7xc256/chip.h"
#include "at91sam7xc256/AT91SAM7XC256.h"

/*****************/
/*  Definitions  */
/*****************/


// Name of the board.
#define BOARD_NAME "mariokartv1"
// Board definition.
#define mariokartv1

// Frequency of the board main oscillator.
#define BOARD_MAINOSC           18432000

// Master clock frequency (when using board_lowlevel.c).
#define BOARD_MCK               48000000

// ADC clock frequency, at 10-bit resolution (in Hz)
#define ADC_MAX_CK_10BIT         5000000
// ADC clock frequency, at 8-bit resolution (in Hz)
#define ADC_MAX_CK_8BIT          8000000
// Startup time max, return from Idle mode (in �s)
#define ADC_STARTUP_TIME_MAX       20
// Track and hold Acquisition Time min (in ns)
#define ADC_TRACK_HOLD_TIME_MIN   600


// USB attributes configuration descriptor (bus or self powered, remote wakeup)
#define BOARD_USB_BMATTRIBUTES                  USBConfigurationDescriptor_BUSPOWERED_NORWAKEUP

/*
 * This pages lists all the pio definitions contained in board.h. The constants
 * are named using the following convention: PIN_* for a constant which defines
 * a single Pin instance (but may include several PIOs sharing the same
 * controller), and PINS_* for a list of Pin instances.
 */

#define AT91C_PIO_PB0_4 (AT91C_PIO_PB0|AT91C_PIO_PB1|AT91C_PIO_PB2|AT91C_PIO_PB3)
// Char Display Value pin definition.
#define PIN_CHAR_DISPLAY_VALUE        {AT91C_PIO_PB0_4, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
// Char Display A pin definition.
#define PIN_CHAR_DISPLAY_VALUE_A      {AT91C_PIO_PB0, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
// Char Display B pin definition.
#define PIN_CHAR_DISPLAY_VALUE_B      {AT91C_PIO_PB1, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
// Char Display C pin definition.
#define PIN_CHAR_DISPLAY_VALUE_C      {AT91C_PIO_PB2, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
// Char Display D pin definition.
#define PIN_CHAR_DISPLAY_VALUE_D      {AT91C_PIO_PB3, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
// Char Display Enable pin definition.
#define PIN_CHAR_DISPLAY_ENABLE       {AT91C_PIO_PB12, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
// Char Display Select Left pin definition.
#define PIN_CHAR_DISPLAY_SELECT_LEFT  {AT91C_PIO_PB7, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
// Char Display Select Right pin definition.
#define PIN_CHAR_DISPLAY_SELECT_RIGHT {AT91C_PIO_PB17, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}

#define PINS_CHAR_DISPLAY PIN_CHAR_DISPLAY_VALUE,PIN_CHAR_DISPLAY_SELECT_LEFT,PIN_CHAR_DISPLAY_SELECT_RIGHT

// Push button #0 definition.
#define PIN_PUSHBUTTON_0    {AT91C_PIO_PB17, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
// Push button #1 definition.
#define PIN_PUSHBUTTON_2    {AT91C_PIO_PB4, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
// Push button #2 definition
#define PIN_PUSHBUTTON_3    {AT91C_PIO_PA29, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
// Push button #3 definition.
#define PIN_PUSHBUTTON_4    {AT91C_PIO_PA22, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
// List of all push button definitions.
#define PINS_PUSHBUTTONS    PIN_PUSHBUTTON_1, PIN_PUSHBUTTON_2, PIN_PUSHBUTTON_3, PIN_PUSHBUTTON_4
// Push button #1 index.
#define PUSHBUTTON_BP1   0
// Push button #2 index.
#define PUSHBUTTON_BP2   1
// Push button #3 index.
#define PUSHBUTTON_BP3   2
// Push button #4 index.
#define PUSHBUTTON_BP4   3

// USART0 RXD pin definition.
#define PIN_USART0_RXD  {1 << 0, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
// USART0 TXD pin definition.
#define PIN_USART0_TXD  {1 << 1, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
// USART0 SCK pin definition. Removed as it is being used as GND for the uart
//#define PIN_USART0_SCK  {1 << 2, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
#define PIN_USART0_GND  {1 << 2, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_0, PIO_DEFAULT}
// USART0 RTS pin definition
#define PIN_USART0_RTS  {1 << 3, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
// USART0 CTS pin definition
#define PIN_USART0_CTS  {1 << 4, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

// USART1 RXD pin definition.
#define PIN_USART1_RXD  {1 << 5, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
// USART1 TXD pin definition.
#define PIN_USART1_TXD  {1 << 6, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
// USART1 SCK pin definition.
#define PIN_USART1_SCK  {1 << 7, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
// USART1 RTS pin definition
#define PIN_USART1_RTS  {1 << 8, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
// USART1 CTS pin definition
#define PIN_USART1_CTS  {1 << 9, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

// SPI0 MISO pin definition.
#define PIN_SPI0_MISO   {1 << 16, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
// SPI0 MOSI pin definition.
#define PIN_SPI0_MOSI   {1 << 17, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
// SPI0 SPCK pin definition.
#define PIN_SPI0_SPCK   {1 << 18, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
// List of SPI0 pin definitions (MISO, MOSI & SPCK).
#define PINS_SPI0       PIN_SPI0_MISO, PIN_SPI0_MOSI, PIN_SPI0_SPCK
// SPI0 chip select 0 pin definition.
#define PIN_SPI0_NPCS0  {1 << 12, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
// SPI0 chip select 1 pin definition.
#define PIN_SPI0_NPCS1  {1 << 13, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
// SPI0 chip select 2 pin definition.
#define PIN_SPI0_NPCS2  {1 << 14, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
// SPI0 chip select 3 pin definition.
#define PIN_SPI0_NPCS3  {1 << 15, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}

// SPI1 MISO pin definition.
#define PIN_SPI1_MISO   {1 << 24, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
// SPI1 MOSI pin definition.
#define PIN_SPI1_MOSI   {1 << 23, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
// SPI1 SPCK pin definition.
#define PIN_SPI1_SPCK   {1 << 22, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
// List of SPI1 pin definitions (MISO, MOSI & SPCK).
#define PINS_SPI1       PIN_SPI1_MISO, PIN_SPI1_MOSI, PIN_SPI1_SPCK
// SPI1 chip select 0 pin definition.
#define PIN_SPI1_NPCS0  {1 << 21, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
// SPI1 chip select 1 pin definition.
#define PIN_SPI1_NPCS1  {1 << 25, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}
// SPI1 chip select 2 pin definition.
#define PIN_SPI1_NPCS2  {1 << 26, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_PULLUP}

//potientiometer pin definitions
#define PIN_POT {1 << 7, AT91C_BASE_ADC, AT91C_ID_ADC, PIO_PERIPH_A, PIO_DEFAULT}

//encoder pin definitions
#define ENCODER_CLOCKWISE   {1 << 23, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_PULLUP}
#define ENCODER_ANTICLOCKWISE   {1 << 24, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_PULLUP}

//limit switch pins (note pins probably wrong
#define LIM_SW_UP {1 << 4, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
#define LIM_SW_DOWN {1 << 27, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}

//motor driver pins

// PWMC PWM0 pin definition.
#define PIN_PWMC_PWM0  {1 << 19, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
// PWMC PWM1 pin definition.
#define PIN_PWMC_PWM1  {1 << 20, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
// Over temp warning
#define PIN_DRIVER_OTW {1 << 13, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
// Motor driver error line
#define PIN_DRIVER_FAULT {1 << 6, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEGLITCH | PIO_PULLUP}
// driver reset pin 1
#define PIN_DRIVER_RESET1 {1 << 29, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_1, PIO_PULLUP}
// driver reset pin 2
#define PIN_DRIVER_RESET2 {1 << 5, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_1, PIO_PULLUP}

/* TODO: Re-define these to be used for motor-driver etc...

// PWMC PWM2 pin definition.
#define PIN_PWMC_PWM2  {1 << 21, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
// PWMC PWM3 pin definition.
#define PIN_PWMC_PWM3  {1 << 22, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}

// PWM pin definition for LED0
#define PIN_PWM_LED0 PIN_PWMC_PWM1
// PWM pin definition for LED1
#define PIN_PWM_LED1 PIN_PWMC_PWM2
// PWM channel for LED0
#define CHANNEL_PWM_LED0 1
// PWM channel for LED1
#define CHANNEL_PWM_LED1 2
*/

/* TODO: Do we need this? if not remove
// SSC transmitter pins definition.
#define PINS_SSC_TX { (1 << 21) | (1 << 22) | (1 << 23), \
                      AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_PERIPH_A, PIO_DEFAULT}
*/

/* TODO: Do we need this? if not remove
// TWI pins definition.
#define PINS_TWI  {0x00000C00, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
*/

/* TODO: One of these need to be set to Sensor_LA_Position
// ADC_AD0 pin definition.
#define PIN_ADC0_ADC0 {1 << 27, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEFAULT}
// ADC_AD1 pin definition.
#define PIN_ADC0_ADC1 {1 << 28, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEFAULT}
// ADC_AD2 pin definition.
#define PIN_ADC0_ADC2 {1 << 29, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEFAULT}
// ADC_AD3 pin definition.
#define PIN_ADC0_ADC3 {1 << 30, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_INPUT, PIO_DEFAULT}
// Pins ADC
#define PINS_ADC PIN_ADC0_ADC0, PIN_ADC0_ADC1, PIN_ADC0_ADC2, PIN_ADC0_ADC3
*/

// CAN Status LED #0 pin definition.
#define PIN_CAN_LED_0  {AT91C_PIO_PB10, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
// CAN Status LED #1 pin definition.
#define PIN_CAN_LED_1  {AT91C_PIO_PB11, AT91C_BASE_PIOB, AT91C_ID_PIOB, PIO_OUTPUT_0, PIO_DEFAULT}
// List of all LEDs pin definitions.
#define PINS_LEDS      PIN_CAN_LED_0, PIN_CAN_LED_1
// RS: Select input for high speed mode or silent mode
//#define PIN_CAN_TRANSCEIVER_RS  {1<<2, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_OUTPUT_1, PIO_DEFAULT}
// TXD: Transmit data input
#define PINS_CAN_TRANSCEIVER_TXD  {1<<20, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}
// RXD: Receive data output
#define PINS_CAN_TRANSCEIVER_RXD  {1<<19, AT91C_BASE_PIOA, AT91C_ID_PIOA, PIO_PERIPH_A, PIO_DEFAULT}

#endif //#ifndef BOARD_H

