#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int iRollNo;
    char acName[30];
    int iMarks;
    char cGrade;
}STUDENT;

int main()
{
    STUDENT s[20];
    int i, iNum, iFound = 0;
    char acStudName[30];

    printf("\nEnter the number of students\n");
    scanf("%d", &iNum);
    getchar();

    printf("\nEnter Student Details\n");
    for(i=0;i<iNum;i++)
    {
        printf("\nStudent %d\nRollNo : ", i+1);
        scanf("%d", &s[i].iRollNo);
        getchar();
        printf("Name   : ");
        gets(s[i].acName);
        printf("Marks  : ");
        scanf("%d", &s[i].iMarks);
        getchar();
        printf("Grade  : ");
        scanf("%c", &s[i].cGrade);
    }

    getchar();
    printf("\nEnter the name to display marks\n");
    gets(acStudName);

    for(i=0;i<iNum;i++)
    {
        if(strcmp(acStudName, s[i].acName)==0)
        {
            iFound = 1;
            printf("\nMarks obtained by %s is %d\n", s[i].acName, s[i].iMarks);
            exit(0);
        }
    }
    if(iFound == 0)
        printf("\nNo student by name %s found\n", s[i].acName);
    return 0;
}

