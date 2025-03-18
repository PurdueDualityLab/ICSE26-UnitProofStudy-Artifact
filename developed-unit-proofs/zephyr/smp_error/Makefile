# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/bluetooth/host/smp.c \
 $(ROOT)/subsys/net/buf_simple.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_BT_ID_MAX=4 -DCONFIG_BT_MAX_CONN=10 -DCONFIG_BT_SMP=1 -DCONFIG_BT_CONN_TX_USER_DATA_SIZE=50

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/subsys/bluetooth \
	-I$(ROOT)/subsys/bluetooth/controller/include \
	-I$(ROOT)/subsys/bluetooth/shell \
	-I$(ROOT)/subsys/bluetooth/controller \
	-I$(ROOT)/subsys/bluetooth/host \
	-I$(ROOT)/include/zephyr/bluetooth \
	-I$(ROOT)/include/zephyr/sys \
	-I$(ROOT)/include \
	-Ibuild/zephyr/include/generated

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
