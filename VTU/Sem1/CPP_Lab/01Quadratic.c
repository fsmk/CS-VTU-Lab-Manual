/*****************************************************************
* Problem Statement:
* Design, develop and execute a program in C to find and output all
* the roots of a given quadratic equation, for non-zero coefficients. 
*****************************************************************/

/*****************************************************************
* Summary:  
* Any quadratic equation has two roots and the roots of the equation 
* can be found using the formula
* x = (-b±√discriminant)/2a
* where discriminant = b2-4ac and 
* a,b,c are coefficients when the equation is represented in form ax2+bx+c= 0
*
* Hence as per the equation, if discriminant is equal to 0, then the 
* value of both the roots are equal and real. Also to find x, when 
* discriminant is not 0, we need to find square root of disc. When 
* discriminant * value is less than 0, the square root of the discriminant 
* is imaginary and hence the roots of the equation are supposed to be 
* imaginary and distinct. When discriminant value is greater than 0, 
* the square * root of the discriminant is real and hence the roots of 
* the equation are supposed to be real and distinct.
*****************************************************************/

/*****************************************************************
* Algorithm:
* 1) Take the inputs i.e. coefficients of the equation, a,b,c from the 
* user.
* 2) Calculate the value of discriminant = b2-4ac
* 3) Decide whether roots are equal or distinct. If discriminant is 
* equal to 0, then go to step 4, else go to step 5.
* 4) Calculate x1 and x2.  x1 = x2 = -b/2a. Print roots are real and 
* equal. Then go to step 8.
* 5) Decide whether roots are real or imaginary. If discriminant is 
* lesser than 0, roots are imaginary and go to step 6. If discriminant 
* is greater than 0, roots are real and go to step 7.
* 6) Calculate the roots x1  and x2.  
* X1  = p+qi and x2 =p-qi 
* where p = -b/2a and 
* q = (√(discriminant*-1))/2a. 
* Print roots are imaginary and distinct.
* 7) Calculate the roots x1  and x2.  X1  = (-b+√(discriminant))/2a 
* and x2 =(-b-√(discriminant))/2a. Print roots are real and distinct.
* 8) Print the value of x1 and x2.
* 9) STOP
*****************************************************************/

/*****************************************************************
* Special Notes:
* Since this program uses math.h, we need to compile the program by 
* linking it to the math library in gcc, using the switch '-lm'.
*****************************************************************/

/*****************************************************************
* Examples: 
*
* a) if a=5, b=10 and c =2, then discriminant = b2-4ac = (10)2 -4*5*2 
* = 100-40 = 60.
*
* Since the discriminant is not 0, hence the roots are distinct. Also 
* since discriminant is greater than 0, roots are real. Hence as per 
* step 7, 
* x1 = (-b+√(discriminant))/2a = (-10+√60)/2*5 = (-10+7.746)/10 
* = -2.254/10 = 0.2254.
* x2 = (-b-√(discriminant))/2a = (-10-√60)/2*5 = (-10-7.746)/10 
* = -17.746/10 = -1.7746.
*
* b) if a=2, b=-5 and c =10, then discriminant = b2-4ac = (-5)2 -4*2*10 
* = 25-80 = -55.
*
* Since the discriminant is not 0, hence the roots are distinct. Also 
* since discriminant is lesser than 0, roots are imaginary. Hence as 
* per step 6, 
* x1 =p+qi = -b/2a +.((√(discriminant*-1))/2a)i 
* = -(-5)/2*2 + ((√(-55*-1))/22)i = 1.25 + 0.337i
* x2 = p-qi = -b/2a -.((√(discriminant*-1))/2a)i 
* = -(-5)/2*2 - ((√(-55*-1))/22)i = 1.25 - 0.337i
*****************************************************************/

/*****************************************************************
* Program:
*****************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/*****************************************************************
* Function			: main
* Input parameters	:
*	int argc - no of commamd line arguments
*	char **argv - vector to store command line argumennts
* RETURNS			:
*	0 on success
*****************************************************************/


int main(int argc, char **argv)
{
 float fA,fB,fC,fDesc,fX1,fX2,fRealp,fImagp;

 printf("\n*************************************************************");
 printf("\n*\tPROGRAM TO FIND ROOTS OF A QUADRATIC EQUATION\t *\n");
 printf("*************************************************************");


 printf("\nEnter the coefficients of a,b,c \n");
 scanf("%f%f%f",&fA,&fB,&fC);
 if(0 == fA)
 {
		printf("\nInvalid input not a quadratic equation-try again\n");
		exit(0);
	}

	/*COMPUTE THE DESCRIMINANT*/
	fDesc=fB*fB-4*fA*fC;

	if(0 == fDesc)
	{
		fX1 = fX2 = -fB/(2*fA);

		printf("\nRoots are equal and the Roots are \n");
		printf("\nRoot1 = %f and Root2 = %f\n",fX1,fX2);
	}
	else if(fDesc > 0)
	{
		fX1 = (-fB+sqrt(fDesc))/(2*fA);
		fX2 = (-fB-sqrt(fDesc))/(2*fA);
		printf("\nThe Roots are Real and distinct, they are \n");
		printf("\nRoot1 = %f and Root2 = %f\n",fX1,fX2);
	}
	else
	{
		fRealp = -fB / (2*fA);
		fImagp = sqrt(fabs(fDesc))/(2*fA);
		printf("\nThe Roots are imaginary and they are\n");
		printf("\nRoot1 = %f+i%f\n",fRealp,fImagp);
		printf("\nRoot2 = %f-i%f\n",fRealp,fImagp);
	}

	return 0;
}


/*****************************************************************
* Output:
*
*
* *************************************************************
* *	PROGRAM TO FIND ROOTS OF A QUADRATIC EQUATION	      *
* *************************************************************
* Enter the coefficients of a,b,c
* 1 -4 4
*
* Roots are equal and the Roots are
*
* Root1 = 2.000000 and Root2 = 2.000000
*
*
* *************************************************************
* *	PROGRAM TO FIND ROOTS OF A QUADRATIC EQUATION	      *
* *************************************************************
* Enter the coefficients of a,b,c
* 1 -5 6
*
* The Roots are Real and distinct, they are
*
* Root1 = 3.000000 and Root2 = 2.000000
*
*
* ************************************************************
* *	PROGRAM TO FIND ROOTS OF A QUADRATIC EQUATION	     *
* ************************************************************
* Enter the coefficients of a,b,c
* 1 3 3
*
* The Roots are imaginary and they are
*
* Root1 = -1.500000+i0.866025
*
* Root2 = -1.500000-i0.866025
*****************************************************************/
