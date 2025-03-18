# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..
# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = #$(ROOT)/subsys/bluetooth/mesh/pb_adv.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1 --unwindset send_unacked.0:3 

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_BT_MESH_USES_TINYCRYPT=y -DCONFIG_BT_MESH_PB_ADV_RETRANS_TIMEOUT=500 -DCONFIG_BT_MESH_PB_ADV_TRANS_ACK_RETRANSMIT_COUNT=1 -DCONFIG_BT_MESH_PB_ADV_TRANS_PDU_RETRANSMIT_COUNT=1 -DCONFIG_BT_MESH_PB_ADV_LINK_CLOSE_RETRANSMIT_COUNT=1 -DCONFIG_BT_MESH=y

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/subsys/bluetooth/mesh \
	-I$(ROOT)/subsys/bluetooth \
	-I$(ROOT)/include \
	-Ibuild/zephyr/include/generated

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
