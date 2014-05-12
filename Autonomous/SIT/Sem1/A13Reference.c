#include <stdio.h>
#include <stdlib.h>

void fnSwap(int*, int*);

int main()
{
    int iVal1,iVal2;
    printf("\nEnter a pair of Values\n");
    scanf("%d%d",&iVal1, &iVal2);
    printf("\nBefore Swapping\n");
    printf("\nValue 1 = %d\nValue 2 = %d",iVal1,iVal2);

    fnSwap(&iVal1,&iVal2);

    printf("\nAfter Swapping\n");
    printf("\nValue 1 = %d\nValue 2 = %d",iVal1,iVal2);
    return 0;
}

void fnSwap(int *x, int *y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}
