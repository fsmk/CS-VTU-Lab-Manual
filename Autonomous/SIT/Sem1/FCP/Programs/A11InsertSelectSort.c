/********************************************************************************
*File		: InsertSelectSort.c
*Description	: Program to sort an array using Insertion Sort
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: 22 Nov 2013
********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fnGenRandInput(int [], int);
void fnDispArray( int [], int);
void fnInsertionSort(int [], int);
void fnSelectSort(int [], int);


/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{

	int iaArr[100],iNum;

	printf("\nInsertion Sort\n");
	printf("\nEnter the number of elements to sort\n");
	scanf("%d",&iNum);
	fnGenRandInput(iaArr,iNum);
	printf("\nUnsorted Array\n");
	fnDispArray(iaArr,iNum);
	fnInsertionSort(iaArr,iNum);
	printf("\nSorted Array\n");
	fnDispArray(iaArr,iNum);

	printf("\nSelection Sort\n");
	printf("\nEnter the number of elements to sort\n");
	scanf("%d",&iNum);
	fnGenRandInput(iaArr,iNum);
	printf("\nUnsorted Array\n");
	fnDispArray(iaArr,iNum);
	fnSelectSort(iaArr,iNum);
	printf("\nSorted Array\n");
	fnDispArray(iaArr,iNum);

	return 0;
}

/******************************************************************************
*Function	: fnSelectSort
*Description	: Function to sort elements in an iaArray using Quick Sort
*Input parameters:
*	int A[] - iaArray to hold integers
*	int n	- no of elements in the array
*RETURNS	: no value
******************************************************************************/

void fnSelectSort(int A[], int n)
{
	int i,j,iMinPos,iTemp;
	for(i=0;i<n;i++)
	{
		iMinPos = i;
		for(j=i+1;j<n;j++)
		{
			if(A[j]<A[iMinPos])
				iMinPos = j;
		}
		iTemp = A[i];
		A[i] = A[iMinPos];
		A[iMinPos] = iTemp;
	}
}

/******************************************************************************
*Function	: fnInsertionSort
*Description	: Function to sort an array using Insertion Sort
*Input parameters:
*	int A[] - iaArray to hold integers
*	int n	- no of elements in the array
*RETURNS	: no value
******************************************************************************/

void fnInsertionSort(int A[], int n)
{
	int i, j, iKey;
	for(i=1;i<n;i++)
	{
		iKey = A[i];
		j = i-1;
		while(j>=0 && A[j] > iKey)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = iKey;
	}
}

/******************************************************************************
*Function	: GenRandInput
*Description	: Function to generate a fixed number of random elements
*Input parameters:
*	int X[] - array to hold integers
*	int n	- no of elements in the array
*RETURNS	:no return value
******************************************************************************/

void fnGenRandInput(int X[], int n)
{
	int i;
	srand(time(NULL));
	for(i=0;i<n;i++)
	{
		X[i] = rand()%1000;
	}
}

/******************************************************************************
*Function	: DispArray
*Description	: Function to display elements of an array
*Input parameters:
*	int X[] - array to hold integers
*	int n	- no of elements in the array
*RETURNS	: no return value
******************************************************************************/

void fnDispArray( int X[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf(" %4d \n",X[i]);
}

/*
$ ./a.out 

Insertion Sort

Enter the number of elements to sort
5

Unsorted Array
  845 
  154 
  879 
  668 
  214 

Sorted Array
  154 
  214 
  668 
  845 
  879 

Selection Sort

Enter the number of elements to sort
5

Unsorted Array
  925 
  281 
  200 
  162 
  484 

Sorted Array
  162 
  200 
  281 
  484 
  925 
*/
