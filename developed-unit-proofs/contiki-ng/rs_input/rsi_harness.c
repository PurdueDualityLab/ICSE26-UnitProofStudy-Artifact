/**
 * @file rsi_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for rs_input
 * @version 0.1
 * @date 2024-07-17
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip-nd6.h"
#include "net/ipv6/uip-ds6-nbr.h"

// Header length
uint16_t uip_ext_len;

// Length of payload data
uint16_t uip_len;

uip_ds6_nbr_t *
uip_ds6_nbr_lookup(const uip_ipaddr_t *ipaddr) {


    uip_ds6_nbr_t* nbrt = (uip_ds6_nbr_t*)malloc(sizeof(uip_ds6_nbr_t));

    bool match;

    // IP address will match:

    if (nbrt != NULL && match) {
        nbrt->ipaddr = *ipaddr;
    }

    

    return nbrt;
}

uip_ds6_nbr_t *
uip_ds6_nbr_add(const uip_ipaddr_t *ipaddr, const uip_lladdr_t *lladdr,
                uint8_t isrouter, uint8_t state, nbr_table_reason_t reason,
                void *data) {
    // Allocate NBR table entry:

    uip_ds6_nbr_t *nbr = (uip_ds6_nbr_t*)malloc(sizeof(uip_ds6_nbr_t));

    // IP address MUST be the same as provided:

    bool match;

    // IP address will match:

    if (nbr != NULL && match) {
        nbr->ipaddr = *ipaddr;
    }


    // Return entry:

    return nbr;
}

const uip_lladdr_t *
uip_ds6_nbr_get_ll(const uip_ds6_nbr_t *nbr) {

    // Allocate lladdr:

    uip_lladdr_t* addr = (uip_lladdr_t*)malloc(sizeof(uip_lladdr_t));

    return addr;
}

void harness() {

    // Payload length will not exceed maximum:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Header length will not exceed size:

    uint8_t space = UIP_IPH_LEN + sizeof(struct uip_icmp_hdr) + sizeof(uip_nd6_opt_hdr) + UIP_ND6_RS_LEN;

    __CPROVER_assume(uip_ext_len + space > uip_ext_len &&
                        uip_ext_len + space <= uip_len);

    rs_input();
}
