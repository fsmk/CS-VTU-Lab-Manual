%{
#include<stdio.h>
#include<stdlib.h>
%}
%token DIGIT ALPHA
%%
variable:ALPHA
        |variable APLHA
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
        
