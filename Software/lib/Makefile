OUTDIR = lib

all: libmario.a

include ../common.mk
# Define any computer specific TOOL_PREFIX etc. in here
-include ../local.mk

include boards/$(BOARD)/board.mak

OBJS += $(addprefix $(OBJDIR)/,$(wildcard peripherals/**/*.c))

rebuild: clean all

$(OBJDIR) $(OUTPUT):
	mkdir -p $@

libmario.a: libmario.a($(OBJS:.c=.o))
	$(RANLIB) libmario.a

clean:
	rm -f */*.o
	rm -f *.elf
	rm -f *.hex
	rm -f .deps/*
	rm -f *.a

.PRECIOUS: %.o

.PHONY: all rebuild clean

# Include the dependency files, should be the last of the makefile
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)
