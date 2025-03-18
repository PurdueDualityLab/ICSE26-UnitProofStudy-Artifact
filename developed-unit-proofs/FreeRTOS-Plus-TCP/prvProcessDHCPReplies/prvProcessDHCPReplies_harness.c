/**
 * @file _harness.c
 * @brief TODO
 */

#include <stdint.h>

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"

/**
 * @brief Receive data from a bound socket. In this library, the function
 *        can only be used with connection-less sockets (UDP). For TCP sockets,
 *        please use FreeRTOS_recv().
 *
 * @param[in] xSocket The socket to which the data is sent i.e. the
 *                     listening socket.
 * @param[out] pvBuffer The buffer in which the data being received is to
 *                      be stored.
 * @param[in] uxBufferLength The length of the buffer.
 * @param[in] xFlags The flags to indicate preferences while calling this function.
 * @param[out] pxSourceAddress The source address from which the data is being sent.
 * @param[out] pxSourceAddressLength The length of the source address structure.
 *                  This would always be a constant - 24 (in case of no error) as
 *                  FreeRTOS+TCP makes the sizes of IPv4 and IPv6 structures equal
 *                  (24-bytes) for compatibility.
 *
 * @return The number of bytes received. Or else, an error code is returned. When it
 *         returns a negative value, the cause can be looked-up in 'FreeRTOS-Kernel/projdefs.h'.
 */
int32_t FreeRTOS_recvfrom( const ConstSocket_t xSocket, void * pvBuffer, size_t uxBufferLength, BaseType_t xFlags, struct freertos_sockaddr * pxSourceAddress, socklen_t * pxSourceAddressLength ) {

    // Determine a size to copy over:

    uint32_t size;

    // Allocate data of size:

    *((uint8_t**)pvBuffer) = (uint8_t*)malloc(size);

    // Allocated data will not be NULL

    __CPROVER_assume(*((uint8_t**)pvBuffer) != NULL);

    // Return the size

    return size;
}

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{

    // Model input arguments

    BaseType_t type;
    NetworkEndPoint_t *endpoint = malloc(sizeof(NetworkEndPoint_t));
    __CPROVER_assume(endpoint != NULL);

    BaseType_t res = prvProcessDHCPReplies(type, endpoint);
}
