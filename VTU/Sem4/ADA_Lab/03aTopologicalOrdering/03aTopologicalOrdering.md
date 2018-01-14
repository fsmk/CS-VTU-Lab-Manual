## AIM : To obtain the Topological ordering of vertices in a given digraph.
## DESCRIPTION :
>Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.Topological Sorting for a graph is not possible if the graph is not a DAG.
 Input parameters:
 int a[MAX][MAX]  - adjacency matrix of the input graph
 int n	- no of vertices in the graph
 
## ALGORITHM :

L  Empty list that will contain the sorted elements
S  Set of all nodes with no incoming edges
while S is non-empty do
    remove a node n from S
    add n to tail of L
    for each node m with an edge e from n to m do
        remove edge e from the graph
        if m has no other incoming edges then
            insert m into S
if graph has edges then
    return error (graph has at least one cycle)
else 
    return L (a topologically sorted order)</pre>



## CODE :

	#include <stdio.h>

	const int MAX = 10;
	void fnTopological(int a[MAX][MAX], int n);
	int main(void)
	{
		int a[MAX][MAX],n;
		int i,j;

		printf("Topological Sorting Algorithm -\n");
		printf("\nEnter the number of vertices : ");
		 scanf("%d",&n);

		printf("Enter the adjacency matrix -\n");
		for (i=0; i<n; i++) 
			for (j=0; j<n; j++)
				scanf("%d",&a[i][j]);

		fnTopological(a,n);
		printf("\n");
		return 0;
	}

	void fnTopological(int a[MAX][MAX], int n)
	{
		int in[MAX], out[MAX], stack[MAX], top=-1;
		int i,j,k=0;

		for (i=0;i<n;i++)
		{
			in[i] = 0;
			for (j=0; j<n; j++)
				if (a[j][i] == 1)
					in[i]++;
		}

		while(1)
		{
			for (i=0;i<n;i++)
			{
				if (in[i] == 0)
				{
					stack[++top] = i;
					in[i] = -1;
				}
			}

			if (top == -1)
				break;

			out[k] = stack[top--];

			for (i=0;i<n;i++)
			{
				if (a[out[k]][i] == 1)
					in[i]--;
			}
			k++;
		}

		printf("Topological Sorting (JOB SEQUENCE) is:- \n");
		for (i=0;i<k;i++)
			printf("%d ",out[i] + 1);
	}

## OUTPUT

Input Graph : 5 vertices
    0 0 1 0 0
    0 0 1 0 0
    0 0 0 1 1
    0 0 0 0 1
    0 0 0 0 0
    
Topological Sorting (JOB SEQUENCE) is:- 
2 1 3 4 5 </pre>
