# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/drivers/ipm/ipm_imx.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1 --unwindset imx_mu_ipm_send.0:2

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_SOC_MCIMX7D_M4=1 -DCONFIG_IPM_IMX_MAX_DATA_SIZE=4 -DCONFIG_IPM_IMX_MAX_ID_VAL=1 -DCONFIG_IPM_IMX_MAX_DATA_SIZE_4=1

# Extra CBMC includes to be passed during compilation

H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/boards/native/native_posix \
	-I$(ROOT)/include \
	-I. \
	-I/usr/include \
	-I$(ROOT)/subsys/net/ip \
	-I$(ROOT)/drivers/ipm \
	-I$(ROOT)/modules/hal/nxp/imx/drivers \
	-I$(ROOT)/modules/hal/nxp/imx/devices \
	-I$(ROOT)/modules/hal/nxp/imx/devices/MCIMX7D \
	-Ibuild/zephyr/include/generated \
	-I$(ROOT)/lib/posix/options/getopt \


BOARD = colibri_imx7d/mcimx7d/m4

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
