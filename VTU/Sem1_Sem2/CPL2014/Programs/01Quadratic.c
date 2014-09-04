/**********************************************************************
Copyright 2012
Prabodh C P
Siddaganga Institute of Technology
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
**********************************************************************/
/***************************************************************************
*File		: 01Quadratic.c
*Description	: Program to find the roots of a Quadratic Equation
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 10.04
*Date		: 7 September 2010
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	float fA,fB,fC,fDesc,fX1,fX2,fRealp,fImagp;

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
	fDesc=fB*fB-4*fA*fC;

	if(0 == fDesc)
	{
		fX1 = fX2 = -fB/(2*fA);

		printf("\nRoots are equal and the Roots are \n");
		printf("\nRoot1 = %g and Root2 = %g\n",fX1,fX2);
	}
	else if(fDesc > 0)
	{
		fX1 = (-fB+sqrt(fDesc))/(2*fA);
		fX2 = (-fB-sqrt(fDesc))/(2*fA);
		printf("\nThe Roots are Real and distinct, they are \n");
		printf("\nRoot1 = %g and Root2 = %g\n",fX1,fX2);
	}
	else
	{
		fRealp = -fB / (2*fA);
		fImagp = sqrt(fabs(fDesc))/(2*fA);
		printf("\nThe Roots are imaginary and they are\n");
		printf("\nRoot1 = %g+i%g\n",fRealp,fImagp);
		printf("\nRoot2 = %g-i%g\n",fRealp,fImagp);
	}

	return 0;
}

/*
(1,-5,6)
(1,4,4)
(1,3,3)
*/
