##Aim:
###Design and develop a function matchany (s1,s2) which returns the first location in the string s1 where any character from the string s2 occurs,   or – 1 if s1 contains no character from s2. Do not use the standard library function which does a similar job! Invoke the function matchany (s1,s2) from the main for different strings and print both the strings and the return value from the function matchany (s1,s2).

##Summary:
	
>The  matchany function returns the first location of the character of the second string if it is present in the second string, or else it returns -1. It first checks the first character of the first string with all the characters of the second string(from first to last of second character), if any matches is found it returns the location of that character in the first string, else it searches for the second character , same process is carried on till the last character of the first string if any matches are not found in between.

##Algorithm:

1. Start 
2. Take the input strings
3. Call the function matchany
4. From i=0 to string length, check whether the character in first string    	matches with second string.
5. When match found return the position of character in first string,else 			exit.                                                                                                          
6. Stop
	
##Program: matchany.c

	#include<stdio.h>
	#include<string.h>
	int matchany(char *,char *);
	void main()
	{
	    char a[100],b[100];
	    int f;
	    printf("Enter the first string\n");
	    scanf("%s",a);
	    printf("Enter the second string\n");
	    scanf("%s",b);
	
	    f=matchany(a,b);//calling a function //
	
	    //printing two strings //
	    printf("The First string is\n %s\n",a);  
	    printf("The Second string is\n %s\n",b);     
	
	
	    if(f==-1)  // executes when string does not match //
	     printf("Character did not match\n");
	    else     //prints the matching string with its position //
	     printf("The character %c of the second string is found at position %d of first string\n",b[f],f+1);
	
	}
	
	int matchany(char *a,char *b)   // function to find a match  pattern in string //
	{
		int i,j;
		for(i=0;i<strlen(a);i++)
		{       
		    for(j=0;j<strlen(b);j++)
		    {       
			if(a[i]==b[j])
			return i;   
		    }
		}
		return -1;
	}


##Output :

###gcc matchany.c
###./a.out

        1. Enter the first string 
           book
           Enter the second string
           pencil
           The First string is
           book
           The Second string is
           Pencil

           Character did not match


###gcc matchany.c
###./a.out

        2. Enter the first string 
           computer
           Enter the second string
           machine
           The First string is
           computer
           The Second string is
           machine

           The character c of the second string is found at position 1 of first string
