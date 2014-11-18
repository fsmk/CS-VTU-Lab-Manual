#include <stdio.h>
#include <stdlib.h>

void fnReadArray(int [], int);
void fnSortArray(int [], int);
void fnDispArray(int [], int);
int fnSearchArray(int [], int, int);

int main(void)
{
    int iaList[100], iKey, iNum, iPos;

    printf("\nEnter the no. of elements\n");
    scanf("%d", &iNum);

    printf("\nEnter %d elements\n", iNum);
    fnReadArray(iaList, iNum);
    printf("\nEntered values are :\n");
    fnDispArray(iaList, iNum);

    fnSortArray(iaList, iNum);

    printf("\nAfter Sorting :\n");
    fnDispArray(iaList, iNum);

    printf("\nEnter the key element\n");
    scanf("%d", &iKey);
    iPos = fnSearchArray(iaList, iKey, iNum);

    if(-1 == iPos)
    {
        printf("\nElement not found\n");
    }
    else
    {
        printf("\nElement %d found at position %d\n", iKey, iPos+1);
    }
    return 0;
}

void fnReadArray(int iaArr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        scanf("%d", &iaArr[i]);
}

void fnDispArray(int iaArr[], int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("\t%d", iaArr[i]);
    printf("\n");
}

void fnSortArray(int iaArr[], int n)
{
    int i,j,iTemp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(iaArr[j] > iaArr[j+1])
            {
                iTemp = iaArr[j];
                iaArr[j] = iaArr[j+1];
                iaArr[j+1] = iTemp;
            }
        }
    }
}

int fnSearchArray(int iaArr[], int k, int n)
{
    int iLow, iMid, iHigh;

    iLow = 0;
    iHigh = n-1;
    while(iLow <= iHigh)
    {
        iMid = (iLow + iHigh);
        if(k == iaArr[iMid])
            return iMid;
        else if(k < iaArr[iMid])
            iHigh = iMid - 1;
        else
            iLow = iMid + 1;
    }
    return -1;
}

