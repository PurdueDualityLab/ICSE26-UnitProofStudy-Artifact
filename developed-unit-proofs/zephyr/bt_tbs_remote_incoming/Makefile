# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = \
	$(ROOT)/subsys/bluetooth/audio/tbs.c \

# Harness to utilize, omit the extension!
H_ENTRY = main

# Extra CBMC flags to be passed during CBMC analysis
# Added additional unwinding to increase coverage at different locations
H_CBMCFLAGS = --nondet-static --verbosity 9 --unwind 1 \
	--unwindset lookup_call_in_inst.0:3 --unwindset next_free_call_index.0:3 --unwindset lookup_call.0:3 \
	--unwindset  call_alloc.0:3 --unwindset  net_buf_put_call_states_by_inst.0:3 \
	--unwindset net_buf_put_current_calls_by_inst.0:3 --unwindset net_buf_put_call_states.0:3 \
	--unwindset net_buf_put_current_calls.0:3  --unwindset strlen.0:11

# Extra header defintiions to be passed during compilation
H_DEF = \
	-DCONFIG_BT_TBS_BEARER_COUNT=1 \
	-DCONFIG_BT_TBS_MAX_URI_LENGTH=10 \
	-DCONFIG_BT_TBS_MAX_PROVIDER_NAME_LENGTH=512 \
	-DCONFIG_BT_TBS_MAX_SCHEME_LIST_LENGTH=512 \
	-DCONFIG_BT_TBS_MAX_SERVICE_NAME_LENGTH=512 \
	-DCONFIG_BT_TBS_MAX_SCHEME_LIST_LENGTH=512 \
	-DCONFIG_BT_TBS_MAX_CALLS=2 \
	-DCONFIG_BT_TBS_UCI=1 \
	-DCONFIG_BT_TBS_SUPPORTED_FEATURES=1 \
	-DCONFIG_BT_TBS_TECHNOLOGY=1 \
	-DCONFIG_BT_TBS_SIGNAL_STRENGTH_INTERVAL=0\
	-DCONFIG_BT_TBS_STATUS_FLAGS=1 \
	-DCONFIG_BT_TBS_PROVIDER_NAME=1 \
	-DCONFIG_BT_TBS_URI_SCHEMES_LIST=1 \
	-DCONFIG_BT_GTBS=1 \

# Extra CBMC includes to be passed during compilation

H_INC = \
	-I$(ROOT)/include \
	-I$(ROOT)/subsys/bluetooth/audio \
	-I$(ROOT)/include/zephyr/bluetooth/audio \

BOARD = native_posix

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
