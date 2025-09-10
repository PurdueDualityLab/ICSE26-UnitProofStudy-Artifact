/**
 * @file _harness.c
 * @brief TODO
 */

#include <stdlib.h>

#include "FreeRTOS.h"

#include "task.h"

#include "FreeRTOS_DNS.h"

uint32_t DNS_ParseDNSReply( uint8_t * pucUDPPayloadBuffer, size_t uxBufferLength, struct freertos_addrinfo ** ppxAddressInfo, BaseType_t xExpected, uint16_t usPort ) {

    // Allocate address info:

    struct freertos_addrinfo *pxAddressInfo = (struct freertos_addrinfo *)malloc(sizeof(struct freertos_addrinfo));

    // Set address info to allocated data

    if (pxAddressInfo != NULL) {
        pxAddressInfo->ai_next = NULL;
    }

    *ppxAddressInfo = pxAddressInfo; 

    // Return unconstrained uint32_t

    uint32_t res;

    return res;
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    NetworkBufferDescriptor_t *buff = malloc(sizeof(NetworkBufferDescriptor_t));
    __CPROVER_assume(buff != NULL);

    // Constrain the size:

    __CPROVER_assume(buff->xDataLength >= sizeof(EthernetHeader_t));  // MUST be larger than ethernet header

    // Allocate input data:

    buff->pucEthernetBuffer = malloc(buff->xDataLength);

    __CPROVER_assume(buff->pucEthernetBuffer != NULL);  // Data will not be NULL

    uint32_t res = ulDNSHandlePacket(buff);
}
