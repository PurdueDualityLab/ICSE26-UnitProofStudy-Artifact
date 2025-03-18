/**
 * @file cts_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for check_for_tcp_syn
 * @version 0.1
 * @date 2024-07-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/tcpip.h"

// Header length
uint16_t uip_ext_len;

// Length of payload data
uint16_t uip_len;

void harness() {

    // Payload length will not exceed maximum:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Header length will not exceed size:

    __CPROVER_assume(uip_ext_len <= uip_len - UIP_IPH_LEN);

    check_for_tcp_syn();
}
