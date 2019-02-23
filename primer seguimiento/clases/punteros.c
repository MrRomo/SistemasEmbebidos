#include <stdio.h>
#include <stdlib.h>

int main()
{
    char x = 5;
    char* ptrx = NULL;
    ptrx = &x;
    printf("X desde la variable: %d\n",x);
    printf("X desde el puntero: %d\n",*ptrx);

    char vec[5] = {1,2,3,4,5};
    int* ptrVec = NULL;
    ptrVec = &vec[0];
    printf("Posicion vec: %d\n", *ptrVec);
    printf("Posicion vec: %d\n", *(ptrVec+1));
    printf("Posicion vec: %d\n", *(ptrVec+2));
    printf("Posicion vec: %d\n", *(ptrVec+3));
    printf("Posicion vec: %d\n", *(ptrVec+4));

    return 0;
}
