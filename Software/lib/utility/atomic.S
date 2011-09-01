/**
 * Found at http://infocenter.arm.com/help/index.jsp?topic=/com.arm.doc.dht0008a/ch01s03s02.html
 */

#define locked   1
#define unlocked 0

            .align      4
            .arm

            .section    .text
            .global     lock_mutex
            .global     unlock_mutex

/**
 * lock_mutex
 * Declare for use from C as extern void lock_mutex(void * mutex);
 */
lock_mutex:
    LDR     r1, =locked
1:
    LDREX   r2, [r0]
    CMP     r2, r1        // Test if mutex is locked or unlocked
    BEQ     2f           // If locked - wait for it to be released, from 2
    STREXNE r2, r1, [r0]  // Not locked attempt to lock it
    CMPNE   r2, #1        // Check if Store-Exclusive failed
    BEQ     1b           // Failed - retry from 1
    // Lock acquired
    DMB                   // Required before accessing protected resource
    BX      lr

2:  // Take appropriate action while waiting for mutex to become unlocked
    WFE                    // Indicate opportunity to enter low-power state
    B       1b

/**
 * unlock_mutex
 * Declare for use from C as extern void unlock_mutex(void * mutex);
 */
unlock_mutex:
    LDR     r1, =unlocked
    DMB                   // Required before releasing protected resource
    STR     r1, [r0]      // Unlock mutex
    DSB                    // Ensure update has completed before signalling
    SEV                    // Signal update
    BX      lr
