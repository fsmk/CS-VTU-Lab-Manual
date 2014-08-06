#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
int main(void)
{
    int iaA[10], iaB[10], iaC[10], iNum1, iNum2;
    int i, j, iNotOccur, iCount;

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

	/*Copy those elements of X that are not in Y into C*/
    for(i=0;i<iNum1;i++)
    {
	iNotOccur = TRUE;
	for(j=0;j<iNum2;j++)
	{
	    if(iaA[i] == iaB[j])
	        iNotOccur = FALSE;
	}
	if(iNotOccur == TRUE)
	{
	    iaC[iCount++] = iaA[i];
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

    printf("\nDifference of A and B: \n");
    for(i=0;i<iCount;++i)
    {
	printf("%d\t",iaC[i]);
    }
    printf("\n");
    return 0;
}
/*

$ ./a.out 

Enter no of elements in Array A
4     

Enter no of elements in Array B
5

Enter 4 elements in Array A
1 2 3 4

Enter 5 elements in Array B
3 4 5 6 7  

Elements of Array A:
1	2	3	4	
Elements of Array B:
3	4	5	6	7	
Difference of A and B: 
1	2	

$ ./a.out 

Enter no of elements in Array A
5 

Enter no of elements in Array B
4 

Enter 5 elements in Array A
3 4 5 6 7

Enter 4 elements in Array B
1 2 3  4

Elements of Array A:
3	4	5	6	7	
Elements of Array B:
1	2	3	4	
Difference of A and B: 
5	6	7	

$ ./a.out 

Enter no of elements in Array A
5 

Enter no of elements in Array B
4

Enter 5 elements in Array A
3 5 7 4 6

Enter 4 elements in Array B
4 1 2 3

Elements of Array A:
3	5	7	4	6	
Elements of Array B:
4	1	2	3	
Difference of A and B: 
5	7	6	

*/
