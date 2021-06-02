

#include "stdio.h"
#include "stdlib.h"
#include <unistd.h>

int main()
{ 
    int pid, cpid;
    int i=0;
		int status;
    
    printf("Ready to fork...\n"); 
    pid = fork();	// create a clone
    // printf("Fork returned %d\n",pid);

		if(pid == 0){
			printf("Child process pid=%d parent process pid=%d\n",getpid(),getppid());
			return 55;
		} else if(pid > 0){
			printf("Parent process pid=%d child process pid=%d\n",getpid(),pid);
			cpid = wait(&status);
			printf("cpid=%d\n",cpid);
			if(WIFEXITED(status))
				printf("Child has returned value %d\n", WEXITSTATUS(status));
			return 0;
		} else{
			printf("\t ERROR - parent process pid=%d could not fork a child process \n",getpid());
			return(1);
		}

  //   for (i = 0; i < 3; i++){
  //       printf("%d: in foor loop \n",pid);
  //       sleep(1);
  //       i++;
	// }

}

