#include <tbs.h>
// #include "tbs_internal.h"

bool bt_tbs_valid_uri(const char *uri, size_t len)
{
	bool ret;
	return ret;
}


void harness()
{
	uint8_t bearer_index;

	uint8_t buf_len;
	// We want to restrict the length of strings we havoc so we can fully unrol strlen
	__CPROVER_assume(buf_len > 0 && buf_len < 10);
	char *to = malloc(buf_len);
	__CPROVER_assume(to != NULL);
	// Because character pointers are string, we need to make it a valid string
	to[buf_len - 1] = '\0';

	uint8_t buf2_len;
	__CPROVER_assume(buf2_len > 0 && buf2_len < 10);
	char *from = malloc(buf2_len);
	__CPROVER_assume(from != NULL);
	from[buf2_len - 1] = '\0';


	uint8_t friendly_name_len;
	__CPROVER_assume(friendly_name_len > 0 && friendly_name_len < 10);
	char *friendly_name = malloc(friendly_name_len);
	if (friendly_name != NULL) {
		friendly_name[friendly_name_len - 1] = '\0';
	}
	

	int a = bt_tbs_remote_incoming(bearer_index, to, from, friendly_name);
}

int main(void)
{

	harness();
	return 0;
}
