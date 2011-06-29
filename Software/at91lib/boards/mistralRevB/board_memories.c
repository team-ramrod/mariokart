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
//  Title: Memories implementation
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "board.h"
#include "board_memories.h"
#include <pio/pio.h>

//------------------------------------------------------------------------------
//  Macros:
//      READ - Reads a register value. Useful to add trace information to read
//             accesses.
//      WRITE - Writes data in a register. Useful to add trace information to
//              write accesses.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Internal definitions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Constants: Remap types
//      BOARD_ROM - ROM or EBI CS0 is mirrored in the remap zone.
//      BOARD_RAM - RAM is mirrored in the remap zone.
//------------------------------------------------------------------------------
#define BOARD_ROM               0
#define BOARD_RAM               1

//------------------------------------------------------------------------------
//         Internal function
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//  Function: BOARD_RemapRom
//      Changes the mapping of the chip so that the remap area mirrors the
//      internal ROM or the EBI CS0.
//------------------------------------------------------------------------------
void BOARD_RemapRom( void )
{
    AT91C_BASE_MATRIX->MATRIX_MRCR = 0;
}

//------------------------------------------------------------------------------
// Function: BOARD_RemapRam
//     Changes the mapping of the chip so that the remap area mirrors the
//     internal RAM.
//------------------------------------------------------------------------------
void BOARD_RemapRam( void )
{
    AT91C_BASE_MATRIX->MATRIX_MRCR = (AT91C_MATRIX_RCA926I | AT91C_MATRIX_RCA926D);
}


//------------------------------------------------------------------------------
// Function: BOARD_ConfigureSdram
//     Initialize and configure the SDRAM
//------------------------------------------------------------------------------
void BOARD_ConfigureSdram(unsigned char busWidth)
{
  unsigned int i;
  volatile unsigned int *pSdram = (unsigned int *) AT91C_EBI0_SDRAM;

  // Program SDRAMC : CAS = 2, 4 banks, row = 12, column = 9 SDRAM 128MB 
  // 133MHz barrette NADIA + 32 bit mode
  AT91C_BASE_SDRAMC0->SDRAMC_CR =   AT91C_SDRAMC_NC_9   
                                  | AT91C_SDRAMC_NR_13
                                  | AT91C_SDRAMC_NB_4_BANKS
                                  | AT91C_SDRAMC_CAS_2
                                  | AT91C_SDRAMC_DBW_32_BITS
                                  | AT91C_SDRAMC_TWR_1
                                  | AT91C_SDRAMC_TRC_1
                                  | AT91C_SDRAMC_TRP_1
                                  | AT91C_SDRAMC_TRCD_1
                                  | AT91C_SDRAMC_TRAS_1
                                  | AT91C_SDRAMC_TXSR_1;

  AT91C_BASE_SDRAMC0->SDRAMC_MDR = AT91C_SDRAMC_MD_SDRAM;

  for (i =0; i< 1000;i++);

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_PRCGALL_CMD; // Set PRCHG AL
  pSdram[0] = 0x00000000;     // Perform PRCHG

  for (i =0; i< 10000;i++);

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_RFSH_CMD;    // Set 1st CBR
  pSdram[0] = 0x00000000;     // Perform CBR

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_RFSH_CMD;    // Set 2 CBR
  pSdram[0] = 0x00000000;     // Perform CBR

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_RFSH_CMD;    // Set 3 CBR
  pSdram[0] = 0x00000000;     // Perform CBR

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_RFSH_CMD;    // Set 4 CBR
  pSdram[0] = 0x00000000;     // Perform CBR

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_RFSH_CMD;    // Set 5 CBR
  pSdram[0] = 0x00000000;     // Perform CBR

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_RFSH_CMD;    // Set 6 CBR
  pSdram[0] = 0x00000000;     // Perform CBR

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_RFSH_CMD;    // Set 7 CBR
  pSdram[0] = 0x00000000;     // Perform CBR

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_RFSH_CMD;    // Set 8 CBR
  pSdram[0] = 0x00000000;     // Perform CBR

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_LMR_CMD;    // Set LMR operation
  pSdram[9] = 0xCAFEDADA; // Perform LMR burst=1, lat=2

  // Set Refresh Timer 390 for 25MHz (TR= 15.6 * F ) : (F : system clock freq. MHz)
  AT91C_BASE_SDRAMC0->SDRAMC_TR = (AT91C_SDRAMC_COUNT & (BOARD_MCK *15)/1000000);

  AT91C_BASE_SDRAMC0->SDRAMC_MR = AT91C_SDRAMC_MODE_NORMAL_CMD;    // Set Normal mode
  pSdram[0] = 0x00000000;     // Perform Normal mode

  AT91C_BASE_SDRAMC0->SDRAMC_HSR = AT91C_SDRAMC_DA_ENABLE;    // Set Decode Cycle NECESAIRE pour NADIA a 22MHz 25aug03

  pSdram[20] = 0xD4C3B2A1; // test

}

