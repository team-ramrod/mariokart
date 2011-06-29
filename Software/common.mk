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

CFLAGS += -I../lib
CFLAGS += -I../lib/peripherals
CFLAGS += -I../lib/boards/$(BOARD)

LDFLAGS += -L../build
LDFLAGS += -lmario

rebuild: clean all

OBJDIR = ../build/objs/$(OUTDIR)
OUTPUT = ../build

VPATH += $(OUTPUT)
VPATH += $(OBJDIR)

$(OBJDIR)/%.o: %.c $(OBJDIR)
	$(CC) $(CFLAGS) -o $@ -c $<


# Generate dependency information
CFLAGS += -MMD -MP -MF .dep/$(@F).d
