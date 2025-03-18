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

#include "clif.h"

void harness(void)
{
    clif_attr_t* attr = malloc(sizeof(clif_attr_t));
    __CPROVER_assume(attr != NULL);

    size_t input_len;
    __CPROVER_assume(input_len <= 10);

    char* input = malloc(input_len);
    __CPROVER_assume(input != NULL);

    clif_get_attr(input, input_len, attr);

}
