#include <stdio.h>
#include <stdlib.h>


int main()
{
    int var = 68;
    void * prtVar = NULL;
    int * prtVar2 = &var;
    prtVar = &var;
    printf("valor de var a travez del puntero2: %d\ne", *prtVar2);
    printf("valor de var a travez del puntero: %d", *(int*)prtVar);
    return 0;
}
