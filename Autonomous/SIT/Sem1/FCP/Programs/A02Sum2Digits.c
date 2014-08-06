/***************************************************************************
*File           : SumTwoDigits.c
*Descriptio     : Program to add the last two digits of a given number
*Author         : Prabodh C P
*Compiler       : gcc compiler, Ubuntu 14.04
*Date           : 4 August 2014
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int fnExtractUnit(int);
int fnExtractTen(int);
int fnAddUnitTen(int, int);

int main(void)
{
    int iNum,iTen,iUnit,iSum;

    printf("\nEnter a number\n");
    scanf("%d", &iNum);

    iUnit = fnExtractUnit(iNum);
    iTen = fnExtractTen(iNum);
    iSum = fnAddUnitTen(iTen, iUnit);

    printf("\nThe unit digit in %d is %d\n",iNum, iUnit);
    printf("\nThe ten's digit in %d is %d\n",iNum, iTen);
    printf("\nThe sum of last two digits in %d is %d\n",iNum, iSum);

    return 0;
}

int fnExtractUnit(int iVal)
{
    int iU;
    iU = (iVal%10);
    return iU;
}

int fnExtractTen(int iVal)
{
    int iT;
    iT = (iVal%100)/10;
    return iT;
}

int fnAddUnitTen(int iVal1, int iVal2)
{
    int iS;
    iS =  (iVal1 + iVal2);
    return iS;
}
/*
$ ./a.out 

Enter a number
4567

The unit digit in 4567 is 7

The ten's digit in 4567 is 6

The sum of last two digits in 4567 is 13
$ ./a.out 

Enter a number
1209

The unit digit in 1209 is 9

The ten's digit in 1209 is 0

The sum of last two digits in 1209 is 9
$ ./a.out 

Enter a number
76

The unit digit in 76 is 6

The ten's digit in 76 is 7

The sum of last two digits in 76 is 13

*/
