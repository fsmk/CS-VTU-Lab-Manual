#include <stdio.h>
#include <stdlib.h>
int fnMatchAny(char*, char*);

int main()
{
    char acStr1[50], acStr2[50];
    int iRes;

    printf("\nEnter two strings\n");
    gets(acStr1);
    gets(acStr2);

    iRes = fnMatchAny(acStr1, acStr2);

    if(iRes == 0)
        printf("\nStrings are same\n");
    else if(iRes == -1)
        printf("\nString1 is not a substring of String2\n");
    else
        printf("\nString1 is a substring of String2 and match occured at position %d\n",iRes);

    return 0;
}

int fnMatchAny(char *s1, char *s2)
{
    int iL1, iL2, i, j, iCnt;
    for(iL1=0;s1[iL1]!='\0';iL1++);
    for(iL2=0;s2[iL2]!='\0';iL2++);

    if(iL1 > iL2)
        return -1;
    else if(iL1 == iL2)
    {
        iCnt = 0;
        for(i=0;i<iL1;i++)
        {
            if(s1[i]==s2[i])
                iCnt++;
        }
        if(iCnt == iL1)
            return 0;
        else
            return -1;
    }
    else
    {
            for(i=0;i<iL2-iL1;i++)
            {
                iCnt = 0;
                for(j=0;j<iL1;j++)
                {
                    if(s1[j]==s2[i+j])
                        iCnt++;
                }
                if(iCnt == iL1)
                    return i+1;
            }
            return -1;
    }
}

