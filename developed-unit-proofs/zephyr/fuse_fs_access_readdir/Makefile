# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/subsys/fs/fuse_fs_access.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1 \
	 --unwindset strcmp.0:21 --unwindset strlen.0:21 

# Extra header defintiions to be passed during compilation
H_DEF = -DFUSE_USE_VERSION=30 -D_FILE_OFFSET_BITS=64 -DHAVE_IOVEC=1

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem /usr/include \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/boards/native/native_posix \
	-I$(ROOT)/include \
	-Ibuild/zephyr/include/generated

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
