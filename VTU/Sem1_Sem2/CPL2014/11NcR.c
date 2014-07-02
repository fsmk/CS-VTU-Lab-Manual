#include <stdio.h>
#include <stdlib.h>

int fnFactorial(int);

int main()
{
    int iN,iR,iNCR;
    printf("\nEnter the value of n\n");
    scanf("%d", &iN);
    printf("\nEnter the value of r\n");
    scanf("%d", &iR);

    if(iN < iR)
    {
        printf("\nnCr does not exist\n");
        exit(0);
    }

    iNCR = (fnFactorial(iN)/(fnFactorial(iR)*fnFactorial(iN-iR)));

    printf("\nFor n = %d and r = %d, %dC%d = %d\n", iN ,iR, iN, iR, iNCR);
    return 0;
}

int fnFactorial(int iVal)
{
    if(0 == iVal)
        return 1;
    else
        return (iVal * fnFactorial(iVal - 1));
}
