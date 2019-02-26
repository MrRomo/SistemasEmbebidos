#ifndef _DINAMICSTRUCTURE
#define _DINAMICSTRUCTURE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Firmas de funciones
struct list;
struct nodo;

typedef struct nodo
{
    int dato;
    struct nodo *next;
    struct nodo *prev;
} Nodo;

typedef struct list
{
    size_t tam;
    size_t posMarker;
    Nodo *head;
    Nodo *pos;
    Nodo *tail;
} List;

//Construcctor de la lista
List *list_new();

//inserta un elemento en la posicion especifica
//devuelve un bool si hubo un error o no
bool list_append(List *list, void *elemento);

//devuelve el valor del elemento segun el indice
void *list_get(List *list, size_t indice);

//recorre la lista de izquierda a derecha a travez de sus nodos
Nodo *list_node(Nodo *nodo, char move);

//Recorre e imprime toda la lista
void list_run(List *list);

//obtiene el tamaño del list
size_t list_length(List *list);

//destruye el list de la memoria
void list_destroy(List *list);

#endif