/**
 * @file gnh_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for uipbuf_get_next_header
 * @version 0.1
 * @date 2024-06-25
 * 
 * @copyright Copyright (c) 2024
 * 
 */

 #include "contiki.h"
 #include "net/ipv6/uip.h"
 #include "net/ipv6/uipbuf.h"
 
 void harness() {
 
     // Define input buffer size:
 
     uint16_t isize;
 
     // Unconstrained bool:
 
     bool start;
 
     // Define minimum size:
 
     __CPROVER_assume(!start || isize >= sizeof(struct uip_ip_hdr));
     __CPROVER_assume(start || isize >= sizeof(struct uip_ext_hdr));
 
     // Allocate buffer of unconstrained size:
 
     uint8_t *buff = (uint8_t *)malloc(sizeof(uint8_t) * isize);
 
     // Buffer won't be NULL:
 
     __CPROVER_assume(buff != NULL);
 
     // Define unconstrained protocol char
 
     uint8_t proto = 0;
 
     uipbuf_get_next_header(buff, isize, &proto, start);
 }
 