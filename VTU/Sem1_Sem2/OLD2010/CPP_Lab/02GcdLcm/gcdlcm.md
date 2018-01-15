##Aim:
###Design, develop and execute a program in C to implement Euclid's algorithm to find the GCD and LCM of two integers and to output  the results along with the given integers.

##Summary:
>In its simplest form, Euclid's algorithm starts with a pair of positive integers, and forms a new pair that consists of the smaller number and the difference between the larger and smaller numbers. 

> The process repeats until the numbers in the pair are equal. That number then is the greatest common divisor of the original pair of integers.

>The main principle is that the GCD does not change if the smaller number is subtracted from the larger number. For example, the GCD of 252 and 105 is exactly the GCD of 147 (= 252 - 105) and 105. Since the larger of the two numbers is reduced, repeating this process gives successively smaller numbers, so this repetition will necessarily stop sooner or later - when the numbers are equal (if the process is attempted once more, one of the numbers will become 0).

>Euclid's Algorithm can thus be simplified by finding the remainder of the two integers and forms a new pair consisting of the divisor and the remainder. 

>Also to calculate the LCM of any two numbers m and n, following formula can be used if GCD of the two numbers, GCD(m,n) is already known.
<pre><code>LCM(m,n) = (m*n)/GCD(m,n)</code></pre>

>To illustrate the extension of Euclid's algorithm, consider the computation of gcd(120, 23), which is shown in the table below. Notice that the quotient in each division is recorded as well alongside the remainder. In this example, the divisor in the last  line (which is equal to 1) indicates that the gcd is 1; that is, 120 and 23 are coprime (also called relatively prime).

>     Iteration  Dividend  Divisor Remainder  Quotient

>        1         120       23       5         5

>        2         23        5        3         4

>        3         5         3        2         1

>        4         3         2        1         1

>        5         2         1        0         2

>        6         1         0


##Algorithm:
1.  Start.
2.  Take two numbers as input a and b.
3.  If both input numbers are 0 then print error message, go to step 9, else to step 4.
4.  Take x=a and y=b. 
5.  When y is not 0
		
           do   
	         rem=x%y;
             x=y;             
             y=rem;

6.  The final value of X is GCD.
7.  LCM is computed by    
           (a*b)/GCD.
8.  Print the values of GCD and LCM.
9.  Stop.

##Program: Gcdlcm.c
	
	#include<stdio.h>
	#include<stdlib.h>
	
	int main()
	{
		int x,y,a,b,rem,lcm,gcd;
		
		// taking inputs
		printf("Enter the two numbers\n");
		scanf("%d%d",&a,&b);  
		
		// statement verifying values of a and b for zero
      	if(a==0 && b==0) 
		{
			printf("GCD doesn't Exist\n");
		}
		else
		{
            // assigning value of a to x		  
			x=a; 
			
			// assigning value of b to y
			y=b; 
		
		    // loop computing GCD using Euclids algorithm      
     		while(y!=0)  
		    {
			    rem=x%y;
			    x=y;
			    y=rem;
		    }
		
		    // final value of x when y=0 is GCD
		    gcd=x;  

            // computing LCM
     		lcm=(a*b)/gcd; 

     	    printf("The GCD and LCM of %d and %d is %d and %d\n",a,b,gcd,lcm);
           
           // prining GCD and LCM of given integer
		}
		
		return 0;
	}

## Output:

Run the following commands in your terminal:
####gcc Gcdlcm.c
####./a.out
     1.Enter the two numbers
       0 0
       GCD doesn't exist
####gcc Gcdlcm.c
####./a.out
    2: Enter the two numbers
       64   48
       GCD and LCM of 64 and 48 is 16 and 192
####gcc Gcdlcm.c
####./a.out
    3: Enter the two numbers
       5   0
       GCD and LCM of 5 and 0 is 5 and 0
