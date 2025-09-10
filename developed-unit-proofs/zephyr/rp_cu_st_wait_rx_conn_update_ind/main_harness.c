#include <stdint.h>

// #include "zephyr/sys/slist.h"

// #include "ll_sw/pdu_df.h"
// #include "util/memq.h"
// #include "ll_sw/nordic/lll/pdu_vendor.h"
// #include "ll_sw/pdu.h"
// #include "ll_sw/ull_llcp_internal.h"

#include <zephyr/kernel.h>

#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/slist.h>
#include <zephyr/sys/util.h>

#include <zephyr/bluetooth/hci_types.h>

#include "hal/ccm.h"

#include "util/util.h"
#include "util/mem.h"
#include "util/memq.h"
#include "util/dbuf.h"

#include "pdu_df.h"
#include "lll/pdu_vendor.h"
#include "pdu.h"

#include "ll.h"
#include "ll_feat.h"
#include "ll_settings.h"

#include "lll.h"
#include "lll/lll_df_types.h"
#include "lll_conn.h"

#include "lll_conn_iso.h"

#include "ull_tx_queue.h"

#include "isoal.h"
#include "ull_iso_types.h"
#include "ull_conn_iso_types.h"
#include "ull_conn_iso_internal.h"

#include "ull_conn_internal.h"
#include "ull_conn_types.h"

#if defined(CONFIG_BT_CTLR_USER_EXT)
#include "ull_vendor.h"
#endif /* CONFIG_BT_CTLR_USER_EXT */

#include "ull_internal.h"
#include "ull_llcp.h"
#include "ull_llcp_features.h"
#include "ull_llcp_internal.h"

#include <soc.h>
#include "hal/debug.h"

void rp_cu_st_wait_rx_conn_update_ind(struct ll_conn *conn, struct proc_ctx *ctx,
					     uint8_t evt, void *param);

int harness() {

	struct ll_conn conn;

	// Model ctx struct:

	struct proc_ctx ctxs;

	uint8_t rxlen;
	__CPROVER_assume(rxlen > sizeof(struct node_rx_pdu) + sizeof(struct node_rx_cu));

	struct node_rx_pdu *ntf = malloc(rxlen);
	__CPROVER_assume(ntf != NULL);
	ctxs.node_ref.rx = ntf;

	uint8_t txlen;
	__CPROVER_assume(txlen > sizeof(struct node_tx) + sizeof(struct pdu_data));

	struct node_tx *tx = malloc(txlen);
	__CPROVER_assume(tx != NULL);
	ctxs.node_ref.tx = tx;



	uint8_t evt;

	// Model pdu data struct:
	uint8_t datalen;
	__CPROVER_assume(datalen > sizeof(struct pdu_data));
	struct pdu_data *data = (struct pdu_data *) malloc(datalen);
	__CPROVER_assume(data != NULL);

	// struct pdu_data pdata;

	rp_cu_st_wait_rx_conn_update_ind(&conn, &ctxs, evt, data);
}

int main() {

	harness();
	return 0;
}
