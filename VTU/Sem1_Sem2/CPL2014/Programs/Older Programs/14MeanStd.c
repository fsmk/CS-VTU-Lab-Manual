#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int iNum, i, j;
    double daArr[50], dTemp;
    double *dPtr;

    double dSum,dMean,dVar,dStdDev;

    dPtr = daArr;

    printf("\nEnter the no of elements in the array\n");
    scanf("%d",&iNum);

    printf("\nEnter elements of Array\n");
    for(i = 0; i < iNum; i++)
        scanf("%lf",dPtr+i);

    printf("\nThe elements of Array\n");
    for(i = 0; i < iNum; i++)
        printf("%0.2lf \t",*(dPtr+i));
	printf("\n\n");

    for(i = 0; i < iNum; i++)
        dSum += *(dPtr+i);

	dMean = dSum/iNum;


    for(i = 0; i < iNum; i++)
    {
		dVar += ((*(dPtr+i)-dMean)*(*(dPtr+i)-dMean));
	}
	dVar = dVar/iNum;

	dStdDev = sqrt(dVar);

    printf("\nMean = %g\n", dMean);
    printf("\nVariance = %g\n", dVar);
    printf("\nStd Deviation = %g\n", dStdDev);

    return 0;
}

