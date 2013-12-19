//4.  Knapsack problem By dynamic programming
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#define MAX 10

int v[MAX][MAX];

int max(int a,int b)
{   return a>b ?a:b;   }

void knapsack(int w[],int p[],int n,int m)
{
	for (int i=0;i<=n;i++)
	{
		for (int j=0;j<=m;j++)
		{
			if (i==0||j==0)
			    v[i][j]=0;
			else if  (j < w[i])
			       v[i][j]= v[i-1][j];
			      else
			    v[i][j]=max(v[i-1][j], v[i-1][j-w[i]]+p[i]);
		}
	}
}

void main()
{
	int i,j,m,n,w[MAX],p[MAX],x[MAX];
	cout<<"Enter Number of objects:"<<endl;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cout<<"Enter Weights  of "<<i<<" th object:";
		cin>>w[i];
	}
	for(i=1;i<=n;i++)
	{
		cout<<"Enter Profit of "<<i<<" th object:";
		cin>>p[i];
	}

	cout<<"Enter Capacity of Knapsack : ";
	cin>>m;
	// output
	knapsack(w,p,n,m);
	//object selection;
	for( i=0;i<=n;i++)
	{  
		for (j=0;j<=m;j++)
		cout<<setw(4)<<v[i][j]<<" | ";
		cout<<endl;
	}
	cout<<"Optimal Solution is "<<v[n][m]<<endl;
	for (i=0;i<=n;i++)
	x[i]=0;
	i=n;
	j=m;
	while (i!=0 && j!=0)
	{
		if (v[i][j]!=v[i-1][j])
		{
			x[i]=1;
			j=j-w[i];
		}
		i=i-1;
	}

	for (i=1;i<=n;i++)
	cout<<"X["<<i<<"]="<<x[i]<<endl;
	getch();
}
