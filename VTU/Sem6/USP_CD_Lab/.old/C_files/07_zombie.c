##Aim:

/* Write a C/C++ program that creates a zombie and then calls system to execute the ps
    command to verify that the process is zombie. */
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
        int pid;
        if((pid=fork())<0)
                printf("fork error\n");
        else if(pid==0)
                _exit(0);
        sleep(2);
        system( "ps -o pid,ppid,state,tty,command");
        _exit(0);
}
