#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./student.h"


int main(int argc, char **argv){
    char *filename = argv[1];
    char *atributo  = argv[2];
    char *palabra = argv[3];
    char buffer; 

    FILE *forigen;
    forigen = fopen(filename, "rb");

    STUDENT newstudent;

    while(fread(&newstudent, sizeof(newstudent), 1, forigen)){
        if(strcmp(atributo, "name")==0){
            if(strcmp(palabra, newstudent.name)==0){
                printf("Nombre: %s\n", newstudent.name);
                printf("Apellido: %s\n", newstudent.lastname);  
                printf("ID: %d\n", newstudent.id);
                printf("Semestre: %d\n", newstudent.semestre);
            }
        }
        if(strcmp(atributo, "lastname")==0){
            if(strcmp(palabra, newstudent.lastname)==0){
                printf("Nombre: %s\n", newstudent.name);
                printf("Apellido: %s\n", newstudent.lastname);  
                printf("ID: %d\n", newstudent.id);
                printf("Semestre: %d\n", newstudent.semestre);
            }
        }
        if(strcmp(atributo, "id")==0){
            if(atoi(palabra)==newstudent.id){
                printf("Nombre: %s\n", newstudent.name);
                printf("Apellido: %s\n", newstudent.lastname);  
                printf("ID: %d\n", newstudent.id);
                printf("Semestre: %d\n", newstudent.semestre);
            }
        }
        if(strcmp(atributo, "id")==0){
            if(atoi(palabra)==newstudent.semestre){
                printf("Nombre: %s\n", newstudent.name);
                printf("Apellido: %s\n", newstudent.lastname);  
                printf("ID: %d\n", newstudent.id);
                printf("Semestre: %d\n", newstudent.semestre);
            }
        }
    }
    
    fclose(forigen);
    return 0;
}