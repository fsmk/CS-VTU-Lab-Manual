#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iaA[20], iaB[20], iaC[20], i, j=0, k=0, iNum;

    printf("\nEnter the no of elements in the array\n");
    scanf("%d", &iNum);

    printf("\nEnter %d elements\n", iNum);
    for(i=0;i<iNum;i++)
        scanf("%d", &iaA[i]);

    printf("\nContents of Array A\n");
    for(i=0;i<iNum;i++)
    {
        printf("%d\t", iaA[i]);
    }

    for(i=0;i<iNum;i++)
    {
        if(0==iaA[i]%2)
            iaB[j++] = iaA[i];
        else
            iaC[k++] = iaA[i];
    }

    printf("\nEven Element array\n");
    for(i=0;i<j;i++)
    {
        printf("%d\t", iaB[i]);
    }

    printf("\nOdd Element array\n");
    for(i=0;i<k;i++)
    {
        printf("%d\t", iaC[i]);
    }

    return 0;
}

