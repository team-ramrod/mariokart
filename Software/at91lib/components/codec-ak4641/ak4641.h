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

#ifndef AK4641_H
#define AK4641_H

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

/*! Calculates the SSC Transmit Clock Mode Register value given the desired
    \a sampleSize (in bytes) and \a numChannels */
#define AK4641_TCMR(sampleSize, numChannels) \
           (0x02 /* LibV3 constant is not valid */ \
            | AT91C_SSC_CKO_NONE \
            | AT91C_SSC_START_FALL_RF \
            | SSC_STTDLY(1) \
            | SSC_PERIOD(sampleSize * 8 * numChannels))

/*! Calculates the SSC Transmit Frame Mode Register value given the desired
    \a sampleSize (in bytes) and \a numChannels */
#define AK4641_TFMR(sampleSize, numChannels) \
           (SSC_DATLEN(sampleSize * 8) \
            | AT91C_SSC_MSBF \
            | SSC_DATNB(numChannels) \
            | SSC_FSLEN(sampleSize * 8) \
            | AT91C_SSC_FSOS_NEGATIVE)

/*! Calculates the SSC Received Clock Mode Register value given the desired
    \a sampleSize (in bytes) and \a numChannels */
#define AK4641_RCMR(sampleSize, numChannels) \
            (AT91C_SSC_CKS_TK \
             | AT91C_SSC_CKO_NONE \
             | AT91C_SSC_CKI \
             | AT91C_SSC_START_TX \
             | SSC_STTDLY(1) \
             | SSC_PERIOD(sampleSize * 8 * numChannels))

/*! Calculates the SSC Receive Frame Mode Register value given the desired
    \a sampleSize (in bytes) and \a numChannels. */
#define AK4641_RFMR(sampleSize, numChannels) \
            (SSC_DATLEN(sampleSize *8) \
             | AT91C_SSC_MSBF \
             | SSC_DATNB(numChannels) \
             | SSC_FSLEN(sampleSize * 8) \
             | AT91C_SSC_FSOS_NEGATIVE)

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
      
extern inline void AK4641_Configure(AT91S_TWI *twi);
extern inline void AK4641_SetMuted(AT91S_TWI *twi, unsigned char muted);

#endif //#ifndef AK4641_H

