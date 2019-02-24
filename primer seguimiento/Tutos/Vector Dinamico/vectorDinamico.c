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
    int pos = 3;
    char* ele = (char *)vector_get(v1,pos);
    printf("Vector pos %d: %s", pos, ele);

}