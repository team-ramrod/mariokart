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
/// Definitions and methods for using a single external AT73C213 DAC. Several
/// constants must be declared at the board.h level for that:
/// - BOARD_AT73C213_SPI
/// - BOARD_AT73C213_SPI_ID 
/// - BOARD_AT73C213_NPCS
/// - BOARD_AT73C213_SSC
/// - BOARD_AT73C213_SSC_ID
///
/// !Usage
/// 
/// -# Configure the mode register of the SPI associated with the DAC and
///    enable the SPI peripheral (see spi.h).
/// -# Enable the master clock of the DAC (usually, it will be connected to
///    a programmable clock output).
/// -# Call the AT73C213_Enable function with the desired parameters. This
///    function configures the associated NPCS register of the SPI for correct
///    interfacing with the DAC, starts the DAC and configures the SSC.
/// -# Send audio data to the DAC using the SSC, with SSC_WriteBuffer or
///    SSC_Write.
//------------------------------------------------------------------------------

#ifndef AT73C213_H
#define AT73C213_H

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

// Master Clock Selector
#define AT73C213_MCK_SEL_256_FS 0
#define AT73C213_MCK_SEL_384_FS 1

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

extern void AT73C213_Enable(unsigned int Fs,
                            unsigned int sampleSize,
                            unsigned int numChannels,
                            unsigned char isClock384,
                            unsigned int masterClock);
extern void AT73C213_Disable();
extern void AT73C213_SetMuteStatus(unsigned char leftChannelMuted,
                                   unsigned char rightChannelMuted);

#endif //#ifndef AT73C213_H

