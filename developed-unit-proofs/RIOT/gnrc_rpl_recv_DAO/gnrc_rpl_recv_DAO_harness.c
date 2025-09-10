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

#include "sys/include/net/gnrc/rpl/structs.h"
#include "net/ipv6.h"
#include "evtimer_msg.h"
#include "net/icmpv6.h"
#include "net/gnrc/pkt.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/netif/hdr.h"
#include "sched.h"

#include "sys/include/net/gnrc/rpl/structs.h"

gnrc_rpl_instance_t *gnrc_rpl_instance_get(uint8_t instance_id) {
    gnrc_rpl_instance_t* rpl = malloc(sizeof(gnrc_rpl_instance_t));

    return rpl;
}

gnrc_pktsnip_t *gnrc_icmpv6_build(gnrc_pktsnip_t *next, uint8_t type,
                                  uint8_t code, size_t size)
{
    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
    // Can be NULL
    if(pkt == NULL) {
        return NULL;
    }

    pkt -> data = malloc(size);
    __CPROVER_assume(pkt -> data != NULL);
    return pkt;
}

gnrc_pktsnip_t *gnrc_ipv6_hdr_build(gnrc_pktsnip_t *payload, const ipv6_addr_t *src,
                                    const ipv6_addr_t *dst)
{
    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
    //Can be NULL

    return pkt;
}

gnrc_pktsnip_t *gnrc_netif_hdr_build(const uint8_t *src, uint8_t src_len,
                                     const uint8_t *dst, uint8_t dst_len)
{
    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));

    if(pkt == NULL) {
        return NULL;
    }

    pkt -> data = malloc(sizeof(gnrc_netif_hdr_t));
    __CPROVER_assume(pkt -> data != NULL);

    return pkt;
}

gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    gnrc_netif_t *new_netif = malloc(sizeof(gnrc_netif_t));
    //Normally this can be NULL, but the only place this is used has a check for it anyways
    __CPROVER_assume(new_netif != NULL);

    return new_netif;

}


gnrc_netif_t *_find_interface_with_rpl_mcast(void) {
    gnrc_netif_t *new_netif = malloc(sizeof(gnrc_netif_t));
    //It CAN be NULL

    return new_netif;
}

void harness(void)
{
    uint16_t dao_len;
    gnrc_rpl_dao_t *dao = malloc(dao_len);
    __CPROVER_assume(dao != NULL);

    kernel_pid_t iface;
    ipv6_addr_t src;
    ipv6_addr_t dst;

    gnrc_rpl_recv_DAO(dao, iface, &src, &dst, dao_len);
}
