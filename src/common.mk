##################################
##  Microcontroller Properties  ##
##################################
MCU = arm7tdmi


########################
##  Toolchain Config  ##
########################
CC = arm-elf-gcc
MMCU = mmcu
OBJCOPY = arm-elf-objcopy
CFLAGS = -Wall -$(MMCU)=$(MCU) -Os -std=gnu99 -pedantic
LDFLAGS =


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
	rm -f *.o
	rm -f */*.o
	rm -f *.out

cleanall:
	rm -f *.hex

.PHONY: all rebuild
.PHONY: clean cleanall
