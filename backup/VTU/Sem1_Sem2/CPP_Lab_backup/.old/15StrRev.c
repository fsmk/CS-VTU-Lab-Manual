/***************************************************************************
*File		: 15StrRev.c
*Description	: Program to reverse a string in place
*Author		: Prabodh C P
*Compiler	: gcc 4.4.3 compiler, Ubuntu 10.04
*Date		: Tuesday, August 21 2012
***************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//void fnReverse(char *);
void fnReverse(char []);

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{

	char acStr[100];

	printf("\n****************************************************");
	printf("\n*\tPROGRAM TO REVERSE A STRING IN PLACE\t   *\n");
	printf("****************************************************");

	printf("\nEnter a String\n");
	scanf("%s",acStr);

	fnReverse(acStr);

	printf("\nReversed String is\n%s\n",acStr);
	return 0;
}

/***************************************************************************
*Function		: fnReverse
*Description		: Function to reverse a string in place
*Input parameters	:
*	char *s	- string to be reversed 
*RETURNS		: nothing
***************************************************************************/


//void fnReverse(char *s)
void fnReverse(char s[])
{
	char cTemp;
	int i,j;
	i =0;
	j = strlen(s)-1;
	while (i<j)
	{
		cTemp = s[i];
		s[i] = s[j];
		s[j] = cTemp;
		i++;
		j--;
	}
}
