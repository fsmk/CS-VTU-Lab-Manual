## Aim:
## Design, develop and execute a program in C to reverse a given four    digit integer number and check whether it is a palindrome or not. Output the given number with suitable message.

## Summary:
>Palindrome is a number, word, phrase, or sequence that reads the same backward as forward, e.g., "madam" or "malayalam" or 1221 or 10301.

## Algorithm:

1. Start.
2. Take a four digit number as input i.e. n.
3. Assign value of n to m (to retain the value of n)
4. Until the value of n is not 0.

           Do    
           rem=n%10;        
           rev=rev*10+rem;
           n=n/10;

5. When value of m is equal to rev, go to step 6, else to 8.
6. Print given number as palindrome, goto step 8
7. Print given number as not palindrome.  
8. Stop.

## Program: Palindrome.c
   
	#include<stdio.h>
	void main()
	{
		int n,m,rem,rev=0;
		printf("Enter the number\n");
		scanf("%d",&n); // taking input //
		m=n;   // assigning value of n to m //
		while(n!=0)
		{                  //reversing the integer //
			rem=n%10;        
			rev=rev*10+rem;
			n=n/10;
		}

		printf("The reverse of %d is %d\n",m,rev);  
               // printing the reversed integer //                        
	
		if(m==rev)  //executes when reversed integer is same as given integer //
			printf("It is a palindrome\n");
		else   // executes when not equal //
			printf("It is not a palindrome\n");
	}	

## Output:

Run the following commands in your terminal:<br>

###gcc palindrome.c
###./a.out

        1. Enter the number
           7667
           Reverse of 7667 is 7667
           It is a palindrome



###gcc palindrome.c 
###./a.out

       2.  Enter the number
           1234
           Reverse of 1234 is 4321
           It is not a palindrome
