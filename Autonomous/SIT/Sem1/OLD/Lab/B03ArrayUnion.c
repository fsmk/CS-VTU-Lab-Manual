	#include <stdio.h>
	#include <stdlib.h>

	#define TRUE 1
	#define FALSE 0
	int main()
	{
	    int iaA[10],iaB[10],iaC[10],iaX[10],iaY[10],iNum1,iNum2;
	    int i,j,k = 0, l = 0, iNotOccur, iCount;

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

	    for(i=0;i<iNum1;++i)
	    {
		iNotOccur = TRUE;
		for(j=0;j<i;j++)
		{
		    if(iaA[i]==iaA[j])
		        iNotOccur = FALSE;
		}
		if(iNotOccur == TRUE)
		{
		    iaX[k++] = iaA[i];
		}
	    }

	    for(i=0;i<iNum2;++i)
	    {
		iNotOccur = TRUE;
		for(j=0;j<i;j++)
		{
		    if(iaB[i]==iaB[j])
		        iNotOccur = FALSE;
		}
		if(iNotOccur == TRUE)
		{
		    iaY[l++] = iaB[i];
		}
	    }
		/*Copy elements of X directly into C*/
	    for(i=0;i<k;i++)
	    {
		iaC[i] = iaX[i];
	    }
	    iCount = i;
		/*Copy those elements of Y that are not in X into C*/
	    for(i=0;i<l;i++)
	    {
		iNotOccur = TRUE;
		for(j=0;j<k;j++)
		{
		    if(iaY[i] == iaX[j])
		        iNotOccur = FALSE;
		}
		if(iNotOccur == TRUE)
		{
		    iaC[iCount++] = iaY[i];
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
	    for(i=0;i<iCount;++i)
	    {
		printf("%d\t",iaC[i]);
	    }
	    printf("\n");
	    return 0;
	}




