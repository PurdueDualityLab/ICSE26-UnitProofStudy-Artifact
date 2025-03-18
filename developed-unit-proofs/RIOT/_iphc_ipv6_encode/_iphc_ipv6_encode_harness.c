/**
 * @file _iphc_ipv6_encode.c
 * @brief Implements the proof harness for _iphc_ipv6_encode function.
 */

#include <stdbool.h>

#include "byteorder.h"
#include "net/ipv6/hdr.h"
#include "net/ipv6/ext.h"
#include "net/gnrc.h"
#include "net/gnrc/netif/internal.h"
#include "net/gnrc/sixlowpan.h"
#include "net/gnrc/sixlowpan/ctx.h"
#include "net/gnrc/sixlowpan/frag/rb.h"
#include "net/gnrc/sixlowpan/frag/minfwd.h"
#ifdef MODULE_GNRC_SIXLOWPAN_FRAG_SFR
#include "net/gnrc/sixlowpan/frag/sfr.h"
#endif  /* MODULE_GNRC_SIXLOWPAN_FRAG_SFR */
#ifdef MODULE_GNRC_SIXLOWPAN_FRAG_VRB
#include "net/gnrc/sixlowpan/frag/vrb.h"
#endif  /* MODULE_GNRC_SIXLOWPAN_FRAG_VRB */
#include "net/gnrc/sixlowpan/internal.h"
#include "net/sixlowpan.h"
#include "utlist.h"
#include "net/gnrc/nettype.h"
#include "net/gnrc/udp.h"
#include "od.h"

#include "net/gnrc/sixlowpan/iphc.h"

gnrc_sixlowpan_ctx_t *gnrc_sixlowpan_ctx_lookup_addr(const ipv6_addr_t *addr) {
    gnrc_sixlowpan_ctx_t *ctx = malloc(sizeof(gnrc_sixlowpan_ctx_t));
    
    return ctx;
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Unconstrained structs:

    gnrc_pktsnip_t pkt;
    gnrc_netif_hdr_t netif_hdr;
    gnrc_netif_t iface;

    // Create a next value for the packetsnip:

    pkt.next = (gnrc_pktsnip_t *)malloc(sizeof(gnrc_pktsnip_t));

    // Determine if next is NULL:

    if (pkt.next != NULL) {
        // Allocate a IPv6 header in the data:

        uint16_t size;

        __CPROVER_assume(size > sizeof(ipv6_hdr_t));

        // pkt.next->data = malloc(sizeof(ipv6_hdr_t));
        pkt.next->data = malloc(size);  // Use unconstrained size
        __CPROVER_assume(pkt.next->data != NULL);
        pkt.next->size = size;
    }

    size_t len;

    __CPROVER_assume(len >= 41);

    uint8_t *data = (uint8_t*)malloc(sizeof(uint8_t) * len);

    // Data will NOT be NULL:

    __CPROVER_assume(data != NULL);

    size_t size = _iphc_ipv6_encode(&pkt, &netif_hdr, &iface, data);
}
