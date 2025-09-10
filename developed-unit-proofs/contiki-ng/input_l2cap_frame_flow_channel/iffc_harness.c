/**
 * @file iffc_harness.c
 * @author Owen Cochell (owencochell@gmail.com)
 * @brief Harness for input_l2cap_frame_flow_channel
 * @version 0.1
 * @date 2024-06-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "contiki.h"
#include "net/mac/ble/ble-l2cap.h"

#include "gnet/packetbuf-generic.h"
#include "l2cap-struct.h"

static uint16_t bufsize;

uint16_t
packetbuf_remaininglen(void) {

    return bufsize;

}

void *packetbuf_dataptr(void)
{
    uint8_t *data = malloc(bufsize);
    __CPROVER_assume(data != NULL);
    return data;
}

void harness() {

    // Create packetbuf:

    l2cap_channel_t channel;

    uint16_t len;

    __CPROVER_assume(channel.rx_buffer.sdu_length != 0 || len > 6);

    // Define channel data:

    uint8_t *data = malloc(len);
    __CPROVER_assume(data != NULL);

    input_l2cap_frame_flow_channel(&channel, data, len);
}
