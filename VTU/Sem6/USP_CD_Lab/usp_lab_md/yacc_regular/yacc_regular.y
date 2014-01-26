%{
/** 
Yacc program to recognise a regular expression
and produce a parse tree as output
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

/* To store the productions */
#define MAX 100

int getREindex ( const char* );

signed char productions[MAX][MAX];
int count = 0 , i , j;
char temp[200] , temp2[200];
%}

 
%token ALPHABET

%left '|'
%left '.'
%nonassoc '*' '+'
%start S
%%
S : re '\n' { 
printf ( "This is the rightmost derivation--\n" );
for ( i = count - 1 ; i >= 0 ; --i ) {
if ( i == count - 1 ) {
printf ( "\nre => " );
strcpy ( temp , productions[i] );
printf ( "%s" , productions[i] );
}
else {
printf ( "\n => " );
j = getREindex ( temp );
temp[j] = '\0';
sprintf ( temp2 , "%s%s%s" , temp , 
productions[i] , (temp + j + 2) );
printf ( "%s" , temp2 );
strcpy ( temp , temp2 );
}
}
printf ( "\n" );
exit ( 0 ); 
}
re : ALPHABET { 
temp[0] = yylval; temp[1] = '\0';
strcpy ( productions[count++] , temp );
}
| '(' re ')' 
{ strcpy ( productions[count++] , "(re)" ); }
| re '*' 
{ strcpy ( productions[count++] , "re*" ); }
| re '+' 
{ strcpy ( productions[count++] , "re+" ); }
| re '|' re 
{strcpy ( productions[count++] , "re | re" );}
| re '.' re 
{strcpy ( productions[count++] , "re . re" );}
;
%%
int main ( int argc , char **argv ) 
{
/* 
Parse and output the rightmost derivation,
from which we can get the parse tree 
*/
yyparse();

return 0;
}

yylex() 
{
signed char ch = getchar();
yylval = ch;
if ( isalpha ( ch ) )
return ALPHABET;
return ch;
}

yyerror() 
{
fprintf(stderr , "Invalid Regular Expression!!\n");
exit ( 1 );
}

int getREindex ( const char *str ) 
{ 
int i = strlen ( str ) - 1;
for ( ; i >= 0 ; --i ) {
if ( str[i] == 'e' && str[i-1] == 'r' )
return i-1;
}
}
/*
Output:./a.out
a+|b*|(b.c*)
This is the rightmost derivation--

re => re | re
 => re | (re)
 => re | (re . re)
 => re | (re . re*)
 => re | (re . c*)
 => re | (b . c*)
 => re | re | (b . c*)
 => re | re* | (b . c*)
 => re | b* | (b . c*)
 => re+ | b* | (b . c*)
 => a+ | b* | (b . c*)
*/

