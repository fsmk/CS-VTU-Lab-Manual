/***************************************************************************
*File		: 07BubbleSort.c
*Description	: Program to implement Bubble Sort Algorithm
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 8.10
*Date		: 7 September 2010
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/***************************************************************************
*Function	: main
*Input parameters: none
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	char acNames[20][30], cTemp[30], cKeyName[30];
	int iNum, i, j, k,  iPos, iLow, iHigh, iMid, iFound;

	printf("\nEnter no of names\n");
	scanf("%d",&iNum);

	printf("\nEnter %d names\n", iNum);
	for(i=0;i<iNum;i++)
		gets(acNames[i]);

	for(i=0;i<iNum;i++)
	{
		for(j=i+1;j<iNum;j++)
		{
			if(strcmp(acNames[i], acNames[j])>0)
			{
				strcpy(cTemp, acNames[i]);
				strcpy(acNames[i], acNames[j]);
				strcpy(acNames[j], cTemp);
			}		
		}
	}

	printf("\nThe names in sorted form \n");

	for(i=0;i<iNum;i++)
		printf("%s\n",acNames[i]);

	printf("\n");
	printf("\nEnter the name you want to search\n");
	scanf("%d",&cKeyName);

	iFound = 0;
	iLow = 0;
	iHigh = iNum-1;

	while(iLow <= iHigh)
	{
		iMid = (iLow + iHigh)/2;
		
		if(strcmp(cKeyName, acNames[iMid]) == 0)	/*KEY ELEMENT FOUND*/
		{
			iPos = iMid;
			iFound = 1;
			break;
		}
		else if(strcmp(cKeyName, acNames[iMid]) < 0)	/*KEY ELEMENT IS IN 1ST HALF*/
			iHigh = iMid - 1;
		else	/*KEY ELEMENT IS IN 2ND HALF*/
			iLow = iMid +1;
	}


	if(iFound)
		printf("\nKey name %s found at position %d\n",cKeyName,iPos+1);
	else
		printf("\nKey element not found\n");

	return 0;
}


