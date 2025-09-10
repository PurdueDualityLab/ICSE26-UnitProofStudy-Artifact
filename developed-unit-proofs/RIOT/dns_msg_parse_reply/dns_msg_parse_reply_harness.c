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

#include "arpa/inet.h"
#include "net/dns/msg.h"

void harness(void)
{

    size_t len;

    //Based on the start of the function, the buffer must have at least a dns_hdr_t
    //Might be a vuln depending on if it is possible for buf to be less than dns_hdr_t
    __CPROVER_assume(len >= sizeof(dns_hdr_t));
    uint8_t* buf = malloc(len);
    __CPROVER_assume(buf != NULL);

    int family;
    // Family must be one of these 3 values
    __CPROVER_assume(family == AF_UNSPEC || family == AF_INET || family == AF_INET6);

    //Addr_out is a place where the IP addr can be writen to
    //Don't think it's user controlled, so I'm going to assume it can fit ipv6
    //and can't be null/too small
    uint8_t size;
    __CPROVER_assume(size >= 16);
    uint8_t *addr_out = malloc(size);
    __CPROVER_assume(addr_out != NULL);

    uint32_t ttl;
    dns_msg_parse_reply(buf, len, family, addr_out, &ttl);
}
