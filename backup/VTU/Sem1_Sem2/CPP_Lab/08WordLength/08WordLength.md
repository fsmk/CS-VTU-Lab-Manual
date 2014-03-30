## Aim:
### Design, develop and execute a program in C to compute and print the word length on the host machine.

## Summary:  
>The word size of a computer generally indicates the bit length of the largest integer it can process in a single instruction, and the size of a memory address, which is usually, but not necessarily the same as the integer size.
The C/C++ standard does not specify the size of integral types in bytes, but it specifies minimum ranges they must be able to hold.
The word size can be inferred using predefined architecture/OS/compiler macros provided by the compiler. The below program finds out virtually the word size used by the compiler.

>Lets assume that the word size of the target machine is 8 , (we can consider 16,32 or 64, but we are lazy to write so many zeros in examples)
 
>So the integer in that machine will be represented with 8 bits, lets use unsigned integer to utilize the sign bit as well. 
 
>now to make an unsigned integer have all 1's in it, we can apply one of the 4 hacks listed below,
>1) i = ~0;
>2) i = -1;
>3) i = (2^8)-1;
>4) i= UINT_MAX;
 
>1) take negation of 00000000 that is 11111111

>2) -1 in 2's compilemt is 11111111  

>3) Obvious , but not practical in our case, as we are finding the word lenght, we do not know it beforehand . the value would be 255

>4) Again not practical in our case, asking the compiler to provide the max value is like cheating right? :P

>Now we have the max unsigned integer variable in our hand, lets destroy every single bit of it , one bit at a time and keep a count of it. when we reach the situation where nothing is left to destroy, the count holds the value of the word lenght 
 
 
>i=~0 in different word sizes

>bits		--> base 10	     --> base 2	

>8  		--> 255          --> 11111111

>16 		--> 65535	 --> 1111111111111111

>32 		--> 4294967295	 --> 11111111111111111111111111111111

## Algorithm:
	1) start
	2) initialize len=0
	3) i=find negation of 0 
	4) if i is not 0
		 go to step5
	   else
		 got ot step 8
	5) i = i>>1
	6) len= len +1
	7) goto step 4
	8) print len
	9) stop
  
## Program: wordlength.c

	#include<stdio.h>
	#include<stdlib.h>

	int main(void)
	{

		int iLen=0;
		unsigned int i=~0;

		for(i = 1; i != 0; i = i << 1)
		{

			iLen++;
		}

		printf("\n\nThe Word length of the host machine is %d bits\n\n", iLen);
		return 0;
	}


## Output:

Run the following commands in your terminal:<br>
####gcc wordlength.c
####./a.out

The Word length of the host machine is 32 bits
