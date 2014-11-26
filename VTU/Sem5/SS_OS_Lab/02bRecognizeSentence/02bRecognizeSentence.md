#AIM:
Program to recognize whether a given sentence is simple or compound.
##DESCRIPTION:
The user is expected to develop a code which recognizes a sentence as either simple or compound.The design considers that we use and, or, but & between.The user can specify more rules as per his/her choice.

##CODE:
	%{
	#include <stdio.h>
	#include <stdlib.h>
	int flag=0;
	%}
	%%
	("AND")|("OR")|("and")|("or")|("but")|("between")|("BUT")("BETWEEN") {flag=1;}
	[\n]	;
	. ;
	%%
	main()
	{
		printf("Enter a sentence\n");
		yylex();
		if(flag){
			printf("It's a compound statement\n");
		}else{
			printf("It's not a compound statement\n");
		}
		exit(EXIT_SUCCESS);

	}
##OUTPUT:
<pre>Enter a sentence
hi and bye
Its a compound sentence</pre>

<pre>Enter a sentence
anand
Its a simple sentence</pre>


