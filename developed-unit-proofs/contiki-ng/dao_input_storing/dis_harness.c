/**
 * @file dis_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for dao_input_storing
 * @version 0.1
 * @date 2024-06-27
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
extern uint16_t uip_ext_len;  // Define header extension length

const uip_ipaddr_t *
uip_ds6_route_nexthop(uip_ds6_route_t *route) {
    uip_ipaddr_t *addr = malloc(sizeof(uip_ipaddr_t));

    __CPROVER_assume(addr != NULL);

    return addr;
}

rpl_instance_t *
rpl_get_instance(uint8_t instance_id) {

    bool thing;

    if (thing) {
        return NULL;
    }

    // Allocate struct:

    rpl_instance_t* inst = (rpl_instance_t*)malloc(sizeof(rpl_instance_t));

    // Won't be null:

    __CPROVER_assume(inst != NULL);

    // Create DAG:

    rpl_dag_t* dag = (rpl_dag_t*)malloc(sizeof(rpl_dag_t));

    // Won't be NULL:

    __CPROVER_assume(dag != NULL);

    // Set dag and instance pointers:

    inst->current_dag = dag;
    dag->instance = inst;

    __CPROVER_assume(inst->min_hoprankinc != 0);

    return inst;
}

rpl_parent_t *
rpl_find_parent(rpl_dag_t *dag, uip_ipaddr_t *addr) {

    // Allocate parent:

    rpl_parent_t *p = (rpl_parent_t*)malloc(sizeof(rpl_parent_t));

    return p;
}

uip_ds6_route_t *
uip_ds6_route_lookup(const uip_ipaddr_t *addr) {

    bool thing;
    // Allocate data for route:

    uip_ds6_route_t* route = (uip_ds6_route_t*)malloc(sizeof(uip_ds6_route_t));

    return thing ? NULL : route;
}

uip_ds6_route_t *
rpl_add_route(rpl_dag_t *dag, uip_ipaddr_t *prefix, int prefix_len,
              uip_ipaddr_t *next_hop) {

    // Just create an unconstrained ds6 route:

    return uip_ds6_route_lookup(NULL);
}

void harness() {

    // Length will not exceed buffer size:

    __CPROVER_assume(uip_len <= UIP_BUFSIZE);

    // Total length of extension headers will not exceed buffer size:

    __CPROVER_assume(uip_l3_icmp_hdr_len < uip_len);

    // Prepare packetbuf:

    dao_input_storing();
}
