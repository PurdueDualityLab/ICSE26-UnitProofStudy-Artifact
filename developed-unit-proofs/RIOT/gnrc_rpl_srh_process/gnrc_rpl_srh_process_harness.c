/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _rbuf_add function.
 */

#include "net/gnrc/rpl/srh.h"
#include "net/gnrc/netif.h"

gnrc_netif_t *gnrc_netif_get_by_ipv6_addr(const ipv6_addr_t *addr)
{
    gnrc_netif_t *netif = (gnrc_netif_t *)malloc(sizeof(gnrc_netif_t));

    return netif;
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Unconstrained struts:

    ipv6_hdr_t ipv6;

    // Allocate input headers
    // The function can read a LOT of data, so we allocate a good amount

    uint8_t size;

    __CPROVER_assume(size > sizeof(gnrc_rpl_srh_t));

    gnrc_rpl_srh_t *rh = (gnrc_rpl_srh_t *)malloc(size);

    // Ensure we can't be NULL:

    __CPROVER_assume(rh != NULL);

    __CPROVER_assume((rh->len * 8) + 8 <= size );

    char *point;

    int res = gnrc_rpl_srh_process(&ipv6, rh, &point);
}
