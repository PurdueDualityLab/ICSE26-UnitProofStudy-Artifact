# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/application_layer/asymcute/asymcute.c #$(ROOT)/sys/event/timeout_ztimer.c

# Harness to utilize, omit the extension!
H_ENTRY = _on_regack

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset _req_preprocess.0:2

H_DEF = -DRIOT_VERSION=1 -DMODULE_SOCK_UDP=y -DSOCK_HAS_IPV6=y -DMODULE_GNRC_NETIF_IPV6=1 -DSOCK_HAS_ASYNC=1 -DMODULE_GNRC_NETAPI_CALLBACKS=1

H_INC = -I$(ROOT) -I$(ROOT)/sys/include/  \
            -I$(ROOT)/core/lib/include/  \
            -I$(ROOT)/core/include/  \
            -I$(ROOT)/cpu/native/include/  \
            -I$(ROOT)/drivers/include/  \
            -I$(ROOT)/boards/native/include/  \
            -I$(ROOT)/sys/net/gnrc/sock/include \            

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
