//11b. WARSHALL algo to find Path Matrix
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#define MAX 10

void warshall(int a[MAX][MAX],int n)
{  
	int i,j,k,p[MAX][MAX];
	//Find Trasitive closure (path matrix)
	// Make copy of Adjacency Matrix
	for ( i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		p[i][j]=a[i][j];
	}
	for (k=0;k<n;k++)
	{
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			if (p[i][k]==1 && p[k][j]==1)
			p[i][j]=1;
		}
	}
	cout<<"PATH  MATRIX "<<endl;
	for ( i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		cout<<p[i][j]<<" ";
		cout<<endl;
	}
}

void main()
{
	int n,a[MAX][MAX],i,j;
	cout<<"Enter Number of nodes"<<endl;
	cin>>n;
	cout<<"Enter Adjacency Matrix"<<endl;
	for ( i=0;i<n;i++)
	{ 
		for ( j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
		cout<<endl;
	}
	warshall(a,n);
	getch();
}
