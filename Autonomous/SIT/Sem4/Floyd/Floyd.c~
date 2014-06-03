/***************************************************************************
*File		: Floyd.c
*Description	: Program to implement Floyd's Algorithm
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 12.04
*Date		: 20 November 2013
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>


/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{
	int iN, i, j, k;
	int iaFloyd[10][10], iaCost[10][10];


	printf("\n*********************************************************");
	printf("\n*\tPROGRAM TO IMPLEMENT FLOYD'S ALGORITHM\t*\n");
	printf("*********************************************************");

	printf("\nEnter the iNber of vertices\n");
	scanf("%d",&iN);

	printf("\nEnter the Cost adjacency Matrix\n");
	for(i=0;i<iN;i++)
		for(j=0;j<iN;j++)
			scanf("%d",&iaCost[i][j]);

	printf("\nInput Graph\n");

	for(i=0;i<iN;i++)
	{
		for(j=0;j<iN;j++)
		{
			printf("%d\t",iaCost[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for(i=0;i<iN;i++)
	{
		for(j=0;j<iN;j++)
		{
			iaFloyd[i][j] = iaCost[i][j];
		}
	}

	for(k=0;k<iN;k++)
	{
		for(i=0;i<iN;i++)
		{
			for(j=0;j<iN;j++)
			{
				iaFloyd[i][j] = (iaFloyd[i][j] < (iaFloyd[i][k] + iaFloyd[k][j]))?
				                    (iaFloyd[i][j]):(iaFloyd[i][k] + iaFloyd[k][j]);
			}
		}
	}

	printf("\nAll Pair Shortest Path Matrix\n");

	for(i=0;i<iN;i++)
	{
		for(j=0;j<iN;j++)
		{
			printf("%d\t",iaFloyd[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}



/***************************************************************************

Compiling instructions
gcc filename.c -o FLOYD.x

Execution
./FLOYD.x

OUTPUT

SAMPLE 1

Input Graph
0		9999	3		9999
2		0		9999	9999
9999	7		0		1
6		9999	9999	0


All Pair Shortest Path Matrix
0	10	3	4
2	0	5	6
7	7	0	1
6	16	9	0

SAMPLE 2

Input Graph

0		15		10		9999	45		9999
9999	0		15		9999	20		9999
20		9999	0		20		9999	9999
9999	10		9999	0		35		9999
9999	9999	9999	30		0		9999
9999	9999	9999	4		9999	0

All Pair Shortest Path Matrix
0	15	10	30	35	9999
35	0	15	35	20	9999
20	30	0	20	50	9999
45	10	25	0	30	9999
75	40	55	30	0	9999
49	14	29	4	34	0

***************************************************************************/

