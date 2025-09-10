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

#include "net/emcute.h"


extern emcute_sub_t *subs;

void emcute_callback(const emcute_topic_t *topic, void *data, size_t len) {
    return;
}

void harness(void)
{
    uint16_t port;

    size_t str_size;

    __CPROVER_assume(str_size > 0);
    char* id = malloc(str_size);
    __CPROVER_assume(id != NULL);
    id[str_size - 1] = '\0';

    subs = malloc(sizeof(emcute_sub_t));
    if(subs != NULL) {
        subs -> next = NULL;
        subs -> cb = emcute_callback;
    }
    

    emcute_run(port, id);
}
