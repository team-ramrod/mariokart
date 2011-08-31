/* ----------------------------------------------------------------------------
 *          Mariokart project
 * ----------------------------------------------------------------------------
 *  Copyright (c) 2011, University of Canterbury
 */

#ifndef SWITCHES_H
#define SWITCHES_H

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include <board.h>
#include <pio/pio.h>
#include <stdbool.h>

//------------------------------------------------------------------------------
//         Global Definitions
//------------------------------------------------------------------------------
#define SWITCHES_NUMBER_OF 4

//------------------------------------------------------------------------------
//         Global Macros
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Exported variables
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Global Functions
//------------------------------------------------------------------------------
/**
 * Setup a interrupt callback on a switch
 *
 * @param switch number between zero and SWITCHES_NUMBER_OF
 * @param interrupt handler
 */
void switches_init_interupt(unsigned int switch_no, void (*handler)(const Pin *));

/**
 * Get the current switch position
 * 
 * @param switch number between zero and SWITCHES_NUMBER_OF
 * @return true for pressed
 */
bool switches_pressed(unsigned int switch_no);

/**
 * Initialise all the switches as inputs that can have PIO calls on them
 */
void switches_init(void);

#endif //#ifndef SWITCHES_H

