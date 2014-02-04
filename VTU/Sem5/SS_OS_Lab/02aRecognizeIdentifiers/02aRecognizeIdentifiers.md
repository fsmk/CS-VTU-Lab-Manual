##AIM:
Program to recognize a valid arithmetic expression and to recognize 
the identifiers and operators present. Print them separately.

##DESCRIPTION:
Following the syntax for defining an identifier we generate arithmetic expressions using basic arithmetic operators such as +, -, * & /.

##FLEX:  flex - the fast lexical analyser generator.

##CODE:
<pre>%{
`#`include<stdio.h>
int a[4]={0,0,0,0};
int valid=1,i;
int nop=0;
%}
%x OPER
%%
[a-zA-Z0-9]+ {BEGIN OPER;nop++;}
<OPER>"+" {if(valid) {valid=0;i=0;}else ext();}
<OPER>"-" {if(valid) {valid=0;i=1;}else ext();}
<OPER>"*" {if(valid) {valid=0;i=2;}else ext();}
<OPER>"/" {if(valid) {valid=0;i=3;}else ext();}
<OPER>[a-zA-Z0-9]+ {nop++;if(valid==0){valid=1;a[i]++;}else ext();}
<OPER>. {if(valid){valid=0;ext();}else return 0;}
<OPER>"\n" {if(valid==0){ext();}else return 0;}
. ext();
\n ext();
%%
int ext()
{
	printf("Invalid expression\n");
	exit(0);
}
int main()
{
	printf("Enter expression\n");
	yylex();
	printf("Expression is valid\n");
	printf("No. of '+' is:%d\n",a[0]);
	printf("No. of '-' is:%d\n",a[1]);
	printf("No. of '*' is:%d\n",a[2]);
	printf("No. of '/' is:%d\n",a[3]);
	printf("No. of operands is:%d\n",nop);
	return 0;
}</pre>		

##COMPILE:
<pre>lex 2a.l
gcc lex.yy.c -ll
./a.out </pre>

##OUTPUT:
<pre>Enter expression
2+4*6+2/5-3*6     
Expression is valid
No. of '+' is:2
No. of '-' is:1
No. of '*' is:2
No. of '/' is:1
No. of operands is:7
Enter expression
2-3*
Invalid expression</pre>
