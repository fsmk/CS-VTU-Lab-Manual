%{
#include<stdio.h>
int valid=1;
%}
id [a-zA-Z0-9]*
%%
{id}" and "{id} {valid=0;}
{id}" or "{id} {valid=0;}
{id}" but "{id} {valid=0;}
{id}" between "{id} {valid=0;}
. ;
\n {return 0;}
%%
main()
{
	printf("Enter a sentence\n");
	yylex();
	if(valid==1)
	printf("Its a simple sentence\n");
	else
	printf("Its a compound sentence\n");
} 
