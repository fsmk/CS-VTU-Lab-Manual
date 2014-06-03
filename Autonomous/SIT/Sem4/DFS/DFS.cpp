/******************************************************************************
*File		: DFS.cpp
*Description: Program to find all nodes reachable from a given node using DFS
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: Wednesday 27 November 2013 
******************************************************************************/
#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX = 100;

void fnDepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n);

/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{
	int i,j,k;
	int visited[MAX];
	int graph[MAX][MAX];
	int numVert, Vert;

	cout << "Enter the number of vertices : ";
	cin >> numVert;

	for (i=0; i<numVert; i++)
		visited[i] = 0;

	cout << "Enter the adjacency matrix :\n";

	for (i=0; i<numVert; i++)
		for (j=0; j<numVert; j++)
			cin >> graph[i][j];

	cout << "Enter the source vertex : ";
	cin >> Vert;

    fnDepthFirstSearch(Vert,visited,graph,numVert);

    for (k=0; k<numVert; k++)
    {
        if(visited[k])
        {
            cout << "\nVertex " << k+1 << " reachable " << endl;
        }
        else
        {
            cout << "\nVertex " << k+1 << " not reachable " << endl;
        }
    }

    return 0;
}

/******************************************************************************
*Function	: fnDepthFirstSearch
*Description	: Function to perform DFS traversal and mark visited vertices
*Input parameters:
*	int currentVertex	- source vertex
*	int v[]		- vector to store visited information
*	int g[][]	- adjacency matrix of the graph
*	int n		- no of vertices
*RETURNS	: void
******************************************************************************/

void fnDepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n)
{

	int i;

	v[currentVertex] = 1;

	for (i=0; i<n; i++)
		if (g[currentVertex][i] && !v[i])
			fnDepthFirstSearch(i,v,g,n);
}

/******************************************************************************
OUTPUT
SAMPLE 1

Enter the number of vertices : 4
Enter the adjacency matrix :
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter the starting vertex : 1

Vertex 1 reachable 

Vertex 2 reachable 

Vertex 3 reachable 

Vertex 4 reachable 

SAMPLE 2

Enter the number of vertices : 4
Enter the adjacency matrix :
0 1 0 0
1 0 0 0
0 0 0 1
0 0 1 0
Enter the starting vertex : 1

Vertex 1 reachable 

Vertex 2 reachable 

Vertex 3 not reachable 

Vertex 4 not reachable

SAMPLE 3

Enter the number of vertices : 4
Enter the adjacency matrix :
0 1 0 0
0 0 1 0
0 0 0 1
0 0 0 0
Enter the source vertex : 2

Vertex 1 not reachable 

Vertex 2 not reachable 

Vertex 3 reachable 

Vertex 4 reachable

SAMPLE 4

Enter the number of vertices : 4
Enter the adjacency matrix :
0 1 0 0
0 0 1 0
0 0 0 1
1 0 0 0
Enter the source vertex : 2

Vertex 1 reachable 

Vertex 2 reachable 

Vertex 3 reachable 

Vertex 4 reachable 
******************************************************************************/


