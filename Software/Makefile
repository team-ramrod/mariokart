##################################
##  Microcontroller Properties  ##
##################################

MCU = arm7tdmi
CHIP = at91sam7xc256
BOARD = at91sam7xc-ek


########################
##  Toolchain Config  ##
########################

PREFIX = arm-elf-

CC = $(PREFIX)gcc
AR = $(PREFIX)ar
RANLIB = $(PREFIX)ranlib
OBJCOPY = $(PREFIX)objcopy

OUTPUT_FOLDER = build
OBJECTS_FOLDER = $(OUTPUT_FOLDER)/objs

VPATH += $(OUTPUT_FOLDER)
VPATH += $(OBJECTS_FOLDER)

# Define any computer specific PREFIX etc. in here
-include ../local.mk


#############
##  Flags  ##
#############

CFLAGS += -Wall -std=gnu99 -pedantic
CFLAGS += -mcpu=$(MCU)
CFLAGS += -Os
CFLAGS += -D$(CHIP)

CFLAGS += -Ilib
CFLAGS += -Ilib/peripherals
CFLAGS += -Ilib/boards/$(BOARD)

# Generate dependency information
CFLAGS += -MMD -MP -MF .dep/$(@F).d

LDFLAGS += -Lbuild
LDFLAGS += -lmario


LIBS += $(wildcard lib/peripherals/**/*.c)
OBJS = $(addprefix $(OBJECTS_FOLDER)/,$(LIBS:.c=.o))

###############
##  Targets  ##
###############

all: libs hexes


libs: $(OUTPUT_FOLDER)/libmario.a


hexes: $(patsubst src/%/main.c,$(OUTPUT_FOLDER)/%.hex,$(wildcard src/*/main.c))


rebuild: clean all


%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@


$(OUTPUT_FOLDER)/%.elf: $(OBJECTS_FOLDER)/src/%/main.o libs
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)


$(OBJECTS_FOLDER)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -o $@ -c $<


$(OUTPUT_FOLDER)/libmario.a: $(OBJS)
	$(AR) $(ARFLAGS) $?
	$(RANLIB) $@


clean:
	rm -rf $(OUTPUT_FOLDER)/*
	rm -rf .dep/*


.PRECIOUS: $(OBJECTS_FOLDER)/%.o %.hex $(OUTPUT_FOLDER)/%.elf
.PHONY: all rebuild clean

# Include the dependency files, should be the last of the makefile
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)
