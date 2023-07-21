# Environment 
MKDIR=mkdir
CP=cp
CC=xc8
LD=xc8
CCADMIN=CCadmin
RANLIB=ranlib
OBJCOPY=xc8-bin2hex





# Compiler options
CFLAGS=-mcpu=pic18f4520 -O2
CFLAGS+=-Iinclude

# Linker options
LDFLAGS=-mcpu=pic18f4520
LDFLAGS+=-Wl,-Llib
LDFLAGS+=-Wl,-Map=output.map

# Source files
DIRS := $(shell cat ./build.dir)
SRC_PATH :=  $(foreach dir,$(DIRS),$(dir)) 
SOURCES  :=  $(foreach S,$(SRC_PATH),$(wildcard $(S)/*.c))
SOURCES_COUNT:= $(words $(SOURCES))
SOURCES_CTR:=0
SOURCES += ./main.c
INC:=  $(foreach dir,$(DIRS), -I$(dir))


# Object files
OBJS:= $(SOURCES:.c=.o)

# Output file
OUTPUT=output.elf

# build
build: $(OUTPUT) output.hex

# Rules for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for linking the object files into the output file
$(OUTPUT): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(OUTPUT)

# Rule for generating the hex file from the output file
output.hex: $(OUTPUT)
	$(OBJCOPY) $(OUTPUT) output.hex

# clean
clean:
	rm -f $(OBJS) $(OUTPUT) output.hex

.PHONY: all clean

all: build

clean:
	rm -f $(OBJS) $(OUTPUT) output.hex
