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
#include "net/nanocoap.h"
#include "net/gcoap.h"
#include "thread_flags.h"

extern char* _result_buf;
extern size_t _result_buf_len;

static coap_pkt_t* alloc_coap_pkt() {
    //Paschal's implementation

    coap_pkt_t* pkt = malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pkt != NULL);
    uint8_t pkt_size;
    __CPROVER_assume(pkt_size > sizeof(coap_hdr_t));
    uint8_t *hdr = malloc(pkt_size);
    __CPROVER_assume(hdr != NULL);
    pkt->hdr = hdr;
    uint8_t payload_offset;
    __CPROVER_assume(payload_offset >= sizeof(coap_hdr_t) && payload_offset <= pkt_size);
    pkt->payload = hdr + payload_offset;
    pkt->payload_len = pkt_size - payload_offset;

    return pkt;
}


void harness(void)
{
    
    gcoap_request_memo_t memo;

    coap_pkt_t *pdu = alloc_coap_pkt();

    sock_udp_ep_t remote;

    _result_buf = malloc(_result_buf_len);
    __CPROVER_assume(_result_buf != NULL);

    _on_rd_init(&memo, pdu, &remote);
}
