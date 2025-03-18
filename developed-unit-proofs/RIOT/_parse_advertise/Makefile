# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/application_layer/dhcpv6/client.c

# Harness to utilize, omit the extension!
H_ENTRY = _parse_advertise

# Extra CBMC flags to be passed during CBMC analysis
# H_CBMCFLAGS = --nondet-static --unwind 1 --unwindset _preparse_advertise.3:5 --unwindset _parse_advertise.10:5 --unwindset memcmp.0:45 --unwindset _parse_advertise.4:5 --unwindset _parse_advertise.8:5 --unwindset _parse_advertise.3:5 --unwindset _parse_advertise.7:5 --unwindset _parse_advertise.10:5
H_CBMCFLAGS = --nondet-static --unwindset _parse_advertise.3:2 --unwindset _parse_advertise.7:2 --unwindset _parse_advertise.10:2


H_DEF = -DSOCK_HAS_IPV6=1 -DMODULE_DHCPV6_CLIENT_IA_PD=1 -DMODULE_DHCPV6_CLIENT_IA_NA=1 -DENABLE_DEBUG=1

H_INC = -I$(ROOT) -I$(ROOT)/sys/include/  \
            -I$(ROOT)/core/lib/include/  \
            -I$(ROOT)/core/include/  \
            -I$(ROOT)/cpu/native/include/  \
            -I$(ROOT)/drivers/include/  \
            -I$(ROOT)/boards/native/include/  \
            -I$(ROOT)/sys/net/gnrc/sock/include/ \
            -I$(ROOT)/sys/net/application_layer/dhcpv6/ \

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
