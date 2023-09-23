CC:= avr-gcc
MCU:= atmega32a
CLK:= 8000000

CCFLAGS:= -g -Wall -DF_CPU=$(CLK) -mmcu=$(MCU) -gdwarf-2 -DMCU_TYPE=1 -O1

TARGET:= utils-test

DIRS := $(shell find ../../.. -maxdepth 5 -type d | grep -E '\./hal/|\./common|\./mcal/')
SRC_PATH :=  $(foreach dir,$(DIRS),$(dir)) 
SOURCES  :=  $(foreach S,$(SRC_PATH),$(wildcard $(S)/*.c)) 
SOURCES_COUNT:= $(words $(SOURCES))
SOURCES_CTR:=0
INC:=  $(foreach dir,$(DIRS), -I$(dir))
OBJS:= $(SOURCES:.c=.o)

ELF_TARGET:=$(TARGET).elf

.PHONY: all clean build 

all:build

build-avr:
	make -C ../../../ build 
	
build: $(OBJS)
	$(CC) $(CCFLAGS) ./main.c $(OBJS) -o $(ELF_TARGET)
	@echo "\n[Makefile] : Compiled successfully."

clean:
	@find . -name "*.o" -type f -delete
	@rm -rf *.o
	@rm -rf *.bin
	@rm -rf *.exe
	@rm -rf *.elf
	@rm -rf *.hex
	@rm -rf avr
