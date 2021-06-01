#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./student.h"


int main(int argc, char **argv){
    char *filename = argv[1];
    char *atributo  = argv[2];
    char *palabra = argv[3];
    char *cambio = argv[4];

    FILE *forigen;
    forigen = fopen(filename, "rb+");

    STUDENT newstudent;

    while(fread(&newstudent, sizeof(newstudent), 1, forigen)){
        if(strcmp(atributo, "name")==0){
            if(strcmp(palabra, newstudent.name)==0){
                strcpy(newstudent.name,cambio);
                fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
                fwrite(&newstudent, sizeof(newstudent),1,forigen);
            }
        }
        if(strcmp(atributo, "lastname")==0){
            if(strcmp(palabra, newstudent.lastname)==0){
                strcpy(newstudent.lastname,cambio);
                fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
                fwrite(&newstudent, sizeof(newstudent),1,forigen);
            }
        }
        if(strcmp(atributo, "id")==0){
            if(atoi(palabra)==newstudent.id){
                newstudent.id=atoi(cambio);
                fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
                fwrite(&newstudent, sizeof(newstudent),1,forigen);
            }
        }
        if(strcmp(atributo, "semestre")==0){
            if(atoi(palabra)==newstudent.semestre){
                newstudent.semestre=atoi(cambio);
                fseek(forigen, -1 * sizeof(newstudent), SEEK_CUR);
                fwrite(&newstudent, sizeof(newstudent),1,forigen);
            }
        }
    }
    
    fclose(forigen);
    return 0;
}