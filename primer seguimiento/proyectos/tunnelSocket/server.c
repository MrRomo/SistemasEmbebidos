#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <fcntl.h>

#include <string.h>
#include <pthread.h>

typedef struct pack
{
    int id;
    float temp;
    char chat[50];
} pack;

void handler_signal1(int sig);

pack *client1_data;
pack *client2_data;
int sock_req1, sock_res1;

void *task1()
{
    printf("Socket on port 3000\n");
    struct sigaction signal;
    signal.sa_handler = handler_signal1;
    sigaction(SIGIO, &signal, 0);

    int c, read_size;
    struct sockaddr_in server;
    struct sockaddr client;
    unsigned char buffer[100];
    char response[] = "OK 200";

    sock_req1 = socket(PF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET; //macro para familia de protocolos de internet
    // server.sin_addr.s_addr = inet_addr("104.27.156.246"); //inet_addr cambia de string a uint32_t
    server.sin_addr.s_addr = INADDR_ANY; //inet_addr cambia de string a uint32_t
    server.sin_port = htons(3000);       //inet_addr cambia de entero a uint16_t
    fcntl(sock_req1, F_SETFL, O_ASYNC);
    fcntl(sock_req1, __F_SETOWN, getpid());
    if (bind(sock_req1, (struct sockaddr *)&server, sizeof(server)) < 0)
        printf("BIND ERROR");

    if (listen(sock_req1, 3) < 0)
        printf("LISTEN ERROR");
    sock_res1 = accept(sock_req1, &client, &c);
}

int main()
{
    pthread_t hilo1;
    pthread_create(&hilo1, NULL, &task1, NULL);

    pthread_join(hilo1, NULL);

    return 0;
}
void handler_signal1(int sig)
{
    char buffer[500];
    recv(sock_res1, buffer, sizeof(buffer), 0);
    client1_data = (pack *)buffer; //receive data
    printf("*cliente conectado* \nid: %d\ntemp: %f °C\nmessage: \"%s\"\n", client1_data->id, client1_data->temp, client1_data->chat);
    send(sock_res1, (const void *)&client1_data, sizeof(client1_data), 0);
}


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

typedef struct pack
{
    int id;
    float temp;
    char chat[50];
} pack;

void *task1()
{
    printf("Socket on port 3000");
    pack *dato;
    int sock_req, sock_res;
    int c, read_size;
    struct sockaddr_in server;
    struct sockaddr client;
    unsigned char buffer[100];

    sock_req = socket(PF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET; //macro para familia de protocolos de internet
    // server.sin_addr.s_addr = inet_addr("104.27.156.246"); //inet_addr cambia de string a uint32_t
    server.sin_addr.s_addr = INADDR_ANY; //inet_addr cambia de string a uint32_t
    server.sin_port = htons(3000);       //inet_addr cambia de entero a uint16_t
    while (1)
    {
        if (bind(sock_req, (struct sockaddr *)&server, sizeof(server)) < 0)
            printf("BIND ERROR");

        if (listen(sock_req, 3) < 0)
            printf("LISTEN ERROR");
        sock_res = accept(sock_req, &client, &c);

        while (recv(sock_res, buffer, sizeof(buffer), 0) > 0)
        {
            dato = (pack *)buffer;
            printf("*cliente conectado* \nid: %d\ntemp: %f °C\nmessage: \"%s\"", dato->id, dato->temp, dato->chat);
            fflush(stdout);
            memset(buffer, 0, sizeof(buffer));
        }
    }
}

void *task2()
{
    printf("Socket on port 3001");
    pack *dato;
    int sock_req, sock_res;
    int c, read_size;
    struct sockaddr_in server;
    struct sockaddr client;
    unsigned char buffer[100];

    sock_req = socket(PF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET; //macro para familia de protocolos de internet
    // server.sin_addr.s_addr = inet_addr("104.27.156.246"); //inet_addr cambia de string a uint32_t
    server.sin_addr.s_addr = INADDR_ANY; //inet_addr cambia de string a uint32_t
    server.sin_port = htons(3001);       //inet_addr cambia de entero a uint16_t
    while (1)
    {
        if (bind(sock_req, (struct sockaddr *)&server, sizeof(server)) < 0)
            printf("BIND ERROR");

        if (listen(sock_req, 3) < 0)
            printf("LISTEN ERROR");
        sock_res = accept(sock_req, &client, &c);

        while (recv(sock_res, buffer, sizeof(buffer), 0) > 0)
        {
            dato = (pack *)buffer;
            printf("*cliente conectado* \nid: %d\ntemp: %f °C\nmessage: \"%s\"", dato->id, dato->temp, dato->chat);
            fflush(stdout);
            memset(buffer, 0, sizeof(buffer));
        }
    }
}

int main()
{
    pthread_t hilo1, hilo2;
    pthread_create(&hilo1, NULL, &task1, NULL);
    pthread_create(&hilo2, NULL, &task2, NULL);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    return 0;
}
