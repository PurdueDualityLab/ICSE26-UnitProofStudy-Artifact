#include <stdint.h>
#include <stdlib.h>
#include <time.h>

// #include header files
#include "zephyr/usb/usb_ch9.h"

#define USB_DFU_MAX_XFER_SIZE		CONFIG_USB_REQUEST_BUFFER_SIZE

int dfu_class_handle_to_device(struct usb_setup_packet *setup,
				      int32_t *data_len, uint8_t **data);


int harness() {

	// Model inputs
	struct usb_setup_packet *setup = malloc(sizeof(struct usb_setup_packet));

	__CPROVER_assume(setup != NULL);

	int32_t data_len;

	uint8_t *data = malloc(data_len);

	__CPROVER_assume(data != NULL);

	// Uncomment to recreate CVE-2021-3625
	__CPROVER_assume(setup->wLength <= MIN(data_len, USB_DFU_MAX_XFER_SIZE));

	// Call target function
	dfu_class_handle_to_device(setup, &data_len, &data);
}

int main() {

	harness();
	return 0;
}
