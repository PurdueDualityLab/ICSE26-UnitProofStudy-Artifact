/**
 * @file mde_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for snmp message decoding
 * @version 0.1
 * @date 2024-06-19
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-message.h"

#include "snmp-generic.h"

void harness() {

    // Create packet to be processed:

    snmp_packet_t pack;

    // Initialize

    int size;
    __CPROVER_assume(size > 0);
    pack.in = malloc(size);
    __CPROVER_assume(pack.in != NULL);
    pack.used = size;

    snmp_header_t header;

    snmp_varbind_t *varbinds = malloc(SNMP_MAX_NR_VALUES * sizeof(snmp_varbind_t));
    __CPROVER_assume(varbinds != NULL);

    // Pass values to function:

    snmp_message_decode(&pack, &header, varbinds);
}
