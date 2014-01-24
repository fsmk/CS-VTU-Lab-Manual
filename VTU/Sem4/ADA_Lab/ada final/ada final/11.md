#AIM: 
 Implement All-Pairs Shortest Paths Problem using Floyd's algorithm. 
Parallelize this algorithm, implement it using OpenMP and determine the 
speed-up achieved.

##DESCRIPTION:
The Floyd's algorithm is a graph analysis algorithm for finding shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles, see below) and also for finding transitive closure of a relation R. A single execution of the algorithm will find the lengths (summed weights) of the shortest paths between all pairs of vertices, though it does not return details of the paths themselves.

##ALGORITHM:
<pre>
1 let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)
2 for each vertex v
3    dist[v][v] ← 0
4 for each edge (u,v)
5    dist[u][v] ← w(u,v)  // the weight of the edge (u,v)
6 for k from 1 to |V|
7    for i from 1 to |V|
8       for j from 1 to |V|
9          if dist[i][j] > dist[i][k] + dist[k][j] 
10             dist[i][j] ← dist[i][k] + dist[k][j]
11         end if
</pre>


##CODE:
<pre>`#`include&lt;stdio.h> 
`#`include&lt;stdlib.h> 
`#`include&lt;sys/time.h> 
`#`include&lt;omp.h> </pre>

int min(int,int); 
<pre>int main() 
{ 
	int n,k,i,j,c[10][10]; 
	int tid; 
	omp_set_num_threads(0); 
	{ 
		tid=omp_get_thread_num(); 
		printf("Enter the number of nodes:"); 
		scanf("%d",&n); 
		printf("Enter the cost matrix:\n"); 
		for(i=0;i&lt;n;i++) 
		for(j=0;j&lt;n;j++) 
		      scanf("%d",&c[i][j]); 
		for(k=0;k&lt;n;k++) 
		{
    			for(i=0;i&lt;n;i++) 
			   	for(j=0;j&lt;n;j++) 
		       			c[i][j]=min(c[i][j],c[i][k]+c[k][j]); 
		} 
		printf("\n All pairs shortest path\n"); 
		for(i=0;i&lt;n;i++) 
		{
		       for(j=0;j&lt;n;j++) 
			printf("%d\t",c[i][j]); 
	 	       printf("\n"); 
		} 
	} 
	return 0; 
} 

int min(int a,int b)
 
{ 

  return(a&lt;b?a:b); 

}</pre>


##OUTPUT:
<pre>Enter the number of nodes:3 
Enter the cost matrix: 
5 6 7 
8 9 1 
2 3 4 

 All pairs shortest path 
5	6	7
3	4	1
2	3	4</pre>
