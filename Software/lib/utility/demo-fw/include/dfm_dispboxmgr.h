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

#ifndef __LCD_DISPBOX_H_
#define __LCD_DISPBOX_H_

#include "DemobinHeader.h"

//------------------------------------------------------------------------------
//      Definitions
//------------------------------------------------------------------------------

///display margin in pixel in dispbox area
#define DISPMARGIN 2
///line distance in pixel in dispbox area
#define LINEDISTANCE 2
///char distance in pixel, actually this is used to meet API LIB DrawString(...)
#define CHARDISTANCE 2
///status of enable display box
#define DISPBOX_ENABLE 1
///status of disable display box
#define DISPBOX_DISABLE 0

typedef struct _DISPBOX_ZONE {
  /// display box top
  unsigned int top;
  /// display box left
  unsigned int left;
  /// display box width
  unsigned int width;
  /// display box height
  unsigned int height;  
} TDISPBOX_ZONE;

typedef struct _DISPBOX_INFO {
  unsigned int dispBoxEnable;
  TDISPBOX_ZONE dispBoxZone;
  unsigned int bgColor;// background color
  unsigned int fontColor;// font color of display box
  unsigned int xCursor;
  unsigned int yCursor;
} TDISPBOX_INFO;

typedef struct _DISPBOX_MGR {
  unsigned int dispBoxCount;
  TDISPBOX_INFO dispBoxInfo[MAX_DISPBOX_PER_SLIDE];
} TDISPBOX_MGR;

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//set display box position info
extern void SetDispBoxPos(
                   unsigned int dispBoxID, 
                   unsigned int enabledispbox, 
                   unsigned int top,
                   unsigned int left,
                   unsigned int width,
                   unsigned int height);

//Draw a string in display box with 
extern void DrawStringInDispBox(
    // lcd frame buffer address
    void *pBuffer,
    // display box ID, starting from 1
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
    unsigned int scrollFlag);

//Draw a string in display box with default font color
extern void DrawStrInDispBoxDefault(void *pBuffer, unsigned int dispBoxID, const char *pStr);

//Draw a string in display box with default font and background color
//if scroll back, don't clear
void DrawStrInDispBoxScrollNoClear(void *pBuffer, unsigned int dispBoxID, const char *pStr);

//clear display box zone with 'color'
extern void ClearDispBoxZoneColor(unsigned int dispBoxID, unsigned int color);

//Clear display box with default background color
extern void ClearDispBoxZoneDefault(unsigned int dispBoxID);

//disable display box
extern void DisableDispBox(unsigned int dispBoxID);

//enable display box
extern void EnableDispBox(unsigned int dispBoxID);

#endif

