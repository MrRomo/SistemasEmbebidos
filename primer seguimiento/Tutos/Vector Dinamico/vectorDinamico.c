#include <stdio.h>
#include <stdlib.h>
#include "dinamicVector.c"

int main()
{
    vector_t* v1 = vector_new(4);
    int dato1 = 7;
    float dato2 = 53.23;
    char dato3 = 'g';
    char dato4[] = "Nuevo vector";

    vector_insert(v1,0,&dato1);
    vector_insert(v1,1,&dato2);
    vector_insert(v1,2,&dato3);
    vector_insert(v1,3,dato4);
    printf("Vector pos %d: %d\n", 0, *(int*)vector_get(v1,0));
    printf("Vector pos %d: %f\n", 1, *(float *)vector_get(v1,1));
    printf("Vector pos %d: %c\n", 2, *(char *)vector_get(v1,2));
    printf("Vector pos %d: %s\n", 3, (char *)vector_get(v1,3));

}

//  char letra = 'd';
//     char letra2 = 'F';
//     list_append(lista1, &letra, &letra);
//     list_append(lista1, &letra2, &letra2);
//     Vector_d* v1 = vector_new(2);
//     int dato1 = 7;
//     char dato2 = 'g';

//     vector_insert(v1,0,&dato1);
//     vector_insert(v1,1,&dato2);
//     printf("Vector pos %c:\n", *(char *)vector_get(v1,1));
//     printf("LIST [%d] head: [%c]", lista1->tam,*(char*)lista1->pos->dato->dato[0]);
//     list_run(lista1);