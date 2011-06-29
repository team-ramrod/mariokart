//  ----------------------------------------------------------------------------
//          ATMEL Microcontroller Software Support  -  ROUSSET  -
//  ----------------------------------------------------------------------------
//  Copyright (c) 2009, Atmel Corporation
// 
//  All rights reserved.
// 
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
// 
//  - Redistributions of source code must retain the above copyright notice,
//  this list of conditions and the disclaimer below.
// 
//  Atmel's name may not be used to endorse or promote products derived from
//  this software without specific prior written permission. 
//  
//  DISCLAIMER:  THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
//  IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
//  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
//  DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
//  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
//  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
//  EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//  ----------------------------------------------------------------------------

#include <board.h>

#if defined(BOARD_CAPTOR_OV2640)

//------------------------------------------------------------------------------
/// \unit
///
/// !!!Purpose
/// 
/// Specific configuration for Omnivision OV2640 captor
/// 
/// !!!Usage
/// 
/// -# Different files are been provided by Omnivision:
///     - 2640_yuv_cif.h
///     - 2640_yuv_qcif.h
///     - 2640_yuv_qqcif.h
///     - 2640_yuv_qqvga.h
///     - 2640_yuv_qvga.h
///     - 2640_yuv_sxga.h
///     - 2640_yuv_vga.h
/// -# Configure the captor using theses files
//--------------------------------------------------------------------------

 
//-----------------------------------------------------------------------------
//         Headers
//-----------------------------------------------------------------------------
#include <drivers/twi/twid.h>
#include <utility/trace.h>

#include <omnivision/omnivision.h>

#include "2640_yuv_cif.h"
#include "2640_yuv_qvga.h"
#include "2640_yuv_sxga.h"
#include "2640_yuv_vga.h"

//------------------------------------------------------------------------------
/// Array of image sizes supported by OV264x
//------------------------------------------------------------------------------
const static struct capture_size ov264x_sizes[] = {
//  {width, height}
    /// QVGA
    { 320, 240 },
    /// CIF
    { 352, 288 },
    /// VGA
    { 640, 480 },
    /// SXGA
    {1280, 1024 }
};

//------------------------------------------------------------------------------
//         Global Functions
//------------------------------------------------------------------------------

//-----------------------------------------------------------------------------
/// Configure the OV9650 for a specified image size, pixel format, 
/// and frame period.
//-----------------------------------------------------------------------------
void ov_configure(Twid *pTwid, unsigned int width, unsigned int heigth)
{
    const struct ov_reg *reg_conf;
    unsigned char goodCaptureSize = 0;
    unsigned char i;

    TRACE_DEBUG("ov264x_configure\n\r");
    for( i=0; i<sizeof(ov264x_sizes); i++ ) {
        if( ov264x_sizes[i].width == width ) {
            if( ov264x_sizes[i].height != heigth ) {
                TRACE_ERROR("ov264x_configure vsize not define\n\r");
            }
            else {
                goodCaptureSize = 1;
                break;
            }
        }
    }

    if( goodCaptureSize == 0 ) {
        TRACE_ERROR("Problem size\n\r");
        while(1);
        return;
    }

    // Default value
    reg_conf = ov2640_yuv_vga;
   
    // common register initialization
    switch(width) {
        case 1280: //SXGA
            TRACE_DEBUG("SXGA\n\r");
            reg_conf = ov2640_yuv_sxga;
        break;
        case 640: //VGA
            TRACE_DEBUG("VGA\n\r");
            reg_conf = ov2640_yuv_vga;
        break;
        case 352: //CIF
            TRACE_DEBUG("CIF\n\r");
            reg_conf = ov2640_yuv_cif;
        break;
        case 320: //QVGA
            TRACE_DEBUG("QVGA\n\r");
            reg_conf = ov2640_yuv_qvga;
       break;

        default:  
            TRACE_DEBUG("ov264x_configure problem\n\r");
        break;
    }
    ov_write_regs(pTwid, reg_conf);
}
#endif
