//11a . FLOYD Algo to find all pairs shortest path
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#define MAX 10

int min(int a,int b)
{
	return a<b?a:b;
}

void floyd(int n,int cost[MAX][MAX])
{
	int i,j,k,d[MAX][MAX]; //d Holds the shortest Distance
	// Make copy of Adjacency Matrix
	for ( i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		d[i][j]=cost[i][j];
	}
	//Find Soln to all pairs shortest paths problem
	for (k=0;k<n;k++)
	{
		for ( i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
		}
	}
	cout<<"DISTANCE MATRIX "<<endl;
	for ( i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		cout<<setw(5)<<d[i][j];
		cout<<endl;
	}
}

void main()
{
	int cost[MAX][MAX],n,i,j;
	cout<<"Enter Number of nodes"<<endl;
	cin>>n;
	cout<<"Enter Cost Adjacency Matrix"<<endl;
	for ( i=0;i<n;i++)
	{ 
		for ( j=0;j<n;j++)
		{
			cin>>cost[i][j];
		}
		cout<<endl;
	}
	floyd(n,cost);
	getch();
}
