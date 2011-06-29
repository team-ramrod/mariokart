/* ----------------------------------------------------------------------------
 *         ATMEL Microcontroller Software Support
 * ----------------------------------------------------------------------------
 * Copyright (c) 2008, Atmel Corporation

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
//------------------------------------------------------------------------------

#include "sdmmc_mci.h"

#include <utility/assert.h>
#include <utility/trace.h>

#include <pio/pio.h>

#include <string.h>

//------------------------------------------------------------------------------
//         Global variables
//------------------------------------------------------------------------------

#if defined(MCI2_INTERFACE)
unsigned char gSdmmcAutoHsEnable = 1;
#else
unsigned char gSdmmcAutoHsEnable = 0;
#endif

//------------------------------------------------------------------------------
//         Local constants
//------------------------------------------------------------------------------

//#define SINGLE_READ
//#define SINGLE_WRITE

// Timeout wait loop
#define TO_LOOP             0x10000

// SD card operation states
#define SD_STATE_IDLE        0
#define SD_STATE_INIT        1
#define SD_STATE_READY       2
#define SD_STATE_READ     0x10
#define SD_STATE_RD_RDY   0x11
#define SD_STATE_RD_BSY   0x12
#define SD_STATE_WRITE    0x20
#define SD_STATE_WR_RDY   0x21
#define SD_STATE_WR_BSY   0x22
#define SD_STATE_BOOT     0x30

// Delay between sending MMC commands
#define MMC_DELAY     0x4FF

#define SD_ADDRESS(pSd, address) \
    ( ((pSd)->totalSize == 0xFFFFFFFF) ? \
                            (address):((address) << SD_BLOCK_SIZE_BIT) )

//-----------------------------------------------------------------------------
/// MMC/SD in SPI mode reports R1 status always, and R2 for SEND_STATUS
/// R1 is the low order byte; R2 is the next highest byte, when present.
//-----------------------------------------------------------------------------
#define R1_SPI_IDLE             (1 << 0)
#define R1_SPI_ERASE_RESET      (1 << 1)
#define R1_SPI_ILLEGAL_COMMAND  (1 << 2)
#define R1_SPI_COM_CRC          (1 << 3)
#define R1_SPI_ERASE_SEQ        (1 << 4)
#define R1_SPI_ADDRESS          (1 << 5)
#define R1_SPI_PARAMETER        (1 << 6)
// R1 bit 7 is always zero
#define R2_SPI_CARD_LOCKED      (1 << 0)
#define R2_SPI_WP_ERASE_SKIP    (1 << 1)
#define R2_SPI_LOCK_UNLOCK_FAIL R2_SPI_WP_ERASE_SKIP
#define R2_SPI_ERROR            (1 << 2)
#define R2_SPI_CC_ERROR         (1 << 3)
#define R2_SPI_CARD_ECC_ERROR   (1 << 4)
#define R2_SPI_WP_VIOLATION     (1 << 5)
#define R2_SPI_ERASE_PARAM      (1 << 6)
#define R2_SPI_OUT_OF_RANGE     (1 << 7)
#define R2_SPI_CSD_OVERWRITE    R2_SPI_OUT_OF_RANGE

// Status register constants
#define STATUS_APP_CMD          (1UL << 5)
#define STATUS_SWITCH_ERROR     (1UL << 7)
#define STATUS_READY_FOR_DATA   (1UL << 8)
#define STATUS_IDLE             (0UL << 9)
#define STATUS_READY            (1UL << 9)
#define STATUS_IDENT            (2UL << 9)
#define STATUS_STBY             (3UL << 9)
#define STATUS_TRAN             (4UL << 9)
#define STATUS_DATA             (5UL << 9)
#define STATUS_RCV              (6UL << 9)
#define STATUS_PRG              (7UL << 9)
#define STATUS_DIS              (8UL << 9)
#define STATUS_STATE          (0xFUL << 9)
#define STATUS_ERASE_RESET       (1UL << 13)
#define STATUS_WP_ERASE_SKIP     (1UL << 15)
#define STATUS_CIDCSD_OVERWRITE  (1UL << 16)
#define STATUS_OVERRUN           (1UL << 17)
#define STATUS_UNERRUN           (1UL << 18)
#define STATUS_ERROR             (1UL << 19)
#define STATUS_CC_ERROR          (1UL << 20)
#define STATUS_CARD_ECC_FAILED   (1UL << 21)
#define STATUS_ILLEGAL_COMMAND   (1UL << 22)
#define STATUS_COM_CRC_ERROR     (1UL << 23)
#define STATUS_UN_LOCK_FAILED    (1UL << 24)
#define STATUS_CARD_IS_LOCKED    (1UL << 25)
#define STATUS_WP_VIOLATION      (1UL << 26)
#define STATUS_ERASE_PARAM       (1UL << 27)
#define STATUS_ERASE_SEQ_ERROR   (1UL << 28)
#define STATUS_BLOCK_LEN_ERROR   (1UL << 29)
#define STATUS_ADDRESS_MISALIGN  (1UL << 30)
#define STATUS_ADDR_OUT_OR_RANGE (1UL << 31)

#define STATUS_STOP ( STATUS_CARD_IS_LOCKED \
                        | STATUS_COM_CRC_ERROR \
                        | STATUS_ILLEGAL_COMMAND \
                        | STATUS_CC_ERROR \
                        | STATUS_ERROR \
                        | STATUS_STATE \
                        | STATUS_READY_FOR_DATA )

#define STATUS_WRITE ( STATUS_ADDR_OUT_OR_RANGE \
                        | STATUS_ADDRESS_MISALIGN \
                        | STATUS_BLOCK_LEN_ERROR \
                        | STATUS_WP_VIOLATION \
                        | STATUS_CARD_IS_LOCKED \
                        | STATUS_COM_CRC_ERROR \
                        | STATUS_ILLEGAL_COMMAND \
                        | STATUS_CC_ERROR \
                        | STATUS_ERROR \
                        | STATUS_ERASE_RESET \
                        | STATUS_STATE \
                        | STATUS_READY_FOR_DATA )

#define STATUS_READ  ( STATUS_ADDR_OUT_OR_RANGE \
                        | STATUS_ADDRESS_MISALIGN \
                        | STATUS_BLOCK_LEN_ERROR \
                        | STATUS_CARD_IS_LOCKED \
                        | STATUS_COM_CRC_ERROR \
                        | STATUS_ILLEGAL_COMMAND \
                        | STATUS_CARD_ECC_FAILED \
                        | STATUS_CC_ERROR \
                        | STATUS_ERROR \
                        | STATUS_ERASE_RESET \
                        | STATUS_STATE \
                        | STATUS_READY_FOR_DATA )

#define STATUS_SD_SWITCH ( STATUS_ADDR_OUT_OR_RANGE \
                            | STATUS_CARD_IS_LOCKED \
                            | STATUS_COM_CRC_ERROR \
                            | STATUS_ILLEGAL_COMMAND \
                            | STATUS_CARD_ECC_FAILED \
                            | STATUS_CC_ERROR \
                            | STATUS_ERROR \
                            | STATUS_UNERRUN \
                            | STATUS_OVERRUN \
                            | STATUS_STATE)

#define STATUS_MMC_SWITCH ( STATUS_CARD_IS_LOCKED \
                            | STATUS_COM_CRC_ERROR \
                            | STATUS_ILLEGAL_COMMAND \
                            | STATUS_CC_ERROR \
                            | STATUS_ERROR \
                            | STATUS_ERASE_RESET \
                            | STATUS_STATE \
                            | STATUS_READY_FOR_DATA \
                            | STATUS_SWITCH_ERROR )

//                            | (0x3UL << 12) /* IO_CURRENT_STATE */
#define STATUS_SDIO_CMD52 ( (1UL << 15) /* COM_CRC_ERROR */ \
                            | (1UL << 14) /* ILLEGAL_COMMAND */ \
                            | (1UL << 11) /* ERRIR */ \
                            | (1UL <<  9) /* FUNCTION_NUMBER */ \
                            | (1UL <<  8) /* OUT_OF_RANGE */)

//-----------------------------------------------------------------------------
/// OCR Register
//-----------------------------------------------------------------------------
#define AT91C_VDD_16_17          (1UL << 4)
#define AT91C_VDD_17_18          (1UL << 5)
#define AT91C_VDD_18_19          (1UL << 6)
#define AT91C_VDD_19_20          (1UL << 7)
#define AT91C_VDD_20_21          (1UL << 8)
#define AT91C_VDD_21_22          (1UL << 9)
#define AT91C_VDD_22_23          (1UL << 10)
#define AT91C_VDD_23_24          (1UL << 11)
#define AT91C_VDD_24_25          (1UL << 12)
#define AT91C_VDD_25_26          (1UL << 13)
#define AT91C_VDD_26_27          (1UL << 14)
#define AT91C_VDD_27_28          (1UL << 15)
#define AT91C_VDD_28_29          (1UL << 16)
#define AT91C_VDD_29_30          (1UL << 17)
#define AT91C_VDD_30_31          (1UL << 18)
#define AT91C_VDD_31_32          (1UL << 19)
#define AT91C_VDD_32_33          (1UL << 20)
#define AT91C_VDD_33_34          (1UL << 21)
#define AT91C_VDD_34_35          (1UL << 22)
#define AT91C_VDD_35_36          (1UL << 23)
#define AT91C_SDIO_MP            (1UL << 27)
#define AT91C_SDIO_NF            (7UL << 28)
#define AT91C_MMC_OCR_BIT2930    (3UL << 29)
#define AT91C_CARD_POWER_UP_BUSY (1UL << 31)

#define AT91C_MMC_HOST_VOLTAGE_RANGE     (AT91C_VDD_27_28 +\
                                          AT91C_VDD_28_29 +\
                                          AT91C_VDD_29_30 +\
                                          AT91C_VDD_30_31 +\
                                          AT91C_VDD_31_32 +\
                                          AT91C_VDD_32_33)

// MMC OCR response for Bit 29, 30
#define AT91C_MMC_NORM_DENSITY   (0x0UL << 29)
#define AT91C_MMC_HIGH_DENSITY   (0x2UL << 29)

#define AT91C_CCS    (1 << 30)

// MCI_CMD Register Value
#define AT91C_POWER_ON_INIT      (0 | AT91C_MCI_TRCMD_NO    \
                                    | AT91C_MCI_SPCMD_INIT  \
                                    | AT91C_MCI_OPDCMD)

//-----------------------------------------------------------------------------
/// eMMC CMD6
//-----------------------------------------------------------------------------
#define AT91C_EMMC_CMD6ARG_ACCESS_BITS        (0x3UL << 24)
#define AT91C_EMMC_CMD6ARG_ACCESS_SHIFT       (24)
// change command sets
#define AT91C_EMMC_CMD6ARG_ACCESS_CMDSETS     (0x0UL << 24)
// set bits in the value field
#define AT91C_EMMC_CMD6ARG_ACCESS_SETBITS     (0x1UL << 24)
// clear bits in the value field
#define AT91C_EMMC_CMD6ARG_ACCESS_CLRBITS     (0x2UL << 24)
// the value field is written into the pointed byte
#define AT91C_EMMC_CMD6ARG_ACCESS_WRBYTES     (0x3UL << 24) 
#define AT91C_EMMC_CMD6ARG_INDEX_BITS         (0xffUL << 16)
#define AT91C_EMMC_CMD6ARG_INDEX_SHIFT        (16)
#define AT91C_EMMC_CMD6ARG_VALUE_BITS         (0xffUL << 8)
#define AT91C_EMMC_CMD6ARG_VALUE_SHIFT        (8)
#define AT91C_EMMC_CMD6ARG_CMDSET_BITS        (0x7UL << 0)
#define AT91C_EMMC_CMD6ARG_CMDSET_SHIFT       (0)

//-----------------------------------------------------------------------------
// Command Classes
//-----------------------------------------------------------------------------
//
// Class 0, 2, 4, 5, 7 and 8 are mandatory and shall be supported by
// all SD Memory Cards.
//
// Basic Commands (class 0)
//
// Cmd0 MCI + SPI
#define   AT91C_GO_IDLE_STATE_CMD     (0 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE )
// Cmd1 SPI
#define   AT91C_MMC_SEND_OP_COND_CMD  (1 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_RSPTYP_48 \
                                         | AT91C_MCI_OPDCMD)
// Cmd2 MCI
#define   AT91C_ALL_SEND_CID_CMD      (2 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_OPDCMD \
                                         | AT91C_MCI_RSPTYP_136 )
// Cmd3 MCI
#define   AT91C_SET_RELATIVE_ADDR_CMD (3 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_RSPTYP_48 \
                                         | AT91C_MCI_OPDCMD \
                                         | AT91C_MCI_MAXLAT )
// Cmd4 MCI
#define AT91C_SET_DSR_CMD             (4 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_RSPTYP_NO \
                                         | AT91C_MCI_MAXLAT )
// Cmd5 MCI
#define AT91C_IO_SEND_OP_COND_CMD     (5 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_RSPTYP_48 \
                                         | AT91C_MCI_OPDCMD )
// Cmd6 SD/MMC
#if defined(MCI2_INTERFACE)
#define AT91C_MMC_SWITCH_CMD          (6 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_RSPTYP_R1B \
                                         | AT91C_MCI_MAXLAT )
#else
#define AT91C_MMC_SWITCH_CMD          (6 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_RSPTYP_48 \
                                         | AT91C_MCI_MAXLAT )
#endif
#define AT91C_SD_SWITCH_CMD           (6 | AT91C_MCI_TRCMD_START \
                                         | AT91C_MCI_TRTYP_BLOCK \
                                         | AT91C_MCI_TRDIR_READ \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_RSPTYP_48 \
                                         | AT91C_MCI_MAXLAT )
// cmd7 MCI
#define   AT91C_SEL_DESEL_CARD_CMD    (7 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_RSPTYP_48 \
                                         | AT91C_MCI_MAXLAT )
#define   AT91C_SEL_CARD_CMD          (7 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_RSPTYP_48 \
                                         | AT91C_MCI_MAXLAT )
#define   AT91C_DESEL_CARD_CMD        (7 | AT91C_MCI_TRCMD_NO \
                                         | AT91C_MCI_SPCMD_NONE \
                                         | AT91C_MCI_RSPTYP_NO \
                                         | AT91C_MCI_MAXLAT )
// Cmd8 MCI + SPI
#define   AT91C_SEND_IF_COND          (8  | AT91C_MCI_TRCMD_NO \
                                          | AT91C_MCI_SPCMD_NONE \
                                          | AT91C_MCI_RSPTYP_48 \
                                          | AT91C_MCI_MAXLAT )
// Cmd9 MCI + SPI
#define   AT91C_SEND_CSD_CMD          (9  | AT91C_MCI_TRCMD_NO \
                                          | AT91C_MCI_SPCMD_NONE \
                                          | AT91C_MCI_RSPTYP_136 \
                                          | AT91C_MCI_MAXLAT )
// Cmd10 MCI + SPI
#define   AT91C_SEND_CID_CMD          (10 | AT91C_MCI_TRCMD_NO \
                                          | AT91C_MCI_SPCMD_NONE \
                                          | AT91C_MCI_RSPTYP_136 \
                                          | AT91C_MCI_MAXLAT )
// Cmd12 MCI + SPI
#if defined(MCI2_INTERFACE)
#define   AT91C_STOP_TRANSMISSION_CMD (12 | AT91C_MCI_TRCMD_STOP \
                                          | AT91C_MCI_SPCMD_NONE \
                                          | AT91C_MCI_RSPTYP_R1B \
                                          | AT91C_MCI_MAXLAT )
#else
#define   AT91C_STOP_TRANSMISSION_CMD (12 | AT91C_MCI_TRCMD_STOP \
                                          | AT91C_MCI_SPCMD_NONE \
                                          | AT91C_MCI_RSPTYP_48 \
                                          | AT91C_MCI_MAXLAT )
#endif
// Cmd13 MCI + SPI
#define   AT91C_SEND_STATUS_CMD       (13 | AT91C_MCI_TRCMD_NO \
                                          | AT91C_MCI_SPCMD_NONE \
                                          | AT91C_MCI_RSPTYP_48 \
                                          | AT91C_MCI_MAXLAT )
// Cmd15 MCI
#define AT91C_GO_INACTIVE_STATE_CMD   (15 | AT91C_MCI_RSPTYP_NO )

// Cmd58 SPI
#define   AT91C_READ_OCR_CMD          (58 | AT91C_MCI_RSPTYP_48 \
                                          | AT91C_MCI_SPCMD_NONE \
                                          | AT91C_MCI_MAXLAT )
// Cmd59 SPI
#define   AT91C_CRC_ON_OFF_CMD        (59 | AT91C_MCI_RSPTYP_48 \
                                          | AT91C_MCI_SPCMD_NONE \
                                          | AT91C_MCI_MAXLAT )

//*------------------------------------------------
//* Class 2 commands: Block oriented Read commands
//*------------------------------------------------

// Cmd8 for MMC
#define AT91C_SEND_EXT_CSD_CMD          (8 | AT91C_MCI_SPCMD_NONE \
                                           | AT91C_MCI_OPDCMD_PUSHPULL \
                                           | AT91C_MCI_RSPTYP_48 \
                                           | AT91C_MCI_TRCMD_START \
                                           | AT91C_MCI_TRTYP_BLOCK \
                                           | AT91C_MCI_TRDIR \
                                           | AT91C_MCI_MAXLAT)

// Cmd16
#define AT91C_SET_BLOCKLEN_CMD          (16 | AT91C_MCI_TRCMD_NO \
                                            | AT91C_MCI_SPCMD_NONE \
                                            | AT91C_MCI_RSPTYP_48 \
                                            | AT91C_MCI_MAXLAT )
// Cmd17
#define AT91C_READ_SINGLE_BLOCK_CMD     (17 | AT91C_MCI_SPCMD_NONE \
                                            | AT91C_MCI_RSPTYP_48 \
                                            | AT91C_MCI_TRCMD_START \
                                            | AT91C_MCI_TRTYP_BLOCK \
                                            | AT91C_MCI_TRDIR \
                                            | AT91C_MCI_MAXLAT)
// Cmd18
#define AT91C_READ_MULTIPLE_BLOCK_CMD   (18 | AT91C_MCI_SPCMD_NONE \
                                            | AT91C_MCI_RSPTYP_48 \
                                            | AT91C_MCI_TRCMD_START \
                                            | AT91C_MCI_TRTYP_MULTIPLE \
                                            | AT91C_MCI_TRDIR \
                                            | AT91C_MCI_MAXLAT)

//*------------------------------------------------
//* Class 4 commands: Block oriented write commands
//*------------------------------------------------
// Cmd24
#define AT91C_WRITE_BLOCK_CMD           (24 | AT91C_MCI_SPCMD_NONE \
                                            | AT91C_MCI_RSPTYP_48 \
                                            | AT91C_MCI_TRCMD_START \
                                            | (AT91C_MCI_TRTYP_BLOCK \
                                                & ~(AT91C_MCI_TRDIR)) \
                                            | AT91C_MCI_MAXLAT)
// Cmd25
#define AT91C_WRITE_MULTIPLE_BLOCK_CMD  (25 | AT91C_MCI_SPCMD_NONE \
                                            | AT91C_MCI_RSPTYP_48 \
                                            | AT91C_MCI_TRCMD_START \
                                            | (AT91C_MCI_TRTYP_MULTIPLE \
                                                & ~(AT91C_MCI_TRDIR)) \
                                            | AT91C_MCI_MAXLAT)
// Cmd27
#define AT91C_PROGRAM_CSD_CMD           (27 | AT91C_MCI_RSPTYP_48 )

//*----------------------------------------
//* Class 5 commands: Erase commands
//*----------------------------------------
// Cmd32
//#define AT91C_TAG_SECTOR_START_CMD          (32 | AT91C_MCI_SPCMD_NONE  | AT91C_MCI_RSPTYP_48   | AT91C_MCI_TRCMD_NO    | AT91C_MCI_MAXLAT)
// Cmd33
//#define AT91C_TAG_SECTOR_END_CMD            (33 | AT91C_MCI_SPCMD_NONE  | AT91C_MCI_RSPTYP_48   | AT91C_MCI_TRCMD_NO    | AT91C_MCI_MAXLAT)
// Cmd38
//#define AT91C_ERASE_CMD                     (38 | AT91C_MCI_SPCMD_NONE  | AT91C_MCI_RSPTYP_48   | AT91C_MCI_TRCMD_NO    | AT91C_MCI_MAXLAT )

//*----------------------------------------
//* Class 7 commands: Lock commands
//*----------------------------------------
// Cmd42
//#define AT91C_LOCK_UNLOCK           (42 | AT91C_MCI_SPCMD_NONE  | AT91C_MCI_RSPTYP_48   | AT91C_MCI_TRCMD_NO    | AT91C_MCI_MAXLAT) // not tested

//*-----------------------------------------------
// Class 8 commands: Application specific commands
//*-----------------------------------------------
// Cmd55
#define AT91C_APP_CMD               (55 | AT91C_MCI_SPCMD_NONE \
                                        | AT91C_MCI_RSPTYP_48 \
                                        | AT91C_MCI_TRCMD_NO \
                                        | AT91C_MCI_MAXLAT)
// cmd 56
//#define AT91C_GEN_CMD               (56 | AT91C_MCI_SPCMD_NONE  | AT91C_MCI_RSPTYP_48   | AT91C_MCI_TRCMD_NO | AT91C_MCI_MAXLAT)    // not tested
// ACMD6
#define AT91C_SD_SET_BUS_WIDTH_CMD          (6  | AT91C_MCI_SPCMD_NONE \
                                                | AT91C_MCI_RSPTYP_48 \
                                                | AT91C_MCI_TRCMD_NO \
                                                | AT91C_MCI_MAXLAT)
// ACMD13
#define AT91C_SD_STATUS_CMD                 (13 | AT91C_MCI_SPCMD_NONE \
                                                | AT91C_MCI_RSPTYP_48 \
                                                | AT91C_MCI_TRCMD_START \
                                                | AT91C_MCI_TRTYP_BLOCK \
                                                | AT91C_MCI_TRDIR_READ \
                                                | AT91C_MCI_MAXLAT)
// ACMD22
//#define AT91C_SD_SEND_NUM_WR_BLOCKS_CMD     (22 | AT91C_MCI_SPCMD_NONE  | AT91C_MCI_RSPTYP_48   | AT91C_MCI_TRCMD_NO    | AT91C_MCI_MAXLAT)
// ACMD23
//#define AT91C_SD_SET_WR_BLK_ERASE_COUNT_CMD (23 | AT91C_MCI_SPCMD_NONE  | AT91C_MCI_RSPTYP_48   | AT91C_MCI_TRCMD_NO    | AT91C_MCI_MAXLAT)
// ACMD41
#define AT91C_SD_APP_OP_COND_CMD            (41 | AT91C_MCI_SPCMD_NONE \
                                                | AT91C_MCI_RSPTYP_48 \
                                                | AT91C_MCI_TRCMD_NO )
// ACMD42
//#define AT91C_SD_SET_CLR_CARD_DETECT_CMD    (42 | AT91C_MCI_SPCMD_NONE  | AT91C_MCI_RSPTYP_48   | AT91C_MCI_TRCMD_NO    | AT91C_MCI_MAXLAT)
// ACMD51
#define AT91C_SD_SEND_SCR_CMD               (51 | AT91C_MCI_SPCMD_NONE \
                                                | AT91C_MCI_RSPTYP_48 \
                                                | AT91C_MCI_TRCMD_START \
                                                | AT91C_MCI_TRDIR_READ \
                                                | AT91C_MCI_TRTYP_BLOCK \
                                                | AT91C_MCI_MAXLAT)

// SDIO commands
// CMD5, R4
#define AT91C_SDIO_SEND_OP_COND (5 | AT91C_MCI_TRCMD_NO \
                                   | AT91C_MCI_SPCMD_NONE \
                                   | AT91C_MCI_RSPTYP_48 \
                                   | AT91C_MCI_OPDCMD)

// CMD52, R5
#define AT91C_SDIO_IO_RW_DIRECT (52| AT91C_MCI_TRCMD_NO \
                                   | AT91C_MCI_SPCMD_NONE \
                                   | AT91C_MCI_RSPTYP_48 \
                                   | AT91C_MCI_MAXLAT )

// CMD53, R5
#define AT91C_SDIO_IO_RW_EXTENDED (53 | AT91C_MCI_SPCMD_NONE \
                                      | AT91C_MCI_RSPTYP_48 \
                                      | AT91C_MCI_TRCMD_START \
                                      | AT91C_MCI_MAXLAT)

#ifdef AT91C_MCI_SPCMD_BOOTREQ
// BOOTREQ
#define AT91C_BOOTREQ           (AT91C_MCI_SPCMD_BOOTREQ \
                                    | AT91C_MCI_TRDIR_READ \
                                    | AT91C_MCI_TRCMD_START \
                                    | AT91C_MCI_MAXLAT)
// BOOTEND
#define AT91C_BOOTEND           (AT91C_MCI_SPCMD_BOOTEND \
                                    | AT91C_MCI_OPDCMD_PUSHPULL)
#endif
// Optional commands
#define SD_ACMD6_SUPPORT        (1UL << 0)
#define SD_ACMD13_SUPPORT       (1UL << 1)
#define SD_ACMD41_SUPPORT       (1UL << 2)
#define SD_ACMD51_SUPPORT       (1UL << 3)

#define SD_CMD16_SUPPORT        (1UL << 8)

//------------------------------------------------------------------------------
//         Local functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// DecodeR1
/// \param R1  
//------------------------------------------------------------------------------
void DecodeR1(unsigned char R1)
{
    if( (R1 & R1_SPI_IDLE)==R1_SPI_IDLE) {
        TRACE_DEBUG("R1_SPI_IDLE\n\r");
    }
    if( (R1 & R1_SPI_ERASE_RESET)==R1_SPI_ERASE_RESET) {
        TRACE_DEBUG("R1_SPI_ERASE_RESET\n\r");
    }
    if( (R1 & R1_SPI_ILLEGAL_COMMAND)==R1_SPI_ILLEGAL_COMMAND) {
        TRACE_DEBUG("R1_SPI_ILLEGAL_COMMAND\n\r");
    }
    if( (R1 & R1_SPI_COM_CRC)==R1_SPI_COM_CRC) {
        TRACE_DEBUG("R1_SPI_COM_CRC\n\r");
    }
    if( (R1 & R1_SPI_ERASE_SEQ)==R1_SPI_ERASE_SEQ) {
        TRACE_DEBUG("R1_SPI_ERASE_SEQ\n\r");
    }
    if( (R1 & R1_SPI_ADDRESS)==R1_SPI_ADDRESS) {
        TRACE_DEBUG("R1_SPI_ADDRESS\n\r");
    }
    if( (R1 & R1_SPI_PARAMETER)==R1_SPI_PARAMETER) {
        TRACE_DEBUG("R1_SPI_PARAMETER\n\r");
    }
}

//------------------------------------------------------------------------------
/// DecodeR2
/// \param R2  
//------------------------------------------------------------------------------
void DecodeR2(unsigned char R2)
{
    if( (R2 & R2_SPI_CARD_LOCKED)==R2_SPI_CARD_LOCKED) {
        TRACE_DEBUG("R2_SPI_CARD_LOCKED\n\r");
    }
    if( (R2 & R2_SPI_WP_ERASE_SKIP)==R2_SPI_WP_ERASE_SKIP) {
        TRACE_DEBUG("R2_SPI_WP_ERASE_SKIP/R2_SPI_LOCK_UNLOCK_FAIL\n\r");
    }
    if( (R2 & R2_SPI_ERROR)==R2_SPI_ERROR) {
        TRACE_DEBUG("R2_SPI_ERROR\n\r");
    }
    if( (R2 & R2_SPI_CC_ERROR)==R2_SPI_CC_ERROR) {
        TRACE_DEBUG("R2_SPI_CC_ERROR\n\r");
    }
    if( (R2 & R2_SPI_CARD_ECC_ERROR)==R2_SPI_CARD_ECC_ERROR) {
        TRACE_DEBUG("R2_SPI_CARD_ECC_ERROR\n\r");
    }
    if( (R2 & R2_SPI_WP_VIOLATION)==R2_SPI_WP_VIOLATION) {
        TRACE_DEBUG("R2_SPI_WP_VIOLATION\n\r");
    }
    if( (R2 & R2_SPI_ERASE_PARAM)==R2_SPI_ERASE_PARAM) {
        TRACE_DEBUG("R2_SPI_ERASE_PARAM\n\r");
    }
    if( (R2 & R2_SPI_OUT_OF_RANGE)==R2_SPI_OUT_OF_RANGE) {
        TRACE_DEBUG("R2_SPI_OUT_OF_RANGE/R2_SPI_CSD_OVERWRITE\n\r");
    }
}

//------------------------------------------------------------------------------
/// Get Trans Speed Value (Kbit/s)
/// \param tranSpeed The TRAN_SPEED value from SD(IO)/MMC enum information.
/// \param unitList  Transfer rate units (Kbit/s), 4 units listed.
/// \param nbUnits   Transfer rate units list size.
/// \param codeList  Time value codes list, 16 codes listed.
//------------------------------------------------------------------------------
static unsigned int MmcGetTranSpeed(unsigned int tranSpeed,
                            const unsigned int* unitList, unsigned int nbUnits,
                            const unsigned int* codeList)
{
    unsigned int unit, value;
    unit = tranSpeed & 0x7;
    if (unit < nbUnits) unit = unitList[unit];
    else                return 0;
    value = (tranSpeed >> 3) & 0xF;
    if (value < 16)   value = codeList[value];
    else                return 0;
    return (unit * value);
}

//------------------------------------------------------------------------------
/// Get Trans Speed Value
/// \param pSd    
//------------------------------------------------------------------------------
void GetTransSpeedValue(SdCard *pSd)
{
    // CSD register, TRANS_SPEED bit
    const unsigned int units[4] = {10, 100, 1000, 10000 }; // *Kbit/s 
    const unsigned int values_emmc[16] = {0, 10, 12, 13, 15, 20,
                                          26, 30, 35, 40, 45, 52,
                                          55, 60, 70, 80};
    const unsigned int values_sdmmc[16] = {0, 10, 12, 13, 15, 20,
                                           25, 30, 35, 40, 45, 50,
                                           55, 60, 70, 80};
  #if 0
    unsigned int unit, value;
    unit = (SD_CSD_TRAN_SPEED(pSd) & 0x7);
    if(unit < 4)    unit  = units[unit];
    else            return;
    value = (SD_CSD_TRAN_SPEED(pSd) >> 3) & 0xF;
    if (value < 16) {
        if (pSd->cardType >= CARD_MMC && SD_CID_BGA(pSd) == 1) {
            value = values_emmc[value];
        }
        else
            value = values_sdmmc[value];
    }
    else            return;
    pSd->transSpeed = (unit * value);
  #else
    pSd->transSpeed = MmcGetTranSpeed(SD_CSD_TRAN_SPEED(pSd),
                                      units, 4,
                                      (pSd->cardType >= CARD_MMC
                                       && SD_CID_BGA(pSd) == 1) ?
                                       values_emmc : values_sdmmc);
  #endif
    if (pSd->cardType >= CARD_MMC && SD_EXTCSD_HS_TIMING(pSd)) {
        pSd->transSpeed *= 2;
    }
    TRACE_WARNING_WP("-I- SD/MMC TRANS SPEED %d KBit/s\r\n", pSd->transSpeed);
    pSd->transSpeed *= 1000;  
}

#if 1
//------------------------------------------------------------------------------
/// Reset the SdCmd
//------------------------------------------------------------------------------
static void ResetCommand(SdCmd *pCommand)
{
  #if 0
    unsigned char* p = (unsigned char*)pCommand;
    unsigned int   l = sizeof(SdCmd);
    while(l --) *p++ = 0;
  #else
    pCommand->cmd       = 0;
    pCommand->arg       = 0;
    pCommand->pData     = 0;
    pCommand->blockSize = 0;
    pCommand->nbBlock   = 0;
    pCommand->pResp     = 0;
    pCommand->callback  = 0;
    pCommand->pArg      = 0;
    pCommand->resType   = 0;
    pCommand->dataTran  = 0;
    pCommand->tranType  = 0;
    pCommand->isRead    = 0;
    pCommand->status    = 0;
  #endif
}
#else
// GNU halt on memset now
# define ResetCommand(pCommand) memset(pCommand, 0, sizeof(SdCmd))
#endif

//------------------------------------------------------------------------------
/// Delay some loop
//------------------------------------------------------------------------------
static void Delay(volatile unsigned int loop)
{
    for(;loop > 0; loop --);
}

//------------------------------------------------------------------------------
/// Sends the current SD card driver command to the card.
/// Returns 0 if successful; Otherwise, returns the transfer status code or
/// SD_ERROR_DRIVER if there was a problem with the SD transfer.
/// \param pSd  Pointer to a SdCard driver instance.
//------------------------------------------------------------------------------
static unsigned char SendCommand(SdCard *pSd)
{
    SdCmd *pCommand = &(pSd->command);
    SdDriver *pSdDriver = pSd->pSdDriver;
    unsigned char error;

    // Send command
    error = MCI_SendCommand((Mci *)pSdDriver, (MciCmd *)pCommand);
    if (error) {
        TRACE_ERROR("MCI SendCommand: Failed to send command (%d)\n\r", error);
        return SD_ERROR_DRIVER;
    }

    // Wait for command to complete (if no callback defined)
    if (pCommand->callback == 0) {
        while (!MCI_IsTxComplete((Mci *)pSdDriver));
    }

    // Check for using fifo to transfer data
  #if !defined(MCI_DMA_ENABLE) && defined(MCI2_INTERFACE)
    if (pCommand->dataTran && pCommand->nbBlock) {
        MCI_FifoTransfer((Mci *)pSdDriver, (MciCmd *)pCommand);
    }
  #endif

    return pCommand->status;
}

//------------------------------------------------------------------------------
/// Initialization delay: The maximum of 1 msec, 74 clock cycles and supply ramp
/// up time.
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SdCard driver instance.
//------------------------------------------------------------------------------
static unsigned char Pon(SdCard *pSd)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned int response;
    unsigned char error;

    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_POWER_ON_INIT;
    pCommand->pResp = &response;

    // Send command
    error =  SendCommand(pSd);
    return error;
}

#if defined(MCI2_INTERFACE) && defined(AT91C_MCI_SPCMD_BOOTREQ)
//------------------------------------------------------------------------------
/// Initialization delay: The maximum of 1 msec, 74 clock cycles and supply ramp
/// up time, CMD keeps low so that the device run in boot mode.
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SdCard driver instance.
//------------------------------------------------------------------------------
static unsigned char PonBoot(SdCard *pSd)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned int response;
    unsigned char error;

    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_POWER_ON_INIT;
    pCommand->pResp = &response;

    // Send command
    error =  SendCommand(pSd);
    return error;
}
#endif

//------------------------------------------------------------------------------
/// Resets all cards to idle state
/// \param pSd  Pointer to a SdCard driver instance.
/// \param arg  Argument used.
/// \return the command transfer result (see SendCommand).
//------------------------------------------------------------------------------
static unsigned char Cmd0(SdCard *pSd, unsigned int arg)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned int response;
    unsigned char error;

    TRACE_DEBUG("Cmd0()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_GO_IDLE_STATE_CMD;
    pCommand->arg = arg;
    pCommand->pResp = &response;

    // send command
    error =  SendCommand(pSd);
    return error;
}

//------------------------------------------------------------------------------
/// MMC send operation condition command.
/// Sends host capacity support information and activates the card's
/// initialization process.
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SdCard driver instance.
/// \param hdSupport  Indicate whether the host support high density MMC.
/// \param pHdSupport  Indicate whether the card is a high density MMC.
//------------------------------------------------------------------------------
static unsigned char Cmd1(SdCard *pSd,
                          unsigned char hdSupport,
                          unsigned char *pHdSupport)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;

    TRACE_DEBUG("Cmd1()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_MMC_SEND_OP_COND_CMD;
    pCommand->arg = AT91C_MMC_HOST_VOLTAGE_RANGE;
    if(hdSupport) {
        pCommand->arg |= AT91C_MMC_HIGH_DENSITY;
    }
    else {
        pCommand->arg |= AT91C_MMC_NORM_DENSITY;
    }
    pCommand->resType = 3;
    pCommand->pResp = &response;

    // send command
    *pHdSupport = 0; 
    error = SendCommand(pSd);
    if (error) {
        return error;
    }
    if ((response & AT91C_CARD_POWER_UP_BUSY) == AT91C_CARD_POWER_UP_BUSY) {        if((response & AT91C_MMC_OCR_BIT2930) == AT91C_MMC_HIGH_DENSITY) {
            *pHdSupport = 1;
        }
        return 0;
    }
    else {
        return SD_ERROR_DRIVER;
    }
}

//------------------------------------------------------------------------------
/// Asks any card to send the CID numbers
/// on the CMD line (any card that is
/// connected to the host will respond)
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SD card driver instance.
/// \param pCid  Buffer for storing the CID numbers.
//------------------------------------------------------------------------------
static unsigned char Cmd2(SdCard *pSd)
{
    SdCmd *pCommand = &(pSd->command);

    TRACE_DEBUG("Cmd2()\n\r");
    ResetCommand(pCommand);
    // Fill the command information
    pCommand->cmd = AT91C_ALL_SEND_CID_CMD;
    pCommand->resType = 2;
    pCommand->pResp = pSd->cid;

    // Send the command
    return SendCommand(pSd);
}

//------------------------------------------------------------------------------
/// Ask the card to publish a new relative address (RCA)
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SD card driver instance.
//------------------------------------------------------------------------------
static unsigned char Cmd3(SdCard *pSd)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned int cardAddress;
    unsigned char error;

    TRACE_DEBUG("Cmd3()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_SET_RELATIVE_ADDR_CMD;

    // Assign relative address to MMC card
    if ((pSd->cardType == CARD_MMC) || (pSd->cardType == CARD_MMCHD)) {
        pCommand->arg = (0x1 << 16);
    }
    pCommand->resType = 1;
    pCommand->pResp = &cardAddress;

    // Send command
    error = SendCommand(pSd);
    if (error) {
        return error;
    }

    // Save card address in driver
    if ( (pSd->cardType == CARD_SD)
        || (pSd->cardType == CARD_SDHC)) {
        pSd->cardAddress = (cardAddress >> 16) & 0xFFFF;
    }
    else if (pSd->cardType >= CARD_SDIO) {
        pSd->cardAddress = (cardAddress >> 16) & 0xFFFF;
    }
    else {
        // Default MMC RCA is 0x0001
        pSd->cardAddress = 1;
    }

    return 0;
}

#if MCI_SDIO_ENABLE
//------------------------------------------------------------------------------
/// SDIO send operation condition command.
/// Sends host capacity support information and activates the card's
/// initialization process.
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SdCard driver instance.
/// \param pIo  Pointer to data send as well as response buffer.
//------------------------------------------------------------------------------
static unsigned char Cmd5(SdCard *pSd,
                          unsigned int *pIo)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;

    TRACE_DEBUG("Cmd5()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_IO_SEND_OP_COND_CMD;
    pCommand->arg = *pIo;
    pCommand->resType = 4;
    pCommand->pResp = pIo;

    // send command
    error = SendCommand(pSd);
    return error;
}
#endif

//------------------------------------------------------------------------------
/// Command toggles a card between the
/// stand-by and transfer states or between
/// the programming and disconnect states.
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SD card driver instance.
/// \param address  Relative Card Address (0 deselects all).
//------------------------------------------------------------------------------
static unsigned char Cmd7(SdCard *pSd, unsigned int address)
{
    SdCmd *pCommand = &(pSd->command);

    TRACE_DEBUG("Cmd7()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_SEL_DESEL_CARD_CMD;
    pCommand->arg = address << 16;
    pCommand->resType = 1;

    // Send command
    return SendCommand(pSd);
}

//------------------------------------------------------------------------------
/// Switches the mode of operation of the selected card (SD/MMC) or
/// modifies the EXT_CSD registers (for MMC only).
/// CMD6 is valid under the "trans" state.
/// \return The command transfer result (see SendCommand).
/// \param  pSd         Pointer to a SD/MMC card driver instance.
/// \param  pSwitchArg  Pointer to a MmcCmd6Arg instance.
/// \param  pStatus     Pointer to where the 512bit status is returned.
/// \param  pResp       Pointer to where the response is returned.
//------------------------------------------------------------------------------
static unsigned char Cmd6(SdCard *pSd,
                          const void * pSwitchArg,
                          unsigned int  * pStatus,
                          unsigned int  * pResp)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned int  response;
    unsigned char error;
    SdCmd6Arg  * pSdSwitch;
    MmcCmd6Arg * pMmcSwitch;

    SANITY_CHECK(pSd);
    SANITY_CHECK(pSwitchArg);

    TRACE_DEBUG("CMD6()\n\r");

    ResetCommand(pCommand);

    if (pSd->cardType >= CARD_MMC) {
        pMmcSwitch = (MmcCmd6Arg*)pSwitchArg;
        // R1b response
        pCommand->cmd = AT91C_MMC_SWITCH_CMD;
        pCommand->resType = 1;
        pCommand->arg =   (pMmcSwitch->access << 24)
                        | (pMmcSwitch->index  << 16)
                        | (pMmcSwitch->value  <<  8)
                        | (pMmcSwitch->cmdSet <<  0);
    }
    else if (pSd->cardType >= CARD_SD) {

        pSdSwitch = (SdCmd6Arg*)pSwitchArg;
        // R1 response & 512 bits of status on DAT
        pCommand->cmd = AT91C_SD_SWITCH_CMD;
        pCommand->resType = 1;
        pCommand->arg =   (pSdSwitch->mode << 31)
                        | (pSdSwitch->reserved << 30)
                        | (pSdSwitch->reserveFG6 << 20)
                        | (pSdSwitch->reserveFG5 << 16)
                        | (pSdSwitch->reserveFG4 << 12)
                        | (pSdSwitch->reserveFG3 <<  8)
                        | (pSdSwitch->command << 4)
                        | (pSdSwitch->accessMode << 0);
        if (pStatus) {
            pCommand->blockSize = 512 / 8;
            pCommand->nbBlock = 1;
            pCommand->pData = (unsigned char*)pStatus;

            pCommand->dataTran = 1;
            pCommand->isRead = 1;
            pCommand->tranType = MCI_NEW_TRANSFER;
        }
    }
    pCommand->pResp = &response;

    TRACE_INFO("CMD6(%d) arg 0x%X\n\r", pSd->cardType, pCommand->arg);

    error = SendCommand(pSd);

    if (error)
        return error;
    else if (pResp)
        *pResp = response;

    return 0;
}

//------------------------------------------------------------------------------
/// SD:  Sends SD Memory Card interface condition, which includes host supply
///      voltage information and asks the card whether card supports voltage.
///      Should be performed at initialization time to detect the card type.
/// MMC: SEND_EXT_CSD, to get EXT_CSD register as a block of data.
///      Valid under "trans" state.
/// \param pSd   Pointer to a SD card driver instance.
/// \param sdCmd For SD Memory Card interface condition 
/// \param arg   Expected supply voltage(SD) or 512 byte buffer pointer (MMC).
/// \return 0 if successful;
///         otherwise returns SD_ERROR_NORESPONSE if the card did not answer
///         the command, or SD_ERROR_DRIVER.
//------------------------------------------------------------------------------
static unsigned char Cmd8(SdCard *pSd,
                          unsigned char sdCmd,
                          void* arg)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned int response;
    unsigned char error;
    unsigned char supplyVoltage = (unsigned char)((unsigned int)arg);

    TRACE_DEBUG("Cmd8()\n\r");
    ResetCommand(pCommand);

    if (sdCmd) {

        // Fill command information
        pCommand->cmd = AT91C_SEND_IF_COND;
        pCommand->arg = (supplyVoltage << 8) | (0xAA);
        pCommand->resType = 7;

        TRACE_DEBUG("supplyVoltage: 0x%x\n\r", supplyVoltage);
    }
    else {

        pCommand->cmd = AT91C_SEND_EXT_CSD_CMD;
        pCommand->resType = 1;

        pCommand->blockSize = SD_BLOCK_SIZE;
        pCommand->nbBlock = 512 / SD_BLOCK_SIZE;
        pCommand->pData = arg;

        pCommand->dataTran = 1;
        pCommand->isRead = 1;
        pCommand->tranType = MCI_NEW_TRANSFER;
    }
    pCommand->pResp = &response;

    // Send command
    error = SendCommand(pSd);

    if (sdCmd) {

        // Check result
        if (error == MCI_STATUS_NORESPONSE) {

            return SD_ERROR_NORESPONSE;
        }
        // SD_R7
        // Bit 0 - 7: check pattern (echo-back)
        // Bit 8 -11: voltage accepted
        else if (!error &&
                ((response & 0x00000FFF) == ((supplyVoltage << 8) | 0xAA))) {
            return 0;
        }
        else {
            return SD_ERROR_DRIVER;
        }
    }

    return error;
}

//------------------------------------------------------------------------------
/// Addressed card sends its card-specific
/// data (CSD) on the CMD line.
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SD card driver instance.
//------------------------------------------------------------------------------
static unsigned char Cmd9(SdCard *pSd)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;

    TRACE_DEBUG("Cmd9()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_SEND_CSD_CMD;
    pCommand->arg = pSd->cardAddress << 16;
    pCommand->resType = 2;
    pCommand->pResp = pSd->csd;

    // Send command
    error = SendCommand(pSd);
    return error;
}

//------------------------------------------------------------------------------
/// Forces the card to stop transmission
/// \param pSd      Pointer to a SD card driver instance.
/// \param stopRead Stop reading stream/writing stream.
/// \param pStatus  Pointer to a status variable.
//------------------------------------------------------------------------------
static unsigned char Cmd12(SdCard *pSd,
                           unsigned char stopRead,
                           unsigned int *pStatus)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;

    TRACE_DEBUG("Cmd12()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_STOP_TRANSMISSION_CMD;
    pCommand->isRead = stopRead;
    pCommand->tranType = MCI_STOP_TRANSFER;
    pCommand->resType = 1;
    pCommand->pResp = &response;

    // Send command
    error = SendCommand(pSd);
    if (pStatus) *pStatus = response;
    return error;
}

//------------------------------------------------------------------------------
/// Addressed card sends its status register.
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SD card driver instance.
/// \param pStatus  Pointer to a status variable.
//------------------------------------------------------------------------------
static unsigned char Cmd13(SdCard *pSd, unsigned int *pStatus)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;

    TRACE_DEBUG("Cmd13()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_SEND_STATUS_CMD;
    pCommand->arg = pSd->cardAddress << 16;
    pCommand->resType = 1;
    pCommand->pResp = pStatus;

    // Send command
    error = SendCommand(pSd);

    return error;
}

//------------------------------------------------------------------------------
/// In the case of a Standard Capacity SD Memory Card, this command sets the
/// block length (in bytes) for all following block commands
/// (read, write, lock).
/// Default block length is fixed to 512 Bytes.
/// Set length is valid for memory access commands only if partial block read
/// operation are allowed in CSD.
/// In the case of a High Capacity SD Memory Card, block length set by CMD16
/// command does not affect the memory read and write commands. Always 512
/// Bytes fixed block length is used. This command is effective for LOCK_UNLOCK
/// command. In both cases, if block length is set larger than 512Bytes, the
/// card sets the BLOCK_LEN_ERROR bit.
/// \param pSd  Pointer to a SD card driver instance.
/// \param blockLength  Block length in bytes.
//------------------------------------------------------------------------------
static unsigned char Cmd16(SdCard *pSd, unsigned short blockLength)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;

    TRACE_DEBUG("Cmd16()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_SET_BLOCKLEN_CMD;
    pCommand->arg = blockLength;
    pCommand->resType = 1;
    pCommand->pResp = &response;

    // Send command
    error = SendCommand(pSd);

    return error;
}

#ifdef SINGLE_READ
static unsigned char Cmd17(SdCard *pSd,
                           unsigned char  *pData,
                           unsigned int   address,
                           unsigned int   *pStatus)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;

    TRACE_DEBUG("Cmd17()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_READ_SINGLE_BLOCK_CMD;
    pCommand->arg = address;
    pCommand->resType = 1;
    pCommand->pResp = &response;

    pCommand->blockSize = SD_BLOCK_SIZE;
    pCommand->nbBlock = 1;
    pCommand->pData = pData;

    pCommand->dataTran = 1;
    pCommand->isRead = 1;
    pCommand->tranType = MCI_NEW_TRANSFER;

    // Send command
    error = SendCommand(pSd);

    if (pStatus) *pStatus = response;
    return error;
}
#endif

//------------------------------------------------------------------------------
/// Continously transfers datablocks from card to host until interrupted by a
/// STOP_TRANSMISSION command.
/// \param pSd        Pointer to a SD card driver instance.
/// \param blockSize  Block size (shall be set to 512 in case of high capacity).
/// \param pData      Pointer to the DW aligned buffer to be filled.
/// \param address    SD card address.
//------------------------------------------------------------------------------
static unsigned char Cmd18(SdCard *pSd,
                           unsigned short nbBlock,
                           unsigned char *pData,
                           unsigned int address,
                           unsigned int *pStatus)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;

    TRACE_DEBUG("Cmd18()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_READ_MULTIPLE_BLOCK_CMD;
    pCommand->arg = address;
    pCommand->resType = 1;
    pCommand->pResp = &response;

    pCommand->blockSize = SD_BLOCK_SIZE;
    pCommand->nbBlock = nbBlock;
    pCommand->pData = pData;

    pCommand->dataTran = 1;
    pCommand->isRead = 1;
    pCommand->tranType = MCI_NEW_TRANSFER;

    // Send command
    error = SendCommand(pSd);

    if (pStatus) *pStatus = response;

    return error;
}
#ifdef SINGLE_WRITE
static unsigned char Cmd24(SdCard *pSd,
                           unsigned char  *pData,
                           unsigned int   address,
                           unsigned int   *pStatus)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;

    TRACE_DEBUG("Cmd24()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_WRITE_BLOCK_CMD;
    pCommand->arg = address;
    pCommand->resType = 1;
    pCommand->pResp = &response;

    pCommand->blockSize = SD_BLOCK_SIZE;
    pCommand->nbBlock = 1;
    pCommand->pData = pData;

    pCommand->dataTran = 1;
    pCommand->isRead = 0;
    pCommand->tranType = MCI_NEW_TRANSFER;

    // Send command
    error = SendCommand(pSd);

    if (pStatus) *pStatus = response;
    return error;
}
#endif
//------------------------------------------------------------------------------
/// Write block command
/// \param pSd  Pointer to a SD card driver instance.
/// \param blockSize  Block size (shall be set to 512 in case of high capacity).
/// \param pData  Pointer to the DW aligned buffer to be filled.
/// \param address  SD card address.
//------------------------------------------------------------------------------
static unsigned char Cmd25(SdCard *pSd,
                           unsigned short nbBlock,
                           unsigned char *pData,
                           unsigned int address,
                           unsigned int *pStatus)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;

    TRACE_DEBUG("Cmd25()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_WRITE_MULTIPLE_BLOCK_CMD;
    pCommand->arg = address;
    pCommand->resType = 1;
    pCommand->pResp = &response;

    pCommand->blockSize = SD_BLOCK_SIZE;
    pCommand->nbBlock = nbBlock;
    pCommand->pData = pData;

    pCommand->dataTran = 1;
    pCommand->tranType = MCI_NEW_TRANSFER;

    // Send command
    error = SendCommand(pSd);
    if (pStatus) *pStatus = response;

    return error;
}

#if MCI_SDIO_ENABLE
//------------------------------------------------------------------------------
/// SDIO R/W Byte Direct, response R5
/// \param pSd Pointer to SdCard instance.
/// \param func Number of function.
/// \param rw   The direction of IO operation, 1 for write.
/// \param raw  Read after write
/// \param addr The register address to access.
/// \param pIoData Pointer to fill written data and response.
//------------------------------------------------------------------------------
static unsigned char Cmd52(SdCard *pSd,
                           unsigned char func,
                           unsigned char rw,
                           unsigned char raw,
                           unsigned int addr,
                           unsigned int *pIoData)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;
    unsigned char byte = 0;

    TRACE_DEBUG("Cmd52()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_SDIO_IO_RW_DIRECT;
    // - argument
    if (pIoData) byte = *pIoData;
    pCommand->arg = byte
                   | (addr << 9)    // register address 25: 9
                   | (raw  << 27)   // ReadAfterWrite   27
                   | (func << 28)   // FunctionNumber   30:28
                   | (rw << 31);    // R/W              31
    pCommand->resType = 5;
    pCommand->pResp = &response;
    // Send command
    error = SendCommand(pSd);
    if (pIoData) *pIoData = response;
    return error;
}

//------------------------------------------------------------------------------
/// SDIO R/W Extended, response R5
/// \param pSd Pointer to SdCard instance.
/// \param func Number of function.
/// \param rw   The direction of IO operation, 1 for write.
/// \param blockMode  R/O on a block basis
/// \param incAddress R/W to incrementing address (1) or fixed address (0)
/// \param addr The register address to access.
/// \param pIoData Pointer to fill written data and response.
/// \param size    Data size base on bytes or blocks depending on blockMode
/// \param pResp   Pointer to response buffer
//------------------------------------------------------------------------------
static unsigned char Cmd53(SdCard *pSd,
                           unsigned char func,
                           unsigned char rw,
                           unsigned char blockMode,
                           unsigned char incAddress,
                           unsigned int  addr,
                           unsigned char *pIoData,
                           unsigned short size,
                           unsigned int *pResp)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;

    TRACE_DEBUG("Cmd53()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_SDIO_IO_RW_EXTENDED;
    // - argument
    pCommand->arg = size
                   | (addr << 9)        // register address 25: 9
                   | (incAddress << 26) // OP Code          26
                   | (blockMode << 27)  // ReadAfterWrite   27
                   | (func << 28)       // FunctionNumber   30:28
                   | (rw << 31);        // R/W              31
    pCommand->resType = 5;
    pCommand->pResp   = pResp;
    
    // - Write...
    if (rw) {}
    else {
        pCommand->cmd |= AT91C_MCI_TRDIR_READ;
        pCommand->isRead = 1;
    }
    // - Block...
    if (blockMode) {
        pCommand->cmd |= AT91C_MCI_TRTYP_SDIO_BLOCK
                       | AT91C_MCI_TRCMD_START;
        pCommand->blockSize = SD_BLOCK_SIZE;
    }
    else {
        pCommand->cmd |= AT91C_MCI_TRTYP_SDIO_BYTE
                       | AT91C_MCI_TRCMD_START;
        pCommand->blockSize = 1;
    }
    pCommand->nbBlock  = size;
    pCommand->pData    = pIoData;
    pCommand->dataTran = 1;
    pCommand->tranType = MCI_NEW_TRANSFER;

    // Send command
    error = SendCommand(pSd);
    return error;
}
#endif

//------------------------------------------------------------------------------
/// Initialization delay: The maximum of 1 msec, 74 clock cycles and supply
/// ramp up time.
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SD card driver instance.
//------------------------------------------------------------------------------
static unsigned char Cmd55(SdCard *pSd)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;

    TRACE_DEBUG("Cmd55()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_APP_CMD;
    pCommand->arg = (pSd->cardAddress << 16);
    pCommand->resType = 1;
    pCommand->pResp = &response;

    // Send command
    error = SendCommand(pSd);

    return error;
}

/*
//------------------------------------------------------------------------------
/// SPI Mode, Reads the OCR register of a card
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SD card driver instance.
/// \param pOcr   OCR value of the card
//------------------------------------------------------------------------------
static unsigned char Cmd58(SdCard *pSd, unsigned int *pOcr)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response[2];

    TRACE_DEBUG("Cmd58()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_READ_OCR_CMD;
    pCommand->resType = 3;
    pCommand->pResp = &response[0];

    // Send command
    error = SendCommand(pSd);
    return error;
}

//------------------------------------------------------------------------------
/// SPI Mode, Set CRC option of a card
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SD card driver instance.
/// \param option  CRC option, 1 to turn on, 0 to trun off
//------------------------------------------------------------------------------
static unsigned char Cmd59(SdCard *pSd, unsigned char option)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;

    TRACE_DEBUG("Cmd59()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_CRC_ON_OFF_CMD;
    pCommand->arg = (option & 0x1);
    pCommand->resType = 1;
    pCommand->pResp = &response;

    // Send command
    error = SendCommand(pSd);

    return error;
}
*/

//------------------------------------------------------------------------------
/// Defines the data bus width (00=1bit or 10=4 bits bus) to be used for data
/// transfer.
/// The allowed data bus widths are given in SCR register.
/// \param pSd  Pointer to a SD card driver instance.
/// \param busWidth  Bus width in bits.
/// \return the command transfer result (see SendCommand).
//------------------------------------------------------------------------------
static unsigned char Acmd6(SdCard *pSd, unsigned char busWidth)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response;

    TRACE_DEBUG("Acmd6()\n\r");

    error = Cmd55(pSd);
    if (error) {
        TRACE_ERROR("Acmd6.Cmd55: %d\n\r", error);
        return error;
    }

    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_SD_SET_BUS_WIDTH_CMD;
    pCommand->arg = (busWidth == 4) ? SD_STAT_DATA_BUS_WIDTH_4BIT :
                                      SD_STAT_DATA_BUS_WIDTH_1BIT;
    pCommand->resType = 1;
    pCommand->pResp = &response;

    // Send command
    return SendCommand(pSd);
}

//------------------------------------------------------------------------------
/// The SD Status contains status bits that are related to the SD memory Card
/// proprietary features and may be used for future application-specific usage.
/// Can be sent to a card only in 'tran_state'.
//------------------------------------------------------------------------------
static unsigned char Acmd13(SdCard *pSd, unsigned int * pSdSTAT)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response[1];

    TRACE_DEBUG("Acmd13()\n\r");

    error = Cmd55(pSd);
    if (error) {
        TRACE_ERROR("Acmd13.Cmd55: %d\n\r", error);
        return error;
    }

    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_SD_STATUS_CMD;
    pCommand->resType = 1;
    pCommand->pResp = response;

    pCommand->blockSize = 512 / 8;
    pCommand->nbBlock = 1;
    pCommand->pData = (unsigned char*)pSdSTAT;

    pCommand->dataTran = 1;
    pCommand->isRead = 1;
    pCommand->tranType = MCI_NEW_TRANSFER;

    // Send command
    error = SendCommand(pSd);

    return error;
}

//------------------------------------------------------------------------------
/// Asks to all cards to send their operations conditions.
/// Returns the command transfer result (see SendCommand).
/// \param pSd  Pointer to a SD card driver instance.
/// \param hcs  Shall be true if Host support High capacity.
/// \param pCCS  Set the pointed flag to 1 if hcs != 0 and SD OCR CCS flag is set.
//------------------------------------------------------------------------------
static unsigned char Acmd41(SdCard *pSd, unsigned char hcs, unsigned char *pCCS)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int  response;

    do {
        error = Cmd55(pSd);
        if (error) {
            return error;
        }

        ResetCommand(pCommand);
        // Fill command information
        pCommand->cmd = AT91C_SD_APP_OP_COND_CMD;
        pCommand->arg = AT91C_MMC_HOST_VOLTAGE_RANGE;
        if (hcs) {
            pCommand->arg |= AT91C_CCS;
        }

        pCommand->resType = 3;
        pCommand->pResp = &response;

        // Send command
        TRACE_DEBUG("Acmd41()\n\r");
        error = SendCommand(pSd);
        if (error) {
            return error;
        }
        *pCCS  = ((response & AT91C_CCS) != 0);
    }
    while ((response & AT91C_CARD_POWER_UP_BUSY) != AT91C_CARD_POWER_UP_BUSY);

    return 0;
}

//------------------------------------------------------------------------------
/// SD Card Configuration Register (SCR) provides information on the SD Memory
/// Card's special features that were configured into the given card. The size
/// of SCR register is 64 bits.
//------------------------------------------------------------------------------
static unsigned char Acmd51(SdCard *pSd, unsigned int * pSCR)
{
    SdCmd *pCommand = &(pSd->command);
    unsigned char error;
    unsigned int response[1];

    TRACE_DEBUG("Acmd51()\n\r");

    error = Cmd55(pSd);
    if (error) {
        TRACE_ERROR("Acmd51.Cmd55: %d\n\r", error);
        return error;
    }

    ResetCommand(pCommand);
    // Fill command information
    pCommand->cmd = AT91C_SD_SEND_SCR_CMD;
    pCommand->resType = 1;
    pCommand->pResp = response;

    pCommand->blockSize = 64 / 8;
    pCommand->nbBlock = 1;
    pCommand->pData = (unsigned char*)pSCR;

    pCommand->dataTran = 1;
    pCommand->isRead = 1;
    pCommand->tranType = MCI_NEW_TRANSFER;

    // Send command
    error = SendCommand(pSd);

    //if (!error) Int2MsbFirstStream((unsigned char*)pSCR, 8 / 4);

    return error;
}

#if defined(MCI2_INTERFACE) && defined(AT91C_MCI_SPCMD_BOOTREQ)
//------------------------------------------------------------------------------
/// Terminate boot stream.
/// \param pSd      Pointer to SdCard instance.
//------------------------------------------------------------------------------
static unsigned char BootEnd(SdCard *pSd)
{
    SdCmd * pCommand = &(pSd->command);

    TRACE_DEBUG("BootEnd()\n\r");
    ResetCommand(pCommand);

    // Send boot end
    pCommand->cmd = AT91C_BOOTEND;

    return SendCommand(pSd);
}

//------------------------------------------------------------------------------
/// In boot operation mode, the processor can read boot data from the slave,
/// by keeping the CMD line low after power-on before issuing CMD1.
/// BootEnd() must be invoked after the boot request done.
/// \param pSd      Pointer to SdCard instance.
/// \param pBuffer  The buffer holding received data.
/// \param length   The buffer length.
//------------------------------------------------------------------------------
static unsigned char BootREQ(SdCard *pSd,
                             unsigned char* pBuffer,
                             unsigned int   nbBlocks,
                             unsigned char  ackEnable)
{
    SdCmd * pCommand = &(pSd->command);
    unsigned char error;

    TRACE_DEBUG("BootREQ()\n\r");
    ResetCommand(pCommand);

    // Send boot request
    pCommand->cmd = ackEnable ? (AT91C_BOOTREQ | AT91C_MCI_BOOTACK)
                              :  AT91C_BOOTREQ;
    pCommand->blockSize = SD_BLOCK_SIZE;
    pCommand->nbBlock   = nbBlocks;
    pCommand->pData     = pBuffer;
    pCommand->isRead    = 1;
    pCommand->tranType = MCI_NEW_TRANSFER;

    error = SendCommand(pSd);
    if (error) {
        TRACE_ERROR("BootOperation.BootReq: %d\n\r", error);
        return error;
    }
    return error;
}
#endif

//------------------------------------------------------------------------------
/// Continue to transfer datablocks from card to host until interrupted by a
/// STOP_TRANSMISSION command.
/// \param pSd  Pointer to a SD card driver instance.
/// \param blockSize  Block size (shall be set to 512 in case of high capacity).
/// \param pData  Pointer to the application buffer to be filled.
/// \param address  SD card address.
//------------------------------------------------------------------------------
static unsigned char ContinuousRead(SdCard *pSd,
                                    unsigned short nbBlock,
                                    unsigned char *pData,
                                    SdCallback     pCb,
                                    void          *pArg)
{
    SdCmd *pCommand = &(pSd->command);

    TRACE_DEBUG("Read()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->blockSize = SD_BLOCK_SIZE;
    pCommand->nbBlock   = nbBlock;
    pCommand->pData     = pData;

    pCommand->dataTran = 1;
    pCommand->tranType = MCI_CONTINUE_TRANSFER;
    pCommand->isRead = 1;
    
    pCommand->callback = pCb;
    pCommand->pArg     = pArg;

    // Send command
    return SendCommand(pSd);
}

//------------------------------------------------------------------------------
/// Continue to transfer datablocks from host to card until interrupted by a
/// STOP_TRANSMISSION command.
/// \param pSd  Pointer to a SD card driver instance.
/// \param blockSize  Block size (shall be set to 512 in case of high capacity).
/// \param pData  Pointer to the application buffer to be filled.
//------------------------------------------------------------------------------
static unsigned char ContinuousWrite(SdCard *pSd,
                                     unsigned short nbBlock,
                                     const unsigned char *pData,
                                     SdCallback     pCb,
                                     void          *pArg)
{
    SdCmd *pCommand = &(pSd->command);

    TRACE_DEBUG("Write()\n\r");
    ResetCommand(pCommand);
    // Fill command information
    pCommand->blockSize = SD_BLOCK_SIZE;
    pCommand->nbBlock   = nbBlock;
    pCommand->pData     = (unsigned char*)pData;

    pCommand->dataTran = 1;
    pCommand->tranType = MCI_CONTINUE_TRANSFER;
    
    pCommand->callback = pCb;
    pCommand->pArg     = pArg;

    // Send command
    return SendCommand(pSd);
}

//------------------------------------------------------------------------------
/// Try SW Reset several times (CMD0 with ARG 0)
/// \param pSd      Pointer to a SD card driver instance.
/// \param retry    Retry times.
/// \return 0 or MCI error code.
//------------------------------------------------------------------------------
static unsigned char SwReset(SdCard *pSd, unsigned int retry)
{
    unsigned int i;
    unsigned char error = 0;

    for (i = 0; i < retry; i ++) {
        error = Cmd0(pSd, 0);
        if (error != MCI_STATUS_NORESPONSE)
            break;
    }
    return error;
}
/*
//------------------------------------------------------------------------------
/// Re-init card to trans state.
//------------------------------------------------------------------------------
static unsigned char ReInit(SdCard *pSd)
{
    #if 0
    unsigned char error;
    error = SwReset(pSd, 1);
    if (error) {
        TRACE_ERROR("ReInit.Cmd0: %d\n\r", error);
        return error;
    }
    error = Cmd1(pSd);
    if (error) {
        TRACE_ERROR("ReInit.Cmd1: %d\n\r", error);
        return error;
    }
    error = Cmd2(pSd);
    if (error) {
        TRACE_ERROR("ReInit.Cmd2: %d\n\r", error);
        return error;
    }
    error = Cmd3(pSd);
    if (error) {
        TRACE_ERROR("ReInit.Cmd3: %d\n\r", error);
        return error;
    }
    error = Cmd7(pSd, pSd->cardAddress);
    if (error) {
        TRACE_ERROR("ReInit.Cmd7: %d\n\r", error);
        return error;
    }
    #endif
    return 0;
}
*/
//------------------------------------------------------------------------------
/// Move SD card to transfer state.
//------------------------------------------------------------------------------
static unsigned char MoveToTranState(SdCard * pSd)
{
    unsigned char error;
    unsigned int  status;

    // Quit transfer state
    if((pSd->state == SD_STATE_READ)
    || (pSd->state == SD_STATE_WRITE)) {

        error = Cmd12(pSd,
                      (pSd->state == SD_STATE_READ),
                      &status);
        if (error) {
            TRACE_ERROR("MvToTran.Cmd12: %d\n\r", error);
            return error;
        }
    }

    // Put device into tran state
    error = Cmd13(pSd, &status);
    if (error) {
        TRACE_ERROR("MvToTran.Cmd13: %d\n\r", error);
        return error;
    }
    if ((status & STATUS_STATE) == STATUS_STBY) {
        error = Cmd7(pSd, pSd->cardAddress);
        if (error) {
            TRACE_ERROR("MvToTran.Cmd7: %d\n\r", error);
            return error;
        }
    }

    return 0;
}

#if defined(SINGLE_READ) || defined(SINGLE_WRITE)
static unsigned char PerformSingleTransfer(SdCard *pSd,
                                           unsigned int address,
                                           unsigned char *pData,
                                           unsigned char isRead)
{
    unsigned int status;
    unsigned char error = 0;

    /* Reset transfer state if previous in multi- mode */
    if(    (pSd->state == SD_STATE_READ)
        || (pSd->state == SD_STATE_WRITE)) {
        /* Stop transfer */
        error = Cmd12(pSd, (pSd->state == SD_STATE_READ), &status);
        if (error) {
            TRACE_ERROR("SingleTx.Cmd12: st%x, er%d\n\r", pSd->state, error);
        }
        pSd->state = SD_STATE_READY;
        pSd->preBlock = 0xFFFFFFFF;
    }

#ifdef SINGLE_READ
    if(isRead) {
        // Wait for card to be ready for data transfers
        do {
            error = Cmd13(pSd, &status);
            if (error) {
                TRACE_ERROR("SingleTx.RD.Cmd13: %d\n\r", error);
                return error;
            }
            if(  ((status & STATUS_STATE) == STATUS_IDLE)
               ||((status & STATUS_STATE) == STATUS_READY)
               ||((status & STATUS_STATE) == STATUS_IDENT)) {
                TRACE_ERROR("SingleTx.mode\n\r");
                return SD_ERROR_NOT_INITIALIZED;
            }
            // If the card is in sending data state or in receivce data state
            if (  ((status & STATUS_STATE) == STATUS_RCV)
                ||((status & STATUS_STATE) == STATUS_DATA) ){

                TRACE_DEBUG("SingleTx.state = 0x%X\n\r", (status & STATUS_STATE) >> 9);
            }
        }
        while (    ((status & STATUS_READY_FOR_DATA) == 0)
                || ((status & STATUS_STATE) != STATUS_TRAN) );
        ASSERT((status & STATUS_STATE) == STATUS_TRAN,
                "SD Card can't be configured in transfer state 0x%X\n\r",
                (status & STATUS_STATE)>>9);
        // Read data
        // Move to Sending data state
        error = Cmd17(pSd, pData, SD_ADDRESS(pSd,address), &status);
        if (error) {
            TRACE_ERROR("SingleTx.Cmd17: %d\n\r", error);
            return error;
        }
        if (status & ~(STATUS_READY_FOR_DATA | STATUS_STATE)) {
            TRACE_ERROR("CMD17.stat: %x\n\r",
                status & ~(STATUS_READY_FOR_DATA | STATUS_STATE));
            return SD_ERROR_DRIVER;
        }
        return error;
    }
#endif
#ifdef SINGLE_WRITE
    // Write
    {
        // Wait for card to be ready for data transfers
        do {
            error = Cmd13(pSd, &status);
            if (error) {
                TRACE_ERROR("SingleTx.WR.Cmd13: %d\n\r", error);
                return error;
            }
        }
        while ((status & STATUS_READY_FOR_DATA) == 0);
        // Move to Sending data state
        error = Cmd24(pSd, pData, SD_ADDRESS(pSd,address), &status);
        if (error) {
            TRACE_DEBUG("SingleTx.Cmd25: %d\n\r", error);
            return error;
        }
        if (status & (STATUS_WRITE & ~(STATUS_READY_FOR_DATA | STATUS_STATE))) {
            TRACE_ERROR("CMD24(0x%x).stat: %x\n\r",
                SD_ADDRESS(pSd,address), 
                status & (STATUS_WRITE
                            & ~(STATUS_READY_FOR_DATA | STATUS_STATE)));
            return SD_ERROR_DRIVER;
        }
    }
    return error;
#endif
}
#endif

//------------------------------------------------------------------------------
/// Move SD card to transfer state. The buffer size must be at
/// least 512 byte long. This function checks the SD card status register and
/// address the card if required before sending the transfer command.
/// Returns 0 if successful; otherwise returns an code describing the error.
/// \param pSd      Pointer to a SD card driver instance.
/// \param address  Address of the block to transfer.
/// \param nbBlocks Number of blocks to be transfer, 0 for infinite transfer.
/// \param pData    Data buffer whose size is at least the block size.
/// \param isRead   1 for read data and 0 for write data.
//------------------------------------------------------------------------------
static unsigned char MoveToTransferState(SdCard *pSd,
                                         unsigned int address,
                                         unsigned short nbBlocks,
                                         unsigned char *pData,
                                         unsigned char isRead)
{
    unsigned int status;
    unsigned char error;

    if(    (pSd->state == SD_STATE_READ)
        || (pSd->state == SD_STATE_WRITE)) {
#if 1//!defined(MCI2_INTERFACE)
        if (pSd->state == SD_STATE_WRITE) {
            DBGU_PutChar(0);
            DBGU_PutChar(0);
            DBGU_PutChar(0);
            DBGU_PutChar(0);
        }
#endif
        // RW MULTI with length
        error = Cmd12(pSd,
                      (pSd->state == SD_STATE_READ),
                      &status);
        if (error) {
            TRACE_ERROR("MTTranState.Cmd12: st%x, er%d\n\r", pSd->state, error);
            return error;
        }
#if !defined(MCI2_INTERFACE)
        // RW MULTI Infinite
        if (pSd->state == SD_STATE_WRITE) {
            while(MCI_CheckBusy((Mci *)pSd->pSdDriver) != 0);
        }
#endif
    }

    if(isRead) {
        // Wait for card to be ready for data transfers
        do {
            error = Cmd13(pSd, &status);
            if (error) {
                TRACE_ERROR("MTTranState.RD.Cmd13: %d\n\r", error);
                return error;
            }
            if(  ((status & STATUS_STATE) == STATUS_IDLE)
               ||((status & STATUS_STATE) == STATUS_READY)
               ||((status & STATUS_STATE) == STATUS_IDENT)) {
                TRACE_ERROR("Pb Card Identification mode\n\r");
                return SD_ERROR_NOT_INITIALIZED;
            }
            // If the card is in sending data state or in receivce data state
            if (  ((status & STATUS_STATE) == STATUS_RCV)
                ||((status & STATUS_STATE) == STATUS_DATA) ){

                TRACE_DEBUG("state = 0x%X\n\r", (status & STATUS_STATE) >> 9);
            }
        }
        while (    ((status & STATUS_READY_FOR_DATA) == 0)
                || ((status & STATUS_STATE) != STATUS_TRAN) );
        ASSERT((status & STATUS_STATE) == STATUS_TRAN,
                "SD Card can't be configured in transfer state 0x%X\n\r",
                (status & STATUS_STATE)>>9);
        // Read data
        // Move to Sending data state
        error = Cmd18(pSd, nbBlocks, pData, SD_ADDRESS(pSd,address), &status);
        if (error) {
            TRACE_ERROR("MTTranState.Cmd18: %d\n\r", error);
            return error;
        }
        if (status & ~(STATUS_READY_FOR_DATA | STATUS_STATE)) {
            TRACE_ERROR("CMD18.stat: %x\n\r",
                status & ~(STATUS_READY_FOR_DATA | STATUS_STATE));
            return SD_ERROR_DRIVER;
        }
    }
    else {
        // Wait for card to be ready for data transfers
        do {
            error = Cmd13(pSd, &status);
            if (error) {
                TRACE_ERROR("MoveToTransferState.WR.Cmd13: %d\n\r", error);
                return error;
            }
        }
        while ((status & STATUS_READY_FOR_DATA) == 0);
        // Move to Sending data state
        error = Cmd25(pSd, nbBlocks, pData, SD_ADDRESS(pSd,address), &status);
        if (error) {
            TRACE_DEBUG("MoveToTransferState.Cmd25: %d\n\r", error);
            return error;
        }
        if (status & (STATUS_WRITE & ~(STATUS_READY_FOR_DATA | STATUS_STATE))) {
            TRACE_ERROR("CMD25(0x%x, %d).stat: %x\n\r",
                SD_ADDRESS(pSd,address), nbBlocks,
                status & (STATUS_WRITE
                            & ~(STATUS_READY_FOR_DATA | STATUS_STATE)));
            return SD_ERROR_DRIVER;
        }
    }

    if (!error) pSd->preBlock = address + (nbBlocks-1);
    return error;
}

//------------------------------------------------------------------------------
/// Switch the bus width of card
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Switch the HS mode of card
/// \param pSd      Pointer to SdCard instance.
/// \param hsEnable 1 to enable, 0 to disable.
//------------------------------------------------------------------------------
static unsigned char SdMmcSwitchHsMode(SdCard *pSd, unsigned char hsEnable)
{
    unsigned int status;
    unsigned char error = SD_ERROR_DRIVER;
    if (pSd->mode == hsEnable)
        return 0;
    if (pSd->cardType >= CARD_MMC) {
        MmcCmd6Arg cmd6Arg;
        cmd6Arg.access = 0x3;
        cmd6Arg.index  = SD_EXTCSD_HS_TIMING_INDEX;
        cmd6Arg.value  = hsEnable ? SD_EXTCSD_HS_TIMING_ENABLE
                                  : SD_EXTCSD_HS_TIMING_DISABLE;
        cmd6Arg.cmdSet = 0;
        error = Cmd6(pSd, &cmd6Arg, 0, &status);
        if (error) {
            TRACE_ERROR("MMC SwitchHs.Cmd6: %d\n\r", error);
        }
        else if (status & STATUS_SWITCH_ERROR) {
            TRACE_WARNING("MMC HS SW Fail\n\r");
            error = SD_ERROR_DRIVER;
        }
        else {
            TRACE_WARNING_WP("-I- MMC HS %d\n\r", hsEnable);
            pSd->mode = hsEnable;
        }
    }
    else if (pSd->cardType >= CARD_SD) {
        SdCmd6Arg cmd6Arg;
        unsigned int switchStatus[512/32];
        cmd6Arg.mode = 1;
        cmd6Arg.reserved = 0;
        cmd6Arg.reserveFG6 = 0xF;
        cmd6Arg.reserveFG5 = 0xF;
        cmd6Arg.reserveFG4 = 0xF;
        cmd6Arg.reserveFG3 = 0xF;
        cmd6Arg.command = 0;
        cmd6Arg.accessMode = 1;
        error = Cmd6(pSd,
                     &cmd6Arg,
                     switchStatus,
                     &status);
      #if 0
        unsigned int i;
        printf("SD Switch status:");
        for(i = 0; i < 512 / 8; i ++) {
            if ((i % 8) == 0) printf("\n\r[%3d]", i);
            printf(" %02x", ((char*)switchStatus)[i]);
        }
        printf("\n\r");
        printf(" _FG1_INFO %x\n\r",
            SD_SW_STAT_FUN_GRP1_INFO(switchStatus));
        printf(" _FG1_RC   %x\n\r",
            SD_SW_STAT_FUN_GRP1_RC(switchStatus));
        printf(" _FG1_BUSY %x\n\r",
            SD_SW_STAT_FUN_GRP1_BUSY(switchStatus));
        printf(" _FG1_DS_V %x\n\r",
            SD_SW_STAT_DATA_STRUCT_VER(switchStatus));
      #endif
        if (error) {
            TRACE_ERROR("SD SwitchHs.Cmd6: %d\n\r", error);
        }
        else if (status & STATUS_SWITCH_ERROR) {
            TRACE_WARNING("SD HS SW Fail\n\r");
            error = SD_ERROR_DRIVER;
        }
        else if (SD_SW_STAT_FUN_GRP1_RC(switchStatus)
                        == SD_SW_STAT_FUN_GRP_RC_ERROR) {
            TRACE_ERROR_WP("-I- SD HS Not Supported\n\r");
            error = SD_ERROR_DRIVER;
        }
        else if (SD_SW_STAT_FUN_GRP1_BUSY(switchStatus)) {
            TRACE_WARNING("SD HS Busy\n\r");
            error = SD_ERROR_DRIVER;
        }
        else {
            TRACE_WARNING_WP("-I- SD HS %d\n\r", hsEnable);
            pSd->mode = hsEnable;
        }
    }

    return error;
}

#if defined(MCI2_INTERFACE) && defined(AT91C_MCI_SPCMD_BOOTREQ)
//------------------------------------------------------------------------------
/// Process a list of SWITCH command
/// \param  pSd      Pointer to SdCard instance.
/// \param  pArgList Argument list.
/// \param  listSize Number of arguments listed.
/// \return 0, or error code and argument index.
//------------------------------------------------------------------------------
static unsigned short MmcSwitchSettings(SdCard *pSd,
                                       const MmcCmd6Arg * pArgList,
                                       unsigned int listSize,
                                       unsigned int * pErrSta)
{
    unsigned int i, status;
    unsigned char error;

    SANITY_CHECK(pSd);
    SANITY_CHECK(pArgList);

    for (i = 0; i < listSize; i ++) {
        error = Cmd6(pSd, &pArgList[i], 0, &status);
        if (pErrSta) *pErrSta = status;
        if (error) {
            return (error | (i << 8));
        }
        if (status & ~(STATUS_STATE | STATUS_READY_FOR_DATA)) {
            TRACE_WARNING("Error in SWITCH.%d, 0x%x\n\r",
                          pArgList[i].index, status);
        }
        else {
            TRACE_INFO("SWITCH.%d: 0x%x\n\r",
                       pArgList[i].index, status);
        }
    }
    return 0;
}
#endif

//------------------------------------------------------------------------------
/// Switch card state between STBY and TRAN
/// \param pSd      Pointer to a SD card driver instance.
/// \param address  Card address to TRAN, 0 to STBY
/// \param check    Whether to check the state
//------------------------------------------------------------------------------
static unsigned char MmcSelectCard(SdCard *pSd,
                                   unsigned short address,
                                   unsigned char check)
{
    unsigned char error;
    unsigned int  status;
    unsigned int  targetState = address ? STATUS_TRAN : STATUS_STBY;
    unsigned int  srcState    = address ? STATUS_STBY : STATUS_TRAN;
    if (pSd->cardType == CARD_SDIO) check = 0;

    // At this stage the Initialization and identification process is achieved
    // The SD card is supposed to be in Stand-by State
    while(check) {
        error = Cmd13(pSd, &status);
        if (error) {
            TRACE_ERROR("MmcSelectCard.Cmd13 (%d)\n\r", error);
            return error;
        }
        if ((status & STATUS_READY_FOR_DATA)) {
            unsigned int currState = status & STATUS_STATE;
            if (currState == targetState) return 0;
            if (currState != srcState) {
                TRACE_ERROR("MmcSelectCard, wrong state %x\n\r", currState);
                return SD_ERROR_DRIVER;
            }
            break;
        }
    }

    // witch to TRAN mode to Select the current SD/MMC
    // so that SD ACMD6 can process or EXT_CSD can read.
    error = Cmd7(pSd, address);
    if (error == SD_ERROR_NOT_INITIALIZED && address == 0) {}
    else if (error) {
        TRACE_ERROR("MmcSelectCard.Cmd7 (%d)\n\r", error);
    }

    return error;
}

//------------------------------------------------------------------------------
/// Get EXT_CSD information
/// \param pSd      Pointer to a SD card driver instance.
//------------------------------------------------------------------------------
static unsigned char MmcGetExtInformation(SdCard *pSd)
{
    unsigned char error;
    unsigned int i;

    // CSD 1.2 or Higher version
    if(SD_CSD_STRUCTURE(pSd) >= 2) {

        /* Clear EXT_CSD data */
        for (i = 0;i < 512/4; i ++) pSd->extData[i] = 0;
        error = Cmd8(pSd, 0, pSd->extData);
        if (error) {
            TRACE_ERROR("MmcGetExt.Cmd8: %d\n\r", error);
        }
    }
    return 0;
}

//------------------------------------------------------------------------------
/// Get SCR and SD Status information
/// \param pSd      Pointer to a SD card driver instance.
//------------------------------------------------------------------------------
static unsigned char SdGetExtInformation(SdCard *pSd)
{
    unsigned char error;

    // Reset data (64 + 512 bits, 8 + 64 bytes)
    // memset(pSd->extData, 0x00, 512);

    // SD Status
    if (pSd->optCmdBitMap & SD_ACMD13_SUPPORT) {
        error = Acmd13(pSd, &pSd->extData[SD_EXT_OFFSET_SD_STAT]);
        if (error) {
            TRACE_ERROR("SdGetExt.Acmd13: %d\n\r", error);
            pSd->optCmdBitMap &= ~SD_ACMD13_SUPPORT;
        }
    }

    // SD SCR
    error = Acmd51(pSd, &pSd->extData[SD_EXT_OFFSET_SD_SCR]);
    if (error) {
        TRACE_ERROR("SdGetExt.Acmd51: %d\n\r", error);
    }

    return 0;
}

//------------------------------------------------------------------------------
/// Update SD/MMC information.
/// Update CSD for card speed switch.
/// Update ExtDATA for any card function switch.
/// \param pSd      Pointer to a SD card driver instance.
/// \return error code when update CSD error.
//------------------------------------------------------------------------------
static unsigned char SdMmcUpdateInformation(SdCard *pSd,
                                            unsigned char csd,
                                            unsigned char extData)
{
    unsigned char error;

    // Update CSD for new TRAN_SPEED value
    if (csd) {
        MmcSelectCard(pSd, 0, 1);
        Delay(800);
        error = Cmd9(pSd);
        if (error ) {
            TRACE_ERROR("SdMmcUpdateInfo.Cmd9 (%d)\n\r", error);
            return error;
        }
        error = MmcSelectCard(pSd, pSd->cardAddress, 1);
    }
    if (pSd->cardType >= CARD_MMC)     MmcGetExtInformation(pSd);
    else if (pSd->cardType >= CARD_SD) SdGetExtInformation(pSd);
    GetTransSpeedValue(pSd);

    return 0;
}

#if MCI_SDIO_ENABLE
//------------------------------------------------------------------------------
/// Find ManfID, Func0 tuple.
//------------------------------------------------------------------------------
static unsigned char SdioFindTuples(SdCard * pSd,
                                    unsigned int address, unsigned int size,
                                    unsigned int *pAddrManfID,
                                    unsigned int *pAddrFunc0)
{
    unsigned char error, tmp[3];
    unsigned int addr = address;
    unsigned char nbFound = 0;
    for (;;) {
        error = SDIO_ReadDirect(pSd, 0, addr, tmp, 3);
        if (error)
            return error;
        // ManfID
        if (tmp[0] == CISTPL_MANFID) {
            if (pAddrManfID) *pAddrManfID = addr;
            nbFound ++;
        }
        // Func0
        if (tmp[0] == CISTPL_FUNCE && tmp[2] == 0x00) {
            if (pAddrFunc0) *pAddrFunc0 = addr;
            nbFound ++;
        }
        // END
        if (tmp[0] == CISTPL_END) break;

        // All found
        if (nbFound >= 2)         break;
        // Not tuple?
        if (tmp[1] == 0)          break;

        // Next address
        addr += (tmp[1] + 2);
        if (addr > (address + size))
            break;
    }
    return 0;
}
#endif

//------------------------------------------------------------------------------
//         Global functions
//------------------------------------------------------------------------------

#if MCI_SDIO_ENABLE
//------------------------------------------------------------------------------
/// Read at least one byte from SDIO card, using RW_DIRECT command.
/// \param pSd      Pointer to SdCard instance.
/// \param funNb    Function number.
/// \param address  First byte address of data in SDIO card.
/// \param pBytes   Pointer to data buffer.
/// \param size     Buffer size.
//------------------------------------------------------------------------------
unsigned char SDIO_ReadDirect(SdCard *pSd,
                              unsigned char funNb,
                              unsigned int  address,
                              unsigned char *pBytes,
                              unsigned int  size)
{
    unsigned char error;
    unsigned int status;
    if (pSd->cardType < CARD_SDIO) {
        return SD_ERROR_NOT_SUPPORT;
    }
    if (size == 0)
        return SD_ERROR_DRIVER;

    while(size --) {
        status = 0;
        error = Cmd52(pSd, funNb, 0, 0, address ++, &status);
        if (pBytes) *pBytes ++ = (unsigned char)status;
        if (error) {
            TRACE_ERROR("SDIO_ReadDirect.Cmd52: %d, %x\n\r", error, status);
            return SD_ERROR_DRIVER;
        }
    }

    return 0;
}

//------------------------------------------------------------------------------
/// Write one byte to SDIO card, using RW_DIRECT command.
/// \param pSd      Pointer to SdCard instance.
/// \param funNb    Function number.
/// \param address  First byte address of data in SDIO card.
/// \param pBytes   Pointer to data buffer.
/// \param size     Buffer size.
//------------------------------------------------------------------------------
unsigned char SDIO_WriteDirect(SdCard *pSd,
                               unsigned char funNb,
                               unsigned int address,
                               unsigned char byte)
{
    if (pSd->cardType < CARD_SDIO) {
        return SD_ERROR_NOT_SUPPORT;
    }
    unsigned char error;
    unsigned int status;
    status = byte;
    error = Cmd52(pSd, funNb, 1, 0, address, &status);
    if (error) {
        TRACE_ERROR("SDIO_ReadDirect.Cmd52: %d, %x\n\r", error, status);
        return SD_ERROR_DRIVER;
    }

    return 0;
}

//------------------------------------------------------------------------------
/// Read byte by byte from SDIO card, using RW_EXT command.
/// \param pSd          Pointer to SdCard instance.
/// \param funNb        Function number.
/// \param address      First byte address of data in SDIO card.
/// \param isFixedAddr  Address not increased.
/// \param pBytes       Pointer to data buffer.
/// \param size         Buffer size.
//------------------------------------------------------------------------------
unsigned char SDIO_ReadBytes(SdCard *pSd,
                             unsigned char funNb,
                             unsigned int  address,
                             unsigned char isFixedAddr,
                             unsigned char *pBytes,
                             unsigned int   size)
{
    unsigned char error;
    unsigned int status;
    if (pSd->cardType < CARD_SDIO) {
        return SD_ERROR_NOT_SUPPORT;
    }

    if (size == 0)
        return SD_ERROR_DRIVER;

    error = Cmd53(pSd, funNb,
                  0, 0, !isFixedAddr,
                  address, pBytes, size, &status);
    if (error || (status & STATUS_SDIO_CMD52)) {
        TRACE_ERROR("SDIO_ReadBytes.Cmd53: %d, %x\n\r", error, status);
        return SD_ERROR_DRIVER;
    }

    return 0;
}

//------------------------------------------------------------------------------
/// Write byte by byte to SDIO card, using RW_EXT command.
/// \param pSd          Pointer to SdCard instance.
/// \param funNb        Function number.
/// \param address      First byte address of data in SDIO card.
/// \param isFixedAddr  Address not increased.
/// \param pBytes       Pointer to data buffer.
/// \param size         Buffer size.
//------------------------------------------------------------------------------
unsigned char SDIO_WriteBytes(SdCard *pSd,
                              unsigned char funNb,
                              unsigned int  address,
                              unsigned char isFixedAddr,
                              unsigned char *pBytes,
                              unsigned int   size)
{
    unsigned char error;
    unsigned int status;
    if (pSd->cardType < CARD_SDIO) {
        return SD_ERROR_NOT_SUPPORT;
    }
    if (size == 0)
        return SD_ERROR_DRIVER;

    error = Cmd53(pSd, funNb,
                  1, 0, !isFixedAddr,
                  address, pBytes, size, &status);
    if (error || (status & STATUS_SDIO_CMD52)) {
        TRACE_ERROR("SDIO_ReadBytes.Cmd53: %d, %x\n\r", error, status);
        return SD_ERROR_DRIVER;
    }

    return 0;
}
#endif

//------------------------------------------------------------------------------
/// Read Block of data in a buffer pointed by pData. The buffer size must be at
/// least 512 byte long. This function checks the SD card status register and
/// address the card if required before sending the read command.
/// Returns 0 if successful; otherwise returns an code describing the error.
/// \param pSd      Pointer to a SD card driver instance.
/// \param address  Address of the block to read.
/// \param pData    Data buffer whose size is at least the block size, it can
///            be 1,2 or 4-bytes aligned when used with DMA.
/// \param length   Number of blocks to be read.
/// \param pCallback Pointer to callback function that invoked when read done.
///                  0 to start a blocked read.
/// \param pArgs     Pointer to callback function arguments.
//------------------------------------------------------------------------------
unsigned char SD_Read(SdCard        *pSd,
                      unsigned int   address,
                      void          *pData,
                      unsigned short length,
                      SdCallback     pCallback,
                      void          *pArgs)
{
    unsigned char error;

    // If callback is defined, performe none blocked reading
    if (pCallback) {
        if (MCI_IsTxComplete((Mci *)pSd) == 0) {
            return SD_ERROR_BUSY;
        }
    }

    if (   pSd->state != SD_STATE_READ
        || pSd->preBlock + 1 != address ) {
        // Start infinite block reading
        error = MoveToTransferState(pSd, address, 0, 0, 1);
    }
    else    error = 0;
    if (!error) {
        pSd->state = SD_STATE_READ;
        pSd->preBlock = address + (length - 1);
        error = ContinuousRead(pSd,
                               length,
                               pData,
                               pCallback, pArgs);
    }
    TRACE_DEBUG("SDrd(%u,%u):%u\n\r", address, length, error);

    return 0;    
}

//------------------------------------------------------------------------------
/// Write Block of data in a buffer pointed by pData. The buffer size must be at
/// least 512 byte long. This function checks the SD card status register and
/// address the card if required before sending the read command.
/// Returns 0 if successful; otherwise returns an code describing the error.
/// \param pSd      Pointer to a SD card driver instance.
/// \param address  Address of the block to read.
/// \param pData    Data buffer whose size is at least the block size, it can
///            be 1,2 or 4-bytes aligned when used with DMA.
/// \param length   Number of blocks to be read.
/// \param pCallback Pointer to callback function that invoked when read done.
///                  0 to start a blocked read.
/// \param pArgs     Pointer to callback function arguments.
//------------------------------------------------------------------------------
unsigned char SD_Write(SdCard        *pSd,
                       unsigned int   address,
                       void          *pData,
                       unsigned short length,
                       SdCallback     pCallback,
                       void          *pArgs)
{
    unsigned char error;
    // If callback is defined, performe none blocked writing
    if (pCallback) {
        if (MCI_IsTxComplete((Mci *)pSd) == 0) {
            return SD_ERROR_BUSY;
        }
    }
    if (   pSd->state != SD_STATE_WRITE
        || pSd->preBlock + 1 != address ) {
        // Start infinite block writing
        error = MoveToTransferState(pSd, address, 0, 0, 0);
    }
    else    error = 0;
    if (!error) {
        pSd->state = SD_STATE_WRITE;
        error = ContinuousWrite(pSd,
                                length,
                                pData,
                                pCallback, pArgs);
        pSd->preBlock = address + (length - 1);
    }
    TRACE_DEBUG("SDwr(%u,%u):%u\n\r", address, length, error);
    
    return 0;
}

//------------------------------------------------------------------------------
/// Read Block of data in a buffer pointed by pData. The buffer size must be at
/// least 512 byte long. This function checks the SD card status register and
/// address the card if required before sending the read command.
/// Returns 0 if successful; otherwise returns an code describing the error.
/// \param pSd  Pointer to a SD card driver instance.
/// \param address  Address of the block to read.
/// \param nbBlocks Number of blocks to be read.
/// \param pData    Data buffer whose size is at least the block size, it can
///            be 1,2 or 4-bytes aligned when used with DMA.
//------------------------------------------------------------------------------
unsigned char SD_ReadBlock(SdCard *pSd,
                           unsigned int address,
                           unsigned short nbBlocks,
                           unsigned char *pData)
{
    unsigned char error = 0;

    SANITY_CHECK(pSd);
    SANITY_CHECK(pData);
    SANITY_CHECK(nbBlocks);

    TRACE_DEBUG("ReadBlk(%d,%d)\n\r", address, nbBlocks);
#if defined(SINGLE_READ)
    while(nbBlocks --) {
        error = PerformSingleTransfer(pSd, address, pData, 1);
        if (error)
            break;
        // SDHC
        if (pSd->totalSize == 0xFFFFFFFF) {
            address += 1;
            pData = &pData[512];
        }
        else {
            address += 1;
            pData = &pData[512];
        }
    }
    return error;
#endif
#if !defined(MCI2_INTERFACE)
  #if !defined(AT91C_MCI_RDPROOF)
    error = MoveToTransferState(pSd, address, nbBlocks, pData, 1);
    pSd->state = SD_STATE_READ;
  #else
    if((pSd->state == SD_STATE_READ)
        && ((pSd->preBlock + 1) == address)) {

      #if defined(at91rm9200)
        error = Cmd12(pSd, 0);
        if (error) {
            return error;
        }
      #else
        TRACE_DEBUG("SD_ReadBlock:ContinuousRead\n\r");
        error = ContinuousRead(pSd,
                               nbBlocks,
                               pData,
                               0, 0);
        pSd->preBlock = address + (nbBlocks-1);
      #endif
    }
    else {
        error = MoveToTransferState(pSd, address, nbBlocks, pData, 1);
        pSd->state = SD_STATE_READ;
    }
  #endif
#else
    if (   pSd->state != SD_STATE_READ
        || pSd->preBlock + 1 != address ) {
        // Start infinite block reading
        error = MoveToTransferState(pSd, address, 0, 0, 1);
    }
    if (!error) {
        pSd->state = SD_STATE_READ;
        error = ContinuousRead(pSd,
                               nbBlocks,
                               pData,
                               0, 0);
        if (!error) pSd->preBlock = address + (nbBlocks - 1);
    }
#endif
    return error;
}

//------------------------------------------------------------------------------
/// Write Block of data pointed by pData. The buffer size must be at
/// least 512 byte long. This function checks the SD card status register and
/// address the card if required before sending the read command.
/// Returns 0 if successful; otherwise returns an SD_ERROR code.
/// \param pSd  Pointer to a SD card driver instance.
/// \param address  Address of block to write.
/// \param nbBlocks Number of blocks to be read
/// \param pData    Data buffer whose size is at least the block size, it can
///            be 1,2 or 4-bytes aligned when used with DMA.
//------------------------------------------------------------------------------
unsigned char SD_WriteBlock(SdCard *pSd,
                            unsigned int address,
                            unsigned short nbBlocks,
                            const unsigned char *pData)
{
    unsigned char error = 0;

    SANITY_CHECK(pSd);
    SANITY_CHECK(pData);
    SANITY_CHECK(nbBlocks);

    TRACE_DEBUG("WriteBlk(%d,%d)\n\r", address, nbBlocks);

#if defined(SINGLE_WRITE)
    unsigned char *pB = (unsigned char*)pData;
    while(nbBlocks --) {
        error = PerformSingleTransfer(pSd, address, pB, 0);
        if (error)
            break;
        // SDHC
        if (pSd->totalSize == 0xFFFFFFFF) {
            address += 1;
            pB = &pB[512];
        }
        else {
            address += 1;
            pB = &pB[512];
        }
    }
    return error;
#endif
#if !defined(MCI2_INTERFACE)
  #if !defined(AT91C_MCI_WRPROOF)
    error = MoveToTransferState(pSd, address, nbBlocks,
                                (unsigned char *)pData, 0);
    pSd->state = SD_STATE_WRITE;
  #else
    if((pSd->state == SD_STATE_WRITE)
        && ((pSd->preBlock + 1) == address)) {

        TRACE_DEBUG("SD_WriteBlock:ContinuousWrite\n\r");
        error = ContinuousWrite(pSd,
                                nbBlocks,
                                pData,
                                0, 0);
        pSd->preBlock = address + (nbBlocks-1);
    }
    else {

        //TRACE_FATAL("SD_WriteBlock:MoveToTransferState\n\r");
        error = MoveToTransferState(pSd, address, nbBlocks,
                                    (unsigned char *)pData, 0);
        pSd->state = SD_STATE_WRITE;
    }
  #endif
#else
    if (   pSd->state != SD_STATE_WRITE
        || pSd->preBlock + 1 != address ) {
        // Start infinite block writing
        error = MoveToTransferState(pSd, address, 0, 0, 0);
    }
    if (!error) {
        pSd->state = SD_STATE_WRITE;
        error = ContinuousWrite(pSd,
                                nbBlocks,
                                pData,
                                0, 0);
        if (!error) pSd->preBlock = address + (nbBlocks - 1);
    }
#endif

    return error;
}

//------------------------------------------------------------------------------
/// Run the SDcard SD/MMC/SDIO Mode initialization sequence.
/// This function resets both IO and memory controller, runs the initialisation
/// procedure and the identification process. Then it leaves the card in ready
/// state. The following command must check the card type and continue to put
/// the card into tran(for memory card) or cmd(for io card) state for data
/// exchange.
/// Returns 0 if successful; otherwise returns an SD_ERROR code.
/// \param pSd  Pointer to a SD card driver instance.
//------------------------------------------------------------------------------
static unsigned char SdMmcIdentify(SdCard *pSd)
{
    unsigned char mem = 0, io = 0, f8 = 0, mp = 1, ccs = 0;
    unsigned char error = 0;
#if MCI_SDIO_ENABLE
    unsigned int  status;
#endif

    // Reset HC to default HS and BusMode
    MCI_EnableHsMode(pSd->pSdDriver, 0);
    MCI_SetBusWidth(pSd->pSdDriver, MCI_SDCBUS_1BIT);

#if MCI_SDIO_ENABLE
    // Reset SDIO
    // CMD52, write 1 to RES bit in the CCCR (bit 3 of register 6)
    status = (0x1 << 3);
    error = Cmd52(pSd, 0, 1, 0, 6, &status);
    if (!error && ((status & STATUS_SDIO_CMD52) == 0)) {}
    else if (error == MCI_STATUS_NORESPONSE) {}
    else {
        TRACE_DEBUG("SdMmcIdentify.Cmd52 fail: %d, %x\n\r", error, status);
    }
#endif

    // Reset MEM
    error = SwReset(pSd, 1);
    if (error) {
        TRACE_DEBUG("SdMmcIdentify.SwReset: %d\n\r", error)
    }

    // CMD8 is newly added in the Physical Layer Specification Version 2.00 to
    // support multiple voltage ranges and used to check whether the card
    // supports supplied voltage. The version 2.00 host shall issue CMD8 and
    // verify voltage before card initialization.
    // The host that does not support CMD8 shall supply high voltage range...
    error = Cmd8(pSd, 1, (void*)1);
    if (error == 0) {
        f8 = 1;
    }
    else if (error != SD_ERROR_NORESPONSE) {
        TRACE_ERROR("SdMmcIdentify.Cmd8: %d\n\r", error);
        return SD_ERROR_DRIVER;
    }
    else {
        // Delay after "no response"
        Delay(800);
    }

#if MCI_SDIO_ENABLE
    // CMD5 is added for SDIO OCR check
    status = 0;
    error = Cmd5(pSd, &status);
    if (error) {
        TRACE_WARNING("SdMmcIdentify.Cmd5: %d\n\r", error);
    }
    // SDIO or SD COMBO: FN > 0
    else if ((status & AT91C_SDIO_NF) > 0) {
        // Set New Voltage
        unsigned int   cmd5Retries = 10000;
        do {
            status &= AT91C_MMC_HOST_VOLTAGE_RANGE;
            error = Cmd5(pSd, &status);
            if (status & AT91C_CARD_POWER_UP_BUSY)
                break;
        } while(!error && cmd5Retries --);
        if (error) {
            TRACE_ERROR("SdMmcIdentify.Cmd5 V: %d\n\r", error);
            return SD_ERROR_DRIVER;
        }
        TRACE_INFO("SDIO\n\r");
        io = 1;
        // SDIO only?
        if ((status & AT91C_SDIO_MP) == 0) mp = 0;
    }
#endif
    // SD or MMC or COMBO: mp is 1
    if (mp) {
        // Try SD memory initialize
        error = Acmd41(pSd, f8, &ccs);
        if (error) {
            unsigned int   cmd1Retries = 10000;
            TRACE_DEBUG("SdMmcIdentify.Acmd41: %d, try MMC\n\r", error);

            // Try MMC initialize
            error = SwReset(pSd, 10);
            if (error) {
                TRACE_ERROR("SdMmcIdentify.Mmc.SwReset: %d\n\r", error);
                return SD_ERROR_DRIVER;
            }
            // - Set Voltage
            do {
                error = Cmd1(pSd, 1, &ccs);
            }
            while ((error) && (cmd1Retries-- > 0));
            if (error) {
                TRACE_ERROR("SdMmcIdentify.Cmd1: %d\n\r", error);
                return SD_ERROR_DRIVER;
            }
            else if (ccs) {
                pSd->cardType = CARD_MMCHD;
            }
            else {
                pSd->cardType = CARD_MMC;
            }

            // MMC Identified OK
            return 0;
        }
        else if (ccs) {
            TRACE_INFO("SDHC MEM\n\r");
        }
        else {
            TRACE_INFO("SD MEM\n\r");
        }
        mem = 1;
    }

    // SD(IO)+MEM ?
    if (!mem) {
        // SDIO only
        if (io) {
            pSd->cardType = CARD_SDIO;
            return 0;
        }
    }
    // SD COMBO, continue with memory initialize
    else if (io) {
        if (ccs) pSd->cardType = CARD_SDHCCOMBO;
        else     pSd->cardType = CARD_SDCOMBO;
    }
    // SD(HC), continue with memory initialize
    else {
        if (ccs) pSd->cardType = CARD_SDHC;
        else     pSd->cardType = CARD_SD;
    }
    return 0;
}

//------------------------------------------------------------------------------
/// Run the SDcard SD Mode enumeration sequence. This function runs after the
/// initialisation procedure and the identification process. It sets the
/// SD card in transfer state to set the block length and the bus width.
/// Returns 0 if successful; otherwise returns an SD_ERROR code.
/// \param pSd  Pointer to a SD card driver instance.
//------------------------------------------------------------------------------
static unsigned char SdMmcEnum(SdCard *pSd)
{
    unsigned char mem = 0, io = 0;
    unsigned int   status;
    unsigned short error;
    unsigned char  isHsSupport = 0;
    unsigned char  updateInformation = 0;

    if (pSd->cardType & CARD_TYPE_bmSDMMC) mem = 1;
    if (pSd->cardType & CARD_TYPE_bmSDIO)  io = 1;

    // For MEM
    // The host then issues the command ALL_SEND_CID (CMD2) to the card to get
    // its unique card identification (CID) number.
    // Card that is unidentified (i.e. which is in Ready State) sends its CID
    // number as the response (on the CMD line).
    if (mem) {
        error = Cmd2(pSd);
        if (error) {
            TRACE_ERROR("SdMmcEnum.Cmd2: %d\n\r", error);
            return SD_ERROR_DRIVER;
        }
    }

    // For SDIO & MEM
    // Thereafter, the host issues CMD3 (SEND_RELATIVE_ADDR) asks the
    // card to publish a new relative card address (RCA), which is shorter than
    // CID and which is used to address the card in the future data transfer
    // mode. Once the RCA is received the card state changes to the Stand-by
    // State. At this point, if the host wants to assign another RCA number, it
    // can ask the card to publish a new number by sending another CMD3 command
    // to the card. The last published RCA is the actual RCA number of the card.
    error = Cmd3(pSd);
    if (error) {
        TRACE_ERROR("SdMmcInit.Cmd3 %d\n\r", error);
        return SD_ERROR_DRIVER;
    }

    // For MEM
    // SEND_CSD (CMD9) to obtain the Card Specific Data (CSD register),
    // e.g. block length, card storage capacity, etc...
    if (mem) {
        error = Cmd9(pSd);
        if (error) {
            TRACE_ERROR("SdMmcInit.Cmd9 %d\n\r", error);
            return SD_ERROR_DRIVER;
        }
    }

    // For SDIO & MEM
    // Now select the card, to TRAN state
    error = MmcSelectCard(pSd, pSd->cardAddress, 0);
    if (error) {
        TRACE_ERROR("SdMmcInit.Sel %d\n\r", error);
        return SD_ERROR_DRIVER;
    }
    // SDIO only card, enumeration done
    if (!mem && io) {
        // Default tranSpeed: 25MHz
        pSd->transSpeed = 25000000;
        return 0;
    }

    // For MEM cards or combo
    // If the card support EXT_CSD, read it!
    TRACE_INFO("Card Type %d, CSD_STRUCTURE %d\n\r",
               pSd->cardType, SD_CSD_STRUCTURE(pSd));

    // Get extended information of the card
    SdMmcUpdateInformation(pSd, 0, 0);

    // Advanced settings for HD & HS card
    if (pSd->cardType >= CARD_MMC){

        MmcCmd6Arg cmd6Arg;

        // MMC4 or later
        if (SD_CSD_SPEC_VERS(pSd) >= 4) {

            unsigned char busWidth, widthMode;

            // Calculate MMC busWidth (limited by slot information)
            switch (pSd->pSdDriver->mciMode & AT91C_MCI_SCDBUS) {
              #if defined(AT91C_MCI_SCDBUS_8BITS)
                case AT91C_MCI_SCDBUS_8BITS:
                    busWidth = 8;
                    widthMode = MCI_SDCBUS_8BIT;
                    break;
              #endif

              #if defined(AT91C_MCI_SCDBUS_4BITS)
                case AT91C_MCI_SCDBUS_4BITS:
                    busWidth = 4;
                    widthMode = MCI_SDCBUS_4BIT;
                    break;
              #endif

                default:
                    busWidth = 1;
                    widthMode = MCI_SDCBUS_1BIT;
            }

            // Switch to max bus width (4 now)
            cmd6Arg.access = 0x1;
            cmd6Arg.index  = SD_EXTCSD_BUS_WIDTH_INDEX;
            cmd6Arg.value  = SD_EXTCSD_BUS_WIDTH_4BIT;
            cmd6Arg.cmdSet = 0;
            error = Cmd6(pSd, &cmd6Arg, 0, &status);
            if (!error) {
                
              TRACE_WARNING_WP("-I- MMC %d-BIT BUS\n\r", busWidth);
              if (status
                  & (STATUS_MMC_SWITCH
                     & ~(STATUS_STATE | STATUS_READY_FOR_DATA))) {
                  printf("-E- Status %x\n\r", status);
              }
              else {
                  MCI_SetBusWidth(pSd->pSdDriver, widthMode);
                  updateInformation = 1;
              }
            }
            else {
                TRACE_WARNING("MMC %d-BIT not supported\n\r", busWidth)
            }
        }
        
        // CARD_TYPE 3
        if (SD_CSD_STRUCTURE(pSd) >= 2
            && (SD_EXTCSD_CARD_TYPE(pSd) & 0x2)) {

            #if !defined(OP_BOOTSTRAP_MCI_on)
            // Switch to HS mode
            if (gSdmmcAutoHsEnable) {
                cmd6Arg.access = 0x3;
                cmd6Arg.index  = SD_EXTCSD_HS_TIMING_INDEX;
                cmd6Arg.value  = SD_EXTCSD_HS_TIMING_ENABLE;
                cmd6Arg.cmdSet = 0;
                error = Cmd6(pSd, &cmd6Arg, 0, &status);
                if (error
                    || (status
                        & (STATUS_MMC_SWITCH
                            & ~(STATUS_STATE | STATUS_READY_FOR_DATA)))) {
                    TRACE_WARNING("MMC HS Fail, st %x\n\r", status);
                }
                else {
                    MCI_EnableHsMode(pSd->pSdDriver, 1);
                    TRACE_WARNING_WP("-I- MMC HS Enabled\n\r");
                    isHsSupport = 1;
                    updateInformation = 1;
                }
            }
            #endif // end of OP_BOOTSTRAP_MCI_on
        }
    }
    else if (pSd->cardType >= CARD_SD) {
      #if 1
        // Switch to 4-bits bus width
        // (All SD Card shall support 1-bit, 4 bitswidth)
        error = Acmd6(pSd, 4);
        TRACE_WARNING_WP("-I- SD 4-BITS BUS\n\r");
        if (error) {
            TRACE_ERROR("SdMmcInit.12 (%d)\n\r", error);
            return error;
        }
        MCI_SetBusWidth(pSd->pSdDriver, MCI_SDCBUS_4BIT);

        #if !defined(OP_BOOTSTRAP_MCI_on)
        // SD Spec V1.10 or higher, switch to high-speed mode
        if (gSdmmcAutoHsEnable) {
            if (SD_SCR_SD_SPEC(pSd) >= SD_SCR_SD_SPEC_1_10) {
                SdCmd6Arg cmd6Arg;
                unsigned int switchStatus[512/32];
                cmd6Arg.mode = 1;
                cmd6Arg.reserved = 0;
                cmd6Arg.reserveFG6 = 0xF;
                cmd6Arg.reserveFG5 = 0xF;
                cmd6Arg.reserveFG4 = 0xF;
                cmd6Arg.reserveFG3 = 0xF;
                cmd6Arg.command = 0;
                cmd6Arg.accessMode = 1;
                error = Cmd6(pSd,
                             &cmd6Arg,
                             switchStatus,
                             &status);
              #if 0
                unsigned int i;
                printf("SD Switch status:");
                for(i = 0; i < 512 / 8; i ++) {
                    if ((i % 8) == 0) printf("\n\r[%3d]", i);
                    printf(" %02x", ((char*)switchStatus)[i]);
                }
                printf("\n\r");
                printf(" _FG1_INFO %x\n\r",
                    SD_SW_STAT_FUN_GRP1_INFO(switchStatus));
                printf(" _FG1_RC   %x\n\r",
                    SD_SW_STAT_FUN_GRP1_RC(switchStatus));
                printf(" _FG1_BUSY %x\n\r",
                    SD_SW_STAT_FUN_GRP1_BUSY(switchStatus));
                printf(" _FG1_DS_V %x\n\r",
                    SD_SW_STAT_DATA_STRUCT_VER(switchStatus));
              #endif
                if (error || (status & STATUS_SWITCH_ERROR)) {
                    TRACE_WARNING("SD HS Fail\n\r");
                }
                else if (SD_SW_STAT_FUN_GRP1_RC(switchStatus)
                                == SD_SW_STAT_FUN_GRP_RC_ERROR) {
                    TRACE_ERROR_WP("-I- SD HS Not Supported\n\r");
                }
                else if (SD_SW_STAT_FUN_GRP1_BUSY(switchStatus)) {
                    TRACE_WARNING("SD HS Busy\n\r")
                }
                else {
                    MCI_EnableHsMode(pSd->pSdDriver, 1);
                    TRACE_WARNING_WP("-I- SD HS Enable\n\r");
                    isHsSupport = 1;
                }
            }
        }
        #endif
        // Update
        updateInformation = 1;
      #endif
    }

    if (updateInformation) {

        SdMmcUpdateInformation(pSd, isHsSupport, 1);
    }
    return 0;
}

//------------------------------------------------------------------------------
/// Run the SDcard initialization sequence. This function runs the
/// initialisation procedure and the identification process, then it sets the
/// SD card in transfer state to set the block length and the bus width.
/// Returns 0 if successful; otherwise returns an SD_ERROR code.
/// \param pSd  Pointer to a SD card driver instance.
/// \param pSdDriver  Pointer to SD driver already initialized.
//------------------------------------------------------------------------------
unsigned char SD_Init(SdCard *pSd, SdDriver *pSdDriver)
{
    unsigned char error;

    //TRACE_DEBUG("SD_Init()\n\r");

    // Initialize SdCard structure
    pSd->pSdDriver = pSdDriver;
    pSd->cardAddress = 0;
    pSd->preBlock = 0xffffffff;
    pSd->state = SD_STATE_INIT;
    pSd->cardType = CARD_UNKNOWN;
    pSd->optCmdBitMap = 0xFFFFFFFF;
    pSd->mode = 0;
    ResetCommand(&pSd->command);

    // Initialization delay: The maximum of 1 msec, 74 clock cycles and supply
    // ramp up time. Supply ramp up time provides the time that the power is
    // built up to the operating level (the bus master supply voltage) and the
    // time to wait until the SD card can accept the first command.

    // Power On Init Special Command
    //TRACE_DEBUG("Pon()\n\r");
    error = Pon(pSd);
    if (error) {
        TRACE_ERROR("SD_Init.1 (%d)\n\r", error);
        return error;
    }
    // After power-on or CMD0, all cards?CMD lines are in input mode, waiting
    // for start bit of the next command.
    // The cards are initialized with a default relative card address
    // (RCA=0x0000) and with a default driver stage register setting
    // (lowest speed, highest driving current capability).
    error = SdMmcIdentify(pSd);
    if (error) {
        TRACE_ERROR("SD_Init.Identify\n\r");
        return error;
    }
    error = SdMmcEnum(pSd);
    if (error) {
        TRACE_ERROR("SD_Init.Enum\n\r");
        return error;
    }

    // In the case of a Standard Capacity SD Memory Card, this command sets the
    // block length (in bytes) for all following block commands
    // (read, write, lock).
    // Default block length is fixed to 512 Bytes.
    // Set length is valid for memory access commands only if partial block read
    // operation are allowed in CSD.
    // In the case of a High Capacity SD Memory Card, block length set by CMD16
    // command does not affect the memory read and write commands. Always 512
    // Bytes fixed block length is used. This command is effective for
    // LOCK_UNLOCK command.
    // In both cases, if block length is set larger than 512Bytes, the card sets
    // the BLOCK_LEN_ERROR bit.
    if (pSd->cardType == CARD_SD) {
        error = Cmd16(pSd, SD_BLOCK_SIZE);
        if (error) {
            pSd->optCmdBitMap &= ~SD_CMD16_SUPPORT;
            TRACE_INFO("SD_Init.Cmd16 (%d)\n\r", error);
            TRACE_INFO("Fail to set BLK_LEN, default is 512\n\r");
        }
    }

    // Reset status for R/W
    pSd->state = SD_STATE_READY;

    // If SDIO Card
    if (pSd->cardType == CARD_SDIO) {
        pSd->blockNr = 0;
        pSd->totalSize = 0;
    }
    // If MMC Card & get size from EXT_CSD
    else if (pSd->cardType >= CARD_MMC && SD_CSD_C_SIZE(pSd) == 0xFFF) {
        pSd->blockNr = SD_EXTCSD_BLOCKNR(pSd);
        // Block number less than 0x100000000/512
        if (pSd->blockNr > 0x800000)
            pSd->totalSize = 0xFFFFFFFF;
        else
            pSd->totalSize = SD_EXTCSD_TOTAL_SIZE(pSd);
    }
    // If SD CSD v2.0
    else if(pSd->cardType >= CARD_SD
            && pSd->cardType < CARD_MMC
            && SD_CSD_STRUCTURE(pSd) >= 1) {
        pSd->blockNr   = SD_CSD_BLOCKNR_HC(pSd);
        pSd->totalSize = 0xFFFFFFFF;
    }
    // Normal card
    else {
        pSd->totalSize = SD_CSD_TOTAL_SIZE(pSd);
        pSd->blockNr = SD_CSD_BLOCKNR(pSd);
    }

    if (pSd->cardType == CARD_UNKNOWN) {
        return SD_ERROR_NOT_INITIALIZED;
    }
    else {
        return 0;
    }
}

//------------------------------------------------------------------------------
/// Stop the SDcard. This function stops all SD operations.
/// Returns 0 if successful; otherwise returns an SD_ERROR code.
/// \param pSd  Pointer to a SD card driver instance.
/// \param pSdDriver  Pointer to MCI driver already initialized.
//------------------------------------------------------------------------------
unsigned char SD_Stop(SdCard *pSd, SdDriver *pSdDriver)
{
    unsigned char error;
    SdCmd *pCommand = &(pSd->command);

    if (pSd == 0 || pSdDriver == 0)
        return 0;

    if(pCommand->tranType == MCI_CONTINUE_TRANSFER)
    {
        TRACE_DEBUG("SD_StopTransmission()\n\r");

        error = Cmd12(pSd, (pSd->state != SD_STATE_WRITE), 0);
        if(error) {
            return error;
        }
    }

    MCI_Close((Mci *)pSdDriver);
    return 0;
}

//------------------------------------------------------------------------------
/// Switch the SD/MMC card to High-Speed mode.
/// pSd->transSpeed will change to new speed limit.
/// Invoke MCI_SetSpeed() and MCI_EnableHsMode() to change MCI timing after.
/// For SD/MMC card, the speed mode will not change back until another init.
/// \param pSd      Pointer to a SD card driver instance.
/// \param hsMode   1 to enable HS mode, 0 to disable
///                 0xFF to return current mode.
/// \return current mode is hsMode is 0xFF;
///         error code if hsMode is 0 or 1.
//------------------------------------------------------------------------------
unsigned char SD_HighSpeedMode(SdCard *pSd,
                               unsigned char hsMode)
{
    unsigned char error = 0;

    if (hsMode == 0xFF)
        return pSd->mode;
    if (hsMode == 0) {
        TRACE_WARNING("Can not switch, do re-init to disable HS mode\n\r");
        return SD_ERROR_DRIVER;
    }

    // Quit transfer state
    error = MoveToTranState(pSd);
    if (error) {
        TRACE_ERROR("SD_HighSpeedMode.Tran: %d\n\r", error);
        return error;
    }

    if (pSd->mode != hsMode) {
        error = SdMmcSwitchHsMode(pSd, hsMode);
        if (error == 0)
            error = SdMmcUpdateInformation(pSd, 1, 1);
    }
    // Reset state for data R/W
    pSd->state = SD_STATE_READY;

    return error;
}

unsigned char SD_BusWidth(SdCard *pSd,
                          unsigned char busWidth)
{
    return 0;
}

#if defined(MCI2_INTERFACE) && defined(AT91C_MCI_SPCMD_BOOTREQ)
//------------------------------------------------------------------------------
/// Read Block of data in a buffer pointed by pData. The buffer size must be at
/// least 512 byte long. This function checks the SD card status register and
/// address the card if required before sending the read command.
/// Returns 0 if successful; otherwise returns an code describing the error.
/// \param pSd  Pointer to a SD card driver instance.
/// \param address  Address of the block to read.
/// \param nbBlocks Number of blocks to be read.
/// \param pData  Data buffer whose size is at least the block size.
//------------------------------------------------------------------------------
unsigned char MMC_BootRead(SdCard *pSd,
                           unsigned int   nbBlocks,
                           unsigned char *pData)
{
    unsigned char error;
    unsigned char bootAck  = 0;
    unsigned char busWidth = MCI_SDCBUS_4BIT;

    SANITY_CHECK(pSd);

    if (pSd->state != SD_STATE_BOOT)
        return SD_ERROR_DRIVER;

  #if 0
    switch(SD_EXTCSD_BOOT_BUS_WIDTH(pSd)) {
        case SD_EXTCSD_BOOT_BUS_1BIT:
            busWidth = MCI_SDCBUS_1BIT;
            break;
        case SD_EXTCSD_BOOT_BUS_8BIT:
            busWidth = MCI_SDCBUS_8BIT;
            break;
    }

    if (SD_EXTCSD_BOOT_CONFIG(pSd) & SD_EXTCSD_BOOT_PARTITION_ACK)
        bootAck = 1;
  #endif

    MCI_SetBusWidth((Mci*)pSd->pSdDriver, busWidth);
    error = BootREQ(pSd, pData, nbBlocks, bootAck);
    pSd->state = SD_STATE_BOOT;

    return error;
}

//------------------------------------------------------------------------------
/// In boot operation mode, the master can read boot data from the slave.
/// By keeping CMD line low after power-on
/// \param pSd  Pointer to a SD card driver instance.
//------------------------------------------------------------------------------
unsigned char MMC_BootInit(SdCard *pSd)
{
    unsigned char error = 0;

    SANITY_CHECK(pSd);

    error = PonBoot(pSd);

    if (!error) {

        //error = BootREQ(pSd, 0, 0, 0);

        if (!error)
            pSd->state = SD_STATE_BOOT;
        else {
            TRACE_ERROR("MMC_BootInit.BootREQ: %d\n\r", error);
        }
    }
    else {
        TRACE_ERROR("MMC_BootInit.PonBoot: %d\n\r", error);
    }

    return error;
}

//------------------------------------------------------------------------------
/// In boot operation mode, the master can read boot data from the slave.
/// By sending CMD0 with argument + 0xFFFFFFFA
/// \param pSd  Pointer to a SD card driver instance.
//------------------------------------------------------------------------------
unsigned char MMC_BootStart(SdCard *pSd)
{
    unsigned char error;

    SANITY_CHECK(pSd);

    if (pSd->state == SD_STATE_BOOT)
        return 0;

    if (pSd->cardType >= CARD_MMC
        && SD_CSD_STRUCTURE(pSd) >= 2
        && SD_CID_BGA(pSd) == 1
        && SD_EXTCSD_BOOT_INFO(pSd) == 1) {}
    else
        return SD_ERROR_NOT_SUPPORT;

    error = Cmd0(pSd, 0xFFFFFFFA);
    pSd->state = SD_STATE_BOOT;

    return 0;
}

//------------------------------------------------------------------------------
/// Terminate the boot operation mode
/// \param pSd  Pointer to a SD card driver instance.
//------------------------------------------------------------------------------
unsigned char MMC_BootStop(SdCard *pSd)
{
    unsigned char error;

    SANITY_CHECK(pSd);

    if (pSd->state != SD_STATE_BOOT)
        return 0;

    error = BootEnd(pSd);

    if(!error)
        pSd->state = SD_STATE_IDLE;

    return error;
}

//------------------------------------------------------------------------------
/// Setup Boot Settings
/// \param resetBus Wether bus width is reset to 1-bit after quit boot mode.
/// \param busWidth The bus width in boot operation.
/// \param bootPart The partition used for boot operation.
/// \param accPart  The partition to access with normal read/write.
/// \param bootAck  Enable boot acknoledge.
/// \return 0 or error code.
//------------------------------------------------------------------------------
unsigned char MMC_SetupBootMode(SdCard *pSd,
                                unsigned char resetBus,
                                unsigned char busWidth,
                                unsigned char bootPart,
                                unsigned char accPart,
                                unsigned char bootAck)
{
    unsigned int   status;
    unsigned short error;
    const MmcCmd6Arg bootArgs[] = {
        // BOOT_CONFIG
        {3, 179, (bootAck << 6)|(bootPart << 3)|(accPart << 0), 0},
        // BOOT_BUS_WIDTH
        {3, 177, (busWidth << 2)|(resetBus << 0), 0}
    };

    SANITY_CHECK(pSd);
    if (    pSd->cardType >= CARD_MMC
        &&  SD_CSD_STRUCTURE(pSd) >= 2
        &&  SD_CID_CBS(pSd) == 1) {}
    else return SD_ERROR_NOT_SUPPORT;
    //if (MMC_GetBootSizeKB(pSd) == 0) return SD_ERROR_NOT_SUPPORT;

    // Quit transfer state
    error = MoveToTranState(pSd);
    if (error) {
        TRACE_ERROR("MMC_SetupBootMode.Tran: %d\n\r", error);
        return error;
    }

    // Setup all boot informations
    error = MmcSwitchSettings(pSd,
                              bootArgs,
                              sizeof(bootArgs)/sizeof(MmcCmd6Arg),
                              &status);
    if (error) {
        TRACE_ERROR("MMC_SetupBootMode.Cmd6: 0x%x, %x\n\r", error, status);
        return (unsigned char)error;
    }

    // Update the EXT_CSD
  #if 1
    error = Cmd8(pSd, 0, pSd->extData);
    if (error) {
        TRACE_ERROR("MMC_SetupBootMode.Cmd8 (%d)\n\r", error);
    }

   #if 0
    if (   SD_EXTCSD_BOOT_BUS_WIDTH(pSd) != bootArgs[0].value
        || SD_EXTCSD_BOOT_CONFIG(pSd) != bootArgs[1].value ) {

        TRACE_ERROR("MMC_SetupBootMode: ExtCSD not changed\n\r");

      #if 1
        Cmd13(pSd, &status);
        TRACE_INFO("  CARD status: 0x%x\n\r", status);
      #endif
        return SD_ERROR_DRIVER;
    }
   #endif
  #endif

    // Reset state for data R/W
    pSd->state = SD_STATE_READY;

    return 0;
}

//------------------------------------------------------------------------------
/// \return 0 or error code.
//------------------------------------------------------------------------------
unsigned char MMC_StopBootMode()
{
    return 0;
}
#endif


//------------------------------------------------------------------------------
/// \return size of the card in KB
//------------------------------------------------------------------------------
unsigned int MMC_GetTotalSizeKB(SdCard *pSd)
{
    SANITY_CHECK(pSd);

    if (pSd->totalSize == 0xFFFFFFFF) {

        return pSd->blockNr / 2;
    }
    
    return pSd->totalSize / 1024;
}


//------------------------------------------------------------------------------
/// \return size of boot area if the card support boot operation.
//------------------------------------------------------------------------------
unsigned int MMC_GetBootSizeKB(SdCard *pSd)
{
    SANITY_CHECK(pSd);
    if (   pSd->cardType >= CARD_MMC
        && SD_CSD_STRUCTURE(pSd) >= 2) {

        return SD_EXTCSD_BOOT_SIZE_MULTI(pSd) * 128;
    }
    return 0;
}

#if MCI_SDIO_ENABLE
//------------------------------------------------------------------------------
/// Display the content of the CCCR
//------------------------------------------------------------------------------
void SDIO_DisplayCardInformation(SdCard *pSd)
{
    unsigned int  tmp = 0, addrCIS = 0, addrManfID = 0, addrFunc0 = 0;
    unsigned char* p = (unsigned char*)&tmp;
    unsigned char  buf[8];

    switch(pSd->cardType) {
        case CARD_SDIO:
            TRACE_INFO("** SDIO ONLY card\n\r");
            break;
        case CARD_SDCOMBO:
        case CARD_SDHCCOMBO:
            TRACE_INFO("** SDIO Combo card\n\r");
            break;
        default:
            TRACE_INFO("** NO SDIO, CCCR not supported\n\r");
            return;
    }
    // CCCR
    TRACE_INFO("====== CCCR ======\n\r");
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_CCCR_REG, p, 1);
    TRACE_INFO(".SDIO       %02X\n\r", (tmp & SDIO_SDIO) >> 4);
    TRACE_INFO(".CCCR       %02X\n\r", (tmp & SDIO_CCCR) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_SD_REV_REG, p, 1);
    TRACE_INFO(".SD         %02X\n\r", (tmp & SDIO_SD) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_IOE_REG, p, 1);
    TRACE_INFO(".IOE        %02X\n\r", (tmp & SDIO_IOE) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_IOR_REG, p, 1);
    TRACE_INFO(".IOR        %02X\n\r", (tmp & SDIO_IOR) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_IEN_REG, p, 1);
    TRACE_INFO(".IEN        %02X\n\r", (tmp & SDIO_IEN) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_INT_REG, p, 1);
    TRACE_INFO(".INT        %02X\n\r", (tmp & SDIO_INT) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_BUS_CTRL_REG, p, 1);
    TRACE_INFO(".CD         %x\n\r", (tmp & SDIO_CD) >> 7);
    TRACE_INFO(".SCSI       %x\n\r", (tmp & SDIO_SCSI) >> 6);
    TRACE_INFO(".ECSI       %x\n\r", (tmp & SDIO_ECSI) >> 5);
    TRACE_INFO(".BUS_WIDTH  %x\n\r", (tmp & SDIO_BUSWIDTH) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_CAP_REG, p, 1);
    TRACE_INFO(".4BLS       %x\n\r", (tmp & SDIO_4BLS) >> 7);
    TRACE_INFO(".LSC        %x\n\r", (tmp & SDIO_LSC) >> 6);
    TRACE_INFO(".E4MI       %x\n\r", (tmp & SDIO_E4MI) >> 5);
    TRACE_INFO(".S4MI       %x\n\r", (tmp & SDIO_S4MI) >> 4);
    TRACE_INFO(".SBS        %x\n\r", (tmp & SDIO_SBS) >> 3);
    TRACE_INFO(".SRW        %x\n\r", (tmp & SDIO_SRW) >> 2);
    TRACE_INFO(".SMB        %x\n\r", (tmp & SDIO_SMB) >> 1);
    TRACE_INFO(".SDC        %x\n\r", (tmp & SDIO_SDC) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_CIS_PTR_REG, p, 3);
    TRACE_INFO(".CIS_PTR    %06X\n\r", tmp);
    addrCIS = tmp; tmp = 0;
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_BUS_SUSP_REG, p, 1);
    TRACE_INFO(".BR         %x\n\r", (tmp & SDIO_BR) >> 1);
    TRACE_INFO(".BS         %x\n\r", (tmp & SDIO_BS) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_FUN_SEL_REG, p, 1);
    TRACE_INFO(".DF         %x\n\r", (tmp & SDIO_DF) >> 7);
    TRACE_INFO(".FS         %x\n\r", (tmp & SDIO_FS) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_EXEC_REG, p, 1);
    TRACE_INFO(".EX         %x\n\r", (tmp & SDIO_EX));
    TRACE_INFO(".EXM        %x\n\r", (tmp & SDIO_EXM) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_READY_REG, p, 1);
    TRACE_INFO(".RF         %x\n\r", (tmp & SDIO_RF));
    TRACE_INFO(".RFM        %x\n\r", (tmp & SDIO_RFM) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_FN0_BLKSIZ_REG, p, 2);
    TRACE_INFO(".FN0_SIZE   %d(%04X)\n\r", tmp, tmp);
    tmp = 0;
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_POWER_REG, p, 1);
    TRACE_INFO(".EMPC       %x\n\r", (tmp & SDIO_EMPC) >> 1);
    TRACE_INFO(".SMPC       %x\n\r", (tmp & SDIO_SMPC) >> 0);
    SDIO_ReadDirect(pSd, SDIO_CIA, SDIO_HS_REG, p, 1);
    TRACE_INFO(".EHS        %x\n\r", (tmp & SDIO_EHS) >> 1);
    TRACE_INFO(".SHS        %x\n\r", (tmp & SDIO_SHS) >> 0);
    // Metaformat
    SdioFindTuples(pSd, addrCIS, 128, &addrManfID, &addrFunc0);
    if (addrManfID != 0) {
        SDIO_ReadDirect(pSd, SDIO_CIA, addrManfID, buf, 6);
        TRACE_INFO("==== CISTPL_MANFID ====\n\r");
        TRACE_INFO("._MANF %04X\n\r", buf[2] + (buf[3] << 8));
        TRACE_INFO("._CARD %04X\n\r", buf[4] + (buf[5] << 8));
    }
    if (addrFunc0 != 0) {
        SDIO_ReadDirect(pSd, SDIO_CIA, addrFunc0, buf, 6);
        TRACE_INFO("== CISTPL_FUNCE Fun0 ==\n\r");
        TRACE_INFO("._FN0_BLK_SIZE   %d(0x%04X)\n\r",
            buf[3] + (buf[4] << 8), buf[3] + (buf[4] << 8));
        TRACE_INFO("._MAX_TRAN_SPEED %02X\n\r", buf[5]);
    }
}
#endif

//------------------------------------------------------------------------------
/// Display the content of the CID register
/// \param pCid  Pointer to the Cid register value
//------------------------------------------------------------------------------
void SD_DisplayRegisterCID(SdCard *pSd)
{
    // CID for memory card only
    if (pSd->cardType == CARD_UNKNOWN || pSd->cardType >= CARD_SDIO)
        return;

    TRACE_INFO("======= CID =======\n\r");
  #if 0
    TRACE_INFO(" .Card/BGA         %X\n\r", SD_CID_BGA(pSd));
  #else
    TRACE_INFO("CID MID Manufacturer ID       %02X\n\r",
        SD_CID_MID(pSd));
    
    TRACE_INFO("CID OID OEM/Application ID    %c%c\n\r",
        (char)SD_CID_OID_BYTE_1(pSd),
        (char)SD_CID_OID_BYTE_0(pSd));
    
    TRACE_INFO("CID PNM Product revision      %c%c%c%c%c\n\r",
        (char)SD_CID_PNM_BYTE_4(pSd),
        (char)SD_CID_PNM_BYTE_3(pSd),
        (char)SD_CID_PNM_BYTE_2(pSd),
        (char)SD_CID_PNM_BYTE_1(pSd),
        (char)SD_CID_PNM_BYTE_0(pSd));
    
    TRACE_INFO("CID PRV Product serial number %02X%04X\n\r", 
         SD_CID_PRV_2(pSd),
         SD_CID_PRV_1(pSd));

    TRACE_INFO("CID MDT Manufacturing date    %04d/%02d\n\r",
        (unsigned short)SD_CID_MDT_YEAR(pSd),
        (unsigned char)SD_CID_MDT_MONTH(pSd));               
    
    TRACE_INFO("CID CRC checksum              %02X\n\r",   
         SD_CID_CRC(pSd));
  #endif
}

//------------------------------------------------------------------------------
/// Display the content of the CSD register
/// \param pSd  
//------------------------------------------------------------------------------
void SD_DisplayRegisterCSD(SdCard *pSd)
{ 
    // CID for memory card only
    if (pSd->cardType == CARD_UNKNOWN || pSd->cardType >= CARD_SDIO)
        return;

    TRACE_INFO("======== CSD ========");
  #if 0
  {
    unsigned int i;
    unsigned char *p = (unsigned char *)pSd->csd;
    for(i = 0; i < 128 / 8; i++) {
        if ((i % 16) == 0) TRACE_INFO_WP("\n\r [%3d]:", i);
        TRACE_INFO_WP(" %2x", p[i]);
    }
    TRACE_INFO_WP("\n\r");
    TRACE_INFO("------------------------\n\r");
  }
  #else
    TRACE_INFO_WP("\n\r");
  #endif
    TRACE_INFO(" .CSD_STRUCTURE      0x%x\r\n", SD_CSD_STRUCTURE(pSd));
    TRACE_INFO(" .SPEC_VERS          0x%x\r\n", SD_CSD_SPEC_VERS(pSd));
    TRACE_INFO(" .TAAC               0x%X\r\n", SD_CSD_TAAC(pSd)              );
    TRACE_INFO(" .NSAC               0x%X\r\n", SD_CSD_NSAC(pSd)              );
    TRACE_INFO(" .TRAN_SPEED         0x%X\r\n", SD_CSD_TRAN_SPEED(pSd)        );
    TRACE_INFO(" .CCC                0x%X\r\n", SD_CSD_CCC(pSd)               );
    TRACE_INFO(" .READ_BL_LEN        0x%X\r\n", SD_CSD_READ_BL_LEN(pSd)       );
    TRACE_INFO(" .READ_BL_PARTIAL    0x%X\r\n", SD_CSD_READ_BL_PARTIAL(pSd)   );
    TRACE_INFO(" .WRITE_BLK_MISALIGN 0x%X\r\n", SD_CSD_WRITE_BLK_MISALIGN(pSd));
    TRACE_INFO(" .READ_BLK_MISALIGN  0x%X\r\n", SD_CSD_READ_BLK_MISALIGN(pSd) );
    TRACE_INFO(" .DSR_IMP            0x%X\r\n", SD_CSD_DSR_IMP(pSd)           );
    TRACE_INFO(" .C_SIZE             0x%X\r\n", SD_CSD_C_SIZE(pSd)            );
    TRACE_INFO(" .C_SIZE_HC          0x%X\r\n", SD_CSD_C_SIZE_HC(pSd)         );
    TRACE_INFO(" .VDD_R_CURR_MIN     0x%X\r\n", SD_CSD_VDD_R_CURR_MIN(pSd)    );
    TRACE_INFO(" .VDD_R_CURR_MAX     0x%X\r\n", SD_CSD_VDD_R_CURR_MAX(pSd)    );
    TRACE_INFO(" .VDD_W_CURR_MIN     0x%X\r\n", SD_CSD_VDD_W_CURR_MIN(pSd)    );
    TRACE_INFO(" .VDD_W_CURR_MAX     0x%X\r\n", SD_CSD_VDD_W_CURR_MAX(pSd)    );
    TRACE_INFO(" .C_SIZE_MULT        0x%X\r\n", SD_CSD_C_SIZE_MULT(pSd)       );
    TRACE_INFO(" .ERASE_BLK_EN       0x%X\r\n", SD_CSD_ERASE_BLK_EN(pSd)      );
    TRACE_INFO(" .SECTOR_SIZE        0x%X\r\n", SD_CSD_SECTOR_SIZE(pSd)       );
    TRACE_INFO(" .WP_GRP_SIZE        0x%X\r\n", SD_CSD_WP_GRP_SIZE(pSd)       );
    TRACE_INFO(" .WP_GRP_ENABLE      0x%X\r\n", SD_CSD_WP_GRP_ENABLE(pSd)     );
    TRACE_INFO(" .R2W_FACTOR         0x%X\r\n", SD_CSD_R2W_FACTOR(pSd)        );
    TRACE_INFO(" .WRITE_BL_LEN       0x%X\r\n", SD_CSD_WRITE_BL_LEN(pSd)      );
    TRACE_INFO(" .WRITE_BL_PARTIAL   0x%X\r\n", SD_CSD_WRITE_BL_PARTIAL(pSd)  );
    TRACE_INFO(" .FILE_FORMAT_GRP    0x%X\r\n", SD_CSD_FILE_FORMAT_GRP(pSd)   );
    TRACE_INFO(" .COPY               0x%X\r\n", SD_CSD_COPY(pSd)              );
    TRACE_INFO(" .PERM_WRITE_PROTECT 0x%X\r\n", SD_CSD_PERM_WRITE_PROTECT(pSd));
    TRACE_INFO(" .TMP_WRITE_PROTECT  0x%X\r\n", SD_CSD_TMP_WRITE_PROTECT(pSd) );
    TRACE_INFO(" .FILE_FORMAT        0x%X\r\n", SD_CSD_FILE_FORMAT(pSd)       );
    TRACE_INFO(" .ECC                0x%X\r\n", SD_CSD_ECC(pSd)               );
    TRACE_INFO(" .CRC                0x%X\r\n", SD_CSD_CRC(pSd)               );
    TRACE_INFO(" .MULT               0x%X\r\n", SD_CSD_MULT(pSd)              );
    TRACE_INFO(" .BLOCKNR            0x%X\r\n", SD_CSD_BLOCKNR(pSd)           );
    TRACE_INFO(" .BLOCKNR_HC         0x%X\r\n", SD_CSD_BLOCKNR_HC(pSd)        );
    TRACE_INFO(" .BLOCK_LEN          0x%X\r\n", SD_CSD_BLOCK_LEN(pSd)         );
    TRACE_INFO(" .TOTAL_SIZE         0x%X\r\n", SD_CSD_TOTAL_SIZE(pSd)        );
    TRACE_INFO(" .TOTAL_SIZE_HC      0x%X\r\n", SD_CSD_TOTAL_SIZE_HC(pSd)     );
    TRACE_INFO(" -SD_TOTAL_SIZE      0x%X\r\n", SD_TOTAL_SIZE(pSd)            );
    TRACE_INFO(" -SD_TOTAL_BLOCK     0x%X\r\n", SD_TOTAL_BLOCK(pSd)           );
}   

//------------------------------------------------------------------------------
/// Display the content of the EXT_CSD register
/// \param pSd  
//------------------------------------------------------------------------------
void SD_DisplayRegisterECSD(SdCard *pSd)
{
    if (pSd->cardType >= CARD_MMC && pSd->cardType <= CARD_MMCHD
        && SD_CSD_STRUCTURE(pSd) >= 2) {}
    else {
        TRACE_INFO("** EXT_CSD NOT SUPPORTED\n\r");
        return;
    }
    TRACE_INFO("======= EXT_CSD =======");
  #if 0
  {
    unsigned int i;
    unsigned char *p = (unsigned char *)pSd->extData;
    for(i = 0; i < 512; i++) {
        if ((i % 16) == 0) TRACE_INFO_WP("\n\r [%3d]:", i);
        TRACE_INFO_WP(" %2x", p[i]);
    }
    TRACE_INFO_WP("\n\r");
    TRACE_INFO("------------------------\n\r");
  }
  #else
    TRACE_INFO_WP("\n\r");
  #endif
    TRACE_INFO(" .S_CMD_SET            : 0x%X\n\r",
        SD_EXTCSD_S_CMD_SET(pSd));
    TRACE_INFO(" .BOOT_INFO            : 0x%X\n\r",
        SD_EXTCSD_BOOT_INFO(pSd));
    TRACE_INFO(" .BOOT_SIZE_MULTI      : 0x%X\n\r",
        SD_EXTCSD_BOOT_SIZE_MULTI(pSd));
    TRACE_INFO(" .ACC_SIZE             : 0x%X\n\r",
        SD_EXTCSD_ACC_SIZE(pSd));
    TRACE_INFO(" .HC_ERASE_GRP_SIZE    : 0x%X\n\r",
        SD_EXTCSD_HC_ERASE_GRP_SIZE(pSd));
    TRACE_INFO(" .ERASE_TIMEOUT_MULT   : 0x%X\n\r",
        SD_EXTCSD_ERASE_TIMEOUT_MULT(pSd));
    TRACE_INFO(" .REL_WR_SEC_C         : 0x%X\n\r",
        SD_EXTCSD_REL_WR_SEC_C(pSd));
    TRACE_INFO(" .HC_WP_GRP_SIZE       : 0x%X\n\r",
        SD_EXTCSD_HC_WP_GRP_SIZE(pSd));
    TRACE_INFO(" .S_C_VCC              : 0x%X\n\r",
        SD_EXTCSD_S_C_VCC(pSd));
    TRACE_INFO(" .S_C_VCCQ             : 0x%X\n\r",
        SD_EXTCSD_S_C_VCCQ(pSd));
    TRACE_INFO(" .S_A_TIMEOUT          : 0x%X\n\r",
        SD_EXTCSD_S_A_TIMEOUT(pSd));
    TRACE_INFO(" .SEC_COUNT            : 0x%X\n\r",
        SD_EXTCSD_SEC_COUNT(pSd));
    TRACE_INFO(" .MIN_PERF_W_8_52      : 0x%X\n\r",
        SD_EXTCSD_MIN_PERF_W_8_52(pSd));
    TRACE_INFO(" .MIN_PERF_R_8_52      : 0x%X\n\r",
        SD_EXTCSD_MIN_PERF_R_8_52(pSd));
    TRACE_INFO(" .MIN_PERF_W_8_26_4_52 : 0x%X\n\r",
        SD_EXTCSD_MIN_PERF_W_8_26_4_52(pSd));
    TRACE_INFO(" .MIN_PERF_R_8_26_4_52 : 0x%X\n\r",
        SD_EXTCSD_MIN_PERF_R_8_26_4_52(pSd));
    TRACE_INFO(" .MIN_PERF_W_4_26      : 0x%X\n\r",
        SD_EXTCSD_MIN_PERF_W_4_26(pSd));
    TRACE_INFO(" .MIN_PERF_R_4_26      : 0x%X\n\r",
        SD_EXTCSD_MIN_PERF_R_4_26(pSd));
    TRACE_INFO(" .PWR_CL_26_360        : 0x%X\n\r",
        SD_EXTCSD_PWR_CL_26_360(pSd));
    TRACE_INFO(" .PWR_CL_52_360        : 0x%X\n\r",
        SD_EXTCSD_PWR_CL_52_360(pSd));
    TRACE_INFO(" .PWR_CL_26_195        : 0x%X\n\r",
        SD_EXTCSD_PWR_CL_26_195(pSd));
    TRACE_INFO(" .PWR_CL_52_195        : 0x%X\n\r",
        SD_EXTCSD_PWR_CL_52_195(pSd));
    TRACE_INFO(" .CARD_TYPE            : 0x%X\n\r",
        SD_EXTCSD_CARD_TYPE(pSd));
    TRACE_INFO(" .CSD_STRUCTURE        : 0x%X\n\r",
        SD_EXTCSD_CSD_STRUCTURE(pSd));
    TRACE_INFO(" .EXT_CSD_REV          : 0x%X\n\r",
        SD_EXTCSD_EXT_CSD_REV(pSd));
    TRACE_INFO(" .CMD_SET              : 0x%X\n\r",
        SD_EXTCSD_CMD_SET(pSd));
    TRACE_INFO(" .CMD_SET_REV          : 0x%X\n\r",
        SD_EXTCSD_CMD_SET_REV(pSd));
    TRACE_INFO(" .POWER_CLASS          : 0x%X\n\r",
        SD_EXTCSD_POWER_CLASS(pSd));
    TRACE_INFO(" .HS_TIMING            : 0x%X\n\r",
        SD_EXTCSD_HS_TIMING(pSd));
    TRACE_INFO(" .BUS_WIDTH            : 0x%X\n\r",
        SD_EXTCSD_BUS_WIDTH(pSd));
    TRACE_INFO(" .ERASED_MEM_CONT      : 0x%X\n\r",
        SD_EXTCSD_ERASED_MEM_CONT(pSd));
    TRACE_INFO(" .BOOT_CONFIG          : 0x%X\n\r",
        SD_EXTCSD_BOOT_CONFIG(pSd));
    TRACE_INFO(" .BOOT_BUS_WIDTH       : 0x%X\n\r",
        SD_EXTCSD_BOOT_BUS_WIDTH(pSd));
    TRACE_INFO(" .ERASE_GROUP_DEF      : 0x%X\n\r",
        SD_EXTCSD_ERASE_GROUP_DEF(pSd));
}

//------------------------------------------------------------------------------
/// Display the content of the SCR register
/// \param pSd  Pointer to SdCard instance.
//------------------------------------------------------------------------------
void SD_DisplayRegisterSCR(SdCard *pSd)
{ 
    if (pSd->cardType >= CARD_SD && pSd->cardType <= CARD_SDHC) {}
    else {
        TRACE_INFO("** SCR NOT Supported!\n\r");
        return;
    }
    TRACE_INFO("========== SCR ==========");
  #if 0
  {
    unsigned int i;
    unsigned char *p = (unsigned char*)pSd->extData;
    //TRACE_INFO_WP("\n\r");
    //TRACE_INFO("DATA @ 0x%X", (unsigned int)p);
    for(i = 0; i < 16; i ++) {
        if ((i % 8) == 0) TRACE_INFO_WP("\n\r [%3d]:", i);
        TRACE_INFO_WP(" %02x", p[i]);
    }
    TRACE_INFO_WP("\n\r");
    TRACE_INFO("------------------------\n\r");
  }
  #else
    TRACE_INFO_WP("\n\r");
  #endif

    TRACE_INFO(" .SCR_STRUCTURE         :0x%X\n\r",
        SD_SCR_SCR_STRUCTURE(pSd));
    TRACE_INFO(" .SD_SPEC               :0x%X\n\r",
        SD_SCR_SD_SPEC(pSd));
    TRACE_INFO(" .DATA_STAT_AFTER_ERASE :0x%X\n\r",
        SD_SCR_DATA_STAT_AFTER_ERASE(pSd));
    TRACE_INFO(" .SD_SECURITY           :0x%X\n\r",
        SD_SCR_SD_SECURITY(pSd));
    TRACE_INFO(" .SD_BUS_WIDTHS         :0x%X\n\r",
        SD_SCR_SD_BUS_WIDTHS(pSd));
}

//------------------------------------------------------------------------------
/// Display the content of the SD Status
/// \param pSd  Pointer to SdCard instance.
//------------------------------------------------------------------------------
void SD_DisplaySdStatus(SdCard *pSd)
{
    if (   pSd->cardType >= CARD_SD
        && pSd->cardType <= CARD_SDHC
        && (pSd->optCmdBitMap & SD_ACMD13_SUPPORT) ) {}
    else {
        TRACE_INFO("** SD Status NOT Supported!\n\r");
        return;
    }
    TRACE_INFO("=========== STAT ============");
  #if 0
  {
    unsigned int i;
    unsigned char *p = (unsigned char*)pSd->extData;
    //TRACE_INFO_WP("\n\r");
    //TRACE_INFO("DATA @ 0x%X", (unsigned int)p);
    for(i = 0; i < 72; i ++) {
        if ((i % 8) == 0) TRACE_INFO_WP("\n\r [%3d]:", i);
        TRACE_INFO_WP(" %02x", p[i]);
    }
    TRACE_INFO_WP("\n\r");
    TRACE_INFO("------------------------\n\r");
  }
  #else
    TRACE_INFO_WP("\n\r");
  #endif

    TRACE_INFO(" .DAT_BUS_WIDTH          :0x%X\n\r",
        SD_STAT_DAT_BUS_WIDTH(pSd));
    TRACE_INFO(" .SECURED_MODE           :0x%X\n\r",
        SD_STAT_SECURED_MODE(pSd));
    TRACE_INFO(" .SD_CARD_TYPE           :0x%X\n\r",
        SD_STAT_SD_CARD_TYPE(pSd));
    TRACE_INFO(" .SIZE_OF_PROTECTED_AREA :0x%X\n\r",
        SD_STAT_SIZE_OF_PROTECTED_AREA(pSd));
    TRACE_INFO(" .SPEED_CLASS            :0x%X\n\r",
        SD_STAT_SPEED_CLASS(pSd));
    TRACE_INFO(" .PERFORMANCE_MOVE       :0x%X\n\r",
        SD_STAT_PERFORMANCE_MOVE(pSd));
    TRACE_INFO(" .AU_SIZE                :0x%X\n\r",
        SD_STAT_AU_SIZE(pSd));
    TRACE_INFO(" .ERASE_SIZE             :0x%X\n\r",
        SD_STAT_ERASE_SIZE(pSd));
    TRACE_INFO(" .ERASE_TIMEOUT          :0x%X\n\r",
        SD_STAT_ERASE_TIMEOUT(pSd));
    TRACE_INFO(" .ERASE_OFFSET           :0x%X\n\r",
        SD_STAT_ERASE_OFFSET(pSd));
}
