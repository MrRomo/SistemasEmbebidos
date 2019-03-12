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
    printf("Socket on port 3000\n");
    char temp[8];
    // scanf("%s", temp);
    pack *dato;
    int sock_req, sock_res;
    int c, read_size;
    struct sockaddr_in server;
    struct sockaddr client;
    unsigned char buffer[100];
    char response[]= "OK 200";

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
            printf("*cliente conectado* \nid: %d\ntemp: %f °C\nmessage: \"%s\"\n", dato->id, dato->temp, dato->chat);
            fflush(stdout);
            memset(buffer, 0, sizeof(buffer));
        }
        // printf("send response %s", response);
        // send(sock_res,response, sizeof(response),0 );

    }
}

void *task2()
{
    printf("Socket on port 3001\n");
    pack *dato;
    int sock_req, sock_res;
    int c, read_size;
    struct sockaddr_in server;
    struct sockaddr client;
    unsigned char buffer[100];

    sock_req = socket(PF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET; //macro para familia de protocolos de internet
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
            printf("*cliente conectado* \nid: %d\ntemp: %f °C\nmessage: \"%s\"\n", dato->id, dato->temp, dato->chat);
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
