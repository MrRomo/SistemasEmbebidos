#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

typedef struct pack
{
    int id;
    float temp;
    char chat[50];
} pack;

int main()
{
    pack dato;
    char chat[50];
    dato.id = 00001;
    dato.temp = 30.5;

    int sock;

    unsigned char res_buff[500] = {0};
    sock = socket(PF_INET, SOCK_STREAM, 0); //macro para familia de protocolos de internet SOCK_DGRAM para UDP
    printf("SOCKET %d\n", sock);            //retorna el recurso de conexion que utilizo el computador
    struct sockaddr_in server;
    server.sin_family = AF_INET;                     //macro para familia de protocolos de internet
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); //inet_addr cambia de string a uint32_t
    server.sin_port = htons(3000);                   //inet_addr cambia de entero a uint16_t

    printf("Conexion establecida\n");
    connect(sock, (struct sockaddr *)&server, sizeof(server));
    while (1)
    {
        printf("Ingrese su mensaje:\r\n");
        fflush(stdin);
        scanf("%s", dato.chat);
        fflush(stdin);

        send(sock, (const void *)&dato, sizeof(dato), 0);
        // recv(sock, res_buff, sizeof(res_buff), 0);
        // close(sock);
    }

    return EXIT_SUCCESS;
}
