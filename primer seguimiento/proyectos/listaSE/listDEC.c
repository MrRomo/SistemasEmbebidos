#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listSE.h"

List *list_new()
{
    //creamos la estructura y pedimos memoria para la estructura
    List *list = malloc(sizeof(list));
    if (list == NULL)
        return NULL;
    //seteamos la cabeza y la cola
    list->head = NULL;
    list->tail = NULL;
    list->tam = 0;
    return list;
}

//inserta un elemento en la posicion especifica
//devuelve un bool si hubo un error o no
bool list_append(List *list, void *elemento)
{
    Nodo *nuevo = malloc(sizeof(Nodo));
    nuevo->dato = *(int *)elemento;
    nuevo->next = NULL;
    nuevo->prev = NULL;
    if (list->head == NULL)
    {
        list->head = nuevo;
        list->head->next = list->head;
        list->tail = list->head;
        list->head->prev = list->tail;
        list->tam = 1;
    }
    else
    {
        list->tail->next = nuevo;
        nuevo->next = list->head;
        nuevo->prev = list->tail;
        list->tail = nuevo;
        list->head->prev = list->tail;
        list->tam += 1;
    }
}

//devuelve el valor del elemento segun el indice
void *list_get(List *list, size_t indice)
{
    if (indice < 0 || indice >= list->tam)
        return NULL;
    Nodo *tmpList;
    tmpList = list->head;
    for (char i = 0; i < indice; i++)
    {
        tmpList = tmpList->next;
    }
    return tmpList->dato;
}

//recorre la lista de izquierda a derecha a travez de sus nodos
Nodo* list_move_node(Nodo* nodo, char move){
    switch (move)
    {
        case 'a':
            return nodo->prev;
        case 'd':
            return nodo->next;
        default:
            break;
    }
}

//Recorre e imprime toda la lista
void list_run(List *list)
{
    Nodo *tmpList;
    tmpList = list->head;
    printf("[");
    for (int i = 0; i < (int)list->tam; i++)
    {
        printf(" %d, ", (int)tmpList->dato);
        tmpList = tmpList->next;
    }
    printf("]\n");
}

//obtiene el tamaño del list
size_t list_length(List *list)
{
    return list->tam;
}

//destruye el list de la memoria
void list_destroy(List *list)
{
    Nodo *tmpNode = list->head;
    Nodo *nextNode = NULL;
    free(list->head);
    for (size_t i = 0; i < list->tam - 1; i++)
    {
        nextNode = tmpNode->next;
        free(tmpNode);
        tmpNode = nextNode;
    }
    free(list);
}
