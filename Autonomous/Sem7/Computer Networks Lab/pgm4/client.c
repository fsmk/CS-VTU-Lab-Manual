#include<string.h>
#include<stdio.h>
#include<netinet/in.h>
int main(){
     int sockfd,n,portno;
     char fname[20],buf[100],host[20];
     struct sockaddr_in serv;

	printf("This is client :\n");
	bzero(host,20);
  	printf("\nEnter IP address of server: "); 
  	scanf("%s",host);
  			
	printf("\nEnter port no :");
  	scanf("%d",&portno);             
 	printf("\nClient:Enter file name which is in server:");
 	scanf("%s",fname);
  
	sockfd=socket(AF_INET,SOCK_STREAM,0);
 	  
	bzero(&serv,sizeof(serv));
 	serv.sin_family=AF_INET;
 	serv.sin_port=htons(portno);
	serv.sin_addr.s_addr = inet_addr(host);
	
 	connect(sockfd,(struct sockaddr *)&serv,sizeof(serv));
 	 
	write(sockfd,fname,strlen(fname));
   	  
    bzero(&buf,sizeof(buf));
 	printf("\nClient:File contents\n"); 
	while(read(sockfd,buf,100)>0)
        printf("%s",buf);  	     
	close(sockfd);   
        return 0;	       
 }
