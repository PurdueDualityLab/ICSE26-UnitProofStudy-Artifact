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

#define CONFIG_GCOAP_DNS_SERVER_URI_LEN     64U

extern char _proxy[CONFIG_GCOAP_DNS_SERVER_URI_LEN];
extern char _uri[CONFIG_GCOAP_DNS_SERVER_URI_LEN];

void harness(void)
{

    uint8_t src_null_byte;
    __CPROVER_assume(src_null_byte < CONFIG_GCOAP_DNS_SERVER_URI_LEN);
    _proxy[src_null_byte] = '\0';

    uint8_t uri_null_byte;
    __CPROVER_assume(uri_null_byte < CONFIG_GCOAP_DNS_SERVER_URI_LEN);
    _uri[uri_null_byte] = '\0';

    size_t str_len;

    char* str = malloc(str_len);
    __CPROVER_assume(str != NULL);

    //Don't add a NULL byte to a string of length 0
    if (str_len != 0) {
        str[str_len - 1] = '\0';
    }


    gcoap_dns_server_proxy_get(str, str_len);
}
