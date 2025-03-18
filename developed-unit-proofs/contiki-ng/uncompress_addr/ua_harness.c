/**
 * @file ua_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for uncompress_addr
 * @version 0.1
 * @date 2024-07-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/sicslowpan.h"
#include <stdlib.h>

// Pointer to data to uncompress
extern uint8_t *iphc_ptr;
extern uint8_t *packetbuf_ptr;

static uint16_t buflen;

uint16_t
packetbuf_datalen(void) {
    return buflen;
}

void harness() {

    // Define an unconstrained IP6 address:

    uip_ipaddr_t ipaddr;

    // Define unconstrained 802.15.4 address

    uip_lladdr_t lladdr;

    // Define prefix counts variable:

    uint8_t prefix_counts;

    // Get nibbles:

    uint8_t pre = prefix_counts >> 4;  // Upper nibble, prefix size
    uint8_t post = prefix_counts & 0x0f;  // Lower nibble, iphc_pointer size

    // Special case - If counts are are 15, they need to be 16

    if (pre == 15) {
        ++pre;
    }

    if (post == 15) {
        ++post;
    }

    // Allocate prefix array:

    uint8_t const prefix[pre];

    uint16_t len;

    packetbuf_ptr = malloc(len);
    __CPROVER_assume(packetbuf_ptr != NULL);
    buflen = len;

    uint16_t iphc_offset;
    __CPROVER_assume(iphc_offset < len);
    iphc_ptr = packetbuf_ptr + iphc_offset;


    uncompress_addr(&ipaddr, prefix, prefix_counts, &lladdr);
}
