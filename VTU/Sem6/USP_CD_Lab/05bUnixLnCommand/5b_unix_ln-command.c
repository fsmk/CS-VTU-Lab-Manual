/*5b) Write a C / C++ program to emulate the unix ln command*/
#include<stdio.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
if(argc!=3)
{
printf("Usage: %s <src_file><dest_file>\n",argv[0]);
return 0;
}
if(link(argv[1],argv[2])==-1)
{
printf("Link Error\n");
return 1;
}
printf("Files Linked\n");
printf("Inode number of linked files\n");
//display the inode linked files
char str[100];
sprintf(str,"ls -i %s %s\n",argv[1],argv[2]);
system(str);
return 0;
}
