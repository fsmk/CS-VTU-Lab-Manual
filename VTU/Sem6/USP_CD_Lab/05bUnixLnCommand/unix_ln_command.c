#include <stdio.h>
#include <unistd.h>

int main (int argc, char *argv[])
{
	if(argc != 3) {
		printf("Usage: %s SRC DEST\n", argv[0]);
		return 1;
	}
	if(link(argv[1], argv[2]) == -1) {
		printf("Link error\n");
		return 1;
	}
	return 0;
}
