/***************************************************************************
*File		: 04Horner.c
*Description	: Program to implement Horners method for Polynomial evaluation
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 8.10
*Date		: 7 September 2010
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/***************************************************************************
*Function	: main
*Input parameters: none
*RETURNS	: 0 on success
***************************************************************************/

int main(void)
{

	int iDeg,i,iaCoeff[10];
	float fX,fSum=0;

	printf("\n*********************************************************************");
	printf("\n*\tPROGRAM TO EVALUATE A POLYNOMIAL USING HORNERS METHOD\t    *\n");
	printf("*********************************************************************");

	printf("\nEnter the degree of the polynomial and value of x\n");
	scanf("%d%f",&iDeg,&fX);

	printf("\nEnter the coefficients \n");
	for(i=0;i<=iDeg;i++)
	{
		scanf("%d",&iaCoeff[i]);
	}

	for(i=0;i<iDeg;++i)
	{
	fSum = (fSum + iaCoeff[i])*fX;
	}

	fSum = fSum + iaCoeff[iDeg];


	printf("\nValue of polynomial after evaluation=%f\n",fSum);

	return 0;
}

