# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/bluetooth/host/gatt.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --verbosity 9 --unwindset gatt_find_info_rsp.12:2

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_BT_ID_MAX=62 -DCONFIG_BT_MAX_CONN=62 -DCONFIG_BT_GATT_CLIENT=1 -DCONFIG_BT_MAX_PAIRED=62 -DCONFIG_BT_BUF_ACL_RX_SIZE=255 -DCONFIG_BT_L2CAP_TX_MTU=247

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/subsys/bluetooth \
	-I$(ROOT)/subsys/bluetooth/controller/include \
	-I$(ROOT)/subsys/bluetooth/shell \
	-I$(ROOT)/subsys/bluetooth/controller/ll_sw \
	-I$(ROOT)/subsys/bluetooth/controller/ll_sw/nordic \
	-I$(ROOT)/subsys/bluetooth/controller \
	-I$(ROOT)/include \
	-Ibuild/zephyr/include/generated

# Include our special build file
MAKE_INCLUDE_PATH ?= .
include $(MAKE_INCLUDE_PATH)/Makefile.include
