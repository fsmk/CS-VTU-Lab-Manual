//10  MST USING PRIMS ALGORITHM
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#define MAX 10

using namespace std;

void prims(int c[MAX][MAX],int n)
{
	int i,j,k,min_cost=0,lowcost[MAX],T[MAX],visited[MAX];
	cout << "Initialising lowcost[]...\n";
	for (i=2;i<=n;i++)
	{
		lowcost[i]=c[1][i];
		cout << lowcost[i] << "  ";
	}
	cout << "\n";

	// mark all nodes as unvisited
	cout << "Marking all nodes as visited...\n";
	for (i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	// Inititialize output tree
	cout << "Initialising the output tree...\n";
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
		cout << "Finding the least cost edge...\n";
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
		cout<<"<"<<T[j]<<","<<j<<"> Cost : " <<min <<"\n";
		//Update the distances
		cout << "Finding new least-cost edges from the new vertex...\n";
		for (int k=2;k<=n;k++)
		if ((visited[k]!=1)&&( c[j][k]<lowcost[k]))
		{
			cout << "One found : ";
			cout << "<"<<j<<","<<k<<"> with cost -> " <<c[j][k] <<"\n";
			lowcost[k]=c[j][k];
			T[k]=j;
		}
		cout << "Low cost contents :\n";
		for(i=2;i<=n;++i)
		{
			cout << lowcost[i] <<"  ";
		}
		cout <<endl;
	}//MST construction ends
	if (min_cost<9999)
	cout<<"\nSpanning tree exists and MST cost="<<min_cost;
	else
	cout<<"\nSpanning tree does not exists \n";
}

int main()
{
	int c[MAX][MAX],n,i,j;
	/*
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
	*/
	n = 4;
	srand(time(NULL));
	cout << "Creating the adjacency matrix :\n";
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		c[i][j] = rand() % 100;
	}
	cout << "Done.\n";
	cout << "Randomly inserting infinity edges...\nWaiting : ";
	for(int count=5; count > 0; count--)
	{
		i = rand()%n;
		system("sleep 1");
		j = rand()%n;
		c[i][j] = 9999;
		cout << count <<" ";
	}
	cout << "Done\n";
	cout << "Matrix :\n";
	for(i = 1; i <= n; ++i)
	{
		for(j = 1; j <= n; ++j)
		{
			cout << c[i][j] <<"\t";
		}
		cout << endl;
	}
	cout <<"\n";
	prims(c,n);
	return 0;
}
