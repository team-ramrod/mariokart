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

#ifndef __DFM_FATFS_H__
#define __DFM_FATFS_H__

#if defined(PINS_NANDFLASH)
#include <memories/MEDNandFlash.h>
#include <memories/nandflash/RawNandFlash.h>
#include <memories/nandflash/TranslatedNandFlash.h>
#endif

#include "fatfs_config.h"
#include "dfm_config.h"
#include <usb/device/massstorage/MSDLun.h>
#include <pio/pio.h>
#include "Media.h"

//Assign storage drive name
#if _FS_TINY == 0
#define SDCARD_ROOT_DIRECTORY "0:"
#define NAND_ROOT_DIRECTORY "1:"
#else
#define SDCARD_ROOT_DIRECTORY ""
#define NAND_ROOT_DIRECTORY ""
#endif

#if defined(at91cap9stk)
#define MCI_ID 1 //no connector for MCIO/SPI0
#else
#define MCI_ID 0
#endif

#if defined(PINS_NANDFLASH)
/// Pins used to access to nandflash.
extern const Pin gpPinsNf[];// = {PINS_NANDFLASH};
/// Nandflash device structure.
extern struct TranslatedNandFlash gTranslatedNf;
/// Address for transferring command bytes to the nandflash.
extern unsigned int gNFCmdBytesAddr;// = BOARD_NF_COMMAND_ADDR;
/// Address for transferring address bytes to the nandflash.
extern unsigned int gNFAddrBytesAddr;// = BOARD_NF_ADDRESS_ADDR;
/// Address for transferring data bytes to the nandflash.
extern unsigned int gNFDataBytesAddr;// = BOARD_NF_DATA_ADDR;
/// Nandflash chip enable pin.
extern const Pin gNFCePin;// = BOARD_NF_CE_PIN;
/// Nandflash ready/busy pin.
extern const Pin gNFRbPin;// = BOARD_NF_RB_PIN;
#endif

///// Maximum number of LUNs which can be defined.
///// (Logical drive = physical drive = medium number)
#define MAX_LUNS        3

/// Size of one block in bytes.
#define BLOCK_SIZE          512

/// Size of the reserved Nand Flash (4M)
#define NF_RESERVE_SIZE     (4*1024*1024)

/// Size of the managed Nand Flash (128M)
#define NF_MANAGED_SIZE     (128*1024*1024)

/// Size of the MSD IO buffer in bytes (6K, more the better).
#define MSD_BUFFER_SIZE     (12*BLOCK_SIZE)

extern void ConfigureNandFlashEBI(unsigned int mck);

#endif // end of __DFM_FATFS_H__

