#############################################################################
# Author: Wen Li
# Date  : 3/31/2020
# Description: makefile for entry of module of project
##############################################################################

export NDDSHOME := "/opt/rti_connext_dds-6.0.1"
export TARGET_ARCH = x64Linux2.6gcc4.4.5

ifndef COMPILER
export COMPILER = g++
endif

export COMPILER_FLAGS = -m64

ifndef LINKER
export LINKER = g++
endif

export LINKER_FLAGS = -m64 -static-libgcc
export SYSLIBS = -ldl -lm -lpthread -lrt
export DEFINES = -DRTI_UNIX -DRTI_LINUX -DRTI_64BIT 

ifndef DEBUG
DEBUG=0 
endif

export COMPILER_FLAGS += -g -O0
export LINKER_FLAGS += -g
export DEBUG_SFX = d
 
ifndef SHAREDLIB
export SHAREDLIB=0
endif

ifeq ($(SHAREDLIB),1)
export SHAREDLIB_SFX = 
else
export SHAREDLIB_SFX = z
export DEFINES += -DRTI_STATIC
endif

export ROOT_PATH = $(PWD)
export BIN_PATH   = $(ROOT_PATH)/bin
export LIB_PATH  = $(ROOT_PATH)/lib
export OBJ_PATH  = $(ROOT_PATH)/obj

export INCLUDES = -I. -I$(NDDSHOME)/include -I$(NDDSHOME)/include/ndds      
export LIBS = $(SYSLIBS)\
              -L$(NDDSHOME)/lib/$(TARGET_ARCH) -lnddscpp$(SHAREDLIB_SFX)$(DEBUG_SFX)\
              -lnddsc$(SHAREDLIB_SFX)$(DEBUG_SFX) -lnddscore$(SHAREDLIB_SFX)$(DEBUG_SFX)\

SUBDIRS = message vehicle passanger operator

$(SUBDIRS):init
	for subdir in $(SUBDIRS);\
	do $(MAKE) -C $$subdir;\
	done

init:
	@if [ ! -d $(LIB_PATH) ]; then	mkdir $(LIB_PATH); fi
	@echo begin compile $(PWD)

.PHONY : clean
clean:
	for subdir in $(SUBDIRS);\
	do $(MAKE) -C $$subdir clean;\
	done
	@rm -rf lib