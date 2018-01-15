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


