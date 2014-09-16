#AIM:
 Program to count the number of characters, words, spaces and lines 
in a given input file.

##DESCRIPTION:
We have the command 'wc' in UNIX which gives us all the 
number of characters,number of words,number of lines.We are expected to develop a similar utility which does the same using flex.

##FLEX:  flex - the fast lexical analyser generator.




##CODE:

<pre>%{
#include&lt;stdio.h&gt;
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
}</pre>

##COMPILE:
<pre>lex 1a.l
gcc lex.yy.c -ll
./a.out 1a.l</pre>

##OUTPUT:
<pre>line count is 29
word count is 55
space count is 26
character count is 588</pre>
