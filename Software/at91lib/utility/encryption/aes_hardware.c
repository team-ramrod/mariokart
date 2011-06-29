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
// Function:      Firmware encryption using hardware acceleration
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------

#include "aes_hardware.h"

#if defined(USE_ENCRYPTION) && defined(ENCRYPTION_AES_HARD)
#include "config.h"
#include <stdio.h>
#include <string.h>
#include <board.h>
#include <utility/trace.h>
#include <utility/assert.h>
#include <pmc/pmc.h>
#include <aes/aes_p.h>

//------------------------------------------------------------------------------
// Inline functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Converts an ASCII value to an hexadecimal one
/// \param ASCII string
/// \param Buffer to store integer value
/// \param Length of string
//------------------------------------------------------------------------------
static inline void ASCII2Hex(const unsigned char * ascii,
                             unsigned char * binary,
                             unsigned int length)
{
    unsigned int i;

    for (i=0; i < length; i++) {
        if (ascii[i*2] >= 'A') {
            binary[i] = ascii[i*2] - 'A' + 10;
        }
        else {
            binary[i] = ascii[i*2] - '0';
        }
        binary[i] <<= 4;
        if (ascii[i*2+1] >= 'A') {
            binary[i] += ascii[i*2+1] - 'A' + 10;
        }
        else {
            binary[i] += ascii[i*2+1] - '0';
        }
    }
}

//------------------------------------------------------------------------------
// Functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Initializes the AES peripheral
//------------------------------------------------------------------------------
#ifdef ONLY_ONE_ENCRYPTION
void aes_hard_init(void) 
{
    unsigned char key[ENCRYPTION_KEY_LENGTH];

#if defined(ENCRYPTION_CTR) || defined(ENCRYPTION_CBC)
    unsigned char IV[ENCRYPTION_BLOCK_LENGTH];
#endif
  
    TRACE_DEBUG("AES/HARD: Initializing ...\n\r");

    // Activate peripheral clock
#ifdef AT91C_ID_AES
    PMC_EnablePeripheral( AT91C_ID_AES );
#elif AT91C_ID_AESTDES
    PMC_EnablePeripheral( AT91C_ID_AESTDES );
#elif AT91C_ID_TDES
    PMC_EnablePeripheral( AT91C_ID_TDES );
#else
#error AES undefined
#endif

    // Load mode
    //AES_Configure(AT91C_AES_CIPHER, AT91C_AES_SMOD_PDC, AT91C_AES_OPMOD_ECB);

#if (ENCRYPTION_KEY_LENGTH == 32)
#if defined(ENCRYPTION_ECB)
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
                           | AT91C_AES_KEYSIZE_256_BIT
                           | AT91C_AES_OPMOD_ECB;

#elif defined(ENCRYPTION_CBC)
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
                           | AT91C_AES_KEYSIZE_256_BIT
                           | AT91C_AES_OPMOD_CBC;

#elif defined(ENCRYPTION_CTR)
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
                           | AT91C_AES_KEYSIZE_256_BIT
                           | AT91C_AES_OPMOD_CTR;
#endif
#elif (ENCRYPTION_KEY_LENGTH == 24)
#if defined(ENCRYPTION_ECB)
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
                           | AT91C_AES_KEYSIZE_192_BIT
                           | AT91C_AES_OPMOD_ECB;

#elif defined(ENCRYPTION_CBC)
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
                           | AT91C_AES_KEYSIZE_192_BIT
                           | AT91C_AES_OPMOD_CBC;

#elif defined(ENCRYPTION_CTR)
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
                           | AT91C_AES_KEYSIZE_192_BIT
                           | AT91C_AES_OPMOD_CTR;
#endif
#else
#if defined(ENCRYPTION_ECB)
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
                           | AT91C_AES_KEYSIZE_128_BIT
                           | AT91C_AES_OPMOD_ECB;

#elif defined(ENCRYPTION_CBC)
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
                           | AT91C_AES_KEYSIZE_128_BIT
                           | AT91C_AES_OPMOD_CBC;

#elif defined(ENCRYPTION_CTR)
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
                           | AT91C_AES_KEYSIZE_128_BIT
                           | AT91C_AES_OPMOD_CTR;
#endif
#endif
  
    // Convert and load key
    ASCII2Hex((unsigned char*)ENCRYPTION_KEY, key, ENCRYPTION_KEY_LENGTH);

    AES_SetKey((unsigned int*)key, ENCRYPTION_KEY_LENGTH);

    // Convert and load IV
#if defined(ENCRYPTION_CTR) || defined(ENCRYPTION_CBC)
    ASCII2Hex((unsigned char*)ENCRYPTION_IV, IV, ENCRYPTION_BLOCK_LENGTH);

    AES_SetVector((unsigned int*)IV);
#endif

    TRACE_DEBUG("AES/HARD: Initialization done.\n\r");
}
#endif

//------------------------------------------------------------------------------
/// Initializes the AES peripheral for CBC mode
//------------------------------------------------------------------------------
#ifndef ONLY_ONE_ENCRYPTION
#if defined(ENCRYPTION_CBC)
void aes_hard_init_CBC(void) 
{
    unsigned char key[ENCRYPTION_KEY_LENGTH];
    unsigned char IV[ENCRYPTION_BLOCK_LENGTH];
  
    TRACE_DEBUG("aes_hard_init_CBC\n\r");

    // Activate peripheral clock
#ifdef AT91C_ID_AES
    PMC_EnablePeripheral( AT91C_ID_AES );
#elif AT91C_ID_AESTDES
    PMC_EnablePeripheral( AT91C_ID_AESTDES );
#elif AT91C_ID_TDES
    PMC_EnablePeripheral( AT91C_ID_TDES );
#else
#error AES undefined
#endif

    // Load mode
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
#if (ENCRYPTION_KEY_LENGTH == 32)
                           | AT91C_AES_KEYSIZE_256_BIT
#endif
#if (ENCRYPTION_KEY_LENGTH == 24)
                           | AT91C_AES_KEYSIZE_192_BIT
#endif
                           | AT91C_AES_OPMOD_CBC; // Cipher Block Chaining mode
  
    // Convert and load key
    ASCII2Hex((unsigned char*)ENCRYPTION_KEY, key, ENCRYPTION_KEY_LENGTH);

    AES_SetKey((unsigned int*)key, ENCRYPTION_KEY_LENGTH);

    // Convert and load IV
    ASCII2Hex((unsigned char*)ENCRYPTION_IV, IV, ENCRYPTION_BLOCK_LENGTH);

    AES_SetVector((unsigned int*)IV);
}
#endif

//------------------------------------------------------------------------------
/// Initializes the AES peripheral for CTR mode
//------------------------------------------------------------------------------
#if defined(ENCRYPTION_CTR)
void aes_hard_init_CTR(void) 
{
    unsigned char key[ENCRYPTION_KEY_LENGTH];
    unsigned char IV[ENCRYPTION_BLOCK_LENGTH];
  
    TRACE_DEBUG("aes_hard_init_CTR\n\r");

    // Activate peripheral clock
#ifdef AT91C_ID_AES
    PMC_EnablePeripheral( AT91C_ID_AES );
#elif AT91C_ID_AESTDES
    PMC_EnablePeripheral( AT91C_ID_AESTDES );
#elif AT91C_ID_TDES
    PMC_EnablePeripheral( AT91C_ID_TDES );
#else
#error AES undefined
#endif

    // Load mode
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC    // PDC Mode
#if (ENCRYPTION_KEY_LENGTH == 32)
                           | AT91C_AES_KEYSIZE_256_BIT
#endif
#if (ENCRYPTION_KEY_LENGTH == 24)
                           | AT91C_AES_KEYSIZE_192_BIT
#endif
                           | AT91C_AES_OPMOD_CTR;  // Counter mode
  
    // Convert and load key
    ASCII2Hex((unsigned char*)ENCRYPTION_KEY, key, ENCRYPTION_KEY_LENGTH);

    AES_SetKey((unsigned int*)key, ENCRYPTION_KEY_LENGTH);

    // Convert and load IV
    ASCII2Hex((unsigned char*)ENCRYPTION_IV, IV, ENCRYPTION_BLOCK_LENGTH);

    AES_SetVector((unsigned int*)IV);
}
#endif

//------------------------------------------------------------------------------
/// Initializes the AES peripheral for ECB mode
//------------------------------------------------------------------------------
#if defined(ENCRYPTION_ECB)
void aes_hard_init_ECB(void) 
{
    unsigned char key[ENCRYPTION_KEY_LENGTH];

    TRACE_DEBUG("aes_hard_init_ECB\n\r");

    // Activate peripheral clock
#ifdef AT91C_ID_AES
    PMC_EnablePeripheral( AT91C_ID_AES );
#elif AT91C_ID_AESTDES
    PMC_EnablePeripheral( AT91C_ID_AESTDES );
#elif AT91C_ID_TDES
    PMC_EnablePeripheral( AT91C_ID_TDES );
#else
#error AES undefined
#endif

    // Load mode
    AT91C_BASE_AES->AES_MR = AT91C_AES_SMOD_PDC   // PDC Mode
#if (ENCRYPTION_KEY_LENGTH == 32)
                           | AT91C_AES_KEYSIZE_256_BIT
#endif
#if (ENCRYPTION_KEY_LENGTH == 24)
                           | AT91C_AES_KEYSIZE_192_BIT
#endif
                           | AT91C_AES_OPMOD_ECB; // ECB Electronic CodeBook mode

    // Convert and load key
    ASCII2Hex((unsigned char*)ENCRYPTION_KEY, key, ENCRYPTION_KEY_LENGTH);

    AES_SetKey((unsigned int*)key, ENCRYPTION_KEY_LENGTH);
}
#endif
#endif // ONLY_ONE_ENCRYPTION

//------------------------------------------------------------------------------
/// Cleans up the AES peripheral
//------------------------------------------------------------------------------
void aes_hard_cleanup(void) 
{
    TRACE_DEBUG("AES/HARD: Cleaning up ...\n\r");

    AT91C_BASE_AES->AES_MR = 0;

#ifdef AT91C_ID_AES
    PMC_DisablePeripheral( AT91C_ID_AES );
#elif AT91C_ID_AESTDES
    PMC_DisablePeripheral( AT91C_ID_AESTDES );
#elif AT91C_ID_TDES
    PMC_DisablePeripheral( AT91C_ID_TDES );
#else
#error AES undefined
#endif

#ifdef AT91C_BASE_PDC_AES
    // Close PDC
    AT91C_BASE_PDC_AES->PDC_PTCR = AT91C_PDC_RXTDIS;
    AT91C_BASE_PDC_AES->PDC_PTCR = AT91C_PDC_TXTDIS;

    // Reset all Counter register Next buffer first
    AT91C_BASE_PDC_AES->PDC_TNPR = 0;
    AT91C_BASE_PDC_AES->PDC_TNCR = 0;
    AT91C_BASE_PDC_AES->PDC_RPR = 0;
    AT91C_BASE_PDC_AES->PDC_RCR = 0;
    AT91C_BASE_PDC_AES->PDC_TPR = 0;
    AT91C_BASE_PDC_AES->PDC_TCR = 0;
    AT91C_BASE_PDC_AES->PDC_RPR = 0;
    AT91C_BASE_PDC_AES->PDC_RCR = 0;
#else
    //Disable DMA Channels
    AT91C_BASE_HDMA->HDMA_CHDR = (1<<0)| (1<<1);
 #endif

    TRACE_DEBUG("AES/HARD: Cleanup done.\n\r");
}

//------------------------------------------------------------------------------
/// Decrypts a variable-length cipher text
/// \param pCipherText text to decrypt
/// \param pPlainText to store plain text
/// \param length of cipher text (in bytes)
/// \return: 1 if ok, 0 if error
//------------------------------------------------------------------------------
int aes_hard_decrypt(const unsigned char *pCipherText,
                     unsigned char *pPlainText,
                     unsigned int length)
{
    TRACE_DEBUG("aes_hard_decrypt\n\r");

    // Check parameters
    if ((pCipherText == NULL) || (pPlainText == NULL)) {
        return 0;
    }

#ifdef AT91C_BASE_PDC_AES
    // Set source and destination buffers in PDC
    AT91C_BASE_PDC_AES->PDC_TPR = (unsigned int) pCipherText;
    AT91C_BASE_PDC_AES->PDC_RPR = (unsigned int) pPlainText;

    AT91C_BASE_PDC_AES->PDC_TCR = length >> 2;
    AT91C_BASE_PDC_AES->PDC_RCR = length >> 2;

    // Start decryption and wait
    AT91C_BASE_PDC_AES->PDC_PTCR = AT91C_PDC_RXTEN | AT91C_PDC_TXTEN;
    while (((AES_GetStatus()) & AT91C_AES_ENDRX) == 0);
#else

    // Enable DMA chanels
    AT91C_BASE_HDMA->HDMA_CHER = (1<<0) | (1<<1);
    // Wait end of transfer
    while( (AT91C_BASE_HDMA->HDMA_CHSR & ((1<<0)|(1<<1))) != 0 );
#endif

    return 1;
}

#endif // defined(USE_ENCRYPTION) && defined(ENCRYPTION_AES_HARD)

