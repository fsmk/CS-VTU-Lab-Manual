#include <stdio.h>
#include <stdlib.h>

void fnCalcVolSurfArea(int, int, int, int*, int*);
int main(void)
{
    int iLength, iBreadth, iHeight, iSurfArea, iVolume;

    printf("\nEnter the length, breadth and height of the cuboid\n");
    scanf("%d%d%d", &iLength, &iBreadth, &iHeight);

    fnCalcVolSurfArea(iLength, iBreadth, iHeight, &iSurfArea, &iVolume);

    printf("\nSurface Area of cuboid is %d units\n", iSurfArea);
    printf("\nVolume of cuboid is %d cubic units\n", iVolume);
    return 0;
}

void fnCalcVolSurfArea(int iL, int iB, int iH, int *iA, int *iV)
{
    *iA = 2*iL*iB + 2*iB*iH + 2*iH*iL;
    *iV = iL*iB*iH;
}

/*
$ ./a.out 

Enter the length, breadth and height of the cuboid
3 4 5

Surface Area of cuboid is 94 units

Volume of cuboid is 60 cubic units
$ ./a.out 

Enter the length, breadth and height of the cuboid
6 6 6

Surface Area of cuboid is 216 units

Volume of cuboid is 216 cubic units
*/

