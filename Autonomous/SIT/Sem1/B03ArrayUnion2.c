#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
int main()
{
    int iaA[10],iaB[10],iaC[10],iaD[10],iNum1,iNum2;
    int i,j,k = 0, iNotOccur, iCount;

    printf("\nEnter no of elements in Array A\n");
    scanf("%d",&iNum1);
    printf("\nEnter no of elements in Array B\n");
    scanf("%d",&iNum2);

    printf("\nEnter %d elements in Array A\n",iNum1);
    for(i=0;i<iNum1;++i)
    {
	scanf("%d",&iaA[i]);
    }
    printf("\nEnter %d elements in Array B\n",iNum2);
    for(i=0;i<iNum2;++i)
    {
	scanf("%d",&iaB[i]);
    }

    for(i=0;i<iNum1;i++)
    {
	iaC[i] = iaA[i];
    }
    for(j=0;j<iNum2;j++)
    {
	iaC[i+j] = iaB[j];
    }

    iCount = i+j;

    for(i=0;i<iCount;++i)
    {
	iNotOccur = TRUE;
	for(j=0;j<i;j++)
	{
	    if(iaC[i]==iaC[j])
	        iNotOccur = FALSE;
	}
	if(iNotOccur == TRUE)
	{
	    iaD[k++] = iaC[i];
	}
    }

    printf("\nElements of Array A:\n");
    for(i=0;i<iNum1;++i)
    {
	printf("%d\t",iaA[i]);
    }

    printf("\nElements of Array B:\n");
    for(i=0;i<iNum2;++i)
    {
	printf("%d\t",iaB[i]);
    }

    printf("\nUnion of A and B: \n");
    for(i=0;i<k;++i)
    {
	printf("%d\t",iaD[i]);
    }
    printf("\n");

    return 0;
}
