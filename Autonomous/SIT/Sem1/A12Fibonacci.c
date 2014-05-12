#include <stdio.h>
#include <stdlib.h>

int fnFibonacci(int);
int main()
{
    int iaFib[100],iNum,i;
    printf("\nEnter the no. of terms\n");
    scanf("%d",&iNum);

    for(i=0;i<iNum;i++)
    {
        iaFib[i] = fnFibonacci(i);
    }

    printf("\nFirst %d terms of Fibonacci series\n",iNum);
    for(i=0;i<iNum;i++)
    {
        printf("%d\t",iaFib[i]);
    }
    printf("\n");
    return 0;
}

int fnFibonacci(int iN)
{
    if(iN == 0 || iN == 1)
        return iN;
    else
        return fnFibonacci(iN-1)+fnFibonacci(iN-2);
}
