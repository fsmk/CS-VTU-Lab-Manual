%{
#include<stdio.h>
#include<stdlib.h>
%}
% token A B;
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
}		
