#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void fnReadArray(double [], int);
void fnPrintArray(double [], int);
double fnMean(double [], int);
double fnVar(double [], int, double);
double fnSD(double);

int main(void)
{
	int iNum;
	double daArr[10], dMean, dVar, dSD;

	printf("\nEnter no of elements\n");
	scanf("%d",&iNum);

    fnReadArray(daArr, iNum);

    printf("\nInput Array is:\n");
    fnPrintArray(daArr, iNum);

    dMean = fnMean(daArr, iNum);
    printf("\nMean of the Array is: %lf\n",dMean);

    dVar = fnVar(daArr, iNum, dMean);
    printf("\nVariance of the Array is: %lf\n",dVar);

    dSD = fnSD(dVar);
    printf("\nStandard Deviation of the Array is: %lf\n",dSD);

	return 0;
}

void fnReadArray(double A[], int n)
{
    int i;
    printf("\nEnter %d elements into the array\n", n);
	for(i=0;i<n;i++)
		scanf("%lf",&A[i]);

}

void fnPrintArray(double A[], int n)
{
    int i;
	for(i=0;i<n;i++)
		printf("%lf\t",A[i]);
	printf("\n");
}

double fnMean(double A[], int n)
{
    double dM=0.0;
    int i;
	for(i=0;i<n;i++)
	{
	    dM += A[i];
	}
    dM /= n;
    return dM;
}

double fnVar(double A[], int n, double dM)
{
    double dV=0.0;
    int i;
	for(i=0;i<n;i++)
	{
	    dV += ((A[i]-dM) * (A[i]-dM));
	}
    dV /= n;
    return dV;

}

double fnSD(double dVal)
{
    return sqrt(dVal);
}

