#include <stdio.h>
#include <stdlib.h>

void imprimirMenu();
void verInvitado();
void agregarInvitado();

int main()
{
    int salir = 0;
    while (1)
    {
        imprimirMenu();
        fflush(stdin);
        scanf("%d", &salir);

        switch (salir)
        {
        case 1:
            agregarInvitado();
            break;
        case 2:
            verInvitado();
            break;
        case 3:
            printf("Saliendo de invitado logger...");
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}

void imprimirMenu()
{
    printf("**** Bienvenido al invitado logger ****\n ¿que desea hacer?\n");
    printf("1 - Agregar invitados\n");
    printf("2 - Ver invitados\n");
    printf("3 - Salir\n");
}
void verInvitado()
{
    FILE *archivo = NULL;
    char nombre[80];
    char *filename = "listaInvitados.txt";
    char lectura[80];
    int end = 0;

    archivo = fopen(filename, "r");
    if (!archivo)
        return -1;

    printf("\nLista de invitados:\n");
    end = fscanf(archivo, " %[^\n]", &lectura);
    while (end != EOF)
    {
        printf("- %s\n",lectura);
        end = fscanf(archivo, " %[^\n]", &lectura);
    }
    printf("\n");
};
void agregarInvitado()
{
    FILE *archivo = NULL;
    char nombre[80];
    char *filename = "listaInvitados.txt";

    archivo = fopen(filename, "a");

    printf("Ingrese el nombre del invitado:\n");

    scanf(" %[^\n]", &nombre);

    fprintf(archivo, "%s \n", nombre);

    fclose(archivo);
};
