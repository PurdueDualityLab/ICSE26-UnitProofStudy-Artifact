/**
 * @file _harness.c
 * @brief TODO
 */

#include "FreeRTOS.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"


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

    // Define some data size:

    size_t size;

    // A well-formed option MUST be at least two bytes
    // Or, it must be a single byte specifying the end of an option
    // We get out of bounds errors when this is not enforced
    // Potential vulnerability?

    __CPROVER_assume(size >= 1);

    // Allocate some data:

    uint8_t* data = (uint8_t*)malloc(size);

    // No NULL checks present, data will NOT be NULL:

    __CPROVER_assume(data != NULL);

    // Model other input types:

    FreeRTOS_Socket_t pxSocket;
    BaseType_t xHasSYNFlag;

    // Add function pointer to dummy callback:

    pxSocket.u.xTCP.pxHandleSent = sock_call;

    int32_t res = prvSingleStepTCPHeaderOptions( data, size, &pxSocket, xHasSYNFlag);
}
