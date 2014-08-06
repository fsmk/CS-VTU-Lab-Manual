#include <stdio.h>
#include <stdlib.h>

int fnFibonacci(int);

int main(void)
{
    int iTerm, i, iNum;

    printf("Enter the no of terms\n");
    scanf("%d", &iNum);

    printf("\nThe terms in the Fibonacci Sequence:\n");
    //printf("\nThe terms in the Fibonacci Sequence:\n%d\t%d\t",0,1);
    for(i=0;i<iNum;++i)
    {
        iTerm = fnFibonacci(i);
        printf("%d\t", iTerm);
    }
    return 0;
}

int fnFibonacci(int n)
{
    if(0 == n || 1 == n)
        return n;
    else
    {
        return fnFibonacci(n-1) + fnFibonacci(n-2);
    }
}

/*
$ ./a.out 
Enter the no of terms
5

The terms in the Fibonacci Sequence:
0	1	1	2	3	
*/
