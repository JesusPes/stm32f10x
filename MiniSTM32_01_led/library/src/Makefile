# Makefile to create the STM32F10x cortex-M3 Library 
# by Qibo Zhang (Michael) China
#
# mail: sudazqb@163.com
# MSN: zhangqibo_1985@hotmail.com
#DATE:2007-12-19
#
# modifyied from Martin Thomas's luminary makefile
#

# using the Codesourcery Q1-2007 ARM-Toolchain

TCHAIN = arm-none-eabi

CPU = cortex-m3

# library-filename will be libstm32f10x.a
TARGET = stm32f10x

# C-Sources
SRC  = $(TARGET)_adc.c  $(TARGET)_bkp.c   $(TARGET)_can.c  $(TARGET)_dma.c 
SRC += $(TARGET)_exti.c $(TARGET)_flash.c $(TARGET)_gpio.c $(TARGET)_i2c.c
SRC += $(TARGET)_iwdg.c $(TARGET)_lib.c   $(TARGET)_nvic.c $(TARGET)_pwr.c 
SRC += $(TARGET)_rcc.c  $(TARGET)_rtc.c   $(TARGET)_spi.c  $(TARGET)_systick.c
SRC += $(TARGET)_tim1.c $(TARGET)_tim.c   $(TARGET)_usart.c $(TARGET)_wwdg.c
# Assembler-Sources
#ASRC = cpu.S
ASRC =


OPT = s
DEBUG = dwarf-2

#include file path
EXTRAINCDIRS = ../inc
EXTRAINCDIRS += ../../project

CSTANDARD = -std=gnu99
CDEFS = -DBUILD_ALL

CFLAGS = -g$(DEBUG)
CFLAGS += $(CDEFS)
CFLAGS += -O$(OPT)
CFLAGS += -Wall
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wa,-adhlns=$(<:%.c=%.lst)
CFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS))
CFLAGS += $(CSTANDARD)
# prepare for using GCC 4 unused code removal
CFLAGS += -ffunction-sections -fdata-sections
# must be thumb for cortex-m3
CFLAGS += -mthumb

ASFLAGS = -Wa,-adhlns=$(<:%.S=%.lst),-g$(DEBUG)
# must be thumb for cortex-m3
ASFLAGS += -mthumb -Dgcc -DBUILD_ALL

SHELL = sh
CC = $(TCHAIN)-gcc
AR = $(TCHAIN)-ar

#OBJCOPY = $(TCHAIN)-objcopy
#OBJDUMP = $(TCHAIN)-objdump
#SIZE = $(TCHAIN)-size
#NM = $(TCHAIN)-nm

REMOVE = rm -f
REMOVEDIR = rm -rf

# Define all object files.
OBJ = $(SRC:%.c=%.o) $(ASRC:%.S=%.o) 

# Define all listing files.
LST = $(SRC:%.c=%.lst) $(ASRC:%.S=%.lst) 

# Combine all necessary flags and optional flags.
# Add target processor to flags.
ALL_CFLAGS = -mcpu=$(CPU) -I. $(CFLAGS) $(GENDEPFLAGS)
ALL_ASFLAGS = -mcpu=$(CPU) -I. -x assembler-with-cpp $(ASFLAGS)

# target for make all -> just create go to target lib
all: lib

%.o : %.c
	$(CC) -c $(ALL_CFLAGS) $< -o $@ 

%.o : %.S
	$(CC) -c $(ALL_ASFLAGS) $< -o $@
	
lib: $(OBJ)
	$(AR) rcs ../../project/lib$(TARGET).a $(OBJ)

# Target: clean project.
clean :
	$(REMOVE) $(SRC:.c=.s)
	$(REMOVE) $(SRC:.c=.d)
	$(REMOVE) $(OBJ)
	$(REMOVE) $(LST)
	$(REMOVE) ../lib$(TARGET).a
	$(REMOVEDIR) .dep


# Create object files directory
# $(shell mkdir $(OBJDIR) 2>/dev/null)


# Include the dependency files.
-include $(shell mkdir .dep 2>/dev/null) $(wildcard .dep/*)


# Listing of phony targets.
.PHONY : all build clean lib
