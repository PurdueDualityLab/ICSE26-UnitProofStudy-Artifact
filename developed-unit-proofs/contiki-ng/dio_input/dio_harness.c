/**
 * @file dio_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for dio_input
 * @version 0.1
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip.h"
#include "net/ipv6/uipbuf.h"
#include "net/routing/rpl-classic/rpl.h"
#include "net/routing/rpl-classic/rpl-conf.h"

#include "gnet/packetbuf-generic.h"

extern uint16_t uip_len;

void harness() {

    // Length will not exceed buffer size:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Total length of extension headers will not exceed buffer size:

    __CPROVER_assume(uip_l3_icmp_hdr_len <= uip_len);

    dio_input();
}
