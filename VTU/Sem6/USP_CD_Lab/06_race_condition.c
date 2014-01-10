/* Write a C/C++ program to illustrate the race condition */
/* Note: You may have to run (./a.out) many times before you can get the output
         which shows race condition */
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
static void charatatime(char *);
int main()
{
        int pid;
        if((pid=fork())<0)
                printf("fork error\n");
        else if(pid==0)
                charatatime("output from child\n");
        else
                charatatime("output from parent\n");
        _exit(0);
}
static void charatatime(char *str)
{
        char *ptr;
        int c;
        setbuf(stdout,NULL);
        for(ptr=str;(c=*ptr++)!=0;)
                putc(c,stdout);
}
