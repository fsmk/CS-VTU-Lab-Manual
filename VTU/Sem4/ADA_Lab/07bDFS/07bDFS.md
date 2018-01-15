## AIM:Program 7.b. Check whether a given graph is connected or not using DFS method.
## DESCRIPTION:
>Depth-first search is a graph traversal algorithm, which has a very wide application area. This algorithm may be used for finding out number of components of a graph, topological order of its nodes or detection of cycles.Itis an algorithm for traversing or searching a tree, tree structure, or graph. One starts at the root (selecting some node as the root in the graph case) and explores as far as possible along each branch before backtracking.

## ALGORITHM:
<pre>
 DFS(G,v)   ( v is the vertex where the search starts )
         Stack S := {};   ( start with an empty stack )
         for each vertex u, set visited[u] := false;
         push S, v;
         while (S is not empty) do
            u := pop S;
            if (not visited[u]) then
               visited[u] := true;
               for each unvisited neighbour w of u
                  push S, w;
            end if
         end while
      END DFS()
</pre>

## CODE:
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

## OUTPUTS

Enter the number of vertices : 4

Enter the adjacency matrix :

0 1 0 0

0 0 1 0

0 0 0 1

1 0 0 0


Graph is connected.

