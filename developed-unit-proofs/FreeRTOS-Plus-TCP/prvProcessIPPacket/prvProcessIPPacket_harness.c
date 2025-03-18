/**
 * @file _harness.c
 * @brief TODO
 */

 #include <stddef.h>
#include <stdlib.h>

 #include "FreeRTOS.h"
 #include "FreeRTOS_IP.h"
 
 /**
  * @brief Starting point for formal analysis
  * 
  */
 void harness(void)
 {
 
     // Model input arguments
 
     IPPacket_t pack;
 
     NetworkBufferDescriptor_t buff;
 
     // Allocate data in buffer:
 
     size_t dataLength;
     size_t headerSizes = ipSIZE_OF_ETH_HEADER;
     __CPROVER_assume(dataLength > ipIP_TYPE_OFFSET + headerSizes);
 
     buff.pucEthernetBuffer = malloc(dataLength);
 
     // Allocated data will not be NULL
 
     __CPROVER_assume(buff.pucEthernetBuffer != NULL);

     buff.pucEthernetBuffer += ipIP_TYPE_OFFSET;
     buff.xDataLength = dataLength - ipIP_TYPE_OFFSET;
 
     eFrameProcessingResult_t res = prvProcessIPPacket( &pack, &buff );
 }