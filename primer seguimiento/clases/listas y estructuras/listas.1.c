#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

typedef struct
{
    int indice;
} lista;

int main()
{
    while (1)
    {
        printf("%d\n", getch());
    }

    return 0;
}
