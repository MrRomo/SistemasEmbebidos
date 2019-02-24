#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct Nodo* next;
}Nodo;

Nodo* head = NULL;
Nodo* tail = NULL;

void node_insert(Nodo* nodo){
    nodo->next = NULL; 
    if(head == NULL){
        head = nodo;
        tail = nodo;
    }else
    {
        tail->next = nodo;
        tail = nodo;
    }
}

int main()
{
    Nodo* primerNodo = malloc(sizeof(Nodo));
    primerNodo->dato = 5;
    
    Nodo* segundoNodo = malloc(sizeof(Nodo));
    segundoNodo->dato = 4;

    node_insert(primerNodo);
    node_insert(segundoNodo);

    Nodo *i = primerNodo;
    while(i!=NULL){
        printf("%i\n", i->dato);
        i = i->next;
    }
    

   return 0;
}