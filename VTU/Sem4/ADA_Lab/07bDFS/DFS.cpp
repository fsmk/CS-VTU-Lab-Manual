#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 100;


void DepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n)
{

	int i;

	v[currentVertex] = 1;

	for (i=0; i<n; i++)
		if (g[currentVertex][i] && !v[i])
			DepthFirstSearch(i,v,g,n);
}

int main()
{
	int i,j,k;
	int visited[MAX];
	int graph[MAX][MAX];
	int numVert;

	cout << "Enter the number of vertices : ";
	cin >> numVert;

	for (i=0; i<numVert; i++)
		visited[i] = 0;

	cout << "Enter the adjacency matrix :\n";

	for (i=0; i<numVert; i++)
		for (j=0; j<numVert; j++)
			cin >> graph[i][j];

	for (i=0; i<numVert; i++)
	{
		for (k=0; k<numVert; k++)
		    visited[k] = 0;

		DepthFirstSearch(i,visited,graph,numVert);

		for (k=0; k<numVert; k++)
		{
		    if (!visited[k])
		    {
		        cout << "\nGraph is not connected since there is no path between " << i << " and " << k << endl;

		        exit(0);
		    }
		}
	}

	cout << "\nGraph is connected."<< endl;
	return 0;
}

/*
Enter the number of vertices : 4
Enter the adjacency matrix :
0 1 0 0
0 0 1 0
0 0 0 1
1 0 0 0

Graph is connected.

*/
