#include <stdio.h>

int main (int argc, char *argv[])
{
	int i = 0;
	extern char **environ;
	while (environ[i])
		printf("%s\n", environ[i++]);
	return 0;
}
