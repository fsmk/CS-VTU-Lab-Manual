#include <stdio.h>
#include <stdlib.h>

int fnRecPow(int, int);
int main(void)
{
    int iX, iN, iRes;
    printf("\n Enter value of x and n\n");
    scanf("%d%d", &iX, &iN);

    //printf("\n%d raised to the power %d is %d\n",iX, iN, fnRecPow(iX,iN));
    iRes = fnRecPow(iX,iN);
        printf("\n%d raised to the power %d is %d\n",iX, iN, iRes);
    return 0;
}

int fnRecPow(int iX, int iN)
{
    if(1 == iN)
        return iX;
    else
        return (iX * fnRecPow(iX, iN-1));
}
