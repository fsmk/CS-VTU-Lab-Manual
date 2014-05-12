#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iaArr[10], iLen, i, iTemp;
    int *iptr1, *iptr2;


    printf("\nEnter the no of elements in the 1st array\n");
    scanf("%d",&iLen);

    iptr1 = iaArr;
    iptr2 = (iaArr + iLen-1);

    printf("\nEnter elements of the Array\n");
    for(i = 0; i < iLen; i++)
        scanf("%d",(iptr1+i));

    printf("\nElements of the Array before reversing\n");
    for(i = 0; i < iLen; i++)
        printf("%d\t",*(iptr1+i));

    while(iptr1 < iptr2)
    {
        iTemp = *iptr1;
        *iptr1 = *iptr2;
        *iptr2 = iTemp;
        iptr1++;
        iptr2--;
    }

    iptr1 = iaArr;
    printf("\nElements of the Array after reversing\n");
    for(i = 0; i < iLen; i++)
        printf("%d\t",*(iptr1+i));

    return 0;
}

