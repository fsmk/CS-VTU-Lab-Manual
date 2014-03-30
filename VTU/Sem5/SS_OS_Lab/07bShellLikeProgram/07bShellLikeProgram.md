###Aim:
C program that creates a child process to read commands from the standard input and execute them (a minimal implementation of a shell-like program). You can assume that no arguments will be passed to the commands to be executed.

####Description:
 <p>fork():it is a system call which forks a new child of a processs
</p>system ():it is a system call which takes a command as an argument and invokes the operating system to execute it.</p>

####Code:
<pre>#include&lt;stdio.h>
`#`include&lt;stdlib.h>
`#`include&lt;string.h>
`#`include&lt;unistd.h></pre>
<pre>int main()
{
int pid,n,i;
char cmd[14];
system("clear");
printf("enter the no. of commands:\n");
scanf("%d",&n);
pid=fork();
if(!pid)
{
for(i=0;i&lt;n;i++)
{
printf("\nEnter command:\n");
scanf("%s",cmd);
system(cmd);
}
</pre>
####Output:

/a.out
<pre>enter the no. of commands:
2

Enter command:
ls
<pre>12.html  3.c~		    db4doc.odt	examples.desktop       Templates
1.c	 5a.html	    Desktop	Firefox_wallpaper.png  Thumbs.db
1.c~	 ada final	    doc		Mock-Docathon	       Videos
1.C	 a.out		    Documents	Music		       worshop
1.cpp~	 CS-VTU-Lab-Manual  Downloads	Public</pre>

Enter command:
date
Fri Jan 24 17:56:06 IST 2014
</pre>