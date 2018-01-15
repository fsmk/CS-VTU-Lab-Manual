## Aim:
### Design and develop a function rightrot(x,n) in C that returns the value of the integer x rotated to the right by n bit positions as an unsigned integer. Invoke the function from the main with different values for x and n and print the results with suitable headings. 

## Summary:
>Rightrot is a function used to right rotate a integer for specified number of times. This function shifts all the bits of the digit to next bit in right direction and places the LSB(least significant bit) in MSB(most significant bit) position, specified number of times and returns the value.

## Algorithm:
1. Start.
2. Take a input number below 65536 to rightrot.
3. Take input for number of times of righrot.
4. Call rightrot function.
5. righrot function;
	
	 from i=0 to n-1
	
			When x mod 2 = 0
					Right shift once.
       		Else 
	
					Right shift once and add 32768 to value of x 
					(I.e. append MSB to 1)


6. Return the value of x.
7. Stop.

## Program: rightrot.c
	#include<stdio.h>
	
       // function performing right rotate //
	unsigned int right_rot(unsigned int x,int n)
	{        
	        int i;
	        for(i=1;i<=n;i++)
	        {
	                if(x%2==0)
	                x=x>>1;
	                else 
	                x=x>>1,x+=32768;
	        }
	        return x;
	}
	void main()
	{
	        unsigned int x; 
	        int result,n; 
	        
		    printf("Enter an integer <=65535\n");
	        scanf("%u",&x); 
	
	        printf("Rotate %u how many times: ",x); 
	        scanf("%d",&n);

	        result=right_rot(x,n);
	        printf("Right_rot(%u,%d)=%u\n",x,n,result);
	}   


## Output:

Run the following commands in your terminal:<br>
###gcc rightrot.c
###./a.out

	Enter an integer <=65535
	28
	Rotate 28 how many times
	2
	Right_rot(28,2)=7



###gcc rightrot.c
###./a.out

	Enter an integer <=65535
	4
	Rotate 4 how many times
	3
	Right_rot(4,3)=32768
