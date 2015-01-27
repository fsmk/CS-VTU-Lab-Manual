/***************************************************************************
*File		: 07BubbleSort.c
*Description	: Program to implement Bubble Sort Algorithm
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 8.10
*Date		: 7 September 2010
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/***************************************************************************
*Function	: main
*Input parameters: none
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	int iNum, i, j, k, iaArr[10], iTemp, iKey, iPos, iLow, iHigh, iMid, iFound;

	printf("\nEnter no of elements\n");
	scanf("%d",&iNum);

	printf("\nEnter the elements\n");
	for(i=0;i<iNum;i++)
		scanf("%d",&iaArr[i]);

	for(i=0;i<iNum-1;i++)
	{
		for(j=i+1;j<iNum;j++)
		{
			if(iaArr[i] > iaArr[j])
			{
				iTemp = iaArr[i];
				iaArr[i] = iaArr[j];
				iaArr[j] = iTemp;
			}
		
		}
	}

/*	for(i=0;i<iNum;i++)
	{
		for(j=0;j<iNum-i-1;j++)
		{
			if(iaArr[j] > iaArr[j+1])
			{
				iTemp = iaArr[j];
				iaArr[j] = iaArr[j+1];
				iaArr[j+1] = iTemp;
			}
		
		}
	}
*/
	printf("\nThe Sorted array is \n");

	for(i=0;i<iNum;i++)
		printf("%d\t",iaArr[i]);

	return 0;
}


