##Aim:
###Design, develop and execute a program in C to calculate the approximate value of exp (0.5) using the Taylor Series expansion for the exponential function. Use the terms in the expansion until the last term is less than the machine epsilon defines as FLT_EPSILON in the header file <float.h>. Print the value returned by the Mathematical function exp ( ) also.

##Summary:
>In mathematics, a Taylor series is a representation of a function as an infinite sum of terms that are calculated from the values of the function's derivatives at a single point.		

>Exponential formula:

>Sigma (n=0 to infinity) of ((x^n)/n!)
>where ^ = power , ! = factorial

>(x^0)/0! + (x^1)/1! + (x^2)/2! + ....


>Now obviously we cannot go on till infinity expanding this equation. we have to stop somewhere to get aproximate acceptable answer.
We define this termination condition with the fact that our computer has a minimum limit on which the floating operations take place.beyond this limit the values are not representable. This limit is called FLT_EPSILON.  The values less than FLT_EPSILON is virtually 0.
>define FLT_EPSILON 1.19209290E-07F // decimal constant
FLT_EPSILON the minimum positive number such that, 1.0 + FLT_EPSILON != 1.0 // do not apply your math here, this is hardware/compiler dependent ;-)

>When the value of one of the component of the above Taylor expression ( (x^n) / n!  ) gets equal to zero, or technically less than FLT_EPSILON we stop the calculation and print the answer.

##Algorithm:
1. Start
2. Taylor's series expansion
		Let sum=0, x=0.5
3. Do num=pow(x,i), where value of i=1,2,3,4,5.......  (for numerator)
4. Calculate deno=factorial of k, where k ranges from 1 to i  (for denominator)
5. Calculate num/den 6. Repeat step 2,3,4 till the value is less than FLT_EPSILON
7. Stop.

##Program: Taylor.c

	#include<stdio.h>
	#include<float.h>
	#include<stdlib.h>
	#include<math.h>

	int main(void)
	{

        	int i,k;
        	float X,Sum,Numer,Deno,Fact,Val;

        	Sum = 0;
        	X = 0.5;


        	for(i=1;i;i++)
        	{
                	Numer = pow(X,i);
                       /*COMPUTE FACTORIAL*/
                	Fact = 1;
                	for(k=1;k<=i;k++)
                        	Fact *= k;

                	Deno = Fact;
                	Val = (Numer/Deno);
                	Sum += Val;
                	if(Val < FLT_EPSILON)
                        	break;
        	}                /*ADD FIRST TERM IN THE SERIES*/
        	Sum += 1;
     		printf("\nValue of exp(0.5) after evaluation = %f\n",Sum);

        	printf("\nValue of exp(0.5) using built in function = %f\n",exp(0.5));
        	return 0;
	}

##Output:

###gcc -lm Taylor.c
###./a.out

    Value of exp(0.5) after evaluation = 1.648721

    Value of exp(0.5) using built in function = 1.648721
