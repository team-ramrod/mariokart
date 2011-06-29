include ../common.mk
# Define any computer specific TOOL_PREFIX etc. in here
-include ../local.mk

LIB_DIR  = ../lib
LIB_NAME = mario
LIB = $(LIB_DIR)/lib$(LIB_NAME).a

LDFLAGS += -L$(LIB_DIR)
LDFLAGS += -l$(LIB)

CFLAGS += -I$(LIB_DIR)/peripherals
CFLAGS += -I$(LIB_DIR)/boards/$(BOARD)

all: $(patsubst %/main.c,%.hex,$(wildcard */main.c))

rebuild: clean all

%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@

$(LIB):
	$(MAKE) -C $(LIB_DIR)

%.elf: %/main.o $(LIB)
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

ocd-%: build/%.hex
	blahblahblah

clean:
	rm -f */*.o
	rm -f *.elf
	rm -f *.hex
	rm -f .deps/*
	rm -f *.a

.PRECIOUS: %.o %.hex %.elf

.PHONY: all rebuild clean

# Include the dependency files, should be the last of the makefile
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)
