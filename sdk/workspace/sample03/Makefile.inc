mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=

APPL_CXXOBJS += \
util.o \
Tracer.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif

APPL_DIRS += $(mkfile_path)app $(mkfile_path)unit


INCLUDES += \
	-I$(mkfile_path)app \
	-I$(mkfile_path)unit

#COPTS += -fno-use-cxa-atexit
