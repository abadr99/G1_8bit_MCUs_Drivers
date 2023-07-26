CC:= avr-gcc
MCU:= atmega32a
CLK:= 8000000

CCFLAGS:= -g -Wall -DF_CPU=$(CLK) -mmcu=$(MCU) -gdwarf-2 -DMCU_TYPE=1 -O3 -Werror
 

TARGET:= avr

DIRS := $(shell cat ./build.dir)
SRC_PATH :=  $(foreach dir,$(DIRS),$(dir)) 
SOURCES  :=  $(foreach S,$(SRC_PATH),$(wildcard $(S)/*.c))
SOURCES_COUNT:= $(words $(SOURCES))
SOURCES_CTR:=0
SOURCES += ./main.c
INC:=  $(foreach dir,$(DIRS), -I$(dir))
OBJS:= $(SOURCES:.c=.o)

# Hex file
HEX_TARGET:= $(TARGET).hex
ELF_TARGET:=$(TARGET).elf
# AVRDUDE options
AVRDUDE = avrdude
AVRDUDE_PROGRAMMER = usbasp
AVRDUDE_MCU = m32
AVRDUDE_PORT = /dev/ACM0


.PHONY: all clean build 

all:build

build: $(OBJS)
	@$(CC) $(CCFLAGS) $(OBJS) -o $(ELF_TARGET)
	@avr-objcopy -j .text -j .data -O ihex $(ELF_TARGET) $(HEX_TARGET)
	@echo "\n[Makefile] : Compiled successfully."

%.o : %.c
	@$(CC) $(CCFLAGS) $(INC) -c $< -o $@
	@$(eval SOURCES_CTR=$(shell echo $$(($(SOURCES_CTR)+1))))
	@printf '\033[2K\r%s' "[Makefile] : [$(SOURCES_CTR)/$(words $(SOURCES))] $<"

upload: $(HEX)
	@$(AVRDUDE) -c $(AVRDUDE_PROGRAMMER) -p $(AVRDUDE_MCU) -P $(AVRDUDE_PORT) -U flash:w:$(TARGET).hex:i
clean:
	@find . -name "*.o" -type f -delete
	@rm -rf *.o
	@rm -rf *.bin
	@rm -rf *.exe
	@rm -rf *.elf
	@rm -rf *.hex
	@rm -rf avr
