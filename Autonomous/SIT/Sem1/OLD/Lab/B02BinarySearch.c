#include <stdio.h>
#include <stdlib.h>

int main()
{
	int iaArr[100],iKey,iNum,i,iLow,iMid,iHigh,iProbe;
	printf("\nEnter the number of elements\n");
	scanf("%d",&iNum);

	printf("\nEnter %d elements in ascending order\n", iNum);
	for(i=0;i<iNum;i++)
	{
		scanf("%d", &iaArr[i]);
	}
	printf("\nEnter the key element\n");
	scanf("%d", &iKey);

	iLow = 0;
	iHigh = iNum -1;
	iProbe = 0;
	while(iLow <= iHigh)
	{
		iProbe++;
		iMid = (iLow + iHigh)/2;
		if(iKey == iaArr[iMid])
		{
			printf("\nElement %d found at %d position\n",iKey, iMid+1);
			break;
		}
		else if(iKey < iaArr[iMid])
			iHigh = iMid-1;
		else
			iLow = iMid +1;
	}
	if(iLow > iHigh)
		printf("\nElement not found\n");

	printf("\nTotal number of probes required is %d\n", iProbe);

	return 0;
}





