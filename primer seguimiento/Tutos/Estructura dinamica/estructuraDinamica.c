#include <stdio.h>
#include <stdlib.h>
#include "estructuraDinamica.h"

Contacto* newContact() {
    Contacto* contactoNuevo = malloc(sizeof(Contacto));
    if(!contactoNuevo) printf("error de asiganacion de memoria");
    
    fflush(stdin);
    printf("ingrese la edad del contacto: ");
    scanf("%u", (unsigned)&contactoNuevo->edad);
 
    fflush(stdin);
    printf("ingrese el numero del contacto: ");
    scanf("%ul", &contactoNuevo->numero);
    
    return contactoNuevo;
}

void run(Contacto* contactoPrint){
    printf("\nEdad %u, Numero %u", contactoPrint->edad, contactoPrint->numero);
}


