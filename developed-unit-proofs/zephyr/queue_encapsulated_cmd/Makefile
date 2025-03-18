# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = /home/tlelievr/zephyrproject/zephyr

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/usb/device/class/netusb/function_rndis.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --verbosity 9

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_RNDIS_INTERRUPT_EP_MPS=16 -DCONFIG_USB_DEVICE_MANUFACTURER='"ZEPHYR"' -DCONFIG_USB_DEVICE_VID='0x8087' -DCONFIG_RNDIS_BULK_EP_MPS=64 -DCONFIG_USB_REQUEST_BUFFER_SIZE=2048

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/include \
	-I$(ROOT)/subsys/usb/device \
	-I$(ROOT)/subsys/usb/ \
	-I$(ROOT)/subsys/usb/device/class/netusb/ \
	-Ibuild/zephyr/include/generated

# Include our special build file
include ./Makefile.include
