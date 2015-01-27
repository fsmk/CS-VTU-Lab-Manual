/*pg 28 and 293 in second 183*/
#include<stdio.h>
#include<stdlib.h>

int fnCheckPrime(int);

int main(void)
{
	int iVal1, iVal2, i;

	printf("\nEnter the range\n");
	scanf("%d%d",&iVal1, &iVal2);

	printf("\nPrime numbers in the range %d to %d is\n", iVal1, iVal2);
	for(i=iVal1;i<=iVal2;i++)
	{
        if(fnCheckPrime(i))	//arguments
            printf("%d\t", i);
	}

	return 0;
}

/*Function with return values and parameters*/

int fnCheckPrime(int iX)		//parameters
{
	int i,isPrime = 1;
	for(i=2;i<iX;i++)
	{
		if(iX%i == 0)
		{
			isPrime = 0;
			break;
		}
	}

	if(isPrime)
        return 1;
	else
        return 0;
}


