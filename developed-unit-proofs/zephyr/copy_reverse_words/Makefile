# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/drivers/crypto/crypto_stm32.c

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1  --unwindset sys_mem_swap.0:3

# Extra header defintiions to be passed during compilation
H_DEF = -DCONFIG_CRYPTO_STM32_MAX_SESSION=1 

# Extra CBMC includes to be passed during compilation
H_INC = \
	-isystem $(ROOT)/lib/libc/minimal/include \
	-I$(ROOT)/drivers \
	-I$(ROOT)/drivers/crypto \
	-I$(ROOT)/include \
	-Ibuild/zephyr/include/generated

BOARD=mikroe_mini_m4_for_stm32

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
