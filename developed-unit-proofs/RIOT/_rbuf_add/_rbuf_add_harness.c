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

#include <stdlib.h>
#include <stdint.h>

// #include "net/gnrc/pkt.h"
// #include "net/gnrc/netif/hdr.h"

// #include "sys/net/gnrc/network_layer/sixlowpan/frag/rb/gnrc_sixlowpan_frag_rb.c"

#include <assert.h>
#include <inttypes.h>
#include <stdbool.h>

#include "net/ieee802154.h"
#include "net/ipv6.h"
#include "net/ipv6/hdr.h"
#include "net/gnrc.h"
#include "net/gnrc/sixlowpan.h"
#include "net/gnrc/sixlowpan/config.h"
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

#include "net/gnrc/sixlowpan/frag/rb.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

extern gnrc_sixlowpan_frag_rb_t rbuf[CONFIG_GNRC_SIXLOWPAN_FRAG_RBUF_SIZE];


// int _rbuf_add(gnrc_netif_hdr_t *netif_hdr, gnrc_pktsnip_t *pkt,
//                      size_t offset, unsigned page);

gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, gnrc_nettype_t type) {
    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);
    uint8_t size;
    uint8_t *data = malloc(size);
    __CPROVER_assume(data != NULL);
    pkt->data = data;
    pkt->size = size;
    pkt->next = NULL;

    return pkt;
}

int _rbuf_get(const void *src, size_t src_len,
                     const void *dst, size_t dst_len,
                     size_t size, uint16_t tag,
                     unsigned page) {
                        int ret;
                        __CPROVER_assume(ret < CONFIG_GNRC_SIXLOWPAN_FRAG_RBUF_SIZE);
                        return ret;
                     }

gnrc_sixlowpan_frag_vrb_t *gnrc_sixlowpan_frag_vrb_get(const uint8_t *src, 
        size_t src_len, unsigned src_tag) {
        gnrc_sixlowpan_frag_vrb_t *ret = malloc(sizeof(gnrc_sixlowpan_frag_vrb_t));
        __CPROVER_assume(ret != NULL);

        ret->super.ints = malloc(sizeof(gnrc_sixlowpan_frag_rb_int_t));
        __CPROVER_assume(ret->super.ints != NULL);
        ret->super.ints->next = NULL;
        return ret;
}
/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

  /* Insert argument declarations */
    gnrc_netif_hdr_t *netif_hdr = malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(netif_hdr != NULL);

    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    uint8_t size;
    uint8_t minSize = MAX(sizeof(sixlowpan_frag_t), MAX(sizeof(sixlowpan_frag_n_t), sizeof(sixlowpan_sfr_rfrag_t)));
    __CPROVER_assume(size > minSize);
    uint8_t *data = malloc(size);
    __CPROVER_assume(data != NULL);
    pkt->data = data;
    pkt->size = size;
    pkt->next = NULL;

    size_t offset;
    __CPROVER_assume(offset < 1000);
    // Adding this check to ensure consistency and remove an error.
    // We need to check if it is possible for a caller to violate this condition. If it is, it is a bug.
    __CPROVER_assume(offset != 0 || sixlowpan_frag_1_is(pkt->data) || sixlowpan_sfr_rfrag_is(data));
    unsigned page;

    // Modeling rbuf
    gnrc_sixlowpan_frag_rb_t entry;
    entry.pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(entry.pkt != NULL);
    uint8_t entry_size;
    __CPROVER_assume(entry_size > 0);
    entry.pkt->data = malloc(entry_size);
    __CPROVER_assume(entry.pkt->data != NULL);
    entry.pkt->size = entry_size;
    entry.pkt->next = NULL;
    uint16_t datagram_size;
    __CPROVER_assume(datagram_size <= entry_size);
    entry.super.datagram_size = datagram_size;
    // Added this to fix a bug. Not sure how best to model it
    int8_t offset_diff;
    __CPROVER_assume(offset_diff >= 0); // Basically, offset diff should not be negative that it overflows.
    entry.offset_diff = offset_diff;

    entry.super.ints = malloc(sizeof(gnrc_sixlowpan_frag_rb_int_t));
    __CPROVER_assume(entry.super.ints != NULL);
    entry.super.ints->next = NULL;


    rbuf[0] = entry;

    _rbuf_add( netif_hdr, pkt, offset, page );
}
