#include <stdint.h>

#include <lwm2m/lwm2m_object.h>
#include <zephyr/net/lwm2m.h>


int lwm2m_engine_validate_write_access(struct lwm2m_message *msg,
                                       struct lwm2m_engine_obj_inst *obj_inst,
                                       struct lwm2m_engine_obj_field **obj_field) {
	uint8_t len;
	__CPROVER_assume(len >= sizeof(struct lwm2m_engine_obj_field));
	*obj_field = malloc(len);
	__CPROVER_assume(*obj_field != NULL);

	}

int harness() {
	struct lwm2m_message *msg = malloc(sizeof(struct lwm2m_message));
	__CPROVER_assume(msg != NULL);

	struct lwm2m_ctx *ctx = malloc(sizeof(struct lwm2m_ctx));
	__CPROVER_assume(ctx != NULL);
	msg->ctx = ctx;

	struct lwm2m_block_context *block_ctx = malloc(sizeof(struct lwm2m_block_context));
	__CPROVER_assume(block_ctx != NULL);
	msg->in.block_ctx = block_ctx;

	struct coap_packet *cpkt = malloc(sizeof(struct coap_packet));
	__CPROVER_assume(cpkt != NULL);
	msg->in.in_cpkt = cpkt;

	uint16_t data_len;
	uint8_t *data = malloc(data_len);
	__CPROVER_assume(data != NULL);
	msg->in.in_cpkt->data = data;
	msg->in.in_cpkt->max_len = data_len;

	do_write_op_tlv(msg);
}

int main() {

	harness();
	return 0;
}
