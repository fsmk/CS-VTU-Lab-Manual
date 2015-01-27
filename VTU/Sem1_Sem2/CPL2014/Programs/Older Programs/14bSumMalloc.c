#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *iPtr, iNum, i, iSum=0;

	printf("\nEnter number of elements : ");
	scanf("%d", &iNum);

	iPtr = (int*)malloc(iNum * sizeof(int));

	for(i=0;i<iNum;i++)
		scanf("%d", iPtr+i);

	for(i=0;i<iNum;i++)
		iSum += *(iPtr+i);

	printf("\nThe sum of elements is : %d\n", iSum);

	free(iPtr);
	return 0;
}
