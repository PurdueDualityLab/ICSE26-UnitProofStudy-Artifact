#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "net/wifi.h"

int harness() {

	uint8_t str_size;
	__CPROVER_assume(str_size > 0);
	char* str = malloc(str_size);
	__CPROVER_assume(str != NULL);
	str[str_size - 1] = '\0';
	uint8_t ssid_size;
	__CPROVER_assume(ssid_size >= WIFI_SSID_MAX_LEN);
	char* ssid = malloc(ssid_size);
	__CPROVER_assume(ssid != NULL);
	ssid[ssid_size - 1] = '\0';
	__parse_ssid(str, ssid);
}

int main() {

	harness();
	return 0;
}
