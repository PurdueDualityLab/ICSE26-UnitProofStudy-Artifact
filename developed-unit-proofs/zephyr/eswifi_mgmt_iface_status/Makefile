# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/drivers/wifi/eswifi/eswifi_core.c # $(ROOT)/lib/libc/common/source/string/strnlen.c $(ROOT)/subsys/net/l2/wifi/wifi_mgmt.c $(ROOT)/subsys/net/ip/net_mgmt.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1 \
--unwindset strlen.0:20 --unwindset strncmp.0:20 \
--unwindset eswifi_at_cmd_rsp.9:2 --unwindset strtol.0:20 \
--unwindset strncpy.0:20 

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_WIFI_ESWIFI_MAX_DATA_SIZE=500

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/include \
	-I$(ROOT)/drivers \
	-Ibuild/zephyr/include/generated

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
