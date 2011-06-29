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

#include <board.h>
#include <adc/adc12.h>
#include <utility/trace.h>
#include <utility/assert.h>



//------------------------------------------------------------------------------
//         Global Functions
//------------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/// Initialize the ADC controller
/// \param pAdc Pointer to an AT91S_ADC instance.
/// \param trgEn trigger mode, software or Hardware
/// \param trgSel hardware trigger selection
/// \param sleepMode sleep mode selection
/// \param resolution resolution selection 8 bits or 10 bits
/// \param mckClock value of MCK in Hz
/// \param adcClock value of the ADC clock in Hz
/// \param startupTime value of the start up time (in us) (see datasheet)
/// \param sampleAndHoldTime (in ns)
//-----------------------------------------------------------------------------
void ADC12_Initialize (AT91S_ADC12B *pAdc,
                     unsigned char idAdc,
                     unsigned char trgEn,
                     unsigned char trgSel,
                     unsigned char sleepMode,
                     unsigned char resolution,        
                     unsigned int mckClock,
                     unsigned int adcClock,
                     unsigned int startupTime,
                     unsigned int sampleAndHoldTime)
{
    unsigned int prescal;
    unsigned int startup;
    unsigned int shtim;

    ASSERT(startupTime<=ADC_STARTUP_TIME_MAX, "ADC Bad startupTime\n\r");
    ASSERT(sampleAndHoldTime>=ADC_TRACK_HOLD_TIME_MIN, "ADC Bad sampleAndHoldTime\n\r");

    // Example:
    // 5 MHz operation, 20�s startup time, 600ns track and hold time
    // PRESCAL: Prescaler Rate Selection ADCClock = MCK / ( (PRESCAL+1) * 2 )
    // PRESCAL = [MCK / (ADCClock * 2)] -1 = [48/(5*2)]-1 = 3,8
    // PRESCAL =  4 -> 48/((4+1)*2) = 48/10 = 4.8MHz
    // 48/((3+1)*2) = 48/8 = 6MHz
    // Startup Time = (STARTUP+1) * 8 / ADCClock
    // STARTUP = [(Startup Time * ADCClock)/8]-1 = [(20 10e-6 * 5000000)/8]-1 = 11,5
    // STARTUP = 11 -> (11+1)*8/48000000 = 96/4800000 = 20us
    //
    // Sample & Hold Time = (SHTIM) / ADCClock
    // SHTIM = (HoldTime * ADCClock)-1 = (600 10e-9 * 5000000) = 3
    // SHTIM   =  3 -> (3)/4800000 = 1/1600000 = 625ns
    prescal = (mckClock / (2*adcClock)) - 1;
    startup = ((adcClock/1000000) * startupTime / 8) - 1;
    shtim = (((adcClock/1000000) * sampleAndHoldTime)/1000);
    
    ASSERT( (prescal<0x3F), "ADC12 Bad PRESCAL\n\r");
    ASSERT(startup<0x7F, "ADC12 Bad STARTUP\n\r");
    ASSERT(shtim<0xF, "ADC12 Bad SampleAndHoldTime\n\r");

    TRACE_DEBUG("adcClock:%d MasterClock:%d\n\r", (mckClock/((prescal+1)*2)), mckClock);
    TRACE_DEBUG("prescal:0x%X startup:0x%X shtim:0x%X\n\r", prescal, startup, shtim);
    
    if( adcClock != (mckClock/((prescal+1)*2)) ) {
        TRACE_WARNING("User and calculated adcClocks are different : user=%d calc=%d\n\r", 
            adcClock, (mckClock/((prescal+1)*2)));
    }

    // Enable peripheral clock    
    AT91C_BASE_PMC->PMC_PCER = 1 << idAdc;    
    
    // Reset the controller
    ADC12_SoftReset(pAdc);

    // Write to the MR register
    ADC12_CfgModeReg( pAdc,
          ( trgEn & AT91C_ADC12B_MR_TRGEN)
        | ( trgSel & AT91C_ADC12B_MR_TRGSEL)
        | ( resolution & AT91C_ADC12B_MR_LOWRES)			
        | ( sleepMode & AT91C_ADC12B_MR_SLEEP)
        | ( (prescal<<8) & AT91C_ADC12B_MR_PRESCAL) 
        | ( (startup<<16) & AT91C_ADC12B_MR_STARTUP) 
        | ( (shtim<<24) & AT91C_ADC12B_MR_SHTIM) );
}


//-----------------------------------------------------------------------------
/// Return the Channel Converted Data
/// \param pAdc Pointer to an AT91S_ADC instance.
/// \param channel channel to get converted value
/// \return Channel converted data of the specified channel
//-----------------------------------------------------------------------------
unsigned int ADC12_GetConvertedData(AT91S_ADC12B *pAdc, unsigned int channel)
{
    unsigned int data=0;
    
    ASSERT(channel < 8, "ADC channel %u not exist", channel);
    
    switch(channel) {
        case 0: data = pAdc->ADC12B_CDR[0]; break;
        case 1: data = pAdc->ADC12B_CDR[1]; break;
        case 2: data = pAdc->ADC12B_CDR[2]; break;
        case 3: data = pAdc->ADC12B_CDR[3]; break;
        case 4: data = pAdc->ADC12B_CDR[4]; break;
        case 5: data = pAdc->ADC12B_CDR[5]; break;
        case 6: data = pAdc->ADC12B_CDR[6]; break;
        case 7: data = pAdc->ADC12B_CDR[7]; break;    
        default: printf("\n\r Channel is not available!\n\r");
              
    }
    return data;    
}


//-----------------------------------------------------------------------------
/// Test if ADC Interrupt is Masked 
/// \param pAdc Pointer to an AT91S_ADC instance.
/// \param flag flag to be tested
/// \return 1 if interrupt is masked, otherwise 0
//-----------------------------------------------------------------------------
unsigned int ADC12_IsInterruptMasked(AT91S_ADC12B *pAdc, unsigned int flag)
{
    return (ADC12_GetInterruptMaskStatus(pAdc) & flag);
}

//-----------------------------------------------------------------------------
/// Test if ADC Status is Set
/// \param pAdc Pointer to an AT91S_ADC instance.
/// \param flag flag to be tested
/// \return 1 if the staus is set; 0 otherwise
//-----------------------------------------------------------------------------
unsigned int ADC12_IsStatusSet(AT91S_ADC12B *pAdc, unsigned int flag)
{
    return (ADC12_GetStatus(pAdc) & flag);
}


//-----------------------------------------------------------------------------
/// Test if ADC channel interrupt Status is Set
/// \param adc_sr Value of SR register
/// \param channel Channel to be tested
/// \return 1 if interrupt status is set, otherwise 0
//-----------------------------------------------------------------------------
unsigned char ADC12_IsChannelInterruptStatusSet(unsigned int adc_sr, 
                                              unsigned int channel)
{
    unsigned char status;
    
    if((adc_sr & (1<<channel)) == (1<<channel)) {
        status = 1;
    }
    else {
        status = 0;
    }
    return status;
}





