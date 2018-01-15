## Aim:
### Design and develop a function isprime (x) that accepts an integer argument and returns 1 if the argument is prime and 0 otherwise. The function is to use plain division checking approach to determine if a given number is prime. Invoke this function from the main with different values obtained from the user and print appropriate messages.

## Summary:
>A Prime number is a number which can be divisible by 1 and itself, 1 is neither considered as prime nor non-prime(composite). Here a plain division checking approach is used to determine whether a given number is prime or not. The given number is check for divisibility from 1 to itself, if it is not divisible by any other number other than 1 and itself, then that number is a prime number or else it is not a prime number.  

## Algorithm:
1. Start
2. Take the input integer to be checked
3. Call the isPrime function
4. isPrime function 
			when value=1, print it is niether prime nor 			composite
			from i=2 to value perform x (mod) i
				when x%i is equal to 0,  return 0 else 	return 1
5. when  value return is 1, print  number is prime else step 6.
6. i.e. The return is 0, print number is not prime.
7. Stop

## Program: isprime.c
	#include<stdio.h>
	#include<stdlib.h>
	
	int isPrime(int);

	int main(void)
	{
	        int val,flag;

	        printf("\nEnter the value to be checked\n");
	        scanf("%d",&val); //Taking input//
   
	        flag = isPrime(val);//Calling isprime function//

	        if(flag==1)  //Prints if the number is prime//
	      	printf("\nThe entered value %d is a prime number\n",val);
	
	        else   //Prints if the number is not prime//
	     	 printf("\nThe entered value %d is not a prime number\n",val);

	        return 0;
	}

	int isPrime(int x)
	{
	        int i;
	        if(x==1)  //Executes if the given value is 1//
	        {
	              printf("\n1 is neither prime nor composite\n");
		      exit(0);
	        }
	        for(i = 2; i<x ;i++)
	        {
	                if(x % i==0)// Checks for divisibility//
	                return 0;
	        }
	        return 1;
	}
## Output:

Run the following commands in your terminal:<br>

###gcc isprime.c
###./a.out

	Enter the value to be checked
	1
	1 is neither prime nor composite

###gcc isprime.c
###./a.out

	Enter the value to be checked
	27
	The entered value 27 is not a prime number




###gcc isprime.c
###./a.out

	Enter the value to be checked
	29
	The entered value 29 is a prime number

