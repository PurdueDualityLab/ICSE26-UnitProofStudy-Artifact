# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT = ../../../../../..

# OBJ_BITS = 10

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/os/net/routing/rpl-classic/rpl-icmp6.c #$(ROOT)/os/net/ipv6/uipbuf.c $(ROOT)/os/net/packetbuf.c $(ROOT)/os/net/ipv6/uip6.c
#$(ROOT)/os/net/ipv6/uip6.c $(ROOT)/os/net/ipv6/uip-ds6-route.c $(ROOT)/os/lib/list.c $(ROOT)/os/net/nbr-table.c $(ROOT)/os/net/routing/rpl-classic/rpl-dag.c $(ROOT)/os/lib/memb.c $(ROOT)/os/net/ipv6/uip-ds6.c $(ROOT)/os/net/ipv6/uip-ds6-nbr.c
# Harness to utilize, omit the extension!
H_ENTRY = dis

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 #--malloc-may-fail --malloc-fail-null --unwindset dao_input_storing.14:20
# Extra header defintiions to be passed during compilation
H_DEF = \
	-D'$(MAC_DRIVER)=1' \
	-D'$(NET_DRIVER)=1' \
	-D'$(ROUTE_DRIVER)=1' \

# Extra CBMC includes to be passed during compilation
H_INC = 

NET_DRIVER ?= NETSTACK_CONF_WITH_IPV6
MAC_DRIVER ?= MAC_CONF_WITH_NULLMAC
ROUTE_DRIVER ?= ROUTING_CONF_RPL_LITE

C_INC = \
	-I$(ROOT)/os \
	-I$(ROOT)/arch/cpu/native \
	-I$(ROOT)/arch/platform/native \
	-I$(ROOT)/cbmc/include \
	# empty

# Include our special build file
MAKE_INCLUDE_PATH ?= ../../../..
include $(MAKE_INCLUDE_PATH)/Makefile.include
