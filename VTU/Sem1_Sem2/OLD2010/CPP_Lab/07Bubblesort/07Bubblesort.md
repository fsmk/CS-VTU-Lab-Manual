## Aim:
### Design, develop and execute a program in C to input N integer numbers into a single dimension array, sort them in to ascending order using bubble sort technique, and then to print both the given array and the sorted array with suitable headings.

## Summary:
>Bubble sort technique sorts the integers of the array in ascending order. This technique at first compares the first digit with all the remaining digits individually , if the first number is greater than the other number both the numbers are swapped. Then the second number is compared with all the remaining digits leaving the first digits, if it is greater than other number , both numbers are swapped. This process are done for all the numbers except the last digit. The resulting array of digits will be in ascending order.

## Algorithm:
1. Start.
2. Input the size of dimensional array(size=n).
3. Take the input elements to the initialized array.
4. Initialize i=0,j=i+1
5. When a[i]>a[i+1], go to step 6 else to step 8. 
6. Swap elements

 		temp=a[i]
		a[i]=a[j]
		a[j]=temp 

7. Increment i and j upto n-1,Go to step 5;
8. Display sorted array.
9. Stop. 

## Program: bubblesort.c
	#include<stdio.h>
	void main()
	{
	    int n,i,j,a[10],b[10],temp;
	    for(i=0;i<10;i++)
	    {
	        //for removing junk values in the array //
	        a[i]=0;
	        b[i]=0; 
	    }
	
	    printf("\nEnter no of elements\n"); 
	        scanf("%d",&n); //input for size of the array //
	    printf("\nEnter the elements\n"); 
	    for(i=0;i<n;i++) 
	        scanf("%d",&a[i]); // taking array elements //
	    for(i=0;i<n;i++)
	    {
	        b[i]=a[i];           //storing copy of array to an another array //
	    }   
	    //Sorting array using BUBBLESORT method //
	    for(i=0;i<n;i++) 
	    { 
	        for(j=i+1;j<n;j++) 
	        { 
	            if(a[i] > a[j]) 
	            { 
	                temp = a[i]; 
	                a[i] = a[j]; 
	                a[j] = temp; 
	            } 
	        } 
	    }
	    printf("The given array of elements is \n");
	    for(i=0;i<n;i++)
	    {
	        printf("%d\t",b[i]); //prints the input array//
	    }
	    printf("\nThe sorted array of given array is\n");
	    for(i=0;i<n;i++)
	    {
	        printf("%d\t",a[i]); //prints the sorted array // 
	    }
	    printf("\n");
	}   

## Output:

Run the following commands in your terminal:<br>
###gcc bubblesort.c
###./a.out

1:	Enter no of elements
	5

Enter the elements
1 3 5 2 4

The given array of element is
1 3 5 2 4

The Sorted array of the given array is
1 2 3 4 5



###gcc bubblesort.c
###./a.out



2:	Enter no of elements
6

Enter the elements
9 8 6 5 3 4

The given array of element is
9 8 6 5 3 4

The Sorted array of the given array is
3 4 5 6 8 9


