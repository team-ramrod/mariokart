OUTDIR = src

all: $(patsubst %/main.c,%.hex,$(wildcard */main.c))

include ../common.mk
# Define any computer specific TOOL_PREFIX etc. in here
-include ../local.mk

%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@

mariolib.a:
	$(MAKE) -C ../lib

%.elf: $(OBJ_DIR)/%/main.o mariolib.a
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

ocd-%: build/%.hex
	blahblahblah

clean:
	rm -rf $(OBJ_DIR)/*
	rm -rf .dep/*

.PRECIOUS: %.o %.hex %.elf

.PHONY: all rebuild clean

# Include the dependency files, should be the last of the makefile
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)
