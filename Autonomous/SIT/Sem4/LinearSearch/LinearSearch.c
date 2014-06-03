/******************************************************************************
*File		: LinearSearch.c
*Description	: Program to perform Linear Search
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: Friday 13 December 2013 
******************************************************************************/
#include<stdio.h>
int fnLinSearch(int [], int, int);

/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{
	int iaArr[20],iNum,iKey;
	int i,iPos=0;
	printf("\nEnter the size of the array\n");
	scanf("%d",&iNum);
	printf("\nEnter the elements of the array:\n");
	for(i=0;i<iNum;i++)
		scanf("%d",&iaArr[i]);
	printf("\nenter the key element\n");
	scanf("%d",&iKey);

	iPos=fnLinSearch(iaArr,iKey,iNum);

	if(iPos==-1)
		printf("\nElement not found\n");
	else
		printf("\nElement found at position %d\n",iPos);

	return 0;
}

/******************************************************************************
*Function	: fnLinSearch
*Description	: Function to perform Linear Search
*Input parameters:
*	int A[]	- array of elements in ascending order
*	int k	- key element to be searched
*	int iN - no of elements to be searched
*RETURNS	: position of the element if found or -1 otherwise 
******************************************************************************/

int fnLinSearch(int A[], int k, int iN)
{
	if( iN ==0)
		return -1;
	else if( k == A[iN-1])
		return iN;
	else 
		return fnLinSearch(A,k,iN-1);
}

