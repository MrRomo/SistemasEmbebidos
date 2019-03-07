#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

typedef struct pack
{
    int id;
    float temp;
} pack;

int main()
{
    pack dato;

    dato.id = 12432543;
    dato.temp = 30.5;

    int sock;
    unsigned char req_buff[30] = "GET /index.html HTTP\r\n Host: www.ricardoromo.co\r\n";

    unsigned char res_buff[500] = {0};
    sock = socket(PF_INET, SOCK_STREAM, 0); //macro para familia de protocolos de internet SOCK_DGRAM para UDP
    printf("SOCKET %d\n", sock);            //retorna el recurso de conexion que utilizo el computador
    struct sockaddr_in server;
    server.sin_family = AF_INET; //macro para familia de protocolos de internet
    // server.sin_addr.s_addr = inet_addr("104.27.156.246"); //inet_addr cambia de string a uint32_t
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); //inet_addr cambia de string a uint32_t
    server.sin_port = htons(3000);                         //inet_addr cambia de entero a uint16_t

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("ERROR de conexion");
        return 1;
    }
    printf("Conexion establecida\n");
    send(sock, (const void*)&dato, sizeof(dato), 0);
    recv(sock, res_buff, sizeof(res_buff), 0);
    printf("%s", res_buff);
    pause(5);
    close(sock);
    return EXIT_SUCCESS;
}
