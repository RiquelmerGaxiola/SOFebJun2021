#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./student.h"


int main(int argc, char **argv){
    char *filename = argv[1];
    int cuantos=atoi(argv[2]);
    
    FILE *forigen;
    forigen = fopen(filename, "rb");
    
    for(int i = 0; i<cuantos; i++){
        STUDENT buffer;
        
        fread(&buffer, sizeof(buffer), 1, forigen);
        printf("Nombre: %s\n", buffer.name);
        printf("Apellido: %s\n", buffer.lastname);  
        printf("ID: %d\n", buffer.id);
        printf("Semestre: %d\n", buffer.semestre);
    }
    fclose(forigen);
    return 0;
}