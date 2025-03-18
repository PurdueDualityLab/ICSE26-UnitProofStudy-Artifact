/**
 * @file gbu_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for get_bulk function
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-engine.h"
#include "net/app-layer/snmp/snmp-mib.h"

void *resource_handler(snmp_varbind_t *varbind, snmp_oid_t *oid) {

    uint8_t size;
    void *pointer = malloc(size);
    return pointer;

}

snmp_mib_resource_t *snmp_mib_find_next(snmp_oid_t *oid) {
    snmp_mib_resource_t *resource = malloc(sizeof(snmp_mib_resource_t));
    __CPROVER_assume(resource != NULL);
    resource->handler = resource_handler;
    uint8_t b;
    return b ? NULL : resource;
}

void harness() {

    // Create header:

    snmp_header_t header;

    // Create varbind array:

    snmp_varbind_t *varbinds = malloc(SNMP_MAX_NR_VALUES * sizeof(snmp_varbind_t));
    __CPROVER_assume(varbinds != NULL);

    // Send along to function:

    snmp_engine_get_bulk(&header, varbinds);
}
