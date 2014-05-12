#include <stdio.h>
#include <stdlib.h>
void fnGetMatrix(int [][10], int, int);
void fnShowMatrix(int [][10], int, int);
void fnRowSum(int [][10], int, int);
void fnColSum(int [][10], int, int);
void fnSumAll(int [][10], int, int);

int main()
{
    int iaMatrix[10][10],iRow,iCol;

    printf("\nEnter the number of rows and columns\n");
    scanf("%d%d",&iRow,&iCol);
    fnGetMatrix(iaMatrix,iRow,iCol);
    fnShowMatrix(iaMatrix,iRow,iCol);
    fnRowSum(iaMatrix,iRow,iCol);
    fnColSum(iaMatrix,iRow,iCol);
    fnSumAll(iaMatrix,iRow,iCol);
    return 0;
}

void fnGetMatrix(int iaMat[][10], int iM, int iN)
{
    int i,j;
    printf("\nEnter the elements\n");
    for(i=0;i<iM;i++)
        for(j=0;j<iN;j++)
            scanf("%d",&iaMat[i][j]);

}
void fnShowMatrix(int iaMat[][10], int iM, int iN)
{
    int i,j;
    printf("\nThe elements of the matrix are:\n");
    for(i=0;i<iM;i++)
    {
        for(j=0;j<iN;j++)
        {
            printf("%d\t",iaMat[i][j]);
        }
        printf("\n");
    }
}
void fnRowSum(int iaMat[][10], int iM, int iN)
{
    int i, j, iRowSum;
    for(i=0;i<iM;i++)
    {
        iRowSum = 0;
        for(j=0;j<iN;j++)
        {
            iRowSum += iaMat[i][j];
        }
        printf("\nRow sum of Row %d is %d\n", i+1, iRowSum);
    }
}

void fnColSum(int iaMat[][10], int iM, int iN)
{
    int i, j, iColSum;
    for(j=0;j<iN;j++)
    {
        iColSum = 0;
        for(i=0;i<iM;i++)
        {
            iColSum += iaMat[i][j];
        }
        printf("\nColumn sum of Column %d is %d\n", i+1, iColSum);
    }
}
void fnSumAll(int iaMat[][10], int iM, int iN)
{
    int i, j, iTotSum=0;
    for(i=0;i<iM;i++)
    {
        for(j=0;j<iN;j++)
        {
            iTotSum += iaMat[i][j];
        }
    }
    printf("\nSum of all elements in the matrix is %d\n", iTotSum);

}

