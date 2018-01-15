###Aim:
C program that creates a child process to read commands from the standard input and execute them (a minimal implementation of a shell-like program). You can assume that no arguments will be passed to the commands to be executed.

####Description:
 <p>fork():it is a system call which forks a new child of a processs
</p>system ():it is a system call which takes a command as an argument and invokes the operating system to execute it.</p>

####Code:
<pre>
#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;sys/types.h&gt;
int main()
  {
  char cmd[20];
  system("clear");
  do{
    printf("[PROMPT]$\n");
    gets(cmd);
    system(cmd);
    }while(strcmp(cmd,"exit"));
}
</pre>
####Output:

/a.out

[PROMPT]$
echo "Hello world"
<pre>Hello world!</pre>

[PROMPT]$
date
<pre>Wed Oct 29 21:40:20 IST 2014</pre>
[PROMPT]$
exit
<pre>

</pre>
