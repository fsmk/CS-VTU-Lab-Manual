###Aim:
C program to do the following: Using fork( ) create a child process.The child process prints its own process-id and id of its parent and then exits. The parent process waits for its child to finish (by executing the wait( )) and prints its own process-id and the id of its child process and then exits.

###Description:
<p>pid_t:parent id of the process.
<p>fork():it is a system call which forks a new child of a processs</p>

###Code:
<pre>`#`include&lt;stdio.h>
`#`include&lt;unistd.h>
`#`include&lt;stdlib.h>
int main()
{
	pid_t p;
	if((p=fork())&lt;0)
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
}</pre>

###Output:
<pre>i am child process
my parent process id is:4273
my process id is:4274
i am parent process
my child process id is:4274
my own id is: 4273</pre>

		
	




