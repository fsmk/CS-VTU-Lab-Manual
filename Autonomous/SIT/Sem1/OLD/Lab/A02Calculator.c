#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int iChoice,iVal1,iVal2,iResult;
    printf("\nEnter two values\n");
    scanf("%d%d",&iVal1,&iVal2);

    printf("\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
    printf("\nEnter your Choice\n");
    scanf("%d",&iChoice);

    switch(iChoice)
    {
        case 1: iResult = iVal1 + iVal2;
                break;
        case 2: iResult = iVal1 - iVal2;
                break;
        case 3: iResult = iVal1 * iVal2;
                break;
        case 4: if(iVal2 == 0)
		{
			printf("\nCannot divide by zero\n");
			exit(0);
		}
		iResult = iVal1 / iVal2;
                break;
	default: printf("\nInvalid Input\n");
		exit(0);
		
    }

    printf("\nResult of the operation is : %d\n",iResult);

    return 0;
}
