#include <stdint.h>

#include "pb_adv.c"

void bt_test_mesh_prov_invalid_bearer(uint8_t opcode) {
	return;
}

static void link_opened(const struct prov_bearer *bearer, void *cb_data) {
	return;
}

static void link_closed(const struct prov_bearer *bearer, void *cb_data,
			    enum prov_bearer_link_status reason) {
	return;
}

static void error(const struct prov_bearer *bearer, void *cb_data,
		      uint8_t err) {
	return;
}

static void recv(const struct prov_bearer *bearer, void *cb_data,
		     struct net_buf_simple *buf) {
	return;
}

void callback(int err, void *cb_data){
	return;
}

int harness() {
	struct prov_bearer_cb cb_funcs;
	cb_funcs.error = error;
	cb_funcs.link_opened = link_opened;
	cb_funcs.link_closed = link_closed;
	cb_funcs.recv = recv;
	extern struct pb_adv link;
	link.cb = &cb_funcs;

	uint16_t link_buf_size;
	struct net_buf_simple link_buf;
	link_buf.data = (uint8_t*) malloc(link_buf_size);
	__CPROVER_assume(link_buf.data != NULL);
	link_buf.__buf = link_buf.data;
	link_buf.size = link_buf_size;
	link.rx.buf = &(link_buf);

	struct prov_rx rx;
	struct net_buf_simple buf;
	uint16_t size;
	
	buf.data = (uint8_t*) malloc(size);
	__CPROVER_assume(buf.data != NULL);
	buf.size = size;
	uint16_t len;
	__CPROVER_assume(len <= size);
	__CPROVER_assume(len <= link_buf_size); // This is not upheld, potential bug
	buf.len = len;


	gen_prov_start(&rx, &buf);
}

int main() {

	harness();
	return 0;
}
