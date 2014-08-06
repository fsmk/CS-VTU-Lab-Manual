/***************************************************************************
*File		: Quadratic.c
*Description	: Program to find the roots of a Quadratic Equation
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 14.04
*Date		: 3 August 2014
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float fnCalcDiscriminant(float, float, float);
/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	float fA,fB,fC,fDesc,fX1,fX2,fRealp,fImagp;
	int iState;

	printf("\n*************************************************************");
	printf("\n*\tPROGRAM TO FIND ROOTS OF A QUADRATIC EQUATION\t    *\n");
	printf("*************************************************************");


	printf("\nEnter the coefficients of a,b,c \n");
	scanf("%f%f%f",&fA,&fB,&fC);
	if(0 == fA)
	{
		printf("\nInvalid input, not a quadratic equation - try again\n");
		exit(0);
	}

	/*COMPUTE THE DESCRIMINANT*/
	fDesc=fnCalcDiscriminant(fA,fB,fC);
	((0 == fDesc) ? (iState = 1):((fDesc > 0) ? (iState = 2) : (iState = 3)));
	switch(iState)
	{
		case 1:
			fX1 = fX2 = -fB/(2*fA);
			printf("\nRoots are equal and the Roots are \n");
			printf("\nRoot1 = %g and Root2 = %g\n",fX1,fX2);
			break;
		case 2:
			fX1 = (-fB+sqrt(fDesc))/(2*fA);
			fX2 = (-fB-sqrt(fDesc))/(2*fA);
			printf("\nThe Roots are Real and distinct, they are \n");
			printf("\nRoot1 = %g and Root2 = %g\n",fX1,fX2);
			break;
		case 3:
			fRealp = -fB / (2*fA);
			fImagp = sqrt(fabs(fDesc))/(2*fA);
			printf("\nThe Roots are imaginary and they are\n");
			printf("\nRoot1 = %g+i%g\n",fRealp,fImagp);
			printf("\nRoot2 = %g-i%g\n",fRealp,fImagp);
	}
	return 0;
}

float fnCalcDiscriminant(float a, float b, float c)
{
	return (b*b-4*a*c);
}

/*
*************************************************************
*       PROGRAM TO FIND ROOTS OF A QUADRATIC EQUATION       *
*************************************************************
Enter the coefficients of a,b,c 
0 1 2

Invalid input, not a quadratic equation - try again
\end{Verbatim}
\textbf{\$./a.out }
\begin{Verbatim}
*************************************************************
*       PROGRAM TO FIND ROOTS OF A QUADRATIC EQUATION       *
*************************************************************
Enter the coefficients of a,b,c 
1 -5 6

The Roots are Real and distinct, they are 

Root1 = 3 and Root2 = 2
\end{Verbatim}
\textbf{\$./a.out }
\begin{Verbatim}
*************************************************************
*       PROGRAM TO FIND ROOTS OF A QUADRATIC EQUATION       *
*************************************************************
Enter the coefficients of a,b,c 
1 4 4

Roots are equal and the Roots are 

Root1 = -2 and Root2 = -2
\end{Verbatim}
\textbf{\$./a.out }
\begin{Verbatim}
*************************************************************
*       PROGRAM TO FIND ROOTS OF A QUADRATIC EQUATION       *
*************************************************************
Enter the coefficients of a,b,c 
1 3 3

The Roots are imaginary and they are

Root1 = -1.5+i0.866025
Root2 = -1.5-i0.866025

*/
