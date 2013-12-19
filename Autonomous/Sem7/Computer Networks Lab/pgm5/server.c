#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

char fname[256];


int main() {
	int readfd, writefd, fd;
	ssize_t n;
	char buff[512];

    // Create fifo files for communication
	if (mkfifo("fifo1", 0666)<0)
	printf("Unable to create FIFO files\n");
	if (mkfifo("fifo2", 0666)<0)
	printf("Unable to create FIFO files\n");

    //On seeing the above messages, try 'rm fifo1 fifo2' and run the server again
	
    printf("Waiting for connection Request..\n");
    // opening fifo files to start communication
	readfd = open("fifo1", O_RDONLY, 0);
	writefd = open("fifo2", O_WRONLY, 0);
	printf("Connection Established..\n");

    // Read client's request sent via fifo1
	read(readfd, fname, 255);
	printf("Client has requested file %s\n", fname);

    // Check if the requested file exists
	if ((fd = open(fname, O_RDWR)) < 0) {
        // If no, send message "File doesnot exist to the client
        strcpy(buff, "File does not exist..\n");
        write(writefd, buff, strlen(buff));
	} 
    else {
        // Otherwise, read the data in the file and send it
        while((n = read(fd, buff,512)) > 0)
            write(writefd, buff, n);
	}
	close(readfd);  
    unlink("fifo1");
	close(writefd);  
    unlink("fifo2");
}

