# include <stdio.h>
# include <math.h>
#define PI 3.1416
int main()
{
	float fAngR,fAngD;
	float fTerm,fNum,fDen;
	float fVal;
	int i;
	
	printf("\n Cos(angle)\t\tValue\t\tlibFn\n");
	for(fAngD = 0.0;fAngD <= 180.0;fAngD += 10.0)
	{
		fAngR = (fAngD*PI)/180 ;
		fNum = 1.0;
		fDen = 1.0;
		fVal  = 0.0;
		fTerm = fNum/fDen;
		for(i = 1;i<= 10;i++)
		{
			fVal  =  fVal + fTerm;
			fNum  =  -fNum * fAngR * fAngR ;
			fDen  =  fDen * (2*i) *(2*i-1);
			fTerm =  fNum/fDen;
		}
		printf("Cos(%03.0f) \t %12f \t %12f\n",fAngD,fVal,
							cos(fAngR));
	}
	return 0;
}








