#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1,*fp2, *fp3;
    int iWordCount = 0, iLineCount = 0;
    char cCharacter;

    fp1 = fopen("Ramayana.in","r");
    fp2 = fopen("Mahabharatha.in", "r");
    fp3 = fopen("Karnataka.in", "w+");

    while((cCharacter=fgetc(fp1))!=EOF)
    {
        fputc(cCharacter,fp3);
    }

    while((cCharacter=fgetc(fp2))!=EOF)
    {
        fputc(cCharacter,fp3);
    }

    rewind(fp3);

    while((cCharacter=fgetc(fp3))!=EOF)
    {
        if(cCharacter == '\n')
        {
            iLineCount++;
            iWordCount++;
        }
        else if(cCharacter == '\t' || cCharacter == ' ')
            iWordCount++;
       printf("%c",cCharacter);
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    printf("\n\nNumber of lines is : %d\n", iLineCount);

    printf("\n\nNumber of words is : %d\n", iWordCount);

    //Code for Verification (works only on GNU\Linux)
    printf("\nOutput of command : wc Karnataka.in -lw\n");
    system("wc Karnataka.in -lw");
    return 0;
}

