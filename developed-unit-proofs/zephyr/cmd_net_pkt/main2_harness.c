#include <pkt.c>
#include <shell.c>

void harness()
{

	struct shell sh;
	struct net_pkt pkt;

	__CPROVER_assume(&sh != NULL);
	__CPROVER_assume(&pkt != NULL);
	__CPROVER_assume(pkt.buffer != NULL);

	net_pkt_buffer_hexdump(&sh, &pkt);
}

int main(void)
{
	harness();
	return 0;
}
