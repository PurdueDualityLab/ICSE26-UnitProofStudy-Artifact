# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = ${ROOT}/drivers/usb/device/usb_dc_native_posix.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_ARCH_POSIX_RECOMMENDED_STACK_SIZE=500

# Extra CBMC includes to be passed during compilation
H_INC = \
	-I$(ROOT)/include \
	-I$(ROOT)/subsys/net/ip \
	-I$(ROOT)/drivers/usb/device \
	-I$(ROOT)/soc/ite/ec/common \
	-I$(ROOT)/lib/libc/minimal/include/ \

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
