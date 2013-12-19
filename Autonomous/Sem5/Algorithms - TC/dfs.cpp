//7b Check for graph connectivity using DFS  method
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#define MAX 10

int a[MAX][MAX],n,s[MAX];//a adjacency matrix and 
//s is status array of node visited or not

void dfs(int u)
{
	s[u]=1;
	for (int v=1;v<n;v++)
	{
		if (s[v]==0 && a[u][v]==1)
		{
			cout<<v<<"  ";
			dfs(v);
		}
	}
}


void graph_connectivity()
{ 
	int count=0; //counter for total num of connected components

	for (int i=0;i<n;i++)
	{
		if (s[i]==0)
		{
		count++;
		cout<<"\n"<<"connected comp "<<count <<" = "<<i<<" ";
		dfs(i);
		}
	}
	if (count>1)
	cout<<"\nGraph is not connected\n";
	else
	cout<<"\nGraph is connected\n";
}


void main()
{
	cout<<"Enter Number of nodes"<<endl;
	cin>>n;
	cout<<"Enter Adjacency Matrix"<<endl;
	for (int i=0;i<n;i++)
	{ 
		for (int j=0;j<n;j++)
		{
			cin>>a[i][j];
		}
		cout<<endl;
	}
	graph_connectivity();

	getch();
}
