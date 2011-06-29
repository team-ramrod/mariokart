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
//-----------------------------------------------------------------------------
#include <string.h>
#include <stdlib.h>

#include "dfm_cmd.h"
#include "dfm_lcd_tsd.h"

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Portal for 'slidepage' command
//  \param argc, number of argument
//  \param argv, argument string array
//  \return 0 succeed, other value failure
//------------------------------------------------------------------------------
int DFM_SlidePage(int argc, char **argv)
{
  unsigned char file[32];
  if(argc == 2 && strcmp(argv[1], "next") == 0) {
    ++gActiveSlideIndex;
  }
  
  if(argc == 2 && strcmp(argv[1], "previous") == 0) {
    --gActiveSlideIndex;
  }
  
  if(argc == 3 && strcmp(argv[1], "goto") == 0) {
    gActiveSlideIndex = atoi(argv[2]) - 1;
  }
  
  return 0;
}

//define a new command 'slidepage' for change slide page
DFM_CMD(slidepage, DFM_SlidePage, "Change display slide", "default");
