# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/bluetooth/host/hci_raw.c \
  $(ROOT)/cbmc/bt_buf_get_tx/buf_stub.c

# Harness to utilize, omit the extension!
H_ENTRY = btclass

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_BT_BUF_EVT_RX_COUNT=2 -DCONFIG_BT_BUF_ACL_RX_COUNT=2 -DCONFIG_BT_BUF_ACL_RX_SIZE=100 -DCONFIG_BT_BUF_EVT_RX_SIZE=100 -DCONFIG_BT_BUF_CMD_TX_COUNT=2 \
		-DCONFIG_BT_BUF_CMD_TX_SIZE=100 -DCONFIG_BT_BUF_ACL_TX_COUNT=2 -DCONFIG_BT_BUF_ACL_TX_SIZE=100 -DCONFIG_BT_BUF_EVT_TX_COUNT=2 -DCONFIG_BT_BUF_EVT_TX_SIZE=100 \
		-DCONFIG_BT_HCI_RAW_H4=1
		#-DCONFIG_NET_BUF_LOG='n'

# Extra CBMC includes to be passed during compilation
H_INC = -I$(ROOT)/subsys/usb/device \
		-I$(ROOT)/include \


C_INC = \
	-include $(ROOT)/cbmc/include/zephyr/autoconf.h \
	-I$(ROOT)/cbmc/include \
	-I$(ROOT)/include \
	-I$(ROOT)/boards/native/native_posix \
	# empty

ENABLE_BUILD = 0

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
