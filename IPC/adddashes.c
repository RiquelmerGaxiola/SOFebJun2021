#include <unistd.h>
#include <stdio.h>

int main(){
    int fd[2];
    int pid;
    pipe(fd);
    pid = fork();    
    if(pid == 0){
        //Hijo
        close(fd[1]);
        //La 1ra posicion es la entrada
        dup2(fd[0],STDIN_FILENO);
        execl("/usr/bin/tr","tr","' '","-",NULL);
    }
    if(pid > 0){
        //Padre
        close(fd[0]);
        //La 2da posicion es la salida
        dup2(fd[1],STDOUT_FILENO);
        execl("/usr/bin/cat","cat",NULL);
    }
    //execl("/usr/bin/ls","ls","-l","-a",NULL);
    return 0;
}