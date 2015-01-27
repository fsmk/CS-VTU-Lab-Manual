#include <stdio.h>
#include <stdlib.h>

int main()
{
    int iYear;

    printf("\n Enter a year\n");
    scanf("%d", &iYear);

    if(iYear % 4 == 0 && iYear % 100 != 0)
        printf("\n%d is a leap year\n",iYear);
    else if(iYear % 400 == 0)
        printf("\n%d is a leap year\n",iYear);
    else
        printf("\n%d is not a leap year\n",iYear);
    return 0;
}
