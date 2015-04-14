#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#define INTERVAL 5

void callme(int sig)
{
	printf("Hello!!!\n");
	exit(EXIT_SUCCESS);
}

int main()
{
	struct sigaction action;
	action.sa_handler = (void(*)(int))callme;
	sigaction(SIGALRM, &action, NULL);
	alarm(INTERVAL);
	pause();
	return 0;
}
