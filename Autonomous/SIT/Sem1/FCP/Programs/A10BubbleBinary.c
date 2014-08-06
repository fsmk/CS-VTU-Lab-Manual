#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iaArr[100],iKey,iNum,i,j,iLow,iMid,iHigh,iProbe,iTemp;
    printf("\nEnter the number of elements\n");
    scanf("%d",&iNum);

    printf("\nEnter %d elements\n", iNum);
    for(i=0;i<iNum;i++)
    {
        scanf("%d", &iaArr[i]);
    }

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
    printf("\nSorted Input Array\n");
    for(i=0;i<iNum;i++)
    {
        printf("%d ", iaArr[i]);
    }

    printf("\nEnter the key element\n");
    scanf("%d", &iKey);

    iLow = 0;
    iHigh = iNum -1;
    iProbe = 0;
    while(iLow <= iHigh)
    {
        iProbe++;
        iMid = (iLow + iHigh)/2;
        if(iKey == iaArr[iMid])
        {
            printf("\nElement %d found at %d position\n",iKey, iMid+1);
            break;
        }
        else if(iKey < iaArr[iMid])
            iHigh = iMid-1;
        else
            iLow = iMid +1;
    }
    if(iLow > iHigh)
        printf("\nElement not found\n");

    printf("\nTotal number of probes required is %d\n", iProbe);

    return 0;
}

/*
$ ./a.out 

Enter the number of elements
5        

Enter 5 elements
1 7 4 2 9

Sorted Input Array
1 2 4 7 9 
Enter the key element
4

Element 4 found at 3 position

Total number of probes required is 1
$ ./a.out 

Enter the number of elements
3

Enter 3 elements
5 7 9

Sorted Input Array
5 7 9 
Enter the key element
8

Element not found

Total number of probes required is 2
*/
