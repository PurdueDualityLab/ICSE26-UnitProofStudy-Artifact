/**
 * @file esl_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Tests for string len encoding
 * @version 0.1
 * @date 2024-06-08
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/app-layer/snmp/snmp.h"
#include "net/app-layer/snmp/snmp-ber.h"

#include "snmp-generic.h"

void harness() {

    // First, create packet to be processed:
    snmp_packet_t pack;

    // Initialize:

    uint16_t size;

    __CPROVER_assume(size > 0);

    pack.out = (uint8_t *) malloc(sizeof(uint8_t) * size);
    __CPROVER_assume(pack.out != NULL);
    pack.out += (size - 1);
    pack.max = size;
    pack.used = 0;

    // Define length, limit by max size:

    uint16_t length;

    __CPROVER_assume(length > 0);

    // Allocate string (won't be null):

    char* str = (char*)malloc(sizeof(char) * length);

    __CPROVER_assume(str != NULL);

    // Pass to function:

    snmp_ber_encode_string_len(&pack, str, length);
}
