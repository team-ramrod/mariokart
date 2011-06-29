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
/// !Purpose
///
/// Definition of AT91SAM3UX characteristics and features
///
/// !Usage
/// -# For ARM core feature, see "AT91SAM3UX - ARM core features".
/// -# For IP features, see "AT91SAM3UX - IP features".
/// -# For misc, see "AT91SAM3UX - Misc".
//------------------------------------------------------------------------------
 
#ifndef CHIP_H 
#define CHIP_H

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// \page "AT91SAM3UX - ARM core features"
/// This page lists several characteristics related to the ARM core
///

//ARM core features

/// ARM core definition.
#define cortexm3

/// family definition.
//#define at91sam3ux (already defined)

//------------------------------------------------------------------------------
/// \page "AT91SAM3UX - IP features"
/// This page lists several characteristics related to the embedded IP
///

//IP FEATURES

// EFC GPNVM number
#define CHIP_EFC_NUM_GPNVMS    3

/// Indicates chip has an Enhanced EFC. 
#define CHIP_FLASH_EEFC 

// DMA channels number
#define CHIP_DMA_CHANNEL_NUM   4

// Indicate chip's MCI interface. 
#define MCI2_INTERFACE

// Indicate chip has a hardware ECC engine. 
#define HARDWARE_ECC

/// Indicates chip has an OTG High Speed. 
#define CHIP_USB_OTGHS 

/// Indicates chip has an internal pull-up. 
#define CHIP_USB_PULLUP_INTERNAL 

/// Number of USB endpoints 
#define CHIP_USB_NUMENDPOINTS 10 

/// Endpoints max paxcket size 
#define CHIP_USB_ENDPOINTS_MAXPACKETSIZE(i) \
   ((i == 0) ? 64 : \
   ((i == 1) ? 1024 : \
   ((i == 2) ? 1024 : \
   ((i == 3) ? 1024 : \
   ((i == 4) ? 1024 : \
   ((i == 5) ? 1024 : \
   ((i == 6) ? 1024 : \
   ((i == 7) ? 1024 : \
   ((i == 8) ? 1024 : \
   ((i == 9) ? 1024 : 0 ))))))))))

/// Endpoints Number of Bank 
#define CHIP_USB_ENDPOINTS_BANKS(i) \
   ((i == 0) ? 1 : \
   ((i == 1) ? 3 : \
   ((i == 2) ? 3 : \
   ((i == 3) ? 2 : \
   ((i == 4) ? 2 : \
   ((i == 5) ? 2 : \
   ((i == 6) ? 2 : \
   ((i == 7) ? 2 : \
   ((i == 8) ? 2 : \
   ((i == 9) ? 2 : 0 ))))))))))

/// Endpoints max paxcket size 
#define CHIP_USB_ENDPOINTS_DMA(i) \
   ((i == 1) ? 1 : \
   ((i == 2) ? 1 : \
   ((i == 3) ? 1 : \
   ((i == 4) ? 1 : 0 ))))

//------------------------------------------------------------------------------
/// \page "AT91SAM3UX - Misc "
/// This page lists misc features
///

//Misc 

#endif //#ifndef CHIP_H

