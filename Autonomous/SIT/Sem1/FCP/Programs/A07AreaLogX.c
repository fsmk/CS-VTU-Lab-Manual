#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fnAreaTrapezoid(double, double, double);

int main(void)
{
    double i, dDx=0.1,dX1,dX2,dY1,dY2;
    double dLeft, dRight, dArea=0.0, dTotArea=0.0;

    printf("\nEnter the left and right limit\n");
    scanf("%lf%lf", &dLeft, &dRight);

    printf("\nEnter the increment dx\n");
    scanf("%lf", &dDx);

    for(i=dLeft;i<dRight;i+=dDx)
    {
        dX1 = i;
        dX2 = i+dDx;
        dY1 = log(dX1);
        dY2 = log(dX2);

        dArea = fnAreaTrapezoid(dY1,dY2,dDx);
        dTotArea += dArea;
    }

    printf("\nArea under the curve is %lf units\n", dTotArea);
    return 0;
}

double fnAreaTrapezoid(double dHeight1, double dHeight2, double dBase)
{
    double dArea;
    dArea = dBase * ((dHeight1 + dHeight2)/2);
    return dArea;
}

/*
$ ./a.out 

Enter the left and right limit
2 5

Enter the increment dx
0.001

Area under the curve is 3.660895 units

$ ./a.out 

Enter the left and right limit
1 2

Enter the increment dx
0.001

Area under the curve is 0.386988 units

$ ./a.out 

Enter the left and right limit
6 9

Enter the increment dx
0.01

Area under the curve is 6.046442 units
*/
