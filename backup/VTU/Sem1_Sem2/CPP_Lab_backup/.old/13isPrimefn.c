/***************************************************************************
*File		: 13isPrime.c
*Description	: Program to check whether the given integer is a Prime or not
*Author		: Prabodh C P
*Compiler	: gcc 4.4.3 compiler, Ubuntu 10.04
*Date		: Tuesday, August 21 2012
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int fnisPrime(int);

/***************************************************************************
*Function	: main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	int iVal,iFlag;

	printf("\n******************************************************");
	printf("\n*\tPROGRAM TO IMPLEMENT TEST OF PRIMALITY\t     *\n");
	printf("******************************************************");

	printf("\nEnter the value to be checked\n");
	scanf("%d",&iVal);

    iFlag = fnisPrime(iVal);

    if(1 == iFlag)
    {
        printf("\nThe entered value %d is a prime number\n",iVal);
    }
    else if(0 == iFlag)
    {
        printf("\nThe entered value %d is not a prime number\n",iVal);
    }

	return 0;
}


/***************************************************************************
*Function		: fnisPrime
*Description		: Function to check whether a number is prime or not
*Input parameters	:
*	int iX	- value to be checked whether prime or not
*RETURNS		:
	1 if the number is prime and
	0 otherwise
***************************************************************************/

int fnisPrime(int iX)
{
	int iLimit = iX-1;  //(int)sqrt(iX);
	int i;
	if(1 == iX)
  	{
  	      printf("\n1 is neither prime nor composite\n");
  	      exit(0);
  	}
	for(i = 2; i<= iLimit ;i++)
	{
		if( 0 == iX % i )
		{
			return 0;
		}
	}
	return 1;
}
