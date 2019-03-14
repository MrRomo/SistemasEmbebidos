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

message client_data[2];             /* message clients structure*/
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

    int c;
    unsigned char buffer[100];

    servSock[sock] = socket(PF_INET, SOCK_STREAM, 0);

    echoServAddr[sock].sin_family = AF_INET;         //macro para familia de protocolos de internet
    echoServAddr[sock].sin_addr.s_addr = INADDR_ANY; //inet_addr cambia de string a uint32_t
    echoServAddr[sock].sin_port = htons(port);       //inet_addr cambia de entero a uint16_t
    if (bind(servSock[sock], (struct sockaddr *)&echoServAddr[sock], sizeof(echoServAddr[sock])) < 0)
        DieWithError("BIND ERROR");

    if (listen(servSock[sock], 3) < 0)
        DieWithError("LISTEN ERROR");
    printf("Socket [%d] on port : %d\n", sock, port);

    while (1)
    {

        int recvMsgSize; /* Size of received message */
        // clntSock[sock] = accept(servSock[sock], &echoClntAddr, &c);

        if ((clntSock[sock] = accept(servSock[sock], (struct sockaddr *)&echoClntAddr[sock], &c)) < 0)
            DieWithError("accept() failed");
        printf("accept client\n");
        /* Receive message from client */
        printf("\n*cliente conectado*\n");
        do
        {
            /* code */

            while (1)
            {
                if ((recvMsgSize = recv(clntSock[sock], buffer, sizeof(buffer), 0)) < 0)
                    DieWithError("recv() failed");
                client_data[sock] = *(message *)buffer;
                printf("Size of message: %d - %d\n", strlen(client_data[sock].chat), recvMsgSize);
                if (strlen(client_data[sock].chat) > 0)
                {
                    printf("id: %d\ntemp: %f °C\nmessage: \"%s\"\n----\n", client_data[sock].id, client_data[sock].temp, client_data[sock].chat);
                    send(clntSock[!sock], (const void *)&client_data[sock], sizeof(client_data[sock]), 0);
                    break;
                }
                memset(buffer, 0, sizeof(buffer));
            }
        } while (recvMsgSize > 0);
        printf("Closing conection");
    }
}
