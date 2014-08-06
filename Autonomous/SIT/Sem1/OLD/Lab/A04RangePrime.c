#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j, iLim1, iLim2, iFactCnt;

    printf("\nEnter the range\n");
    scanf("%d%d", &iLim1, &iLim2);

    printf("\nPrime numbers in the range %d to %d is\n",iLim1,iLim2);
    for(i=iLim1;i<=iLim2;i++)
    {
        iFactCnt = 0;
        for(j=2;j<i;j++)
        {
            if(0 == i%j)
            {
                iFactCnt++;
            }
        }
        if(0 == iFactCnt)
            printf("%d\t",i);
    }
    return 0;
}
