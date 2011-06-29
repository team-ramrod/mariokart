# Output directories
BIN = bin
OBJ = obj

# Compiler
CC = g++

# Optimization level
OPT = 

# Flags
INCLUDES = -I include  
INCLUDES += -I lib/EasyBMP
INCLUDES += -I lib/regex

CXXFLAGS =	$(OPT) -g -Wall 
CXXFLAGS += -D DEBUG_PROPSECTION
CXXFLAGS += -D DEBUG_DISPSECTION
CXXFLAGS += -D DEBUG_SLIDESECTION
CXXFLAGS += -D DEBUG_LINKSECTION
CXXFLAGS += -D DEBUG_CONVBMPINFO
CXXFLAGS += -D DEBUG_BEFOREPARSE
CXXFLAGS += -D DEBUG_AFTERPARSE

# Movie flas
ifeq ($(MOVIE_MERGE), on)
CXXFLAGS += -D MOVIE_MERGE_on
endif

LDFLAGS = $(OPT) 

# VPATH to search source
VPATH += ./src
VPATH += ./lib/EasyBMP

# Objects
OBJS += main.o
OBJS += ScriptParse.o
OBJS += EasyBMP.o
OBJS += CreateDemoBin.o

C_OBJECTS = $(addprefix $(OBJ)/, $(OBJS))

LIBS = lib/libregex.a

# Source code

# Output target
ifeq ($(MOVIE_MERGE), on)
TARGET =    CreateMovieBin.exe
else
TARGET =    CreateDemoBin.exe
endif

# Make target
.PHONY: all
all:	 $(BIN) $(OBJ) $(TARGET)
	
$(BIN) $(OBJ): 
	mkdir $@
	
$(OBJS): %.o: %.cpp
	$(CC) -c $(CXXFLAGS) $(INCLUDES) $< -o $(OBJ)/$@
	
$(TARGET):	$(OBJS)
	$(CC) $(LDFLAGS) -o $(BIN)/$(TARGET) $(C_OBJECTS) $(LIBS)

clean:
	-rm -f $(OBJ)/*.o $(BIN)/$(TARGET)
