// #include <usb_dc_it82xx2.c>

#include <stdint.h>
#include <stdlib.h>

int usb_dc_ep_write(const uint8_t ep, const uint8_t *const data,
		    const uint32_t data_len, uint32_t * const ret_bytes);

void harness()
{

	uint8_t ep;

	int buf_size;
	uint8_t *buf = (uint8_t *) malloc(buf_size);

	__CPROVER_assume(buf != NULL);

	uint32_t ret_bytes;

	usb_dc_ep_write(ep, buf, buf_size, &ret_bytes);
}

int main(void)
{
	harness();
	return 0;
}
