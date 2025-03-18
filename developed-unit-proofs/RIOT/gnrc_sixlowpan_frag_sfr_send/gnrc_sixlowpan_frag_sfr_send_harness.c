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
#include <assert.h>

#include "irq.h"
#include "kernel_defines.h"
#ifdef MODULE_GNRC_IPV6_NIB
#include "net/ipv6/addr.h"
#endif
#ifdef MODULE_GNRC_IPV6
#include "net/ipv6/hdr.h"
#endif
#include "net/gnrc/neterr.h"
#include "net/gnrc/netif/internal.h"
#include "net/gnrc/netif/pktq.h"
#include "net/gnrc/pkt.h"
#include "net/gnrc/sixlowpan.h"
#include "net/gnrc/sixlowpan/config.h"
#include "net/gnrc/sixlowpan/frag/fb.h"
#include "net/gnrc/sixlowpan/frag/rb.h"
#include "net/gnrc/sixlowpan/frag/vrb.h"
#include "net/gnrc/tx_sync.h"
#include "net/sixlowpan/sfr.h"
#include "thread.h"
#include "unaligned.h"
#include "xtimer.h"
#include "evtimer.h"
#include "evtimer_msg.h"

#include "net/gnrc/sixlowpan/frag/sfr.h"
#include "net/gnrc/sixlowpan/frag/sfr/congure.h"

extern evtimer_msg_t _arq_timer;
extern clist_node_t _frag_descs_free;

typedef struct {
    clist_node_t super;     /**< list parent instance */
    gnrc_pktsnip_t *frame;  /**< frame in the queue */
    uint8_t datagram_tag;   /**< tag for identification */
    uint8_t page;           /**< parsing page context for the frame */
} _frame_queue_t;

typedef struct {
    congure_snd_msg_t super;    /**< CongURE message parent */
    /**
     * @brief   Acknowledgment request flag, sequence number, and fragment size
     */
    uint16_t ar_seq_fs;
    uint16_t offset;            /**< offset of the fragment */
} _frag_desc_t;

uint16_t _send_1st_fragment(gnrc_netif_t *netif,
                                   gnrc_sixlowpan_frag_fb_t *fbuf,
                                   unsigned page, gnrc_pktsnip_t **tx_sync) {

    uint16_t res;
    return res;   
}

uint16_t _send_nth_fragment(gnrc_netif_t *netif,
                                   gnrc_sixlowpan_frag_fb_t *fbuf,
                                   unsigned page,
                                   gnrc_pktsnip_t **tx_sync) {

    uint16_t res;
    return res;   
}

bool _send_abort_frag(gnrc_pktsnip_t *pkt,
                             gnrc_sixlowpan_frag_fb_t *fbuf,
                             bool req_ack, unsigned page) {
    bool rand;
    return rand;
}

// This function usually pops out of a circular linked list
// Don't know how I could implement that, so I'll use this stub to model popping it
clist_node_t *clist_lpop(clist_node_t *list)
{
    //In the specific place this is used, the returned node is cast to a _frame_queue_t
    clist_node_t* node = malloc(sizeof(_frame_queue_t));
    return node;
}



void harness(void) 
{
    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);
    // pkt -> next = NULL;

    size_t size;

    //Data buffer is read as gnrc_netif_hdr_t, I'm going to assume it's at least that size
    //However if it is less than that size I think it can cause an OOB read
    __CPROVER_assume(size >= sizeof(gnrc_netif_hdr_t));
    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);
    
    pkt -> data = data;
    pkt -> size = size;
    // pkt -> type = GNRC_NETTYPE_NETIF; //This is checked via an assert at the start of the func

    gnrc_sixlowpan_frag_fb_t* ctx = malloc(sizeof(gnrc_sixlowpan_frag_fb_t));
    __CPROVER_assume(ctx != NULL);
    ctx -> pkt = pkt; //There is an assertion that checks for this to be true

    //This is a linked list node, so it can't be an undefined obj
    //I think this is read as a _frag_desc_t in the function (line 407)

    //It's unclear whether or not this can be NULL, as it's a node in a LL
    //If it can be then there might be a potential vulnerability
    ctx -> sfr.window.next = malloc(sizeof(_frag_desc_t));

    //Technically this can be null, but _send_nth_fragment will change that add onto the linked list
    //We stub that function out and thus there is an error caused by this field being null
    //So we'll assume it's not null for that reason
    __CPROVER_assume(ctx -> sfr.window.next != NULL);

    uint8_t page;

    //This is checked somewhere, I think it can be NULL but can't be an invalid obj
    evtimer_event_t* events = malloc(sizeof(evtimer_event_t));
    _arq_timer.events = events;

    _frag_descs_free.next = malloc(sizeof(struct list_node));

    gnrc_sixlowpan_frag_sfr_send(pkt, ctx, page);

}
