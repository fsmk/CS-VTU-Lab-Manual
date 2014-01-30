/***************************************************************************
*File		: 08WordLength.c
*Description	: Program to calculate Word Length
*Author		: Prabodh C P
*Compiler	: gcc 4.4.3 compiler, Ubuntu 10.04
*Date		: Tuesday, August 21 2012
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

	int iLen=0;
	//unsigned int i=1;
	unsigned int i=~0;

	//printf("\n%d\n",sizeof(int));
	//printf("\n%lu\n",i);
	printf("\n*************************************************");
	printf("\n*\tPROGRAM TO CALCULATE WORD LENGTH\t*\n");
	printf("*************************************************");

	for(i = 1; i != 0; i = i << 1)
	{
		//printf("\n%u",i);
		iLen++;
	}
	//printf("\n%u\n",i);
	printf("\n\nThe Word length of the host machine is %d\n\n", iLen);

	return 0;
}
