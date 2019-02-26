#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listDEC.c"
void imprimirMenu();
void desition();
void printDesition();
void clrscr();
void space (char pos);

int main(int argc, char const *argv[])
{
    List *lista1 = list_new();
    printf("entrando a append");
    int salir = 0;
    bool append = list_append(lista1,&salir);
    for (size_t i = 0; i < 10; i++)
    {
        append = list_append(lista1, &i);
    }
    while (1)
    {
        imprimirMenu();
        fflush(stdin);
        scanf("%d", &salir);
        clrscr();
        desition(salir, lista1);
    }
    return 0;
}

void desition(int salir, List *list)
{
    // printDesition();
    switch (salir)
    {
    case 1:
        printList(list);
        break;
    case 2:
        printf("Ingrese el nuevo valor...");
        int tmpNum;
        fflush(stdin);
        scanf("%d", &tmpNum);
        list_append(list, &tmpNum);
        printList(list);
        break;
    case 3:
        printf("Saliendo de invitado list maker...");
        break;
    case 4:
        printf("Hacia donde se desea mover a(derecha) o b(izquierda)\n");
        list_move_node(list->pos, 'd');
        printList(list);
        break;
    default:
        break;
    }
}
void printList(List * list){
    list_run(list);
    space((int)list->posMarker*3);
    printf("^\n");
    space((int)list->posMarker*3);
    printf("[%d,%d]\n", (int)list->posMarker, (int)list->pos->dato);
}
void imprimirMenu()
{
    printf("**** Bienvenido al list maker ****\n ¿que desea hacer?\n");
    printf("1 - Ver lista\n");
    printf("2 - Agregar valor\n");
    printf("3 - Editar posicion\n");
    printf("4 - Mover posicion\n");
    printf("5 - Eliminar posicion\n");

}
void printDesition()
{
    printf("**** Que Lista quiere seleccionar ****\n");
    printf("1 - Lista 1\n");
    printf("2 - Lista 2\n");
}
void clrscr()
{
    system("@cls||clear");
}

void space (char pos){
    for(char i = 0; i <pos; i++)
    {
        printf(" ");
    }
}