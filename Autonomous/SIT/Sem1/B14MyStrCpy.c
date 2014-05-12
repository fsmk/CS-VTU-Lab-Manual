#include <stdio.h>
#include <stdlib.h>

void fnMyStrCpy(char*, char*);

int main()
{
    char acSrc[50],acDest[50];

    printf("\nEnter the string to be copied\n");
    gets(acSrc);

    fnMyStrCpy(acDest, acSrc);

    printf("\nThe copied string is\n");
    puts(acDest);

    return 0;
}

void fnMyStrCpy(char *dest, char *src)
{
    int i;
    for(i=0;*(src+i) != '\0';i++)
    {
        *(dest+i) = *(src+i);
    }
    *(dest+i) = '\0';

//    for(i=0;src[i] != '\0';i++)
//    {
//        dest[i] = src[i];
//    }
//    dest[i] = '\0';

}

