#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int pid;
	pid = fork();

	if (pid == 0) {
		// First child
		pid = fork();
		if (pid == 0) {
			// Second child
			sleep(1);
			printf("Second child: My parent PID is %d\n", getppid());
		}
	}
	else {
		// Parent process
		wait(NULL);
		sleep(2);
		system("ps -o pid,ppid,state,tty,command");
	}
	return 0;
}
