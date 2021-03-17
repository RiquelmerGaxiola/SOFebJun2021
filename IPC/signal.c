#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int varG;

void signalHandler(int sig){
	printf("Recibi segnal %d\n", sig);
	varG=0;
}

int main(){
	varG=1;
	signal(2, signalHandler);
	signal(15, signalHandler);
	while(varG){
		printf("Trabajando\n");
		sleep(1);
	}
	printf("Ya voy a terminar \n");
	return 0;
}