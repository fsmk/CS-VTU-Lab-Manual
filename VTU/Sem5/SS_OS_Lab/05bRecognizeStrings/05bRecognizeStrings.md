## AIM :Program to recognize strings 'aaab', 'abbb', 'ab' and 'a' using the grammar (anbn, n>= 0).


## DESCRIPTION : 
<p>The program has three parts defination section,rule section,subroutine section. The program accepts equal number of a's and b's as valid inputs. The grammar is S->A S B, A->a ,b->b . </p>

## ALGORITHM :


## CODE :

<pre>%{
#include<stdio.h>
#include<stdlib.h>
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



## LEX SPECIFICATION

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

## OUTPUT :

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



