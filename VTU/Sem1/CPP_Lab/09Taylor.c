/***************************************************************************
*File		: 09Taylor.c
*Description	: Program to evaluate exp(0.5) using Taylor's expansion
*Author		: Prabodh C P
*Compiler	: gcc 4.4.3 compiler, Ubuntu 10.04
*Date		: Tuesday, August 21 2012
***************************************************************************/

#include<stdio.h>
#include<float.h>
#include<stdlib.h>
#include<math.h>

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{

	int i,k;
	float fX,fSum,fNumer,fDeno,faArr[10],fFact,fVal;

	printf("\n*********************************************************************");
	printf("\n*\tPROGRAM TO EVALUATE EXP(0.5) USING TAYLOR'S EXPANSION\t    *\n");
	printf("*********************************************************************");

/*****************************************************************
	exp(x)= 1 + (x/1!) + (x2/2!) + .................
*****************************************************************/

	fSum = 0;
	fX = 0.5F;


	for(i=1;i;i++)
	{
		fNumer = pow(fX,i);

		/*COMPUTE FACTORIAL*/		
		fFact = 1;
		for(k=1;k<=i;k++)
			fFact *= k;

		fDeno = fFact;
		fVal = (fNumer/fDeno);
		fSum += fVal;
		//printf("\nfVal = %f\n",fVal);
		if(fVal < FLT_EPSILON)
			break;
	}
	
	//printf("\nNumber of iterations = %d\n",i);
	printf("\nValue of changed FLT_EPSILON = %f\n",FLT_EPSILON);

	/*ADD FIRST TERM IN THE SERIES*/
	fSum += 1;
	printf("\nValue of exp(0.5) after evaluation = %f\n",fSum);

	printf("\nValue of exp(0.5) using built in function = %f\n",expf(0.5F));
	return 0;
}
