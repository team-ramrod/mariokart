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
 * - Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the disclaimer below in the documentation and/or
 * other materials provided with the distribution.
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

/*
     Title: Memories implementation
*/

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include <board.h>
#include <pio/pio.h>
#include "board_memories.h"

/*
    Macros:
        READ - Reads a register value. Useful to add trace information to read
               accesses.
        WRITE - Writes data in a register. Useful to add trace information to
                write accesses.
*/

#define READ(peripheral, register)          (peripheral->register)
#define WRITE(peripheral, register, value)  (peripheral->register = value)

//------------------------------------------------------------------------------
//         Internal definitions
//------------------------------------------------------------------------------
/*
    Constants: Remap types
        BOARD_ROM - ROM or EBI CS0 is mirrored in the remap zone.
        BOARD_RAM - RAM is mirrored in the remap zone.
*/

#define BOARD_ROM               0
#define BOARD_RAM               1

//------------------------------------------------------------------------------
//         Internal functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/// Returns the current remap (see <Remap types>).
//------------------------------------------------------------------------------
static unsigned char BOARD_GetRemap()
{
    volatile unsigned int *remap = (volatile unsigned int *) 0;
    volatile unsigned int *ram = (volatile unsigned int *) AT91C_IRAM;
    // Try to write in 0 and see if this affects the RAM
    unsigned int temp = *ram;
    *ram = temp + 1;
    if (*remap == *ram) {

        *ram = temp;
        return BOARD_RAM;
    }
    else {

        *ram = temp;
        return BOARD_ROM;
    }
}

//------------------------------------------------------------------------------
/// Use in SDRAM and DDRAM configuration
//------------------------------------------------------------------------------
void sleep_time(unsigned int timeval)
{
    unsigned int i;
    for( i=0; i<timeval; i++);
}

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Initialize Vdd EBI external memory
//------------------------------------------------------------------------------
int BOARD_ConfigureVddMemSel(unsigned char VddMemSel)
{
    return 0;
}

//------------------------------------------------------------------------------
/// Changes the mapping of the chip so that the remap area mirrors the
///   internal ROM or the EBI CS0.
//------------------------------------------------------------------------------
void BOARD_RemapRom()
{
  if (BOARD_GetRemap() != BOARD_ROM)
  {
    WRITE(AT91C_BASE_MATRIX, MATRIX_MRCR, 0);
  }
}

//------------------------------------------------------------------------------
/// Changes the mapping of the chip so that the remap area mirrors the
///   internal RAM.
//------------------------------------------------------------------------------
void BOARD_RemapRam()
{
  if (BOARD_GetRemap() != BOARD_RAM)
  {
    WRITE(AT91C_BASE_MATRIX, MATRIX_MRCR, (AT91C_MATRIX_RCB0_ARM7TDMI | AT91C_MATRIX_RCB1_PDC));
  }
}

//------------------------------------------------------------------------------
/// Initialize and configure the SDRAM
//------------------------------------------------------------------------------

#define AT91C_SDRAM      ((volatile unsigned int *)0x20000000)
#define SDRAM_TOP        0x24000000    // 64 MByte
#define SDRAM_BASE       0x20000000    //

void BOARD_ConfigureSdram(unsigned char busWidth)
{
    volatile unsigned int i=0;
    static const Pin pinsSdram[] = {PINS_SDRAM};
    volatile unsigned int *pSdram = (unsigned int *) AT91C_EBI_SDRAM;
    unsigned short sdrc_dbw = 0;

    switch (busWidth) {
	        case 16:
	            sdrc_dbw = AT91C_SDRAMC_DBW_16_BITS;
	            break;

	        case 32:
	        default:
	            sdrc_dbw = AT91C_SDRAMC_DBW_32_BITS;
	            break;

    }

    // Enable EBI chip select for the SDRAM
    AT91C_BASE_MATRIX->MATRIX_EBICSA |= AT91C_MATRIX_EBI_CS1A_SDRAMC;

    // Enable corresponding PIOs
    PIO_Configure(pinsSdram, 1);

    // CFG Control Register
    WRITE(AT91C_BASE_SDRAMC, SDRAMC_CR  , ( AT91C_SDRAMC_TXSR_10       |
			                    AT91C_SDRAMC_TRAS_6       |
			                    AT91C_SDRAMC_TRCD_3       |
			                    AT91C_SDRAMC_TRP_3        |
			                    AT91C_SDRAMC_TRC_9        |
			                    AT91C_SDRAMC_TWR_2        |
			                    sdrc_dbw                  |
			                    AT91C_SDRAMC_CAS_2        |
			                    AT91C_SDRAMC_NB_4_BANKS   |
			                    AT91C_SDRAMC_NR_13        |
			                    AT91C_SDRAMC_NC_9));          // row = 13, column = 9 SDRAM CAS = 3

    // CFG Memory Device Register
    WRITE(AT91C_BASE_SDRAMC, SDRAMC_MDR, AT91C_SDRAMC_MD_SDRAM);

    // Wait for at least 200us
    for (i = 0; i < 3000; i++);

    // Perform NOP
    WRITE(AT91C_BASE_SDRAMC, SDRAMC_MR, AT91C_SDRAMC_MODE_NOP_CMD) ;
    pSdram[0] = 0x00000000;

    // Perform All Bank Precharge
    WRITE(AT91C_BASE_SDRAMC, SDRAMC_MR, AT91C_SDRAMC_MODE_PRCGALL_CMD) ;
    pSdram[0] = 0x00000000;

    // Perform 8 CBR cycles
    WRITE(AT91C_BASE_SDRAMC, SDRAMC_MR, AT91C_SDRAMC_MODE_RFSH_CMD) ;
    for (i = 0 ; i < 8 ; i++)
    {
        pSdram[0] = 0x00000000;
    }

    // Program the SDRAM
    // Perform LMR operation
    WRITE(AT91C_BASE_SDRAMC, SDRAMC_MR, AT91C_SDRAMC_MODE_LMR_CMD) ;
    pSdram[0] = 0x00000000;

    // Set Normal CTRL
    WRITE(AT91C_BASE_SDRAMC, SDRAMC_MR, AT91C_SDRAMC_MODE_NORMAL_CMD) ;
    pSdram[0] = 0x00000000;

    // Set Refresh timer
    //pSDRAMC->SDRAMC_TR = sdram_Ptr->sdram_tr;
    WRITE(AT91C_BASE_SDRAMC, SDRAMC_TR, 375); //Refresh Timer (ex: ((64 x 10^-3)/8192) x 48 x 10^6 ) => 375 or 0x177 for MCK 48 MHz

    //SDRAM is ready to use
}

//------------------------------------------------------------------------------
/// Configures the EBI for NandFlash access
/// \Param busWidth Bus width
//------------------------------------------------------------------------------
void BOARD_ConfigureNandFlash(unsigned char busWidth)
{
    // Configure EBI
    AT91C_BASE_MATRIX->MATRIX_EBICSA |= AT91C_MATRIX_EBI_CS3A_SM;

    AT91C_BASE_SMC->SMC_SETUP3 = ((AT91C_SMC_NWESETUP & (0x1)) |
                                 ( AT91C_SMC_NCSSETUPWR & (0x1<<8)) |
                                 ( AT91C_SMC_NRDSETUP & (0x1<<16)) |
                                 ( AT91C_SMC_NCSSETUPRD & (0x1<<24)));

    AT91C_BASE_SMC->SMC_PULSE3 = (( AT91C_SMC_NCSPULSERD & (0x03 <<24)) |
                                  ( AT91C_SMC_NRDPULSE &  (0x02 <<16)) |
                                  ( AT91C_SMC_NCSPULSEWR & (0x03 <<8)) |
                                  ( AT91C_SMC_NWEPULSE & 0x02));

    AT91C_BASE_SMC->SMC_CYCLE3 = ((AT91C_SMC_NRDCYCLE & (0x06<<16)) |
                                 ( AT91C_SMC_NWECYCLE & 0x06));

    AT91C_BASE_SMC->SMC_CTRL3 =  ( AT91C_SMC_BAT_BYTE_WRITE |
                                   AT91C_SMC_READMODE |
                                   AT91C_SMC_WRITEMODE |
                                   AT91C_SMC_DBW_WIDTH_EIGTH_BITS |
                                  (AT91C_SMC_TDF & (0x2 <<16)));

    if (busWidth == 8) {

        AT91C_BASE_SMC->SMC_CTRL3 |= AT91C_SMC_DBW_WIDTH_EIGTH_BITS;
    }
    else if (busWidth == 16) {

        AT91C_BASE_SMC->SMC_CTRL3 |= AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS;
    }
    else if (busWidth == 32) {

        AT91C_BASE_SMC->SMC_CTRL3 |= AT91C_SMC_DBW_WIDTH_THIRTY_TWO_BITS;
    }
}

//------------------------------------------------------------------------------
/// Configures the EBI for NandFlash access at 48MHz.
/// \Param busWidth Bus width
//------------------------------------------------------------------------------
void BOARD_ConfigureNandFlash48MHz(unsigned char busWidth)
{
    // Configure EBI
    AT91C_BASE_MATRIX->MATRIX_EBICSA |= AT91C_MATRIX_EBI_CS3A_SM;

    // Configure SMC

    AT91C_BASE_SMC->SMC_SETUP3 = 0x00010001;
    AT91C_BASE_SMC->SMC_PULSE3 = 0x04030302;
    AT91C_BASE_SMC->SMC_CYCLE3 = 0x00070004;

    AT91C_BASE_SMC->SMC_CTRL3  = (AT91C_SMC_READMODE
                                  | AT91C_SMC_WRITEMODE
                                  | AT91C_SMC_NWAITM_NWAIT_DISABLE
                                  | ((0x1 << 16) & AT91C_SMC_TDF));

    if (busWidth == 8) {

        AT91C_BASE_SMC->SMC_CTRL3 |= AT91C_SMC_DBW_WIDTH_EIGTH_BITS;
    }
    else if (busWidth == 16) {

        AT91C_BASE_SMC->SMC_CTRL3 |= AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS;
    }
    else if (busWidth == 32) {

        AT91C_BASE_SMC->SMC_CTRL3 |= AT91C_SMC_DBW_WIDTH_THIRTY_TWO_BITS;
    }
}

//------------------------------------------------------------------------------
// Configures the EBI for NorFlash access
// \Param busWidth Bus width
//------------------------------------------------------------------------------
void BOARD_ConfigureNorFlash(unsigned char busWidth)
{
    // Configure SMC

    AT91C_BASE_SMC->SMC_SETUP0 = 0x00000002;
    AT91C_BASE_SMC->SMC_PULSE0 = 0x0A0A0A06;
    AT91C_BASE_SMC->SMC_CYCLE0 = 0x000A000A;
    AT91C_BASE_SMC->SMC_CTRL0  = (AT91C_SMC_READMODE
                                  | AT91C_SMC_WRITEMODE
                                  | AT91C_SMC_NWAITM_NWAIT_DISABLE
                                  | ((0x1 << 16) & AT91C_SMC_TDF));

    if (busWidth == 8) {
        AT91C_BASE_SMC->SMC_CTRL0 |= AT91C_SMC_DBW_WIDTH_EIGTH_BITS;
    }
    else if (busWidth == 16) {
        AT91C_BASE_SMC->SMC_CTRL0 |= AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS;
    }
    else if (busWidth == 32) {
        AT91C_BASE_SMC->SMC_CTRL0 |= AT91C_SMC_DBW_WIDTH_THIRTY_TWO_BITS;
    }
}

//------------------------------------------------------------------------------
/// Configures the EBI for NorFlash access at 48MHz.
/// \Param busWidth Bus width
//------------------------------------------------------------------------------
void BOARD_ConfigureNorFlash48MHz(unsigned char busWidth)
{
    AT91C_BASE_SMC->SMC_SETUP0 = 0x02040204;
    AT91C_BASE_SMC->SMC_PULSE0 = 0x0A080A08;
    AT91C_BASE_SMC->SMC_CYCLE0 = 0x00100010;

    AT91C_BASE_SMC->SMC_CTRL0  = (AT91C_SMC_READMODE
                                  | AT91C_SMC_WRITEMODE
                                  | AT91C_SMC_NWAITM_NWAIT_DISABLE
                                  | ((0x1 << 16) & AT91C_SMC_TDF));

    if (busWidth == 8) {

        AT91C_BASE_SMC->SMC_CTRL0 |= AT91C_SMC_DBW_WIDTH_EIGTH_BITS;
    }
    else if (busWidth == 16) {

        AT91C_BASE_SMC->SMC_CTRL0 |= AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS;
    }
    else if (busWidth == 32) {

        AT91C_BASE_SMC->SMC_CTRL0 |= AT91C_SMC_DBW_WIDTH_THIRTY_TWO_BITS;
    }
}

