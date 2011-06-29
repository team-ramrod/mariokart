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
/// !Purpose
///
/// Definition of methods for ISO7816 driver.
/// 
/// !Usage
/// 
/// -# ISO7816_Init
/// -# ISO7816_IccPowerOff
/// -# ISO7816_XfrBlockTPDU_T0
/// -# ISO7816_Escape
/// -# ISO7816_RestartClock
/// -# ISO7816_StopClock
/// -# ISO7816_toAPDU
/// -# ISO7816_Datablock_ATR
/// -# ISO7816_SetDataRateandClockFrequency
/// -# ISO7816_StatusReset
/// -# ISO7816_cold_reset
/// -# ISO7816_warm_reset
/// -# ISO7816_Decode_ATR
//------------------------------------------------------------------------------

#ifndef ISO7816_4_H
#define ISO7816_4_H

//------------------------------------------------------------------------------
// Constants Definition
//------------------------------------------------------------------------------

/// Size max of Answer To Reset
#define ATR_SIZE_MAX            55

/// NULL byte to restart byte procedure
#define ISO_NULL_VAL            0x60

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
extern void ISO7816_Init( const Pin pPinIso7816RstMC );
extern void ISO7816_IccPowerOff(void);
extern unsigned short ISO7816_XfrBlockTPDU_T0(const unsigned char *pAPDU, 
                                        unsigned char *pMessage, 
                                        unsigned short wLength );
extern void ISO7816_Escape( void );
extern void ISO7816_RestartClock(void);
extern void ISO7816_StopClock( void );
extern void ISO7816_toAPDU( void );
extern void ISO7816_Datablock_ATR( unsigned char* pAtr, unsigned char* pLength );
extern void ISO7816_SetDataRateandClockFrequency( unsigned int dwClockFrequency, unsigned int dwDataRate );
extern unsigned char ISO7816_StatusReset( void );
extern void ISO7816_cold_reset( void );
extern void ISO7816_warm_reset( void );
extern void ISO7816_Decode_ATR( unsigned char* pAtr );

#endif // ISO7816_4_H

