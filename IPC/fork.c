#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int varG;
int pidHijoTermino;

void signalHandler(int sig){
	pidHijoTermino = wait(NULL);
	varG=0;
}

int main(){
    int pid = fork();
    
    if(pid == 0){
        //Proceso hijo
        printf("Soy el proceso hijo\n");
    }else{
        varG=1;
	    signal(2, signalHandler);
	    signal(15, signalHandler);  
        signal(17, signalHandler); 
        printf("Soy el proceso padre y mi hijo es %d\n", pidHijoTermino);         
        //Se puede utilizar el Ctrl+C para terminar el proceso   
        while(varG){
            printf("Trabajando\n");
            sleep(0.5f);
        }
        printf("Mi hijo termino\n");
    }
    printf("Terminado\n");
    return 0;
}