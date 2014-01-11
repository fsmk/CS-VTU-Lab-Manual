%{
#include<stdio.h>
int count=0,floatcount=0,charcount=0,doublecount=0;
%}
ID [a-zA-Z][a-zA-Z0-9]*
I "int"
F "float"
C "char"
D "double"
%s DEFN
%s DEFN2
%s DEFN3
%s DEFN4
%%
[\t] ;
{I} {BEGIN DEFN;}
<DEFN>{ID}"," {intcount++;printf("%s\n",yytext);}
<DEFN>{ID}";" {intcount++;BEGIN 0;printf("%s\n",yytext);}
{F} {BEGIN DEFN2;}
<DEFN2>{ID}"," {floatcount++;printf("%s\n",yytext);}
<DEFN2>{ID}";" {floatcount++;BEGIN 0;printf("%s\n",yytext);}
{C} {BEGIN DEFN3;}
<DEFN3>{ID}"," {charcount++;printf("%s\n",yytext);}
<DEFN3>{ID}";" {charcount++;BEGIN 0;printf("%s\n",yytext);}
{D} {BEGIN DEFN;}
<DEFN4>{ID}"," {doublecount++;printf("%s\n",yytext);}
<DEFN4>{ID}";" {doublecount++;BEGIN 0;printf("%s\n",yytext);}
. ;
\n ;
%%
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("Error\n");
		return 0;
	}
	yyin=fopen(argv[1],"r");
	printf("The identifiers are:\n");
	yylex();
	printf("the no. of int identifiers are %d\n",intcount);	
	printf("the no. of float identifiers are %d\n",floatcount);
	printf("the no. of char identifiers are %d\n",charcount);
	printf("the no. of double identifiers are %d\n",doublecount);
	return 0;
}	
