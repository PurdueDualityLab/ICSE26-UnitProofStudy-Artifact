# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/net/l2/ieee802154/ieee802154.c $(ROOT)/subsys/net/l2/ieee802154/ieee802154_frame.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --verbosity 9  \
--unwindset net_buf_frags_len.0:2 --unwindset sys_memcpy_swap.0:9 \
--unwindset memcmp.0:9 --unwindset sys_mem_swap.0:5

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_LITTLE_ENDIAN=n  

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/subsys/net \
	-I$(ROOT)/subsys/net/l2 \
	-I$(ROOT)/subsys/net/l2/ieee802154 \
	-I$(ROOT)/include \
	-Ibuild/zephyr/include/generated

# Include our special build file
MAKE_INCLUDE_PATH ?= .
include $(MAKE_INCLUDE_PATH)/Makefile.include
