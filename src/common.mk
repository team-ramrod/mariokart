##################################
##  Microcontroller Properties  ##
##################################
MCU = arm7tdmi


########################
##  Toolchain Config  ##
########################
CC = arm-elf-gcc
OBJCOPY = arm-elf-objcopy
CFLAGS += -Wall -mcpu=$(MCU) -Os -iquote. -std=gnu99 -pedantic
LDFLAGS +=


###############################
##  Internal Implementation  ##
###############################
rebuild: clean all

%.hex: %.out
	$(OBJCOPY) -O ihex $< $@

%.out:
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $^

ocd-%: build/%.hex
	blahblahblah

clean:
	rm -f */*.o
	rm -f *.out

cleanall: clean
	rm -f *.hex

.PHONY: all rebuild
.PHONY: clean cleanall
