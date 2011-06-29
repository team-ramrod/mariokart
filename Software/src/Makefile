##################################
##  Microcontroller Properties  ##
##################################
MCU = arm7tdmi

########################
##  Toolchain Config  ##
########################
CC = arm-elf-gcc
AR = arm-elf-ar
RANLIB = arm-elf-ranlib
OBJCOPY = arm-elf-objcopy
CFLAGS += -Wall -mcpu=$(MCU) -Os -iquote. -std=gnu99 -pedantic
LDFLAGS +=
LIBS := $(patsubst %.c,%.o,$(wildcard libs/*.c))

# Generate dependency information
CFLAGS += -MMD -MP -MF .dep/$(@F).d

# Define any computer specific CC etc. in here.
-include local.mk

###############################
##  Internal Implementation  ##
###############################
all: $(patsubst %/main.c,%.hex,$(wildcard */main.c))

rebuild: clean all

%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@

libs.a: libs.a($(LIBS))

%.elf: %/main.o libs.a
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^

ocd-%: build/%.hex
	blahblahblah

clean:
	rm -f */*.o
	rm -f *.elf
	rm -f *.hex
	rm -f .deps/*
	rm -f *.a

.PRECIOUS: %.o %.hex %.elf

.PHONY: all rebuild
.PHONY: clean cleanall

# Include the dependency files, should be the last of the makefile
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)
