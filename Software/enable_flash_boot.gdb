target remote:3333
monitor reset
monitor sleep 500
monitor poll
monitor soft_reset_halt
monitor at91sam7 gpnvm 2 set
