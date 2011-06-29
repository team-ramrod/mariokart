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

/*------------------------------------------------------------------------------
 *      Linker script for running in internal SRAM on the AT91SAM3UE256
 *----------------------------------------------------------------------------*/

OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
/*ENTRY(entry)*/

/* Memory Spaces Definitions */
MEMORY
{
    sram0 (W!RX) : ORIGIN = 0x20000000, LENGTH = 0x00008000 /* Sram0, 32K */
    sram1 (W!RX) : ORIGIN = 0x20080000, LENGTH = 0x00008000 /* Sram1, 32K */

/*    flash (  RX) : ORIGIN = 0x00080000, LENGTH = 0x00010000*/ /* Flash, 64K */
/*    rom   (W!RX) : ORIGIN = 0x00180000, LENGTH = 0x00004000*/ /* ROM,   16K */
/*    sram0 (W!RX) : ORIGIN = 0x20000000, LENGTH = 0x00008000*/ /* Sram0, 32K */
/*    sram1 (W!RX) : ORIGIN = 0x20080000, LENGTH = 0x00008000*/ /* Sram1, 32K */

    /* PSRAM, 16M, HISMC4_EBI.CS1 */
    psram (W!RX) : ORIGIN = 0x61000000, LENGTH = 0x01000000 
}

 /* Stack in SRAM0 */
_estack = 0x20007000;

/* Entry point */
ENTRY(ResetException)
SECTIONS
{
    /* startup code in the .isr_vector */
    .text :
    {
        . = ALIGN(4);
        _stext = .;
        KEEP(*(.isr_vector .isr_vector.*))
        *(.text .text.*)
        *(.glue_7)
        *(.glue_7t)
        *(.gcc_except_table)
        *(.rodata .rodata*)
        *(.gnu.linkonce.r.*)
        . = ALIGN(4);
        _etext = .;            /* End of text section */
    } > sram0

    .data :                   /* data */
    {
        . = ALIGN(4);
        _sidata = .;
        _sdata = .;

        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _edata = .;           /* End of data section */
    } > sram0

    .bss (NOLOAD) : {
        . = ALIGN(4);
        _szero = .;
        *(.bss)
        . = ALIGN(4);
        _ezero = .;
    } >sram0

    PROVIDE (end = .);
    PROVIDE (_end = .);

    /* after that it's only debugging information. */
    /* remove the debugging information from the standard libraries */
    /* Sections to be discarded */
    /DISCARD/ :
    {
     libc.a ( * )
     libm.a ( * )
     libgcc.a ( * )
     }

    /* Stabs debugging sections.  */
    .stab          0 : { *(.stab) }
    .stabstr       0 : { *(.stabstr) }
    .stab.excl     0 : { *(.stab.excl) }
    .stab.exclstr  0 : { *(.stab.exclstr) }
    .stab.index    0 : { *(.stab.index) }
    .stab.indexstr 0 : { *(.stab.indexstr) }
    .comment       0 : { *(.comment) }
    /* DWARF debug sections.
       Symbols in the DWARF debugging sections are relative to the beginning
       of the section so we begin them at 0.  */
    /* DWARF 1 */
    .debug          0 : { *(.debug) }
    .line           0 : { *(.line) }
    /* GNU DWARF 1 extensions */
    .debug_srcinfo  0 : { *(.debug_srcinfo) }
    .debug_sfnames  0 : { *(.debug_sfnames) }
    /* DWARF 1.1 and DWARF 2 */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    /* DWARF 2 */
    .debug_info     0 : { *(.debug_info .gnu.linkonce.wi.*) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }
    /* SGI/MIPS DWARF 2 extensions */
    .debug_weaknames 0 : { *(.debug_weaknames) }
    .debug_funcnames 0 : { *(.debug_funcnames) }
    .debug_typenames 0 : { *(.debug_typenames) }
    .debug_varnames  0 : { *(.debug_varnames) }

 }