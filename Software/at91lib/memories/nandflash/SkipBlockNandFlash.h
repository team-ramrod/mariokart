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
/// \page "SkipBlockNandFlash"
///
/// !!!Purpose
/// 
/// SkipBlockNandFlash layer supplies application a set of interface to operate nandflash, which include 
/// initialize, block erase, block write/read, page write/read. This layer is called by upper layer 
/// applications, and it will call lower layer drivers, such as EccNandFlash, RawNandFlash.
///
/// !!!Usage
/// -# SkipBlockNandFlash_Initialize is used to initializes a SkipBlockNandFlash instance. Scans 
///      the device to retrieve or create block status information.
/// -# SkipBlockNandFlash_EraseBlock is used to erase a certain block in the device, user can 
///      select "check block status before erase" or "erase without check"
/// -# User can use SkipBlockNandFlash_WriteBlock to write a certain block and SkipBlockNandFlash_WritePage
///      to write a certain page. The functions will check the block status before write, if the block
///      is not a good block, the write command will not be issued.
/// -# User can use SkipBlockNandFlash_ReadBlock to read a certain block and SkipBlockNandFlash_ReadPage
///      to read a certain page. The functions will check the block status before read, if the block
///      is not a good block, the read command will not be issued. ECC is also checked after read
///      operation is finished, an error will be reported if ecc check got errors.  
//------------------------------------------------------------------------------

#ifndef SKIPBLOCKNANDFLASH_H
#define SKIPBLOCKNANDFLASH_H

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "NandCommon.h"
#include "EccNandFlash.h"

//------------------------------------------------------------------------------
//         Definitions
//------------------------------------------------------------------------------

#define NandBlockStatus_BAD   0xBA

// Erase types
/// Check block before erase
#define NORMAL_ERASE    0x00000000
/// Do NOT check the block status before erasing it
#define SCRUB_ERASE     0x0000EA11
// Values returned by the CheckBlock() function
#define BADBLOCK        255
#define GOODBLOCK       254


//------------------------------------------------------------------------------
//         Types
//------------------------------------------------------------------------------

struct SkipBlockNandFlash {
    struct EccNandFlash ecc;
};

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

extern unsigned char SkipBlockNandFlash_CheckBlock(
    const struct SkipBlockNandFlash *skipBlock,
    unsigned short block);

extern unsigned char SkipBlockNandFlash_Initialize(
    struct SkipBlockNandFlash *skipBlock,
    const struct NandFlashModel *model,
    unsigned int commandAddress,
    unsigned int addressAddress,
    unsigned int dataAddress,
    const Pin pinChipEnable,
    const Pin pinReadyBusy);

extern unsigned char SkipBlockNandFlash_EraseBlock(
    struct SkipBlockNandFlash *skipBlock,
    unsigned short block,
    unsigned int eraseType);

extern unsigned char SkipBlockNandFlash_ReadPage(
    const struct SkipBlockNandFlash *skipBlock,
    unsigned short block,
    unsigned short page,
    void *data,
    void *spare);

unsigned char SkipBlockNandFlash_ReadBlock(
    const struct SkipBlockNandFlash *skipBlock,
    unsigned short block,
    void *data);

extern unsigned char SkipBlockNandFlash_WritePage(
    const struct SkipBlockNandFlash *skipBlock,
    unsigned short block,
    unsigned short page,
    void *data,
    void *spare);

unsigned char SkipBlockNandFlash_WriteBlock(
    const struct SkipBlockNandFlash *skipBlock,
    unsigned short block,
    void *data);

#endif //#ifndef SKIPBLOCKNANDFLASH_H

