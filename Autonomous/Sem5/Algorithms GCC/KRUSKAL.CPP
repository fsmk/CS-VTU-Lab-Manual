#include <iostream>
#include <iomanip>
#define MAX 10

using namespace std;

//function to find the root of of given vertex
int find(int v,int p[])
{
	/*
	Array p[] stores the parent node of a given node.
	Eg: if node 5 has node 2 as parent then,
	p[5] = 2
	*/
	while (p[v]!=v)
	v=p[v];

	return v;
}

// function to merge 2 trees into single tree
void union_ij(int i,int j,int p[])
{
	if (i<j)
	p[j]=i;
	else
	p[i]=j;
}

void min_span_tree(int n,int c[MAX][MAX])
{
	int count,i,j,p[MAX],min,u,v,k,t[MAX][2],cost;
	count=0;// Edges selected so far initialized to zero
	cost=0;//
	k=0;   //Points to the first Selected Edge of MST

	for(i=0;i<n;i++)
	/*
	Create forest with n vertices by making each node its own parent
	*/
	p[i]=i;

	// Selection of  n-1 Edges for MST
	while(count<n)
	{
		min=9999;
		for (i=0;i<n;i++)
		{
			for (j=0;j<n;j++)
			{
				if (c[i][j]<min)
				{
					min=c[i][j];
					u=i;
					v=j;
				}
			}
		}
		/*
		Above loops find the least cost edge
		*/

		if (min==9999) break;    //No more edges to select
		i=find(u,p);//Find root for vertex u
		j=find(v,p);//Find root for vertex v
		if (i!=j)
		{
			t[k][0]=u;
			t[k][1]=v;
			k++;
			count++;//Update no of edges selected
			cost=cost+min;//PUpdate cost of MST
			union_ij(i,j,p);//Merge 2 trees with roots i and j

		}
		c[u][v]=c[v][u]=9999;//Delete the edge <u,v>by storing big value
	}

	if (count==n-1)
	{
		cout<<"MST Exists and its Cost="<<cost<<endl;
		cout <<"Edges of MST are shown below"<<endl;
		for( k=0;k<n-1;k++)
		{
			cout<<"<"<<t[k][0]<<","<<t[k][1]<<">"<<endl;
		}
	}
	else
	{
		cout<<"Spanning Tree does not Exists"<<endl;
	}
}

int main()
{
	int i,u,v,m,n,c[MAX][MAX];
	cout<<"Enter Number of nodes"<<endl;
	cin>>n;
	cout<<"Enter Number of Edges"<<endl;
	cin>>m;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			c[i][j]=9999;
		}
	}
	for (i=1;i<=m;i++)
	{
		cout<<"Enter "<< i <<"Edge <u,v,cost> "<<endl;
		cin>>u;cin>>v;cin>>c[u][v];
		c[v][u]=c[u][v];
	}
	min_span_tree(n,c) ;
    return 0;
}
