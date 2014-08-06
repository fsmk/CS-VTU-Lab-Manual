#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    int iXcor, iYcor;
}POINT;


int main(void)
{
	POINT p1, p2;

	float fDistance;
	
	int iDiffX,iDiffY;

	printf("\nEnter coordinates of the first point\n");
	scanf("%d%d",&p1.iXcor,&p1.iYcor);

	printf("\nEnter coordinates of the second point\n");
	scanf("%d%d",&p2.iXcor,&p2.iYcor);

	iDiffX = p2.iXcor - p1.iXcor;
	iDiffY = p2.iYcor - p1.iYcor;

	fDistance = sqrt(((iDiffX)*(iDiffX)) + ((iDiffY)*(iDiffY)));

	printf("\nDistance between the two points is %g units\n",fDistance);

	return 0;
}

/*

$ ./a.out 

Enter coordinates of the first point
0 0

Enter coordinates of the second point
5 0

Distance between the two points is 5 units
$ ./a.out 

Enter coordinates of the first point
5 5

Enter coordinates of the second point
5 9

Distance between the two points is 4 units
$ ./a.out 

Enter coordinates of the first point
1 1

Enter coordinates of the second point
6 7

Distance between the two points is 7.81025 units
*/

