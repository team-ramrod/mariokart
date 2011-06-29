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

#undef TRACE_LEVEL
#define TRACE_LEVEL 0

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "ms5540b.h"
#include <spi/spi.h>
#include <utility/trace.h>
#include <utility/assert.h>

//------------------------------------------------------------------------------
//         Local definitions
//------------------------------------------------------------------------------

/// Baudrate divisor value.
#define SCBR                (0xFF << 8)

/// Command for retrieving calibration word 1.
#define CMD_WORD_1          /*0x0EA8*/ 0x1D50
/// Command for retrieving calibration word 2.
#define CMD_WORD_2          /*0x0EB0*/ 0x1D60
/// Command for retrieving calibration word 3.
#define CMD_WORD_3          /*0x0EC8*/ 0x1D90
/// Command for retrieving calibration word 4.
#define CMD_WORD_4          /*0x0ED0*/ 0x1DA0
/// Command for starting a pressure conversion.
#define CMD_PRES            0x0F40
/// Command for starting a temperature conversion.
#define CMD_TEMP            0x0F20

/// Driver is idle.
#define STATE_IDLE          0
/// Driver is performing a temperature conversion.
#define STATE_TEMP          1
/// Driver is performing a pressure conversion.
#define STATE_PRES          2

//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------

/// SPI peripheral used to connect to the MS5540B.
static AT91S_SPI *lpSpi;

/// Chip select configured for the sensor.
static unsigned int lCs;

/// Calibration coefficients.
static unsigned short lCoeffs[6];

/// Current driver state.
static unsigned char lState;

/// Last temperature measurement made.
static unsigned short lD2 = 0;

//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Reads & returns the result of the last command.
//------------------------------------------------------------------------------
unsigned short Fetch(void)
{
    unsigned short result;

    // Configure SPI to receive the first 8 data bytes
    SPI_ConfigureNPCS(lpSpi, lCs, AT91C_SPI_BITS_8 | SCBR);

    // Read the first 8 bytes
    SPI_Write(lpSpi, lCs, 0);
    while (!SPI_IsFinished(lpSpi));
    result = (SPI_Read(lpSpi) & 0xFF) << 8;

    // Configure SPI to receive the next 8 bytes (with one dummy byte)
    SPI_ConfigureNPCS(lpSpi, lCs, AT91C_SPI_BITS_9 | SCBR);

    // Read the last 8 bytes
    SPI_Write(lpSpi, lCs, 0);
    while (!SPI_IsFinished(lpSpi));
    result |= (SPI_Read(lpSpi) >> 1) & 0xFF;

    TRACE_DEBUG("MS5540B_Fetch: Result = %d\n\r", result);

    return result;
}

//------------------------------------------------------------------------------
/// Resets the sensor.
//------------------------------------------------------------------------------
static void Reset()
{
    const unsigned short pCommand[] = {0x00AA, 0x1540};

    SANITY_CHECK(SPI_IsFinished(lpSpi));

    TRACE_DEBUG("MS5540B_Reset()\n\r");

    // Configure chip select for 8 bits transfer
    SPI_ConfigureNPCS(lpSpi, lCs, AT91C_SPI_NCPHA | AT91C_SPI_BITS_8 | SCBR);

    // Transfer first 8 bits
    SPI_Write(lpSpi, lCs, pCommand[0]);
    while (!SPI_IsFinished(lpSpi));

    // Configure chip select for 13 bits transfer
    SPI_ConfigureNPCS(lpSpi, lCs, AT91C_SPI_NCPHA | AT91C_SPI_BITS_13 | SCBR);

    // Transfer remaining 13 bits
    SPI_Write(lpSpi, lCs, pCommand[1]);
    while (!SPI_IsFinished(lpSpi));
}

//------------------------------------------------------------------------------
/// Reads and returns a calibration word from the sensor.
/// \param cmd  Command to retrieve desired word (CMD_WORD_1 ... CMD_WORD_4).
//------------------------------------------------------------------------------
static unsigned short ReadCalibrationWord(unsigned short cmd)
{
    TRACE_DEBUG("MS5540B_ReadCalibrationWord(0x%04X)\n\r", cmd);

    SANITY_CHECK((cmd == CMD_WORD_1)
                 || (cmd == CMD_WORD_2)
                 || (cmd == CMD_WORD_3)
                 || (cmd == CMD_WORD_4));
    SANITY_CHECK(SPI_IsFinished(lpSpi));

    // Configure SPI to send the command
    SPI_ConfigureNPCS(lpSpi, lCs, AT91C_SPI_NCPHA | AT91C_SPI_BITS_13 | SCBR);

    // Transfer command
    SPI_Write(lpSpi, lCs, cmd);
    while (!SPI_IsFinished(lpSpi));

    // Read & return result
    return Fetch();
}

//------------------------------------------------------------------------------
//         Global functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Initializes a MS5540B sensor. The provided SPI peripheral is configured
/// for the sensor (using the given chip select), and the calibration data
/// is extracted.
/// The sensor MUST BE CLOCKED before calling this function. It can then be
/// unclocked in-between measurements.
/// In addition, the SPI peripheral must be configured properly prior to calling
/// this function.
/// \param pSpi  Pointer to the SPI peripheral connected to the MS5540B.
/// \param cs  Chip select value to use.
//------------------------------------------------------------------------------
void MS5540B_Initialize(AT91S_SPI *pSpi, unsigned char cs)
{
    unsigned short word1, word2, word3, word4;

    SANITY_CHECK(pSpi);

    TRACE_DEBUG("MS5540B_Initialize(0x%08X, %d)\n\r", pSpi, cs);

    // Store SPI information
    lpSpi = pSpi;
    lCs = cs;
    lState = STATE_IDLE;

    // Reset the sensor
    Reset();

    // Extract calibration data from the sensor
    word1 = ReadCalibrationWord(CMD_WORD_1);
    word2 = ReadCalibrationWord(CMD_WORD_2);
    word3 = ReadCalibrationWord(CMD_WORD_3);
    word4 = ReadCalibrationWord(CMD_WORD_4);

    TRACE_DEBUG("Word1 = %d\n\r", word1);
    TRACE_DEBUG("Word2 = %d\n\r", word2);
    TRACE_DEBUG("Word3 = %d\n\r", word3);
    TRACE_DEBUG("Word4 = %d\n\r", word4);

    // Compute coefficients
    lCoeffs[0] = (word1 >> 1) & 0x7FFF;
    lCoeffs[1] = (word4 & 0x003F) | ((word3 & 0x003F) << 6);
    lCoeffs[2] = (word4 >> 6) & 0x03FF;
    lCoeffs[3] = (word3 >> 6) & 0x03FF;
    lCoeffs[4] = ((word2 >> 6) | ((word1 & 0x0001) << 10)) & 0x07FF;
    lCoeffs[5] = word2 & 0x003F;

    TRACE_DEBUG("C1 = %d\n\r", lCoeffs[0]);
    TRACE_DEBUG("C2 = %d\n\r", lCoeffs[1]);
    TRACE_DEBUG("C3 = %d\n\r", lCoeffs[2]);
    TRACE_DEBUG("C4 = %d\n\r", lCoeffs[3]);
    TRACE_DEBUG("C5 = %d\n\r", lCoeffs[4]);
    TRACE_DEBUG("C6 = %d\n\r", lCoeffs[5]);
}

//------------------------------------------------------------------------------
/// Starts a temperature acquisition. This function returns as soon as the
/// command has been sent.
/// The conversion must be completed by calling MS5540B_ConversionFinished()
/// whenever the device signals the end-of-conversion.
//------------------------------------------------------------------------------
void MS5540B_AcquireTemperature(void)
{
    SANITY_CHECK(lState == STATE_IDLE);

    TRACE_DEBUG("MS5540B_AcquireTemperature()\n\r");

    // Configure SPI for 12 bits transfers
    SPI_ConfigureNPCS(lpSpi, lCs, AT91C_SPI_NCPHA | AT91C_SPI_BITS_12 | AT91C_SPI_CSAAT | SCBR);

    // Send command
    SPI_Write(lpSpi, lCs, CMD_TEMP);
    while (!SPI_IsFinished(lpSpi));

    // Update driver state
    lState = STATE_TEMP;
}

//------------------------------------------------------------------------------
/// Starts a pressure acquisition. This function returns as soon as the
/// command has been sent.
/// The conversion must be completed by calling MS5540B_ConversionFinished()
/// whenever the device signals the end-of-conversion.
/// A temperature measurement must have been performed prior to calling this
/// function.
//------------------------------------------------------------------------------
void MS5540B_AcquirePressure(void)
{
    SANITY_CHECK(lState == STATE_IDLE);
    SANITY_CHECK(lD2 != 0);

    TRACE_DEBUG("MS5540B_AcquirePressure()\n\r");

    // Configure SPI for 12 bits transfers
    SPI_ConfigureNPCS(lpSpi, lCs, AT91C_SPI_NCPHA | AT91C_SPI_BITS_12 | AT91C_SPI_CSAAT | SCBR);

    // Send command
    SPI_Write(lpSpi, lCs, CMD_PRES);
    while (!SPI_IsFinished(lpSpi));

    // Update driver state
    lState = STATE_PRES;
}

//------------------------------------------------------------------------------
/// Fetches and returns the result of the last conversion from the sensor. This
/// function must only be called whenever the MS5540B signals that the
/// conversion is completed with the DOUT signal line.
/// The temperature returned is 10*C° (e.g. 31.4°C -> 314).
//------------------------------------------------------------------------------
unsigned short MS5540B_ConversionFinished(void)
{
    signed short result;
    signed short dT;
    unsigned short offset, sensitivity, x;

    SANITY_CHECK((lState == STATE_TEMP) || (lState == STATE_PRES));

    TRACE_DEBUG("MS5540B_ConversionFinished()\n\r");

    // Retrieve conversion result
    result = (signed short) Fetch();

    // Correct result using calibration data
    if (lState == STATE_TEMP) {

        lD2 = result;
        dT = result - 8 * lCoeffs[4] - 20224;
        result = 200 +  dT * (lCoeffs[5] + 50) / 1024;
        TRACE_DEBUG("D2 = %d\n\r", lD2);
        TRACE_DEBUG("dT = %d\n\r", dT);
        TRACE_DEBUG("TEMP = %d\n\r", result);
    }
    else {

        TRACE_DEBUG("D1 = %d\n\r", result);
        dT = lD2 - 8 * lCoeffs[4] - 20224;
        offset = lCoeffs[1] * 4 + ((lCoeffs[3] - 512) * dT) / 4096;
        sensitivity = lCoeffs[0] + (lCoeffs[2] * dT) / 1024 + 24576;
        x = (sensitivity * (result - 7168)) / 16384 - offset;
        result = x * 10 / 32 + 2500;
        TRACE_DEBUG("dT = %d\n\r", dT);
        TRACE_DEBUG("OFF = %d\n\r", offset);
        TRACE_DEBUG("SENS = %d\n\r", sensitivity);
        TRACE_DEBUG("X = %d\n\r", x);
        TRACE_DEBUG("P = %d\n\r", result);
    }

    // Update driver state
    lState = STATE_IDLE;

    return result;
}

