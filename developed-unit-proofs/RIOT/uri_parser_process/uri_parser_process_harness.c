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

#include "uri_parser.h"

// Stubbing this to help runtime and avoid loop
// const char *_strchrb(char *start, const char *stop, char c)
// {   

//     bool rand;
//     if(rand) {
//         return NULL;
//     }
//     size_t offset;
//     //Keep within str bounds without risk of an overflow
//     __CPROVER_assume(offset < stop - start);
//     start[offset] = c;
//     return start + offset;
// }

void harness(void)
{
    uri_parser_result_t* result = malloc(sizeof(uri_parser_result_t));
    __CPROVER_assume(result != NULL);

    //There seems to be an assumption  uri_size is not 0
    //Considering the first byte is checked to not be a null byte
    size_t uri_size;
    __CPROVER_assume(uri_size <= 10 && uri_size > 0);

    char* uri = malloc(uri_size);
    __CPROVER_assume(uri != NULL);


    uri_parser_process(result, uri, uri_size);

}
