#include <stdio.h>
#include <stdlib.h>
#include <sys/signal.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <pthread.h>

//manejador de la señal
void handler_signal(int sig)
{
    printf("procesando la señal %d\n", sig);
}

typedef struct pack
{
    int id;
    float temp;
} pack;

int main()
{
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

    if (bind(sock_req, (struct sockaddr *)&server, sizeof(server)) < 0)
        printf("BIND ERROR");

    if (listen(sock_req, 3) < 0)
        printf("LISTEN ERROR");
    sock_res = accept(sock_req, &client, &c);

    struct sigaction signal;
    signal.sa_handler = handler_signal;
    sigaction(SIGIO, &signal, 0);

    fcntl(sock_res, F_SETFL, O_ASYNC);
    fcntl(sock_res, __F_SETOWN, getpid());

    return EXIT_SUCCESS;
}
