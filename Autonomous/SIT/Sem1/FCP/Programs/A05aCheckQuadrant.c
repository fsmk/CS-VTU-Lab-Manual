#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float fXcor,fYcor;
    printf("\nEnter the coordinates\n");
    scanf("%g%g",&fXcor,&fYcor);

    if(0 == fXcor && 0 ==fYcor)
    {
        printf("\n(%g,%g) is at origin\n",fXcor,fYcor);
    }
    else if(0 == fXcor)
    {
        printf("\n(%g,%g) is on Y-axis\n",fXcor,fYcor);
    }
    else if(0 == fYcor)
    {
        printf("\n(%g,%g) is on X-axis\n",fXcor,fYcor);
    }
    else if(fXcor > 0 && fYcor > 0)
    {
        printf("\n(%g,%g) is in Quadrant I\n",fXcor,fYcor);
    }
    else if(fXcor < 0 && fYcor > 0)
    {
        printf("\n(%g,%g) is in Quadrant II\n",fXcor,fYcor);
    }
    else if(fXcor < 0 && fYcor < 0)
    {
        printf("\n(%g,%g) is in Quadrant III\n",fXcor,fYcor);
    }
    else
    {
        printf("\n(%g,%g) is in Quadrant IV\n",fXcor,fYcor);
    }

    return 0;
}
/*
$ ./a.out 

Enter the coordinates
1.2 3.4

(1.2,3.4) is in Quadrant I
$ ./a.out 

Enter the coordinates
2.3 -4.5

(2.3,-4.5) is in Quadrant IV
$ ./a.out 

Enter the coordinates
-9.9 -6.5

(-9.9,-6.5) is in Quadrant III
$ ./a.out 

Enter the coordinates
-6.5 7.5

(-6.5,7.5) is in Quadrant II
$ ./a.out 

Enter the coordinates
5 0

(5,0) is on X-axis
$ ./a.out 

Enter the coordinates
0 9.6

(0,9.6) is on Y-axis
$ ./a.out 

Enter the coordinates
0 0

(0,0) is at origin

*/
