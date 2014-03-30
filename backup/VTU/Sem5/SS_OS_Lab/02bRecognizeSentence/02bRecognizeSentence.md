#AIM:
Program to recognize whether a given sentence is simple or compound.
##DESCRIPTION:
The user is expected to develop a code which recognizes a sentence as either simple or compound.The design considers that we use and, or, but & between.The user can specify more rules as per his/her choice.

##CODE:
<pre>%{
`#`include&lt;stdio.h>
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
}</pre> 
##OUTPUT:
<pre>Enter a sentence
hi and bye
Its a compound sentence</pre>

<pre>Enter a sentence
anand
Its a simple sentence</pre>



