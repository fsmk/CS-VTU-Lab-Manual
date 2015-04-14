#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("No of clock ticks: %d\n", sysconf(_SC_CLK_TCK));
	printf("Maximum no of child processes: %d\n", sysconf(_SC_CHILD_MAX));
	printf("Maximum path length: %d\n", pathconf("/", _PC_PATH_MAX));
	printf("Maximum characters in a file name: %d\n", pathconf("/", _PC_NAME_MAX));
	printf("Maximum no of open files: %d\n", sysconf(_SC_OPEN_MAX));
	return 0;
}
