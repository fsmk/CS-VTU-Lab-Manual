/* Write a C/C++ program which demonstrates interprocess communication between a 
 reader process and a writer process. Use mkfifo, open, read, write and close APIs in your program. */

/* Executing Instructions 
	1) Compile the writer using the following command
		g++ 4_ipc_fifo_writer.cpp -o writer
				OR
		gcc 4_ipc_fifo_writer.cpp -o writer
	2) Compile the reader using the following command
		g++ 4_ipc_fifo_reader.cpp -o reader
				OR
		gcc 4_ipc_fifo_reader.cpp -o reader
	3) Exectue the writer first
		./writer fifofile
	4) Open another terminal and execute reader
		./reader fifofile
	5) Switch back to the terminal running writer
	6) Type your message and hit enter
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>
using namespace std;
#define BUFFER_SIZE PIPE_BUF
int main(int argc,char *argv[])
{
        int pipe_fd,res;
        char buffer[BUFFER_SIZE+1];
        if(argc!=2)
        {
                cout<<"usage:./a.out pipe_name\n";
                return 1;
        }
        if(access(argv[1],F_OK)==-1)
        {
                res=mkfifo(argv[1],0777);
                if(res!=0)
                {
                        perror("\nmkfifo error\n");
                        exit(0);
                }
        }
        cout<<"Process "<<getpid()<<"opening fifo in write mode"<<endl;
        pipe_fd=open(argv[1],O_WRONLY);
        cout<<"FD of fifo in write mode:"<<pipe_fd<<endl;
        if(pipe_fd!=-1)
        {
                cout<<"enter data\n";
                gets(buffer);
                res=write(pipe_fd,buffer,BUFFER_SIZE);
                if(res==-1)
                {
                        perror("write error\n");
                        exit(0);
                }
                close(pipe_fd);
        }
        else
                perror("fifo write");
        cout<<"\nprocess "<<getpid()<<" finished writing\n"<<endl;
        unlink(argv[1]);
        return 0;
}
