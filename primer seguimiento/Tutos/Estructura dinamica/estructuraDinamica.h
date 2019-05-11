#ifndef _DINAMICSTRUCTURE
#define _DINAMICSTRUCTURE
#include <stdio.h>
#include <stdlib.h>

struct contacto;

typedef struct contacto
{
    char nombre[50];
    unsigned char edad;
    unsigned long numero;
}Contacto;

Contacto* newContact();  

void run(Contacto* contactoPrint);

#endif