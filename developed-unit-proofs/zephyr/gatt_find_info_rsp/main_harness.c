#include <stdint.h>

#include "host/conn_internal.h"
#include "host/att_internal.h"
#include "zephyr/bluetooth/gatt.h"

uint8_t bt_gatt_discover_func(struct bt_conn *conn,
					const struct bt_gatt_attr *attr,
					struct bt_gatt_discover_params *params) {
						uint8_t random;

						return random;
					}

void gatt_discover_next(struct bt_conn *conn, uint16_t last_handle,
                    	struct bt_gatt_discover_params *params) {

						}

int harness() {

	// Harness input variables:

	int err;

	// Unconstrained connection struct:

	struct bt_conn conn;

	// Define unconstrained bt_att_find_info_rsp (gets cast to it internally)

	uint16_t length;

	// The 3rd argument is actually pointing to a buffer containing a header and a payload.
	// Reviewing the function shows that the function tries to read beyond the bounds of the initial struct, until it reads all of length (4th argument)
	
	__CPROVER_assume(length > sizeof(struct bt_att_find_info_rsp));

	struct bt_att_find_info_rsp *pdu = malloc(length);

	__CPROVER_assume(pdu != NULL);
	
	// Define an unconstrained bt_gatt_discover_params (gets copied internally)

	struct bt_gatt_discover_params user_data;
	user_data.func = bt_gatt_discover_func;

	gatt_find_info_rsp(&conn, err, pdu, length, &user_data);
}

int main() {

	harness();
	return 0;
}
