#include <stdio.h>     /* forprintf() and fprintf() */
#include <sys/socket.h>/* for socket(), bind(), and connect() */
#include <arpa/inet.h> /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>    /* for atoi() */
#include <string.h>    /* for memset() */
#include <unistd.h>    /* for close() */
#include <signal.h>    /* for signal handler */
#include <fcntl.h>     /* for file attachment */
typedef struct DHTData
{
    float humidity;
    float temperature;
    int id;
    int stamp;
} DHTData_t;

DHTData_t client_data[2];           /* message clients structure*/
int servSock[2];                    /*Socket descriptor for server */
int clntSock[2];                    /*Socket descriptor for client */
struct sockaddr_in echoServAddr[2]; /*Local address */
struct sockaddr_in echoClntAddr[2]; /*Client address */
unsigned short echoServPort[2];     /*Server port */
unsigned int clntLen[2];            /*Length of client address data structure */
char prevMsg[50];

void handler_signal1(int sig);
void handler_signal2(int sig);
char *struct2str(DHTData_t ap);

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

    if (listen(servSock[sock], 1) < 0)
        DieWithError("LISTEN ERROR");
    printf("Socket [%d] on port : %d\n", sock, port);

    while (1)
    {

        int recvMsgSize; /* Size of received message */
        if ((clntSock[sock] = accept(servSock[sock], (struct sockaddr *)&echoClntAddr[sock], &c)) < 0)
            DieWithError("accept() failed");
        /* Receive message from client */
        printf("*cliente [%d] conectado*\n", sock);
        do
        {
            while (1)
            {
                if ((recvMsgSize = recv(clntSock[sock], buffer, sizeof(buffer), 0)) < 0)
                    DieWithError("recv() failed");
                client_data[sock] = *(DHTData_t *)buffer;
                if ((client_data[sock].temperature < 80)&&(client_data[sock].temperature >0))
                {
                    printf("\t-----------\n\t\tid: %d\n\t\ttemp: %.1f °C\n\t\thumidity: %.1f\n\t\tstamp: %d\t\n-----------\n", client_data[sock].id, client_data[sock].temperature, client_data[sock].humidity, client_data[sock].stamp);
                    char *filename = "sensor_log.json";

                    char logData[] = "{\"ID\": ";
                    char logData2[] = ", \"Temp\": ";
                    char logData3[] = ", \"Hum\": ";
                    char logData4[] = " \"Stamp\": ";
                    char logData5[] = "}";
                    char buf[1000];
                    sprintf(buf, ",\n{\"ID\": %d, \"Temp\": %f, \"Hum\":  %f,\"Stamp\": %d}\n]}", client_data[sock].id, client_data[sock].temperature, client_data[sock].humidity, client_data[sock].stamp);
                    appendFile(filename, buf);
                    memset(buf, 0, sizeof(buf));
                }
            }
        } while (recvMsgSize > 0);
    }
}
