#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listDEC.c"
void desition(int salir, List *list);
void printList(List *list);
void imprimirMenu();
void printDesition();
void space(char pos);

int main(int argc, char const *argv[])
{
    List *lista1 = list_new();
    int salir = 0;
    for (size_t i = 0; i < 10; i++)
    {
        if(i!=3)list_append(lista1, &i);
    }
    printList(lista1);
    while (1)
    {
        imprimirMenu();
        fflush(stdin);
        scanf("%d", &salir);
        desition(salir, lista1);
    }
    return 0;
}

void desition(int salir, List *list)
{
    size_t tmpNum;
    char move = 0;

    switch (salir)
    {
    case 1:
        printList(list);
        break;
    case 2:
        printf("Ingrese el nuevo valor...");
        fflush(stdin);
        scanf("%d", &tmpNum);
        bool append = list_append(list, &tmpNum);
        printList(list);
        break;
    case 3:
        printList(list);
        printf("3 - Editar posicion [%d][%d]\nIngresa el nuevo valor del nodo: _", list->pos->dato, list->posMarker);
        fflush(stdin);
        scanf("%d", &tmpNum);
        list_edit_node(list, &tmpNum);
        printList(list);
        break;
    case 4:
        while (move != 's')
        {
            printf("Hacia donde se desea mover a(derecha) o b(izquierda)\n");
            scanf("%c", &move);
            list_move_node(list, move);
            printList(list);
        }

        break;
    case 5:
        printList(list);
        printf("desea eliminar el nodo [%d,%d] - [Y/N]\n", (int)list->posMarker, (int)list->pos->dato);
        fflush(stdin);
        scanf("%s", &move);
        if (move == 'y')
        {
            list_remove(list);
            printList(list);
            printf("Nodo eliminado...\n");
        }
        else
        {
            printList(list);
            printf("No se realizo ninguna accion...\n");
        }
        break;
    case 6: 
        printList(list);
        printf("ingrese el valor del nuevo nodo detras de [%d,%d] - [Y/N]\n", (int)list->posMarker, (int)list->pos->dato);
        fflush(stdin);
        scanf("%d", &tmpNum);
        list_insert(list,&tmpNum);
        printList(list);
        printf("Nodo insertado...\n");
        break;
    default:
        break;
    }
}
void printList(List *list)
{
    // system("@cls||clear");
    list_run(list);
    space((int)list->posMarker * 3);
    printf("^\n");
    // space((int)list->posMarker * 3);
    printf("[pos|dato][%d,%d]\n", (int)list->posMarker, (int)list->pos->dato);
    printf("[h|p|t][%d,%d,%d]\n", (int)list->head->dato, (int)list->pos->dato,(int)list->tail->dato);
}

void imprimirMenu()
{
    printf("**** Bienvenido al list maker ****\n ¿que desea hacer?\n");
    printf("1 - Ver lista\n");
    printf("2 - Agregar valor\n");
    printf("3 - Editar posicion\n");
    printf("4 - Mover posicion\n");
    printf("5 - Eliminar posicion\n");
    printf("6 - Insertar nodo en posicion\n");

}
void printDesition()
{
    printf("**** Que Lista quiere seleccionar ****\n");
    printf("1 - Lista 1\n");
    printf("2 - Lista 2\n");
}
void space(char pos)
{
    for (char i = 0; i < pos + 4; i++)
    {
        printf(" ");
    }
}