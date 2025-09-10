# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/net/lib/shell/pkt.c # ${ROOT}/zephyr/subsys/net/l2/ieee802154/ieee802154_frame.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1 --unwindset net_pkt_buffer_info.5:2 --unwindset net_pkt_buffer_hexdump.2:2

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_NET_CONTEXT_NET_PKT_POOL=1

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/include \
	-I$(ROOT)/subsys/net/ip \
	-I$(ROOT)/subsys/net/lib/shell \
	-I$(ROOT)/lib/utils \
	-I$(ROOT)/subsys/shell \
	-I$(ROOT)/include \
	-Ibuild/zephyr/include/generated

BOARD = native_posix 

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
