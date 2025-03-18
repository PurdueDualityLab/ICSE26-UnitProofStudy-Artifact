
#include <sys/types.h>


/* FreeRTOS+TCP includes. */
#include "FreeRTOS_IP.h"
#include "FreeRTOS_IP_Private.h"
#include "FreeRTOS_ICMP.h"
#include "FreeRTOS_Sockets.h"
#include "FreeRTOS_UDP_IP.h"
#include "FreeRTOS_DHCP.h"
#include "NetworkInterface.h"
#include "NetworkBufferManagement.h"
#include "FreeRTOS_DNS.h"

eFrameProcessingResult_t ProcessICMPPacket( const NetworkBufferDescriptor_t * const pxNetworkBuffer );

void harness() {

    NetworkBufferDescriptor_t *pxNetworkBuffer = malloc(sizeof(NetworkBufferDescriptor_t));
    __CPROVER_assume(pxNetworkBuffer != NULL);

    size_t dataLength;
    uint8_t *pucEthernetBuffer = malloc(dataLength);
    __CPROVER_assume(pucEthernetBuffer != NULL);

    pxNetworkBuffer->pucEthernetBuffer = pucEthernetBuffer;
    pxNetworkBuffer->xDataLength = dataLength;

    ProcessICMPPacket(pxNetworkBuffer);

}