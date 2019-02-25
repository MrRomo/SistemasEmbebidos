#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listDEC.c"
void imprimirMenu();
void desition();
void printDesition();
void clrscr();
void space(char pos);

int main(int argc, char const *argv[])
{
    List *lista1 = list_new();
    int salir = 0;

    for (size_t i = 0; i < 10; i++)
    {
        list_append(lista1, &i);
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
    char move = 0;
    // printDesition();
    switch (salir)
    {
    case 1:
        clrscr();
        printList(list);
        break;
    case 2:
        clrscr();
        printf("Ingrese el nuevo valor...");
        int tmpNum;
        fflush(stdin);
        scanf("%d", &tmpNum);
        list_append(list, &tmpNum);
        printList(list);
        break;
    case 3:
        clrscr();
        printf("Saliendo de invitado list maker...");
        break;
    case 4:
        while (move != 's')
        {
            clrscr();
            printf("Hacia donde se desea mover a(derecha), b(izquierda), s(salir)\n");
            printList(list);
            fflush(stdin);
            scanf("%s", &move);
            list_move_node(list, move);
        }
        break;
    case 5:
        printf("desea eliminar el nodo [%d,%d] - [Y/N]\n",(int)list->count, (int)list->pos->dato);
        printList(list);
        fflush(stdin);
        scanf("%s", &move);
        if (move =='Y')
        {
            list_remove(list->pos);
            printf("Nodo eliminado...\n");
        }else 
        {
            printf("No se realizo ninguna accion...\n");
        }
        
    default:
        break;
    }
}
void printList(List *list)
{
    list_run(list);
    space((int)list->count* 3);
    printf("^\n");
    space((int)list->count * 3);
    printf("[%d,%d]\n", (int)list->count, (int)list->pos->dato);
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
void movePosition(List *list)
{
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

void space(char pos)
{
    for (char i = 0; i < pos; i++)
    {
        printf(" ");
    }
}