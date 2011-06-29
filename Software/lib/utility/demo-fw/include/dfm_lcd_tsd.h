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

#ifndef __DFM_LCD_TSD_H__
#define __DFM_LCD_TSD_H__

#include "dfm_entry.h"
#include "DemobinHeader.h"

//for LCD prompt register entry
extern TInputEntry gLCDEntry;

//for change of display slide on lcd
extern unsigned short gActiveSlideIndex;

#define GLOBALSLIDEINFO

#if defined(GLOBALSLIDEINFO)
extern SlideINFOHeader gActiveSlideHeader;
#endif

/// Get link string from link index on active slide
extern char * GetLinkStrFromActiveSlide(unsigned int linkIdx);

// Show pic on LCD as prompt
extern int LCD_ShowPrompt();

// Check if hotzones have been hit on touchscreen
extern unsigned int TSD_CommandIsReady();

// Get hotzone command hyperlink string 
extern const char * TSD_GetCommand();

//  Set LCD fresh show flag
extern void LCD_SetRefreshFlag();

//  Clear LCD fresh show flag
extern void LCD_ClearRefreshFlag();

// Get last pen press position
extern void TSD_GetPenLastPosition(unsigned int *pX, unsigned int *pY);

/// Set touched flag
void TSD_SetTouched(void);
/// Clear touched flag
void TSD_ClearTouched(void);
/// Get touched flag
unsigned char TSD_GetTouched(void);

#endif

