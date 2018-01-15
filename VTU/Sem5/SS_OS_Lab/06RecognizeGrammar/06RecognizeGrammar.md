##AIM:Program to recognize the grammar (anb, n>= 10).

###DESCRIPTION:
<p>The program has three parts:definition section,rule section,subroutine section. The program uses a variable count to keep track of the number of A's in the input string and B is accepted only once according to the rule described.So count must be more than 9.</p>

###ALGORITHM:

###CODE:

<pre>%{
#include<stdio.h>
#include<stdlib.h>
int count=0;
%}
%token A B;
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
