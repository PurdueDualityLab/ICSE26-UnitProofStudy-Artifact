#include <stdint.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/buf.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/hci.h>
#include <zephyr/debug/stack.h>
#include <zephyr/kernel.h>
#include <zephyr/net/buf.h>
#include <zephyr/sys/__assert.h>
#include <zephyr/sys/atomic.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/check.h>
#include <zephyr/sys/util.h>

#include "hci_core.h"
#include "ecc.h"
#include "keys.h"
#include "conn_internal.h"
#include "l2cap_internal.h"
#include "smp.h"
#include "slist.h"

void smp_pairing_complete(struct bt_smp *smp, uint8_t status) {}

struct net_buf *net_buf_alloc_fixed(struct net_buf_pool *pool, k_timeout_t timeout) {

	// Allocate buffer:

	uint8_t buflen;
	__CPROVER_assume(buflen > sizeof(struct net_buf));

	struct net_buf *buf = (struct net_buf *)malloc(buflen);
	
	if (buf == NULL) {
		return NULL;
	}

	uint8_t size;
	buf->data = malloc(size);
	__CPROVER_assume(buf->data != NULL);
	buf->__buf = buf->data;
	buf->size = size;
	uint8_t len;
	__CPROVER_assume(len + sizeof(struct bt_smp_pairing_fail) < size);
	buf->len = len;

	buf->user_data_size = buflen - sizeof(struct net_buf);

	return buf;
}

struct net_buf *bt_l2cap_create_pdu_timeout(struct net_buf_pool *pool, size_t reserve, k_timeout_t timeout) {

	// Return new allocated buffer:

	k_timeout_t val;

	return net_buf_alloc_fixed(NULL, val);
}

enum {
	SMP_FLAG_CFM_DELAYED,   /* if confirm should be send when TK is valid */
	SMP_FLAG_ENC_PENDING,   /* if waiting for an encryption change event */
	SMP_FLAG_KEYS_DISTR,    /* if keys distribution phase is in progress */
	SMP_FLAG_PAIRING,       /* if pairing is in progress */
	SMP_FLAG_TIMEOUT,       /* if SMP timeout occurred */
	SMP_FLAG_SC,            /* if LE Secure Connections is used */
	SMP_FLAG_PKEY_SEND,     /* if should send Public Key when available */
	SMP_FLAG_DHKEY_PENDING, /* if waiting for local DHKey */
	SMP_FLAG_DHKEY_GEN,     /* if generating DHKey */
	SMP_FLAG_DHKEY_SEND,    /* if should generate and send DHKey Check */
	SMP_FLAG_USER,          /* if waiting for user input */
	SMP_FLAG_DISPLAY,       /* if display_passkey() callback was called */
	SMP_FLAG_OOB_PENDING,   /* if waiting for OOB data */
	SMP_FLAG_BOND,          /* if bonding */
	SMP_FLAG_SC_DEBUG_KEY,  /* if Secure Connection are using debug key */
	SMP_FLAG_SEC_REQ,       /* if Security Request was sent/received */
	SMP_FLAG_DHCHECK_WAIT,  /* if waiting for remote DHCheck (as periph) */
	SMP_FLAG_DERIVE_LK,     /* if Link Key should be derived */
	SMP_FLAG_BR_CONNECTED,  /* if BR/EDR channel is connected */
	SMP_FLAG_BR_PAIR,       /* if should start BR/EDR pairing */
	SMP_FLAG_CT2,           /* if should use H7 for keys derivation */

	/* Total number of flags - must be at the end */
	SMP_NUM_FLAGS,
};

// Copied from private source file:
struct bt_smp {
	/* Commands that remote is allowed to send */
	ATOMIC_DEFINE(allowed_cmds, BT_SMP_NUM_CMDS);

	/* Flags for SMP state machine */
	ATOMIC_DEFINE(flags, SMP_NUM_FLAGS);

	/* Type of method used for pairing */
	uint8_t method;

	/* Pairing Request PDU */
	uint8_t preq[7];

	/* Pairing Response PDU */
	uint8_t prsp[7];

	/* Pairing Confirm PDU */
	uint8_t pcnf[16];

	/* Local random number */
	uint8_t prnd[16];

	/* Remote random number */
	uint8_t rrnd[16];

	/* Temporary key */
	uint8_t tk[16];

	/* Remote Public Key for LE SC */
	uint8_t pkey[BT_PUB_KEY_LEN];

	/* DHKey */
	uint8_t dhkey[BT_DH_KEY_LEN];

	/* Remote DHKey check */
	uint8_t e[16];

	/* MacKey */
	uint8_t mackey[16];

	/* LE SC passkey */
	uint32_t passkey;

	/* LE SC passkey round */
	uint8_t passkey_round;

	/* LE SC local OOB data */
	const struct bt_le_oob_sc_data *oobd_local;

	/* LE SC remote OOB data */
	const struct bt_le_oob_sc_data *oobd_remote;

	/* Local key distribution */
	uint8_t local_dist;

	/* Remote key distribution */
	uint8_t remote_dist;

	/* The channel this context is associated with.
	 * This marks the beginning of the part of the structure that will not
	 * be memset to zero in init.
	 */
	struct bt_l2cap_le_chan chan;

	/* Delayed work for timeout handling */
	struct k_work_delayable work;

	/* Used Bluetooth authentication callbacks. */
	atomic_ptr_t auth_cb;

	/* Bondable flag */
	atomic_t bondable;
};

int harness() {

	// Model input struct:

	struct bt_smp bts;

	struct bt_conn *conn = malloc(sizeof(struct bt_conn));
	__CPROVER_assume(conn != NULL);

	if (conn != NULL) {
		conn->l2cap_data_ready.tail = malloc(sizeof(sys_snode_t));
		conn->l2cap_data_ready.head = malloc(sizeof(sys_snode_t));
	}
	bts.chan.chan.conn = conn;

	uint8_t reason;

	int res = smp_error(&bts, reason);
}

int main() {

	harness();
	return 0;
}
