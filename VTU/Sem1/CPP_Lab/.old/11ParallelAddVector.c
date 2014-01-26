/***************************************************************************
*File		: 11ParallelAddVector.c
*Description	: Program to perform parallel addition of two vectors elementwise
*Author		: Prabodh C P
*Compiler	: gcc 4.4.3 compiler, Ubuntu 10.04
*Date		: Tuesday, August 21 2012
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<omp.h>

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	int iaArr1[10],iaArr2[10],iaSum[10],i, iNum;

	printf("\nEnter The number of elements");
	scanf("%d",&iNum);

	printf("\nEnter The element of 1st array");
	for(i=0;i<iNum;i++)
		scanf("%d",&iaArr1[i]);

	printf("Enter The elements of 2nd array");
	for(i=0;i<iNum;i++)
		scanf("%d",&iaArr2[i]);

	printf("\nThe contents of array A\n");
	for(i=0;i<iNum;i++)
	{
		printf("\niaArr1[%d]=%d",i,iaArr1[i]);

	}

	printf("\nThe contents of array B\n");
	for(i=0;i<iNum;i++)
	{
		printf("\niaArr2[%d]=%d",i,iaArr2[i]);
	}

	printf("\nComputing Sum........\n");

	omp_set_num_threads(5);
	
	#pragma omp parallel for shared(iaSum) private(i)
	for(i=0;i<iNum;i++)
	{
		iaSum[i]=iaArr1[i]+iaArr2[i];
		printf("\niaSum[%d]=%d,thread id=%d\n",i,iaSum[i],omp_get_thread_num());
	}



	printf("\nThe Resultant array is\n");
	for(i=0;i<iNum;i++)
	{
		printf("\tiaSum[%d]=%d\n" ,i , iaSum[i]);
	}
	return 0;
}



/* gcc filename.c -fopenmp
*/
