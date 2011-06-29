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

#include <board.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <adc/adc12.h>
#include <irq/irq.h>
#include <rtc/rtc.h>

#include "dfm_config.h"
#include "dfm_cmd.h"
#include "dfm_lcd_tsd.h"
#include "dfm_dispboxmgr.h"
#include "dfm_it.h"

//------------------------------------------------------------------------------
//         Global variables
//------------------------------------------------------------------------------

#if defined(at91sam3u4)
#define BOARD_ADC_FREQ 5000000
#define ADC_VREF       3300  // 3.3 * 1000
#endif

#if defined(USE_IT_CHAIN_MGR)
void RTC_IrqHandlerSlideShow(void);
TDFM_ItServList gRtcItHandlerSlideShow = {BOARD_RTC_ID, RTC_IrqHandlerSlideShow, NULL};
#endif

/// count seconds
unsigned int gSecondCount = 0;
/// Record when slide show starts
static unsigned int gSlideShowStartSec = 0xFFFFFFFF;
/// slide show wait interval
unsigned int gSlideShowInterval = 5;
/// default home page to return when slide show ends
unsigned int gDefaultHomePage = 1;
/// adc sample value when slide show starts
unsigned int gPoMeterRefADValue = 0xFFFFFFFF;
/// adjustment interval base, will be set same as gSlideShowInterval when slide show start
unsigned int gIntervalBase;
/// the threshold value for interval adjustment by potentimeter
unsigned int gInvThreshold = 30;//default is 30 seconds


unsigned int xSlPenLast=0;
unsigned int ySlPenLast=0;

//------------------------------------------------------------------------------
/// Interrupt RTC handler for slide show. 
//------------------------------------------------------------------------------
void RTC_IrqHandlerSlideShow()
{
  unsigned int status, advalue;
  unsigned char tmpT;
  
  status = AT91C_BASE_RTC->RTC_SR;
    
  if ((status & AT91C_RTC_SECEV) == AT91C_RTC_SECEV) {
    // Disable RTC interrupt
    RTC_DisableIt(AT91C_RTC_SECEV);
  }

  ++gSecondCount;
  
  if(gSlideShowStartSec == 0xffffffff)
    gSlideShowStartSec = gSecondCount;
  
  if(gSecondCount - gSlideShowStartSec >= gSlideShowInterval) {
    ++gActiveSlideIndex;
    
    gSlideShowStartSec = gSecondCount;
  }
  
#if defined(at91sam3u4)  
  if(gSecondCount & 1 == 0) {
    ADC12_StartConversion(AT91C_BASE_ADC12B);
  } else {
  
//  if(gSecondCount % 2 == 0) {
    advalue = ADC12_GetConvertedData(AT91C_BASE_ADC12B, ADC12_CHANNEL_3);
    
    advalue = advalue * ADC_VREF / 0xFFF;
    
    if(gPoMeterRefADValue == 0xFFFFFFFF) {
      gPoMeterRefADValue = advalue;
      gSlideShowInterval = advalue * gInvThreshold / ADC_VREF;
//      gIntervalBase = gSlideShowInterval;
    }
    
    if(advalue !=  gPoMeterRefADValue) {
      gSlideShowInterval = advalue * gInvThreshold / ADC_VREF;
    }
//    if(advalue > gPoMeterRefADValue) {
//      gSlideShowInterval = (advalue - gPoMeterRefADValue) * (gInvThreshold - gIntervalBase) \
//                            /(ADC_VREF - gPoMeterRefADValue) + gIntervalBase;
//    }
//    
//    if(advalue < gPoMeterRefADValue) {
//      gSlideShowInterval = gIntervalBase - (gPoMeterRefADValue - advalue) * gIntervalBase \
//                            / gPoMeterRefADValue;
//    }
    
    if(gSlideShowInterval == 0) {
      gSlideShowInterval = 1;
    } 
  }
#endif
  
  AT91C_BASE_RTC->RTC_SCCR = AT91C_RTC_SECEV;
  
  RTC_EnableIt(AT91C_RTC_SECEV);  

  tmpT = TSD_GetTouched();
  if(tmpT)
  {
      //printf("Touch \n\r");
      TSD_ClearTouched();
      // End slide show command
      ParseAndRunMultiCmds("slideshow end");
      ParseAndRunMultiCmds("slidepage goto 02");
  }
}

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Portal for 'slideshow' command
//  \param argc, number of argument
//  \param argv, argument string array
//  \return 0 succeed, other value failure
//------------------------------------------------------------------------------
int DFM_SlideShow(int argc, char ** argv)
{
  unsigned int value;
  char string[20];
  
  if(argc == 3 && strcmp(argv[1], "-interval") == 0) {
    //command "slideshow -interval up
    if(strcmp(argv[2], "up")==0) {
      ++gSlideShowInterval;
    }
    
    //command "slideshow -interval down
    if(strcmp(argv[2], "down")==0) {
      --gSlideShowInterval;
    }
    
    //command "slideshow -interval display
    // display current gSlideShowInterval value in display box
    if(strcmp(argv[2], "display")==0) {
      sprintf(string, "%u ", gSlideShowInterval);
      DrawStrInDispBoxScrollNoClear((void *)BOARD_LCD_BASE, 1, string);
    }
  }
  

  //command "slideshow start"  
  if(argc == 2 && strcmp(argv[1], "start")==0) {

    TSD_ClearTouched();

    //reset variable 
    gSlideShowStartSec = 0xFFFFFFFF;
    gPoMeterRefADValue = 0xFFFFFFFF;

#if defined(at91sam3u4)
    ADC12_EnableChannel(AT91C_BASE_ADC12B, ADC12_CHANNEL_3);
    // Start measurement
    ADC12_StartConversion(AT91C_BASE_ADC12B);
#endif

#if defined(USE_IT_CHAIN_MGR)
    DFM_RegisterItHandler(&gRtcItHandlerSlideShow);
#endif    
    //enable RTC interrupt
    IRQ_ConfigureIT(BOARD_RTC_ID, 0, RTC_IrqHandlerSlideShow);
    RTC_EnableIt(AT91C_RTC_SECEV);
    IRQ_EnableIT(BOARD_RTC_ID);
    
  }

  //command "slideshow start -homepage xx"  
  if(argc == 4 && strcmp(argv[1], "start")==0 &&
     strcmp(argv[2], "-homepage")==0) {

    TSD_ClearTouched();

    //reset variable 
    gSlideShowStartSec = 0xFFFFFFFF;

#if defined(USE_IT_CHAIN_MGR)
    DFM_RegisterItHandler(&gRtcItHandlerSlideShow);
#endif
    //enable RTC interrupt
    IRQ_ConfigureIT(BOARD_RTC_ID, 0, RTC_IrqHandlerSlideShow);
    RTC_EnableIt(AT91C_RTC_SECEV);
    IRQ_EnableIT(BOARD_RTC_ID);
      
    value = atoi(argv[3]);
    //in command input, slide start from 1, but in program it starts from 0
    //note if index number of slide bigger than max, program will correct as
    //the last of slide
    gDefaultHomePage = value - 1;   
  }
  
  //command "slideshow end"
  if(argc == 2 && strcmp(argv[1], "end")==0) {

    TSD_ClearTouched();

    RTC_DisableIt(AT91C_RTC_SECEV);
    IRQ_DisableIT(BOARD_RTC_ID);

#if defined(at91sam3u4)
    DFM_UnRegisterItHandler(&gRtcItHandlerSlideShow);
#endif
      
    //reset variable 
    gSlideShowStartSec = 0xFFFFFFFF;
    
    gActiveSlideIndex = gDefaultHomePage;
  }
  
  //command "slideshow start -homepage xx"  
  if(argc == 4 && strcmp(argv[1], "end")==0 &&
     strcmp(argv[2], "-homepage")==0) {

    TSD_ClearTouched();

    RTC_DisableIt(AT91C_RTC_SECEV);
    IRQ_DisableIT(BOARD_RTC_ID);

#if defined(at91sam3u4)
    DFM_UnRegisterItHandler(&gRtcItHandlerSlideShow);
#endif
      
    //reset variable 
    gSlideShowStartSec = 0xFFFFFFFF;
      
    value = atoi(argv[3]);
    //in command input, slide start from 1, but in program it starts from 0
    //note if index number of slide bigger than max, program will correct as
    //the last of slide
    gActiveSlideIndex = value - 1;
    
    gDefaultHomePage = gActiveSlideIndex;
  }
  
  return 0;
}

//define a new command 'slideshow' for slide show
DFM_CMD(slideshow, DFM_SlideShow, "slide show ppt pages", "default");

