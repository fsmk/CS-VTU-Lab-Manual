// for std C functions
#include <stdio.h>
#include <stdlib.h>

// for general Unix apis
#include <unistd.h>
#include <sys/types.h>

// for file apis
#include <sys/stat.h>
#include <fcntl.h>

// for socket apis
#include <netinet/in.h>
#include <sys/socket.h>

int main(){
    int server, client, fd, count;
    int buflen = 1024;
    char *buf = malloc(buflen);
    char fname[256];
    struct sockaddr_in address;
    
    server = socket(AF_INET, SOCK_STREAM, 0);
    if(server < 0){
        printf("Couldnot create socket");
        return -1;
    }
    printf("The socket was created\n");
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(15000);
    
    printf("Binding Socket\n");
    if(bind(server, (struct sockaddr*)&address, sizeof(address)) != 0){
        printf("Error binding address to server");
        return -1;
    }
    printf("Done\n");

    listen(server, 3);
    printf("Server started\n");
    int len = sizeof(address);
    client = accept(server, (struct sockaddr*)&address, &len);
    if(client > 0){
        printf("Client connected\n");
        
        // Receiving filename
        recv(client, fname, 255, 0);
        
        //Opening file
        if ((fd = open(fname, O_RDONLY)) < 0){
            perror("File Open Failed"); 
            return 0;
        }

        //Reading contents and sending
        while((count = read(fd, buf, buflen)) > 0) {
            send(client, buf, buflen, 0);
        }

        printf("Data sent\n");
        close(client);
        close(server);
    }
    return 0;
}