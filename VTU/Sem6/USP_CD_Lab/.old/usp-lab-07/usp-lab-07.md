
## Aim:
<blockquote>
## Write a C/C++ program that creates a zombie and then calls system to execute the ps command to verify that the process is zombie.
</blockquote>
## Theory:
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

## Code:
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
## Output:
<ul>
 <li>Open a terminal</li>
 <li>Change directory to the file location in the terminal</li>
 <li>Complile the program by using the command cc usp-lab-07.c -o usp07.out</li>
 <li>Run usp07.out</li>
## Screenshots:
![not avialable] (usp-lab-07.png)
