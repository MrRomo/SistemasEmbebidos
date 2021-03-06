#include <stdio.h>     /* forprintf() and fprintf() */
#include <sys/socket.h>/* for socket(), bind(), and connect() */
#include <arpa/inet.h> /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>    /* for atoi() */
#include <string.h>    /* for memset() */
#include <unistd.h>    /* for close() */
#include "HandleTCPClient.c"
#include "DieWithError.c"

#define MAXPENDING 5 /* Maximum outstanding connection requests */

void DieWithError(char *errorMessage); /* Error handling function */
void HandleTCPClient(int clntSocket);  /* TCP client handling function */
int main(int argc, char *argv[])
{
    int servSock;                    /*Socket descriptor for server */
    int clntSock;                    /*Socket descriptor for client */
    struct sockaddr_in echoServAddr; /*Local address */
    struct sockaddr_in echoClntAddr; /*Client address */
    unsigned short echoServPort;     /*Server port */
    unsigned int clntLen;            /*Length of client address data structure */

    echoServPort = 3000; /* First arg: local port */

    /* Create socket for incoming connections */
    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket () failed");

    /* Construct local address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));   /* Zero out structure */
    echoServAddr.sin_family = AF_INET;                /* Internet address family */
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    echoServAddr.sin_port = htons(echoServPort);      /* Local port */

    /* Bind to the local address */
    if (bind(servSock, (struct sockaddr *)&echoServAddr, sizeof(echoServAddr)) < 0)
        DieWithError("bind () failed");
    /* Mark the socket so it will listen for incoming connections */
    if (listen(servSock, MAXPENDING) < 0)
        DieWithError("listen() failed");
    /* Set the size of the in-out parameter */
    while (1) /* Run forever */
    {
        clntLen = sizeof(echoClntAddr);

        /* Wait for a client to connect */
        if ((clntSock = accept(servSock, (struct sockaddr *)&echoClntAddr, &clntLen)) < 0)
            DieWithError("accept() failed");

        /* clntSock is connected to a client! */
        printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));
        HandleTCPClient(clntSock); /* NOT REACHED */
    }
}