/**
 * @file snmp_ber_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Tests unsigned int decoder
 * @version 0.1
 * @date 2024-06-04
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"

void harness() {

    // First, create packet to be processed:
    snmp_packet_t pack;

    // Initialize:

    // init_packet_in(&pack);
    int size;
    pack.in = (uint8_t *) malloc(sizeof(uint8_t) * size);

    __CPROVER_assume(pack.in != NULL);
    pack.used = size;

    // Define an unconstrained type and output:

    uint8_t type;
    uint32_t out;

    snmp_ber_decode_unsigned_integer(&pack, type, &out);
}
