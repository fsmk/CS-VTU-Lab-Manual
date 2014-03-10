##Aim:
###Design, develop and execute a program in C to copy its input to its output,    replacing each string of one or more blanks by a single blank.

##Summary:
>The program introduces concept of character comparision and also white space characters like ‘\t’ and null characters like ‘\0’. To find and replace all multiple blanks, with a single blank in the string, we will start from second character as current character in the input string and compare it with the previous character and if only both are not spaces, then the current character will stored in the destination string. We will continue this till we reach the end of the input string which is denoted by null character, ‘\0’.

##Algorithm:
1. Start
2. Initialise inspace to 0
3. Take the input string (using gets() function).
4. from i=0 to string length,  go to step 5  else go to step 7
5. When position of i is space, else step 6
		 
	Check if inspace is 0
	
	Assign inspace=1 and print a space, go to step 4	

6. Print the character, go to step 4
7. Stop

##Program: space.c

	#include<stdio.h>
	#include<string.h>
	int main()
	{
	      char c[50];
	      int i,inspace=0;
	      printf("Enter the string with spaces\n");
	      gets(c);   // taking the input string //
	      printf("\n String with only one space\n");
	
	      for(i=0;i<strlen(c);i++)
	      {
			if(c[i]==' ' || c[i]=='\t')// Checks for white spaces//
			{
				if(inspace==0)
				{ 
					//replaces multiple space with single space// 
					inspace=1;  //change the value of inspace//
					printf("%c",32); //32 is the ASCII character of space
				}
			}
			else//prints the text//
			{	
				inspace=0;//change the value of inspace//
				printf("%c",c[i]);
			}
	        }
	     	
		printf("\n");
		return 0;
	}
	
## Output:

Run the following commands in your terminal:<br>
###gcc space.c
###./a.out     
     

	Enter the sentence with space 
	I like          programming in      C.
	String with only one space 
	I like programming in C.                                                                                     
                                              
