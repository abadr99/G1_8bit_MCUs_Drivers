
DIRS := $(shell find . -maxdepth 5 -type d | grep -E '\./hal/|\./common|\./mcal/|\./utils/')
SRC_PATH :=  $(foreach dir,$(DIRS),$(dir)) 
SOURCES  :=  $(foreach S,$(SRC_PATH),$(wildcard $(S)/*.c))
SRC_NAMES:= $(notdir $(SOURCES))
SOURCES_COUNT:= $(words $(SOURCES))
SOURCES_CTR:=0
INC:=  $(foreach dir,$(DIRS), -I$(dir))

include avr.mk
include pic.mk


# ---- TESTING 
REGRESSION_TEST_SCRIPT = ../scripts/testing/run-regressions.sh
REGRESSION_ALL_TEST_SCRIPT = ../scripts/testing/run-all-regressions.sh

.PHONY: all clean build 


build-avr: $(AVR_OBJS)
	@$(AVR_GCC) $(AVR_GCCFLAGS) $(AVR_OBJS) ./main.c -o $(AVR_ELF_TARGET)
	@$(AVR_OBJ_COPY) $(AVR_OBJ_COPY_OPTS) $(AVR_ELF_TARGET) $(AVR_HEX_TARGET)
	@echo "\n[Makefile][build] : Compiled successfully."

build-avr-opt:$(AVR_OBJS)
	@$(AVR_GCC) $(AVR_OPT_CCFLAGS) $(AVR_OBJS) ./main.c -o $(AVR_ELF_TARGET)
	@$(AVR_OBJ_COPY) $(AVR_OBJ_COPY_OPTS) $(AVR_ELF_TARGET) $(AVR_HEX_TARGET)
	@echo "\n[Makefile][opt-build] : Compiled successfully."	

build-app: $(AVR_OBJS) $(AVR_OBJDIR)
	@$(AVR_GCC) $(AVR_GCCFLAGS) $(AVR_OBJS) $(wildcard $(path)/*.c) $(INC) -o $(path)/$(AVR_ELF_TARGET)
	@$(AVR_OBJ_COPY) $(AVR_OBJ_COPY_OPTS) $(path)/$(AVR_ELF_TARGET) $(path)/$(AVR_HEX_TARGET)
	@echo "\n[Makefile][build-app] : Compiled successfully."


clean:
	@find . -name "*.o" -type f -delete
	@rm -rf .build
	@rm -rf *.o
	@rm -rf *.bin
	@rm -rf *.exe
	@rm -rf *.elf
	@rm -rf *.hex
	@rm -rf avr
	@rm -rf .build
	@find app/* -name "*.hex" -type f -delete
	@find app/* -name "*.elf" -type f -delete



