# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = /home/pamusuo/research/cbmc-research/zephyrproject/zephyr

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/usb/device/class/dfu/usb_dfu.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static 

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_IMG_BLOCK_BUF_SIZE=512 -DCONFIG_USB_REQUEST_BUFFER_SIZE=300 -DCONFIG_USB_DFU_DETACH_TIMEOUT=10000 -DCONFIG_USB_DEVICE_VID=0x2FE9 \
		 -DCONFIG_USB_DEVICE_DFU_PID=0 -DCONFIG_USB_MAX_POWER=50 -DCONFIG_USB_DEVICE_MANUFACTURER=123 -DCONFIG_USB_DEVICE_PRODUCT=20 -DCONFIG_USB_DEVICE_SN=43 \
		-DCONFIG_USB_DFU_DEFAULT_POLLTIMEOUT = 19000

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
	-I$(ROOT)/subsys/usb/device \
	-Ibuild/zephyr/include/generated

# Include our special build file
MAKE_INCLUDE_PATH ?= .
include $(MAKE_INCLUDE_PATH)/Makefile.include
