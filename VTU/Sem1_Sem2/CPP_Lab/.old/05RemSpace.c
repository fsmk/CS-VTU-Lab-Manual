/***************************************************************************
*File		: 05RemSpace.c
*Description	: Program to replace multiple whitespaces with a single space
*Author		: Prabodh C P
*Compiler	: gcc 4.4.3 compiler, Ubuntu 10.04
*Date		: Tuesday, August 21 2012
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	char acSStr[100],acDStr1[100],acDStr2[100];
	int i=0,j=0,iSpcount=0;
	char cCurChar; 

	printf("\n*************************************************************************");
	printf("\n*\tPROGRAM TO REPLACE MULTIPLE WHITESPACES WITH A SINGLE BLANK\t*\n");
	printf("*************************************************************************");


	printf("\nEnter a Sentence\n");
	gets(acSStr);

	/*REPLACE TABS WITH SPACES*/
	j=0;
	for(i = 0; acSStr[i] != '\0'; i++)
	{	
		cCurChar = acSStr[i];
		if( cCurChar == '\t' )
		{
			cCurChar = ' ';
		}
		acDStr1[j++] = cCurChar;
	}
	/*PLACE A NULL TERMINATOR AT END OF STRING*/
	acDStr1[j] = '\0';

	/*REPLACE MULTIPLE SPACES WITH SINGLE SPACE*/
	j=0;
	for(i = 0; acDStr1[i] != '\0'; i++)
	{
		cCurChar = acDStr1[i];
		if( cCurChar == ' ' )
		{
			iSpcount++;
			if( iSpcount == 1)
			acDStr2[j++] = cCurChar;	
		}
		else
		{		
			iSpcount = 0;
			acDStr2[j++] = cCurChar;
		}

	}   
	/*PLACE A NULL TERMINATOR AT END OF STRING*/
	acDStr2[j] = '\0';

	printf("\nThe Original String is\n");
	puts(acSStr);

	printf("\nThe String without spaces is\n");
	puts(acDStr2);
	return 0;
}
