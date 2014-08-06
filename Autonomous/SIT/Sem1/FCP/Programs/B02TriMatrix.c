#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int iaMat[100][100],iRow,iCol,i,j;

	printf("\nEnter the order of the matrix\n");
	scanf("%d%d",&iRow,&iCol);

	if(iRow != iCol)
	{
		printf("\nMatrix should be a Square Matrix\n");
		exit(0);
	}
	for(i=0;i<iRow;i++)
	{
		for(j=0;j<iCol;j++)
		{
			if(i < j)
				iaMat[i][j] = 1;
			else if(i == j)
				iaMat[i][j] = 0;
			else
				iaMat[i][j] = -1;
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
	return 0;
}

