#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

int main(void)
{
	int iaMat[100][100],iRow,iCol,i,j;
	int isIdentity;

	printf("\nEnter the order of the matrix\n");
	scanf("%d%d",&iRow,&iCol);

	if(iRow != iCol)
	{
		printf("\nMatrix should be a Square Matrix\n");
		exit(0);
	}

	printf("\nEnter the elements of the matrix\n");
	for(i=0;i<iRow;i++)
	{
		for(j=0;j<iCol;j++)
		{
			scanf("%d",&iaMat[i][j]);
		}
	}

    	isIdentity = TRUE;

	for(i=0;i<iRow;i++)
	{
		for(j=0;j<iCol;j++)
		{
			if(i==j && iaMat[i][j]!=1)
				isIdentity = FALSE;
			if(i!=j && iaMat[i][j]!=0)
				isIdentity = FALSE;
		}
	}

	printf("\nMatrix \n");
	for(i=0;i<iRow;i++)
	{
		for(j=0;j<iCol;j++)
		{
			printf("%2d\t",iaMat[i][j]);
		}
		printf("\n");
	}

	if(isIdentity == TRUE)
        	printf("\nThe given Matrix is a Identity Matrix\n");
    	else
        	printf("\nThe given Matrix is a not an Identity Matrix\n");

	return 0;
}

