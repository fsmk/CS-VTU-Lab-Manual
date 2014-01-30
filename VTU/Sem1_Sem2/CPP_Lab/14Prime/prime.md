##Aim:
###Design, develop and execute a parallel program in C to determine and print the prime numbers which are less than 100 making use of algorithm of the Sieve of Eratosthenes.

##Summary:

##Algorithm:
1. Start
2. Input the value of n, from i=2 upto n store the value in an array.
3. Set the number of threads.
4. From k=2 to sqareroot of n
		When array element at k is not 0
		For all multiples of k*k assign 0, increment k.
5. From i=2 to n,
		Print the numbers of array which is not 0.
6. Stop.

##Program:

	#include<omp.h>
	#include<stdio.h>
	#include<math.h>
	int main(void)

	{   
		int a[200];
		int n,i,k;

		printf("Enter the value of n:\n");
		scanf("%d",&n);  // Input value//

		for(i=2;i<=n;i++)
		{
			a[i]=i;  //Storing the number into array upto n//
		}

		omp_set_num_threads(5); //Setting up threads//
		for(k=2;k<=sqrt(n);k++)
		{
        		if(a[k]!=0)
              		{
				#pragma omp parallel for private(i)
				for(i=k*k;i<=n;i=i+k)  //Assigning 0 	to multiples// 
				{
		printf("\nThread id=%d makes %d position   
          zero",omp_get_thread_num(),i);				
					a[i]=0;
				}	
        		}
		}	
		printf("\nPrime numbers are \n");
		for(i=2;i<=n;i++)
		{
			if(a[i]>0)
		printf("%d\t",a[i]); //Printing prime numbers//
		}
		printf("\n");
		return 0;
	}


##Output:

###gcc prime.c –fopenmp –lm
###./a.out

    Enter the value of n:  25

    Thread id=0 makes 4 position zero

    Thread id=3 makes 22 position zero

    Thread id=3 makes 24 position zero

    Thread id=0 makes 6 position zero

    Thread id=0 makes 8 position zero

    Thread id=1 makes 10 position zero

    Thread id=1 makes 12 position zero

    Thread id=1 makes 14 position zero

    Thread id=2 makes 16 position zero

    Thread id=2 makes 18 position zero

    Thread id=2 makes 20 position zero

    Thread id=0 makes 9 position zero

    Thread id=0 makes 12 position zero

    Thread id=1 makes 15 position zero

    Thread id=1 makes 18 position zero

    Thread id=2 makes 21 position zero

    Thread id=2 makes 24 position zero

    Thread id=0 makes 25 position zero

    Prime numbers are 

	2	3	5	7	11	13	17	19	23	
