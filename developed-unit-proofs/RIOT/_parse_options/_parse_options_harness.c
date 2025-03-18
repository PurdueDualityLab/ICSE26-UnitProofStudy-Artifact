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

#include "sys/net/gnrc/routing/rpl/gnrc_rpl_control_messages.c"

gnrc_netif_t *gnrc_netif_get_by_pid(kernel_pid_t pid) {
    //Normally this function can return NULL
    //But _parse_options has an assert that checks for this
    //So in the stub I'll assume it can't return NULL
    gnrc_netif_t *new_netif = malloc(sizeof(gnrc_netif_t));
    __CPROVER_assume(new_netif != NULL);
    return new_netif;

}

void harness(void)
{

    int msg_type;
    gnrc_rpl_instance_t inst; //No fields to alloc, pass in by address

    uint16_t opt_len; //Length of the options PDU
    __CPROVER_assume(opt_len > sizeof(gnrc_rpl_opt_t));

    //Options length doesn't include first 2 bytes in the struct
    gnrc_rpl_opt_t* opt = malloc(opt_len);
    __CPROVER_assume(opt != NULL);

    //I believe this field represents the length of the data for this option stored in the buffer
    //Rather than the length of the entire buffer (which stores several options)
    __CPROVER_assume(opt -> length <= opt_len - sizeof(gnrc_rpl_opt_t));


    ipv6_addr_t src; 
    uint32_t included_opts;

    _parse_options(msg_type, &inst, opt, opt_len, &src, &included_opts);
}
