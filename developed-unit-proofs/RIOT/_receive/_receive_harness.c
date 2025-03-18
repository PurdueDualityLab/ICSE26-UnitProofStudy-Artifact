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
#include "net/gnrc/pkt.h"
#include "gnrc_tcp_common.h"
#include "net/tcp.h"

_gnrc_tcp_common_tcb_list_t *_gnrc_tcp_common_get_tcb_list(void)
{
    _gnrc_tcp_common_tcb_list_t* head = malloc(sizeof(_gnrc_tcp_common_tcb_list_t));
    __CPROVER_assume(head != NULL);
    gnrc_tcp_tcb_t* tcb = malloc(sizeof(gnrc_tcp_tcb_t));
    __CPROVER_assume(tcb != NULL);

    tcb -> next = NULL;

    head -> head = tcb;
    return head;
}

gnrc_pktsnip_t *gnrc_pktbuf_start_write(gnrc_pktsnip_t *pkt)
{
    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    if(pkt == NULL) {
        return pkt;
    }

    size_t size;
    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);

    pkt -> data = data;
    pkt -> size = size;
    pkt -> next = NULL;

    return pkt;
}

gnrc_pktsnip_t *gnrc_pktbuf_mark(gnrc_pktsnip_t *pkt, size_t size, gnrc_nettype_t type)
{
    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    if(pkt == NULL) {
        return pkt;
    }

    tcp_hdr_t* data = malloc(sizeof(tcp_hdr_t));
    __CPROVER_assume(data != NULL);

    pkt -> data = data;
    pkt -> size = size;
    pkt -> next = NULL;

    return pkt;
}

gnrc_pktsnip_t *gnrc_pktsnip_search_type(gnrc_pktsnip_t *pkt,
                                         gnrc_nettype_t type)
{
    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    if(pkt == NULL) {
        return pkt;
    }

    size_t size;
    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);

    pkt -> data = data;
    pkt -> size = size;
    pkt -> type = type;
    pkt -> next = NULL;

    return pkt;
}


void harness(void)
{
    gnrc_pktsnip_t* pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);

    size_t size;
    uint8_t* data = malloc(size);
    __CPROVER_assume(data != NULL);

    pkt -> data = data;
    pkt -> size = size;
    pkt -> next = NULL;

    _receive(pkt);
}
