// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _rbuf_add function.
 */

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */

/**
 * @brief Starting point for formal analysis
 * 
 */

#include <stdlib.h>
#include <stdint.h>

// #include "net/gnrc/pkt.h"
// #include "net/gnrc/netif/hdr.h"

// #include "sys/net/gnrc/network_layer/sixlowpan/iphc/gnrc_sixlowpan_iphc.c"
// #include "sys/net/gnrc/network_layer/sixlowpan/frag/rb/gnrc_sixlowpan_frag_rb.c"

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>

#include "net/ieee802154.h"
#include "net/eui64.h"
#include "net/ipv6.h"
#include "net/ipv6/hdr.h"
#include "net/ipv6/addr.h"
#include "net/gnrc.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/sixlowpan.h"
#include "net/gnrc/sixlowpan/config.h"
#include "net/gnrc/sixlowpan/ctx.h"
#ifdef  MODULE_GNRC_SIXLOWPAN_FRAG_STATS
#include "net/gnrc/sixlowpan/frag/stats.h"
#endif  /* MODULE_GNRC_SIXLOWPAN_FRAG_STATS */
#include "net/gnrc/sixlowpan/frag/minfwd.h"
#include "net/gnrc/sixlowpan/frag/vrb.h"
#include "net/sixlowpan.h"
#include "net/sixlowpan/sfr.h"
#include "thread.h"
#include "xtimer.h"
#include "utlist.h"
#include "net/gnrc/nettype.h"

#include "net/gnrc/sixlowpan/frag/rb.h"


gnrc_sixlowpan_ctx_t *gnrc_sixlowpan_ctx_lookup_id(uint8_t id) {
    gnrc_sixlowpan_ctx_t* context = malloc(sizeof(gnrc_sixlowpan_ctx_t));
    return context;
}

gnrc_pktsnip_t *gnrc_pktsnip_search_type(gnrc_pktsnip_t *pkt,
                                         gnrc_nettype_t type) {
    gnrc_pktsnip_t* new_pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(new_pkt != NULL);
    // pkt -> next = NULL;

    size_t size;

    //This part of the buffer can be read as quite a few different things
    //sixlowpan_sfr_rfrag_t I think is the biggest of the possible options

    __CPROVER_assume(size <= 100 && size >= sizeof(gnrc_netif_hdr_t));

    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);
    
    new_pkt -> data = data;
    new_pkt -> size = size;
    new_pkt -> next = NULL;

    return new_pkt;
}

gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    gnrc_netif_t *new_netif = malloc(sizeof(gnrc_netif_t));

    //Addresses Potential Vulnerability B in gnrc_sixlowpan_iphc_recv
    __CPROVER_assume(new_netif != NULL);

    return new_netif;
}

bool _is_rfrag(gnrc_pktsnip_t *sixlo)
{
    bool rand;
    return rand;
}

gnrc_pktsnip_t *_encode_frag_for_forwarding(gnrc_pktsnip_t *decoded_pkt,
                                                   gnrc_sixlowpan_frag_vrb_t *vrbe) {
    gnrc_pktsnip_t* new_pkt = malloc(sizeof(gnrc_pktsnip_t));
    if(new_pkt == NULL) {
        return new_pkt;
    }

    size_t size;

    //Assume no size constraints
    __CPROVER_assume(size <= 100);

    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);
    
    new_pkt -> data = data;
    new_pkt -> size = size;
    new_pkt -> next = NULL;

    return new_pkt;
}


void gnrc_pktbuf_release_error(gnrc_pktsnip_t *pkt, uint32_t err)
{
    return;
}

gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_from_route(
            const gnrc_sixlowpan_frag_rb_base_t *base,
            gnrc_netif_t *netif, const gnrc_pktsnip_t *hdr)
{
    gnrc_sixlowpan_frag_vrb_t* new_vrb = malloc(sizeof(gnrc_sixlowpan_frag_vrb_t));
    return new_vrb;
}


void harness(void)
{

    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    size_t size;

    __CPROVER_assume(size <= 100);

    //Addresses potential vulnerability A in _ipv6_iphc_decode
    __CPROVER_assume(size >= sizeof(ipv6_hdr_t));
    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);

    
    pkt -> data = data;
    pkt -> size = size;

    gnrc_pktsnip_t* npkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(npkt != NULL);

    size_t nsize;

    __CPROVER_assume(nsize <= 100);

    //Addresses potential vulnerability A in _ipv6_iphc_decode
    __CPROVER_assume(nsize >= sizeof(ipv6_hdr_t));
    uint8_t* ndata = malloc(nsize);
    __CPROVER_assume(ndata != NULL);

    
    npkt -> data = ndata;
    npkt -> size = nsize;
    npkt -> next = NULL;

    pkt -> next = npkt;

    gnrc_sixlowpan_frag_rb_t* rbuf_entry = malloc(sizeof(gnrc_sixlowpan_frag_rb_t));
    if(rbuf_entry != NULL) {
        gnrc_pktsnip_t* rbuf_pkt = malloc(sizeof(gnrc_pktsnip_t));
        __CPROVER_assume(rbuf_pkt != NULL);

        size_t entry_size;
        __CPROVER_assume(entry_size <= 100 && entry_size > 0);
        uint8_t* entry_data = malloc(entry_size);
        __CPROVER_assume(entry_data != NULL);
        rbuf_pkt -> data = entry_data;
        rbuf_pkt -> size = entry_size;
        rbuf_pkt -> next = NULL;

        gnrc_sixlowpan_frag_rb_base_t super;

        gnrc_sixlowpan_frag_rb_int_t* interval = malloc(sizeof(gnrc_sixlowpan_frag_rb_int_t));
        __CPROVER_assume(interval != NULL);
        __CPROVER_assume(interval -> next == NULL);

        super.ints = interval;

        rbuf_entry -> super = super;
        rbuf_entry -> pkt = rbuf_pkt;
    }

    unsigned page;

    gnrc_sixlowpan_iphc_recv(pkt, rbuf_entry, page);
}
