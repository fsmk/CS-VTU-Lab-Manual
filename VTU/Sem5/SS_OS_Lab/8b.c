#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
	int fd;
	char buf2[16]="ABCDEFGHIJKLMNOP";
	char buf1[16]="abcdefghijklmnop";

	fd=open("data.txt",O_RDWR|O_CREAT|O_EXCL,0765);

	if(fd==-1)
	printf("Error creating file");
	else
	write(fd,buf1,16);
	lseek(fd,32,SEEK_CUR);
	write(fd,buf2,16);
	system(" vi data.txt");
	close(fd);
}


