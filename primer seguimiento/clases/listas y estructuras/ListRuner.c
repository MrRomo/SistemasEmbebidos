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

nodo* header = NULL;
nodo* footer = NULL;

nodo* new()
{
    nodo* nuevo = malloc(sizeof(nodo));
    nuevo->ptrNext = NULL;
    nuevo->ptrPrev = NULL;
    return nuevo;
}
void run(){
    nodo* i = NULL;
    i = header; 
    printf("[");
    char n =0;
    while(i!=NULL){
        printf("%c", 3);
        printf("%c, ",i->dato);
        n++;
        i = i->ptrNext;
    }
    printf("]\n");
}
char length(){
    nodo* i = NULL;
    i = header; 
    char n = 0;
    while(i!=NULL){
        n++;
        i = i->ptrNext;
    }
    return n;
}

char get(char n){
    nodo* i = NULL;
    i = header; 
    char c = 0;
    if(length()>=n-1){
        while((n!=c)&&(i!=NULL)) {
            // printf("(%c)",i->dato);
            i = i->ptrNext;
            c++;
        }
        return i->dato;
    }else
    {
        return NULL;
    }
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
void append (char dato) {
    nodo* i = new();
    i->dato = dato;
    insert(i);
}
void space (char pos){
    for(char i = 0; i <pos; i++)
    {
        printf(" ");
    }
}
int main()
{
    for(char c = 'A'; c <= 'Z'; ++c){
        append(c);
    }
    char pos = 0;
    char res = 0;
    run();

    while(1) {
        printf("\n\ningrese la direccion a(izquierda)||d(derecha): \n");
        scanf("%c",&res);
        switch (res)
        {
            case 'a':
                pos--;
                if(pos<0) pos = 0;
                break;
            case 'd':
                pos++;
                if(pos>length()-1) pos = length()-1;
                break;
            default:
                break;
        }
        clrscr();
        run();
        space(pos*3);
        printf("^\n");        
        printf("[%c]\n", get(pos));
    }
    // run();
    return 0;
}
