##Program : 4b.y
##Aim: 
Program to recognize a valid variable, which starts with a letter, followed by any number of letters or digits.

##Description:
This program checks if the given variable is valid or invalid. A variable should start with a letter followed any no of letters or digits.For example a123 or aa23 or b3455 etc are valid variables.Example for invalid expression 12aa or 1cc etc.

##Code:

    %{
    #include<stdio.h>
    #include<stdlib.h>
    %}
    %token DIGIT ALPHA
    %%
    variable:ALPHA
            |variable ALPHA
            | variable DIGIT 
            ;
    %%
    yyerror()
    {
 	printf("Invalid expression\n");
 	exit(0);
    }
    int main()
    {
 	printf("Enter the variable\n");
 	yyparse();
 	printf("Valid variable\n");
 	return 0;
    }		
        
##Program : 4b.l (Lex Specification)

##Code:
    %{
    #include"y.tab.h"
    %}
    %%
    [0-9]                  return DIGIT;
    [a-zA-Z]               return ALPHA;
    .                      return yytext[0];
    \n                     return 0;
    %%


##Output:
1.Enter the variable

a345

Valid variable

2.Enter the variable

34aaa

Invalid expression
