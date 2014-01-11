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
