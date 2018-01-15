## PROGRAM: 5a.y(YACC specification)
## AIM:
 Program to evaluate an arithmetic expression involving operators +, -, * and /.
## DESCRIPTION:
This program is to solve or to evaluate the given arithmatic expression using the operators +,-,* and /. 

example: 3+5=8.


## ALGORITHM:


## CODE:
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
	  printf("Valid expression\n");
}		





## PROGRAM: 5a.l(LEX specification)


## CODE:
%{

   #include"y.tab.h"

   extern int yylval;

%}

%%

[0-9]+                   {yylval=atoi(yytext);return NUMBER;}

.                        return yytext[0];

\n                       return 0;

%%

## OUTPUT:

 1.) Enter the expression

   2+6

   Result is 8

   Valid expression

2.) Enter the expression

    2*

    Invalid expression




