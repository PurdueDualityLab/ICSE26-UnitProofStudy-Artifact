/**
 * @file _harness.c
 * @brief TODO
 */

 #include "FreeRTOS.h"
 #include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"
#include "FreeRTOS_IP_Private.h"
 
 List_t xBoundTCPSocketsList;
 _Bool ipv6;

 FreeRTOS_Socket_t * pxTCPSocketLookup( uint32_t ulLocalIP,
    UBaseType_t uxLocalPort,
    IPv46_Address_t xRemoteIP,
    UBaseType_t uxRemotePort ) {
     FreeRTOS_Socket_t *socket = malloc(sizeof(FreeRTOS_Socket_t));
 
     FreeRTOS_Socket_t *peerSocket = malloc(sizeof(FreeRTOS_Socket_t));
 
     __CPROVER_assume(peerSocket != NULL);
     peerSocket->bits.bIsIPv6 = ipv6;
 
     if (socket != NULL) {
         socket->u.xTCP.pxPeerSocket = peerSocket;
         socket->bits.bIsIPv6 = ipv6;
     }
 
     return socket;
 }
 
 FreeRTOS_Socket_t * prvHandleListen( FreeRTOS_Socket_t * pxSocket,
     NetworkBufferDescriptor_t * pxNetworkBuffer ) {
         FreeRTOS_Socket_t *socket = malloc(sizeof(FreeRTOS_Socket_t));
 
         FreeRTOS_Socket_t *peerSocket = malloc(sizeof(FreeRTOS_Socket_t));
 
         __CPROVER_assume(peerSocket != NULL);
         peerSocket->bits.bIsIPv6 = ipv6;
 
         if (socket != NULL) {
             socket->bits.bIsIPv6 = ipv6;
             socket->u.xTCP.pxPeerSocket = peerSocket;
         }
 
         return socket;
     }
 
     size_t uxIPHeaderSizePacket( const NetworkBufferDescriptor_t * pxNetworkBuffer )
     {
         size_t uxResult;
         /* Map the buffer onto Ethernet Header struct for easy access to fields. */
         /* MISRA Ref 11.3.1 [Misaligned access] */
         /* More details at: https://github.com/FreeRTOS/FreeRTOS-Plus-TCP/blob/main/MISRA.md#rule-113 */
         /* coverity[misra_c_2012_rule_11_3_violation] */
         const EthernetHeader_t * pxHeader = ( ( const EthernetHeader_t * ) pxNetworkBuffer->pucEthernetBuffer );
     
         if( pxHeader->usFrameType == ( uint16_t ) ipIPv6_FRAME_TYPE )
         {
             uxResult = ipSIZE_OF_IPv6_HEADER;
         }
         else
         {
             uxResult = ipSIZE_OF_IPv4_HEADER;
         }
     
         return uxResult;
     }

     size_t uxIPHeaderSizeSocket( const FreeRTOS_Socket_t * pxSocket )
     {
         size_t uxResult;
     
         if( ( pxSocket != NULL ) && ( pxSocket->bits.bIsIPv6 != pdFALSE_UNSIGNED ) )
         {
             uxResult = ipSIZE_OF_IPv6_HEADER;
         }
         else
         {
             uxResult = ipSIZE_OF_IPv4_HEADER;
         }
     
         return uxResult;
     }
 /**
  * @brief Starting point for formal analysis
  * 
  */
 void harness(void)
 {
 
     // Create a network buffer
 
     NetworkBufferDescriptor_t buff;
 
     size_t dataLength;

     __CPROVER_assume(dataLength > sizeof(EthernetHeader_t));
 
     // Allocate some data:
 
     buff.pucEthernetBuffer = malloc(dataLength);
     __CPROVER_assume(buff.pucEthernetBuffer != NULL);

     __CPROVER_assume(((EthernetHeader_t *) buff.pucEthernetBuffer)->usFrameType != ipIPv6_FRAME_TYPE || ipv6);
     __CPROVER_assume(((EthernetHeader_t *) buff.pucEthernetBuffer)->usFrameType == ipIPv6_FRAME_TYPE || !ipv6);
 
     buff.xDataLength = dataLength;

     ListItem_t * pxIterator = malloc(sizeof(ListItem_t));
     __CPROVER_assume(pxIterator != NULL);

     FreeRTOS_Socket_t *sock = malloc(sizeof(FreeRTOS_Socket_t));
     __CPROVER_assume(sock != NULL);
     pxIterator->pvOwner = sock;
     pxIterator->pxNext = &xBoundTCPSocketsList.xListEnd;

     xBoundTCPSocketsList.xListEnd.pxNext = pxIterator;

 
     BaseType_t res = xProcessReceivedTCPPacket( &buff );
 }