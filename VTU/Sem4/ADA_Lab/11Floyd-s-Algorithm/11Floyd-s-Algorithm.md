#AIM: 
Implement All-Pairs Shortest Paths Problem using Floyd's algorithm. 
Parallelize this algorithm, implement it using OpenMP and determine the 
speed-up achieved.

## DESCRIPTION:
>The Floyd's algorithm is a graph analysis algorithm for finding shortest paths in a weighted graph with positive or negative edge weights (but with no negative cycles, see below) and also for finding transitive closure of a relation R. A single execution of the algorithm will find the lengths (summed weights) of the shortest paths between all pairs of vertices, though it does not return details of the paths themselves.

## ALGORITHM:
	 let dist be a |V| x |V| array of minimum distances initialized to infinity
	 for each vertex v
	    dist[v][v] <- 0
	 for each edge (u,v)
	    dist[u][v] <- w(u,v)  // the weight of the edge (u,v)
	 for k from 1 to |V|
	    for i from 1 to |V|
	       for j from 1 to |V|
	          if dist[i][j] > dist[i][k] + dist[k][j] 
	             dist[i][j] <- dist[i][k] + dist[k][j]
	         end if



## CODE:
	#include<stdio.h> 
	#include<stdlib.h> 
	#include<sys/time.h> 
	#include<omp.h>

	int min(int,int); 
	int main() 
	{ 
		int n,k,i,j,c[10][10]; 
		int tid; 
		omp_set_num_threads(0); 
		{ 
			tid=omp_get_thread_num(); 
			printf("Enter the number of nodes:"); 
			scanf("%d",&n); 
			printf("Enter the cost matrix:\n"); 
			for(i=0;i<n;i++) 
			for(j=0;j<n;j++) 
			      scanf("%d",&c[i][j]); 
			for(k=0;k<n;k++) 
			{
	    			for(i=0;i<n;i++) 
				   	for(j=0;j<n;j++) 
			       			c[i][j]=min(c[i][j],c[i][k]+c[k][j]); 
			} 
			printf("\n All pairs shortest path\n"); 
			for(i=0;i<n;i++) 
			{
			       for(j=0;j<n;j++) 
				printf("%d\t",c[i][j]); 
		 	       printf("\n"); 
			} 
		} 
		return 0; 
	} 

	int min(int a,int b)
	 
	{ 

	  return(a<b?a:b); 

	}


## OUTPUT:
Enter the number of nodes:3 

Enter the cost matrix: 

5 6 7 

8 9 1 

2 3 4 

 All pairs shortest path 

5	6	7

3	4	1

2	3	4
