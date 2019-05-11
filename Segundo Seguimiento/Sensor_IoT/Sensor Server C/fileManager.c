#include <stdio.h>
#include <stdlib.h>



// int main()
// {
//     char content[] = ",\nhola perros como estan\n]}";
//     appendFile("listaInvitados.txt", content);
    
    
//     return 0;
// }


void appendFile(const char *filename,const char *content){

    FILE *archivo = NULL;

    deleteline(filename,getLines(filename));

    archivo = fopen(filename, "a");


    fprintf(archivo, "%s", content);

    fclose(archivo);
}

void deleteline(const char *filename,unsigned int linetodelete){
    printf("deleting %s\n", filename);

    FILE *test = fopen(filename,"a");
    fclose(test);

  
    FILE *file=fopen(filename,"r");

    printf("Open temfile\n");

    FILE *filetemp=fopen("__tempfile__","w");

    char line[255];
    unsigned int last = 0;

    while(fgets(line,255,file)!=NULL){
        last++;
    }
    last--;

    rewind(file);

    unsigned int countline=0;

    while(fgets(line,255,file)!=NULL) {
       if (linetodelete != last) {
            if (countline != linetodelete)
            fputs(line, filetemp);
        }
        else {
            if (countline == linetodelete - 1) 
                line[strlen(line) - 1] = '\0';

            if (countline != linetodelete)
                fputs(line, filetemp);
        }
        countline++;
    }

    fclose(file);
    fclose(filetemp);
    rename("__tempfile__",filename);
}
int getLines(const char* filename){
    FILE *fp; 
    int count = 0;  // Line counter (result) 
    char c;  // To store a character read from file 
      // Open the file 
    fp = fopen(filename, "r"); 
  
    // Check if file exists 
    if (fp == NULL) 
    { 
        printf("Could not open file %s", filename); 
        return 0; 
    } 
  
    // Extract characters from file and store in character c 
    for (c = getc(fp); c != EOF; c = getc(fp)) 
        if (c == '\n') // Increment count if this character is newline 
            count = count + 1; 
  
    // Close the file 
    fclose(fp); 
    printf("The file %s has %d lines\n ", filename, count); 
  
    return count; 
}