#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
//0 = stdin
//1 = stdout
int main(){
    char minC;
    int lineas = 0;
    while(read(0,&minC,1)){
        if(minC=='\n')
            lineas++;
    }    
    printf("Numero de lineas: %d\n",lineas);
    return 0;
}