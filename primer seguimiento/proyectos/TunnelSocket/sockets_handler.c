#include <stdio.h>     /* forprintf() and fprintf() */
#include <sys/socket.h>/* for socket(), bind(), and connect() */
#include <arpa/inet.h> /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>    /* for atoi() */
#include <string.h>    /* for memset() */
#include <unistd.h>    /* for close() */
#include <signal.h>    /* for signal handler */
#include <fcntl.h>     /* for file attachment */

typedef struct message
{
    int id;
    float temp;
    char chat[50];
} message;

message *client_data[2];            /* message clients structure*/
int servSock[2];                    /*Socket descriptor for server */
int clntSock[2];                    /*Socket descriptor for client */
struct sockaddr_in echoServAddr[2]; /*Local address */
struct sockaddr_in echoClntAddr[2]; /*Client address */
unsigned short echoServPort[2];     /*Server port */
unsigned int clntLen[2];            /*Length of client address data structure */

void handler_signal1(int sig);
void handler_signal2(int sig);

int createSocket(int port, int sock)
{

    struct sigaction signal;
    if (port)
    {
        signal.sa_handler = handler_signal1;
    }
    else
    {
        signal.sa_handler = handler_signal2;
    }

    sigaction(SIGIO, &signal, 0);

    /* Create socket for incoming connections */
    if ((servSock[sock] = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        DieWithError("socket () failed");

    /* Construct local address structure */
    memset(&echoServAddr[sock], 0, sizeof(echoServAddr[sock])); /* Zero out structure */
    echoServAddr[sock].sin_family = AF_INET;                    /* Internet address family */
    echoServAddr[sock].sin_addr.s_addr = htonl(INADDR_ANY);     /* Any incoming interface */
    echoServAddr[sock].sin_port = htons(port);                  /* Local port */

    fcntl(servSock[sock], F_SETFL, O_ASYNC);
    fcntl(servSock[sock], __F_SETOWN, getpid());

    if (bind(servSock[sock], (struct sockaddr *)&echoServAddr[sock], sizeof(echoServAddr[sock])) < 0)
        DieWithError("bind ( ) failed");
    printf("Socket [%d] listen on port: %d\n", sock, port);

    /* Mark the socket so it will listen for incoming connections */
    if (listen(servSock[sock], 3) < 0)
        DieWithError("listen() failed");

    /* Set the size of the in-out parameter */

    clntLen[sock] = sizeof(echoClntAddr[sock]);
    /* Wait for a client to connect */
    if ((clntSock[sock] = accept(servSock[sock], (struct sockaddr *)&echoClntAddr[sock], &clntLen[sock])) < 0)
        DieWithError("accept() failed");
    /* clntSock is connected to a client! */
    printf("Handling client %s - N° %d\n", inet_ntoa(echoClntAddr[sock].sin_addr), sock);
}

void handler_signal1(int sig)
{
    char buffer[500];
    int recvMsgSize; /* Size of received message */
    if ((recvMsgSize = recv(clntSock[0], buffer, sizeof(buffer), 0)) < 0)
        return printf("Not mesage received");
    recv(servSock[0], buffer, sizeof(buffer), 0);
    client_data[0] = (message *)buffer; //receive data
    printf("*cliente conectado* \nid: %d\ntemp: %f °C\nmessage: \"%s\"\n", client_data[0]->id, client_data[0]->temp, client_data[0]->chat);
    // send(servSock[0], (const void *)&client_data[0], sizeof(client_data[0]), 0);
}

void handler_signal2(int sig)
{
    // char buffer[500];
    // recv(servSock[1], buffer, sizeof(buffer), 0);
    // client_data[1] = (message *)buffer; //receive data
    // printf("*cliente conectado* \nid: %d\ntemp: %f °C\nmessage: \"%s\"\n", client_data[1]->id, client_data[1]->temp, client_data[1]->chat);
    // send(servSock[1], (const void *)&client_data[1], sizeof(client_data[1]), 0);
}
