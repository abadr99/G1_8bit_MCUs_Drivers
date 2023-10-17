CC:= avr-gcc
MCU:= atmega32a
CLK:= 8000000
MAIN_DIR:= ../../../
CCFLAGS:= -g -Wall -DF_CPU=$(CLK) -mmcu=$(MCU) -gdwarf-2 -DMCU_TYPE=1 -O1

TARGET := $(shell basename "$$(pwd)")
OBJS:= $(shell find $(MAIN_DIR) -type f -name *.o)

ELF_TARGET:=$(TARGET).testelf

.PHONY: all clean build 

all:build

build-avr:
	@make -C ../../../ build 
	
build:
	@echo "TARGET = $(TARGET)"	
	@rm -rf *.testelf
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
