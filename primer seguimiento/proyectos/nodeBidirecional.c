#include <stdio.h>
#include <stdlib.h>

void clrscr()
{
    system("@cls||clear");
}

typedef struct
{
    char dato;
    struct nodo* ptrNext;
    struct nodo* ptrPrev;
}nodo;

typedef struct
{
    struct nodo* header;
    struct nodo* footer;
}newList;

void main()
{



}
