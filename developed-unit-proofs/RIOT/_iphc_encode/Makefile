# Defines the root of the project.
# Be aware of how many directories deep you go!
ROOT ?= ../../..

# Defines file(s) to link to harness, MUST be a full path!
# (We recommend $(ROOT)/os/... for defining these paths)
# Each file is space seperated, and multiple can be defined
LINK = $(ROOT)/sys/net/gnrc/network_layer/sixlowpan/iphc/gnrc_sixlowpan_iphc.c # $(ROOT)/sys/net/gnrc/pktbuf_malloc/gnrc_pktbuf_malloc.c $(ROOT)/sys/net/gnrc/pktbuf/gnrc_pktbuf.c $(ROOT)/sys/net/gnrc/network_layer/sixlowpan/ctx/gnrc_sixlowpan_ctx.c

# Harness to utilize, omit the extension!
H_ENTRY = _iphc_encode

# Extra CBMC flags to be passed during CBMC analysis
H_CBMCFLAGS = --nondet-static --unwind 1 # --unwindset harness.0:11 --unwindset gnrc_pktbuf_release_error.1:10 --unwindset gnrc_sixlowpan_ctx_lookup_addr.0:17 --unwindset memcmp.0:17


H_DEF = -DMODULE_GNRC_IPV6=1 -DMODULE_GNRC_NETTYPE_IPV6=1 -DMODULE_GNRC_NETTYPE_SIXLOWPAN=1 -DMODULE_GNRC_NETIF_IPV6=1 -DMODULE_GNRC_SIXLOWPAN_IPHC_NHC=1
#-DMODULE_GNRC_NETIF_IPV6=1

H_INC = -I$(ROOT) -I$(ROOT)/sys/include/  \
            -I$(ROOT)/core/lib/include/  \
            -I$(ROOT)/core/include/  \
            -I$(ROOT)/cpu/native/include/  \
            -I$(ROOT)/drivers/include/  \
            -I$(ROOT)/boards/native/include/  \
            -I$(ROOT)/sys/net/gnrc/pktbuf/include  \

# Include our special build file
MAKE_INCLUDE_PATH ?= ..
include $(MAKE_INCLUDE_PATH)/Makefile.include
