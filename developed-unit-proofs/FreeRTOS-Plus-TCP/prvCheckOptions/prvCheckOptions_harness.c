/**
 * @file _harness.c
 * @brief TODO
 */

#include <stdint.h>

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"

/**
 * @brief Dummy socket send callback
 * 
 * Removes function pointer violation
 * 
 * @param xSocket 
 * @param xLength 
 */
void sock_call( Socket_t xSocket, size_t xLength ) {}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Model socket:

    FreeRTOS_Socket_t pxSocket;

    // Add dummy callback:

    pxSocket.u.xTCP.pxHandleSent = sock_call;

    // Allocate proper stream buffer:

    pxSocket.u.xTCP.txStream = (StreamBuffer_t*)malloc(sizeof(StreamBuffer_t));

    // Model network buffer:

    NetworkBufferDescriptor_t pxNetworkBuffer;

    // Allocate data of size:

    pxNetworkBuffer.pucEthernetBuffer = malloc(pxNetworkBuffer.xDataLength);

    // Data will NOT be NULL

    __CPROVER_assume(pxNetworkBuffer.pucEthernetBuffer != NULL);

    BaseType_t res = prvCheckOptions(&pxSocket, &pxNetworkBuffer );
}
