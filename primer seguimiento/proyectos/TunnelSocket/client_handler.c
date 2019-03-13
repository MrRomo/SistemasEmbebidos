#include <stdio.h>      /*for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /*for atoi() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /*for close() */
#include "DieWithError.c"
#define RCVBUFSIZE 32                  /* Size of receive buffer */


typedef struct message
{
    int id;
    float temp;
    char chat[50];
} message;

void DieWithError(char *errorMessage); /* Error handling function */

void socketCreator(int port, int client)
{
    int sock;                        /*Socket descriptor */
    struct sockaddr_in echoServAddr; /* Echo server address */
    int bytesRcvd, totalBytesRcvd;   /* /*Bytes read in single recv()and total bytes read */
    struct sockaddr_in server;
    message dato;
    dato.id = client;

    /* Construct the server address structure */
    sock = socket(PF_INET, SOCK_STREAM, 0); //macro para familia de protocolos de internet SOCK_DGRAM para UDP

    // memset(&echoServAddr, 0, sizeof(echoServAddr));   /* Zero out structure */
    server.sin_family = AF_INET;                /* Internet address family */
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); /* Server IP address */
    server.sin_port = htons(port);      /* Server port */

    /* Establish the connection to the echo server */
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
        DieWithError(" connect () failed");
    
 
    while (1)
    {
        setMessage(&dato); // pasa la estructura de datos para llenarla de mensaje
        send(sock, (const void *)&dato, sizeof(dato), 0);
    }

}

void setMessage(message *dato){
    printf("Ingrese su mensaje:\r\n");
    fflush(stdin);
    gets(dato->chat);
    dato->temp = 26 + rand() / (float)RAND_MAX * (9); 
    fflush(stdin);
}