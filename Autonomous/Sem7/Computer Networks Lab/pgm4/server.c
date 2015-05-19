#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
int main(){
	int sockfd,newsockfd,portno;
	char buffer[256],fname[20];	
	struct sockaddr_in cli;
	FILE *fptr;

	printf("This is server\n");
	printf("Enter server port number  : ");
	scanf("%d",&portno);
	
	sockfd=socket(AF_INET,SOCK_STREAM,0);
	bzero(&cli,sizeof(cli));
	cli.sin_family=AF_INET;
	cli.sin_addr.s_addr=INADDR_ANY;
	cli.sin_port=htons(portno);

	bind(sockfd,(struct sockaddr *)&cli,sizeof(cli));
		
	printf("\nNow server is up wating for client");
	
	listen(sockfd,1);
	
	while(1){
		newsockfd=accept(sockfd,NULL,NULL);               
		printf("\n New client requested it sockfd  =  %d",newsockfd);
		bzero(fname,20);
		close(sockfd);

     	read(newsockfd,fname,20);
    	printf("\nClient requesting %s file content\n\n",fname);

		if((fptr=fopen(fname,"r"))==NULL){		  
         	printf("\nSERVER:file not found");
		    strcpy(buffer, "File not Found vijay");
            write(newsockfd, buffer, strlen(buffer));
            close(newsockfd);
	 	    fclose(fptr);
         	return 0;   
        }
	
   	printf("\nServer : Following information is sent to the client \n\n\n");

    while(fgets(buffer,79,fptr)!=NULL){
        write(newsockfd, buffer, strlen(buffer));
	    printf("%s",buffer);
	}
	      
    close(fptr);
    close(newsockfd);
    return 0;
    }    
}
