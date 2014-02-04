%{
#include<stdio.h>
int char_count=0,word_count=0,line_count=0,space_count=0;
%}
%%
[^ \t\n]+ {word_count++;char_count+=yyleng;}
\n {line_count++;char_count++;}
" " {space_count++;char_count++;}
. {char_count++;}
%%
int main(int argc,char *argv[])
{
	if(argc>1)
	{
		FILE *file=fopen(argv[1],"r");
		if(!file)
		{
			printf("Error opening %s\n",argv[1]);
			exit(1);
		}
		yyin=file;
	}
	yylex();
	printf("line count is %d\n",line_count);
	printf("word count is %d\n",word_count);
	printf("space count is %d\n",space_count);
	printf("character count is %d\n",char_count);
	return 0;
}		
