#include <stdio.h>


const int MAX = 100;

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

int main()
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

