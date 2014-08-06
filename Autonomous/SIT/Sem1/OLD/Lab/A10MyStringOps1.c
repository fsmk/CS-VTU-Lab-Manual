#include <stdio.h>
#include <stdlib.h>

int main()
{
    char acStr1[30],acStr2[30];
    char acStr3[30], acStr4[30];
    int i,iLen;
    printf("\nEnter the String\n");
    gets(acStr1);

    for(i=0;acStr1[i] != '\0';i++)
    {
        acStr2[i] = acStr1[i];
    }
    acStr2[i] = '\0';
    
    printf("\nCopied String\n");
    puts(acStr2);

    return 0;
}
