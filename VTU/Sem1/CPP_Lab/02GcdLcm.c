/*****************************************************************
* Problem Statement:
* Design, develop and execute a program in C to implement Euclid’s 
* algorithm to find the GCD and LCM of two integers and to output 
* the results along with the given integers.
*****************************************************************/

/*****************************************************************
* Summary:
* In its simplest form, Euclid's algorithm starts with a pair of 
* positive integers, and forms a new pair that consists of the smaller 
* number and the difference between the larger and smaller numbers. 
* The process repeats until the numbers in the pair are equal. That 
* number then is the greatest common divisor of the original pair of 
* integers.
* The main principle is that the GCD does not change if the smaller 
* number is subtracted from the larger number. For example, the GCD 
* of 252 and 105 is exactly the GCD of 147 (= 252 − 105) and 105. 
* Since the larger of the two numbers is reduced, repeating this process 
* gives successively smaller numbers, so this repetition will necessarily 
* stop sooner or later — when the numbers are equal (if the process 
* is attempted once more, one of the numbers will become 0).
* Euclid’s Algorithm can thus be simplified by finding the remainder 
* of the two integers and forms a new pair consisting of the divisor 
* and the remainder. 
*
* Also to calculate the LCM of any two numbers m and n, following 
* formula can be used if GCD of the two numbers, GCD(m,n) is already 
* known.
*	
*	LCM(m,n) = (m*n)/GCD(m,n)
*
* To illustrate the extension of Euclid's algorithm, consider the 
* computation of gcd(120, 23), which is shown in the table below. 
* Notice that the quotient in each division is recorded as well 
* alongside the remainder. In this example, the divisor in the last 
* line (which is equal to 1) indicates that the gcd is 1; that is, 
* 120 and 23 are coprime (also called relatively prime).
*
* 
*
* Iteration Dividend Divisor Remainder Quotient
*     1       120      23        5        5
*     2        23       5        3        4
*     3         5       3        2        1
*     4         3       2        1        1
*     5         2       1        0        2
*     6         1       0
*
*****************************************************************/

/*****************************************************************
* Algorithm:
*
* 1. Take the inputs i.e. m and n, the numbers for which GCD and LCM 
* needs to be found.
* 2. If both m and n are equal to 0, then print “GCD doesn’t exist”. 
* Go to step 9.
* 3. If n is equal to 0, then go to step 6. Else calculate 
* reminder = m (mod) n. 
* 4. Assign m=n and n = reminder.
* 5. If new value of n is 0, then go to step 6, else go back to step 3.
* 6. GCD= m. Print the value of GCD.
* 7. LCM =  ( Initial value of m * initial value of n) /GCD
* 8. STOP
*****************************************************************/

/*****************************************************************
* Example:
* a) If m = 10, n = 15
* Iteration Dividend Divisor Remainder Quotient
*     1        10       15       10       0
*     2        15       10        5       1
*     3        10        5        0       2
*     4         5        0 
*
* Hence, GCD = m = 5. 
* LCM = (Initial m *Initial n)/GCD = (10*15)/5 = 30.
*
*****************************************************************/

/*****************************************************************
* Program:
*****************************************************************/

#include<stdio.h>
#include<stdlib.h>

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

	int iX1,iX2,iY1,iY2,iRem,iGcd,iLcm; printf("\n*********************************************************");
	printf("\n*\tPROGRAM TO FIND GCD & LCM OF TWO NUMBERS\t*\n");
printf("*********************************************************");
	printf("\nEnter two numbers\n");
	scanf("%d%d",&iX1,&iX2);
	if(0 == iX1 && 0 == iX2)
	{
		printf("\nGCD doesn't  exist\n");
		exit(0);	
	}
	else	/*APPLY EUCLID'S ALGORITHM*/
	{
		iY1 = iX1;
		iY2 = iX2;
		while(iY2!=0)
		{
			iRem = iY1%iY2;
			iY1 = iY2;
			iY2 = iRem;
		}
		iGcd = iY1;
		iLcm = (iX1*iX2)/iGcd;
		printf("\nGCD of %d and %d is %d\n",iX1,iX2,iGcd);
		printf("\nLCM of %d and %d is %d\n",iX1,iX2,iLcm);
	}
	return 0;
}

/*****************************************************************
* Output:
*
*
* *********************************************************
*  *	PROGRAM TO FIND GCD & LCM OF TWO NUMBERS	  *
* *********************************************************
* Enter two numbers
* 0 0
*
* GCD doesn't  exist
* *********************************************************
* *	PROGRAM TO FIND GCD & LCM OF TWO NUMBERS	  *
* *********************************************************
* Enter two numbers
* 64 48
*
* GCD of 64 and 48 is 16
*
* LCM of 64 and 48 is 192
*
* *********************************************************
* *	PROGRAM TO FIND GCD & LCM OF TWO NUMBERS	  *
* *********************************************************
* Enter two numbers
* 5 0
*
* GCD of 5 and 0 is 5
*
* LCM of 5 and 0 is 0
*****************************************************************/
