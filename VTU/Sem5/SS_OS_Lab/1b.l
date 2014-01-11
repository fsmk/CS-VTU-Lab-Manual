%{
#include<stdio.h>
int c=0;
%}
%x COMMENT
%%
"//".* {c++;}
"/*".* {BEGIN COMMENT;}
<COMMENT>. ;
<COMMENT>\n ;
<COMMENT>"*/" {BEGIN 0;c++;}
%%
int main(int argc,char **argv)
{
	if(argc!=3)
	{
		printf("No file\n");
		return 0;
	}
	else
	{
		yyin=fopen(argv[1],"r");
		yyout=fopen(argv[2],"w");
		yylex();
		printf("Number of comments is %d\n",c);
	}
}
