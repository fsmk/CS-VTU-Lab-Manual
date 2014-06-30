/***************************************************************************
*File		: 16MatchAny.c
*Description	: Program to implement String Matching
*Author		: Prabodh C P
*Compiler	: gcc 4.4.3 compiler, Ubuntu 10.04
*Date		: Tuesday, August 21 2012
***************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int fnMatchAny(char [], char []);
//int fnMatchAny(char*, char*);

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	char acStr[100],acSubStr[100];
	int iFound;

	printf("\n****************************************************");
	printf("\n*\tPROGRAM TO IMPLEMENT STRING MATCHING\t   *\n");
	printf("****************************************************");


	printf("\nEnter first string\n");
	gets(acStr);

	printf("\nEnter second string\n");
	gets(acSubStr);

	iFound = fnMatchAny(acStr,acSubStr);

	printf("\nFirst string is\n");
	printf("%s\n",acStr);

	printf("\nSecond string is\n");
	printf("%s\n",acSubStr);

	if(iFound != -1)
		printf("\nCharacter \'%c\' from Second string is found at position %d in the First string\n",acStr[iFound],iFound+1);
	else
		printf("\nMatch not found\n");
	return 0;
}

/***************************************************************************
*Function		: fnMatchAny
*Description		: Function to perform string matching
*Input parameters	:
*	char *s1	- string1 
*	char *s2	- string2 
*RETURNS		: 
	index of first location in string1 where any charecter from string2 occurs
	-1 if string1 contains no charecters from string2 
***************************************************************************/



int fnMatchAny(char s1[], char s2[])
{
	int i,j;
	for(i=0;i<strlen(s1);i++)
	{
		for(j=0;j<strlen(s2);j++)
		{
			if(s1[i] == s2[j])	
				return i;
		}
	}
	return -1;
}
