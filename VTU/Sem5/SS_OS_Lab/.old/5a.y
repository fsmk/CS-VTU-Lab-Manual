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
     		$$=$1/$3'
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
	printf("Valid expression\n");
}		
