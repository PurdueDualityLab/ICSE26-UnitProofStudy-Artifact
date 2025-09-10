/**
 * @file qcmd_harness.c
 * @author Taylor Le Lievre (tlelievr@purdue.edu)
 * @brief Harness for queue_encapsulated_cmd
 * @version 0.1
 * @date 2024-09-24
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdlib.h>
#include <stdint.h>

#include "zephyr/net/buf.h"

int queue_encapsulated_cmd(uint8_t *data, uint32_t len);



void harness() {
    uint32_t len;
    __CPROVER_assume(len <= 100);
    uint8_t* data = malloc(len);

    __CPROVER_assume(data != NULL);

    queue_encapsulated_cmd(data, len);
}

int main(void) {
    harness();
    return 0;
}
