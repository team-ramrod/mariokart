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
/// \unit
///
/// This file contains apis and definitions for tilt sensing.
///
//------------------------------------------------------------------------------
 
#ifndef DV_ACCELEROMETER_H
#define DV_ACCELEROMETER_H

#include "dfm_entry.h"
 
#define ACC_SHIFT 0                           //!< Accelerometer filtering value
#define ACC_ZERO  (0x7FF >> ACC_SHIFT)        //!< Accelerometer 0 value 0x1000/2
#define ACC_1G    (0x223 >> ACC_SHIFT)        //!< Accelerometer 1G value 2.09/3.3 * 0x1000 delta 1g

#define ACC_ZERO_X  ACC_ZERO
#define ACC_ZERO_Y  ACC_ZERO
#define ACC_ZERO_Z  ACC_ZERO

#define ACC_AMPLITUDE_UPPER  (ACC_1G*ACC_1G*1.01)
#define ACC_AMPLITUDE_LOWER  (ACC_1G*ACC_1G*0.99)

#define  DV_Accelerometer_Unchanged  0      //!< default unchanged direction
#define  DV_Accelerometer_normal_up  1      //!< normal up
#define  DV_Accelerometer_up         2      //!< up 
#define  DV_Accelerometer_down       3      //!< down
#define  DV_Accelerometer_left       4      //!< left
#define  DV_Accelerometer_right      5      //!< right

#define  DV_Accelerometer_up_right      6   //!< up and right
#define  DV_Accelerometer_up_left       7   //!< up and left
#define  DV_Accelerometer_down_left     8   //!< down and left
#define  DV_Accelerometer_down_right    9   //!< down and right

#define DIR_UNCHANGED              0
#define DIR_HORIZIONTAL_UP         1
#define DIR_HORIZIONTAL_DOWN       2
#define DIR_VERTICAL_UP            3
#define DIR_VERTICAL_DOWN          4

typedef struct { 
  int x; 
  int y; 
  int z; 
} xyz_t;


typedef struct {
  xyz_t m;                                  //!< immediate acceleration   
  xyz_t k;                                  //!< calibration basis
  xyz_t ak;                                 //!< acceleration difference
 } acc_t;

extern int gDir;

extern TInputEntry gAccEntry ;
extern unsigned int gLcdRefreshFlag;
extern int DV_ACCELEROMETER_Init(void);
extern void DV_Accelerometer_Turn();
extern int DV_Check_AccStatus();
extern void DV_ACCELEROMETER_Measure(void);

#endif
