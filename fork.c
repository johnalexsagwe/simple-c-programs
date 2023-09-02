#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	printf("before fork i was one\n");
/* Store return value of fork in pid */
	pid = fork();
	if (pid == -1)
	{
		printf("Fork unsuccessful\n");
		return1;
	}
	if (pid == 0)
	{
		//This code  will be executed by the child
		printf("I am the child process (PID %d)\n",getpid()));
	}
	else
	{
		printf("I am the parent process (PID) %d),my child is %d\n", getpid(), pid);
	}
	printf("After fork, i become two\n");
	return 0;
}
