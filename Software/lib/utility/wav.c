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
//         Headers
//------------------------------------------------------------------------------

#include "wav.h"
#include <utility/trace.h>

//------------------------------------------------------------------------------
//         Internal constants
//------------------------------------------------------------------------------

/// WAV letters "RIFF"
#define WAV_CHUNKID        0x46464952
/// WAV letters "WAVE"
#define WAV_FORMAT        0x45564157
/// WAV letters "fmt "
#define WAV_SUBCHUNKID    0x20746D66

//------------------------------------------------------------------------------
//         Exported functions
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Returns 1 if the header of a Wav file is valid; otherwise returns 0.
/// \param file  Buffer holding the file to examinate.
//------------------------------------------------------------------------------
unsigned char WAV_IsValid(const WavHeader *header)
{
    return ((header->chunkID == WAV_CHUNKID)
            && (header->format == WAV_FORMAT)
            && (header->subchunk1Size == 0x10));
}

//------------------------------------------------------------------------------
/// Display the information of the WAV file (sample rate, stereo/mono and frame
/// size).
//------------------------------------------------------------------------------
void WAV_DisplayInfo(const WavHeader *header)
{   
    TRACE_PERM_WP( "Wave file header information\n\r");
    TRACE_PERM_WP( "--------------------------------\n\r");
    TRACE_PERM_WP( "  - Chunk ID        = 0x%08X\n\r", header->chunkID);
    TRACE_PERM_WP( "  - Chunk Size      = %d\n\r",     header->chunkSize);
    TRACE_PERM_WP( "  - Format          = 0x%08X\n\r", header->format);
    TRACE_PERM_WP( "  - SubChunk ID     = 0x%08X\n\r", header->subchunk1ID);
    TRACE_PERM_WP( "  - Subchunk1 Size  = %d\n\r",     header->subchunk1Size);
    TRACE_PERM_WP( "  - Audio Format    = 0x%04X\n\r", header->audioFormat);
    TRACE_PERM_WP( "  - Num. Channels   = %d\n\r",     header->numChannels);
    TRACE_PERM_WP( "  - Sample Rate     = %d\n\r",     header->sampleRate);
    TRACE_PERM_WP( "  - Byte Rate       = %d\n\r",     header->byteRate);
    TRACE_PERM_WP( "  - Block Align     = %d\n\r",     header->blockAlign);
    TRACE_PERM_WP( "  - Bits Per Sample = %d\n\r",     header->bitsPerSample);
    TRACE_PERM_WP( "  - Subchunk2 ID    = 0x%08X\n\r", header->subchunk2ID);
    TRACE_PERM_WP( "  - Subchunk2 Size  = %d\n\r",     header->subchunk2Size);
}