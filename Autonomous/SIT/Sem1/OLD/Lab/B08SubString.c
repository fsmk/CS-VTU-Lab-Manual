#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char acText[100], acPattern[10];
    int iCount;
    char *pos = NULL, *start = NULL;
    printf("\nEnter the text\n");
    gets(acText);

    printf("\nEnter the substring to search for\n");
    gets(acPattern);

    start = acText;
    while((pos = strstr(start, acPattern)))
    {

        iCount++;
        start = pos+1;
    }

    printf("\nNo of occurences is %d\n", iCount);

    return 0;
}

