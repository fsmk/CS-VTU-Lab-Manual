%{
#include"y.tab.h"
extern int yylval;
%}
[0-9]+ {yylval=atoi(yytext);return NUMBER;}
. return yytext[0]
\n return 0;
%%
