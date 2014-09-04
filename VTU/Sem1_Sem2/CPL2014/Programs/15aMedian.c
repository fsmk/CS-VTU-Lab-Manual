#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iNum, i, j;
    float faArr1[50], fTemp;
    float *fPtr;

    float fMedian;

    fPtr = faArr1;

    printf("\nEnter the no of elements in the array\n");
    scanf("%d",&iNum);

    printf("\nEnter elements of Array\n");
    for(i = 0; i < iNum; i++)
        scanf("%f",fPtr+i);

    printf("\nThe elements of Array\n");
    for(i = 0; i < iNum; i++)
        printf("%0.2f \t",*(fPtr+i));

    for(i = 0; i < iNum-1; i++)
    {
        for(j = i+1; j < iNum; j++)
        {
            if(faArr1[i] > faArr1[j])
            {
                fTemp = faArr1[i];
                faArr1[i] = faArr1[j];
                faArr1[j] = fTemp;
            }
        }

    }

    if(iNum%2)
        fMedian = *(fPtr+(iNum/2));
    else
        fMedian = (*(fPtr+(iNum/2)) + *(fPtr+(iNum/2)-1))/2.0f;


    printf("\nMedian = %g\n", fMedian);

    return 0;
}

