##Aim:
###Design, develop and execute a program in C to calculate the approximate value of exp (0.5) using the Taylor Series expansion for the exponential function. Use the terms in the expansion until the last term is less than the machine epsilon defines as FLT_EPSILON in the header file <float.h>. Print the value returned by the Mathematical function exp ( ) also.

##Algorithm:
1. Start
2. Taylor’s series expansion
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

###gcc –lm Taylor.c
###./a.out

    Value of exp(0.5) after evaluation = 1.648721

    Value of exp(0.5) using built in function = 1.648721
