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
//         Internal functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
/// Changes the mapping of the chip so that the remap area mirrors the
///   internal ROM or the EBI CS0.
//------------------------------------------------------------------------------
void BOARD_RemapRom()
{
    WRITE(AT91C_BASE_MATRIX, MATRIX_MRCR, 0);
}

//------------------------------------------------------------------------------
/// Changes the mapping of the chip so that the remap area mirrors the
///   internal RAM.
//------------------------------------------------------------------------------
void BOARD_RemapRam()
{
    WRITE(AT91C_BASE_MATRIX,
          MATRIX_MRCR,
          (AT91C_MATRIX_RCA926I | AT91C_MATRIX_RCA926D));
}

//------------------------------------------------------------------------------
/// Configure DDR
//------------------------------------------------------------------------------
void BOARD_ConfigureDdram(unsigned char ddrModel, unsigned char busWidth)
{    
    AT91PS_HDDRSDRC2 pDdrc = AT91C_BASE_DDR2C;
    volatile unsigned int *pDdr = (unsigned int *) AT91C_DDR2;
    int i;
    volatile unsigned int cr = 0;
    unsigned short ddrc_dbw = 0;

    switch (busWidth) {
        case 16:
        default:
            ddrc_dbw = AT91C_DDRC2_DBW_16_BITS;
            break;

        case 32:
            ddrc_dbw = AT91C_DDRC2_DBW_32_BITS;
            break;

    }

    // Enable DDR2 clock x2 in PMC
    WRITE(AT91C_BASE_PMC, PMC_SCER, AT91C_PMC_DDR);


    switch (ddrModel) {

        case DDR_MICRON_MT47H64M8: 

            // Configure the DDR controller
            WRITE(pDdrc, HDDRSDRC2_MDR, ddrc_dbw   |
                                        AT91C_DDRC2_MD_DDR2_SDRAM);     // DDR2

            // Program the DDR Controller
            WRITE(pDdrc, HDDRSDRC2_CR, AT91C_DDRC2_NC_DDR10_SDR9  |     // 10 column bits (1K)
                                       AT91C_DDRC2_NR_14          |     // 14 row bits    (8K)
                                       AT91C_DDRC2_CAS_3          |     // CAS Latency 3
                                       AT91C_DDRC2_DLL_RESET_DISABLED
                                       ); // DLL not reset

            // assume timings for 7.5ns min clock period
            WRITE(pDdrc, HDDRSDRC2_T0PR, AT91C_DDRC2_TRAS_6       |     //  6 * 7.5 = 45   ns
                                         AT91C_DDRC2_TRCD_3       |     //  3 * 7.5 = 22.5 ns
                                         AT91C_DDRC2_TWR_2        |     //  2 * 7.5 = 15   ns
                                         AT91C_DDRC2_TRC_10       |     // 10 * 7.5 = 75   ns
                                         AT91C_DDRC2_TRP_3        |     //  3 * 7.5 = 22.5 ns
                                         AT91C_DDRC2_TRRD_2       |     //  2 * 7.5 = 15   ns
                                         AT91C_DDRC2_TWTR_1       |     //  1 clock cycle
                                         AT91C_DDRC2_TMRD_2);           //  2 clock cycles

            // pSDDRC->HDDRSDRC2_T1PR = 0x00000008;
            WRITE(pDdrc, HDDRSDRC2_T1PR, AT91C_DDRC2_TXP_2  |           //  2 * 7.5 = 15 ns
                                         200 << 16          |           // 200 clock cycles, TXSRD: Exit self refresh delay to Read command
                                         27 << 8            |           // 27 * 7.5 = 202 ns TXSNR: Exit self refresh delay to non read command
                                         AT91C_DDRC2_TRFC_19 << 0);     // 19 * 7.5 = 142 ns (must be 140 ns for 1Gb DDR)

            WRITE(pDdrc, HDDRSDRC2_T2PR, AT91C_DDRC2_TRTP_2   |         //  2 * 7.5 = 15 ns
                                         AT91C_DDRC2_TRPA_2   |         //  2 * 7.5 = 15 ns
                                         AT91C_DDRC2_TXARDS_7 |         //  7 clock cycles
                                         AT91C_DDRC2_TXARD_2);          //  2 clock cycles

        /*   pSDDRC->HDDRSDRC2_LPR = ( 5 << 16  |  // TXSRD: Exit self refresh delay to Read command */
        /*                          5 <<  8  |  // TXSNR: Exit self refresh delay to non read command */
        /*                          8 <<  0     // TRFC :row cycle delay */
        /*                                     ); */

            // Initialization Step 1 + 2: NOP command -> allow to enable clk
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_NOP_CMD);
            *pDdr = 0;
 
            // Initialization Step 3 (must wait 200 us) (6 core cycles per iteration, core is at 396MHz: min 13200 loops)
            for (i = 0; i < 13300; i++) {
                asm("    nop");
            }

            // NOP command -> allow to enable cke
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_NOP_CMD);
            *pDdr = 0;
            
            // wait 400 ns min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 4: Set All Bank Precharge
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_PRCGALL_CMD);
            *pDdr = 0;
            
            // wait 400 ns min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 5: Set EMR operation (EMRS2)
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_EXT_LMR_CMD);
            *((unsigned int *)((unsigned char *)pDdr + 0x4000000)) = 0;
         
            // wait 2 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 6: Set EMR operation (EMRS3)
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_EXT_LMR_CMD);
            *((unsigned int *)((unsigned char *)pDdr + 0x6000000)) = 0;

            // wait 2 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 7: Set EMR operation (EMRS1)
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_EXT_LMR_CMD);
            *((unsigned int *)((unsigned char *)pDdr + 0x2000000)) = 0;

            // wait 2 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 8a: enable DLL reset
            cr = READ(pDdrc, HDDRSDRC2_CR);
            WRITE(pDdrc, HDDRSDRC2_CR, cr | AT91C_DDRC2_DLL_RESET_ENABLED);
            
            // Initialization Step 8b: reset DLL
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_EXT_LMR_CMD);
            //*(pDdr) = 0;

            // wait 2 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 9: Set All Bank Precharge
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_PRCGALL_CMD);
            *(pDdr) = 0;

            // wait 400 ns min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 11: Set 1st CBR
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_RFSH_CMD);
            *(pDdr) = 0;

            // wait 10 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }


            // Set 2nd CBR
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_RFSH_CMD);
            *(pDdr) = 0;

            // wait 10 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 12: disable DLL reset
            cr = READ(pDdrc, HDDRSDRC2_CR);
            WRITE(pDdrc, HDDRSDRC2_CR, cr & (~AT91C_DDRC2_DLL_RESET_ENABLED));

            // Initialization Step 13: Set LMR operation
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_LMR_CMD);
            *(pDdr) = 0;
         
            // Skip Initialization Step 14 to 17 (not supported by the DDR2 model)

            // Initialization Step 18: Set Normal mode
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_NORMAL_CMD);
            *(pDdr) = 0;

            //allow to do calibration of DLL
            // address is used to avoid to corrupt bank 0 (in case of preloaded data) data value does not matter
//          *(pDdr + (2 * ddrBankSizeInWord)) = 0x0000FFFF;

            // WRITE(DDRSDR_BASE + (2*__DDR_BANK_SIZE) + 4, 0x0000FFFF);
            // data value should not matter but needs to set it to 0xaa5555aa to work around issue in HDDRSDRC2
//          *(pDdr + (2 * ddrBankSizeInWord + 4)) = 0xAA5555AA;

            // Set Refresh timer
            WRITE(pDdrc, HDDRSDRC2_RTR, 0x00000410);

            // OK now we are ready to work on the DDRSDR

            // wait for end of calibration
            for (i = 0; i < 500; i++) {
                asm("    nop");
            }

            break;


        case DDR_SAMSUNG_M470T6554EZ3_CE6:

            // Configure the DDR controller
            WRITE(pDdrc, HDDRSDRC2_MDR, ddrc_dbw   |
                                        AT91C_DDRC2_MD_DDR2_SDRAM);     // DDR2

            // Program the DDR Controller
            WRITE(pDdrc, HDDRSDRC2_CR, AT91C_DDRC2_NC_DDR10_SDR9  |     // 10 column bits (1K)
                                       AT91C_DDRC2_NR_13          |     // 13 row bits    (8K)
                                       AT91C_DDRC2_CAS_3          |     // CAS Latency 3
                                       AT91C_DDRC2_DLL_RESET_DISABLED); // DLL not reset

            // assume timings for 7.5ns min clock period
            WRITE(pDdrc, HDDRSDRC2_T0PR, AT91C_DDRC2_TRAS_6       |     //  6 * 7.5 = 45   ns
                                         AT91C_DDRC2_TRCD_3       |     //  3 * 7.5 = 22.5 ns
                                         AT91C_DDRC2_TWR_2        |     //  2 * 7.5 = 15   ns
                                         AT91C_DDRC2_TRC_10       |     // 10 * 7.5 = 75   ns
                                         AT91C_DDRC2_TRP_3        |     //  3 * 7.5 = 22.5 ns
                                         AT91C_DDRC2_TRRD_2       |     //  2 * 7.5 = 15   ns
                                         AT91C_DDRC2_TWTR_1       |     //  1 clock cycle
                                         AT91C_DDRC2_TMRD_2);           //  2 clock cycles

            // pSDDRC->HDDRSDRC2_T1PR = 0x00000008;
            WRITE(pDdrc, HDDRSDRC2_T1PR, AT91C_DDRC2_TXP_2  |           //  2 * 7.5 = 15 ns
                                         200 << 16          |           // 200 clock cycles, TXSRD: Exit self refresh delay to Read command
                                         27 << 8            |           // 27 * 7.5 = 202 ns TXSNR: Exit self refresh delay to non read command
                                         AT91C_DDRC2_TRFC_19 << 0);     // 19 * 7.5 = 142 ns (must be 140 ns for 1Gb DDR)

            WRITE(pDdrc, HDDRSDRC2_T2PR, AT91C_DDRC2_TRTP_2   |         //  2 * 7.5 = 15 ns
                                         AT91C_DDRC2_TRPA_2   |         //  2 * 7.5 = 15 ns
                                         AT91C_DDRC2_TXARDS_7 |         //  7 clock cycles
                                         AT91C_DDRC2_TXARD_2);          //  2 clock cycles

            /*   pSDDRC->HDDRSDRC2_LPR = ( 5 << 16  |  // TXSRD: Exit self refresh delay to Read command */
            /*                          5 <<  8  |  // TXSNR: Exit self refresh delay to non read command */
            /*                          8 <<  0     // TRFC :row cycle delay */
            /*                                     ); */

            // Initialization Step 1 + 2: NOP command -> allow to enable clk
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_NOP_CMD);
            *pDdr = 0;

            // TODO Initialization Step 3 (must wait 200 us) (6 core cycles per iteration, core is at 396MHz: min 13200 loops)
            for (i = 0; i < 13300; i++) {
                asm("    nop");
            }

            // NOP command -> allow to enable cke
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_NOP_CMD);
            *pDdr = 0;

            // wait 400 ns min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 4: Set All Bank Precharge
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_PRCGALL_CMD);
            *pDdr = 0;

            // wait 400 ns min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 5: Set EMR operation (EMRS2)
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_EXT_LMR_CMD);
            *((unsigned int *)((unsigned char *)pDdr + 0x2000000)) = 0;

            // wait 2 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 6: Set EMR operation (EMRS3)
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_EXT_LMR_CMD);
            *((unsigned int *)((unsigned char *)pDdr + 0x3000000)) = 0;

            // wait 2 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 7: Set EMR operation (EMRS1)
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_EXT_LMR_CMD);
            *((unsigned int *)((unsigned char *)pDdr + 0x1000000)) = 0;

            // wait 2 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 8a: enable DLL reset
            cr = READ(pDdrc, HDDRSDRC2_CR);
            WRITE(pDdrc, HDDRSDRC2_CR, cr | AT91C_DDRC2_DLL_RESET_ENABLED);

            // Initialization Step 8b: reset DLL
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_EXT_LMR_CMD);
            //    *(pDdr) = 0;

            // wait 2 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 9: Set All Bank Precharge
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_PRCGALL_CMD);
            *(pDdr) = 0;

            // wait 400 ns min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 11: Set 1st CBR
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_RFSH_CMD);
            *(pDdr) = 0;

            // wait 10 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }


            // Set 2nd CBR
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_RFSH_CMD);
            *(pDdr) = 0;

            // wait 10 cycles min
            for (i = 0; i < 100; i++) {
                asm("    nop");
            }

            // Initialization Step 12: disable DLL reset
            cr = READ(pDdrc, HDDRSDRC2_CR);
            WRITE(pDdrc, HDDRSDRC2_CR, cr & (~AT91C_DDRC2_DLL_RESET_ENABLED));

            // Initialization Step 13: Set LMR operation
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_LMR_CMD);
            *(pDdr) = 0;

            // Skip Initialization Step 14 to 17 (not supported by the DDR2 model)

            // Initialization Step 18: Set Normal mode
            WRITE(pDdrc, HDDRSDRC2_MR, AT91C_DDRC2_MODE_NORMAL_CMD);
            *(pDdr) = 0;

            //allow to do calibration of DLL
            // address is used to avoid to corrupt bank 0 (in case of preloaded data) data value does not matter
            //    *(pDdr + (2 * ddrBankSizeInWord)) = 0x0000FFFF;

            // WRITE(DDRSDR_BASE + (2*__DDR_BANK_SIZE) + 4, 0x0000FFFF);
            // data value should not matter but needs to set it to 0xaa5555aa to work around issue in HDDRSDRC2
            //    *(pDdr + (2 * ddrBankSizeInWord + 4)) = 0xAA5555AA;

            // Set Refresh timer
            WRITE(pDdrc, HDDRSDRC2_RTR, 0x00000410); // = (64ms/8192)/7.8ns

            // OK now we are ready to work on the DDRSDR

            // wait for end of calibration
            for (i = 0; i < 500; i++) {
                asm("    nop");
            }

            break;


        default:
            break;
    }
}


//------------------------------------------------------------------------------
/// Initialize and configure the SDRAM
//------------------------------------------------------------------------------
void BOARD_ConfigureSdram(unsigned char busWidth)
{

    // TO BE IMPLEMENTED IN CASE SDRAM IS MOUNTED.

}

//------------------------------------------------------------------------------
/// Configures the EBI for NandFlash access. Pins must be configured after or
/// before calling this function.
//------------------------------------------------------------------------------
void BOARD_ConfigureNandFlash(unsigned char busWidth)
{
    // Configure EBI
    AT91C_BASE_CCFG->CCFG_EBICSA |= AT91C_EBI_CS3A_SM;

    // Configure SMC
    AT91C_BASE_SMC->SMC_SETUP3 = 0x00020002;
    AT91C_BASE_SMC->SMC_PULSE3 = 0x04040404;
    AT91C_BASE_SMC->SMC_CYCLE3 = 0x00070007;
    AT91C_BASE_SMC->SMC_CTRL3  = 0x00030003;

    if (busWidth == 8) {

        AT91C_BASE_SMC->SMC_CTRL3 |= AT91C_SMC_DBW_WIDTH_EIGTH_BITS;
    }
    else if (busWidth == 16) {
 
        AT91C_BASE_SMC->SMC_CTRL3 |= AT91C_SMC_DBW_WIDTH_SIXTEEN_BITS;
    }
}

//------------------------------------------------------------------------------
/// Configures the EBI for NandFlash access at 48MHz. Pins must be configured
/// after or before calling this function.
//------------------------------------------------------------------------------
void BOARD_ConfigureNandFlash48MHz(unsigned char busWidth)
{
    // Configure EBI
    AT91C_BASE_CCFG->CCFG_EBICSA |= AT91C_EBI_CS3A_SM;

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
}

//------------------------------------------------------------------------------
/// Configures the EBI for NorFlash access
/// \Param busWidth Bus width 
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
    // Configure SMC
    AT91C_BASE_SMC->SMC_SETUP0 = 0x00000001;
    AT91C_BASE_SMC->SMC_PULSE0 = 0x07070703;
    AT91C_BASE_SMC->SMC_CYCLE0 = 0x00070007;
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
