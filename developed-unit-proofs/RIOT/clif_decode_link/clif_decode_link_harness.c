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
#include <stdio.h>
#include <string.h>

#include "clif.h"
#include "clif_internal.h"

void* memchr(void * pointer, int value, size_t size) {
    //Original func can return NULL
    int rand;
    
    //Realistically, if size was 0, this would return NULL as no matching value could be found
    if(rand || size == 0) {
        return NULL;
    }

    //Returns the pointer to the first matching byte, so it has to be less than size
    size_t offset;
    __CPROVER_assume(offset < size);

    return pointer + offset;
}

void harness(void)
{
    clif_t* link = malloc(sizeof(clif_t));
    __CPROVER_assume(link != NULL);

    size_t attrs_len;

    // Constrained the len to avoid overflows during the multiplication
    __CPROVER_assume(attrs_len < 100);

    //If done dynamically it takes way too long due to the amount of possibilities
    clif_attr_t *attrs = malloc(attrs_len * sizeof(clif_attr_t));
    __CPROVER_assume(attrs != NULL);
    
    size_t maxlen;

    char* buf = malloc(maxlen);
    __CPROVER_assume(buf != NULL);

    clif_decode_link(link, attrs, attrs_len, buf, maxlen);
}
