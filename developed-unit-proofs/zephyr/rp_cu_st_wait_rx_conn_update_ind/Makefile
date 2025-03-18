# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/bluetooth/controller/ll_sw/ull_llcp_conn_upd.c \
 $(ROOT)/subsys/bluetooth/controller/ll_sw/ull_conn.c \
 $(ROOT)/subsys/bluetooth/controller/ll_sw/ull_llcp_pdu.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --verbosity 9 --nondet-static --unwind 1

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_BT_CTLR_COMPANY_ID=0x5F1 -DCONFIG_BT_CTLR_SUBVERSION_NUMBER=0xFFFF -DCONFIG_BT_BUF_ACL_TX_COUNT=1 \
		 -DCONFIG_BT_CTLR_LLCP_TX_PER_CONN_TX_CTRL_BUF_NUM_MAX=1 -DCONFIG_BT_CTLR_LLCP_CONN=1 -DCONFIG_BT_CTLR_LLCP_COMMON_TX_CTRL_BUF_NUM=1 \
		 -DCONFIG_BT_BUF_ACL_TX_SIZE=100 -DCONFIG_BT_MAX_CONN=1 -DTICKER_ID_CONN_BASE=1 \
		 -DCONFIG_BT_CTLR_LOW_LAT=1

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
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
