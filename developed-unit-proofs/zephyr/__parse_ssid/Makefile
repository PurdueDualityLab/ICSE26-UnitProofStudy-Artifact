# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/drivers/wifi/eswifi/eswifi_core.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwindset __parse_ssid.0:33

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_WIFI_ESWIFI_MAX_DATA_SIZE=64

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/driver/wifi/eswifi \
	-I$(ROOT)/driver/wifi \
	-I$(ROOT)/include/zephyr/arch \
	-I$(ROOT)/include/zephyr/kernel \
	-I$(ROOT)/include/zephyr/drivers \
	-I$(ROOT)/include/zephyr \
	-I$(ROOT)/include \
	-Ibuild/zephyr/include/generated

# Include our special build file
MAKE_INCLUDE_PATH ?= .
include $(MAKE_INCLUDE_PATH)/Makefile.include
