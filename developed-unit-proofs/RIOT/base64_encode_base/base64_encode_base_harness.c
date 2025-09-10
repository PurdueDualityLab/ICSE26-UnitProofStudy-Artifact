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
#include <stdbool.h>

void harness(void)
{
    size_t data_in_size;

    //Ensure data_in_size does not equal 1 to prevent potential vuln in while loop
    __CPROVER_assume(data_in_size != 1);

    char* data_in = malloc(data_in_size);
    // Code checks if it's null

    size_t base64_out_size;

    char* base64_out = malloc(base64_out_size);
    // Code checks if it's null

    bool urlsafe;
    // We can assume this var behaves as needed because it does not seem user defined

    base64_encode_base(data_in, data_in_size,
                              base64_out, &base64_out_size, urlsafe);
}
