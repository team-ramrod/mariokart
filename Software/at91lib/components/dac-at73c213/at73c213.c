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

#include "at73c213.h"
#include <board.h>
#include <spi/spi.h>
#include <ssc/ssc.h>
#include <utility/trace.h>

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------
/// \internal Calculates the SSC Transmit Clock Mode Register value given the
/// desired sample size (in bytes) and number of channels.
#define AT73C213_TCMR(sampleSize, numChannels) \
           (AT91C_SSC_CKS_DIV \
            | AT91C_SSC_CKO_DATA_TX \
            | AT91C_SSC_START_FALL_RF \
            | SSC_STTDLY(1) \
            | SSC_PERIOD(sampleSize * 8 * numChannels))

/// \internal Calculates the SSC Transmit Frame Mode Register value given the
/// desired sample size (in bytes) and number of channels.
#define AT73C213_TFMR(sampleSize, numChannels) \
           (SSC_DATLEN(sampleSize * 8) \
            | AT91C_SSC_MSBF \
            | SSC_DATNB(numChannels) \
            | SSC_FSLEN(sampleSize * 8) \
            | AT91C_SSC_FSOS_NEGATIVE)

/// \internal Maximum bitrate of AT73C213 SPI interface
#define AT73C213_SPCK_MAX           250000

/// \internal Calculates the SPI chip select configuration, given the system
/// master clock.
#define AT73C213_SPI_NPCSCONFIG(masterClock) \
            (AT91C_SPI_BITS_16 \
             | SPI_SCBR(AT73C213_SPCK_MAX, masterClock) \
             | SPI_DLYBS(50, masterClock) \
             | SPI_DLYBCT(0, masterClock))

// DAC user interface register addresses
/// \internal AT73C213 DAC control register address
#define AT73C213_DAC_CTRL           0x00
/// \internal AT73C213 DAC left line in gain register address
#define AT73C213_DAC_LLIG           0x01
/// \internal AT73C213 DAC right line in gain register address
#define AT73C213_DAC_RLIG           0x02
/// \internal AT73C213 DAC left master playback gain register address
#define AT73C213_DAC_LMPG           0x03
/// \internal AT73C213 DAC right master playback gain register address
#define AT73C213_DAC_RMPG           0x04
/// \internal AT73C213 DAC left line out gain register address
#define AT73C213_DAC_LLOG           0x05
/// \internal AT73C213 DAC right line out gain register address
#define AT73C213_DAC_RLOG           0x06
/// \internal AT73C213 DAC output level control register address
#define AT73C213_DAC_OLC            0x07
/// \internal AT73C213 DAC mixer control register address
#define AT73C213_DAC_MC             0x08
/// \internal AT73C213 DAC clock and sampling frequency control register address
#define AT73C213_DAC_CSFC           0x09
/// \internal AT73C213 DAC miscellaneous register address
#define AT73C213_DAC_MISC           0x0A
/// \internal AT73C213 DAC precharge control register address
#define AT73C213_DAC_PRECH          0x0C
/// \internal AT73C213 DAC auxiliary input gain control register address
#define AT73C213_DAC_AUXG           0x0D
/// \internal AT73C213 DAC reset register address
#define AT73C213_DAC_RST            0x10
/// \internal AT73C213 power amplifier control register address
#define AT73C213_PA_CTRL            0x11

// Register field values
// DAC_CTRL
/// \internal Left channel line in amplifier enable
#define AT73C213_DAC_CTRL_ONLNIL        (1 << 0)
/// \internal Right channel line in amplifier enable
#define AT73C213_DAC_CTRL_ONLNIR        (1 << 1)
/// \internal Left channel line out driver enable
#define AT73C213_DAC_CTRL_ONLNOL        (1 << 2)
/// \internal Right channel line out driver enable
#define AT73C213_DAC_CTRL_ONLNOR        (1 << 3)
/// \internal Left channel DAC enable
#define AT73C213_DAC_CTRL_ONDACL        (1 << 4)
/// \internal Right channel DAC enable
#define AT73C213_DAC_CTRL_ONDACR        (1 << 5)
/// \internal Differential mono auxiliary input amplifier enable
#define AT73C213_DAC_CTRL_ONAUXIN       (1 << 6)
/// \internal Differential mono power amplifier driver enable
#define AT73C213_DAC_CTRL_ONPADRV       (1 << 7)

// DAC_LLOG
/// \internal Digital gain of 0dB
#define AT73C213_DAC_LLOG_GAIN_0        0x00
/// \internal Digital gain of -10.5dB
#define AT73C213_DAC_LLOG_GAIN_10_5N    0x07
/// \internal Channel muted
#define AT73C213_DAC_LLOG_GAIN_MUTE     0x3F

// DAC_RLOG
/// \internal Digital gain of 0dB
#define AT73C213_DAC_RLOG_GAIN_0        0x00
/// \internal Digital gain of -10.5dB
#define AT73C213_DAC_RLOG_GAIN_10_5N    0x07
/// \internal Channel muted
#define AT73C213_DAC_RLOG_GAIN_MUTE     0x3F

// DAC_CSFC
/// \internal Master clock selector
#define AT73C213_DAC_CSFC_OVRSEL        (1 << 4)

// DAC_PRECH
/// \internal Master power on control
#define AT73C213_DAC_PRECH_ONMSTR       (1 << 0)
/// \internal Precharge all mask
#define AT73C213_DAC_PRECH_ALL          0xFE

// DAC_RST
/// \internal Active low reset of the audio codec
#define AT73C213_DAC_RST_RSTZ           (1 << 0)
/// \internal Active low reset of the audio codec filter
#define AT73C213_DAC_RST_RESFILZ        (1 << 1)
/// \internal Active high reset mask of the audio codec
#define AT73C213_DAC_RST_RESMASK        (1 << 2)

// PA_CTRL
/// \internal Audio power amplifier gain: -22dB
#define AT73C213_PA_CTRL_APAGAIN_22N    0xF
/// \internal Audio power amplifier gain: 8dB
#define AT73C213_PA_CTRL_APAGAIN_8      0x5
/// \internal Audio power amplifier gain: -1dB
#define AT73C213_PA_CTRL_APAGAIN_1N     0x8
/// \internal Audio power amplifier precharge bit
#define AT73C213_PA_CTRL_APAPRECH       (1 << 5)
/// \internal Audio power amplifier on bit
#define AT73C213_PA_CTRL_APAON          (1 << 6)

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Writes a byte of data at the given address of the DAC SPI user interface.
/// \param address  Register address to write.
/// \param data  New register value.
//------------------------------------------------------------------------------
void AT73C213_Write(unsigned char address, unsigned char data)
{
    SPI_Write(BOARD_AT73C213_SPI,
              BOARD_AT73C213_SPI_NPCS,
              ((address & 0x7F) << 8) | (data & 0xFF));
}

//------------------------------------------------------------------------------
/// Reads and returns a byte of data read at the given address of the DAC SPI
/// user interface.
/// \param address  Register address to read.
//------------------------------------------------------------------------------
unsigned char AT73C213_Read(unsigned char address)
{
    SPI_Write(BOARD_AT73C213_SPI,
              BOARD_AT73C213_SPI_NPCS,
              (1 << 15) | ((address & 0x7F) << 8));
    return SPI_Read(BOARD_AT73C213_SPI) & 0xFF;
}

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Enables the AT73C213 DAC to operate using the specified sample frequency (in
/// Hz), sample size (in bytes) and number of channels. If the master clock
/// sent to the DAC is equal to 384*Fs, then isClock384 must be 1; otherwise it
/// must be 0.
/// \param Fs  Desired sampling frequency in Hz.
/// \param sampleSize  Size of one sample in bytes.
/// \param numChannels  Number of audio channels used.
/// \param isClock384  Must be 1 if DACmck = 384*Fs, 0 if DACmck = 256*Fs.
/// \param masterClock  Frequency of the system master clock.
//------------------------------------------------------------------------------
void AT73C213_Enable(unsigned int  Fs,
                     unsigned int  sampleSize,
                     unsigned int  numChannels,
                     unsigned char isClock384,
                     unsigned int  masterClock)
{
    // Configure the SPI peripheral chip select
    SPI_ConfigureNPCS(BOARD_AT73C213_SPI,
                      BOARD_AT73C213_SPI_NPCS,
                      AT73C213_SPI_NPCSCONFIG(masterClock));

    // DAC startup sequence
    // De-assert reset
    AT73C213_Write(AT73C213_DAC_RST,
                   AT73C213_DAC_RST_RSTZ
                   | AT73C213_DAC_RST_RESFILZ);

    // Precharge and turn on master power
    AT73C213_Write(AT73C213_DAC_PRECH,
                   AT73C213_DAC_PRECH_ONMSTR
                   | AT73C213_DAC_PRECH_ALL);

    // Enable line out drivers
    AT73C213_Write(AT73C213_DAC_CTRL,
                   AT73C213_DAC_CTRL_ONLNOL
                   | AT73C213_DAC_CTRL_ONLNOR);

    // TODO 500 ms delay

    // Stop precharging
    AT73C213_Write(AT73C213_DAC_PRECH, AT73C213_DAC_PRECH_ONMSTR);

    // TODO 1ms delay

    // Enable DACs
    AT73C213_Write(AT73C213_DAC_CTRL,
                   AT73C213_DAC_CTRL_ONLNOL
                   | AT73C213_DAC_CTRL_ONLNOR
                   | AT73C213_DAC_CTRL_ONDACL
                   | AT73C213_DAC_CTRL_ONDACR);

    // Select master clock speed
    if (isClock384) {
    
        AT73C213_Write(AT73C213_DAC_CSFC, AT73C213_DAC_CSFC_OVRSEL);
    }

    // Output DAC register values
    unsigned int i;
    TRACE_DEBUG_WP("DAC register values:\n\r");
    for (i=0; i <= AT73C213_PA_CTRL; i++) {

        TRACE_DEBUG_WP(" - @0x%02X = 0x%02X\n\r", i, AT73C213_Read(i));
    }

    // Unmute channels
    AT73C213_SetMuteStatus(0, 0);

    // Configure the SSC
    SSC_Configure(BOARD_AT73C213_SSC,
                  BOARD_AT73C213_SSC_ID,
                  Fs * sampleSize * 8 * numChannels,
                  masterClock);
    SSC_ConfigureTransmitter(BOARD_AT73C213_SSC,
                             AT73C213_TCMR(sampleSize, numChannels),
                             AT73C213_TFMR(sampleSize, numChannels));
    SSC_EnableTransmitter(BOARD_AT73C213_SSC);
}

//------------------------------------------------------------------------------
/// Disables the AT73C213 DAC.
//------------------------------------------------------------------------------
void AT73C213_Disable()
{
    // Set gain to -22dB
    AT73C213_Write(AT73C213_PA_CTRL,
                   AT73C213_PA_CTRL_APAGAIN_22N |
                   AT73C213_PA_CTRL_APAON);

    // Turn off power amplifier
    AT73C213_Write(AT73C213_PA_CTRL, AT73C213_PA_CTRL_APAGAIN_22N);

    // Disable DACs
    AT73C213_Write(AT73C213_DAC_CTRL,
                   AT73C213_DAC_CTRL_ONLNOL
                   | AT73C213_DAC_CTRL_ONLNOR);

    // Disable master power
    AT73C213_Write(AT73C213_DAC_PRECH, 0);

    // TODO 1ms delay

    // Power off everything
    AT73C213_Write(AT73C213_DAC_CTRL, 0);
}

//------------------------------------------------------------------------------
/// Mutes or unmutes the left and/or right channel.
/// \param leftChannelMuted  Indicates the new status of the left audio channel.
/// \param rightChannelMuted  New status of the right audio channel.
//------------------------------------------------------------------------------
void AT73C213_SetMuteStatus(unsigned char leftChannelMuted,
                            unsigned char rightChannelMuted)
{
    // Update left channel status
    if (leftChannelMuted) {

        AT73C213_Write(AT73C213_DAC_LLOG, AT73C213_DAC_LLOG_GAIN_MUTE);
    }
    else {

        AT73C213_Write(AT73C213_DAC_LLOG, AT73C213_DAC_LLOG_GAIN_10_5N);
    }

    // Update right channel status
    if (rightChannelMuted) {

        AT73C213_Write(AT73C213_DAC_RLOG, AT73C213_DAC_RLOG_GAIN_MUTE);
    }
    else {

        AT73C213_Write(AT73C213_DAC_RLOG, AT73C213_DAC_RLOG_GAIN_10_5N);
    }
}

