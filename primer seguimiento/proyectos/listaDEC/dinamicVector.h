#ifndef _DINAMICVECTOR
#define _DINAMICSVECTOR
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//Firmas de funciones
struct vector;

typedef struct vector
{
    size_t tam;
    void** dato;
}Vector_d;

//crea el vector
Vector_d* vector_new(size_t tam_inicial);

//inserta un elemento en la posicion especifica
//devuelve un bool si hubo un error o no
bool vector_insert(Vector_d* vector, size_t indice, void* elemento);

//devuelve el valor del elemento segun el indice 
void* vector_get(Vector_d* vector, size_t indice);

//obtiene el tamaño del vector
size_t vector_length(Vector_d* vector);

//redimensiona el vector a un nuevo tamaño mas grande 
bool vector_resize(Vector_d* vector, size_t tam);

//destruye el vector de la memoria
void vector_destroy(Vector_d* vector);

#endif