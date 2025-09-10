#include <stdint.h>
#include <stdlib.h>

#include "zephyr/bluetooth/addr.h"
#include "zephyr/sys/slist.h"

#include "util/util.h"
#include "util/memq.h"
#include "util/mem.h"
#include "util/mayfly.h"
#include "util/dbuf.h"

#include "hal/cpu.h"
#include "hal/ccm.h"
#include "hal/radio.h"
#include "hal/ticker.h"

#include "ticker/ticker.h"

#include "pdu_df.h"
#include "openisa/lll/pdu_vendor.h"
#include "pdu.h"

#include "lll.h"
#include "lll_clock.h"
// #include "lll/lll_vendor.h"
#include "lll/lll_adv_types.h"
#include "lll_adv.h"
// #include "lll/lll_adv_pdu.h"
#include "lll_chan.h"
// #include "lll/lll_df_types.h"
#include "lll_conn.h"
#include "lll_peripheral.h"
#include "lll_filter.h"
#include "lll_conn_iso.h"

#include "ll_sw/ull_tx_queue.h"

#include "ull_adv_types.h"
#include "ull_conn_types.h"
#include "ull_filter.h"

#include "ull_internal.h"
#include "ull_adv_internal.h"
#include "ull_conn_internal.h"
#include "ull_peripheral_internal.h"

#include "ll.h"

#include "ll_sw/isoal.h"
#include "ll_sw/ull_iso_types.h"
#include "ll_sw/ull_conn_iso_types.h"
#include "ll_sw/ull_llcp.h"

extern struct ll_adv_set ll_adv[BT_CTLR_ADV_SET];

struct pdu_adv* lll_adv_pdu_alloc(struct lll_adv *lll,
						     uint8_t *idx)
{
	struct pdu_adv* new_pdu = malloc(sizeof(struct pdu_adv));
	__CPROVER_assume(new_pdu != NULL);
	return new_pdu;
}

int harness() {


	//Presumably, data buffer input length
	uint8_t len;

	//Data buffer
	uint8_t* data = malloc(len);
	__CPROVER_assume(data != NULL);


	uint8_t pdu_offset;
	__CPROVER_assume(pdu_offset < BT_CTLR_ADV_SET);
	struct ll_adv_set *adv = ll_adv + (pdu_offset * sizeof(struct ll_adv_set));


	__CPROVER_assume(adv->lll.scan_rsp.last < DOUBLE_BUFFER_SIZE);

	uint8_t pdulen;
	__CPROVER_assume(pdulen > sizeof(struct pdu_adv));
	uint8_t *pdu1 = malloc(pdulen);
	__CPROVER_assume(pdu1 != NULL);
	uint8_t *pdu2 = malloc(pdulen);
	__CPROVER_assume(pdu2 != NULL);

	adv->lll.scan_rsp.pdu[0] = pdu1;
	adv->lll.scan_rsp.pdu[1] = pdu2;

	__CPROVER_assume(adv->lll.adv_data.last < DOUBLE_BUFFER_SIZE);

	uint8_t pdulen1;
	__CPROVER_assume(pdulen1 > sizeof(struct pdu_adv));
	uint8_t *pdu11 = malloc(pdulen1);
	__CPROVER_assume(pdu11 != NULL);
	uint8_t *pdu21 = malloc(pdulen);
	__CPROVER_assume(pdu21 != NULL);

	adv->lll.adv_data.pdu[0] = pdu11;
	adv->lll.adv_data.pdu[1] = pdu21;

	ull_scan_rsp_set(adv, len, data);
}

int main() {

	harness();
	return 0;
}
