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
	int iNum, i, j, k, iaArr[10], iTemp;


	printf("\n*************************************************");
	printf("\n*\tPROGRAM TO IMPLEMENT BUBBLE SORT\t*\n");
	printf("*************************************************");

	printf("\nEnter no of elements\n");
	scanf("%d",&iNum);

	printf("\nEnter the elements\n");
	for(i=0;i<iNum;i++)
		scanf("%d",&iaArr[i]);

	getchar();
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
		
			printf("\nIteration i=%d, j=%d\n",i,j);
			for(k=0;k<iNum;k++)
				printf("%d\t",iaArr[k]);
			getchar();
		}
		printf("\nPass %d completed\n", i+1);
	}

	printf("\nThe Sorted array is \n");

	for(i=0;i<iNum;i++)
		printf("%d\t",iaArr[i]);

	printf("\n");
	return 0;
}


