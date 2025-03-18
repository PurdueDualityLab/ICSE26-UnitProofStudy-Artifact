# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/net/lib/lwm2m/lwm2m_rw_oma_tlv.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --unwind 1

# Extra header defintiions to be passed during compilation
H_DEF = 

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/subsys/net/lib/lwm2m \
	-I$(ROOT)/subsys/net/lib \
	-I$(ROOT)/subsys/net \
	-I$(ROOT)/include \
	-Ibuild/zephyr/include/generated

# Include our special build file
MAKE_INCLUDE_PATH ?= .
include $(MAKE_INCLUDE_PATH)/Makefile.include
