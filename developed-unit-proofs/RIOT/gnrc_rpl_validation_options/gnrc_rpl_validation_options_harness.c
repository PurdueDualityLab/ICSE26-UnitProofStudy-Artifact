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


void harness(void)
{

    int msg_type;
    gnrc_rpl_instance_t inst; //No fields to alloc, pass in by address

    uint16_t opt_len; //Length of the options PDU

    //Options length doesn't include first 2 bytes in the struct
    gnrc_rpl_opt_t* opt = malloc(opt_len);
    __CPROVER_assume(opt != NULL);

    gnrc_rpl_validation_options(msg_type, &inst, opt, opt_len);
}
