#include <stdio.h>
#include <math.h>

#define PI 3.1416

int main(void)
{
	float fAngD, fAngR;
	float fTerm, fNum, fDen, fVal;
	int i,iNum;

	printf("Enter the Angle ....\n");
	scanf("%f",&fAngD);

	printf("Angle = %g\n",fAngD);

	printf("Enter the Number of terms...\n");
	scanf("%d",&iNum);
	printf("No of terms = %d\n",iNum);

	fAngR= (fAngD*PI)/180 ;

	fNum=fAngR;
	fDen=1.0;
	fVal =0.0;
	fTerm=fNum/fDen;
	for(i=1;i<=iNum;i++)
	{
		fVal = fVal + fTerm;
		fNum = -fNum * fAngR * fAngR ;
		fDen = fDen * (2*i) * (2*i+1);
		fTerm = fNum/fDen;
	}
	printf(" Calculated value is :sin(%g) = %g\n",fAngD,fVal);
	printf("Built In function value is :sin(%g) = %g\n",fAngD, sin(fAngR));
	return 0;
}
/*
$ ./a.out 
Enter the Angle ....
60
Angle = 60
Enter the Number of terms...
3
No of terms = 3
 Calculated value is :sin(60) = 0.866297
Built In function value is :sin(60) = 0.866027
$ ./a.out 
Enter the Angle ....
60
Angle = 60
Enter the Number of terms...
8
No of terms = 8
 Calculated value is :sin(60) = 0.866027
Built In function value is :sin(60) = 0.866027
$ ./a.out 
Enter the Angle ....
90
Angle = 90
Enter the Number of terms...
8
No of terms = 8
 Calculated value is :sin(90) = 1
Built In function value is :sin(90) = 1
*/
