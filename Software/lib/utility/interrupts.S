/**
 * Found at http://www.embeddedrelated.com/groups/AT91SAM/show/367.php
 */

.align      4
.arm

.section    .text
.global     disable_interrupts
.global     enable_interrupts

/* extern void disable_interrupts(); */
disable_interrupts:
    mrs   r0,       cpsr
    orr   r0,       r0,     #0x80
    msr   cpsr_c,   r0
    mov   r0,       #1
    bx    lr

/* extern void enable_interrupts(); */
enable_interrupts:
    mrs   r0,       cpsr
    bic   r0,       r0,     #0x80
    msr   cpsr_c,   r0
    bx    lr

