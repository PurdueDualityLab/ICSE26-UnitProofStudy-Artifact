# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/bluetooth/controller/ll_sw/ull_adv.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_BT_PERIPHERAL=n -DCONFIG_BT_BROADCASTER=1 -DCONFIG_BT_CONN=1 -DCONFIG_BT_MAX_CONN=1 -DCONFIG_BT_CTLR_LLL_PRIO=1 -DCONFIG_BT_CTLR_ULL_LOW_PRIO=1 -DCONFIG_BT_CTLR_COMPANY_ID=0x05F1 -DCONFIG_BT_CTLR_SUBVERSION_NUMBER=0xFFFF
# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/subsys/bluetooth/controller/ll_sw \
	-I$(ROOT)/subsys/bluetooth/controller/include \
	-I$(ROOT)/subsys/bluetooth \
	-I$(ROOT)/subsys/bluetooth/controller \
	-I$(ROOT)/subsys/bluetooth/controller/util \
	-I$(ROOT)/subsys/bluetooth/controller/hal \
	-I$(ROOT)/include \
	-I$(ROOT)/tests/bluetooth/controller/mock_ctrl/include \
	-I$(ROOT)/subsys/bluetooth/controller/ll_sw/openisa \
	-Ibuild/zephyr/include/generated

BOARD = native_posix

# Include our special build file
MAKE_INCLUDE_PATH ?= .
include $(MAKE_INCLUDE_PATH)/Makefile.include