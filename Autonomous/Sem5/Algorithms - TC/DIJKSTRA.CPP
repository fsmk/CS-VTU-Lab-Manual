//5: DIJKSTRAS ALGORITHM
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#define MAX 10

int n,a[MAX][MAX],d[MAX],p[MAX];

void dijkstra(int source,int dest)
{
	int i,j,u,v,min;
	int s[MAX];//reachability Information
	for (i=0;i<n;i++)
	{
		d[i]=a[source][i];
		/*
		Stores the distances between all nodes from source.
		This is updated later as new and shorter paths are
		found.
		*/
		s[i]=0;
		/*
		Marking all nodes as unvisited
		*/
		p[i]=source;
		/*
		Records the path from source to dest.
		Initially no path exists from source to dest.
		Hence path takes from source to source itself.
		Later on, according to greedy technique, as partial solutions
		are created path[] contains path from source to various
		intermediate nodes
		*/
	}
	s[source]=1;//Add source to S
	for (i=1;i<n;i++)
	{
		//find u&d[u] such that d[u] is minimum and u is in V-S
		min=9999;
		u=-1;
		for (j=0;j<n;j++)
		{
			if( s[j]==0)
			{
				if (d[j]<min)
				{
					min=d[j];
					u=j;
				}
			}
		}
		if (u==-1) return;
			//Add u to s
			s[u]=1;
		if (u==dest) return;
			//find d[v] and p[v] for every v in V-S
			for (v=0; v<n;v++)
			/*
			Finding shorter paths from source to v using u as
			intermediate node
			*/
			{
				if (s[v]==0) //if v is unvisited
				{
					if (d[u]+a[u][v]<d[v])
					/*
					If the path through intermediate node
					is shorter
					*/
					{
						/*
						Then, update the distance matrix d[]
						and create a new path
						*/
						d[v]=d[u]+a[u][v];
						p[v]=u;
					}
				}
			}
	}
}

void main()
{
	int source,dest,i,j;
	clrscr();
	cout<<"Enter Number of nodes"<<endl;
	cin>>n;
	cout<<"Enter Cost Adjacency Matrix"<<endl;
	for (i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		cin>>a[i][j];
	}
	/*
	cout<<"Enter source Node ";
	cin>>source;
	cout<<"Enter dest";
	cin >>dest;
	cout<<endl; */

	for (source=0;source<n;source++)
	/*
	Trying all possible sources-destination combinations
	*/
	{
		cout<<"\n OUTPUT\n ";
		for ( dest=0;dest<n;dest++)
		{
			dijkstra(source,dest);
			if (d[dest]==9999)
			cout<<dest<<" is not reachable from "<<source<<endl;
			else
			{
				//cout<<"The shortest path is shown below"<<endl;
				int i=dest;
				if (i==source)
				cout<<i<<"<--"<<i<<"="<<d[dest]<<endl;
				else
				{
					while(i!=source)
					{
						cout<<i<<"<--";
						i=p[i];
					}
					cout<<i<<"="<<d[dest]<<endl;
				}
			}
		}  //dest loop ends
		cout<<"\n***************************\n";
	}// source loop ends
	getch();
}
