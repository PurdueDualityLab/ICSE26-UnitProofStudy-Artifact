#include <stdint.h>
#include <stdlib.h>

#include "zephyr/settings/settings.h"
#include "zephyr/shell/shell.h"

extern struct settings_store *settings_save_dst;

// void shell_error_impl(const struct shell *sh, const char *fmt, ...) {}

int dummy_csi_save(struct settings_store *cs, const char *name,
			const char *value, size_t val_len) {}

int cmd_write(const struct shell *shell_ptr, size_t argc, char *argv[]);

void settings_store_init(void);

char *valid_string() {

	// Define string size:

	uint16_t size;

	// Won't be zero:

	__CPROVER_assume(size > 0 && size < 20);

	// Allocate data:

	char *data = malloc(size);

	__CPROVER_assume(data != NULL);

	// Put null character in final position:

	data[size - 1] = '\0';

	// Return the data:

	return data;
}

int harness() {

	// settings_store_init();
	
	// Model global settings:

	settings_save_dst = malloc(sizeof(struct settings_store));
	__CPROVER_assume(settings_save_dst != NULL);
	// settings_save_dst->cs_itf = malloc(sizeof(struct settings_store_itf));

	// Create settings_store_itf struct:

	struct settings_store_itf *itfs = malloc(sizeof(struct settings_store_itf));

	__CPROVER_assume(itfs != NULL);

	// Assign dummy function:

	itfs->csi_save = dummy_csi_save;

	// Attach itf struct to global settings store:

	settings_save_dst->cs_itf = itfs;

	// Model input arguments:

	size_t argc;

	// Place a limit on the number of arguments:

	__CPROVER_assume(argc < 5 && argc > 1);

	// Create argument array:

	char *argv[argc];

	// Create valid string for each value in the arg array:

	for (int i = 0; i < argc; ++i) {

		argv[i] = valid_string();
	}

	// Unconstrained shell struct:

	const struct shell shell;

	int res = cmd_write(&shell, argc, argv);
}

int main() {

	harness();
	return 0;
}
