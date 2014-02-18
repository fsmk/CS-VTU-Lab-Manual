





#AIM:
 Program to count the number of characters, words, spaces and lines 
in a given input file.

##DESCRIPTION:
We have the command 'wc' in UNIX which gives us all the 
number of characters,number of words,number of lines.We are expected to develop a similar utility which does the same using flex.

##FLEX:  flex - the fast lexical analyser generator.




##CODE:

<pre>%{
#include<stdio.h>
int char_count=0,word_count=0,line_count=0,space_count=0;
%}
%%
[^ \t\n]+ {word_count++;char_count+=yyleng;}
\n {line_count++;char_count++;}
" " {space_count++;char_count++;}
. {char_count++;}
%%
int main(int argc,char *argv[])
{
	if(argc>1)
	{
		FILE *file=fopen(argv[1],"r");
		if(!file)
		{
			printf("Error opening %s\n",argv[1]);
			exit(1);
		}
		yyin=file;
	}
	yylex();
	printf("line count is %d\n",line_count);
	printf("word count is %d\n",word_count);
	printf("space count is %d\n",space_count);
	printf("character count is %d\n",char_count);
	return 0;
}</pre>

##COMPILE:
<pre>lex 1a.l
gcc lex.yy.c -ll
./a.out 1a.l</pre>

##OUTPUT:
<pre>line count is 29
word count is 55
space count is 26
character count is 588</pre>






#AIM:
Program to count the numbers of comment lines in a given C program. 
Also eliminate them and copy the resulting program into separate file.
##Description:
The central idea of the program is to develop a code which can count all the single line comments and the multiple line comments and give the total count.Also we should be able to generate a copy of the orginal C file without the comment lines.

###CODE:

	%{
	#include<stdio.h>
	int c=0;
	%}
	%x COMMENT
    	%%
    	"//".* {c++;}
    	"/*".* {BEGIN COMMENT;}
    	<COMMENT>. ;
    	<COMMENT>\n ;
    	<COMMENT>"*/" {BEGIN 0;c++;}
    	%%
	int main(int argc,char **argv)
	{
		if(argc!=3)
		{
			printf("No file\n");
			return 0;
		}
		else
		{
			yyin=fopen(argv[1],"r");
			yyout=fopen(argv[2],"w");
			yylex();
			printf("Number of comments is %d\n",c);
		}
	}

###OUTPUT:
<pre>
./a.out 11.c r.txt
Number of comments is 3
</pre>

###cat r.txt

	#include<stdio.h>
	#include<omp.h>
	int main()
	{
		int n,a[100],i;
		#pragma omp single
		for(i=2;i<n;i++)
		{
			a[i]=a[i-2]+a[i-1];
			printf("id of thread involved in the computation of fib no %d is=%d\n",i+1,omp_get_thread_num());
		}
		#pragma omp barrier
		#pragma omp single
		{
			printf("the elements of fib series are\n");
			for(i=0;i<n;i++)
			printf("%d,id of the thread displaying this no is =  %d\n",a[i],omp_get_thread_num());
		}
   	}

   	return 0;
	}








##AIM:
Program to recognize a valid arithmetic expression and to recognize 
the identifiers and operators present. Print them separately.

##DESCRIPTION:
Following the syntax for defining an identifier we generate arithmetic expressions using basic arithmetic operators such as +, -, * & /.

##FLEX:  flex - the fast lexical analyser generator.

##CODE:
<pre>%{
`#`include<stdio.h>
int a[4]={0,0,0,0};
int valid=1,i;
int nop=0;
%}
%x OPER
%%
[a-zA-Z0-9]+ {BEGIN OPER;nop++;}
<OPER>"+" {if(valid) {valid=0;i=0;}else ext();}
<OPER>"-" {if(valid) {valid=0;i=1;}else ext();}
<OPER>"*" {if(valid) {valid=0;i=2;}else ext();}
<OPER>"/" {if(valid) {valid=0;i=3;}else ext();}
<OPER>[a-zA-Z0-9]+ {nop++;if(valid==0){valid=1;a[i]++;}else ext();}
<OPER>. {if(valid){valid=0;ext();}else return 0;}
<OPER>"\n" {if(valid==0){ext();}else return 0;}
. ext();
\n ext();
%%
int ext()
{
	printf("Invalid expression\n");
	exit(0);
}
int main()
{
	printf("Enter expression\n");
	yylex();
	printf("Expression is valid\n");
	printf("No. of '+' is:%d\n",a[0]);
	printf("No. of '-' is:%d\n",a[1]);
	printf("No. of '*' is:%d\n",a[2]);
	printf("No. of '/' is:%d\n",a[3]);
	printf("No. of operands is:%d\n",nop);
	return 0;
}</pre>		

##COMPILE:
<pre>lex 2a.l
gcc lex.yy.c -ll
./a.out </pre>

##OUTPUT:
<pre>Enter expression
2+4*6+2/5-3*6     
Expression is valid
No. of '+' is:2
No. of '-' is:1
No. of '*' is:2
No. of '/' is:1
No. of operands is:7
Enter expression
2-3*
Invalid expression</pre>






#AIM:
Program to recognize whether a given sentence is simple or compound.
##DESCRIPTION:
The user is expected to develop a code which recognizes a sentence as either simple or compound.The design considers that we use and, or, but & between.The user can specify more rules as per his/her choice.

##CODE:
<pre>%{
`#`include&lt;stdio.h>
int valid=1;
%}
id [a-zA-Z0-9]*
%%
{id}" and "{id} {valid=0;}
{id}" or "{id} {valid=0;}
{id}" but "{id} {valid=0;}
{id}" between "{id} {valid=0;}
. ;
\n {return 0;}
%%
main()
{
	printf("Enter a sentence\n");
	yylex();
	if(valid==1)
	printf("Its a simple sentence\n");
	else
	printf("Its a compound sentence\n");
}</pre> 
##OUTPUT:
<pre>Enter a sentence
hi and bye
Its a compound sentence</pre>

<pre>Enter a sentence
anand
Its a simple sentence</pre>









#AIM:
Program to recognize and count the number of identifiers in a given
input file.

##DESCRIPTION:
Given any program containing few datatypes defined we should be able to count the total number of identifiers, number of identifers of the same datatype and also display what they are.

###FLEX:  flex - the fast lexical analyser generator.

###CODE:
<pre>%{
`#`include&lt;stdio.h>
int count=0,floatcount=0,charcount=0,doublecount=0;
%}</pre>
<pre>ID [a-zA-Z][a-zA-Z0-9]*
I "int"
F "float"
C "char"
D "double"
%s DEFN
%s DEFN2
%s DEFN3
%s DEFN4
%%
[\t] ;
{I} {BEGIN DEFN;}
&lt;DEFN>{ID}"," {intcount++;printf("%s\n",yytext);}
&lt;DEFN>{ID}";" {intcount++;BEGIN 0;printf("%s\n",yytext);}
{F} {BEGIN DEFN2;}
&lt;DEFN2>{ID}"," {floatcount++;printf("%s\n",yytext);}
&lt;DEFN2>{ID}";" {floatcount++;BEGIN 0;printf("%s\n",yytext);}
{C} {BEGIN DEFN3;}
&lt;DEFN3>{ID}"," {charcount++;printf("%s\n",yytext);}
&lt;DEFN3>{ID}";" {charcount++;BEGIN 0;printf("%s\n",yytext);}
{D} {BEGIN DEFN;}
&lt;DEFN4>{ID}"," {doublecount++;printf("%s\n",yytext);}
&lt;DEFN4>{ID}";" {doublecount++;BEGIN 0;printf("%s\n",yytext);}
. ;
\n ;
%%
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Error\n");
		return 0;
	}
	yyin=fopen(argv[1],"r");
	printf("The identifiers are:\n");
	yylex();
	printf("the no. of int identifiers are %d\n",intcount);	
	printf("the no. of float identifiers are %d\n",floatcount);
	printf("the no. of char identifiers are %d\n",charcount);
	printf("the no. of double identifiers are %d\n",doublecount);
	return 0;
}	
</pre>		
###COMPILE:
<pre>lex 3.l
gcc lex.yy.c -ll
./a.out 10.c
</pre>
###OUTPUT:
<pre>The identifiers are:
name;
at;
burst;
wait;
tat;
remaining;
flag;
n,
n1;
tq,
t,
i,
temp,
ch;
break;
i;
n;
i,
j,
no,
k,
min;
tbt;
i,
n;
n;
n;
name,
at,
burst,
wait,
n;
n;
algorithm,
stwt,
sttat,
sawt,
n1;
n1;
tq;
remaining;
remaining;
temp;
n1;
n1;
n1;
n1;
burst,
wait,
algorithm,
rawt,
the no. of int identifiers are 46
the no. of float identifiers are 4
the no. of char identifiers are 1
the no. of double identifiers are 0
</pre>






##Program : 4a.y (Yacc Specification)
## AIM:
Program to recognize a valid arithmetic expression that uses operators +, -, * and /.

##Description:
This program checks if the given arithmetic expression is valid or not.An arithmetic expression contains operators like +,-,* and /. For example : 12+23-8 or (a+b)*c etc are valid expressions.
Example for invalid expressions are a+* or (23*3)/(78 etc.

##Code:
    %{
    #include<stdio.h>
    #include<stdlib.h>
    %}
    %token NUMBER ID
    %left '+''-'
    %left '*''/'
    %%
    exp:exp'+'exp
    |exp'-'exp
    |exp'*'exp
    |exp'/'exp
    |NUMBER
    |ID;
    %%
    yyerror()
    {
  	printf("Invalid expression\n");
 	exit(0);
     }
    int main()
    {
 	printf("Enter the expression\n");
 	yyparse();
 	printf("Valid expression\n");
 	return 0;
    }




##Program :4a.l (Lex Specification)

##Code:
    %{
    #include"y.tab.h"
    %}
    %%
    [0-9]+                  return NUMBER;
    [a-zA-Z][a-zA-Z0-9]*    return ID;
    .                       return yytext[0];
    \n                      return 0;
    %%



##Output:

1.Enter the expression

a+b

Valid expression


2.Enter the expression

a+

Invalid expression

















































































		





##Program : 4b.y
##Aim: 
Program to recognize a valid variable, which starts with a letter, followed by any number of letters or digits.

##Description:
This program checks if the given variable is valid or invalid. A variable should start with a letter followed any no of letters or digits.For example a123 or aa23 or b3455 etc are valid variables.Example for invalid expression 12aa or 1cc etc.

##Code:

    %{
    #include<stdio.h>
    #include<stdlib.h>
    %}
    %token DIGIT ALPHA
    %%
    variable:ALPHA
            |variable ALPHA
            | variable DIGIT 
            ;
    %%
    yyerror()
    {
 	printf("Invalid expression\n");
 	exit(0);
    }
    int main()
    {
 	printf("Enter the variable\n");
 	yyparse();
 	printf("Valid variable\n");
 	return 0;
    }		
        
##Program : 4b.l (Lex Specification)

##Code:
    %{
    #include"y.tab.h"
    %}
    %%
    [0-9]                  return DIGIT;
    [a-zA-Z]               return ALPHA;
    .                      return yytext[0];
    \n                     return 0;
    %%


##Output:
1.Enter the variable

a345

Valid variable

2.Enter the variable

34aaa

Invalid expression






##PROGRAM: 5a.y(YACC specification)
##AIM:
 Program to evaluate an arithmetic expression involving operators +, -, * and /.
##DESCRIPTION:
This program is to solve or to evaluate the given arithmatic expression using the operators +,-,* and /. 

example: 3+5=8.


##ALGORITHM:


##CODE:
%{

    #include<stdio.h>

    #include<stdlib.h>
%}

%token NUMBER

%left '+''-'

%left '*''/'

%%

exp:expr {printf("Result is %d\n",$1);return 0;}

expr:expr'+'expr {$$=$1+$3;}

    |expr'-'expr {$$=$1-$3;}

    |expr'*'expr {$$=$1*$3;}

    |expr'/'expr 
     {
     	if($3==0)
     		yyerror("divide by zero!!!");
     	else
     		{$$=$1/$3;}
     }
    |'('expr')' {$$=$2;}
    |NUMBER
    ;
%%

yyerror()

{

	printf("Invalid expression\n");
	exit(0);
}

main()

{

	  printf("Enter the expression\n");
	  yyparse();
	  printf("Valid expression\n")
}		





##PROGRAM: 5a.l(LEX specification)


##CODE:
%{

   #include"y.tab.h"

   extern int yylval;

%}

%%

[0-9]+                   {yylval=atoi(yytext);return NUMBER;}

.                        return yytext[0];

\n                       return 0;

%%

##OUTPUT:

 1.) Enter the expression

   2+6

   Result is 8

   Valid expression

2.) Enter the expression

    2*

    Invalid expression










##AIM :Program to recognize strings ‘aaab’, ‘abbb’, ‘ab’ and ‘a’ using the grammar (anbn, n>= 0).


###DESCRIPTION : 
<p>The program has three parts defination section,rule section,subroutine section. The program accepts equal number of a's and b's as valid inputs. The grammar is S->A S B, A->a ,b->b . </p>

###ALGORITHM :


###CODE :

<pre>%{
#include&lt;stdio.h>
#include&lt;stdlib.h>
%}
%token A B;
%%
S:A S B
 |
 ;
%% 
yyerror()
{
	printf("Invalid\n");
	exit(0);
}
main()
{
	printf("enter a string of a's and b's\n");
	yyparse();
	printf("valid grammar\n");
}</pre>



###LEX SPECIFICATION

<pre>
%{
#include"y.tab.h"
%}
%%
a return A;
b return B;
. return yytext[0];
\n return 0;
%%</pre>

###OUTPUT :

<pre>enter a string of a's and b's
aaab
Invalid grammar

enter a string of a's and b's
abbb
Invalid grammar

enter a string of a's and b's
ab
valid grammar

enter a string of a's and b's
a
Invalid grammar</pre>









##AIM:Program to recognize the grammar (anb, n>= 10).

###DESCRIPTION:
<p>The program has three parts:definition section,rule section,subroutine section. The program uses a variable count to keep track of the number of A's in the input string and B is accepted only once according to the rule described.So count must be more than 9.</p>

###ALGORITHM:

###CODE:

<pre>%{
#include&lt;stdio.h>
#include&lt;stdlib.h>
int count=0;
%}
% token A B;
%%
S: X B
X: X A {count++;}
 |
 ;
%% 
yyerror()
{
	printf("Invalid\n");
	exit(0);
}
main()
{
	printf("enter a string of a's and b's\n");
	yyparse();
	if(count>=10)
	printf("valid grammar\n");
	else
	printf("Invalid grammar\n");
}</pre>

###LEX SPECIFICATION:

<pre>%{
#include"y.tab.h"
%}
%%
a return A;
b return B;
. return yytext[0];
\n return 0;
%%</pre>

###OUTPUT:
<p> 1) enter a string of a's and b's</p>
<p>aaaaaaaaaab</p>
<p>valid grammar</p>

<p>2) enter a string of a's and b's</p>
<p>aaaaaab</p>
<p>invalid grammar</p>






###Aim:
Non-recursive shell script that accepts any number of arguments and prints them in the Reverse order, ( For example, if the script is named rargs, then executing rargs A B C should produce C B A on the standard output).

####Description:
<p> $#: Contains the total number of input arguments.</p>
<p>$@:Contains all the input arguments

<pre>#! /bin/bash
if [ $# -eq 0 ]
then
	echo "no arguments"
	exit
fi
echo "the total number of arguments are $#"
echo "the arguments are $*"
for i in $@
do 
	rev=$i" "$rev
done
echo "$rev" </pre>

####Output:
<pre>./7a.sh 2 7 5
5 7 2






###Aim:
C program that creates a child process to read commands from the standard input and execute them (a minimal implementation of a shell–like program). You can assume that no arguments will be passed to the commands to be executed.

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





###Aim:
Shell script that accepts two file names as arguments, checks if the permissions for these files are identical and if the permissions are identical, outputs the common permissions, otherwise outputs each file name followed by its permissions.

####Descrtiption:
<p>-ne:not equal to.</p>
<p>cut -c:command to cut the specified columns from the given input.</p>
<p> $#: Contains the total number of input arguments.</p>

####Code:
<pre>#!/bin/sh

if [ $# -ne 2 ]
then
echo " please enter 2 arguments"
exit
fi
perm1=`ls -l $1|cut -c 1-10`
perm2=`ls -l $2|cut -c 1-10`
if [ $perm1 = $perm2 ]
then
echo "Permissions are same for both files"
echo "permissions are: $perm1"
exit
fi
str1=`ls -l $1|cut -c 2-4`
str2=`ls -l $2|cut -c 2-4`
if [ $str1 = $str2 ]
then
echo "Owner permissions are same: $str1 "
else
echo "Owner permissions are different"
echo " Permissions for file $1 : $str1 "
echo " Permissions for file $2 : $str2 "
fi 
str3=`ls -l $1|cut -c 5-7`
str4=`ls -l $2|cut -c 5-7`
if [ $str3 = $str4 ]
then
echo "Group permissions are same: $str3 "
else
echo "Group permissions are different"
echo " Permissions for file $1 : $str3 "
echo " Permissions for file $2 : $str4 "
fi 
str5=`ls -l $1|cut -c 8-10`
str6=`ls -l $2|cut -c 8-10`
if [ $str5 = $str6 ]
then
echo "Other's permissions are same: $str5 "
else
echo "Other's permissions are different"
echo " Permissions for file $1 : $str5 "
echo " Permissions for file $2 : $str6 "
fi 
</pre> 
###Compile: ./1.sh 1.c 1.sh


###Output:
<pre>Owner permissions are different
 Permissions for file 1.c : rw- 
 Permissions for file 1.sh : rwx 
Group permissions are different
 Permissions for file 1.c : rw- 
 Permissions for file 1.sh : r-x 
Other's permissions are different
 Permissions for file 1.c : r-- 
 Permissions for file 1.sh : r-x
</pre>

###Compile: ./1.sh a.out 1.sh
###Output:
<pre>Owner permissions are same: rwx 
Group permissions are different
 Permissions for file a.out : rwx 
 Permissions for file 1.sh : r-x 
Other's permissions are same: r-x</pre>  





###Aim:
C program to create a file with 16 bytes of arbitrary data from the beginning and another 16 bytes of arbitrary data from an offset of 48. Display the file contents to demonstrate how the hole in file is handled.

####Description:
<pre>  fd:file descriptor
  lseek:function is used to seek the memory offset
</pre>
####Code:
<pre>`#`include&lt;stdio.h>
`#`include&lt;stdlib.h>
`#`include&lt;fcntl.h>

int main()
{
	int fd;
	char buf2[16]="ABCDEFGHIJKLMNOP";
	char buf1[16]="abcdefghijklmnop";

	fd=open("data.txt",O_RDWR|O_CREAT|O_EXCL,0765);

	if(fd==-1)
	printf("Error creating file");
	else
	write(fd,buf1,16);
	lseek(fd,32,SEEK_CUR);
	write(fd,buf2,16);
	system(" vi data.txt");
	close(fd);
}
</pre>
####Output:
<pre>abcdefghijklmnop^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@^@ABCDEFGHIJKLMNOP
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
~                                                                               
Type  :quit<Enter>  to exit Vim
</pre>






###Aim:
Shell script that accepts file names specified as arguments and creates a shell script that contains this file as well as the code to recreate these files. Thus if the script generated by your script is executed, it would recreate the original files(This is same as the “bundle” script described by Brain W. Kernighan and Rob Pike in “The Unix Programming Environment”, Prentice – Hall India).

####Description:
<p> $#: Contains the total number of input arguments.</p>
<p>$@:Contains all the input arguments
####Code:
<pre>if [ $# -eq 0 ]
then
echo "error"
exit
fi
for i in $*
 do 
   echo "extracting $i file" >> f.sh
   cat $i >> f.sh
   echo "EOF" >> f.sh
 done
cat f.sh 
</pre>
####Compile: ./2.sh 1.c

####Output:
<pre>extracting 1.c file
`#`include&lt;stdio.h>
`#`include&lt;stdlib.h>
`#`include&lt;string.h>
`#`include&lt;unistd.h>
int main()
{
int pid,n,i;
char cmd[14];
system("clear");
printf("enter the no. of commands:\n");
scanf("%d",&n);
pid=fork();
if(pid)
{
 for(i=0;i&lt;n;i++)
 {
   printf("\nEnter command:\n");
   scanf("%s",cmd);
   system (cmd);
  }
}
return 0;
}
EOF
</pre>





###Aim:
C program to do the following: Using fork( ) create a child process.The child process prints its own process-id and id of its parent and then exits. The parent process waits for its child to finish (by executing the wait( )) and prints its own process-id and the id of its child process and then exits.

###Description:
<p>pid_t:parent id of the process.
<p>fork():it is a system call which forks a new child of a processs</p>

###Code:
<pre>`#`include&lt;stdio.h>
`#`include&lt;unistd.h>
`#`include&lt;stdlib.h>
int main()
{
	pid_t p;
	if((p=fork())&lt;0)
	{
		printf("fork error\n");
		return 0;
	}
	else if(p==0)
	{
		printf("i am child process\n");
		printf("my parent process id is:%d\n",getppid());
		printf("my process id is:%d\n",getpid());
	}
	else
	{
		wait();
		printf("i am parent process\n");
		printf("my child process id is:%d\n",p);
		printf("my own id is: %d\n",getpid());
	}
	return 0;
}</pre>

###Output:
<pre>i am child process
my parent process id is:4273
my process id is:4274
i am parent process
my child process id is:4274
my own id is: 4273</pre>

		
	










#AIM:
To Design, develop and execute a program in C / C++ to simulate the working of Shortest Remaining Time and Round-Robin Scheduling Algorithms.
##Description:
###Shortest remaining time:
Also known as shortest remaining time first (SRTF), is a scheduling method that is a preemptive version of shortest job next scheduling. In this scheduling algorithm, the process with the smallest amount of time remaining until completion is selected to execute. Since the currently executing process is the one with the shortest amount of time remaining by definition, and since that time should only reduce as execution progresses, processes will always run until they complete or a new process is added that requires a smaller amount of time.Shortest remaining time scheduling is the preemptive counter part of SJF and is useful in time sharing system. In SRT, process with the smallest estimated run time to completion is run next, in SJF once a job begin executing, it runs to completion. In SRT a running process may be preempted by a user process with a shorter estimated run time.Consider an example, where three processes arrived in the order P1, P2, P3 at the time mentioned below, and then the average waiting time using SJF scheduling algorithm will be calculated as:
process 	CPU Burst Time 	Time of Arrival
p1 	      10 	            0
p2 	       5 	            1 
p3 	       2 	            2
shortest remaining time scheduling
In this, the CPU will be taken away from the currently executing process whenever a process will less CPU burst time.
As shown in figure, the time when P2 arrives P1 needs 9 millisecond more to finish. As B’s cpu burst in 5 millisecond < 9 millisecond, therefore, P1 execution will be preempted and P2 will be executed but against as P3 arrives P2 execution needs 3 more millisecond where as P3 needs only 2 millisecond to execute, thus P3 takes over P2 and so on.

<pre>Waiting time for P1 = 0+ (8-1) = 7 millisecond
Waiting time for P2 = 1+ (4-2) = 3 millisecond
Waiting time for P3 = 2 millisecond
Average waiting time = (7+3+2) / 3 = 4 millisecond
</pre>
####Round Robin Scheduling:
The basic purpose of this algorithm is to support time sharing system. This algorithm is similar to the FCFS algorithm but now it is preempted FCFS scheduling. The preempted take place after a fixed interval of time called quantum time of time slice. Its implementation requires timer interrupt based on which the preemption take place.Consider the set of the processes lined up in the ready queue. The processes are taken out of the ready queue in FCFS order. Let us suppose that a process has been taken up for execution now. The execution cannot go beyond that time slice. This process may either finish up its execution before the time goes off or CPU will be preempted from it after the timer goes off and this cause an interrupt to the operating system. At this time, context switching will take place. The next process will be taken up from the ready queue. The process, which is left by the CPU, will be added to the tail of the ready queue.
<pre>Round Robin scheduling
process 	CPU Burst Time
p1 	10
p2 	5
p3 	2
</pre>
<pre>The Gantt chart is shown below:
robin hood scheduling
Waiting time for P1 = 0 + (6-2) + (10-8) + (13-12) = 7 Millisecond
Waiting time for P2 = 2+ (8-4) + (12-10) = 8 millisecond
Waiting time for P3 = 4millisecond
Therefore average waiting time = (7+8+4)/3 = 6.33 Millisecond
</pre>
<pre>As shown in figure: first p1 gets the cpu and get executed for 2 millisecond, then context switching occurs and P2 get cpu for 2 millisecond, then again content switching occur and P3 get cpu for 2 millisecond, since its cpu burst time is 2 millisecond only, therefore it complete its execution and thus do not get the cpu again. P1 and P2 similarly continue to share the CPU in the same fashion till they are done.
</pre>
###CODE:
<pre>
 #include&lt;stdio.h>
struct proc
{
        int id;
        int arrival;
        int burst;
        int rem;
        int wait;
        int finish;
        int turnaround;
        float ratio;
}process[10]; //structure to hold the process information
struct proc temp;
int no;
int chkprocess(int);
int nextprocess();
 void roundrobin(int, int, int[], int[]);
 void srtf(int);
</pre>
int main()
<pre>{
          int n,tq,choice;
          int bt[10],st[10],i,j,k;
for(; ;)
{
printf("Enter the choice \n");
printf(" 1. Round Robin\n 2. SRT\n 3. Exit \n");
scanf("%d",&choice);
switch(choice)
{
case 1:
printf("Round Robin scheduling algorithm\n");
printf("Enter number of processes:\n");
  scanf("%d",&n);
  printf("Enter burst time for sequences:");
  for(i=0;i&lt;n;i++)
   {
     scanf("%d",&bt[i]);
     st[i]=bt[i];        //service time
   }
   printf("Enter time quantum:");
   scanf("%d",&tq);
   roundrobin(n,tq,st,bt);
   break;
case 2:
        printf("\n \n ---SHORTEST REMAINING TIME NEXT---\n \n ");
        printf("\n \n Enter the number of processes: ");
        scanf("%d", &n);
        srtf(n);
break;
case 3: break;
}// end of switch
}// end of for
}//end of main()
</pre>
void roundrobin(int n,int tq,int st[],int bt[])
<pre> {                 
int time=0;
          int tat[10],wt[10],i,count=0,swt=0,stat=0,temp1,sq=0,j,k;
          float awt=0.0,atat=0.0;
         while(1)
           {
                     for(i=0,count=0;i&lt;n;i++)
                     {
       temp1=tq;
       if(st[i]==0) // when service time of a process equals zero then
  //count value is incremented
       {
         count++;
         continue;
       }
       if(st[i]>tq) // when service time of a process greater than time
//quantum then time
                st[i]=st[i]-tq; //quantum value subtracted from service time
       else
        if(st[i]>=0)
        {
                 temp1=st[i]; // temp1 stores the service time of a process
                 st[i]=0; // making service time equals 0
        }
        sq=sq+temp1; // utilizing temp1 value to calculate turnaround time
        tat[i]=sq; // turn around time
     } //end of for
     if(n==count) // it indicates all processes have completed their task because the count value
     break; // incremented when service time equals 0
   } //end of while
   for(i=0;i&lt;n;i++) // to calculate the wait time and turnaround time of each process
   {
    wt[i]=tat[i]-bt[i]; // waiting time calculated from the turnaround time - burst time
    swt=swt+wt[i]; // summation of wait time
    stat=stat+tat[i]; // summation of turnaround time
   }
   awt=(float)swt/n; // average wait time
   atat=(float)stat/n; // average turnaround time
   printf("Process_no        Burst time        Wait time        Turn around time\n");
   for(i=0;i&lt;n;i++)
    printf("%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
    printf("Avg wait time is %f\n Avg turn around time is %f\n",awt,atat);
 }// end of Round Robin
</pre>
int chkprocess(int s) // function to check process remaining time is zero or not
<pre>{
        int i;
        for(i = 1; i &lt;= s; i++)
        {
                if(process[i].rem != 0)
                        return 1;
        }
        return 0;
} // end of chkprocess
</pre>           
int nextprocess() // function to identify the next process to be executed
<pre>{
        int min, l, i;
        min = 32000; //any limit assumed
        for(i = 1; i &lt;= no; i++)
        {
                if( process[i].rem!=0 && process[i].rem &lt; min)
                {
                        min = process[i].rem;
                        l = i;
                }
        }
        return l;
} // end of nextprocess
</pre>
void srtf(int n)
<pre>{
int i,j,k,time=0;
float tavg,wavg;
for(i = 1; i &lt;= n; i++)
        {
                process[i].id = i;
                printf("\n\nEnter the arrival time for process %d: ", i);
                scanf("%d", &(process[i].arrival));
                printf("Enter the burst time for process %d: ", i);
                scanf("%d", &(process[i].burst));
                process[i].rem = process[i].burst;
         }
        for(i = 1; i &lt;= n; i++)
        {
                for(j = i + 1; j &lt;= n; j++)
                {
                        if(process[i].arrival > process[j].arrival) // sort arrival time of a process
                        {
                                temp = process[i];
                                process[i] = process[j];
                                process[j] = temp;
                        }
                }
        }
        no = 0;
        j = 1;
       while(chkprocess(n) == 1)
        {
                if(process[no + 1].arrival == time)
                {
                        no++;
                        if(process[j].rem==0)
                         process[j].finish=time;
                        j = nextprocess();
                }
                if(process[j].rem != 0) // to calculate the waiting time of a process
                {
                        process[j].rem--;
                        for(i = 1; i &lt;= no; i++)
                        {
                                if(i != j && process[i].rem != 0)
                                        process[i].wait++;
                        }
                }
                     else
                {

                        process[j].finish = time;
                        j=nextprocess();
                        time--;
                        k=j;
                }

                time++;
        }
        process[k].finish = time;
        printf("\n\n\t\t\t---SHORTEST REMAINING TIME FIRST---");
        printf("\n\n Process Arrival Burst Waiting Finishing turnaround Tr/Tb \n");
        printf("%5s %9s %7s %10s %8s %9s\n\n", "id", "time", "time", "time", "time", "time");
        for(i = 1; i <= n; i++)
        {
                     process[i].turnaround = process[i].wait + process[i].burst; // calc of turnaround
                     process[i].ratio = (float)process[i].turnaround / (float)process[i].burst;
                     printf("%5d %8d %7d %8d %10d %9d %10.1f ", process[i].id, process[i].arrival,
                     process[i].burst, process[i].wait, process[i].finish, process[i].turnaround,
                     process[i].ratio);
         	  tavg=tavg+ process[i].turnaround; //summation of turnaround time
         	  wavg=wavg+process[i].wait; // summation of waiting time
                    printf("\n\n");
        }
        tavg=tavg/n; // average turnaround time
        wavg=wavg/n; // average wait time
            printf("tavg=%f\t shortest remaining time scheduling=%f\n",tavg,wavg);
}// end of srtf
</pre>

####OUTPUT:
<pre>Enter the choice
 1) Round Robin 2) SRT
 3) Exit
1
Round Robin scheduling algorithm
**********************************
Enter number of processes:3
Enter burst time for sequences:24

3

3

</pre>Enter time quantum:4
<pre>Process_no      Burst time      Wait time       Turnaround time
        1                    24              6                  30
        2                    3               4                  7
        3                    3               7                  10
Avg  wait time is 5.666667 
Avg  turnaround time is 15.666667
Enter the choice
 1) Round Robin 2) SRT
 3) Exit
2
 ---SHORTEST REMAINING TIME NEXT---
 Enter the number of processes: 4
Enter the arrival time for process 1: 0
Enter the burst time for process 1: 8
Enter the arrival time for process 2: 1
Enter the burst time for process 2: 4
Enter the arrival time for process 3: 2
Enter the burst time for process 3: 9
Enter the arrival time for process 4: 3
Enter the burst time for process 4: 5
1               24              6               30
2               3               4               7
3               3               7               10
 ---SHORTEST REMAINING TIME FIRST---
 Enter the number of processes: 4
Enter the arrival time for process 1: 0
Enter the burst time for process 1: 8
Enter the arrival time for process 2: 1
Enter the burst time for process 2: 4
Enter the arrival time for process 3: 2
Enter the burst time for process 3: 9
Enter the arrival time for process 4: 3
Enter the burst time for process 4: 5</pre>
                      ---SHORTEST REMAINING TIME NEXT---

<pre> Process  Arrival  Burst   Waiting  Finishing turnaround  Tr/Tb
   id      time    time       time     time      time     time
    1        0       8        	9       17        17       2.1
    2        1       4          0        5         4       1.0
    3        2       9         15       26        24       2.7
    4        3       5          2       10         7       1.4

tavg=12.734766   

wavg=6.500000






##AIM:
 Using OpenMP, Design, develop and run a multi-threaded program to generate and print Fibonacci Series. One thread has to generate the  numbers up to the specified limit and another thread has to print them. Ensure proper synchronization.

###DESCRIPTION:
In mathematics, the Fibonacci numbers or Fibonacci series or Fibonacci sequence are the numbers in the following integer sequence:0 1 1 2 3 5 8 13 21 34 55 . . . . . . . 
###FORMULA:
F<sub>n</sub> = F<sub>(n-1)</sub> + F<sub>(n-2)</sub>
###CODE:
`#`include&lt;stdio.h&gt;

`#`include&lt;omp.h&gt;

int main()
{
<pre>   int n,a[100],i;
   omp_set_num_threads(2);
   printf("enter the no of terms of fibonacci series which have to be generated\n");
   scanf("%d",&n);
   a[0]=0;
   a[1]=1;
   #pragma omp parallel
   {
    	  #pragma omp single
    	  for(i=2;i&lt;n;i++)
    	  {
           	a[i]=a[i-2]+a[i-1];
     		printf("id of thread involved in the computation of fib no %d is=%d\n",i+1,omp_get_thread_num());
   	  }
          #pragma omp barrier
          #pragma omp single
    	 {
       		printf("the elements of fib series are\n");
       		for(i=0;i&lt;n;i++)
       		printf("%d,id of the thread displaying this no is =  %d\n",a[i],omp_get_thread_num());
   	 }
   }
   return 0;
}
</pre>
###OUTPUT
<pre>
cc -fopenmp 11.c 
./a.out
enter the no of terms of fibonacci series which have to be generated
5
id of thread involved in thes computation of fib no 3 is=0
id of thread involved in the computation of fib no 4 is=0
id of thread involved in the computation of fib no 5 is=0
the elements of fib series are
0,id of the thread displaying this no is =  1
1,id of the thread displaying this no is =  1
1,id of the thread displaying this no is =  1
2,id of the thread displaying this no is =  1
3,id of the thread displaying this no is =  1
</pre>







##AIM: Program 12: Design, develop and run a program to implement the Bankers Algorithm. Demonstrate its Working with different data values

###DESCRIPTION:
The Banker's algorithm is a resource allocation and deadlock avoidance algorithm developed by Edsger Dijkstra that tests for safety by simulating the allocation of predetermined maximum possible amounts of all resources, and then makes an "s-state" check to test for possible deadlock conditions for all other pending activities, before deciding whether allocation should be allowed to continue.The Banker's algorithm is run by the operating system whenever a process requests resources.The algorithm avoids deadlock by denying or postponing the request if it determines that accepting the request could put the system in an unsafe state. When a new process enters a system, it must declare the maximum number of instances of each resource type that it may ever claim; clearly, that number may not exceed the total number of resources in the system. Also, when a process gets all its requested resources it must return them in a finite amount of time.

###ALGORITHM:
<pre>
Let n be the number processes in the system and m be the number of resource types. We need the following data structures:
(1)Available 
(2) Max 
(3) Allocation 
(4) Need 
1) Available: A vector of length m indicates the number of available resources of each type. 
If available [j] = k, there are k instances of resource type R available.
2)Max: An n x m matrix defines the maximum demand of each process. 
If Max [i, j] = k, then process P. may request at most k instances of resource type Rr
3)Allocation: An n x m matrix defines the number of resources of each type currently allocated to each process.
 If allocation [i, j] = k, then P. is currently allocated k instances of resource type R
4)Need: An n x m matrix indicates the remaining resource need of each process.
 If Need |i, j] = k, then process P. may need k more instances of resource type R, to complete its task. Need [i, j] – Allocation [i, j].
</pre>
####Safety algorithm: 
Safety algorithm is used to find the state of the system: That is, system may be safe state or unsafe state. Method for this is as follows:
<pre>
1)Let work and finish be vector of length m and n respectively. Initialize work = Available and Finish [i] = False for i = 1, 2, 3, 4, … n.
2)Find an i such that both
a)Finish [i] = False b) Need f[j] &lt; work
If no such i exist, go to step 4.
3)Work : = Work + Allocation i
Finish [i] = true to step 2
4)If Finish [i] = true for all i, then the system is in a safe state. 
</pre>
####Resource-request algorithm: 
<pre>
Let request, be the request vector for process P. If Request, fj] = k, then process P. wants k instances of resource type R. 
When a request for resources is made by process P, the following actions are taken.
1)If Request. &lt; Need(, then go to step 2. Otherwise, raise an eitor condition since the process has exceeded its maximum claim.
2)If Request &lt; Available, then go to step 3. Otherwise, P. must wait since the resources are not available.
3)Available : = Available – Request.; Allocation : = Allocation + Request.; Need; : = Needt – Request.;

If the resulting resource allocation stale is safe, the transaction is completed and process P. is allocated its resources. If the new state is unsafe, then P. must wait to the Request, and the old resource allocation state is restored.
</pre>
###CODE 1:
<pre>
    #include&lt;stdio.h&gt;
    #include&lt;string.h&gt;
    #include&lt;stdlib.h&gt;
    int n,m,i,j;    //n=no. of processes, m= recources
    int all[10][10],max[10][10],need[10][10],avail[10],work[10],req[10];
    int count=0;
   struct process 
   {
     char process[10]; // to name the process like process=0 implies process 0 = P0
     int flag; //used to check safe sequence
    }p[10];
   void input()
    {
     printf("\n Enter total num of processes:");
     scanf("%d",&n);
     for(i=0;i&lt;n;i++)
     {
     printf("\nprocess:-");
      scanf("%s",p[i].process);
     }
     printf("\n Enter the number of resources:");
     scanf("%d",&m);
     printf("\n Enter allocation matrix:");
     for(i=0;i&lt;n;i++)
     {
      for(j=0;j&lt;m;j++)
      {
       scanf("%d",&all[i][j]);
      }
     }
     printf("\n Enter max matrix:");
     for(i=0;i&lt;n;i++)
     {
     for(j=0;j&lt;m;j++)
      {
       scanf("%d",&max[i][j]);
      }
     }
     printf("\n  need matrix:");
     for(i=0;i&lt;n;i++)
     {
      for(j=0;j&lt;m;j++)
      {
       need[i][j]=max[i][j]-all[i][j];
       printf("%d",need[i][j]);
      }
      printf("\n");
     }
     printf("\n Enter Available");
     for(i=0;i&lt;m;i++)
     {
      scanf("%d",&avail[i]);
     }
    }
   void safeseq() 
    {
     int sseq[10],ss=0,chk=0,chki=0;
     for(j=0;j&lt;m;j++)
       work[j]=avail[j];//initialise work=available
     for(i=0;i&lt;n;i++)
       p[i].flag=0;//initialise finish[i]=false for i=0,1,2...
     while(count!=n)
     {
     for(i=0;i&lt;n;i++)  
           {      
             chk=0;
             for(j=0;j&lt;m;j++)
             {
              if(p[i].flag==0)
              {
               if(need[i][j]&lt;=work[j])
               chk++;
              }
              if(chk==m)
              {
               for(j=0;j&lt;m;j++)
               {
                work[j]=work[j]+all[i][j];
                p[i].flag=1;
               }
              sseq[ss]=i;
              ss++;
              count++;
              }
             }
            }
     }
    for(i=0;i&lt;n;i++)
     {
      if(p[i].flag==1)
      chki++;
     }
     if(chki>=n)
     {
      printf("\n System is in safe state");
      for(i=0;i&lt;n;i++)
      printf("%d",sseq[i]);
     }
     else
     printf("\nsystem is not safe");
    }
   void request()
    {
     int processreq;
     printf("\n Enter the process process that is requesting:");
     scanf("%d",&processreq);
     printf("\n enter the reqested array:");
     for(i=0;i&lt;m;i++)
      scanf("%d",&req[i]);
     for(j=0;j&lt;m;j++)
     {
       if(req[j]&lt;=need[processreq][j])    
       {
          if(req[j]&lt;=avail[j])
           {
            avail[j]=avail[j]-req[j];
            all[processreq][j]=all[processreq][j]+req[j];
            need[processreq][j]=need[processreq][j]-req[j];
            printf("avail:%d",avail[j]);        
           }
       printf("\tneed: %d\n",need[processreq][j]);
       }
       else
       {
        printf("\n Process is not in safe state and hence request cannot be granted");
        exit(0);
       }
      }
      printf("\nrequest can be granted");
     }
</pre>
       
   void print()
    <pre>{
    printf("no. of processes=%d",n);
  
    printf("no. of resources=%d",m);
 
    printf("\npid\t max \t allocated \t need");
     for(i=0;i&lt;n;i++)
     {
       printf("\n%d\t",i);
       for(j=0;j&lt;m;j++) printf(" %d ",max[i][j]); printf("\t");
       for(j=0;j&lt;m;j++) printf(" %d ",all[i][j]); printf("\t");
       for(j=0;j&lt;m;j++) printf(" %d ",need[i][j]); printf("\t");
     }
     printf("\n Available");
     for(i=0;i&lt;m;i++)
     printf("%d ",avail[i]);
    }

 <pre>int main()
    {
     int ch;
     do
     {
      printf("\n menu:");
      printf("\n 1.Input:");
      printf("\n 2.Safe Seq:");
      printf("\n 3.Request:");
      printf("\n 4.Print:");
      printf("\n 5.exit:");
      printf("\n Ent choice");
      scanf("%d",&ch);
      switch(ch)
      {
       case 1: input();
               break;
       case 2: safeseq();
               break;
       case 3: request();
               break;
       case 4: print();
               break;
       case 5: break;
      }
     }while(ch!=n);
     return 0;
    }
</pre>
###Output:
<pre>
$ cc 12.c
$ ./a.out

 menu:
 1.Input:
 2.Safe Seq:
 3.Request:
 4.Print:
 5.exit:
 Ent choice1
</pre>
 Enter total num of processes:5
process:-0
process:-1
process:-2
process:-3
process:-4
</pre>
<pre>
 Enter the number of resources:3
 Enter allocation matrix:0 1 0
2 0 0 
3 0 2
2 1 1
0 0 2
 Enter max matrix:
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
  need matrix:743
122
600
011
431
</pre>
<pre>
 Enter Available3 3 2
</pre>
<pre>
 menu:
 1.Input:
 2.Safe Seq:
 3.Request:
 4.Print:
 5.exit:
 Ent choice4
no. of processes=5no. of resources=3
pid	 max 	 allocated 	 need
0	 7  5  3 	 0  1  0 	 7  4  3 	
1	 3  2  2 	 2  0  0 	 1  2  2 	
2	 9  0  2 	 3  0  2 	 6  0  0 	
3	 2  2  2 	 2  1  1 	 0  1  1 	
4	 4  3  3 	 0  0  2 	 4  3  1 	
 Available3 3 2 
 menu:
 1.Input:
 2.Safe Seq:
 3.Request:
 4.Print:
 5.exit:
 Ent choice2
 System is in safe state13402
</pre>
<pre>
 menu:
 1.Input:
 2.Safe Seq:
 3.Request:
 4.Print:
 5.exit:
 Ent choice3
</pre>
<pre>
 Enter the process process that is requesting:1
enter the reqested array:1 0 2
avail:2	need: 0
avail:3	need: 2
avail:0	need: 0
request can be granted
</pre>
<pre>
 menu:
 1.Input:
 2.Safe Seq:
 3.Request:
 4.Print:
 5.exit:
 Ent choice3
</pre>
<pre>
 Enter the process process that is requesting:2
enter the reqested array:2 2 3
avail:0	need: 4
 Process is not in safe state and hence request cannot be granted
</pre>

##OR
###CODE 2:
<pre>
 #include&lt;stdio.h&gt;
struct process
{
int all[6],max[6],need[6],finished,request[6];
}p[10];
int avail[6],sseq[10],ss=0,check1=0,check2=0,n,pid,work[6];
int nor,nori;
int main()
{
int safeseq(void);
int ch,i=0,j=0,k,pid,ch1;
int violationcheck=0,waitcheck=0;
do
{
printf("\n\n\t 1. Input");
printf("\n\n\t 2. New Request");
printf("\n\n\t 3. Safe State or Not");
printf("\n\n\t 4. print");
printf("\n\n\t 5. Exit");
printf("\n\n\t Enter ur choice :");
scanf("%d",&ch);
switch(ch)
{
case 1:
printf("\n\n\t Enter number of processes : ");
scanf("%d",&n);
printf("\n\n\t Enter the Number of Resources : ");
scanf("%d",&nor);
printf("\n\n\t Enter the Available Resouces : ");
for(j=0;j&lt;n;j++)
{
for(k=0;k&lt;nor;k++)
{
if(j==0)
{
printf("\n\n\t For Resource type %d : ",k);
scanf("%d",&avail[k]);
}
p[j].max[k]=0;
p[j].all[k]=0;
p[j].need[k]=0;
p[j].finished=0;
p[j].request[k]=0;
}
}
for(i=0;i&lt;n;i++)
{
printf("\n\n\t Enter Max and Allocated resources for P %d : ",i);
 for(j=0;j&lt;nor;j++)
{
printf("\n\n\t Enter the Max of resource %d : ",j);
scanf("%d",&p[i].max[j]);
printf("\n\n\t Allocation of resource %d    :",j);
scanf("%d",&p[i].all[j]);
if(p[i].all[j]&gt;p[i].max[j])
{
printf("\n\n\t Allocation should be less &lt; or == max");
j--;
}
else
p[i].need[j]=p[i].max[j]-p[i].all[j];
avail[j]=avail[j]-p[i].all[j];
}
}
break;
case 2:
violationcheck=0;
waitcheck=0;
printf("\n\n\t Requesting process id :");
scanf("%d",&pid);
for(j=0;j&lt;nor;j++)
{
printf("\n\n\t Number of Request for resource %d :",j);
  scanf("%d",&p[pid].request[j]);
if(p[pid].request[j]&gt;p[pid].need[j])
violationcheck=1;
if(p[pid].request[j]&gt;avail[j])
waitcheck=1;
}
if (violationcheck==1)
printf("\n\n\t The Process Exceeds it’s Max Need: Terminated");
else if(waitcheck==1)
printf("\n\n\t Lack of Resourcess : Process State – Wait");
else
{
for(j=0;j&lt;nor;j++)
{
avail[j]=avail[j]-p[pid].request[j];
p[pid].all[j]=p[pid].all[j]+p[pid].request[j];
p[pid].need[j]=p[pid].need[j]-p[pid].request[j];
}
ch1=safeseq();
if(ch1==0)
{
for(j=0;j&lt;nor;j++)
{
avail[j]=avail[j]+p[pid].request[j];
p[pid].all[j]=p[pid].all[j]-p[pid].request[j];
p[pid].need[j]=p[pid].need[j]+p[pid].request[j];
}
}
else if(ch1==1)
printf("\n\n\t Request Committed ");
}
break;
case 3:
if(safeseq()==1)
printf("\n\n\t The System is in safe state ");
else
printf("\n\n\t The System is Not in safe state ");
break;
case 4:
printf("\n\n\t Number of processes : %d",n);
printf("\n\n\t Number of Resources : %d",nor);
printf("\n\n\t Pid \t   Max \t   Allocated \t Need ");
for(i=0;i&lt;n;i++)
{
printf("\n\n\t  P%d : ",i);
for(j=0;j&lt;nor;j++)
printf(" %d",p[i].max[j]);
printf("\t");
for(j=0;j&lt;nor;j++)
printf("%d",p[i].all[j]);
printf("\t");
for(j=0;j&lt;nor;j++)
printf("%d",p[i].need[j]);
}
printf("\n\n\t Available :");
for(i=0;i&lt;nor;i++)
printf("%d",avail[i]);
break;
case 5:
break;
}
}while(ch!=5);
}
int safeseq()
{
int tj,tk,i,j,k;
ss=0;
for(j=0;j&lt;nor;j++)
work[j]=avail[j];
for(j=0;j&lt;n;j++)
p[j].finished=0;
for( tk=0;tk&lt;nor;tk++)
{
for(j=0;j&lt;n;j++)
{
if(p[j].finished==0)
{
check1=0;
for(k=0;k&lt;nor;k++)
if(p[j].need[k]&lt;=work[k])
check1++;
if(check1==nor)
{
for(k=0;k&lt;nor;k++)
{
work[k]=work[k]+p[j].all[k];
p[j].finished=1;
}
sseq[ss]=j;
ss++;
}
}
}
}
check2=0;
for(i=0;i&lt;n;i++)
if(p[i].finished==1)
check2++;
printf("\n\n\t");
if(check2&gt;=n)
{
printf("\n\n\t The system is in safe state");
for( tj=0;tj&lt;n;tj++)
printf("P%d,",sseq[tj]);
return 1;
}
else
printf("\n\n\t The system is Not in safe state");
return 0;
}
</pre>
###Output:
<pre>
$cc 12.c
$./a.out
	 1. Input
	 2. New Request
	 3. Safe State or Not
	 4. print
	 5. Exit
	 Enter ur choice :1
</pre>
<pre>	
 	 Enter number of processes : 5
	 Enter the Number of Resources : 3
	 Enter the Available Resouces : 
 For Resource type 0 : 10
	 For Resource type 1 : 5
 For Resource type 2 : 7
</pre>
<pre>
	 Enter Max and Allocated resources for P 0 : 
	 Enter the Max of resource 0 : 7
	 Allocation of resource 0    :0
	 Enter the Max of resource 1 : 5
	 Allocation of resource 1    :1
	 Enter the Max of resource 2 : 3
	 Allocation of resource 2    :0
	 Enter Max and Allocated resources for P 1 : 
	 Enter the Max of resource 0 : 3
	 Allocation of resource 0    :2
	 Enter the Max of resource 1 : 2
	 Allocation of resource 1    :0
	 Enter the Max of resource 2 : 2
	 Allocation of resource 2    :0
	 Enter Max and Allocated resources for P 2 : 
	 Enter the Max of resource 0 : 9
	 Allocation of resource 0    :3
	 Enter the Max of resource 1 : 0
	 Allocation of resource 1    :0
          Enter the Max of resource 2 : 2
	 Allocation of resource 2    :2
	 Enter Max and Allocated resources for P 3 : 
	 Enter the Max of resource 0 : 2
	 Allocation of resource 0    :2
	 Enter the Max of resource 1 : 2
          Allocation of resource 1    :1
	 Enter the Max of resource 2 : 2
	 Allocation of resource 2    :1
	 Enter Max and Allocated resources for P 4 : 
	 Enter the Max of resource 0 : 4
	 Allocation of resource 0    :0
	 Enter the Max of resource 1 : 3
	 Allocation of resource 1    :0
	 Enter the Max of resource 2 : 3
	 Allocation of resource 2    :2
	 1. Input
	 2. New Request
	 3. Safe State or Not
	 4. print
	 5. Exit
	 Enter ur choice :3
	 The system is in safe stateP1,P3,P4,P0,P2,
	 The System is in safe state 
	 1. Input
	 2. New Request
	 3. Safe State or Not
	 4. print
	 5. Exit
	 Enter ur choice :2
	 Requesting process id :1
	 Number of Request for resource 0 :1
	 Number of Request for resource 1 :0
	 Number of Request for resource 2 :2
          The system is in safe stateP1,P3,P4,P0,P2
 Request Committed 
	 1. Input
	 2. New Request
	 3. Safe State or Not
	 4. print
	 5. Exit
	 Enter ur choice :2
	 Requesting process id :2
	 Number of Request for resource 0 :2
	 Number of Request for resource 1 :2
	 Number of Request for resource 2 :3
	 The Process Exceeds it�s Max Need: Terminated
</pre>
