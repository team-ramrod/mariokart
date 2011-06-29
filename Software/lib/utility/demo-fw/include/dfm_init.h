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

#ifndef __DFM_INIT_
#define __DFM_INIT_

//struct definition for init interface
typedef struct _t_init {
  unsigned int initlvl;
  int (*pfInitFunc)(void);
} T_INIT;


#if defined(__GNUC__) //GNU C compiler, Keil also supported if --gnu is defined in CFLAG

#define OBJ_HEAD const
#define INSECTION(secname) __attribute__ ((unused, section(secname)))

#elif defined(__ICCARM__) //ICCARM compiler

#pragma section = ".gs_initsection"

#define OBJ_HEAD  __root const
#define INSECTION(secname) @ secname

#else

/// current only GNUC(keil MDK), IAR EWARM compiler are supported!
#error "unsupported tool chain"

#endif

/// define a general macro for init function operation management
#define DFM_INIT(initlvl, initFunc)   \
  OBJ_HEAD T_INIT _gs_init_##initFunc##initlvl INSECTION(".gs_initsection")  = {\
                initlvl, \
                initFunc\
      }

//run all init handler from starting from level 1
unsigned int RunAllInit();

#endif

