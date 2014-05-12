#include <stdio.h>
#include <stdlib.h>

int fnFibonacci(int);

int main()
{
    int iTerm, i, iNum;

    printf("Enter the no of terms\n");
    scanf("%d", &iNum);

    printf("\nThe terms in the Fibonacci Sequence:\n%d\t%d\t",0,1);

    for(i=2;i<iNum;++i)
    {
        iTerm = fnFibonacci(i);
        printf("%d\t", iTerm);
    }
    return 0;
}

int fnFibonacci(int n)
{
    if(0 == n)
        return 0;
    else if(1 == n)
        return 1;
    else
    {
        return fnFibonacci(n-1) + fnFibonacci(n-2);
    }
}







