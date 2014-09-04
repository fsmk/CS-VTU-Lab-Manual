#include<stdio.h>

int main(void)
{
	int iaArr[100],iNum,i,iTotal;
	int *iPtr;

	iPtr = iaArr;
	printf("\nEnter the number of elements\n");
	scanf("%d",&iNum);

	printf("\nEnter the elements\n");
	for(i=0;i<iNum;i++)
		scanf("%d",iPtr+i);

	iTotal = 0;
	for(i=0;i<iNum;i++)
	{
		iTotal = iTotal + *(iPtr+i);
	}

	printf("\nSum of elements = %d\n", iTotal);
	return 0;
}
