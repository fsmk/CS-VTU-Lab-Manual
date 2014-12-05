###Aim:
C program to create a file with 16 bytes of arbitrary data from the beginning and another 16 bytes of arbitrary data from an offset of 48. Display the file contents to demonstrate how the hole in file is handled.

####Description:
<pre>  fd:file descriptor
  lseek:function is used to seek the memory offset
</pre>
####Code:
	#include<stdio.h>
	#include<stdlib.h>
	#include<fcntl.h>

	int main()
	{
		int fd;
		char buf2[16]="ABCDEFGHIJKLMNOP";
		char buf1[16]="abcdefghijklmnop";
		fd=open("data.txt",777);
		if(fd==-1)
			printf("Error creating file");
		else{
			write(fd,buf1,16);
			lseek(fd,32,SEEK_CUR);
			write(fd,buf2,16);
		}
		close(fd);
	}
</pre>
####Output:
<pre>abcdefghijklmnop^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@ABCDEFGHIJKLMNOP
</pre>
