#include <stdio.h>
#include <stdlib.h>

int main()
{
	char cmd[10];
	int ch;
	pid_t pid;
	if((pid=fork())<0)
	{
		printf("fork error\n");
		return 0;
	}
	if(pid==0)
	{
		printf("i am parent process\n");
		printf("process id =%d\n",getpid());
		printf("parent process id=%d\n",getppid());
		scanf("%s",cmd);
		system(cmd);

	}
	else
	{
	 	printf("%d",getpid());  
                printf("%d",getppid());
		wait();
	}
}
