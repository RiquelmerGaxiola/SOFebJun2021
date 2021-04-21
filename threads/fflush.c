#include <stdio.h>
#include <stdlib.h>

int main(){
    char str[80], ch;
    int dato;
    float valor;
    scanf("x=%f",&valor); //str=&str[0]
    ch = getchar();
    //printf("%s\n",str);
    //printf("&d\n",dato);
    printf("%f \n",valor);
    printf("%c",ch);
    printf("\n");

    return 0;
}