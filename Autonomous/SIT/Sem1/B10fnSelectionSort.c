#include <stdio.h>
#include <stdlib.h>

void fnReadArray(int [], int);
void fnPrintArray(int [], int);
void fnSortArray(int [], int);

int main(void)
{
	int iNum, iaArr[10];

	printf("\nEnter no of elements\n");
	scanf("%d",&iNum);

    fnReadArray(iaArr, iNum);

    printf("\nInput Array is:\n");
    fnPrintArray(iaArr, iNum);

    fnSortArray(iaArr, iNum);

    printf("\nSorted Array is:\n");
    fnPrintArray(iaArr, iNum);

	return 0;
}

void fnReadArray(int A[], int n)
{
    int i;
    printf("\nEnter %d elements into the array\n", n);
	for(i=0;i<n;i++)
		scanf("%d",&A[i]);

}

void fnPrintArray(int A[], int n)
{
    int i;
	for(i=0;i<n;i++)
		printf("%d\t",A[i]);

	printf("\n");
}

void fnSortArray(int A[], int n)
{
    int i,j,iMinPos,iTemp;
	for(i=0;i<n-1;i++)
	{
		iMinPos = i;
		for(j=i+1;j<n;j++)
		{

			if(A[j] < A[iMinPos])
				iMinPos = j;
		}
		iTemp = A[i];
		A[i] = A[iMinPos];
		A[iMinPos] = iTemp;
	}
}

