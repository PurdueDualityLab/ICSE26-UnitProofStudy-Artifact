/**
 * @file _rbuf_add_harness.c
 * @brief Implements the proof harness for _rbuf_add function.
 */

#include "net/gnrc/pkt.h"
#include "net/gnrc/netif/hdr.h"
#include "net/gnrc/netif.h"

gnrc_pktsnip_t *gnrc_pktbuf_start_write(gnrc_pktsnip_t *pkt) {
    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
    if (pkt != NULL) {
        uint16_t size;
        __CPROVER_assume(size > sizeof(ipv6_hdr_t));
        uint8_t *data = malloc(size);
        __CPROVER_assume(data != NULL);
        pkt->data = data;
        pkt->size = size;
        pkt->next = NULL;
    }
    return pkt;
}

static uint16_t dsize = 0;
gnrc_pktsnip_t *gnrc_pktbuf_add(gnrc_pktsnip_t *next, const void *data, size_t size,
                                     gnrc_nettype_t type) {
                                        gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
                                        if (pkt != NULL) {
                                            uint16_t size;
                                            __CPROVER_assume(size > sizeof(ipv6_hdr_t));
                                            uint8_t *data = malloc(size);
                                            __CPROVER_assume(data != NULL);
                                            pkt->data = data;
                                            pkt->size = size;
                                            pkt->next = NULL;
                                            dsize = size;
                                        }
                                        return pkt;
                                    }

gnrc_pktsnip_t *gnrc_pktbuf_remove_snip(gnrc_pktsnip_t *pkt, gnrc_pktsnip_t *snip) {
    gnrc_pktsnip_t *pkt = malloc(sizeof(gnrc_pktsnip_t));
    __CPROVER_assume(pkt != NULL);
    uint16_t size;
    __CPROVER_assume(size > sizeof(ipv6_hdr_t));
    uint8_t *data = malloc(size);
    __CPROVER_assume(data != NULL);
    pkt->data = data;
    pkt->size = size;
    pkt->next = NULL;
    
    return pkt;
}

size_t _iphc_ipv6_encode(gnrc_pktsnip_t *pkt,
    const gnrc_netif_hdr_t *netif_hdr,
    gnrc_netif_t *iface,
    uint8_t *iphc_hdr) {
        size_t ret;

        __CPROVER_assume(ret + 6 > ret && ret + 6 < dsize);

        return ret;
    }
/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Input structs:

    gnrc_pktsnip_t pkt;
    gnrc_netif_hdr_t netif_hdr;
    gnrc_netif_t *iface;

    // Allocate packetsnip:

    pkt.next = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));

    __CPROVER_assume(pkt.next != NULL);

    uint16_t size;
    __CPROVER_assume(size > sizeof(ipv6_hdr_t));
    pkt.next->data = (ipv6_hdr_t *)malloc(size); // COULD fail

    __CPROVER_assume(pkt.next->data != NULL);
    pkt.next->size = size;


        gnrc_pktsnip_t *pkt1 = malloc(sizeof(gnrc_pktsnip_t));
        if (pkt1 != NULL) {
            uint16_t size1;
            __CPROVER_assume(size1 > sizeof(ipv6_hdr_t));
            uint8_t *data1 = malloc(size1);
            __CPROVER_assume(data1 != NULL);
            pkt1->data = data1;
            pkt1->size = size1;
            pkt1->next = NULL;
        }

        pkt.next->next = pkt1;
    

    gnrc_pktsnip_t *res = _iphc_encode(&pkt, &netif_hdr, &iface);
}
