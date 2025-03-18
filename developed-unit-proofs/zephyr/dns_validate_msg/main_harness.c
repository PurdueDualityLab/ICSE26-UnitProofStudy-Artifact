#include <stdint.h>
#include <stdlib.h>
#include "zephyr/net/dns_resolve.h"
#include "net/lib/dns/dns_pack.h"

// #include header files

int dns_validate_msg(struct dns_resolve_context *ctx,
		     struct dns_msg_t *dns_msg,
		     uint16_t *dns_id,
		     int *query_idx,
		     struct net_buf *dns_cname,
		     uint16_t *query_hash);

static uint16_t max_size;

uint16_t net_buf_simple_max_len(const struct net_buf_simple *buf) {
	uint16_t ret;
	__CPROVER_assume(ret == max_size);
	return ret;
}

void *dns_resolve_cb(enum dns_resolve_status status,
	struct dns_addrinfo *info,
	void *user_data) {

	}

int harness() {

	// Model inputs
	struct dns_resolve_context *ctx = malloc(sizeof(struct dns_resolve_context));
	__CPROVER_assume(ctx != NULL);

	uint8_t index;
	__CPROVER_assume(index < DNS_NUM_CONCUR_QUERIES);
	ctx->queries[index].cb = dns_resolve_cb;

	struct dns_msg_t *dns_msg = malloc(sizeof(struct dns_msg_t));
	__CPROVER_assume(dns_msg != NULL);
	uint16_t msg_size;
	uint8_t *msg = malloc(msg_size);
	__CPROVER_assume(msg != NULL);
	dns_msg->msg = msg;
	dns_msg->msg_size = msg_size;

	__CPROVER_assume(dns_msg->query_offset < msg_size);

	uint16_t dns_id;
	int query_idx;
	__CPROVER_assume(query_idx < DNS_NUM_CONCUR_QUERIES);
	struct net_buf *dns_cname = malloc(sizeof(struct net_buf));
	__CPROVER_assume(dns_cname != NULL);

	dns_cname->data = malloc(max_size);
	__CPROVER_assume(dns_cname->data != NULL);
	uint16_t query_hash;

	// Call target function
	dns_validate_msg(ctx, dns_msg, &dns_id, &query_idx, dns_cname, &query_hash);
}

int main() {

	harness();
	return 0;
}
