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
    // empleado docente1;
    // empleado docente2;
    // memcpy(docente1.nombre, "carlos", sizeof("carlos"));
    // docente1.edad = 25;
    // docente1.estatura = 1.89;
    empleado docente; 
    empleado* ptrDocente = NULL;
    ptrDocente = &docente;
    llenar(ptrDocente);
    printf("Tamaño docente %lu\n", sizeof(docente));
    printf("Nombre docente %s\n", docente.nombre);
    printf("Estatura docente %f\n", docente.estatura);
    printf("Edad docente %d", docente.edad);

    return 0;
}
