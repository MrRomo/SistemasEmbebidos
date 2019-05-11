#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>


typedef struct pack
{
    int id;
    float temp;
    char chat[50];
} pack;
int sock;

void mensaje(pack * dato);
void handler_signal(int sig);

int main()
{
    pack dato;
    pack *dato_res;
    char chat[50];
    dato.id = 00001;
    dato.temp = 39.5;


    struct sigaction signal;
	signal.sa_handler = handler_signal;
	sigaction(SIGIO, &signal, 0);

    unsigned char res_buff[500] = {0};
    sock = socket(PF_INET, SOCK_STREAM, 0); //macro para familia de protocolos de internet SOCK_DGRAM para UDP
    printf("SOCKET %d\n", sock);            //retorna el recurso de conexion que utilizo el computador
    struct sockaddr_in server;
    server.sin_family = AF_INET;                     //macro para familia de protocolos de internet
    server.sin_addr.s_addr = inet_addr("127.0.0.1"); //inet_addr cambia de string a uint32_t
    server.sin_port = htons(3000);                   //inet_addr cambia de entero a uint16_t

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0)
    {
        printf("La conexion no pudo ser establecida\n");
        return 1;
    }
    printf("Conexion establecida\n");
    fcntl(sock, F_SETFL, O_ASYNC);
	fcntl(sock, __F_SETOWN, getpid());

    while (1)
    {
        mensaje(&dato); // pasa la estructura de datos para llenarla de mensaje
        send(sock, (const void *)&dato, sizeof(dato), 0);
    }

    return EXIT_SUCCESS;
}

void mensaje(pack * dato)
{
    printf("Ingrese su mensaje:\r\n");
    fflush(stdin);
    scanf("%s", dato->chat);
    dato->temp = 26 + rand() / (float)RAND_MAX * (9); 
    fflush(stdin);
}

void handler_signal(int sig){
    char buffer[500];
    pack * data;
	recv(sock, buffer, sizeof(buffer), 0);
    data = (pack *)buffer; //receive data
    printf("\t\t\t*Mensaje nuevo* \n\t\t\tid: %d\n\t\t\ttemp: %f °C\n\t\t\tmessage: \"%s\"\n", data->id, data->temp, data->chat);
}