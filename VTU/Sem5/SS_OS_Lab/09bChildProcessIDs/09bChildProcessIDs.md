###Aim:
C program to do the following: Using fork( ) create a child process.The child process prints its own process-id and id of its parent and then exits. The parent process waits for its child to finish (by executing the wait()) and prints its own process-id and the id of its child process and then exits.

###Description:
<p>pid_t:parent id of the process.
<p>fork():it is a system call which forks a new child of a processs</p>

###Code:
	#include<stdio.h>
	#include<unistd.h>
	#include<stdlib.h>
	int main()
	{
		int pid;
		pid=fork();
		if(pid==0){
			//child
			printf("--Child in execution--\n");
			printf("Process ID of child:%d\n",getpid());
			printf("Process ID of parent:%d\n",getppid());
			printf("Done with child\n\n");
		}else{
			//parent
			printf("--Parent in execution--\n");
			printf("Process ID of parent:%d\n",getpid());
			printf("Process ID of child:%d\n",pid);
			printf("Done with parent\n\n");
		}
	}

###Output:
	--Child in execution--
	Process ID of child:3432
	Process ID of parent:3431
	Done with child


	--Parent in execution--
	Process ID of parent:3431
	Process ID of child:3432
	Done with parent