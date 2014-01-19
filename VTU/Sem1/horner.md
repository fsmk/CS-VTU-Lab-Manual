## Aim: A program to implement Horners method for polynomial evaluation.

## Theory

> The main principle used in this program is Horner's method. Horner's Method is a way of expressing a polynomial f(x) which eliminates all exponentiations.  By eliminating exponentiations, we eliminate re–doing some calculations. It is named after a british mathamatician William George Horner.This method is used to convert between different positional number system.

## Algorithm :

1. Start.
2. Input the value of the degree.
3. Input the value of the coefficients.
4. Input the value of x.
5. Compute sum=(sum+arr[i])*x
6. Compute sum=sum+arr[deg]
7. Stop.

## Program Source Code:

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(void)
{

        int iDeg,i,iaArr[10];
        float fX,fSum=0;

        printf("\n*********************************************************************");
        printf("\n*\tPROGRAM TO EVALUATE A POLYNOMIAL USING HORNERS METHOD\t    *\n");
        printf("*********************************************************************");

        printf("\nEnter the degree of the polynomial and value of x\n");
        scanf("%d%f",&iDeg,&fX);

        printf("\nEnter the coefficients in descending order of degree\n");
        for(i=0;i<=iDeg;i++)
        {
                scanf("%d",&iaArr[i]);
        }

        for(i=0;i<iDeg;i++)
        {
		fSum=(fSum+iaArr[i])*fX;
        }

        fSum = fSum + iaArr[iDeg];

        printf("\nValue of polynomial after evaluation=%g\n",fSum);

        return 0;
}

## Output:

#Compilation:
1. Open terminal tab for compilation.
2. type gcc filename.c
3. Type compilation command(./a.out)

/***************************************************************************
       SAMPLE OUTPUT FOR THE HORNERS METHOD TO FIND THE POLYNOMIAL
***************************************************************************/

#Output 1

Enter the value of the degree
4
Enter the value of the coefficient
1 2 3 4 4
Entre the value of x
2
The value of the polynomial is 113

#Outut 2

Enter the value of the degree
4
Enter the value of the coefficient
1 7 2 5 3 
Entre the value of x
2
The value of the polynomial is 111
