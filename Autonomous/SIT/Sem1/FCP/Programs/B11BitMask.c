#include <stdio.h>
#include <stdlib.h>

unsigned short fnSetBit(unsigned short, unsigned short);
unsigned short fnMaskBit(unsigned short, unsigned short);

int main(void)
{
	unsigned short uNum,uPos;

	printf("\nEnter a value\n");
	scanf("%hu",&uNum);

	printf("\nEnter bit uPosition (1-16) to set to one\n");
	scanf("%hu",&uPos);

	uNum = fnSetBit(uNum, uPos);

	printf("\nValue after setting the specified bit = %hu\n",uNum);

	printf("\nEnter a value\n");
	scanf("%hu",&uNum);

	printf("\nEnter bit uPosition (1-16) to mask to zero\n");
	scanf("%hu",&uPos);

	uNum = fnMaskBit(uNum, uPos);

	printf("\nValue after masking the specified bit = %hu\n",uNum);

	return 0;
}

unsigned short fnSetBit(unsigned short uVal, unsigned short uPos)
{
	unsigned short uMask=1;
	uMask = uMask << (uPos-1);
	uVal = uVal | uMask;
	return uVal;
}
unsigned short fnMaskBit(unsigned short uVal, unsigned short uPos)
{
	unsigned short uMask=1;
	uMask = uMask << (uPos-1);
	uMask = ~uMask;
	uVal = uVal & uMask;
	return uVal;
}

/*
$ ./a.out 

Enter a value
56

Enter bit uPosition (1-16) to set to one
3

Value after setting the specified bit = 60

Enter a value
63

Enter bit uPosition (1-16) to mask to zero
3

Value after masking the specified bit = 59
*/
