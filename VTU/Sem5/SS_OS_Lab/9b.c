#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
	pid_t p;
	if((p=fork())<0)
	{
		printf("fork error\n");
		return 0;
	}
	else if(p==0)
	{
		printf("i am child process\n");
		printf("my parent process id is:%d\n",getppid());
		printf("my process id is:%d\n",getpid());
	}
	else
	{
		wait();
		printf("i am parent process\n");
		printf("my child process id is:%d\n",p);
		printf("my own id is: %d\n",getpid());
	}
	return 0;
}
		
	





