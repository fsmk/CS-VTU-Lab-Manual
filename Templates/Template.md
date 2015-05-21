# Template for documentation
Following can be used for reference while documenting the programs. Note that this is just an example.

## Aim: 
### Using TCP/IP sockets, write a client-server program to make client sending the file name and the server to send back the contents of the requested file if present.

## Theory
> This  is  an  implementation of the TCP protocol. It provides a reliable, stream-oriented, full-duplex connection between two sockets on top of IP, for both v4 and v6 versions.  TCP  guarantees  that  the  data arrives in order and retransmits lost packets.  It generates and checks a per-packet checksum to catch transmission errors.  TCP does not preserve record boundaries.

> A newly created TCP socket has no remote or local address and is not fully specified.  To create an  outgoing  TCP  connection  use  connect to  establish  a  connection  to  another  TCP socket.  To receive new incoming connections, first bind the socket to a local address and port and then call listen to put the socket into the listening state.  After that a new socket for each  incoming  connection  can  be  accepted using accept.  A socket which has had accept or connect successfully called on it is fully specified and may transmit data.  Data cannot be transmitted on listening or not yet connected sockets.

## Algorithm: Client Side
1. Start.
2. Create a socket using socket() system call.
3. Connect the socket to the address of the server using connect() system call.
4. Send the filename of required file using send() system call.
5. Read the contents of the file sent by server by recv() system call.
6. Stop.

## Algorithm: Server Side
1. Start.
2. Create a socket using socket() system call.
3. Bind the socket to an address using bind() system call.
4. Listen to the connection using listen() system call.
5. accept connection using accept()
6. Receive filename and transfer contents of file with client.
7. Stop.

## Code: client.c
    #include<stdio.h>
    #include<fcntl.h> 
    // included for file handling using write()
    #include<unistd.h>
    #include<arpa/inet.h> 
    // included to access inet_addr,socket(), send(), recv() method
    int main()
    { 
      char fname[50],buffer[1024];
      int s,n;
      struct sockaddr_in address; 
      // sockaddr_in is used for ip manipulation
      address.sin_family=AF_INET; 
      // default family address
      address.sin_port=htons(15000); 
      // port through which IPC is established
      address.sin_addr.s_addr=INADDR_ANY; 
      // any address can be asssigned to the client
      if((s=socket(AF_INET,SOCK_STREAM,0))<0) 
      // socket() creates an endpoint for communication and returns a descriptor.
      	perror("socket\n");
      	connect(s,(struct sockaddr*)&address,sizeof(address)); 
      // connect - initiate a connection on a socket
      printf("enter file name:\n");
      scanf("%s",fname);
      printf("sending request..\n");
      send(s,fname,sizeof(fname),0); 
      // send() is used to transmit a message to another socket.
      printf("received response\n");
      while((n=recv(s,buffer,sizeof(buffer),0))>0) 
      /* recv() used to receive messages from a socket, and may be used to receive data on a socket whether or not it is connection-oriented. Returns a file descriptor */
    	write(1,buffer,n); 
      // send a message to another user
      return 0;
    }

## Code: server.c
    #include<stdio.h>
    #include<fcntl.h> 
    //included for file handling using write(), read(), open() methods
    #include<unistd.h>
    #include<arpa/inet.h> 
    // included to access inet_addr(), bind(), socket(), send(), recv(), accept() method
    int main()
    {
      char fname[50],buffer[1024];
      int s,n,source,file;
      struct sockaddr_in address;
      address.sin_family=AF_INET;
      address.sin_port=htons(15000);
      /* The htons() function converts the unsigned short integer hostshort from host byte order to network byte order */
      address.sin_addr.s_addr=INADDR_ANY;
      // any address can access the server
      printf("waiting for request...\n");
      s=socket(AF_INET,SOCK_STREAM,0);
      bind(s,(struct sockaddr*)&address,sizeof(address));
      listen(s,3);
      // listen - listen for connections on a socket
      source=accept(s,(struct sockaddr*)NULL,NULL);
      // accept a connection
      recv(source,fname,sizeof(fname),0); 
      // receive a message from the client
      printf("request for file %s\n", fname);
      file=open(fname,O_RDONLY);
      // open file in read-only mode
      if(file<0)
    		send(source,"file not found\n",20,0);
      else
    		while((n=read(file,buffer,sizeof(buffer)))>0) 
      // read the input being sent by the client
                	send(source,buffer,n,0);
      printf("request sent\n");
      close(file);
      return 0;
    }


## Output:
*Commands for execution:-*

* Open two terminals one for client and  server each.
* Change directory to the file location in both the terminals.
* Run gcc *server.c* -o serv.out in the server terminal.
* If no errors, run ./serv.out
* Run gcc *client.c* -o client.out in the client terminal.
* If no errors, run ./client.out

*Screenshots:-*

![ScreenShot of Output](9.png)
