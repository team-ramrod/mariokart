target remote tcp:localhost:3333
monitor arm7_9 dcc_downloads enable
monitor arm7_9 fast_memory_access enable
monitor reset
monitor sleep 500
monitor poll
monitor soft_reset_halt
load
monitor reset

