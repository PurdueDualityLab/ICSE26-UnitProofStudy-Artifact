/**
 * @file gcc_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for get_channel_for_cid
 * @version 0.1
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/mac/ble/ble-l2cap.h"
#include "net/linkaddr.h"
#include "net/packetbuf.h"
#include "net/netstack.h"

extern uint8_t l2cap_channel_count;

typedef struct {
  /* L2CAP Service Data Unit (SDU) (= packet data)*/
  uint8_t sdu[BLE_L2CAP_NODE_MTU];
  /* length of the L2CAP SDU */
  uint16_t sdu_length;
  /* index of the first byte not sent yet */
  uint16_t current_index;
} l2cap_buffer_t;
/*---------------------------------------------------------------------------*/
typedef struct {
  uint16_t cid;
  uint16_t mtu;
  uint16_t mps;
  uint16_t credits;
} ble_mac_l2cap_channel_t;
/*---------------------------------------------------------------------------*/
typedef struct {
  ble_mac_l2cap_channel_t channel_own;
  ble_mac_l2cap_channel_t channel_peer;
  l2cap_buffer_t tx_buffer;
  l2cap_buffer_t rx_buffer;
  linkaddr_t peer_addr;
} l2cap_channel_t;


int * send_stub(const void *payload, unsigned short payload_len) {
    // Adding to stub a function pointer

}

void
input_l2cap_frame_signal_channel(uint8_t *data, uint8_t data_len) {

}

void
input_l2cap_frame_flow_channel(l2cap_channel_t *channel, uint8_t *data, uint16_t data_len) {

}

static uint8_t datalen;

void *
packetbuf_dataptr(void)
{
    __CPROVER_assume(datalen > 4);
  uint8_t *data = malloc(datalen);
  __CPROVER_assume(data != NULL);
  return data;
}

uint16_t packetbuf_datalen(void) {
    return datalen;
}

void harness() {
    __CPROVER_assume(l2cap_channel_count <= L2CAP_CHANNELS);
    NETSTACK_RADIO.send = send_stub;
    input();
}
