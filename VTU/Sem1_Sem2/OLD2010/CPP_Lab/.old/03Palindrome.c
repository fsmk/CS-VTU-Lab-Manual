/***************************************************************************
*File		: 03Palindrome.c
*Description	: Program to check whether the given integer is a Palindrome or not
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 10.04
*Date		: 4 July 2012
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
	int iNum,iRev = 0,iTemp,iRem;

	printf("\n**************************************************************************");
	printf("\n*\tPROGRAM TO CHECK WHETHER AN INTEGER IS A PALINDROME OR NOT\t *\n");
	printf("**************************************************************************");

	printf("\nEnter a number\n");
	scanf("%d",&iNum);

	iTemp = iNum;

	while(iNum!=0)
	{
		iRem = iNum % 10;
		iRev = iRev * 10 + iRem;
		iNum = iNum/10;
	}
	printf("\nReverse is %d",iRev);

	if(iRev == iTemp)
		printf("\nNumber %d is a palindrome\n",iTemp);
	else
		printf("\nNumber %d is not a palindrome\n",iTemp);

	return 0;
}
