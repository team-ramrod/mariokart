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

#include <stdio.h>
#include <pio/pio.h>
#include <lcd/draw.h>
#include <lcd/color.h>
#include <utility/trace.h>

#include "dfm_init.h"
#include "dfm_cmd.h"
#include "dfm_button.h"
#include "dfm_lcd_tsd.h"

//------------------------------------------------------------------------------
//        variable definition
//------------------------------------------------------------------------------
/// global BUTTON entry
TInputEntry gButtonEntry = \
  {0, {NULL,NULL}, BTN_ShowPrompt, BTN_CommandIsReady, BTN_GetCommand, NULL};

/// global active icon, a focus circle should be drawn around it 
unsigned int gActiveIconIndex;

//button pin definition
static Pin pinsPushButtons[] = {PINS_PUSHBUTTONS};

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
///  Init button
//------------------------------------------------------------------------------
int BTN_Init(void)
{
  printf("\n\r Init Button!");
  
  gActiveIconIndex = 0;
  
  //memset(keyStatus, 1, 2);
  
  PIO_Configure(pinsPushButtons, PIO_LISTSIZE(pinsPushButtons));
  
  return 0;
}

//decleare to init it in level 5
DFM_INIT(5, BTN_Init);

//------------------------------------------------------------------------------
///  Draw a focus circle around current active icon
///  \param colormask, color mask to generate a masked color to draw
//------------------------------------------------------------------------------
static void DrawIconSelection(unsigned int linkZoneIndex, unsigned int colorMask)
{
  unsigned int i, left, bottom, width, height;
  unsigned short color16;
  unsigned int color, color24;
  
  //index correcttion
  if(linkZoneIndex >= gActiveSlideHeader.linkcount)
    linkZoneIndex = gActiveSlideHeader.linkcount - 1;
  
  bottom = gActiveSlideHeader.linkinfo[linkZoneIndex].linkboxbottom;
  left = gActiveSlideHeader.linkinfo[linkZoneIndex].linkboxleft;
  width = gActiveSlideHeader.linkinfo[linkZoneIndex].linkboxwidth;
  height = gActiveSlideHeader.linkinfo[linkZoneIndex].linkboxheight;

#ifndef RGB16ToRGB24
/// Convert 16-bits color to 24-bits color, detail lost, only for compatible.
#define RGB16ToRGB24(color) (((color & 0XF800) << 8) | \
    ((color & 0x7E0) << 5) | \
    ((color & 0x1F) << 3))  
#endif
  
  for(i = 0; i < (width + 2); ++i) {
    color16 = LCDD_ReadPixel((void *)BOARD_LCD_BASE,
                                 left + i,
                                 bottom);
    color = RGB16ToRGB24(color16);
    color24 = color ^ colorMask;
    
    LCDD_DrawPixel((void *)BOARD_LCD_BASE,
                   left + i,
                   bottom,
                   color24);
    
    color16 = LCDD_ReadPixel((void *)BOARD_LCD_BASE,
                                 left + i,
                                 bottom - height - 1);
    color = RGB16ToRGB24(color16);
    color24 = color ^ colorMask;
    
    LCDD_DrawPixel((void *)BOARD_LCD_BASE,
                   left + i,
                   bottom - height - 1,
                   color24);
  }
  
  for(i = 1; i < (height + 1); ++i) {
    color16 = LCDD_ReadPixel((void *)BOARD_LCD_BASE,
                                 left,
                                 bottom - i);
    
    color = RGB16ToRGB24(color16);
    color24 = color ^ colorMask;
    
    LCDD_DrawPixel((void *)BOARD_LCD_BASE,
                   left,
                   bottom - i,
                   color24);

    color16 = LCDD_ReadPixel((void *)BOARD_LCD_BASE,
                                 left + width + 1,
                                 bottom - i);
    
    color = RGB16ToRGB24(color16);
    color24 = color ^ colorMask;
    
    LCDD_DrawPixel((void *)BOARD_LCD_BASE,
                   left + width + 1,
                   bottom - i,
                   color24);
  }

}

//------------------------------------------------------------------------------
///  Draw a focus circle on current active icon
//------------------------------------------------------------------------------
int BTN_ShowPrompt()
{
  static unsigned int iconDrawedIndex = 0xFFFFFFFF;
  static unsigned int slidePageLoaded = 0xFFFFFFFF;
  
  if(slidePageLoaded != gActiveSlideIndex) {
    slidePageLoaded = gActiveSlideIndex;
    iconDrawedIndex = gActiveIconIndex = 0;
    
    DrawIconSelection(gActiveIconIndex, COLOR_AZUR);
  } else {
    if(iconDrawedIndex != gActiveIconIndex) {
      DrawIconSelection(iconDrawedIndex, COLOR_AZUR);
      
      DrawIconSelection(gActiveIconIndex, COLOR_AZUR);
      
      iconDrawedIndex = gActiveIconIndex;
    }
  }
  
  return 0;
}

//------------------------------------------------------------------------------
///  Check button press/release status, if OK button press/released, then true
/// \return 0 means not ready, 1 means yes.
//------------------------------------------------------------------------------
//check if button is pressed
unsigned int BTN_CommandIsReady()
{
  //unsigned int i;
  static unsigned int selPressFlag = 0;
  static unsigned int okPressFlag = 0;
  unsigned int ret = 0;
  unsigned char btnStatus;

  //read icon selection button status
  btnStatus = PIO_Get(&(pinsPushButtons[0]));
  
  //icon selection button pressed
  if(btnStatus == 0) {
    if(!selPressFlag) {
//      //use same color mask to clear previous focus circle
//      DrawIconSelection(COLOR_AZUR);
      
      //increase icon index to next
      ++gActiveIconIndex;
      if(gActiveIconIndex >= gActiveSlideHeader.linkcount)
        gActiveIconIndex = 0;
      
//      //use a color mask to draw a focus circle for icon
//      DrawIconSelection(COLOR_AZUR);
      
      //set selection button pressed flag to wait button release
      selPressFlag = 1;
    }
  } else {
    //pressed key released
    selPressFlag = 0;
  }
  
  //read icon confirm button status
  btnStatus = PIO_Get(&(pinsPushButtons[1]));
  
  //ok button pressed
  if(btnStatus == 0)
  {
    if(!okPressFlag) {
      //set ok button pressed flag to wait button release
      okPressFlag = 1;
    }
  } else {
    if(okPressFlag) {
      //pressed key released,then return 1 to id command is ready
      ret = 1;
      okPressFlag = 0;
    }
  }
  
  return ret;
}

//------------------------------------------------------------------------------
///  Get commands for selected icon
///  \return command string for the selected icon
//------------------------------------------------------------------------------
const char * BTN_GetCommand()
{
  return GetLinkStrFromActiveSlide(gActiveIconIndex + 1);
}

