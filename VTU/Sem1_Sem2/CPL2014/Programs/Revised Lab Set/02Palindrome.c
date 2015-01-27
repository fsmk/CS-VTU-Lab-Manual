/**********************************************************************
Copyright 2012
Prabodh C P
Siddaganga Institute of Technology
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
**********************************************************************/
/***************************************************************************
*File		: 03Palindrome.c
*Description	: Program to check whether the given integer is a Palindrome or not
*Author		: Prabodh C P
*Compiler	: gcc compiler, Ubuntu 10.04
*Date		: 4 July 2012
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
	int iNum,iRev = 0,iTemp,iDig;

	printf("\n**************************************************************************");
	printf("\n*\tPROGRAM TO CHECK WHETHER AN INTEGER IS A PALINDROME OR NOT\t *\n");
	printf("**************************************************************************");

	printf("\nEnter a number\n");
	scanf("%d",&iNum);

	iTemp = iNum;

	while(iNum!=0)
	{
		iDig = iNum % 10;
		iRev = iRev * 10 + iDig;
		iNum = iNum/10;
	}
	printf("\nReversed number is %d",iRev);

	if(iRev == iTemp)
		printf("\nNumber %d is a palindrome\n",iTemp);
	else
		printf("\nNumber %d is not a palindrome\n",iTemp);

	return 0;
}

