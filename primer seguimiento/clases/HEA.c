#include <stdio.h>
#include <stdlib.h>


char cuenta () {
    static char cont; 
    cont++;
    return cont;
}

int mem() {
    int vector[100] = {0};
}

int main()
{
    cuenta();
    mem();
    cuenta();
    cuenta();
    printf("Cuenta %d", cuenta());
    return 0;
}
