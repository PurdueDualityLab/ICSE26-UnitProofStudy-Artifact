/**
 * @file uhi_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harnesses the uncompress_hdr_iphc function
 * @version 0.1
 * @date 2024-06-20
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/packetbuf.h" 
#include "net/ipv6/sicslowpan.h"
#include "net/ipv6/uip.h"

// #include "gnet/packetbuf-generic.h"

extern uint8_t *packetbuf_ptr;
extern uint8_t packetbuf_hdr_len;
extern int packetbuf_payload_len;
static uint16_t buflen;

uint16_t
packetbuf_datalen(void)
{
  return buflen;
}

void harness() {

    uint8_t pbuf_size, hdr_len;

    __CPROVER_assume(pbuf_size > 0);

    // Ensure packetbuf is valid:
    packetbuf_ptr = (uint8_t *) malloc(pbuf_size);
    __CPROVER_assume(packetbuf_ptr != NULL);

    __CPROVER_assume(hdr_len < 100); // If this value is large, it causes an overflow when used for an arithmetic operation

    packetbuf_hdr_len = hdr_len;

    buflen = pbuf_size;


    const uint16_t outb_size;
    __CPROVER_assume(outb_size >= sizeof(struct uip_ip_hdr));

    uint8_t* outb = (uint8_t*)malloc(sizeof(uint8_t) * outb_size);

    __CPROVER_assume(outb != NULL);


    uint16_t ip_legnth;
    

    bool res = uncompress_hdr_iphc(outb, outb_size, ip_legnth);
}
