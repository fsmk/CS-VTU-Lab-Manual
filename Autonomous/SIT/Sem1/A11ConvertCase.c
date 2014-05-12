#include <stdio.h>
#include <stdlib.h>

int main()
{
    char acStr1[50], acStr2[50], ch;
    int i, iLen, VowCount=0, ConsCount=0;

    printf("\nEnter the Sentence]\n");
    gets(acStr1);

    for(i=0;acStr1[i]!='\0';i++)
    {
        switch(acStr1[i])
        {
            case 'a':   case 'e':   case 'i':   case 'o':   case 'u':
            case 'A':   case 'E':   case 'I':   case 'O':   case 'U':
                VowCount++; break;
            case ' ':   case '\t':  case '\n': break;
            default: ConsCount++;
        }

        if(acStr1[i]>=65 && acStr1[i]<=90)
        {
            acStr2[i] = acStr1[i] + 32;
        }
        else if(acStr1[i]>=97 && acStr1[i]<=122)
        {
            acStr2[i] = acStr1[i] - 32;
        }
        else
        {
            acStr2[i] = acStr1[i];
        }
    }
    acStr2[i] = '\0';

    printf("\nOriginal String\n");
    puts(acStr1);

    printf("\nConverted String\n");
    puts(acStr2);

    printf("\nNumber of Vowels: %d\n", VowCount);
    printf("\nNumber of Consonants: %d\n", ConsCount);

    return 0;
}
