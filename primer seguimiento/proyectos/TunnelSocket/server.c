#include <stdio.h>     /* forprintf() and fprintf() */
#include <sys/socket.h>/* for socket(), bind(), and connect() */
#include <arpa/inet.h> /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>    /* for atoi() */
#include <string.h>    /* for memset() */
#include <unistd.h>    /* for close() */
// #include "HandleTCPClient.c"
#include <signal.h>
#include <fcntl.h>
#include <pthread.h>

#include "sockets_handler.c"
#include "DieWithError.c"

#define MAXPENDING 5 /* Maximum outstanding connection requests */
int createSocket(int port, int sock);

void DieWithError(char *errorMessage); /* Error handling function */
void HandleTCPClient(int clntSocket);  /* TCP client handling function */
void *task1();
void *task2();
int createSocket(int port, int sock);

int main()
{
    pthread_t hilo1, hilo2;
    pthread_create(&hilo1, NULL, &task1, NULL);
    pthread_create(&hilo2, NULL, &task2, NULL);

    pthread_join(hilo1, NULL);
    pthread_join(hilo2, NULL);

    return 0;
}

void *task1()
{
    printf("Task 0 started\n");
    createSocket(3000, 0);
}
void *task2()
{
    printf("Task 1 started\n");
    createSocket(3001, 1);
}
