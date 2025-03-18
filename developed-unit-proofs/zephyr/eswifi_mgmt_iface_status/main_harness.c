#include <stdint.h>

#include "zephyr/device.h"
#include "zephyr/net/wifi_mgmt.h"
#include "wifi/eswifi/eswifi.h"

// Dummy callback function
int request(struct eswifi_dev *eswifi, char *cmd, size_t clen, char *rsp, size_t rlen) {
	int res;

	return res;
}

int harness() {

	// Model device struct

	struct device *dev = malloc(sizeof(struct device));

	__CPROVER_assume(dev != NULL);

	// Create internal wifi device:

	struct eswifi_dev *wifi_dev = malloc(sizeof(struct eswifi_dev));

	__CPROVER_assume(wifi_dev != NULL);

	// Create bus object:

	struct eswifi_bus_ops *bus = malloc(sizeof(struct eswifi_bus_ops));

	__CPROVER_assume(bus != NULL);

	// Set callback function:

	bus->request = request;

	// Add bus to wifi device:

	wifi_dev->bus = bus;

	// Attach wifi device to the device data:

	dev->data = wifi_dev;

	// Model wifi struct:

	struct wifi_iface_status status;

	int val = eswifi_mgmt_iface_status(dev, &status);
}

int main() {

	harness();
	return 0;
}
