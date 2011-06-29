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

#include "dfm_init.h"

//------------------------------------------------------------------------------
//        variable definition
//------------------------------------------------------------------------------
#if defined(__ICCARM__)//IAR Compiler ID

///no need for declaration of section start and end variable in IAR

#elif defined(__CC_ARM) //MDK ARM Compiler ID

///variables for group start/end address
extern unsigned int Image$$GS_Init_Region$$Base;
extern unsigned int Image$$GS_Init_Region$$Limit;

#elif defined(__GNUC__)//GNU ARM Compiler ID

extern unsigned int __gs_init_section_start, __gs_init_section_end;

#endif

//------------------------------------------------------------------------------
///  Run all init handlers from level 1 to level 7
///  \return 0 succeed, other value failure
//-----------------------------------------------------------------------------
unsigned int RunAllInit()
{
  T_INIT *pInitSecStart, *pInitSecEnd, *pInitTmp;

#if defined(__ICCARM__)
  
  pInitSecStart = __section_begin(".gs_initsection");
  pInitSecEnd   = __section_end(".gs_initsection");
  
#elif defined(__CC_ARM)
  
  pInitSecStart   = (T_INIT *)&Image$$GS_Init_Region$$Base;
  pInitSecEnd     = (T_INIT *)&Image$$GS_Init_Region$$Limit;
 
#elif defined(__GNUC__)
  
  pInitSecStart   = (T_INIT *)&__gs_init_section_start;
  pInitSecEnd     = (T_INIT *)&__gs_init_section_end;
   
#else
  
#error "Unsupported tool chain!"
  
#endif
  
  //count init handler number
  int iInitNum = pInitSecEnd - pInitSecStart;
  
  unsigned int i, iLvlTmp, iLvlMin = 0, iLvlMax = 0xffffffff;
  
  iLvlTmp = 0;
  
  while(iLvlMin <= iLvlMax && iInitNum > 0) {
    
    pInitTmp = pInitSecStart;
    for(i = 0; i < iInitNum && pInitTmp <= pInitSecEnd; ++i, ++pInitTmp) {
      
      if(iLvlMin == 0)
        iLvlMin = pInitTmp->initlvl;
      
      if(iLvlMax == 0xffffffff)
        iLvlMax = pInitTmp->initlvl;
      
      if(pInitTmp->initlvl > iLvlMax)
        iLvlMax = pInitTmp->initlvl;
      
      if((pInitTmp->initlvl > iLvlTmp && pInitTmp->initlvl < iLvlMin) ||
         (pInitTmp->initlvl > iLvlTmp && iLvlMin == iLvlTmp))
        iLvlMin = pInitTmp->initlvl;
      
      //run initHanddler
      if(pInitTmp->initlvl == iLvlTmp)
        pInitTmp->pfInitFunc();
    }
    
    if(iLvlTmp == iLvlMax)
      break;
    
    iLvlTmp = iLvlMin;    
  }
    
  return 0;
}

