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
        printf("\nSubstring found at position %ld\n", pos-acText+1);
        start = pos+1;
    }

    printf("\nNo of occurences is %d\n", iCount);

    return 0;
}

/*
$ ./a.out 

Enter the text
The cat with five legs ran down the hall    

Enter the substring to search for
he

Substring found at position 2

Substring found at position 34

No of occurences is 2

$ ./a.out 

Enter the text
Freedom of the mind

Enter the substring to search for
faith

No of occurences is 0
*/

