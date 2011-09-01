#define locked   1
#define unlocked 0

/**
 * Will spin wait until the mutex given is unlocked.
 */
extern void lock_mutex(void *mutex);

/**
 * Will release the mutex.
 */
extern void unlock_mutex(void *mutex);
