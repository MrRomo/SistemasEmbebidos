#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nombre[50];
    char edad;
    float estatura;
} empleado;

void llenar (empleado* strc) {
    strc->edad = 30;
    strc->estatura = 1.75; 
    memcpy(strc->nombre, "carlos", sizeof("carlos"));
}

    int main()
{
    empleado docente;
    docente.edad = 25;
    docente.estatura = 1.89;
    memcpy(docente.nombre, "carlos", sizeof("carlos"));
    printf("Tamaño docente %lu\n", sizeof(docente));
    printf("Nombre docente %s\n", docente.nombre);
    printf("Estatura docente %f\n", docente.estatura);
    printf("Edad docente %d", docente.edad);

    return 0;
}
