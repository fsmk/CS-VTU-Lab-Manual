#AIM:
Program to recognize and count the number of identifiers in a given
input file.

##DESCRIPTION:
Given any program containing few datatypes defined we should be able to count the total number of identifiers, number of identifers of the same datatype and also display what they are.

###FLEX:  flex - the fast lexical analyser generator.

###CODE:
<pre>%{
`#`include&lt;stdio.h>
int intcount=0,floatcount=0,charcount=0,doublecount=0;
%}</pre>
<pre>ID [a-zA-Z][a-zA-Z0-9]*
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
&lt;DEFN>{ID}"," {intcount++;printf("%s\n",yytext);}
&lt;DEFN>{ID}";" {intcount++;BEGIN 0;printf("%s\n",yytext);}
{F} {BEGIN DEFN2;}
&lt;DEFN2>{ID}"," {floatcount++;printf("%s\n",yytext);}
&lt;DEFN2>{ID}";" {floatcount++;BEGIN 0;printf("%s\n",yytext);}
{C} {BEGIN DEFN3;}
&lt;DEFN3>{ID}"," {charcount++;printf("%s\n",yytext);}
&lt;DEFN3>{ID}";" {charcount++;BEGIN 0;printf("%s\n",yytext);}
{D} {BEGIN DEFN4;}
&lt;DEFN4>{ID}"," {doublecount++;printf("%s\n",yytext);}
&lt;DEFN4>{ID}";" {doublecount++;BEGIN 0;printf("%s\n",yytext);}
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
</pre>		
###COMPILE:
<pre>lex 3.l
gcc lex.yy.c -ll
./a.out 10.c
</pre>
###OUTPUT:
<pre>The identifiers are:
name;
at;
burst;
wait;
tat;
remaining;
flag;
n,
n1;
tq,
t,
i,
temp,
ch;
break;
i;
n;
i,
j,
no,
k,
min;
tbt;
i,
n;
n;
n;
name,
at,
burst,
wait,
n;
n;
algorithm,
stwt,
sttat,
sawt,
n1;
n1;
tq;
remaining;
remaining;
temp;
n1;
n1;
n1;
n1;
burst,
wait,
algorithm,
rawt,
the no. of int identifiers are 46
the no. of float identifiers are 4
the no. of char identifiers are 1
the no. of double identifiers are 0
</pre>
