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

#include "USBDCallbacks.h"
#include "USBD.h"
#include <board.h>
#include <irq/irq.h>

//------------------------------------------------------------------------------
//         Exported function
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
/// Invoked after the USB driver has been initialized. By default, configures
/// the UDP/UDPHS interrupt.
//------------------------------------------------------------------------------
void USBDCallbacks_Initialized(void)
{
#if defined(CHIP_USB_UDP)
    // Configure and enable the UDP interrupt
    IRQ_ConfigureIT(AT91C_ID_UDP, 0, USBD_IrqHandler);
    IRQ_EnableIT(AT91C_ID_UDP);

#elif defined(CHIP_USB_UDPHS)
    // Configure and enable the UDPHS interrupt
    IRQ_ConfigureIT(AT91C_ID_UDPHS, 0, USBD_IrqHandler);
    IRQ_EnableIT(AT91C_ID_UDPHS);

#elif defined(CHIP_USB_OTGHS)
    IRQ_ConfigureIT(AT91C_ID_OTGHS, 1, (void*) 0);
    IRQ_EnableIT(AT91C_ID_OTGHS);

#else
    #error Unsupported controller.
#endif
}

