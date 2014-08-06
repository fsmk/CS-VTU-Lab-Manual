#include <stdio.h>
#include <stdlib.h>

int fnSearchChar(char [], char, int);

int main()
{
    char acText[30], ch;
    int iLen,iPos;


    printf("\nEnter the string\n");
    gets(acText);
    //getchar();
    printf("\nEnter the character\n");
    scanf("%c", &ch);

    for(iLen=0;acText[iLen]!='\0';iLen++);

    iPos = fnSearchChar(acText, ch, iLen-1);

    if(-1 == iPos)
        printf("\nCharacter not found\n");
    else
        printf("\nCharacter found at position : %d\n", iPos+1);

    return 0;
}

int fnSearchChar(char str[], char c, int pos)
{
    if(pos<0)
        return -1;
    else if(str[pos] == c)
        return pos;
    else
        return fnSearchChar(str, c, pos-1);
}

