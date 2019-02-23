#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *a = NULL;  //declaracion del puntero vector
    void *p1 = NULL; //declaracion del puntero a puntero vector
    a = (int *)malloc(7*sizeof(int));
    a[0] = 2;
    p1 = a;
    *((int *)p1+4) = 50;
    *((int *)p1+5) = 50;
    *((int *)p1+6) = 50;
    *((int *)p1+7) = 50;
    *((int *)p1+8) = 541;
    a[7] = 560;
    printf("Sizeof a: %d\n", sizeof(a));
    printf("|a   -  p1 -      &a   -    &p1  |\n");
    for (int i = 0; i < sizeof(a); i++)
    {
        printf("|[%d] - [%d] - [%d] - [%d]|\n", a[i], *((int *)p1 + i), &a[i], (p1 + i));
    }

    a = realloc(a,4*sizeof(int));
    free(a);
    a[7] = 520;
    printf("Sizeof a: %d\n", sizeof(a));
    printf("|a   -  p1 -      &a   -    &p1  |\n");
    for (int i = 0; i < sizeof(a); i++)
    {
        printf("|[%d] - [%d] - [%d] - [%d]|\n", a[i], *((int *)p1 + i), &a[i], (p1 + i));
    }


    return 0;
}
