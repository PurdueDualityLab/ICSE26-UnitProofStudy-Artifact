/**
 * @file dio_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for dio_input
 * @version 0.1
 * @date 2024-07-09
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/ipv6/uip.h"
#include "net/ipv6/uipbuf.h"
#include "net/routing/rpl-lite/rpl.h"
#include "net/routing/rpl-lite/rpl-icmp6.h"

extern uint16_t uip_len;
uint16_t uip_ext_len;

// void harness() {

//     // Length will not exceed buffer size:

//     __CPROVER_assume(uip_len <= UIP_BUFSIZE);

//     // Extension headers will not exceed buffer size:

//     __CPROVER_assume(uip_l3_icmp_hdr_len <= uip_len);

//     dio_input();
// }

extern rpl_instance_t curr_instance;

extern rpl_of_t * const objective_functions[];

void *reset(void) {

}

void *update_metric_container(void) {

}

rpl_nbr_t *
rpl_neighbor_get_from_ipaddr(uip_ipaddr_t *addr) {
    rpl_nbr_t *resp = malloc(sizeof(rpl_nbr_t));

    return resp;
}

nbr_table_item_t *nbr_table_head(const nbr_table_t *table) {
    uint8_t len;
    __CPROVER_assume(len > sizeof(rpl_nbr_t));
    nbr_table_item_t *item = malloc(len);

    return item;
}

nbr_table_item_t *nbr_table_next(const nbr_table_t *table,
                                      nbr_table_item_t *item) {
    uint8_t len;
    __CPROVER_assume(len > sizeof(rpl_nbr_t));
    nbr_table_item_t *item = malloc(len);

    return item;
}

nbr_table_item_t *
nbr_table_add_lladdr(const nbr_table_t *table, const linkaddr_t *lladdr,
                     nbr_table_reason_t reason, const void *data) {
    uint8_t len;
    __CPROVER_assume(len > sizeof(rpl_nbr_t));
    nbr_table_item_t *item = malloc(len);

    return item;
}

void harness() {

    
    uip_ipaddr_t *from = malloc(sizeof(uip_ipaddr_t));
    __CPROVER_assume(from != NULL);

    rpl_dio_t *dio = malloc(sizeof(rpl_dio_t));
    __CPROVER_assume(dio != NULL);

    curr_instance.of = malloc(sizeof(rpl_of_t));
    __CPROVER_assume(curr_instance.of != NULL);

    curr_instance.of->reset = reset;
    curr_instance.of->update_metric_container = update_metric_container;

    objective_functions[0]->reset = reset;
    objective_functions[0]->update_metric_container = update_metric_container;
    

    rpl_process_dio(from, dio);
}
