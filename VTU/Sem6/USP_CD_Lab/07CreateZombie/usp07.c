#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>

int main()
{
	int pid;
	pid = fork();
	assert(pid >= 0);

	if (pid != 0) {
		sleep(2);
		system( "ps -o pid,ppid,state,tty,command");
	}
	return 0;
}
