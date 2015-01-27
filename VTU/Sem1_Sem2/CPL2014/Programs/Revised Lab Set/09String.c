#include <stdio.h>
#include <stdlib.h>

void STRCOPY(char*, char*);

int main()
{
    char acStr1[30],acStr2[30],acStr3[30], cChar;
    int i, iFreqA = 0, iFreqE = 0, iFreqI = 0, iFreqO = 0, iFreqU = 0, iFreqCons = 0;

    printf("\nEnter string to be copied\n");
    gets(acStr1);

    STRCOPY(acStr1,acStr2);

    printf("\nCopied String is\n");
    puts(acStr2);

    printf("\nEnter string to find letter frequency\n");
    gets(acStr3);

    for(i=0;acStr3[i]!='\0';i++)
    {
        cChar = tolower(acStr3[i]);
        switch(cChar)
        {
            case 'a' : iFreqA++;
                    break;
            case 'e' : iFreqE++;
                    break;
            case 'i' : iFreqI++;
                    break;
            case 'o' : iFreqO++;
                    break;
            case 'u' : iFreqU++;
                    break;
            case ' ' : break;
            default : iFreqCons++;
        }
    }
    printf("\nFrequency of vowel 'A' is : %d\n",iFreqA);
    printf("\nFrequency of vowel 'E' is : %d\n",iFreqE);
    printf("\nFrequency of vowel 'I' is : %d\n",iFreqI);
    printf("\nFrequency of vowel 'O' is : %d\n",iFreqO);
    printf("\nFrequency of vowel 'U' is : %d\n",iFreqU);
    printf("\nThe no of consonants is : %d\n",iFreqCons);


    return 0;
}

void STRCOPY(char *s1, char *s2)
{
    int i;
    for(i=0;s1[i]!='\0';i++)
        s2[i] = s1[i];
    s2[i] = '\0';
}

