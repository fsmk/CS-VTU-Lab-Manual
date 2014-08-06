# include <stdio.h>
# include <math.h>
int main()
{
	int n;
	int i,sum=0,j;
	int a[10];
	int x;

	printf("Enter the Number of Terms...\n");
	scanf("%d",&n);
	printf("N=%d\n",n);
	printf("Enter %d Co-Efficients...\n",n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter the Value of x...\n");
	scanf("%d",&x);
	printf("%d\n",x);
	for(i=0;i<=n;i++)
		sum = sum + a[i] * pow (x,i);
	printf("Result= %d\n",sum);
	return 0;
}
