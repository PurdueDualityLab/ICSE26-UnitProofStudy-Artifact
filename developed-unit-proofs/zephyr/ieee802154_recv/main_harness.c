#include <stdint.h>

#include "zephyr/net/net_if.h"
#include "zephyr/net/net_pkt.h"
#include "zephyr/net/ieee802154_radio.h"
#include "l2/ieee802154/ieee802154_frame.h"
#include "l2/ieee802154/ieee802154_6lo.h"



enum ieee802154_hw_caps get_capabilities(const struct device *dev) {
	enum ieee802154_hw_caps rand;
	return rand;
}

struct net_pkt *net_pkt_alloc_with_buffer_debug(struct net_if *iface,
						size_t size,
						sa_family_t family,
						enum net_ip_protocol proto,
						k_timeout_t timeout,
						const char *caller,
						int line) {

							struct net_pkt *pkt = malloc(sizeof(struct net_pkt));
							if (pkt == NULL) {
								return pkt;
							}

							struct net_buf* buf = malloc(sizeof(struct net_buf));
							__CPROVER_assume(buf != NULL);

							uint8_t size;
							__CPROVER_assume(size > sizeof(struct ieee802154_fcf_seq) && size <= 100);
							uint8_t* data = (uint8_t*) malloc(size);
							__CPROVER_assume(data != NULL);
							
							buf -> data = data;
							buf -> size = size;
							__CPROVER_assume(buf->len <= size);
							pkt->frags = buf;

							return pkt;

						}

int tx(const struct device *dev, enum ieee802154_tx_mode mode,
                    struct net_pkt *pkt, struct net_buf *frag) {
						int ret;
						return ret;
					}

int harness() {
	struct net_if iface;
	struct net_if_dev* if_dev = malloc(sizeof(struct net_if_dev));
	__CPROVER_assume(if_dev != NULL);

	struct device* dev = malloc(sizeof(struct device));
	__CPROVER_assume(dev != NULL);

	struct ieee802154_radio_api* radio_api = malloc(sizeof(struct ieee802154_radio_api));
	__CPROVER_assume(radio_api != NULL);

	uint8_t l2_size;
	__CPROVER_assume(l2_size >= sizeof(struct ieee802154_context));
	uint8_t* l2data = (uint8_t*) malloc(l2_size);
	__CPROVER_assume(l2data != NULL);
	if_dev->l2_data = l2data;

	radio_api->get_capabilities = get_capabilities;
	radio_api->tx = tx;
	dev->api = radio_api;
	if_dev->dev = dev;
	iface.if_dev = if_dev;

	struct net_pkt *pkt = malloc(sizeof(struct net_pkt));
	__CPROVER_assume(pkt != NULL);

	uint8_t len;
	uint8_t* srcaddr = (uint8_t*) malloc(len);
	__CPROVER_assume(srcaddr != NULL);
	pkt->lladdr_src.addr = srcaddr;
	pkt->lladdr_src.len = len;
	
	
	struct net_buf* buf = malloc(sizeof(struct net_buf));
	__CPROVER_assume(buf != NULL);
	uint8_t size;
	__CPROVER_assume(size >= (sizeof(struct ieee802154_fcf_seq) + IEEE802154_EXT_ADDR_LENGTH + IEEE802154_EXT_ADDR_LENGTH + sizeof(struct ieee802154_aux_security_hdr)) && size <= IEEE802154_MTU);
	uint8_t* data = (uint8_t*) malloc(size);
	__CPROVER_assume(data != NULL);
	buf -> data = data;
	buf -> size = size;
	buf->frags = NULL;
	
	__CPROVER_assume(buf->len <= size);
	
	
	pkt->frags = buf;

	ieee802154_recv(&iface, pkt);
}

int main() {

	harness();
	return 0;
}
