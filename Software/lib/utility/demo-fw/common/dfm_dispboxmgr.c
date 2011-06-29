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

#include <string.h>
#include <stdio.h>
#include <lcd/font.h>
#include <lcd/color.h>
#include <lcd/draw.h>
#include <components/hx8347/hx8347.h>
#include <utility/trace.h>

#include "dfm_config.h"
#include "dfm_dispboxmgr.h"
#include "dfm_accelerometer.h"
//------------------------------------------------------------------------------
//         Internal variables
//------------------------------------------------------------------------------

static TDISPBOX_MGR dispBoxMgr= {
  0,
  {{0, {0,0,0,0}, COLOR_WHITE, COLOR_BLUE, 0, 0},
  {0, {0,0,0,0}, COLOR_WHITE, COLOR_BLUE, 0, 0},
  {0, {0,0,0,0}, COLOR_WHITE, COLOR_BLUE, 0, 0},
  {0, {0,0,0,0}, COLOR_WHITE, COLOR_BLUE, 0, 0}}
};

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Set default background color of display box
//------------------------------------------------------------------------------
void SetDispBoxBGColor(unsigned int dispBoxID, unsigned int color)
{
  dispBoxMgr.dispBoxInfo[dispBoxID - 1].bgColor = color;
}

//------------------------------------------------------------------------------
/// set default Font Color of display box
//------------------------------------------------------------------------------
void SetDispBoxFontColor(unsigned int dispBoxID, unsigned int color)
{
  dispBoxMgr.dispBoxInfo[dispBoxID - 1].fontColor = color;
}

//------------------------------------------------------------------------------
/// set display box position info
//------------------------------------------------------------------------------
void SetDispBoxPos(unsigned int dispBoxID, 
                   unsigned int enableDispBox,
                   unsigned int top,
                   unsigned int left,
                   unsigned int width,
                   unsigned int height)
{
  if(dispBoxID > dispBoxMgr.dispBoxCount) {
    if(dispBoxID < MAX_DISPBOX_PER_SLIDE) {
      ++dispBoxMgr.dispBoxCount;
    } else
      return;
  }
  
  dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxEnable = enableDispBox;
  if(enableDispBox) {
    dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.top =  top;
    dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.left = left;
    dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.width = width;
    dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.height = height;
    
    //set x,y start position
    dispBoxMgr.dispBoxInfo[dispBoxID - 1].xCursor = \
      dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.left + DISPMARGIN;
    dispBoxMgr.dispBoxInfo[dispBoxID - 1].yCursor = \
      dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.top + DISPMARGIN;
    
    if(gDir > 0 && gDir < 3)
    {
      dispBoxMgr.dispBoxInfo[dispBoxID-1].xCursor = \
        (dispBoxMgr.dispBoxInfo[dispBoxID-1].dispBoxZone.left + width) - DISPMARGIN ;
      dispBoxMgr.dispBoxInfo[dispBoxID-1].yCursor = \
        dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.top + DISPMARGIN;
    }
    
  }
}

//------------------------------------------------------------------------------
/// enable display box
//------------------------------------------------------------------------------
void EnableDispBox(unsigned int dispBoxID)
{
  dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxEnable = DISPBOX_ENABLE;  
}

//------------------------------------------------------------------------------
/// disable display box
//------------------------------------------------------------------------------
void DisableDispBox(unsigned int dispBoxID)
{
  dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxEnable = DISPBOX_DISABLE;  
}

//------------------------------------------------------------------------------
/// Check if any display box region is available
/// \return 0 mean no display box, other means yes and value is number of display box
//------------------------------------------------------------------------------
unsigned int IsDispBoxRegionAvail()
{
  if(!dispBoxMgr.dispBoxCount) {
      return 0;
  }
  
  return dispBoxMgr.dispBoxCount;
}

//------------------------------------------------------------------------------
/// Check if the required display box is enabled
/// \return 0 mean no display box, other means yes
//------------------------------------------------------------------------------
unsigned int IsDispBoxEnable(unsigned int dispBoxID)
{
  if(!dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxEnable)
    return DISPBOX_DISABLE;
  
  return DISPBOX_ENABLE;
}

//------------------------------------------------------------------------------
/// Draw a string in display box with 'color'
/// \param pBuffer, LCD base address
/// \param dispBoxID, display box ID
/// \param pStr, string to draw
/// \param fontColor, font color
/// \param bgColor, background color
/// \param scrollFlag, idendtify if cleaning display box zone when scrolling back
///                    to display box start position
//------------------------------------------------------------------------------
void DrawStringInDispBox(
    //pointer to LCD base address
    void *pBuffer,
    //display box index
    unsigned int dispBoxID,
    //pointer to string for show
    const char *pStr,
    //display string font color,
    unsigned int fontColor,
    //display string background color, 0xFFFFFFFF means no need to set bgColor
    unsigned int bgColor,
    //flag for scroll way, current only support 'clear or not clear display box'
    //when display string reach end and roll back to show. 
    //0 means clear, 1 means don't clear.
    unsigned int scrollFlag)
{
  unsigned int strWidth = 0;
  unsigned int strHeight = 0;
  extern const Font gFont;
  const char *pString = pStr;
  
  //text direction
  unsigned int dir = 0;
  
  ////////////////////////////////////
  unsigned int width = 0;
  unsigned int height = 0;
  unsigned int left = 0;
  unsigned int top = 0;
  ///////////////////////////////////
  TRACE_DEBUG(" draw string on lcd len is %u\n\r", strlen(pStr));
  
  //no display box or disabled
  if(!IsDispBoxRegionAvail() || !IsDispBoxEnable(dispBoxID)) {
    //then display information on DBGU console;
    printf("\n\r %s", pStr);
    return;
  }
  
#if defined(LCDC_HX8347)
  
  
  if(LCDD_IsBusy()) return;
  
  LCDD_SetBusy();
  
  //a temp way to resolve display direction. Further will be improved based on requirement
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x16, 0x68);//); // MY=1, MX=0, MV=1, BGR=1
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x02, 0x00); // Column address start2
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x03, 0x00); // Column address start1
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x04, 0x01); // Column address end2
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x05, 0x3F); // Column address end1
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x06, 0x00); // Row address start2
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x07, 0x00); // Row address start1
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x08, 0x00); // Row address end2
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x09, 0xEF); // Row address end1
  
  LCDD_ClearBusy();
#endif
  ////////////////////////////////////////////
  
  if(gDir < 3 && gDir > 0)
    //if(gDir >= 3 || gDir == 0)
  {
    // the protrait view,coordinates was changed after loading
    //the Y is mirrored and x-y changed
    height = dispBoxMgr.dispBoxInfo[dispBoxID-1].dispBoxZone.width;
    //the width is to meet the algorithm calculating string lines
    
    width  = dispBoxMgr.dispBoxInfo[dispBoxID-1].dispBoxZone.height;
    //it's strange but useful
    left = dispBoxMgr.dispBoxInfo[dispBoxID-1].dispBoxZone.left + height;
    top = dispBoxMgr.dispBoxInfo[dispBoxID-1].dispBoxZone.top ;
    
    
    //for vertical 
    dir = 1;
    
    
  }
  else
  {
    width = dispBoxMgr.dispBoxInfo[dispBoxID-1].dispBoxZone.width;
    height = dispBoxMgr.dispBoxInfo[dispBoxID-1].dispBoxZone.height;
    top = dispBoxMgr.dispBoxInfo[dispBoxID-1].dispBoxZone.top;
    left = dispBoxMgr.dispBoxInfo[dispBoxID-1].dispBoxZone.left;
    
    dir = 0;
    
  }
  //count lines the string will use
  ////////////////////////////////////////////
  //back from start of display box, then clear dispbox zone
  
  
  if(\
    (dispBoxMgr.dispBoxInfo[dispBoxID-1].xCursor == \
      left + DISPMARGIN) \
        && \
          (dispBoxMgr.dispBoxInfo[dispBoxID-1].yCursor == \
            top + LINEDISTANCE)\
              )
  {            
    ClearDispBoxZoneDefault(dispBoxID);
  }
  
  if(dir)
  {
    if(\
      (dispBoxMgr.dispBoxInfo[dispBoxID-1].xCursor == \
        left - DISPMARGIN) \
          && \
            (dispBoxMgr.dispBoxInfo[dispBoxID-1].yCursor == \
              top + LINEDISTANCE)\
                )
    {            
      ClearDispBoxZoneDefault(dispBoxID);
    }
  }
  
  LCDD_GetStringSize(pString, &strWidth, &strHeight);
  
  TRACE_DEBUG(" string width and height in pixel is %u, %u\n\r", strWidth, strHeight);
  
  //count lines the string will use
  unsigned int linecnt = \
    (strWidth + CHARDISTANCE) \
      / (width - DISPMARGIN) + 1;
  
  //get how many chars the dispbox width can show
  //to be consistent with lib API, a char width is gFont.width + CHARDISTANCE
  unsigned int numCharLine = (width - DISPMARGIN) \
    / (gFont.width + CHARDISTANCE) - 1;
  
  //if line count larger than current position to bottom of dispbox, clear dispbox area,
  //reinit x,y to start of dispbox
  if( linecnt * (gFont.height + LINEDISTANCE) \
    > \
      (height - \
        (dispBoxMgr.dispBoxInfo[dispBoxID-1].yCursor - \
          top - LINEDISTANCE))\
            ) 
  {
    if(scrollFlag == 0) {
      LCDD_DrawRectangle((void *)BOARD_LCD_BASE, 
                         left,
                         top,
                         width,
                         height,
                         dispBoxMgr.dispBoxInfo[dispBoxID-1].bgColor);
    }
    
    dispBoxMgr.dispBoxInfo[dispBoxID-1].xCursor = \
      left + DISPMARGIN;
    dispBoxMgr.dispBoxInfo[dispBoxID-1].yCursor = \
      top + LINEDISTANCE;    
  }
  
  if(dir)
  {
    if( linecnt * (gFont.height + LINEDISTANCE) \
      > \
        (height - \
          (left - dispBoxMgr.dispBoxInfo[dispBoxID-1].xCursor  \
            - LINEDISTANCE))\
              ) 
    {
      if(scrollFlag == 0) {
        //      LCDD_DrawRectangle((void *)BOARD_LCD_BASE, 
        //                         left,
        //                         top,
        //                         width,
        //                         height,
        //                         dispBoxMgr.dispBoxInfo[dispBoxID-1].bgColor);
        ClearDispBoxZoneDefault(dispBoxID);
      }
      
      dispBoxMgr.dispBoxInfo[dispBoxID-1].xCursor = \
        left - DISPMARGIN;
      dispBoxMgr.dispBoxInfo[dispBoxID-1].yCursor = \
        top + LINEDISTANCE;    
    }
  }
  
  //if whole string show height larger than dispbox height, then only show the content 
  //inside dispbox, the rest is not shown any more
  if((linecnt * (gFont.height + LINEDISTANCE) > \
    height)) {
      linecnt  = height / (gFont.height+LINEDISTANCE);
      //shrink string to a full dispbox size.
      strWidth = linecnt * numCharLine * (gFont.width+CHARDISTANCE);
    }
  
  TRACE_DEBUG(" numcharline is %u, linecnt is %u\n\r", numCharLine, linecnt);
  
  unsigned int i;
  for(i = 0; i < linecnt; ++i) {
    char stringline[80];
    if(i == linecnt - 1) {
      //the last char doesn't have additional CHARDISTANCE, to meet API in lib
      memcpy(stringline, pString, (strWidth+CHARDISTANCE) / (gFont.width+CHARDISTANCE) + 1);
      stringline[(strWidth+CHARDISTANCE)/(gFont.width+CHARDISTANCE)] = '\0';
    } else {
      memcpy(stringline, pString, numCharLine);
      stringline[numCharLine] = '\0';
      strWidth -= numCharLine * (gFont.width+CHARDISTANCE);
    }
    
    //forward pString to next line
    pString += numCharLine;
    
    //draw string
    if(bgColor == 0xFFFFFFFF) {
      LCDD_DrawStringEx((void *)BOARD_LCD_BASE,
                        dispBoxMgr.dispBoxInfo[dispBoxID-1].xCursor,
                        dispBoxMgr.dispBoxInfo[dispBoxID-1].yCursor,
                        stringline,
                        fontColor,dir);
    }else {
      LCDD_DrawStringWithBGColorEx((void *)BOARD_LCD_BASE,
                                   dispBoxMgr.dispBoxInfo[dispBoxID-1].xCursor,
                                   dispBoxMgr.dispBoxInfo[dispBoxID-1].yCursor,
                                   stringline,
                                   fontColor,
                                   bgColor,dir);
    }
    
    //move x, y to next line, to be consistent with lib api, height is gFont.height + 2
    if(dir)
    {
      // xCursor is vertical to the direction of text,along with the lines of text
      dispBoxMgr.dispBoxInfo[dispBoxID-1].xCursor -=  (gFont.height + LINEDISTANCE);
      dispBoxMgr.dispBoxInfo[dispBoxID-1].yCursor = \
        top + DISPMARGIN;
      
    }
    else
    {
      dispBoxMgr.dispBoxInfo[dispBoxID-1].xCursor = \
        left + DISPMARGIN;
      dispBoxMgr.dispBoxInfo[dispBoxID-1].yCursor += gFont.height + LINEDISTANCE;
    }
    
  }
  
#if defined(LCDC_HX8347)  
  
  if(LCDD_IsBusy()) return;
  
  LCDD_SetBusy();
  
  //restore previous direction setting
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x16, 0xC8);//); // MY=1, MX=1, MV=0, BGR=1
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x02, 0x00); // Column address start2
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x03, 0x00); // Column address start1
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x04, 0x00); // Column address end2
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x05, 0xEF); // Column address end1
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x06, 0x00); // Row address start2
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x07, 0x00); // Row address start1
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x08, 0x01); // Row address end2
  LCD_WriteReg((void *)BOARD_LCD_BASE, 0x09, 0x3F); // Row address end1
  
  LCDD_ClearBusy();
#endif
}

//Draw a string in display box with default font and background color
//if scroll back then clear
void DrawStrInDispBoxDefault(void *pBuffer, unsigned int dispBoxID, const char *pStr)
{
  DrawStringInDispBox(
                      pBuffer,
                      dispBoxID,
                      pStr,
                      dispBoxMgr.dispBoxInfo[dispBoxID - 1].fontColor,
                      dispBoxMgr.dispBoxInfo[dispBoxID - 1].bgColor,
                      0);
}

//Draw a string in display box with default font and background color
//if scroll back, don't clear
void DrawStrInDispBoxScrollNoClear(void *pBuffer, unsigned int dispBoxID, const char *pStr)
{
  DrawStringInDispBox(
                      pBuffer,
                      dispBoxID,
                      pStr,
                      dispBoxMgr.dispBoxInfo[dispBoxID - 1].fontColor,
                      dispBoxMgr.dispBoxInfo[dispBoxID - 1].bgColor,
                      1);
}

//clear display box zone with color
void ClearDispBoxZoneColor(unsigned int dispBoxID, unsigned int color)
{
  if(IsDispBoxRegionAvail() && IsDispBoxEnable(dispBoxID)) {

    LCDD_DrawRectangle((void *)BOARD_LCD_BASE, \
                        dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.left,
                        dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.top,
                        dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.width,
                        dispBoxMgr.dispBoxInfo[dispBoxID - 1].dispBoxZone.height,
                        color);
  }
}

//------------------------------------------------------------------------------
/// Clear display box with default background color
//------------------------------------------------------------------------------
void ClearDispBoxZoneDefault(unsigned int dispBoxID)
{
  ClearDispBoxZoneColor(dispBoxID, dispBoxMgr.dispBoxInfo[dispBoxID - 1].bgColor);
}
