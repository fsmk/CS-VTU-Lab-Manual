#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void)
{
	int iNum, i, j;
	char acNames[100][50], cTemp[50],ch;

	printf("\nEnter no of elements\n");
	scanf("%d",&iNum);

    ch = getchar();
	printf("\nEnter the list of names\n");
	for(i=0;i<iNum;i++)
		gets(acNames[i]);

	for(i=0;i<iNum-1;i++)
	{
		for(j=0;j<iNum-i-1;j++)
		{
			if(strcmp(acNames[j] ,acNames[j+1])>0)
			{
				strcpy(cTemp, acNames[j]);
				strcpy(acNames[j] , acNames[j+1]);
				strcpy(acNames[j+1] , cTemp);
			}
		}
	}

	printf("\nThe Sorted name list is \n");

	for(i=0;i<iNum;i++)
	{
	    puts(acNames[i]);
	}

	printf("\n");
	return 0;
}
