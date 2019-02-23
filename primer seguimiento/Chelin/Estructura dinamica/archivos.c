#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("Bienvenidos al escritor");

    FILE* miArchivo = NULL;

    char* filename = "output/Data.json";
    char lectura[80];
    miArchivo = fopen(filename, "w"); //Abre el archivo en escritura
    if(!miArchivo) return -1;

    fprintf(miArchivo,"{\"text\": \"Hola soy un nuevo archivo\",\n"); 
    fprintf(miArchivo,"\"text2\": \"Hola soy un nuevo archivo2\"}\n");
    fclose(miArchivo);

    miArchivo = fopen(filename, "r");
    if(!miArchivo) return -1;

    fscanf(miArchivo," %[^\n]",&lectura);
    printf("\nLectura %s", lectura);

    fscanf(miArchivo," %[^\n]",&lectura);
    printf("\nLectura %s", lectura);

    fscanf(miArchivo," %[^\n]",&lectura);
    printf("\nLectura %s", lectura);
    
    return 0;

}
