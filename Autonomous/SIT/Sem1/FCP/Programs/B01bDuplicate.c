#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int iaA[10], iNum;
    int i, j;

    printf("\nEnter no of elements in Array \n");
    scanf("%d",&iNum);

    printf("\nEnter %d elements in Array A\n",iNum);
    for(i=0;i<iNum;++i)
    {
        scanf("%d",&iaA[i]);
    }

    for(i=0;i<iNum;++i)
    {
        for(j=i+1;j<iNum;++j)
        {
            if(iaA[i] == iaA[j])
            {
                printf("\nArray contains duplicate elements\n");
                exit(0);
            }
        }

    }
    printf("\nArray does not contain duplicate elements\n");
    return 0;
}

