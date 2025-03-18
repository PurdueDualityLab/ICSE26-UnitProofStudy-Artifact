# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/net/buf_simple.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1 --unwindset memcmp.0:7

# Extra header defintiions to be passed during compilation
H_DEF =

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/include \
	-I$(ROOT)/subsys/bluetooth/controller/hci \
	-I$(ROOT)/subsys/bluetooth \
	-I$(ROOT)/subsys/bluetooth/controller \
	-I$(ROOT)/subsys/bluetooth/controller/ll_sw/nordic \
	-I$(ROOT)/subsys/bluetooth/controller/include \
	-I$(ROOT)/subsys/bluetooth/controller/ll_sw/nordic/hci \
	-I$(ROOT)/subsys/bluetooth/controller/ll_sw/ \
	-I$(ROOT)/boards/native/native_posix \
	-I$(ROOT)/include \
	-I. \
	-I/usr/include \
	-Ibuild/zephyr/include/generated \
	# -I$(ROOT)/zephyr/subsys/bluetooth/controller \
	# -I$(ROOT)/modules/hal/nordic/nrfx \
	# -I$(ROOT)/zephyr/modules/hal_nordic/nrfx \
	# -I$(ROOT)/modules/hal/nordic/nrfx/mdk \
	# -I$(ROOT)/zephyr/subsys/bluetooth/controller/ll_sw \



BOARD = nrf51_ble400

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include