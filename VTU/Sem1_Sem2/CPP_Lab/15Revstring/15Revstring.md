##Aim:
###Design and develop a function reverses (s) in C to reverse the string s in place. Invoke this function from the main for different strings and print the original and reversed strings.


##Summary:
>Many operations on strings can be performed, reversing the string is one of the operations which can be performed. At first the given string is copied to another empty temporary string, then in the temporary string, first character of the string and the last character of the string is swapped or interchanged, then the second character and last but one character is swapped, this process is done until the middle element of the string ( In case if the string contains even number of characters , process is done until the middle two elements ). Then the reversed string and the original string are printed.

##Algorithm: 

1. Start.
2. Take an input string.
3. Compute the input string length.
4. Call the reversing function.
5. Initialize variable i=0,and j=string length(input )-1 
6. until i is less than j, go to step 6, else go to step 7
	
          Swap characters        
          temp=a[i];
          a[i]=a[j];
          a[j]=temp;
 
7. Stop.	


##Program:reversestring.c
	#include<stdio.h>
	#include<string.h>
	void reverses(char *);

	void main()
	{
		char a[100];

		printf("Enter the string to be reversed\n");
		scanf("%s",a); // reading string //

		printf("The original string is %s\n",a);
		reverses(a); //calling a function //

		printf("The reversed string is %s\n",a);
	}

	void reverses(char *a) // function to reverse a string //
	{
   	char temp;
   	int i,j;

   	i=0; //initializing i to start bit of string //
   	j=strlen(a)-1; //initializing j to last bit of string //

       
	while(i<j)
        	{    //reversing the string //
	        	temp=a[i];
		 		a[i]=a[j];
		 		a[j]=temp;
		 		i++;
		 		j--;
        	}
	}

##Output:

###gcc reversestring.c
###./a.out 

    1. Enter the string to be reversed
       Munitalp

       The original string is 
       Munitalp

       The reversed string is platinum

