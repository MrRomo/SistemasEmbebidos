#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#include "client_handler.c"

#define RCVBUFSIZE 32 /* Size of receive buffer */

void DieWithError(char *errorMessage); /* Error handling function */
void socketCreator(int port, int client);
void handler_signal(int sig);

int sock;

int main()
{
    //Create socket client
    int select;
    while (select != 1 && select != 2)
    {
        printf("A que puerto quiere conectar:\n [1] 3000 -  [2] 3001:\n");
        scanf("%d", &select);
    }
    if (select == 1)
    {
        socketCreator(3000, 0);
    }
    else
    {
        socketCreator(3001, 1);
    }
}
