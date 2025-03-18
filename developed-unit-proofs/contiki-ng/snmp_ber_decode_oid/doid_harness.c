/**
 * @file doid_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Tests for the OID decoder
 * @version 0.1
 * @date 2024-06-05
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdlib.h>

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"

#include "snmp-generic.h"


void harness() {

    // Create packet:

    snmp_packet_t pack;

    // Initialize packet:

    int size;
    pack.in = (uint8_t *) malloc(sizeof(uint8_t) * size);

    __CPROVER_assume(pack.in != NULL);
    pack.used = size;

    // Create OID struct

    snmp_oid_t oid;

    // Send to function:

    snmp_ber_decode_oid(&pack, &oid);
}
