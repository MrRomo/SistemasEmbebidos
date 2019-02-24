#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int dato;
    struct Nodo *next;
    struct Nodo *prev;
} Nodo;

typedef struct list
{
    Nodo *head;
    Nodo *tail;
} List;

Nodo *head = NULL;
Nodo *tail = NULL;
void node_insert(Nodo *nodo);

int main(int argc, char const *argv[])
{

    return 0;
}

void node_new()
{
    Nodo *nuevo = malloc(sizeof(Nodo));
    scanf("%d", &nuevo->dato);
    nuevo->next = NULL;
    
    if (head == NULL)
    {
        head = nuevo;
        head->next=head;
        tail = head;
        head->prev = tail;
    }
    else
    {
        tail->next = nuevo;
        nuevo->next = head;
        nuevo->prev = tail;
        tail = nuevo;
        head->prev = tail;
    }
}