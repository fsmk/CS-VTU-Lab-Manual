##AIM:
Program to recognize a valid arithmetic expression and to recognize 
the identifiers and operators present. Print them separately.

##DESCRIPTION:
Following the syntax for defining an identifier we generate arithmetic expressions using basic arithmetic operators such as +, -, *, /, ( and )

##FLEX:  flex - the fast lexical analyser generator.

##CODE:
	%{
	#include <stdio.h>
	#include <stdlib.h>
	int identifier=0,sum=0,diff=0,multiplication=0,division=0,opening_bracket=0,closing_bracket=0,flag=0,operand=0;
	%}
	%%
	[a-zA-Z0-9]+	{printf("%s is an identifier\n",yytext);identifier++;}
	"+"		{printf("+ is an operator\n");sum++;operand++;}
	"-"		{printf("- is an operator\n");diff++;operand++;}
	"*"		{printf("* is an operator\n");multiplication++;operand++;}
	"/"		{printf("/ is an operator\n");division++;operand++;}
	"("		{printf("( is an operator\n");opening_bracket++;}
	")"		{printf(") is an operator\n");closing_bracket++;if(opening_bracket<closing_bracket)flag=1;}
	%%

	int main()
	{
	yylex();
	if(flag==0&&opening_bracket==closing_bracket&&identifier==operand+1){
		printf("Number of identifiers:%d\n",identifier);
		printf("Number of operands:%d\n",operand);
		printf("Number of +:%d\n",sum);

		printf("Number of -:%d\n",diff);

		printf("Number of *:%d\n",multiplication);

		printf("Number of /:%d\n",division);

		printf("Number of (:%d\n",opening_bracket);

		printf("Number of ):%d\n",closing_bracket);


	}else{
		printf("Invalid Expression");
	}
	exit(EXIT_SUCCESS);

	}

##COMPILE:
<pre>lex 2a.l
gcc lex.yy.c -ll
./a.out </pre>

##OUTPUT:
<pre>Enter expression
2+4*6+2/5-3*6     
2 is an identifier
+ is an operator
4 is an identifier
* is an operator
6 is an identifier
+ is an operator
2 is an identifier
/ is an operator
5 is an identifier
- is an operator
3 is an identifier
* is an operator
6 is an identifier

Number of identifiers:7
Number of operands:6
Number of +:2
Number of -:1
Number of *:2
Number of /:1
Number of (:0
Number of ):0

2-3*
Invalid expression</pre>