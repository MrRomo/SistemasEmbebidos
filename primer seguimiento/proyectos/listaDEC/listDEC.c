#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "listDEC.h"

List *list_new()
{
    //creamos la estructura y pedimos memoria para la estructura
    List *list = (List *)malloc(sizeof(list));
    if (list == NULL)
        return NULL;
    //seteamos la cabeza y la cola
    list->head = NULL;
    list->tail = (Nodo *)malloc(sizeof(Nodo));
    ;
    list->tam = 0;
    list->posMarker = 0;
    return list;
}

//inserta un elemento en la posicion especifica
//devuelve un bool si hubo un error o no
bool list_append(List *list, void *elemento)
{
    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo)
        return false;
    nuevo->dato = *(size_t *)elemento;
    if (list->head == NULL)
    {
        list->head = nuevo;
        list->tail = nuevo;
        list->pos = nuevo;
        nuevo->next = list->head;
        nuevo->prev = list->tail;
        list->tam = 1;
        list->pos = nuevo;
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
    return true;
}

//inserta un dato detras del nodo que apunta pos
void list_insert(List *list, void *value)
{

    Nodo *nuevo = (Nodo *)malloc(sizeof(Nodo));
    if (!nuevo)
        return false;
    nuevo->dato = *(size_t *)value;

    if ((list->posMarker) == 0)
    {
        Nodo *head = list->head;
        list->head = nuevo;
        head->prev = list->head;
        list->head->prev = list->tail;
        list->tail->next = list->head;
        list->head->next = head;
    }
    else
    {
        Nodo *tempNodo = list->pos;
        Nodo *tempNodoPrev = tempNodo->prev;
        printf("TempNodo: [%d][%d][%d]\n", tempNodo->prev->dato, tempNodo->dato, tempNodo->next->dato);
        list->pos = nuevo;
        nuevo->next = tempNodo;
        tempNodo->prev = nuevo;
        nuevo->prev = tempNodoPrev;
        tempNodoPrev->next = nuevo;
    }
    list->pos = list->head;
    printf("Pos: [%d][%d][%d]\n", list->pos->prev->dato, list->pos->dato, list->pos->next->dato);
    list->tam++;
    list->posMarker = 0;
}

//devuelve el valor del elemento segun el indice
void *list_get(List *list, size_t indice)
{
    // if (indice < 0 || indice >= list->tam)
    //     return NULL;
    // Nodo *tmpList;
    // tmpList = list->head;
    // for (char i = 0; i < indice; i++)
    // {
    //     tmpList = tmpList->next;
    // }
    // return tmpList->dato;
}
//devuelve el valor del elemento segun el indice
void list_edit_node(List *list, void *value)
{
    list->pos->dato = *(size_t *)value;
}
//recorre la lista de izquierda a derecha a travez de sus nodos
void *list_move_node(List *list, char move)
{
    switch (move)
    {
    case 'a':
        list->posMarker--;
        if (list->posMarker < 0)
            list->posMarker = list->tam - 1;
        list->pos = list->pos->prev;
        break;
    case 'd':
        list->posMarker++;
        if (list->posMarker >= list->tam)
            list->posMarker = 0;
        list->pos = list->pos->next;
        break;
    default:
        break;
    }
}

//Recorre e imprime toda la lista
void list_run(List *list)
{
    Nodo *nodo;
    nodo = list->head;
    printf("[");
    for (int i = 0; i < (int)list->tam; i++)
    {
        printf(" %d, ", (int)nodo->dato);
        nodo = nodo->next;
    }
    printf("]\n");
}

//obtiene el tamaño del list
size_t list_length(List *list)
{
    return list->tam;
}

//elimina el nodo que apunta pos
void list_remove(List *list)
{
    if ((list->posMarker) == 0)
    {
        Nodo *head = list->head;
        list->head = list->head->next;
        list->head->prev = list->tail;
        list->tail->next = list->head;
        free(head);
    }
    else if (list->posMarker == (list->tam - 1))
    {
        Nodo *tail = list->tail;
        list->tail = list->tail->prev;
        list->tail->next = list->head;
        list->head->prev = list->tail;
        free(tail);
    }
    else
    {
        Nodo *nextNode = list->pos->next;
        Nodo *prevNode = list->pos->prev;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        free(list->pos);
    }
    list->pos = list->head;
    list->tam--;
    list->posMarker = 0;
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