#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#define MAX 10

int s[MAX];  //Holds the info of what nodes are reachable

void bfs_traversal(int a[MAX][MAX],int n,int source)
{
	int q[MAX],f,r; //for Q operation
	int u,v; //Represent 2 vertices
	int i;//index variable

	for (i=0;i<n;i++)
		s[i]=0;//No node is visited in the beginning
	
	f=r=0;      //Q is Empty
	q[r]=source; //Insert source vertex into Q
	s[source]=1; // Add source to S

	while (f<=r)  // As long as Q is not Empty
	{
		u=q[f++];

		for ( v=0;v<n;v++)
		{

			//Find the nodes v which are adjacent to u
			if (a[u][v]==1 && s[v]==0)
			{
				s[v]=1;  //add v to S to indicate that v is visited
				q[++r]=v;//Insert new vertex into Q for exploration
			}
		}
	}
}

void main()
{
	int n;//No of nodes
	int a[MAX][MAX];//Adjacency matrix
	int source;

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
	cout<<"Enter the source node :" ;
	cin>>source;
	bfs_traversal(a,n,source);
	cout<<"The Nodes Reachable from Source Node"<<source<<endl;
	for (i=0;i<n;i++)
	{
		if ( (s[i]==1)  && (i!=source))
		cout<< "Node: " <<i<<endl;
	}
	getch();			
}
