/*Write a C/C++ program to set up a real-time clock interval timer using the alarm API.*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#define INTERVAL 5
void callme(int sig_no)
{
        alarm(INTERVAL);
        printf("Hello!!\n");
}
int main()
{
        struct sigaction action;
        action.sa_handler=(void(*)(int))callme;
        sigaction(SIGALRM,&action,0);
        alarm(2);
        sleep(5);
        return 0;
}
