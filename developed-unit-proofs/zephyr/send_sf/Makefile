# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = ${ROOT}/subsys/canbus/isotp/isotp.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1  --unwindset net_buf_frags_len.0:2

# Extra header defintiions to be passed during compilation
H_DEF = $(shell sed -e 's/^/-D/' -e 's/=y/=1/' -e 's/="/ "/' prj.conf)

# Extra CBMC includes to be passed during compilation
H_INC = \
	-I$(ROOT)/include \
	-I$(ROOT)/subsys/net/ip \
	-I$(ROOT)/subsys/canbus/isotp \
	-I$(ROOT)/include \

BOARD=native_posix

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
