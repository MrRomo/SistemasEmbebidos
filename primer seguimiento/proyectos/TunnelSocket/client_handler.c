#include <stdio.h>      /*for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /*for atoi() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /*for close() */
#include <signal.h>
#include <fcntl.h>
#include "DieWithError.c"
#define RCVBUFSIZE 32 /* Size of receive buffer */

typedef struct message
{
    int id;
    float temp;
    char chat[50];
} message;

void DieWithError(char *errorMessage); /* Error handling function */
void handler_signal(int sig);
message data;

int sock; /*Socket descriptor */
char prevMsg[50];
void socketCreator(int port, int client)
{
    struct sockaddr_in echoServAddr; /* Echo server address */
    int bytesRcvd, totalBytesRcvd;   /* /*Bytes read in single recv()and total bytes read */
    struct sockaddr_in server;
    message dato;
    dato.id = client;

    struct sigaction signal;
    signal.sa_handler = handler_signal;
    sigaction(SIGIO, &signal, 0);

    /* Construct the server address structure */
    sock = socket(PF_INET, SOCK_STREAM, 0); //macro para familia de protocolos de internet SOCK_DGRAM para UDP

    memset(&echoServAddr, 0, sizeof(echoServAddr));  /* Zero out structure */
    server.sin_family = AF_INET;                     /* Internet address family */
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); /* Server IP address */
    server.sin_port = htons(port);                   /* Server port */

    /* Establish the connection to the echo server */
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
        DieWithError(" connect () failed");
    fcntl(sock, F_SETFL, O_ASYNC);
    fcntl(sock, __F_SETOWN, getpid());
    printf("Ingrese su mensaje:\r\n");

    while (1)
    {
            
        fflush(stdin);
        fgets(dato.chat, 100, stdin);
        fflush(stdin);
        dato.temp = 26 + rand() / (float)RAND_MAX * (9);
        send(sock, (const void *)&dato, sizeof(dato), 0);
    }
}

void handler_signal(int sig)
{
    char buffer[500];
    int recvMsgSize; /* Size of received message */
    memset(buffer, 0, sizeof(buffer));
    if ((recvMsgSize = recv(sock, buffer, sizeof(buffer), 0)) < 0)
        DieWithError("recv() failed");
    data = *(message *)buffer;
    if (strlen(data.chat) > 0)
    {
         
        if (strcmp(prevMsg, data.chat))
        {
            printf("\t-----------\n\t\tid: %d\n\t\ttemp: %f °C\n\t\tmessage: %s\n\t-----------\n", data.id, data.temp, data.chat);
            memcpy(prevMsg,data.chat,strlen(data.chat)+1);
            printf("Ingrese su mensaje:\r\n");
        }
        return;
    }
    memset(buffer, 0, sizeof(buffer));
}