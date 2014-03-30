%{
#include<stdio.h>
#include<stdlib.h>
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
}
