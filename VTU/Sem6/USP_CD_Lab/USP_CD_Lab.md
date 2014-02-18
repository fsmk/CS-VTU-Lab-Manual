





##Aim:
###To Write a C/C++ POSIX compliant program to check the following limits: <br>(i) No. of clock ticks<br>(ii) Max. no. of child processes<br>(iii) Max. path length<br>(iv) Max. no. of characters in a file name<br>(v) Max. no. of open files/ process



##Theory:

###**sysconf** - *Get configuration information at runtime*

<blockquote>

SYNOPSIS
<blockquote>

       <pre><code>#include &lt;unistd.h&gt;
long sysconf(int name);</code></pre>
</blockquote>


DESCRIPTION
<blockquote>

<pre><p>POSIX  allows  an  application to test at compile or run time whether certain options are supported, or what the value is of certain configurable constants or limits.At compile time this is done by including &lt;unistd.h&gt; and/or &lt;limits.h&gt; and testing the value of certain macros.</p>
<p>At run time, one can ask for numerical values using the present function sysconf(). One can ask for numerical  values  that may  depend  on  the  file  system a file is in using the calls fpathconf(3) and pathconf(3). One can ask for string values using confstr(3). The values obtained from these functions are system configuration constants. They do not change during the lifetime of a process.</p></pre>


<blockquote>

<pre>clock ticks - _SC_CLK_TCK
              The number of clock ticks per second.  The corresponding variable is obsolete.  It  was  of  course  called  CLK_TCK.

CHILD_MAX - _SC_CHILD_MAX
              The max number of simultaneous processes per user ID.  Must not be less than _POSIX_CHILD_MAX (25).

OPEN_MAX - _SC_OPEN_MAX
              The maximum number of files that a process can have open at any time.  Must not be less than _POSIX_OPEN_MAX (20).</pre>


</blockquote>


</blockquote>

</blockquote>

###fpathconf, pathconf - *Get configuration values for files*

<blockquote>

SYNOPSIS

<blockquote>

<pre><code>#include &lt;unistd.h&gt;
long fpathconf(int fd, int name);
long pathconf(char *path, int name);</code></pre>

</blockquote>

DESCRIPTION
<blockquote>

<pre>fpathconf() gets a value for the configuration option name for the open file descriptor fd.

pathconf() gets a value for configuration option name for the filename path.

The corresponding macros defined in &lt;unistd.h&gt; are minimum values; if an application wants to take advantage of values which may change, a call to fpathconf() or pathconf() can be made, which may yield more liberal results.</pre>

<blockquote>

<pre>_PC_PATH_MAX
              returns the maximum length of a relative pathname when path or fd is the current working directory.  The  corresponding macro is _POSIX_PATH_MAX.

_PC_NAME_MAX
              returns the maximum length of a filename in the directory path or fd that the process is allowed to create.  The corresponding macro is _POSIX_NAME_MAX.</pre>

</blockquote>

</blockquote>
</blockquote>
##Code:

<pre><code>#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include "iostream"
#include &lt;unistd.h&gt;
using namespace std;
int main()
{
	cout&lt;&lt;"No of clock ticks:"&lt;&lt;sysconf(_SC_CLK_TCK)&lt;&lt;endl;
	cout&lt;&lt;"Maximum no of child processes:"&lt;&lt;sysconf(_SC_CHILD_MAX)&lt;&lt;endl;
	cout&lt;&lt;"Maximum path length:"&lt;&lt;pathconf("/",_PC_PATH_MAX)&lt;&lt;endl;
	cout&lt;&lt;"Maximum characters in a file name:"&lt;&lt;pathconf("/",_PC_NAME_MAX)&lt;&lt;endl;
	cout&lt;&lt;"Maximum no of open files:"&lt;&lt;sysconf(_SC_OPEN_MAX)&lt;&lt;endl;
	return 0;
}
</code></pre>

##Output:

*Commands for execution:-*
<ul>
    <li> Open a terminal.</li>
    <li> Change directory to the file location in the terminal.</li>
    <li> Run g++ usp01.c -o usp01.out in the terminal.</li>
    <li> If no errors, run ./usp01.out</li>
    

##Screenshots:

 ![not available](usp-lab-01.png "usp01 screenshot") 








##Aim :
###Write a C/C++ POSIX compliant program that prints the POSIX defined configuration options supported on any given system using feature test macros.

##Theory :

>POSIX allows an application to test at compile or run time whether certain options are supported, or what the value  is  of  certain configurable constants or limits.
<ul>
<li>_POSIX_SOURCE:If you define this macro, then the functionality from the POSIX.1 standard (IEEE Standard 1003.1) is available, as well as all of the ISO C facilities. </li>
<li> _POSIX_C_SOURCE:Define this macro to a positive integer to control which POSIX functionality is made available. The greater the value of this macro, the more functionality is made available. </li>
<li>_POSIX_JOB_CONTROL:If this symbol is defined, it indicates that the system supports job control. Otherwise, the implementation behaves as if all processes within a session belong to a single process group. See section Job Control. </li>
<li> _POSIX_SAVED_IDS:If this symbol is defined, it indicates that the system remembers the effective user and group IDs of a process before it executes an executable file with the set-user-ID or set-group-ID bits set, and that explicitly changing the effective user or group IDs back to these values is permitted. If this option is not defined, then if a nonprivileged process changes its effective user or group ID to the real user or group ID of the process, it can't change it back again.</li>
<li> _POSIX_CHOWN_RESTRICTED:If this option is in effect, the chown function is restricted so that the only changes permitted to nonprivileged processes is to change the group owner of a file to either be the effective group ID of the process, or one of its supplementary group IDs.</li>
<li>int _POSIX_NO_TRUNC:If this option is in effect, file name components longer than NAME_MAX generate an ENAMETOOLONG error. Otherwise, file name components that are too long are silently truncated.</li>
<li>_POSIX_VDISABLE:This option is only meaningful for files that are terminal devices. If it is enabled, then handling for special control characters can be disabled individually.</li>
</ul>

##Code:

<pre><code>
 #define _POSIX_SOURCE
 #define _POSIX_C_SOURCE 199309L
 #include "iostream"
 #include&lt;unistd.h&gt;
 using namespace std;
 int main()
{
        #ifdef _POSIX_JOB_CONTROL
                cout&lt;&lt;"System supports POSIX job control:"&lt;&lt;_POSIX_JOB_CONTROL&lt;&lt;endl;
        #else
                cout&lt;&lt;"System  does not support POSIX job control"&lt;&lt;endl;
        #endif
        #ifdef _POSIX_SAVED_IDS
                cout&lt;&lt;"System supports saved set UID and GID:"&lt;&lt;_POSIX_SAVED_IDS&lt;&lt;endl;
        #else
                cout&lt;&lt;"System does not support saved set GID and UID"&lt;&lt;endl;
        #endif
        #ifdef _POSIX_CHOWN_RESTRICTED
                cout&lt;&lt;"Chown restricted option is :"&lt;&lt;_POSIX_CHOWN_RESTRICTED&lt;&lt;endl;
        #else
                cout&lt;&lt;"Chown Restricted not defined"&lt;&lt;endl;
        #endif
        #ifdef _POSIX_NO_TRUNC
                cout&lt;&lt;"Truncation option is :"&lt;&lt;_POSIX_NO_TRUNC&lt;&lt;endl;
        #else
                cout&lt;&lt;"Truncation Option not defined"&lt;&lt;endl;
        #endif
        #ifdef _POSIX_VDISABLE
                cout&lt;&lt;"disable char for terminal files"&lt;&lt;_POSIX_VDISABLE&lt;&lt;endl;
        #else
                cout&lt;&lt;"char for terminal device files will not be diasbled"&lt;&lt;endl;
        #endif
        return 0;
}

</code></pre>

##Output:

<ul>

 <li>Open a terminal.</li>
 <li> Change directory to the file location in the terminals.</li>
 <li>Open a file using command followed by program_name </li>

<blockquote>

<pre>vi 02_posix_configuration.cpp</pre>

and then enter the source code and save it.

</blockquote>


<li>Then compile the program using</li> 

<blockquote>

<pre>g++ 02_posix_configuration.cpp</pre>

</blockquote>
 <li>If there are no errors after compilation execute the program using</li>

<blockquote> <pre>./a.out</pre> </blockquote> 
</ul>

#*Screenshots:-*
![Not Available](02_output.png)





## Aim:

### Consider the last 100 bytes as a region. Write a C/C++ program to check whether the region is locked or not. If the region is locked, print pid of the process which has locked. Ifthe region is not locked, lock the region with an exclusive lock, read the last 50 bytes and unlock the region.

## Theory:

File locking provides a very simple yet incredibly useful mechanism for coordinating file accesses.

flock - manage locks from shell scripts.

fcntl(used to manipulate the file descriptors) file commands can be used to support record locking, which permits multiple cooperating programs to prevent each other from simultaneously accessing parts of a file in error-prone ways.

fcntl() performs the operations on the open file descriptor fd.

F_GETLK, F_SETLK and F_SETLKW are used  to  acquire, release, and test for the existence of record locks.F_UNLK to remove the existing lock.

## Code:

<pre><code> #include &lt;stdio.h&gt;
 #include &lt;stdlib.h&gt;
 #include &lt;unistd.h&gt;
 #include &lt;fcntl.h&gt;
 #include &lt;errno.h&gt;
 int main(int argc,char *argv[])
 {
        int fd;
        char buffer[255];
        struct flock fvar;
        if(argc==1)
        {
                printf("usage:./a.out filename\n");
                return -1;
        }
        if((fd=open(argv[1],O_RDWR))==-1)
        {
                perror("open");
                exit(1);
        }
        fvar.l_type=F_WRLCK;
        fvar.l_whence=SEEK_END;
        fvar.l_start=SEEK_END-100;
        fvar.l_len=100;
        printf("press enter to set lock\n");
        getchar();
        printf("trying to get lock..\n");
        if((fcntl(fd,F_SETLK,&fvar))==-1)
        {     fcntl(fd,F_GETLK,&fvar);
              printf("\nFile already locked by process (pid):    \t%d\n",fvar.l_pid);        
              return -1;        
        }
        printf("locked\n");
        if((lseek(fd,SEEK_END-50,SEEK_END))==-1)
        {
                perror("lseek");
                exit(1);
        }
        if((read(fd,buffer,100))==-1)
        {
                perror("read");
                exit(1);
        }
        printf("data read from file..\n");
        puts(buffer);
        printf("press enter to release lock\n");
        getchar();
        fvar.l_type = F_UNLCK;
        fvar.l_whence = SEEK_SET;
        fvar.l_start = 0;
        fvar.l_len = 0;
        if((fcntl(fd,F_UNLCK,&fvar))==-1)
        {
                perror("fcntl");
                exit(0);
        }
        printf("Unlocked\n");
        close(fd);
        return 0;
 }</code></pre>

##Output:

*Commands for instructions:*
<ol>
	<li> Compile the program </li>
	<li> Run the program using ./a.out filename </li>
	<li>	Note: Do not stop execution </li>
	<li> Open another terminal </li>
	<li> Run the program using ./a.out filename </li>
		Note: Both the filename's should be same </li>
</ol>

##Screenshots:

![not available](out1.png "output1")

![not available](out2.png "output2")

![not available](out3.png "output3")






##Aim:
Write a C/C++ program which demonstrates interprocess communication between a reader process and a writer process. Use mkfifo, open, read, write and close APIs in your program.

##Algorithm:

##Theory:

<blockquote>

Pipes are the oldest form of UNIX System IPC and are provided by all UNIX systems. Pipes have two
limitations.

<blockquote>

<ol>
<li>
Historically, they have been half duplex (i.e., data flows in only one direction). Some systems
now provide full-duplex pipes, but for maximum portability, we should never assume that this is
the case.</li>
<li>
Pipes can be used only between processes that have a common ancestor. Normally, a pipe is
created by a process, that process calls fork, and the pipe is used between the parent and the
child.
</li>
</ol>

</blockquote>

A pipe is created by calling the pipe function.

<blockquote>

<pre>
#include &lt;unistd.h&gt;
int pipe(int filedes[2]);
</pre>

</blockquote>


Returns: 0 if OK, 1 on error


Figure "Pipe from parent to child"

![figure not available](pipe.png) 


For a pipe from the child to the parent, the parent closes fd[1], and the child closes fd[0]. When one end of a pipe is closed, the following two rules apply.
<ol>
<li>If we read from a pipe whose write end has been closed, read returns 0 to indicate an end of file
after all the data has been read. (Technically, we should say that this end of file is not
generated until there are no more writers for the pipe. It's possible to duplicate a pipe
descriptor so that multiple processes have the pipe open for writing. Normally, however, there is
a single reader and a single writer for a pipe. When we get to FIFOs in the next section, we'll
see that often there are multiple writers for a single FIFO.)</li>
<li>If we write to a pipe whose read end has been closed, the signal SIGPIPE is generated. If we
either ignore the signal or catch it and return from the signal handler, write returns 1 with
errno set to EPIPE.</li></ol>

When we're writing to a pipe (or FIFO), the constant PIPE_BUF specifies the kernel's pipe buffer size.
A write of PIPE_BUF bytes or less will not be interleaved with the writes from other processes to the
same pipe (or FIFO). But if multiple processes are writing to a pipe (or FIFO), and if we write more
than PIPE_BUF bytes, the data might be interleaved with the data from the other writers. We can
determine the value of PIPE_BUF by using pathconf or fpathconf.</pre>
</blockquote>

##Code:

<pre><code>#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;iostream&gt;
#include&lt;unistd.h&gt;
#include&lt;limits.h&gt;
#include&lt;fcntl.h&gt;
using namespace std;
#define BUFFER_SIZE PIPE_BUF
int main(int argc,char *argv[])
{
        int pipe_fd,res=0;
        char buffer[BUFFER_SIZE+1];
        if(argc!=2)
        {
                cout&lt;&lt;"usage:./a.out pipe_name\n";
                return -1;
        }
        cout&lt;&lt;"\nFD of fifo in read mode:"&lt;&lt;pipe_fd&lt;&lt;endl;
        if((pipe_fd=open(argv[1],O_RDONLY))!=-1)
        {
                res=read(pipe_fd,buffer,BUFFER_SIZE);
                cout&lt;&lt;"\n data read..\n";
                cout&lt;&lt;buffer;
                (void) close(pipe_fd);
        }
        else
        {
                perror("\nfifo read\n");
        }
        cout&lt;&lt;\nprocess  "&lt;&lt;getpid()&lt;&lt;" finished reading\n"&lt;&lt;endl;
        return 0;
}
</code></pre>

##Output:

*Commands for execution:-*
<ul>
    <li> Open a terminal.</li>
    <li> Change directory to the file location in the terminal.</li>
    <li> Run gcc "usp01.c -o usp04.out" in the terminal.</li>
    <li> If no errors, run "./usp04.out pipe1" </li>
</ul>

##Screenshots:

 ![not available](usp-lab-04.png "usp04 screenshot") 





##Aim :

###Write a C/C++ program thgat output the contents of its Environment list.


##Theory :

>Environment variables are a set of dynamic named values that can affect the way running processes will behave on a computer.

>They are part of the operating environment in which a process runs. For example, a running process can query the value of the TEMP environment variable to discover a suitable location to store temporary files, or the HOME or USERPROFILE variable to find the directory structure owned by the user running the process.


##Code :

<pre><code>
 #include&lt;stdio.h&gt;
 #include&lt;stdlib.h&gt;
 #include&lt;unistd.h&gt;
 int main(int argc,char *argv[])
 {
  int i;
  char **ptr;
  extern char **environ;
  for(ptr=environ; *ptr!=0;ptr++)
  printf("%s\n",*ptr);
  exit(0);
 }
</code></pre>



##Output:
<ul>
<li>Open a terminal.</li>
<li>Change directory to the file location in both the terminals.</li>
 <li>Open a file using command followed by program_name <pre>vi 5a_environlist.c </pre> and then enter the source code and save it.</li>
 <li>Then compile the program using <pre>gcc 5a_environlist.c</pre></li>
 <li>If there are no errors after compilation execute the program using <pre>./a.out </pre></li>
</ul>


##Screenshot :

![Not Available](out1.png)
![Not Available](out2.png)





##Aim : 

###Write a C / C++ program to emulate the unix ln command.


##Theory :

>Links are created by giving alternate names to the original file. The use of links allows a large file, such as a database or mailing list, to be shared by several users without making copies of that file.
>Not only do links save disk space, but changes made to one file are automatically reflected in all the linked files.
>The ln command links the file designated in the SourceFile parameter to the file designated by the TargetFile parameter or to the same file name in another directory specified by the TargetDirectory parameter. By default, the ln command creates hard links.

>To create a link to a file named chap1, type the following:

>><pre>ln -f chap1 intro</pre>

>This links chap1 to the new name, intro. When the -f flag is used, the file name intro is created if it does not already exist. If intro does exist, the file is replaced by a link to chap1. Both the chap1 and intro file names refer to the same file.

>To link a file named index to the same name in another directory named manual, type the following:

>><pre>ln index manual</pre>

>This links index to the new name, manual/index.
To link several files to names in another directory, type the following:

>><pre>ln chap2 jim/chap3 /home/manual </pre>

>This links chap2 to the new name /home/manual/chap2 and jim/chap3 to /home/manual/chap3.

##Code :

<pre><code>
 #include&lt;stdio.h&gt;
 #include&lt;unistd.h&gt;
 int main(int argc, char *argv[])
 {
  if(argc!=3)
   {
     printf("Usage: %s &lt;src_file&gt;&lt;dest_file&gt;\n",argv[0]);
     return 0;
   }
  if(link(argv[1],argv[2])==-1)
  {
   printf("Link Error\n");
   return 1;
  }
  return 0;
 }
</code></pre>


##Output :

<ul>
<li>Open a terminal.</li>
<li>Change directory to the file location in both the terminals.</li>
 <li>Open a file using command followed by program_name <pre>vi 5b_unix_ln-command.c </pre> and then enter the source code and save it.</li>
 <li>Then compile the program using <pre>g++ 5b_unix_ln-command.c</pre></li>
<li>Then create a dummy file with any of the name like abc.c .</li>
 <li>If there are no errors after compilation execute the program using <pre>./a.out abc.c out.c</pre>where abc.c is the source file and out.c is the new destination file to be given.</li>

<li>Then verify the creation of hard link using <pre>ls -l</pre>
by checking the inode number of both the input files.</li></ul>

##Screenshot :

![Not Available](output5b.png)






##Aim: 

###To Write a C/C++ program to illustrate the race condition.

##Algorithm:

##Theory:
<blockquote>

A race condition occurs when multiple processes are trying to do something with
shared data and the final outcome depends on the order in which the processes run. The fork
function is a lively breeding ground for race conditions, if any of the logic after the fork either
explicitly or implicitly depends on whether the parent or child runs first after the fork. In general, we
cannot predict which process runs first. Even if we knew which process would run first, what happens
after that process starts running depends on the system load and the kernel's scheduling algorithm.

</blockquote>

##Code:

<pre><code>#include&lt;stdlib.h&gt;
#include&lt;stdio.h&gt;
#include&lt;unistd.h&gt;
static void charatatime(char *);
int main()
{
        int pid;
        if((pid=fork())&lt;0)
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
</code></pre>

##Output:

*Commands for execution:-*
<ul>
    <li> Open a terminal.</li>
    <li> Change directory to the file location in the terminal.</li>
    <li> Run gcc usp06.c -o usp06.out in the terminal.</li>
    <li> If no errors, run ./usp06.out</li>
</ul>

##Screenshots:

 ![not available](usp-lab-06a.png "usp06 screenshot") 

 ![not available](usp-lab-06b.png "usp06 screenshot") 








##Aim:

###Write a C/C++ program that creates a zombie and then calls system to execute the ps command to verify that the process is zombie.


##Theory:
<blockquote>
In unix terminology, a process that has terminated, but whose parent has not yet waited for it, is called a zombie.<br><br>
*fork()*
<blockquote>
Syntax:
<code><pre>
<blockquote>
<blockquote>
 #include&lt;unistd.h&gt;
 pid_t fork(void);
</blockquote>
</blockquote>
</pre></code>

<blockquote>fork()  creates  a new process by duplicating the calling process.  The
new process, referred to as the child, is an  exact  duplicate of the calling  process,  referred  to as the parent.<br><br>
<em>Sleep()</em> : Delay for a specified amount of time.<br><br>
<em>System()</em>
<blockquote>
Syntax:
<code><pre>
<blockquote>
<blockquote>
 #include &lt;stdlib.h&gt;
 int system(const char *command);
</code></pre>
</blockquote>
</blockquote>
</blockquote>
<blockquote> system()  executes a command specified in command by calling /bin/sh -c command, and returns after the command has been completed.</blockquote>
</blockquote>
</blockquote>
</blockquote>

##Code:
<code><pre> #include&lt;stdio.h&gt; 
 #include&lt;unistd.h&gt;
 #include&lt;stdlib.h&gt;
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
     }</pre></code>
##Output:
<ul>
 <li>Open a terminal</li>
 <li>Change directory to the file location in the terminal</li>
 <li>Complile the program by using the command 
     <code><pre> cc usp-lab-07.c -o usp07.out</pre></code></li>
 <li>Run 
     <code><pre> usp07.out</pre></code></li></ul>

##Screenshots:
![not avialable](usp-lab-07.png)






##Aim:

###Write a C/C++ program to avoid zombie process by forking twice.

##Algorithm:

##Theory:

<blockquote>

<p>If we want to write a process so that it
forks a child but we don't want to wait for the child to complete and we don't want the child to
become a zombie until we terminate, the trick is to call fork twice.</p>

<p>We call sleep in the second child to ensure that the first child terminates before printing the parent process ID. After a fork, either the parent or the child can continue executing; we never know which will resume execution first. If we didn't put the second child to sleep, and if it resumed execution after the fork before its parent, the parent process ID that it printed would be that of its parent, not process ID 1.</p>

</blockquote>

##Code:

<pre><code>#include&lt;stdio.h&gt;
#include&lt;stdlib.h&gt;
#include&lt;unistd.h&gt;
int main()
{
        int pid;
        if((pid=fork())&lt;0)
                printf("fork error\n");
        else if(pid==0)
        {
                if((pid=fork())&lt;0)
                        printf("fork error\n");
                else if(pid&lt;0)
                        _exit(0);
                sleep(2);
                printf("second child,parent pid:%d\n",getppid());
                _exit(0);
        }
        _exit(0);
}
</code></pre>

##Output:

*Commands for execution:-*
<ul>
    <li> Open a terminal.</li>
    <li> Change directory to the file location in the terminal.</li>
    <li> Run "gcc usp06.c -o usp08.out" in the terminal.</li>
    <li> If no errors, run "./usp08.out"</li>
</ul>

##Screenshot:

![not available](usp-lab-08.png "usp08 screenshot") 





##Aim:

###Write a C/C++ program to implement the system function.

##Theory:
<blockquote>
  fork()  creates  a new process by duplicating the calling process.  The
new process, referred to as the child, is an  exact  duplicate  of  the calling  process,  referred  to as the parent.
</blockquote>
<blockquote>
system()  executes a command specified in command by calling   /bin/sh -c command, and returns after the command has been completed.
</blockquote>
<blockquote>
The  exec() family of functions replaces the current process image with
       a new process image. 
The execl() function is one among the exec() family of functions.
</blockquote>
<blockquote>The  waitpid()  system  call  suspends execution of the calling process until a child specified by pid argument has changed state.
</blockquote>
##Code:
<pre><code> #include&lt;stdio.h&gt;
 #include&lt;stdlib.h&gt;
 #include&lt;unistd.h&gt;
 #include&lt;errno.h&gt;
 #include&lt;sys/types.h&gt;
 #include&lt;sys/wait.h&gt;
void sys(const char *cmdstr)
{
        int pid;
        pid=fork();
        if(pid==0)
                execl("/bin/bash","bash","-c",cmdstr,NULL);
        else
        waitpid(pid,NULL,0);
}
int main(int argc,char *argv[])
{
        int i;
        for(i=1;i< argc;i++)
        {        sys(argv[i]);
                printf("\n");
        }
        _exit(0);
}
</code></pre>
##Output:
<ul>
<li>Open a terminal</li>
<li>Change the present working directory to the location where the program exists using the cd command in the terminal</li>
<li>Complile the program using the command cc <em>&lt;program name&gt;</em> -o usp09.out</li>
<li>run the program using ./usp09.out</li>
Note:To run use ./a.out command1 command2 ,..., commandn where each command is a shell command. Example : ./a.out ps date who 
###Screenshot:
![Not available](output.png)





##Aim :
###Write a C/C++ program to set up a real-time clock interval timer using the alarm API.

##Theory :
<ul>
<li>First, every signal has a name. These names all begin with the three characters SIG .For example,SIGABRT is the abort signal that is generated when a process calls the abort function.</li>
<li>SIGALRM is the alarm signal that is generated when the timer set by the alarm function goes off.</li>
<li>Use the alarm API for generating a signal after certain time interval as specified by the user.</li>
</ul>
##Code :
<pre><code>
 #include&lt;stdio.h&gt;
 #include&lt;stdlib.h&gt;
 #include&lt;unistd.h&gt;
 #include&lt;signal.h&gt;
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

##Output :
<ol>
<li>Open a terminal.</li>
<li>Change directory to the file location in both the terminals.</li>
<li>Open a file using command followed by program_name <pre>vi 10_alarm_signal_handler.cpp </pre> and then enter the source code and save it.</li>
<li>Then compile the program using <pre>g++ 10_alarm_signal_handler.cpp</pre></li>
 <li>If there are no errors after compilation execute the program using <pre>./a.out</pre> </li>
</ol>

##Screenshot:-
![Not Available](Output.png)





##Aim:
### Write a C program for a syntax directed definition of a "if E then S1" and "if E then S1 else S2"

###Description:

>  A SYNTAX-DIRECTED DEFINITION is a context-free grammar in which each grammar symbol X is associated with two finite sets of values: the synthesized attributes of X and the inherited attributes of X, each production A -> alpha is associated with a finite set of expressions of the form

				b  : =  f (c1,..., ck) 	

> called semantic rules where f is a function and either b is a synthesized attribute of A and the values c1,..., ck are attributes of the grammar symbols of alpha or A, or b is an inherited attribute of a grammar symbol of alpha and the values c1,..., ck are attributes of the grammar symbols of alpha or A. Each terminal symbol has no inherited attributes.

> It is usual to denote the attributes of a grammar symbol in the form X.name where name is an meaningful name for the attribute.

###Algorithm:
1. Start
2. Output the if, if-else statement to the user for reference.
3. Manipulate the input string such that the if and if-else conditions are stored separately.
4. Generate the format of the if, if-else statements and output the same.
5. End.

###Code:

	#include<stdio.h>
	#include<stdlib.h>	
	#include<string.h>
	char input[60],stmt[3][60];
	int len,cur,i,j;
	void gen()/*used for generation of if, if-else format statements*/
	{
        		int l1=101,l2=102,l3=103;
        		printf("if %s goto %d\n",stmt[0],l1);
        		printf("goto %d\n",l2);
        		printf("%d:%s\n",l1,stmt[1]);
        		if(cur<3)/*if statement*/
                		printf("%d:STOP\n",l2);
        		else/*if-else statement*/
        		{
                		printf("goto %d\n",l3);
                		printf("%d:%s\n",l2,stmt[2]);
                		printf("%d:STOP\n",l3);
        		}
	}
	int main()
	{
        		printf("Format of if stmt\nExample\n");
        		printf("if(a<b)then(s=a);\n");
        		printf("if(a<b)then(s=a)else(s=b);\n");
        		printf("enter stmt:");
        		gets(input);
        		len=strlen(input);
        		int index=0;
        		for(i=0;i<len&&input[i]!=';';i++)
                	if(input[i]=='(')
                	{
                        index=0;
                        for(j=i;input[j-1]!=')';j++)
                                stmt[cur][index++]=input[j];
                        	     cur++;
                        	     i=j;
                	}
       			gen();
        		return 0;
	}

###Output:
*Commands for execution:-*

* Open a terminal
* Change the directory to the file location
* Use gcc *filename.c* for compilation
* Run ./a.out for execution

###Screenshots:-

![ScreenShot of Output](sdd_cd.png)






##Aim:
### Write a yacc program that accepts a regular expression as input and produce its parse tree as output.

###Description:

> Yacc- Yet another C Compiler defines what it is all by itself.  Computer program input generally has some structure; in fact, every computer program that does input can be thought of as defining an ``input language'' which it accepts. An input language may be as complex as a programming language, or as simple as a sequence of numbers. Unfortunately, usual input facilities are limited, difficult to use, and often are lax about checking their inputs for validity.

> Yacc provides a general tool for describing the input to a computer program. The Yacc user specifies the structures of his input, together with code to be invoked as each such structure is recognized. Yacc turns such a specification into a subroutine that han- dles the input process; frequently, it is convenient and appropriate to have most of the flow of control in the user's application handled by this subroutine. 

> Every Yacc specification file consists of three sections: the declarations, (grammar) rules, and programs. The sections are separated by double percent ``%%'' marks. (The percent % is generally used in Yacc specifications as an escape character.)
In other words, a full specification file looks like

        declarations
        %%
        rules
        %%
        programs

> The declaration section may be empty. Moreover, if the programs section is omitted, the second %% mark may be omitted also;thus,the smallest legal Yacc specification is

        %%
        rules
> The following command:

			yacc grammar.y

> draws yacc rules from the grammar.y file, and places the output in 	  y.tab.c.

> The following command:
	yacc  -d grammar.y
  functions the same as example 1, but it also produces the y.tab.h file            which would contain C-style #define statements for each of the tokens 
  defined in the grammar.y file.

###Algorithm:
1. Start
2. Accept an expression from the user.
3. Check for the structure that satisfies the conditions of a regular expression.
4. Print the parsed tree as output as when the conditions are satisfied.
5. End

###Code:
	%{/*declaration part*/
 	#include<stdio.h>
	#include<ctype.h>
	#include<stdlib.h>
	#include<string.h>
	#define MAX 100 /*to store productions*/
	int getREindex ( const char* );
	signed char productions[MAX][MAX];
	int count = 0 , i , j;
	char temp[200] , temp2[200];
	%}
	%token ALPHABET
	%left '|'
	%left '.'
	%nonassoc '*' '+'
	%%/*rules section*/
	S : re '\n' { 
	printf ( "This is the rightmost derivation--\n" );
	for ( i = count - 1 ; i >= 0 ; --i ) {
		if ( i == count - 1 ) {
			printf ( "\nre => " );
			strcpy ( temp , productions[i] );
			printf ( "%s" , productions[i] );
		}
		else {
			printf ( "\n => " );
			j = getREindex ( temp );	
			temp[j] = '\0';
			sprintf ( temp2 , "%s%s%s" , temp , productions[i] , (temp + j + 2) );
			printf ( "%s" , temp2 );
			strcpy ( temp , temp2 );
		}
	}
	printf ( "\n" );
	exit ( 0 ); 
	}
	re : ALPHABET { 
	temp[0] = yylval; temp[1] = '\0';
	strcpy ( productions[count++] , temp );/*copy the input to the prodcution array*/
	}/*only conditions defined here will be valid, this is the structure*/
	| '(' re ')' /*adds the (expression) to the production array*/
	{ strcpy ( productions[count++] , "(re)" ); }
	| re '*'     
	{ strcpy ( productions[count++] , "re*" ); }
	| re '+' /*adds expression+ type to the production array*/
	{ strcpy ( productions[count++] , "re+" ); }
	| re '|' re /*adds the expression|expression to the production array*/
	{strcpy ( productions[count++] , "re | re" );}
	| re '.' re/*adds the expression.expression to the production array*/ 
	{strcpy ( productions[count++] , "re . re" );}
	;
	%%
	int main ( int argc , char **argv ) 
	{
	/* 
	Parse and output the rightmost derivation,
	from which we can get the parse tree 
	*/
		yyparse();/*calls the parser*/
		return 0;
	}

	yylex() /*calls lex and takes each character as input and feeds ALPHABET to check for the structure*/
	{
		signed char ch = getchar();	
		yylval = ch;
		if ( isalpha ( ch ) )
			return ALPHABET;
		return ch;
	}

	yyerror() /*Function to alert user of invalid regular expressions*/
	{
		fprintf(stderr , "Invalid Regular Expression!!\n");
		exit ( 1 );
	}

	int getREindex ( const char *str ) 
	{ 
		int i = strlen ( str ) - 1;
		for ( ; i >= 0 ; --i ) {
			if ( str[i] == 'e' && str[i-1] == 'r' )
			return i-1;
		}
	}

###Output:-
*Commands for execution*

* Open a terminal
* Change your directory to the location of the file
* Run, yacc -d *filename.y* 
* Run, cc y.tab.c y.tab.h
* An output file a.out is created. 
* Run, ./a.out to execute the program.

###Screenshot:

![ScreenShot of Output](yacc_regular.png)