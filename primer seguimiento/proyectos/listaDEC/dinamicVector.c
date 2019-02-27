#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dinamicVector.h" 

Vector_d *vector_new(size_t tam_inicial)
{

    //creamos la estructura y pedimos memoria para la estructura
    Vector_d *vector = malloc(sizeof(Vector_d)); 
    if (vector == NULL)
        return NULL;
    //seteamos el tamaño inicial del vector
    vector->tam = tam_inicial;

    //pedimos espacio para n datos de void genericos
    vector->dato = malloc(sizeof(void *) * tam_inicial);
    if (vector->dato == NULL)
    {
        free(vector);
        return NULL;
    }
    //Limpiamos el vector
    for (char i = 0; i < tam_inicial; i++)
    {
        vector->dato[i] = NULL;
    }
    return vector;
}
//inserta un elemento en la posicion especifica
bool vector_insert(Vector_d *vector, size_t indice, void *elemento)
{ //valida el indice de inssersion
    if (indice < 0 || indice >= vector->tam)
        return false;
    //asigna el valir al indice
    vector->dato[indice] = elemento;
}
//devuelve el valor del elemento segun el indice
void *vector_get(Vector_d *vector, size_t indice)
{
    if (indice < 0 || indice >= vector->tam)
        return NULL;
    return vector->dato[indice];
}

//obtiene el tamaño del vector
size_t vector_length(Vector_d *vector)
{
    return vector->tam;
}

//redimensiona el vector a un nuevo tamaño mas grande
bool vector_resize(Vector_d *vector, size_t tam)
{ //valida un tamaño mayor al actual
    if (tam < vector->tam)
        return false;

    //copia los datos del vector a un void** al tamaño pedido
    void **datos_nuevos = realloc(vector->dato, tam * sizeof(void *));
    if (datos_nuevos == NULL)
        return false;

    free(vector->dato);          //libera los datos del viejo vector
    vector->dato = datos_nuevos; // asigna el nuevo void** al vector dinamico
    vector->tam = tam;           // nuevo tamaño asignado
    return vector;
}

//destruye el vector de la memoria
void vector_destroy(Vector_d *vector)
{
    free(vector->dato);
    free(vector);
}
