##################################
##  Microcontroller Properties  ##
##################################

MCU = arm7tdmi
CHIP = at91sam7xc256
BOARD = mariokartv1
MEMORY ?= sram

# Trace level used for compilation
# (can be overriden by adding TRACE_LEVEL=#number to the command-line)
# TRACE_LEVEL_DEBUG      5
# TRACE_LEVEL_INFO       4
# TRACE_LEVEL_WARNING    3
# TRACE_LEVEL_ERROR      2
# TRACE_LEVEL_FATAL      1
# TRACE_LEVEL_NO_TRACE   0
TRACE_LEVEL = 4


########################
##  Toolchain Config  ##
########################

PREFIX = arm-eabi-

CC      = $(PREFIX)gcc
AR      = $(PREFIX)ar
GDB     = $(PREFIX)gdb
RANLIB  = $(PREFIX)ranlib
OBJCOPY = $(PREFIX)objcopy

OPENOCD = openocd

OUTPUT_FOLDER  = build
OBJECTS_FOLDER = $(OUTPUT_FOLDER)/objs

OCD_CHECK_FILE = /tmp/mariokart-ocd.running

VPATH += $(OUTPUT_FOLDER)
VPATH += $(OBJECTS_FOLDER)

# Define any computer specific PREFIX etc. in here
-include local.mk


#############
##  Flags  ##
#############

INCLUDES =  -Ilib/boards/$(BOARD)
INCLUDES += -Ilib/peripherals
INCLUDES += -Ilib/components
INCLUDES += -Ilib/drivers
INCLUDES += -Ilib

INCLUDES += -Ilib/usb/common/cdc
INCLUDES += -Ilib/usb/common/core
INCLUDES += -Ilib/usb/device/cdc-serial
INCLUDES += -Ilib/usb/device/core

CFLAGS += -Wall -std=gnu99 -pedantic
CFLAGS += -mcpu=$(MCU)
CFLAGS += -Os
CFLAGS += -D$(CHIP)
CFLAGS += -D$(MEMORY)
CFLAGS += -DTRACE_LEVEL=$(TRACE_LEVEL)
CFLAGS += $(INCLUDES)

# Generate dependency information
CFLAGS += -MD -MP -MF .dep/$(subst /,-,$@).d

ASFLAGS += -Os
ASFLAGS += -D$(CHIP)
ASFLAGS += -D$(MEMORY)
ASFLAGS += -D__ASSEMBLY__
ASFLAGS += $(INCLUDES)

LINK_SCRIPT = -T"lib/boards/$(BOARD)/$(CHIP)/$(MEMORY).lds"

LDFLAGS += -nostartfiles -Wl,--gc-sections
LDFLAGS += -Lbuild
LDFLAGS += -lmario

C_FILES =  $(wildcard lib/utility/*.c)
C_FILES += $(wildcard lib/drivers/*/*.c)
C_FILES += $(wildcard lib/components/*.c)
C_FILES += $(wildcard lib/peripherals/*/*.c)

C_FILES += $(wildcard lib/usb/common/cdc/*.c)
C_FILES += $(wildcard lib/usb/common/core/*.c)
C_FILES += $(wildcard lib/usb/device/cdc-serial/*.c)
C_FILES += $(wildcard lib/usb/device/core/*.c)

C_FILES += lib/boards/$(BOARD)/board_memories.c
C_FILES += lib/boards/$(BOARD)/board_lowlevel.c

#steering files (I dont know much about makefiles so this probably needs changing)
C_FILES += $(wildcard src/steering/*.c)
#brake files will tidy this up soon
C_FILES += $(wildcard src/brake/*.c)

ASM_FILES = lib/boards/$(BOARD)/board_cstartup.S

OBJS =  $(addprefix $(OBJECTS_FOLDER)/,$(C_FILES:.c=.o))
OBJS += $(addprefix $(OBJECTS_FOLDER)/,$(ASM_FILES:.S=.o))


###############
##  Targets  ##
###############

all: libs hexes


LIB = $(OUTPUT_FOLDER)/libmario.a
libs: $(LIB)


hexes: $(patsubst src/%/main.c,$(OUTPUT_FOLDER)/%.bin,$(wildcard src/*/main.c))


rebuild: clean all


%.bin: %.elf
	$(OBJCOPY) -O binary $< $@


$(OUTPUT_FOLDER)/%.elf: $(OBJECTS_FOLDER)/src/%/main.o $(LIB)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LINK_SCRIPT) -o $@ $< $(LDFLAGS)


$(OBJECTS_FOLDER)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<


$(OBJECTS_FOLDER)/%.o: %.S
	mkdir -p $(dir $@)
	$(CC) $(ASFLAGS) -o $@ -c $<


$(OUTPUT_FOLDER)/libmario.a: $(OBJS)
	$(AR) $(ARFLAGS) $@ $?
	$(RANLIB) $@


ocd:
	touch $(OCD_CHECK_FILE) ; $(OPENOCD) -f openocd.cfg ; rm $(OCD_CHECK_FILE)

program-%: $(OUTPUT_FOLDER)/%.elf
	echo "\n\n======================================\n  Programming is not yet implemented  \n\n  Use \`make debug-$*\` then  \n  enter \`continue\` in GDB  \n======================================"

debug-%: $(OUTPUT_FOLDER)/%.elf
	if [ ! -e $(OCD_CHECK_FILE) ] ; then ( echo 'OpenOCD not running'; false ) fi
	$(GDB) -x debug.gdb $<


clean:
	rm -rf $(OUTPUT_FOLDER)/*
	rm -rf .dep/*


.PRECIOUS: $(OBJECTS_FOLDER)/%.o %.hex $(OUTPUT_FOLDER)/%.elf
.PHONY: all rebuild clean

# Include the dependency files, should be the last of the makefile
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)
