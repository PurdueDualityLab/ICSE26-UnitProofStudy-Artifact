#include <hci.c>

void harness()
{

	struct pdu_adv *pdu_data = malloc(sizeof(struct pdu_adv));
	__CPROVER_assume(pdu_data != NULL);
	struct node_rx_pdu *node_rx = malloc(sizeof(struct node_rx_pdu));
	__CPROVER_assume(node_rx != NULL);

	__CPROVER_assume(pdu_data->type < 7);

	uint8_t buflen;
	
	__CPROVER_assume(buflen > sizeof(struct net_buf));
	struct net_buf *buf = malloc(buflen);
	__CPROVER_assume(buf != NULL);

	uint16_t size;
	__CPROVER_assume(size < 1000);
	uint8_t *data = malloc(size);
	__CPROVER_assume(data != NULL);
	uint16_t len;
	uint16_t datalen;
	__CPROVER_assume(pdu_data->type == PDU_ADV_TYPE_DIRECT_IND || datalen >= (pdu_data->len - BDADDR_SIZE));
	__CPROVER_assume(pdu_data->type != PDU_ADV_TYPE_DIRECT_IND || datalen >= 0);
	__CPROVER_assume(pdu_data->len <= PDU_AC_LEG_DATA_SIZE_MAX);
	__CPROVER_assume(pdu_data->len >= BDADDR_SIZE); // Uncomment to expose the vulnerability

	uint16_t advinfo_datalen;
	__CPROVER_assume(advinfo_datalen < 1000);

	__CPROVER_assume(advinfo_datalen >= datalen);
	
	uint16_t minspace = sizeof(struct bt_hci_evt_le_advertising_report) + 
						sizeof(struct bt_hci_evt_le_advertising_info) + 
						sizeof(int8_t) + datalen +
						sizeof(struct bt_hci_evt_le_advertising_report) +
						sizeof(struct bt_hci_evt_le_advertising_info) + advinfo_datalen;

	__CPROVER_assume(minspace <= size - len);
	__CPROVER_assume(len <= size);
	buf->data = data;
	buf->size = size;
	buf->len = len;
	buf->__buf = data;

	// Global vars
	__CPROVER_assume(dup_curr < CONFIG_BT_CTLR_DUP_FILTER_LEN);
	

	le_advertising_report((struct pdu_data *) pdu_data, node_rx, buf);
}

int main(void)
{
	harness();
	return 0;
}
