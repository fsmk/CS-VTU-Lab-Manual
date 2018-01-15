## AIM : Compute the transitive closure of a given directed graph using Warshall's algorithm.

## DESCRIPTION :
>Warshall's algorithm determines whether there is a path between any two nodes in the graph. It does not give the number of the paths between two nodes. 
According to Warshall's algorith,a path exists between two vertices i, j, iff there is a path from i to j or there is a path from i to j through 1,..,k intermadiate nodes.</pre>


## ALGORITHM:

<pre>    n = |V|
	t(0) = the adjacency matrix for G

	for i in 1..n do
		t(0)[i,i] = True
	end for

	for k in 1..n do
		for i in 1..n do
			for j in 1..n do
				t(k)[i,j] = t(k-1)[i,j] OR
					(t(k-1)[i,k] AND t(k-1)[k,j])
			end for
		end for
	end for
	return t(n)</pre>

## CODE :

	#include<stdio.h>
	const int MAX = 100;

	void WarshallTransitiveClosure(int graph[MAX][MAX], int numVert);
	int main(void)
	{
		int i, j, numVert;
		int graph[MAX][MAX];

		printf("Warshall's Transitive Closure\n");
		printf("Enter the number of vertices : ");
		scanf("%d",&numVert);

		printf("Enter the adjacency matrix :-\n");
		for (i=0; i<numVert; i++)
			for (j=0; j<numVert; j++)
				scanf("%d",&graph[i][j]);

		WarshallTransitiveClosure(graph, numVert);

		printf("\nThe transitive closure for the given graph is :-\n");
		for (i=0; i<numVert; i++)
		{
			for (j=0; j<numVert; j++)
			{
				printf("%d\t",graph[i][j]);
			}
			printf("\n");
		}

		return 0;
	}

	void WarshallTransitiveClosure(int graph[MAX][MAX], int numVert)
	{
		int i,j,k;

		for (k=0; k<numVert; k++)
		{
			for (i=0; i<numVert; i++)
			{
				for (j=0; j<numVert; j++)
				{
					if (graph[i][j] || (graph[i][k] && graph[k][j]))
						graph[i][j] = 1;
				}
			}
		}
	}

## OUTPUT
Enter the number of vertices : 4
Enter the adjacency matrix :-
0 0 1 0
0 0 0 1
1 0 0 0
0 1 0 0

The transitive closure for the given graph is :-
1	0	1	0	
0	1	0	1	
1	0	1	0	
0	1	0	1	


Warshall's Transitive Closure
Enter the number of vertices : 4
Enter the adjacency matrix :-

0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0

The transitive closure for the given graph is :-
1	1	1	1	
1	1	1	1	
1	1	1	1	
1	1	1	1 
