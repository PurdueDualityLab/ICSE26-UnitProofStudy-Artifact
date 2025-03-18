// #include <ipm_imx.c>

#include <errno.h>
#include <string.h>
#include <zephyr/device.h>
#include <soc.h>
#include <zephyr/drivers/ipm.h>
#include <zephyr/irq.h>
#include <zephyr/sys/barrier.h>

int imx_mu_ipm_send(const struct device *dev, int wait, uint32_t id,
			   const void *data, int size);

struct imx_mu_config {
	MU_Type *base;
	void (*irq_config_func)(const struct device *dev);
};

void harness()
{
	struct device dev;
	uint16_t config_size;
	__CPROVER_assume(config_size >= sizeof(struct imx_mu_config));
	struct imx_mu_config *config = (struct imx_mu_config *) malloc(config_size);
	__CPROVER_assume(config != NULL);
	config->base = malloc(sizeof(MU_Type));
	__CPROVER_assume(config->base != NULL);
	dev.config = config;

	int wait;
	uint32_t id;
	int size;
	int datalen;

	__CPROVER_assume(size == datalen); // Comment this out to recreate the vuln.

	void *data = malloc(datalen);
	__CPROVER_assume(data != NULL);

	imx_mu_ipm_send(&dev, id, wait, data, size);
}
