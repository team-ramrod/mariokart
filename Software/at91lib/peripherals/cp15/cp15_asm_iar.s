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

        MODULE  ?cp15

        ;; Forward declaration of sections.
        SECTION IRQ_STACK:DATA:NOROOT(2)
        SECTION CSTACK:DATA:NOROOT(3)

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#define __ASSEMBLY__
#include "board.h"

#ifdef CP15_PRESENT

//------------------------------------------------------------------------------
/// Functions to access CP15 coprocessor register
//------------------------------------------------------------------------------
        // c0
        PUBLIC  CP15_ReadID
        PUBLIC  CP15_ReaDcacheType
        PUBLIC  CP15_ReadTCMStatus
        // c1        
        PUBLIC  CP15_ReadControl
        PUBLIC  CP15_WriteControl
        // c2        
        PUBLIC  CP15_ReadTTB
        PUBLIC  CP15_WriteTTB
        // c3        
        PUBLIC  CP15_ReadDomainAccessControl
        PUBLIC  CP15_WriteDomainAccessControl
        // c7        
        PUBLIC  CP15_InvalidateIDcache
        PUBLIC  CP15_InvalidateDcache
        PUBLIC  CP15_InvalidateIcache
        PUBLIC  CP15_PrefetchIcacheLine
        PUBLIC  CP15_TestCleanInvalidateDcache
        PUBLIC  CP15_DrainWriteBuffer
        PUBLIC  CP15_WaitForInterrupt
        // c8        
        PUBLIC  CP15_InvalidateTLB
        PUBLIC  CP15_InvalidateTLBMVA
        PUBLIC  CP15_InvalidateITLB
        PUBLIC  CP15_InvalidateITLBMVA
        PUBLIC  CP15_InvalidateDTLB
        PUBLIC  CP15_InvalidateDTLBMVA    
        // c9        
        PUBLIC  CP15_ReadDcacheLockdown
        PUBLIC  CP15_WriteDcacheLockdown
        PUBLIC  CP15_ReadIcacheLockdown 
        PUBLIC  CP15_WriteIcacheLockdown
        PUBLIC  CP15_ReadTLBLockdown
        PUBLIC  CP15_WriteTLBLockdown 
        // c13        
        PUBLIC  CP15_ReadTLBLockdown
        PUBLIC  CP15_WriteTLBLockdown        
        // c13        
        PUBLIC  CP15_ReadFCSE_PID
        PUBLIC  CP15_WriteFCSE_PID

//------------------------------------------------------------------------------
/// c0
/// Register c0 accesses the ID Register, Cache Type Register, and TCM Status Registers.
/// Reading from this register returns the device ID, the cache type, or the TCM status
/// depending on the value of Opcode_2 used:
/// Opcode_2 = 0 ID value.
/// Opcode_2 = 1 instruction and data cache type.
/// Opcode_2 = 2 TCM status.
//------------------------------------------------------------------------------
        SECTION .CP15_ReadID:DATA:NOROOT(2)
        PUBLIC   CP15_ReadID
        //ARM
// C0 read ID
CP15_ReadID:
        mov     r0, #0
        mrc     p15, 0, r0, c0, c0, 0
        bx      lr

        SECTION .CP15_ReaDcacheType:CODE:NOROOT(2)
        PUBLIC   CP15_ReaDcacheType
        //ARM
// C0 read Cache Type
CP15_ReaDcacheType:
        mov     r0, #0
        mrc     p15, 0, r0, c0, c0, 1
        bx      lr

        SECTION .CP15_ReadTCMStatus:CODE:NOROOT(2)
        PUBLIC   CP15_ReadTCMStatus
        //ARM
// C0 read TCM status
CP15_ReadTCMStatus:
        mov     r0, #0
        mrc     p15, 0, r0, c0, c0, 2
        bx      lr

//------------------------------------------------------------------------------
/// Control Register c1
/// Register c1 is the Control Register for the ARM926EJ-S processor.
/// This register specifies the configuration used to enable and disable the
/// caches and MMU. It is recommended that you access this register using a
/// read-modify-write sequence.
//------------------------------------------------------------------------------

        SECTION .CP15_ReadControl:CODE:NOROOT(2)
        PUBLIC   CP15_ReadControl
        //ARM
// CP15 Read Control Register
CP15_ReadControl:
        mov     r0, #0
        mrc     p15, 0, r0, c1, c0, 0   
        bx      lr

        SECTION .CP15_WriteControl:CODE:NOROOT(2)
        PUBLIC   CP15_WriteControl
        //ARM
// CP15 Write Control Register
CP15_WriteControl:
        mcr     p15, 0, r0, c1, c0, 0
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop        
        bx      lr

//------------------------------------------------------------------------------
/// CP15 Translation Table Base Register c2
/// Register c2 is the Translation Table Base Register (TTBR), for the base
/// address of the first-level translation table.
/// Reading from c2 returns the pointer to the currently active first-level
/// translation table in bits [31:14] and an Unpredictable value in bits [13:0].
/// Writing to register c2 updates the pointer to the first-level translation
/// table from the value in bits [31:14] of the written value. Bits [13:0]
/// Should Be Zero.
/// You can use the following instructions to access the TTBR:
/// Read TTBR  : MRC p15, 0, <Rd>, c2, c0, 0
/// Write TTBR : MCR p15, 0, <Rd>, c2, c0, 0
//------------------------------------------------------------------------------

        SECTION .CP15_ReadTTB:CODE:NOROOT(2)
        PUBLIC   CP15_ReadTTB
        //ARM
CP15_ReadTTB:
        mov     r0, #0
        mrc     p15, 0, r0, c2, c0, 0
        bx      lr

        SECTION .CP15_WriteTTB:CODE:NOROOT(2)
        PUBLIC   CP15_WriteTTB
        //ARM
CP15_WriteTTB:
        mcr     p15, 0, r0, c2, c0, 0
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
        bx      lr

//------------------------------------------------------------------------------
/// Domain Access Control Register c3
/// Read domain access permissions  : MRC p15, 0, <Rd>, c3, c0, 0
/// Write domain access permissions : MCR p15, 0, <Rd>, c3, c0, 0
//------------------------------------------------------------------------------

        SECTION .CP15_ReadDomainAccessControl:CODE:NOROOT(2)
        PUBLIC   CP15_ReadDomainAccessControl
        //ARM
CP15_ReadDomainAccessControl:
        mov     r0, #0
        mrc     p15, 0, r0, c3, c0, 0
        bx      lr

        SECTION .CP15_WriteDomainAccessControl:CODE:NOROOT(2)
        PUBLIC   CP15_WriteDomainAccessControl
        //ARM
CP15_WriteDomainAccessControl:
        mcr     p15, 0, r0, c3, c0, 0
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
        bx      lr

//------------------------------------------------------------------------------
/// Fault Status Registers Register c5
/// Register c5 accesses the Fault Status Registers (FSRs). The FSRs contain the source of
/// the last instruction or data fault. The instruction-side FSR is intended for debug
/// purposes only. The FSR is updated for alignment faults, and external aborts that occur
/// while the MMU is disabled.
/// The FSR accessed is determined by the value of the Opcode_2 field:
/// Opcode_2 = 0  Data Fault Status Register (DFSR).
/// Opcode_2 = 1  Instruction Fault Status Register (IFSR).
/// The fault type encoding is listed in Table 3-9 on page 3-22.
/// You can access the FSRs using the following instructions:
/// MRC p15, 0, <Rd>, c5, c0, 0 ;read DFSR
/// MCR p15, 0, <Rd>, c5, c0, 0 ;write DFSR
/// MRC p15, 0, <Rd>, c5, c0, 1 ;read IFSR
/// MCR p15, 0, <Rd>, c5, c0, 1 ;write IFSR
//------------------------------------------------------------------------------

        SECTION .CP15_ReadDFSR:CODE:NOROOT(2)
        PUBLIC   CP15_ReadDFSR
        //ARM
CP15_ReadDFSR:
        mov     r0, #0
        mrc     p15, 0, r0, c5, c0, 0
        bx      lr

        SECTION .CP15_writeDFSR:CODE:NOROOT(2)
        PUBLIC   CP15_writeDFSR
        //ARM
CP15_writeDFSR:
        mcr     p15, 0, r0, c5, c0, 0
        bx      lr

        SECTION .CP15_ReadIFSR:CODE:NOROOT(2)
        PUBLIC   CP15_ReadIFSR
        //ARM
CP15_ReadIFSR:
        mov     r0, #0
        mrc     p15, 0, r0, c5, c0, 1
        bx      lr

        SECTION .CP15_WriteIFSR:CODE:NOROOT(2)
        PUBLIC   CP15_WriteIFSR
        //ARM
CP15_WriteIFSR:
        mcr     p15, 0, r0, c5, c0, 1
        bx      lr

//------------------------------------------------------------------------------
/// Fault Address Register c6
/// Register c6 accesses the Fault Address Register (FAR). The FAR contains the Modified
/// Virtual Address of the access being attempted when a Data Abort occurred. The FAR is
/// only updated for Data Aborts, not for Prefetch Aborts. The FAR is updated for
/// alignment faults, and external aborts that occur while the MMU is disabled.
/// You can use the following instructions to access the FAR:
/// MRC p15, 0, <Rd>, c6, c0, 0 ; read FAR
/// MCR p15, 0, <Rd>, c6, c0, 0 ; write FAR
//------------------------------------------------------------------------------
        SECTION .CP15_ReadFAR:CODE:NOROOT(2)
        PUBLIC   CP15_ReadFAR
        //ARM
CP15_ReadFAR:
        mov     r0, #0
        mrc     p15, 0, r0, c6, c0, 0
        bx      lr

        SECTION .CP15_writeFAR:CODE:NOROOT(2)
        PUBLIC   CP15_writeFAR
        //ARM
CP15_writeFAR:
        mcr     p15, 0, r0, c6, c0, 0
        bx      lr

//------------------------------------------------------------------------------
/// Control functions caches and the write buffer c7
/// Register c7 controls the caches and the write buffer. The function of each cache
/// operation is selected by the Opcode_2 and CRm fields in the MCR instruction used to
/// write to CP15 c7. Writing other Opcode_2 or CRm values is Unpredictable.
/// Reading from CP15 c7 is Unpredictable, with the exception of the two test and clean
/// operations (see Table 2-18 on page 2-21 and Test and clean operations on page 2-23).
/// You can use the following instruction to write to c7:
/// MCR p15, <Opcode_1>, <Rd>, <CRn>, <CRm>, <Opcode_2>
//------------------------------------------------------------------------------
/// Invalidate Icache and Dcache                        MCR p15, 0, <Rd>, c7, c7, 0
/// Invalidate Icache                                   MCR p15, 0, <Rd>, c7, c5, 0
/// Invalidate Icache single entry (MVA) MVA            MCR p15, 0, <Rd>, c7, c5, 1
/// Invalidate Icache single entry (Set/Way) Set/Way    MCR p15, 0, <Rd>, c7, c5, 2
/// Prefetch Icache line (MVA) MVA                      MCR p15, 0, <Rd>, c7, c13, 1
/// Invalidate Dcache                                   MCR p15, 0, <Rd>, c7, c6, 0
/// Invalidate Dcache single entry (MVA) MVA            MCR p15, 0, <Rd>, c7, c6, 1
/// Invalidate Dcache single entry (Set/Way) Set/Way    MCR p15, 0, <Rd>, c7, c6, 2
/// Clean Dcache single entry (MVA) MVA                 MCR p15, 0, <Rd>, c7, c10, 1
/// Clean Dcache single entry (Set/Way) Set/Way         MCR p15, 0, <Rd>, c7, c10, 2
/// Test and clean Dcache -                             MRC p15, 0, <Rd>, c7, c10, 3
/// Clean and invalidate Dcache entry (MVA)  MVA        MCR p15, 0, <Rd>, c7, c14, 1
/// Clean and invalidate Dcache entry (Set/Way) Set/Way MCR p15, 0, <Rd>, c7, c14, 2
/// Test, clean, and invalidate Dcache -                MRC p15, 0, <Rd>, c7, c14, 3
/// Drain write buffer SBZ                              MCR p15, 0, <Rd>, c7, c10, 4
/// Wait for interrupt SBZ                              MCR p15, 0, <Rd>, c7, c0, 4
//------------------------------------------------------------------------------

        SECTION .CP15_InvalidateIDcache:CODE:NOROOT(2)
        PUBLIC   CP15_InvalidateIDcache
        //ARM
// Invalidate Icache and Dcache
CP15_InvalidateIDcache:
        mov     r0, #0
        mcr     p15, 0, r0, c7, c7, 0        
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop          
        bx      lr
        
        SECTION .CP15_InvalidateIcache:CODE:NOROOT(2)
        PUBLIC   CP15_InvalidateIcache
        //ARM
// Invalidate Icache
CP15_InvalidateIcache:
        mov     r0, #0
        mcr     p15, 0, r0, c7, c5, 0     
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop          
        bx      lr

        SECTION .CP15_InvalidateDcache:CODE:NOROOT(2)
        PUBLIC   CP15_InvalidateDcache
        //ARM
// Invalidate Dcache
CP15_InvalidateDcache:
        mov     r0, #0
        mcr     p15, 0, r0, c7, c6, 0
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop          
        bx      lr

//------------------------------------------------------------------------------
/// CP15 Prefetch Icache line c7
/// Performs an Icache lookup of the specified modified virtual address.
/// If the cache misses, and the region is cacheable, a linefill is performed.
/// Prefetch Icache line (MVA): MCR p15, 0, <Rd>, c7, c13, 1
//------------------------------------------------------------------------------
        SECTION .CP15_PrefetchIcacheLine:CODE:NOROOT(2)
        PUBLIC   CP15_PrefetchIcacheLine
        //ARM
CP15_PrefetchIcacheLine:
        mcr     p15, 0, r0, c7, c13, 1
        bx      lr

//------------------------------------------------------------------------------
/// CP15 Test, clean, and invalidate Dcache c7
/// As for test and clean, except that when the entire cache has 
/// been tested and cleaned, it is invalidated.
//------------------------------------------------------------------------------
        SECTION .CP15_TestCleanInvalidateDcache:CODE:NOROOT(2)
        PUBLIC   CP15_TestCleanInvalidateDcache
        //ARM
CP15_TestCleanInvalidateDcache:
        mrc     p15, 0, r0, c7, c14, 3
        bne     CP15_TestCleanInvalidateDcache
        bx      lr

//------------------------------------------------------------------------------
/// CP15 Drain write buffer c7
/// This instruction acts as an explicit memory barrier. It drains 
/// the contents of the write buffers of all memory stores 
/// occurring in program order before this instruction is 
/// completed. No instructions occurring in program order 
/// after this instruction are executed until it completes. This 
/// can be used when timing of specific stores to the level two 
/// memory system has to be controlled (for example, when a 
/// store to an interrupt acknowledge location has to complete 
/// before interrupts are enabled).
//------------------------------------------------------------------------------
        SECTION .CP15_DrainWriteBuffer:CODE:NOROOT(2)
        PUBLIC   CP15_DrainWriteBuffer
        //ARM
CP15_DrainWriteBuffer:
        mov     r0, #0
        mcr     p15, 0, r0, c7, c10, 4
        bx      lr

//------------------------------------------------------------------------------
/// CP15 Wait For Interrupt operation c7
/// The purpose of the Wait For Interrupt operation is to put the processor in
/// to a low power state.
/// This puts the processor into a low-power state and stops it executing more
/// instructions until an interrupt, or debug request occurs, regardless of
/// whether the interrupts are disabled by the masks in the CPSR.
/// When an interrupt does occur, the mcr instruction completes and the IRQ or
/// FIQ handler is entered as normal. The return link in r14_irq or r14_fiq
/// contains the address of the mcr instruction plus 8, so that the normal
/// instruction used for interrupt return (SUBS PC,R14,#4) returns to the
/// instruction following the mcr.
/// Wait For Interrupt : MCR p15, 0, <Rd>, c7, c0, 4
//------------------------------------------------------------------------------
        SECTION .CP15_WaitForInterrupt:CODE:NOROOT(2)
        PUBLIC   CP15_WaitForInterrupt
        //ARM
CP15_WaitForInterrupt:
        mov     r0, #0
        mcr     p15, 0, r0, c7, c0, 4
        bx      lr

//------------------------------------------------------------------------------
/// Translation Lookaside Buffer (TLB) : c8
/// This is a write-only register used to control the Translation Lookaside Buffer (TLB).
/// There is a single TLB used to hold entries for both data and instructions. The TLB is
/// divided into two parts:
/// � a set-associative part
/// � a fully-associative part.
/// The fully-associative part (also referred to as the lockdown part of the TLB) is used to
/// store entries to be locked down. Entries held in the lockdown part of the TLB are
/// preserved during an invalidate TLB operation. Entries can be removed from the
/// lockdown TLB using an invalidate TLB single entry operation.
/// Six TLB operations are defined, and the function to be performed is selected by the
/// Opcode_2 and CRm fields in the MCR instruction used to write CP15 c8. Writing other
/// Opcode_2 or CRm values is Unpredictable. Reading from this register is Unpredictable.
//------------------------------------------------------------------------------
/// Invalidate TLB                                 MCR p15, 0, <Rd>, c8, c7, 0
/// Invalidate TLB single entry (MVA)              MCR p15, 0, <Rd>, c8, c7, 1
/// Invalidate instruction TLB                     MCR p15, 0, <Rd>, c8, c5, 0
/// Invalidate instruction TLB single entry (MVA)  MCR p15, 0, <Rd>, c8, c5, 1
/// Invalidate data TLB                            MCR p15, 0, <Rd>, c8, c6, 0
/// Invalidate data TLB single entry (MVA)         MCR p15, 0, <Rd>, c8, c6, 1
//------------------------------------------------------------------------------

        SECTION .CP15_InvalidateTLB:CODE:NOROOT(2)
        PUBLIC   CP15_InvalidateTLB
        //ARM
CP15_InvalidateTLB:
        mov     r0, #0
        mcr     p15, 0, r0, c8, c7, 0
        bx      lr

        SECTION .CP15_InvalidateTLBMVA:CODE:NOROOT(2)
        PUBLIC   CP15_InvalidateTLBMVA
        //ARM
CP15_InvalidateTLBMVA:
        mcr     p15, 0, r0, c8, c7, 1
        bx      lr

        SECTION .CP15_InvalidateITLB:CODE:NOROOT(2)
        PUBLIC   CP15_InvalidateITLB
        //ARM
CP15_InvalidateITLB:
        mov     r0, #0
        mcr     p15, 0, r0, c8, c5, 0
        bx      lr

        SECTION .CP15_InvalidateITLBMVA:CODE:NOROOT(2)
        PUBLIC   CP15_InvalidateITLBMVA
        //ARM
CP15_InvalidateITLBMVA:
        mcr     p15, 0, r0, c8, c5, 1
        bx      lr

        SECTION .CP15_InvalidateDTLB:CODE:NOROOT(2)
        PUBLIC   CP15_InvalidateDTLB
        //ARM
CP15_InvalidateDTLB:
        mov     r0, #0
        mcr     p15, 0, r0, c8, c6, 0
        bx      lr

        SECTION .CP15_InvalidateDTLBMVA:CODE:NOROOT(2)
        PUBLIC   CP15_InvalidateDTLBMVA
        //ARM
CP15_InvalidateDTLBMVA:
        mcr     p15, 0, r0, c8, c6, 1
        bx      lr

//------------------------------------------------------------------------------
/// Cache Lockdown Register c9
/// The Cache Lockdown Register uses a cache-way-based locking scheme (Format C) that
/// enables you to control each cache way independently.
/// These registers enable you to control which cache ways of the four-way cache are used
/// for the allocation on a linefill. When the registers are defined, subsequent linefills are
/// only placed in the specified target cache way. This gives you some control over the
/// cache pollution caused by particular applications, and provides a traditional lockdown
/// operation for locking critical code into the cache.
//------------------------------------------------------------------------------
/// Read Dcache Lockdown Register   MRC p15,0,<Rd>,c9,c0,0
/// Write Dcache Lockdown Register  MCR p15,0,<Rd>,c9,c0,0
/// Read Icache Lockdown Register   MRC p15,0,<Rd>,c9,c0,1
/// Write Icache Lockdown Register  MCR p15,0,<Rd>,c9,c0,1
//------------------------------------------------------------------------------

        SECTION .CP15_ReadDcacheLockdown:CODE:NOROOT(2)
        PUBLIC   CP15_ReadDcacheLockdown
        //ARM
CP15_ReadDcacheLockdown:
        mov     r0, #0
        mrc     p15, 0, r0, c9, c0, 0
        bx      lr

        SECTION .CP15_WriteDcacheLockdown:CODE:NOROOT(2)
        PUBLIC   CP15_WriteDcacheLockdown
        //ARM
CP15_WriteDcacheLockdown:
        mcr     p15, 0, r0, c9, c0, 0
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop          
        bx      lr

        SECTION .CP15_ReadIcacheLockdown:CODE:NOROOT(2)
        PUBLIC   CP15_ReadIcacheLockdown
        //ARM
CP15_ReadIcacheLockdown:
        mov     r0, #0
        mrc     p15, 0, r0, c9, c0, 1
        bx      lr

        SECTION .CP15_WriteIcacheLockdown:CODE:NOROOT(2)
        PUBLIC   CP15_WriteIcacheLockdown
        //ARM
CP15_WriteIcacheLockdown:
        mcr     p15, 0, r0, c9, c0, 1
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop          
        bx      lr

//------------------------------------------------------------------------------
/// TLB Lockdown Register c10
/// The TLB Lockdown Register controls where hardware page table walks place the
/// TLB entry, in the set associative region or the lockdown region of the TLB,
/// and if in the lockdown region, which entry is written. The lockdown region
/// of the TLB contains eight entries. See TLB structure for a description of
/// the structure of the TLB.
//------------------------------------------------------------------------------
/// Read data TLB lockdown victim    MRC p15,0,<Rd>,c10,c0,0
/// Write data TLB lockdown victim   MCR p15,0,<Rd>,c10,c0,0
//------------------------------------------------------------------------------

        SECTION .CP15_ReadTLBLockdown:CODE:NOROOT(2)
        PUBLIC   CP15_ReadTLBLockdown
        //ARM
CP15_ReadTLBLockdown:
        mov     r0, #0
        mrc     p15, 0, r0, c10, c0, 0
        bx      lr

        SECTION .CP15_WriteTLBLockdown:CODE:NOROOT(2)
        PUBLIC   CP15_WriteTLBLockdown
        //ARM
CP15_WriteTLBLockdown:
        mcr     p15, 0, r0, c10, c0, 0
	nop
	nop
	nop
	nop
	nop
	nop
	nop
	nop
        bx      lr

//------------------------------------------------------------------------------
/// Register c13 accesses the process identifier registers. The register accessed depends on
/// the value of the Opcode_2 field:
/// Opcode_2 = 0  Selects the Fast Context Switch Extension (FCSE) Process Identifier (PID) Register.
/// Opcode_2 = 1  Selects the Context ID Register.
//------------------------------------------------------------------------------
/// FCSE PID Register
/// Addresses issued by the ARM9EJ-S core in the range 0 to 32MB are translated in
/// accordance with the value contained in this register. Address A becomes A + (FCS
/// PID x 32MB). It is this modified address that is seen by the caches, MMU, and TC
/// interface. Addresses above 32MB are not modified. The FCSE PID is a seven-bit fie
/// enabling 128 x 32MB processes to be mapped.
/// If the FCSE PID is 0, there is a flat mapping between the virtual addresses output by
/// ARM9EJ-S core and the modified virtual addresses used by the caches, MMU, and
/// TCM interface. The FCSE PID is set to 0 at system reset.
/// If the MMU is disabled, then no FCSE address translation occurs.
/// FCSE translation is not applied for addresses used for entry based cache or TLB
/// maintenance operations. For these operations VA = MVA.
//------------------------------------------------------------------------------
/// Read FCSE PID  MRC p15,0,<Rd>,c13,c0, 0
/// Write FCSE PID MCR p15,0,<Rd>,c13,c0, 0
//------------------------------------------------------------------------------
/// Context ID Register
/// The Context ID Register provides a mechanism to allow real-time trace tools to identify
/// the currently executing process in multi-tasking environments.
/// The contents of this register are replicated on the ETMPROCID pins of the
/// ARM926EJ-S processor. ETMPROCIDWR is pulsed when a write occurs to the
/// Context ID Register.
//------------------------------------------------------------------------------
/// Read context ID  MRC p15,0,<Rd>,c13,c0, 1
/// Write context ID MCR p15,0,<Rd>,c13,c0, 1
//------------------------------------------------------------------------------

        SECTION .CP15_ReadFCSE_PID:CODE:NOROOT(2)
        PUBLIC   CP15_ReadFCSE_PID
        //ARM
CP15_ReadFCSE_PID:
        mov     r0, #0
        mrc     p15, 0, r0, c13, c0, 0
        bx      lr

        SECTION .CP15_WriteFCSE_PID:CODE:NOROOT(2)
        PUBLIC   CP15_WriteFCSE_PID
        //ARM
CP15_WriteFCSE_PID:
        mcr     p15, 0, r0, c13, c0, 0
        bx      lr

#endif
    END

