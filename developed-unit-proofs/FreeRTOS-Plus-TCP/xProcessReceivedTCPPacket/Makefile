# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/source/FreeRTOS_TCP_IP.c

# Harness to utilize, omit the extension!
H_ENTRY = xProcessReceivedTCPPacket

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1


H_DEF = -DipconfigUSE_TCP_WIN=0

H_INC = -I$(ROOT) -I../include/ -I$(ROOT)/sys/include/  \
        -I$(ROOT)/test/FreeRTOS-Kernel/include \
        -I$(ROOT)/source/include \
		-I$(ROOT)/test/cbmc/patches \
		-I$(ROOT)/test/FreeRTOS-Kernel/portable/ThirdParty/GCC/Posix \
		-I$(ROOT)/source/portable/Compiler/GCC \

ENABLE_BUILD = 0
# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include