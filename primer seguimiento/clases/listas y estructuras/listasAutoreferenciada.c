#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char dato;
    struct nodo* ptrNext;
}nodo;

nodo* header = NULL;
nodo* footer = NULL;

nodo* new()
{
    nodo* nuevo = malloc(sizeof(nodo));
    nuevo->ptrNext = NULL;
    return nuevo;
}

void run(){
    nodo* i = NULL;
    i = header; 
    printf("[");
    while(i!=NULL){
        printf("%c,",i->dato);
        i = i->ptrNext;
    }
    printf("]\n");
}

char get(char n){
    nodo* i = NULL;
    i = header; 
    char c = 0;
    while((n!=c)&&(i!=NULL)){
        printf("(%c)",i->dato);
        i = i->ptrNext;
        c++;
    }
    return i->dato;
}

void insert(nodo* Nodo) {
    if(header==NULL){
        header = footer = Nodo;
    }else
    {
        footer->ptrNext = Nodo;
        footer = Nodo;
    }
}

void append(char dato){
    nodo* i = new();
    i->dato = dato;
    insert(i);
}

int main()
{
    for(char c = 'A'; c <= 'Z'; ++c){
        append(c);
    }
    while(1) {
        printf("ingrese la posicion a acceder: ");
        char pos;
        scanf("%d",&pos);
        printf("[%d]\n", pos);        
        printf("[%c]", get(pos));        
    }
    return 0;
}
