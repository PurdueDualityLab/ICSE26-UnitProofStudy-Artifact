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
#include "net/nanocoap.h"
#include "sys/include/uri_parser.h"
#include "forward_proxy_internal.h"


/*
    Some comments
    - You really don't know the size of each option at this point, so it's hard to know where the payload should start from
    - When creating packets, do you assume each option only has 1 byte? You allocate single bytes for the different options.
    - You have a source and destination packet. I can imagine the constraints on both packets will be 
            -   different. Hence, I dont think they should be fully allocated with the same function. Maybe a base allocation function and additional constraints as needed.
    */

ssize_t coap_opt_get_next(const coap_pkt_t *pkt, coap_optpos_t *opt,
                               uint8_t **value, bool init_opt) {

    uint16_t opt_num;
    uint16_t offset;

    opt->opt_num = opt_num;
    opt->offset = offset;

    uint16_t len;
    *value = malloc(len);
    __CPROVER_assume(*value != NULL);

    return len;
    
}

static coap_pkt_t* alloc_coap_pkt() {

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

static coap_pkt_t* alloc_coap_client_pkt() {

    coap_pkt_t* pkt = malloc(sizeof(coap_pkt_t));
    __CPROVER_assume(pkt != NULL);

    uint8_t pkt_size;

    __CPROVER_assume(pkt_size > sizeof(coap_hdr_t) + 2);

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

    
    coap_pkt_t *pkt = alloc_coap_pkt();

    coap_pkt_t *client_pkt = alloc_coap_client_pkt();

    // Added this clause as client_pkt->payload is copied into pkt->payload without len checks.
    __CPROVER_assume(client_pkt->payload_len <= pkt->payload_len - 1);

    client_ep_t cep; //No pointers in this so I'm not going to alloc it

    uri_parser_result_t* urip = malloc(sizeof(uri_parser_result_t));
    __CPROVER_assume(urip != NULL);
    //I'm allocing this because the path var which I need to make sure is defined is constant

    uint8_t path_len;
    char* path = malloc(path_len);
    __CPROVER_assume(path != NULL);

    uint8_t query_len;
    char* query = malloc(query_len);
    __CPROVER_assume(query != NULL);

    urip -> path = path;
    urip -> path_len = path_len;
    urip -> query = query;
    urip -> query_len = query_len;
    

    /* Insert argument declarations */
    _gcoap_forward_proxy_copy_options(pkt, client_pkt, &cep, urip);
}
