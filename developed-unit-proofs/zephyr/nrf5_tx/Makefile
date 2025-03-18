# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/drivers/ieee802154/ieee802154_nrf5.c # $(ROOT)/subsys/net/ip/net_pkt.c
# $(ROOT)/subsys/net/ip/net_pkt.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_BT_CTLR_COMPANY_ID=0x5F1 -DCONFIG_BT_CTLR_SUBVERSION_NUMBER=0xFFFF -DNET_PKT_HAS_CONTROL_BLOCK=1 -DCONFIG_IEEE802154=1 -DCONFIG_IEEE802154_NRF5_FCS_IN_LENGTH=1

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/include \
	-I$(ROOT)/drivers \
	-Ibuild/zephyr/include/generated

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
