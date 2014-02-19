##Aim:
###Design, develop and execute a program in C to evaluate the given polynomial    f(x) = a4x4 + a3x3 + a2x2+ a1x + a0   for given value of x and the coefficients using Horner’s method.

##Summary:
>Horner's method of polynomial evaluation is described below

>The expression is broken down  in the following way

>f(x) =  a4x4 +  a3x3 + a2x2 + a1x + a0

>f(x) =  x ( a4x3 +  a3x2 + a2x + a1 ) + a0

>f(x) =  x (  x(   a4x2 +  a3x2 + a2 )  + a1 ) + a0

>f(x) =  x (  x(   x ( a4x +  a3 ) + a2 )  + a1 ) + a0

>f(x) =  x (  x(   x (   x (  a4 )  +  a3 ) + a2 )  + a1 ) + a0


###Example:

>Input values:

>x=6

>a0=5, a1=4, a2=3, a3=2, a4=1

>sum =    a4  * x   		→  1 * 6 		→ 6

>sum =    ( sum + a3 )  * x	→  ( 6 + 2 ) * 6 	→ 48

>sum =    ( sum + a2 )  * x 	→  ( 48  + 3 ) * 6	→  306

>sum =    ( sum + a1 )  * x 	→  ( 306  + 4 ) *6	→  1860


##Algorithm:
1.  Start
2.  Input the degree and value of x
3.  Input Coefficients , upper limit is provided  by the value of degree
4.  i= degree,  sum =0
5.  sum = ( sum + ai ) * x
6.  decrement i by 1
7.  if ( i> 0 ) goto step 5
8.  add a0 to the final sum
9.  display sum
10. Stop

##Program: polynomial.c
	
	#include<stdio.h>
	#include<stdlib.h>
	#include<math.h>
	
	int main(void)
	{
	    int deg,i,Arr[10];
	    float x,Sum=0;
	    printf("\nEnter the degree of the polynomial and value of x\n");
	    scanf("%d%f",&deg,&x); //taking input value of degree and x //
	    printf("\nEnter the coefficients in descending order of degree\n");
	    for(i=0;i<=deg;i++)
	    {
	        scanf("%d",&Arr[i]);
	    }    // taking co-efficient value polynomial //
	
	    for(i=deg;i>0;i--)
	    {
	        Sum=(Sum + Arr[i])*x;
	    }   //evaluating polynomial using Horner’s method//
	    Sum = Sum + Arr[0]; //adding sum to higher degree co-efficient //
	    printf("\nValue of polynomial after evaluation=%g\n",Sum);
	    //printing the result//
	    return 0;
	}
	
## Output:

Run the following commands in your terminal:<br>
###gcc –lm polynomial.c
###./a.out

	1:	Enter the degree of the polynomial and value of x
		5
		2
		Enter the coefficients in descending order of degree
		6 5 4 3 2 1
		Value of polynomial after evaluation=120.000000



###gcc –lm polynomial.c
###./a.out

	2: 	Enter the degree of the polynomial and value of x
		4 1
		Enter the coefficients in descending order of degree
		1 2 3 4 5
		Value of polynomial after evaluation=15.000000
