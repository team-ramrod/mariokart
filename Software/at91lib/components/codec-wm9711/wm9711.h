/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support 
 * ----------------------------------------------------------------------------
 * Copyright (c) 2009, Atmel Corporation
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


#ifndef AC97_WM9711_H
#define AC97_WM9711_H

//------------------------------------------------------------------------------
//         External constants
//------------------------------------------------------------------------------
#define WM9711_CMD(cmd, data) (((cmd << 16) & AT91C_AC97C_CADDR) | data)


#define WM9711_RESET              0x00

#define WM9711_LRVOLUME           0x02

#define WM9711_HPVOLUME           0x04

#define WM9711_MONOVOLUME         0x06

#define WM9711_DACTONECTL         0x08

#define WM9711_PCBEEPINPUT        0x0A

#define WM9711_PHONEVOLUME        0x0C

#define WM9711_MICVOLUME          0x0E

#define WM9711_LINEINVOLUME       0x10

#define WM9711_AUXDACVOLUME       0x12

#define WM9711_SIDETONEVOLUME     0x14

#define WM9711_OUT3VOLUME         0x16

#define WM9711_DACVOLUME          0x18

#define WM9711_RECORDSEL          0x1A

#define WM9711_RECORDGAIN         0x1C

#define WM9711_GENERALPURPOSE     0x20

#define WM9711_DAC3DCTL           0x22

#define WM9711_POWERDOWN          0x24

#define WM9711_POWERDOWNCTL       0x26

#define WM9711_EXAUDIOID          0x28

#define WM9711_EXAUDIOCTL         0x2A

#define WM9711_DACSAMPLERATE      0x2C

#define WM9711_AUXDACSAMPLERATE   0x2E

#define WM9711_ADCSAMPLERATE      0x32

#define WM9711_SPDIFCTL           0x3A

#define WM9711_PINCONFIG          0x4C

#define WM9711_PINPOL             0x4E

#define WM9711_PINSTICKY          0x50

#define WM9711_PINWAKEUP          0x52

#define WM9711_PINSTATUS          0x54

#define WM9711_PINASSIGNMENT      0x56

#define WM9711_PINFUNCTIONS       0x58

#define WM9711_VENDORRESERVED1    0x5A

#define WM9711_FUNCTIONCTL        0x5C

#define WM9711_VENDORRESERVED2    0x5E

#define WM9711_ALCCTL             0x60

#define WM9711_NOISECTL           0x62

#define WM9711_AUXDACINPUT        0x64

#define WM9711_VENDOR_ID1         0x7C		           // Vendor 1

#define WM9711_VENDOR_ID2         0x7E             // Vendor 2

#define WM9711_ID_1	              0x574D           //ASCII "W" "M"

#define WM9711_ID_2	              0x4C12           //ASCII "L" number "12"

#endif //#ifndef AC97_WM9711_H
