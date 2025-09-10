# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/settings/src/settings_shell.c # $(ROOT)/lib/utils/hex.c $(ROOT)/subsys/settings/src/settings_store.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1 --unwindset harness.0:5 --unwindset strcmp.0:20 --unwindset strlen.0:20

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_SHELL_CMD_BUFF_SIZE=4

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/boards/native/native_posix \
	-I$(ROOT)/include \
	-I. \
	-I/usr/include \
	-Ibuild/zephyr/include/generated \
	-I$(ROOT)/lib/posix/options/getopt \

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
