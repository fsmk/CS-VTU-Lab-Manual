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
	int iNum,iRev = 0,iTemp,iDig,iSum=0;

	printf("\n**************************************************************************");
	printf("\n*\tPROGRAM TO CHECK WHETHER AN INTEGER IS A PALINDROME OR NOT\t *\n");
	printf("**************************************************************************");

	printf("\nEnter a number\n");
	scanf("%d",&iNum);

	iTemp = iNum;

	while(iNum!=0)
	{
		iDig = iNum % 10;
		iSum += iDig;
		iRev = iRev * 10 + iDig;
		iNum = iNum/10;
	}
	printf("\nReversed number is %d",iRev);

	if(iRev == iTemp)
		printf("\nNumber %d is a palindrome\n",iTemp);
	else
		printf("\nNumber %d is not a palindrome\n",iTemp);

	printf("\nSum of digits of the given number is %d\n",iSum);

	return 0;
}

