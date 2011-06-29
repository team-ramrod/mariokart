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
//         Headers
//------------------------------------------------------------------------------

#include <chip.h>
#include <board.h>
#include <dbgu/dbgu.h>
#include <twi/twi.h>
#include "ak4641.h"

//------------------------------------------------------------------------------
//         Internal definitions
//------------------------------------------------------------------------------

// 5-bit address of an AK4641 component on the TWI interface
#define AK4641_SLAVEADDRESS         0x12

// Register addresses
// Power management 1 register address
#define AK4641_POWMGT1              0x00
// Power management 2 register address
#define AK4641_POWMGT2              0x01
// Signal select 2 register address
#define AK4641_SIGSEL2              0x03
// DAC control register address
#define AK4641_DACCTRL              0x06
// MIC control register address
#define AK4641_MICCTRL              0x07

// Register field values
// Power management 1 register
// Powers up the ADC block of the stereo CODEC
#define AK4641_POWMGT1_PMADC        (1 << 0)
// Powers up the MIC in block of the stereo CODEC
#define AK4641_POWMGT1_PMMIC        (1 << 1)
// Powers up the AUX in block of the stereo CODEC
#define AK4641_POWMGT1_PMAUX        (1 << 2)
// Powers up the Mont out block of the stereo CODEC
#define AK4641_POWMGT1_PMMO         (1 << 3)
// Powers up the Line out block of the stereo CODEC
#define AK4641_POWMGT1_PMLO         (1 << 4)
// Powers up the VCOM block of the stereo DEOC
#define AK4641_POWMGT1_PMVCM        (1 << 7)

// Power management 2 register
// Powers up the DAC block of the stereo CODEC
#define AK4641_POWMGT2_PMDAC        (1 << 0)
// Powers up the Mono out 2 block of the stereo CODEC
#define AK4641_POWMGT2_PMMO2        (1 << 3)
// Sets the master clock input mode to AC-coupling
#define AK4641_POWMGT2_MCKAC        (1 << 4)
// Disables the master clock input buffer control
#define AK4641_POWMGT2_MCKPD        (1 << 7)

// Signal select 2 register
// Selects the right channel line output
#define AK4641_SIGSEL2_PSLOR        (1 << 0)
// Selects the left channel line output
#define AK4641_SIGSEL2_PSLOL        (1 << 1)
// Selects AUX single-ended output
#define AK4641_SIGSEL2_AUXSI        (1 << 2)
// Sets MIC in as the line out mixer output
#define AK4641_SIGSEL2_MICL         (1 << 4)
// Sets AUX in as the line out mixer output
#define AK4641_SIGSEL2_AUXL         (1 << 5)
// Sets the DAC as the line out mixer output
#define AK4641_SIGSEL2_DACL         (1 << 7)

// DAC control register
// De-emphasis filter for a 44.1kHz sample rate
#define AK4641_DACCTRL_DEM44_1      0
// Disables the de-emphasis filter
#define AK4641_DACCTRL_DEMDIS       1
// De-emphasis filter for a 48kHz sample rate
#define AK4641_DACCTRL_DEM48        2
// De-emphasis filter for a 32kHz sample rate
#define AK4641_DACCTRL_DEM32        3
// Attenuator level for left & right channels controlled by the ATTL6-0 bits
#define AK4641_DACCTRL_DATTC        (1 << 4)
// Soft-mutes the DAC
#define AK4641_DACCTRL_SMUTE        (1 << 5)
// Sets the soft mute time setting to 256/Fs
#define AK4641_DACCTRL_TM           (1 << 6)

// MIC control register
// Enables the 20dB gain on the microphone input
#define AK4641_MICCTRL_MGAIN        (1 << 0)
// Select the microphone as the ADC input
#define AK4641_MICCTRL_MICAD        (1 << 2)
// Enables the power supply input for the internal microphone
#define AK4641_MICCTRL_MPWRI        (1 << 3)

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------
/*!
    Reads data (using the given \a twi peripheral) from an AK4146 starting with
    a particular \a registerAddress and stores it in the provided \a buffer.
    Data is read until the buffer is filled to its \a bufferSize.

    This function returns true if the read operation was successful; otherwise
    it returns false.
 */
inline unsigned char AK4641_Read(AT91S_TWI *twi,
                                 void *buffer,
                                 unsigned int bufferSize,
                                 unsigned char registerAddress)
{
    return TWI_Read(twi,
                    buffer,
                    bufferSize,
                    AK4641_SLAVEADDRESS,
                    registerAddress,
                    1);
}

/*!
    Writes (through a \a twi interface) the content of the provided \a buffer
    in the registers of an AK4641 component, starting at the specified
    \a registerAddress.

    This function returns true if the write operation was successful; otherwise
    it returns false.
 */
inline unsigned char AK4641_Write(AT91S_TWI *twi,
                                  void *buffer,
                                  unsigned int bufferSize,
                                  unsigned char registerAddress)
{
    return TWI_Write(twi,
                     buffer,
                     bufferSize,
                     AK4641_SLAVEADDRESS,
                     registerAddress,
                     1);
}

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
/*!
    Configures an external AK4641 component, through the specified \a twi
    interface.

    The TWI interface and the AK4641 master clock must both be already
    configured properly before calling this method.
 */
inline void AK4641_Configure(AT91S_TWI *twi)
{
    unsigned char value;
    unsigned char values[20];

    // Power up the ADC and VCOM blocks
    value = AK4641_POWMGT1_PMADC | AK4641_POWMGT1_PMVCM;
    AK4641_Write(twi, &value, 1, AK4641_POWMGT1);

    // Power up the DAC
    value = AK4641_POWMGT2_PMDAC;
    AK4641_Write(twi, &value, 1, AK4641_POWMGT2);
    
    // Select the right and left channel outputs, enable the DAC output
    value = AK4641_SIGSEL2_PSLOR | AK4641_SIGSEL2_PSLOL | AK4641_SIGSEL2_DACL;
    AK4641_Write(twi, &value, 1, AK4641_SIGSEL2);

    // Disable the de-emphasis filter
    value = AK4641_DACCTRL_DEMDIS;// | AK4641_DACCTRL_SMUTE;
    AK4641_Write(twi, &value, 1, AK4641_DACCTRL);

    // Enable the MIC 20dB gain and the internal MIC power supply
    value = AK4641_MICCTRL_MGAIN | AK4641_MICCTRL_MICAD | AK4641_MICCTRL_MPWRI;
    AK4641_Write(twi, &value, 1, AK4641_MICCTRL);

    // Power up the Line out and Mic blocks
    value = AK4641_POWMGT1_PMMIC | AK4641_POWMGT1_PMADC
            | AK4641_POWMGT1_PMVCM | AK4641_POWMGT1_PMLO;
    AK4641_Write(twi, &value, 1, AK4641_POWMGT1);
}

/*!
    Mutes or unmutes an external AK4641 component connected to the given \a twi
    peripheral, depending on the value of the \a muted parameter.
 */
inline void AK4641_SetMuted(AT91S_TWI *twi, unsigned char muted)
{
    if (muted) {

        unsigned char value = AK4641_DACCTRL_DEMDIS | AK4641_DACCTRL_SMUTE;
        AK4641_Write(twi, &value, 1, AK4641_DACCTRL);
    }
    else {

        unsigned char value = AK4641_DACCTRL_DEMDIS;
        AK4641_Write(twi, &value, 1, AK4641_DACCTRL);
    }
}

