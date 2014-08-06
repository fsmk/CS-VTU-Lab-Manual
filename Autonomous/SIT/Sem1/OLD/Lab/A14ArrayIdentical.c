#include <stdio.h>
#include <stdlib.h>

int fnCheckIdentical(int*, int*, int);

int main()
{
    int iaArr1[50],iaArr2[50], iLen1, iLen2, i, iFlag;
    int *iptr1, *iptr2;

    printf("\nEnter the no of elements in the 1st array\n");
    scanf("%d",&iLen1);

    printf("\nEnter the no of elements in the 2nd array\n");
    scanf("%d",&iLen2);

    if(iLen1 != iLen2)
    {
        printf("\nArrays are not Identical\n");
        exit(0);
    }

    printf("\nEnter elements of 1st Array\n");
    for(i = 0; i < iLen1; i++)
        scanf("%d",&iaArr1[i]);

    printf("\nEnter elements of 2nd Array\n");
    for(i = 0; i < iLen2; i++)
        scanf("%d",&iaArr2[i]);

    iptr1 = iaArr1;
    iptr2 = iaArr2;

    iFlag = fnCheckIdentical(iptr1, iptr2, iLen1);

    if(iFlag)
        printf("\nArrays are Identical\n");
    else
        printf("\nArrays are not Identical\n");

    return 0;
}

int fnCheckIdentical(int *p, int *q, int n)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(*(p+i) != *(q+i))
            return 0;
    }
    return 1;
}

