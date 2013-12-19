// for std C functions
#include <stdio.h>
#include <malloc.h>

// for general Unix apis
#include <unistd.h>
#include <sys/types.h>

// for socket apis
#include<sys/socket.h>
#include<netinet/in.h>


int main(int argc,char *argv[])
{
    int server,count;

    // Creating buffer of file data
    int bufsize = 1024;
    char *buffer = malloc(bufsize);

    // To store filename input by user
    char fname[256];

    // Socket Address
    struct sockaddr_in address;

    // Creating socket
    if ((server = socket(AF_INET,SOCK_STREAM,0)) > 0)
        printf("The Socket was created\n");

    // Initialing address
    address.sin_family = AF_INET; //address family
    address.sin_port = htons(15000); //port number

    //Storing IP addr in appropriate format
    inet_pton(AF_INET,"127.0.0.1",&address.sin_addr); 
    
    //Connecting to server
    if (connect(server, (struct sockaddr *) &address, sizeof(address)) == 0)
        printf("The connection was accepted by the server\n");

    // User inputs filename
    printf("Enter The Filename to Request : "); scanf("%s",fname);

    // Sending data...
    send(server, fname, sizeof(fname), 0);

    // Once sending is completed, control resumes here where we receive 
    // the data from the sever 
    printf("Request Accepted... Receiving File...\n\n");
    printf("The contents of file are...\n\n");
    
    // Receive the data in buffer as long as server sends data
    while((count = recv(server, buffer, bufsize, 0)) > 0) {
        // Write the buffer data to the screen immediately
        write(1, buffer, count); 
        //printf will not work here as the buffer is not a C string
    }
    
    // No more data to display, hence displaying End of File
    printf("\nEOF\n");

    // Closing the socket
    close(server);
    return 0;
}
