/***************************************************************************
*File		: 07BubbleSort.c
*Description	: Program to implement Bubble Sort Algorithm
*Author		: Prabodh C P
*Compiler	: gcc 4.4.3 compiler, Ubuntu 10.04
*Date		: Tuesday, August 21 2012
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	int iNum, i, j, iaArr[10], iTemp;


	printf("\n*************************************************");
	printf("\n*\tPROGRAM TO IMPLEMENT BUBBLE SORT\t*\n");
	printf("*************************************************");

	printf("\nEnter no of elements\n");
	scanf("%d",&iNum);

	printf("\nEnter the elements\n");
	for(i=0;i<iNum;i++)
		scanf("%d",&iaArr[i]);

	for(i=0;i<iNum;i++)
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

/*	for(i=0;i<iNum-1;i++)
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

	printf("\n");
	return 0;
}


