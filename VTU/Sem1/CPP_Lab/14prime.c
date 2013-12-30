#include<omp.h>
#include<stdio.h>
#include<math.h>
int main(void)
{   
	int a[200];
	int n,i,k;


	printf("enter the value of n");
	scanf("%d",&n);
	for(i=2;i<=n;i++)
	{
		a[i]=i;
	}

	omp_set_num_threads(5);
	for(k=2;k<=sqrt(n);k++)
	{
        	if(a[k]!=0)
              	{
			#pragma omp parallel for private(i)
			for(i=k*k;i<=n;i=i+k)
			{
				printf("\nThread id=%d makes %03d position zero",omp_get_thread_num(),i);				
				a[i]=0;
			}	
        	}
	}	


	printf("\nPrime numbers are \n");

	for(i=2;i<=n;i++)
	{
		if(a[i]>0)printf("%d\t",a[i]);
	}
	printf("\n");
	return 0;

}//end of main   
  
   
/* 
to compile
cc prime.c -fopenmp -lm

to run
./a.out

*/
