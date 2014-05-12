#include <stdio.h>
#include <math.h>

#define PI 3.1416

int main()
{
	float fAngD, fAngR;
	float fTerm, fNum, fDen, fVal;
	int i,iNum;

	printf("Enter the Angle ....\n");
	scanf("%f",&fAngD);

	printf("Angle = %f\n",fAngD);

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
	printf(" Calculated value is :Sin( %f ) = %f\n",fAngD,fVal);
	printf("Built In function value is :Sin( %f ) = %f\n",
					fAngD, sin(fAngR));
	return 0;
}




















