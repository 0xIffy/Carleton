#include "stdio.h"
#include "unistd.h"
#include "stdlib.h"
int main(int argc, char *argv[])
{
	char *param[5];
	param[0] = "morphed";
	param[1] = "55";
 	param[2] = "Second Command Parameter";
 	param[3] = "5";
 	param[4] = NULL;
	int pid, cpid;
	int status;

	pid = fork();
	if (pid == 0) {
	// child process instructions
	int rc;
	rc = execv("./morphed",param);
	printf(" This should not be printed \n"); // this should not be executed because
	// the child is executing a new program
	} else {
	// parent process instructions
	printf("Parent program \n");
	cpid = wait(&status);
	printf("cpid=%d\n",cpid);
	if(WIFEXITED(status))
		printf("Child has returned value %d\n", WEXITSTATUS(status));
	}
}