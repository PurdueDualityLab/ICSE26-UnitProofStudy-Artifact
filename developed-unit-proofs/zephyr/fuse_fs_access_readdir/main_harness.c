#include <stdint.h>

#include <fuse.h>

#include <zephyr/fs/fs.h>

#define PATH_MAX 16 /* # chars in a path name including nul */

int add_entry(void *buf, const char *name, off_t off, enum fuse_fill_dir_flags flags) {

	int res;

	return res;
}

char *dirname(char *path) {

	// Just allocate some data and return:

	uint16_t size;

	__CPROVER_assume(size > 0);

	char *ret = malloc(sizeof(char) * size);

	__CPROVER_assume(ret != NULL);

	// Determine if we need to add null character:

	ret[size - 1] = '\0';

	return ret;
}

int harness() {

	// Create valid path string:

	uint16_t psize;

	__CPROVER_assume(psize > 0);

	char *path = malloc(psize);

	__CPROVER_assume(path != NULL);

	path[psize - 1] = '\0';

	// Allocate some junk data for the buffer

	uint16_t bsize;

	uint8_t* buf = malloc(bsize);

	// Unconstrained fuse file info:

	struct fuse_file_info ffi;

	// Unconstrained off value

	off_t off;

	int res = fuse_fs_access_readdir(path, buf, add_entry, off, &ffi);
}

int main() {

	harness();
	return 0;
}
