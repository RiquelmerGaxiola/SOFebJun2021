// init: The initial user-level program

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

char *argv[] = { "sh", 0 };

int
main(void)
{
  int pid, wpid;

  if(open("console", O_RDWR) < 0){
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  for(;;){
    printf(1, "¡Bienvenido a su xv6 personal!\n");
    pid = fork();
    if(pid < 0){
      printf(1, "init: fork failed\n");
      exit();
    }
    if(pid == 0){
	//Al cambiar sh por ls.-
		//Tardó mucho menos en iniciar nuestro sistema operativo, es por mera suposición, pero me imagino que sh es un proceso muy pesado que realiza muchas acciones, y al saltarnos ese paso el resto de "init" ocurre más rapidamente. Sin embargo, al introducir una ejecución de "ls", la terminal imprime la lista de archivos del directorios, es decir, corre "ls" infinitamente, por lo que fue necesario "matar" el proceso manualmente reiniciando la consola.
	//Al cambiar sh por nohayprograma.-
		//Al no existir un programa llamado "nohayprograma", el "init" intenta iniciarlo constantemente, aparentemente sin fin, por lo que también fue necesario reiniciar la consola para terminar dicho proceso.
      exec("sh", argv);
      printf(1, "init: exec sh failed\n");
      exit();
    }
    while((wpid=wait()) >= 0 && wpid != pid)
      printf(1, "zombie!\n");
  }
}
