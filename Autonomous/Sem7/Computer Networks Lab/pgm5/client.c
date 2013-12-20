#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>

char fname[256];

int main()
{
    ssize_t n;
    char buff[512];
    int readfd, writefd;
    
    printf("Trying to Connect to Server..\n");
    // Opening fifo channels for communication
    writefd = open("fifo1", O_WRONLY, 0);
    readfd  = open("fifo2", O_RDONLY, 0);
    printf("Connected..\n");
    
    // Take user input: the filename to display
    printf("Enter the filename to request from server: ");
    scanf("%s",fname);

    // Send the filename to the server by writing it to fifo1
    write(writefd, fname, strlen(fname) + 1);

    // Read response sent by the server by reading from fifo2
    printf("Waiting for Server to reply..\n");
    while((n = read(readfd,buff,512))>0)	
        write(1,buff,n); //Display the response on the screen
    
    //Closing connections
    close(readfd);
    close(writefd);
    return 0;
}

