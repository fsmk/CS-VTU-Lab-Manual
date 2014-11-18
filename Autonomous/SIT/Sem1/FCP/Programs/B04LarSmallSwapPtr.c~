#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int iaList[50], iNum, i, j,iSmall, iLarge,iTemp, iPos;
    int *iPtr1,*iPtr2;

    iPtr1 = iPtr2 = iaList;
    printf("\nEnter the value of n : ");
    scanf("%d", &iNum);

    printf("\nEnter the elements: ");
    for(i=0;i<iNum;++i)
    {
        scanf("%d", &iaList[i]);
    }

    iSmall = *iPtr1;
    iLarge = *iPtr2;
    for(i=1;i<iNum;++i)
    {
        if(iaList[i] < iSmall)
        {
            iSmall = iaList[i];
            iPtr1 = &iaList[i];
        }
        if(iaList[i] > iLarge)
        {
            iLarge = iaList[i];
            iPtr2 = &iaList[i];
        }
    }

    printf("\nArray elements before swapping the largest and smallest elements\n");
    for(i=0;i<iNum;i++)
    {
        printf("%d\t", iaList[i]);
    }

    printf("\nSmallest Element = %d\n",*iPtr1);
    printf("\nLargest Element = %d\n",*iPtr2);

    iTemp = *iPtr1;
    *iPtr1 = *iPtr2;
    *iPtr2 = iTemp;

    printf("\nArray elements after swapping the largest and smallest elements\n");
    for(i=0;i<iNum;i++)
    {
        printf("%d\t", iaList[i]);
    }
    printf("\n");
    return 0;
}

/*
$ ./a.out 

Enter the value of n : 5

Enter the elements: 5 4 3 2 1

Array elements before swapping the largest and smallest elements
5	4	3	2	1	
Smallest Element = 1

Largest Element = 5

Array elements after swapping the largest and smallest elements
1	4	3	2	5	

$ ./a.out 

Enter the value of n : 6

Enter the elements: 3 2 1 4 5 6

Array elements before swapping the largest and smallest elements
3	2	1	4	5	6	
Smallest Element = 1

Largest Element = 6

Array elements after swapping the largest and smallest elements
3	2	6	4	5	1	
*/

