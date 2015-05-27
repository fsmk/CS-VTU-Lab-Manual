#include <stdio.h>

int main (int argc, char *argv[])
{
	extern char **environ;
	char **ptr;
	for (ptr = environ; *ptr != NULL; ptr++)
		printf("%s\n", *ptr);
	return 0;
}
