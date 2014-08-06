#include <stdio.h>
#include <stdlib.h>

int fnFactorial(int);

int main(void)
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

/*
$ ./a.out 

Enter the value of n
3 6

Enter the value of r

nCr does not exist

$ ./a.out 

Enter the value of n
5 2

Enter the value of r

For n = 5 and r = 2, 5C2 = 10

$ ./a.out 

Enter the value of n
7 5

Enter the value of r

For n = 7 and r = 5, 7C5 = 21
*/
