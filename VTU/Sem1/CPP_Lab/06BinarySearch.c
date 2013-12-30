/***************************************************************************
*File		: 06BinarySearch.c
*Description	: Program to implement binary search
*Author		: Prabodh C P
*Compiler	: gcc 4.4.3 compiler, Ubuntu 10.04
*Date		: Tuesday, August 21 2012
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	int iNum, i, iFound, iaArr[10], iKey, iPos, iLow, iHigh, iMid;


	printf("\n**************************************************");
	printf("\n*\tPROGRAM TO IMPLEMENT BINARY SEARCH\t *\n");
	printf("**************************************************");

	printf("\nEnter no of elements\n");
	scanf("%d",&iNum);

	printf("\nEnter the elements in ascending order\n");
	for(i=0;i<iNum;i++)
		scanf("%d",&iaArr[i]);

	printf("\nEnter the Key element\n");
	scanf("%d",&iKey);

	iFound = 0;
	iLow = 0;
	iHigh = iNum-1;

	while(iLow <= iHigh)
	{
		iMid = (iLow + iHigh)/2;
		
		if(iKey == iaArr[iMid])	/*KEY ELEMENT FOUND*/
		{
			iPos = iMid;
			iFound = 1;
			break;
		}
		else if(iKey < iaArr[iMid])	/*KEY ELEMENT IS IN 1ST HALF*/
			iHigh = iMid - 1;
		else	/*KEY ELEMENT IS IN 2ND HALF*/
			iLow = iMid +1;
	}


	if(iFound)
		printf("\nKey element %d found at position %d\n",iKey,iPos+1);
	else
		printf("\nKey element not found\n");

	return 0;
}

