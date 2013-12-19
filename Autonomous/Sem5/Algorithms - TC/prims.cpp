//10  MST USING PRIMS ALGORITHM
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#define MAX 10

void prims(int c[MAX][MAX],int n)
{
	int i,j,k,min_cost=0,lowcost[MAX],T[MAX],visited[MAX];
	for (i=2;i<=n;i++)
	lowcost[i]=c[1][i];
	// mark all nodes as unvisited
	for (i=1;i<=n;i++)
	visited[i]=0;

	// Inititialize output tree
	for (i=1;i<=n;i++)
	T[i]=1;
	// consider node 1 as starting node
	visited[1]=1;

	for (int treesize=2;treesize<=n;treesize++)
	{
		//find node j with least value  min
		int min,j;
		min=lowcost[2];
		j=2;
		for (i=2;i<=n;i++)
		{ 
			if (lowcost[i]<min)
			{  
				min=lowcost[i];
				j=i;
			}
		}
		visited[j]=1;
		min_cost=min_cost+min;
		lowcost[j]=9999;
		cout<<"\n ("<<T[j]<<","<<j<<")\n ";
		//Update the distances
		for (int k=2;k<=n;k++)
		if ((visited[k]!=1)&&( c[j][k]<lowcost[k]))
		{
			lowcost[k]=c[j][k];
			T[k]=j;
		}
	}//MST construction ends
	if (min_cost<9999)
	cout<<"\nSpanning tree exists and MST cost="<<min_cost;
	else
	cout<<"\nSpanning tree does not exists \n";
}

void main()
{
	int c[MAX][MAX], n ;
	cout<<"Enter Number of nodes"<<endl;
	cin>>n;
	cout<<"Enter cost adj matrix( 9999 for infinity)"<<endl;
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			cin>>c[i][j];
		}
	}
	prims(c,n);
	getch();
}
