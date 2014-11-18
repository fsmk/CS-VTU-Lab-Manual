/***************************************************************************
*File		: MatrixMul.c
*Description	: Program to implement Matrix Multiplication
*Author		: Prabodh C P
*Compiler	: gcc 4.6.3 compiler, Ubuntu 10.04
*Date		: Wednesday, July 16 2014
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>

/***************************************************************************
*Function	: 	main
*Input parameters:	no parameters
*RETURNS	:	0 on success
***************************************************************************/

int main(void)
{
	int iM, iN, iP, iQ, i, j, k, iaMat1[10][10], iaMat2[10][10], iTrace = 0;
	int iaProd[10][10] = {0};   //Initialize the matrix with all zeros


	printf("\n*********************************************************");
	printf("\n*\tPROGRAM TO IMPLEMENT MATRIX MULIPLICATION\t*\n");
	printf("*********************************************************");

	printf("\nEnter the order of Matrix1\n");
	scanf("%d%d",&iM,&iN);

	printf("\nEnter the order of Matrix2\n");
	scanf("%d%d",&iP,&iQ);

	if( iN != iP)
	{
		printf("\nMatrix Multiplication not possible\n");
		exit(0);
	}


	printf("\nEnter the elements of Matrix 1 in row major order\n");
	for(i=0;i<iM;i++)
		for(j=0;j<iN;j++)
			scanf("%d",&iaMat1[i][j]);

	printf("\nEnter the elements of Matrix 2 in column major order\n");
	for(i=0;i<iQ;i++)
		for(j=0;j<iP;j++)
			scanf("%d",&iaMat2[j][i]);


	for(i=0;i<iM;i++)
	{
		for(j=0;j<iQ;j++)
		{
			for(k=0;k<iN;k++)
			{
			iaProd[i][j] += iaMat1[i][k] * iaMat2[k][j];
			}
		}
	}

/**************************************************************************************************
                |*|                    |*|
a00  a01  a02   |*|    b00  b01  b02   |*|
                |*|                    |*|
a10  a11  a12   |*|    b10  b11  b12   |*|
                |*|                    |*|
a20  a21  a22   |*|    b20  b21  b22   |*|
                |*|                    |*|

(a00*b00+a01*b10+a02*b20) (a00*b01+a01*b11+a02*b21) (a00*b02+a01*b12+a02*b22)
(a10*b00+a11*b10+a12*b20) (a10*b01+a11*b11+a12*b21) (a10*b02+a11*b12+a12*b22)
(a20*b00+a21*b10+a22*b20) (a20*b01+a21*b11+a22*b21) (a20*b02+a21*b12+a22*b22)
**************************************************************************************************/


	printf("\nMatrix 1\n");

	for(i=0;i<iM;i++)
	{
		for(j=0;j<iN;j++)
		{
			printf("%d\t",iaMat1[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("\nMatrix 2\n");

	for(i=0;i<iP;i++)
	{
		for(j=0;j<iQ;j++)
		{
			printf("%d\t",iaMat2[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	printf("\nThe Product matrix is \n");

	for(i=0;i<iM;i++)
	{
		for(j=0;j<iQ;j++)
		{
			printf("%d\t",iaProd[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	if(iM == iQ)
	{
		for(i=0;i<iM;i++)
			iTrace += iaProd[i][i];
		printf("\nTrace of the product matrix is : %d\n", iTrace);
	}
	else
	{
		printf("\nTrace does not exist\n");
	}
	return 0;
}
/*
$ ./a.out 

*********************************************************
*	PROGRAM TO IMPLEMENT MATRIX MULIPLICATION	*
*********************************************************
Enter the order of Matrix1
2 3

Enter the order of Matrix2
3 2

Enter the elements of Matrix 1 in row major order
1 2 3 4 5 6

Enter the elements of Matrix 2 in column major order
1 2 3 4 5 6

Matrix 1
1	2	3	
4	5	6	


Matrix 2
1	4	
2	5	
3	6	


The Product matrix is is 
14	32	
32	77	

$ ./a.out 

*********************************************************
*	PROGRAM TO IMPLEMENT MATRIX MULIPLICATION	*
*********************************************************
Enter the order of Matrix1
3 4

Enter the order of Matrix2
3 4

Matrix Multiplication not possible

*/
