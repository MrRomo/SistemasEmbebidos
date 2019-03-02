#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[] = {3,2,3};
    printf("tamañp, valor y direccion: %d - %d - %d\n", sizeof(a), a, &a);
    int * p1 = NULL;
    p1 = malloc(sizeof(int));
    printf("sizeof int: %d \n", sizeof(int));
    int * p1_c = (int *)p1;
    *p1 = a;
    printf("puntero, valor  y tamaño: %d - %d - %d\n", p1, *p1, sizeof(p1));
    printf("puntero c, valor y tamaño: %d - %d - %d\n", p1_c, *p1_c, sizeof(p1_c));
    free(p1);
   
    printf("\n");



    return 0;
}
