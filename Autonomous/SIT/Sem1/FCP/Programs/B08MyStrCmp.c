#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool fnMyStrCmp(char [], char []);

int main()
{
    char acStr1[50],acStr2[50];
    bool notIdentical;

    printf("\nEnter string1\n");
    gets(acStr1);

    printf("\nEnter string2\n");
    gets(acStr2);

    notIdentical = fnMyStrCmp(acStr1, acStr2);

    if(notIdentical)
        printf("\nThe strings are not identical\n");
    else
        printf("\nThe strings are identical\n");

    return 0;
}

bool fnMyStrCmp(char str1[], char str2[])
{
    int i,j;
    bool notSame = false;
    for(i=0; str1[i] != '\0';i++);
    for(j=0; str2[j] != '\0';j++);

    if(i != j)
    {
        notSame = true;
        return notSame;
    }
    for(i=0; str1[i] != '\0';i++)
    {
        if(str1[i] != str2[i])
        {
            notSame = true;
            return notSame;
        }

    }
    return notSame;
}
/*

$ ./a.out 

Enter string1
Tumkur

Enter string2
Bangalore

The strings are not identical

$ ./a.out 

Enter string1
Tumkur

Enter string2
tumkur

The strings are not identical

$ ./a.out 

Enter string1
Tumkur

Enter string2
TUMKUR

The strings are not identical

$ ./a.out 

Enter string1
tumkur

Enter string2
tumkur

The strings are identical

$ ./a.out 

Enter string1
Tumkur

Enter string2
Tumkur City

The strings are not identical

*/
