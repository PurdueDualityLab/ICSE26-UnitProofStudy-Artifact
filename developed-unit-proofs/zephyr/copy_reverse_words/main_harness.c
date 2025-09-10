#include <stdint.h>
#include <stdlib.h>

int harness() {

	int dst_len;
	uint8_t* dst_buf = malloc(dst_len);
	__CPROVER_assume(dst_buf != NULL);

	int src_len;
	uint8_t* src_buf = malloc(src_len);
	__CPROVER_assume(src_buf != NULL);

	copy_reverse_words(dst_buf, dst_len, src_buf, src_len);
}

int main() {

	harness();
	return 0;
}
