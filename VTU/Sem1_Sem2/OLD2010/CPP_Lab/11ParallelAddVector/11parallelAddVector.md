## Aim:
## Design, develop and execute a parallel program in C to add, elementwise, two one dimensional arrays A and B of N integer elements and to store the result in another one dimensional array C of N integer elements.

## Summary:
>The Program add elements of two one dimensional array elementwise and stores it in another one dimensional array.

## Algorithm:
1. Start.
2. Take input size of the arrays a[ ] and b[ ].
3. Input the elements to these arrays.
4. Set the number of threads.
5. Until size of reaches maxlength -1    
		Perform addition in parallel by mentioning the 
			function within parallel syntax.
6. Get thread numbers for the operations.
7. Print the resultant array.
8. stop.  

## Program: parallelprog.c
	#include<stdio.h>
	#include<stdlib.h>
	#include<omp.h>
	
	int main()
	{
	    int a[20],b[20],add[20],i,n;
	
	    printf("Enter the array size\n");
	    scanf("%d",&n); // input for size of the array //
	
	    printf("Enter elements of array A\n");
	    for(i=0;i<n;i++)
	    scanf("%d",&a[i]); //taking elements of array A //
	
	    printf("Enter elements of array B\n");
	     for(i=0;i<n;i++)
	      scanf("%d",&b[i]); //taking elements of array B //
	    
	    printf("Array elements are\n");
	
	    printf("\tArray A\t\tArray B\n");
	
	    for(i=0;i<n;i++)
	       printf("\ta[%d]=%d\t\tb[%d]=%d\n",i,a[i],i,b[i]);
	       printf("\nComputing Sum...\n");
	
	    //parallel function to perform array addition //
	
	    omp_set_num_threads(5);
	    #pragma omp parallel for private(i)
	    for(i=0;i<n;i++)
	     {
	        int tid=omp_get_thread_num();
	        add[i]=a[i]+b[i]; // adding array A and B //
	        printf("\nRES[%d]=%d, thread_id=%d",i,add[i],tid);
	     }
	
	    printf("\n\nResultant array is\n");
	
	    for(i=0;i<n;i++)
	         printf("%d\n",add[i]);//printing resultant array           //
	
	    return 0;
	}
## Output:

Run the following commands in your terminal:<br>
###gcc parallelprog.c -fopenmp
###./a.out

	Enter the array size
	5
	Enter elements of array A 
	1 2 3 4 5
	Enter elements of array B 
	2 3 4 5 6
	Array elements are
	Array A    Array B
	  a[0]=1        b[0]=2
	  a[1]=2        b[1]=3
	  a[2]=3        b[2]=4
	  a[3]=4	    b[3]=5
	  a[4]=5        b[4]=6
	
	Computing Sum........
	RES[4]=11,		thread id=4
	RES[1]=5,		thread id=1
	RES[2]=7,		thread id=2
	RES[3]=9,		thread id=3
	RES[0]=3,		thread id=0
	
	The Resultant array is
	3
	5
	7
	9
	11

