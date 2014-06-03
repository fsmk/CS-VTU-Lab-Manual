/******************************************************************************
*File		: MaxMin.c
*Description	: Program to find the maximum and minimum in a given list 
*					of n elements using divide and conquer.
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: 11 Nov 2013
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void fnRecMaxMin(int [], int , int, int*, int*);
/******************************************************************************
*Function	: main
*Input parameters:
*	int argc - no of commamd line arguments
*	char **argv - vector to store command line argumennts
*RETURNS	:	0 on success
******************************************************************************/

int main( int argc, char **argv)
{
	int iaArr[500000],iNum,i;
	int iMax=0,iMin=0;
	printf("\nEnter the size of the array\n");
	scanf("%d",&iNum);
	printf("\nEnter the elements of the array:\n");
	for(i=0;i<iNum;i++)
		scanf("%d",&iaArr[i]);

	fnRecMaxMin(iaArr, 0, iNum-1, &iMax, &iMin);

	printf("\nMax Element = %d\nMin Element = %d\n", iMax, iMin);
	return 0;
}

/******************************************************************************
*Function	: fnRecMaxMin
*Description	: Function to find maximum and minimum elements in an 
					array using Divide and Conquer,
*Input parameters:
*	int a[] - iaArray to hold integers
*	int low	- start index of the array to be sorted
*	int high- end index of the array to be sorted
*	int *max - pointer to hold the max element
*	int *min - pointer to hold the min element
*RETURNS	: no value
******************************************************************************/

void fnRecMaxMin(int a[],int low,int high, int *max, int *min)
{
	int mid,max1,max2,min1,min2;
	if(high-low == 1)
	{
		if(a[low] > a[high])
		{
			*max = a[low];
			*min = a[high];
		}
		else
		{
			*max = a[high];
			*min = a[low];
		}
	}
	else if(low == high)
	{
		*min = *max = a[low];
	}
	else if(low<high)
	{
		mid=(low+high)/2;
		fnRecMaxMin(a,low,mid,&max1,&min1);
		fnRecMaxMin(a,mid+1,high,&max2,&min2);
		if(max1 > max2)
			*max = max1;
		else
			*max = max2;

		if(min1 < min2)
			*min = min1;
		else
			*min = min2;
	}
}

/******************************************************************************
OUTPUT

SAMPLE 1
Enter the size of the array
6        

Enter the elements of the array:
7 2 3 6 5 4 

Max Element = 7
Min Element = 2

SAMPLE 2
Enter the size of the array
7

Enter the elements of the array:
7 1 2 6 5 3 4

Max Element = 7
Min Element = 1

SAMPLE 3
Enter the size of the array
7

Enter the elements of the array:
1 3 5 7 2 4 6

Max Element = 7
Min Element = 1

******************************************************************************/

