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
    struct nodo *next, *prev;
} Nodo;

typedef struct list
{
    int tam, posMarker;
    struct nodo *head, *pos, *tail;
    
} List;

//Construcctor de la lista
List *list_new();

//inserta un elemento en la posicion especifica
//devuelve un bool si hubo un error o no
bool list_append(List *list, void *elemento);

//devuelve el valor del elemento segun el indice
void *list_get(List *list, size_t indice);

//devuelve el valor del elemento segun el indice
void list_edit_node(List *list, void *value);

//recorre la lista de izquierda a derecha a travez de sus nodos
void *list_move_node(List * list, char move);

//Recorre e imprime toda la lista
void list_run(List *list);

//obtiene el tamaño del list
size_t list_length(List *list);

//elimina el nodo que apunta pos
void list_remove(List *list);


//destruye el list de la memoria
void list_destroy(List *list);

#endif