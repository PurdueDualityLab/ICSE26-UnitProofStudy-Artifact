#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define PATH_MAX        6	/* # chars in a path name including nul */

bool is_mount_point(const char *path);

char* dirname(char* path) {

	// Just allocate some data and return:

	uint16_t size;

	__CPROVER_assume(size <= PATH_MAX && size > 0);

	char* ret = malloc(sizeof(char) * size);

	__CPROVER_assume(ret != NULL);

	// Determine if we need to add null character:

	ret[size - 1] = '\0';

	return ret;
}

int harness() {

	// Allocate some data:

	uint16_t size;

	// Size will not be zero:

	__CPROVER_assume(size > 0);

	char* path = malloc(sizeof(char) * size);
	__CPROVER_assume(path != NULL);

	// Need to add null character to string:

	path[size - 1] = '\0';

	is_mount_point(path);
}

bool is_mount_point(const char *path)
{
	char dir_path[PATH_MAX];
	size_t len;

	len = strlen(path);
	if (len >=  sizeof(dir_path)) {
		return false;
	}

	memcpy(dir_path, path, len);
	dir_path[len] = '\0';
	// sprintf(dir_path, "%s", path);
	return strcmp(dirname(dir_path), "/") == 0;
}

int main() {

	harness();
	return 0;
}
