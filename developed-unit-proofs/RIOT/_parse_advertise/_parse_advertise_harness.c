// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/**
 * @file _parse_advertise.c
 * @brief Implements the proof harness for _parse_advertise function.
 */

#include <stdint.h>
#include <stdlib.h>

#include "byteorder.h"

#include <assert.h>
#include <stdbool.h>

#include "event.h"
#include "event/timeout.h"
#include "log.h"
#include "kernel_defines.h"
#include "net/dhcpv6/client.h"
#include "net/dhcpv6.h"
#include "net/netif.h"
#include "net/sock/udp.h"
#include "random.h"
#include "timex.h"
#if IS_USED(MODULE_ZTIMER)
#include "ztimer.h"
#else
#include "xtimer.h"
#include "xtimer/implementation.h"
#endif

#include "_dhcpv6.h"

uint32_t random_uint32_range(uint32_t a, uint32_t b) {

    // Create unconstrained int

    uint32_t val;

    // Ensure int falls within range

    __CPROVER_assume(a <= val);
    __CPROVER_assume(val < b);

    return val;
}

int _preparse_advertise(uint8_t *adv, size_t len, uint8_t **buf) {
    int val;

    return val;
}

/**
 * @brief Starting point for formal analysis
 * 
 */
    void harness(void)
{
    // Define unconstrained array length

    size_t len;

    // Constrain size to be something reasonable:

    __CPROVER_assume(len >= sizeof(dhcpv6_msg_t));

    // Allocate data of length

    uint8_t* data = (uint8_t*)malloc(sizeof(uint8_t) * len);

    __CPROVER_assume(data != NULL);

    _parse_advertise(data, len);
}
