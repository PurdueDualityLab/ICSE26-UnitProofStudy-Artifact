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

#include <stddef.h>
#include <stdlib.h>
#include "net/asymcute.h"

void user_cb(asymcute_req_t *req, unsigned evt_type) {
    return;
}

void harness(void)
{
    asymcute_con_t *con = malloc(sizeof(asymcute_con_t));
    __CPROVER_assume(con != NULL);
    con -> user_cb = user_cb;

    uint8_t size;

    __CPROVER_assume(size > sizeof(asymcute_topic_t));

    asymcute_topic_t* topic = malloc(size);

    asymcute_req_t *pending = malloc(sizeof(asymcute_req_t ));
    asymcute_req_t *next_pending = malloc(sizeof(asymcute_req_t ));
    if (next_pending != NULL) {
        next_pending->next = NULL;
        next_pending -> arg = topic;
    }
    if (pending != NULL) {
        pending -> next = next_pending;
        pending -> arg = topic;
    
    }
    
    con -> pending = pending;

    asymcute_sub_t *subscriptions = malloc(sizeof(asymcute_req_t));
    __CPROVER_assume(subscriptions != NULL);
    subscriptions -> next = NULL;
    con -> subscriptions = subscriptions;

    size_t len;
  
    uint8_t* data = malloc(len);
    __CPROVER_assume(data != NULL);

    _on_regack(con, data, len);
}
