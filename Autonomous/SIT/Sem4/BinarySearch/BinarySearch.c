/********************************************************************************
*File		: BinarySearch.c
*Description	: Program to perform Binary Search using Divide & Conquer
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: Friday 28 November 2013 
********************************************************************************/
#include<stdio.h>
int fnBinSearch(int A[], int k, int iLow,int iHigh);

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
	printf("\nEnter the elements of the array in ascending order:\n");
	for(i=0;i<iNum;i++)
		scanf("%d",&iaArr[i]);
	printf("\nenter the key element\n");
	scanf("%d",&iKey);

	iPos=fnBinSearch(iaArr,iKey,0,iNum-1);

	if(iPos==-1)
		printf("\nElement not found\n");
	else
		printf("\nElement found at position %d\n",iPos+1);

	return 0;
}

/******************************************************************************
*Function	: fnBinSearch
*Description	: Function to perform Binary Search using Divide & Conquer
*Input parameters:
*	int A[]	- array of elements in ascending order
*	int k	- key element to be searched
*	int iLow - lower bound
*	int iHigh - upper bound
*RETURNS	: position of the element if found or -1 otherwise 
******************************************************************************/

int fnBinSearch(int A[], int k, int iLow,int iHigh)
{
	int iMid;
	if(iLow<=iHigh)
	{
		iMid=(iLow+iHigh)/2;
		if(k==A[iMid])
			return iMid;
		if(k<A[iMid])
			return fnBinSearch(A,k,iLow,iMid-1);
		if(k>A[iMid])
			return fnBinSearch(A,k,iMid+1,iHigh);
	}
	else
		return -1;
}

