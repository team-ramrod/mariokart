MCU = arm7tdmi
CHIP = at91sam7xc256
BOARD = at91sam7xc-ek

TOOL_PREFIX = arm-elf-

CC = $(TOOL_PREFIX)gcc
AR = $(TOOL_PREFIX)ar
RANLIB = $(TOOL_PREFIX)ranlib
OBJCOPY = $(TOOL_PREFIX)objcopy

CFLAGS += -Wall -std=gnu99 -pedantic
CFLAGS += -mcpu=$(MCU)
CFLAGS += -Os
CFLAGS += -D$(CHIP)

# Generate dependency information
CFLAGS += -MMD -MP -MF .dep/$(@F).d
