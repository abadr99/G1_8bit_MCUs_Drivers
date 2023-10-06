CC:= avr-gcc
MCU:= atmega32a
CLK:= 8000000

CCFLAGS:= -g -Wall -DF_CPU=$(CLK) -mmcu=$(MCU) -gdwarf-2 -DMCU_TYPE=1 -O2 -Werror -Wno-cpp
OPT_CCFLAGS:= -g -Wall -DF_CPU=$(CLK) -mmcu=$(MCU) -gdwarf-2 -DMCU_TYPE=1 -O3 -Werror

TARGET:= avr

#DIRS := $(shell cat ./build.dir)
DIRS := $(shell find . -maxdepth 5 -type d | grep -E '\./hal/|\./common|\./mcal/')
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
STYLE_CHECK_SCRIPT = ./scripts/style-checking/style-check.sh

# ---- DOXYGEN OPTIONS
DOXYGEN_SCRIPT = ../scripts/doxygen/doxygen.sh
TREAT_WARN_AS_ERROR = YES
TREAT_WARN_AS_WARN = NO
DOXYGEN_CONFIG = ./doxygen.cnf

# ---- TESTING 
REGRESSION_TEST_SCRIPT = ../scripts/testing/run-regressions.sh

.PHONY: all clean build 

all:build style-check
	@echo -n "[Doxygen] : "
	@sh $(DOXYGEN_SCRIPT) $(DOXYGEN_CONFIG) $(TREAT_WARN_AS_WARN)

build: $(OBJS)
	@$(CC) $(CCFLAGS) $(OBJS) -o $(ELF_TARGET)
	@avr-objcopy -j .text -j .data -O ihex $(ELF_TARGET) $(HEX_TARGET)
	@echo "\n[Makefile][build] : Compiled successfully."

opt-build:
	@$(CC) $(OPT_CCFLAGS) $(OBJS) -o $(ELF_TARGET)
	@avr-objcopy -j .text -j .data -O ihex $(ELF_TARGET) $(HEX_TARGET)
	@echo "\n[Makefile][opt-build] : Compiled successfully."	

run-regressions:
	@echo -n "[Regression-tests] : Run Regressions\n"
	@echo $(REGRESSION_TEST_SCRIPT)
	sh $(REGRESSION_TEST_SCRIPT) $(filter) 
	@echo "\n[Makefile][Regression-Testing] : Tests have been run successfully."
style-check:
	@echo -n "[Style-check] : "
	@sh $(STYLE_CHECK_SCRIPT) . ../scripts/style-checking/rules-scripts

doxygen:
	@echo -n "[Doxygen] : "
	@sh $(DOXYGEN_SCRIPT) $(DOXYGEN_CONFIG) $(TREAT_WARN_AS_ERROR)

%.o : %.c
	@$(CC) $(CCFLAGS) $(INC) -c $< -o $@
	@$(eval SOURCES_CTR=$(shell echo $$(($(SOURCES_CTR)+1))))
	@echo "[Makefile] : [$(SOURCES_CTR)/$(words $(SOURCES))] $<"

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
help:
	@echo "make build                		  		  : Build and generate elf and hex files (for debugging and development mode)"
	@echo "make opt-build            		  		  : Build and generate elf and hex files (for release mode)"
	@echo "make style-check          		  		  : Run vera rules and check if code follow our coding style"
	@echo "make doxygen              		  		  : Run doxygen and generate html file"
	@echo "make upload               		  		  : Upload hex file for target"
	@echo "make clean                		  		  : Clean generated files"
	@echo "make run-regression filter=all   		  : Run all regression test"
	@echo "make run-regression filter=elf/path/dir    : Run specific regression test"
	@echo "NOTE                      		  		  : For issues related to doxygen contact @ManarAbdelraouf"
	@echo "                          		  		  : For issues related to style-check contact @MohamedRefat13"
	@echo "                          		  		  : For issues related to build contact @AbdelrahmanBadr22"





