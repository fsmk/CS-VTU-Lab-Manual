





###Aim:To Sort a given set of elements using the Quicksort method and determine the time required to sort the elements. Repeat the experiment for different values of n, the number of elements in the list to be sorted and plot a graph of the time taken versus n. The elements can be read from a file or can be generated using the random number generator.
###Description:
<p> The program is based on the Quicksort algorithm which is an instatiation of divide and conquer method of solving the problem. Here the given array is partitioned every time and the sub-array is sorted.Dividing is based on an element called pivot. A divide and conquer algorithm works by recursively breaking down a problem into two or more sub-problems of the same (or related) type, until these become simple enough to be solved directly. The solutions to the sub-problems are then combined to give a solution to the original problem.</p>

###Algorithm:

<pre>   1. Pick an element, called a pivot, from the list.
   2. Reorder the list so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.
   3. Recursively apply the above steps to the sub-list of elements with smaller values and separately the sub-list of elements with greater values.</pre>

###Code:

<pre>/******************************************************************************
*File		: QuickSort.c
*Description	: Program to sort an array using Quick Sort
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: 11 Nov 2013
******************************************************************************/

#include &lt;stdio.h>
#include &lt;stdlib.h>
#include &lt;sys/time.h>
#include &lt;time.h>

void fnGenRandInput(int [], int);
void fnDispArray( int [], int);
int fnPartition(int [], int , int );
void fnQuickSort(int [], int , int );
inline void fnSwap(int*, int*);


inline void fnSwap(int *a, int *b)
{
	int t = *a; *a = *b; *b = t;
}

/******************************************************************************
*Function	: main
*Input parameters:
*	int argc - no of commamd line arguments
*	char **argv - vector to store command line argumennts
*RETURNS	:	0 on success
******************************************************************************/

int main( int argc, char **argv)
{

	FILE *fp;
	struct timeval tv;
	double dStart,dEnd;
	int iaArr[500000],iNum,iPos,iKey,i,iChoice;

    for(;;)
    {
        printf("\n1.Plot the Graph\n2.QuickSort\n3.Exit");
        printf("\nEnter your choice\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                fp = fopen("QuickPlot.dat","w");

                for(i=100;i&lt;100000;i+=100)
                {
                    fnGenRandInput(iaArr,i);

                    gettimeofday(&tv,NULL);
                    dStart = tv.tv_sec + (tv.tv_usec/1000000.0);

                    fnQuickSort(iaArr,0,i-1);

                    gettimeofday(&tv,NULL);
                    dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);

                    fprintf(fp,"%d\t%lf\n",i,dEnd-dStart);

                }
                fclose(fp);

                printf("\nData File generated and stored in file < QuickPlot.dat >.\n Use a plotting utility\n");
            break;

            case 2:
                printf("\nEnter the number of elements to sort\n");
                scanf("%d",&iNum);
                printf("\nUnsorted Array\n");
                fnGenRandInput(iaArr,iNum);
                fnDispArray(iaArr,iNum);
                fnQuickSort(iaArr,0,iNum-1);
                printf("\nSorted Array\n");
                fnDispArray(iaArr,iNum);
            break;

            case 3:
                exit(0);
        }
    }

	return 0;
}


/******************************************************************************
*Function	: fnPartition
*Description	: Function to partition an iaArray using First element as Pivot
*Input parameters:
*	int a[] - iaArray to hold integers
*	int l	- start index of the subiaArray to be sorted
*	int r	- end index of the subiaArray to be sorted
*RETURNS	: integer value specifying the location of partition
******************************************************************************/

int fnPartition(int a[], int l, int r)
{
	int i,j,temp;
	int p;

	p = a[l];
	i = l;
	j = r+1;

	do
	{
		do { i++; } while (a[i] &lt; p);
		do { j--; } while (a[j] > p);

		fnSwap(&a[i], &a[j]);
	}
	while (i&lt;j);

	fnSwap(&a[i], &a[j]);
	fnSwap(&a[l], &a[j]);

	return j;
}

/******************************************************************************
*Function	: fnQuickSort
*Description	: Function to sort elements in an iaArray using Quick Sort
*Input parameters:
*	int a[] - iaArray to hold integers
*	int l	- start index of the subiaArray to be sorted
*	int r	- end index of the subiaArray to be sorted
*RETURNS	: no value
******************************************************************************/

void fnQuickSort(int a[], int l, int r)
{
	int s;

	if (l &lt; r)
	{
		s = fnPartition(a, l, r);
		fnQuickSort(a, l, s-1);
		fnQuickSort(a, s+1, r);
	}
}

/******************************************************************************
*Function	: GenRandInput
*Description	: Function to generate a fixed number of random elements
*Input parameters:
*	int X[] - array to hold integers
*	int n	- no of elements in the array
*RETURNS	:no return value
******************************************************************************/

void fnGenRandInput(int X[], int n)
{
	int i;

	srand(time(NULL));
	for(i=0;i&lt;n;i++)
	{
		X[i] = rand()%10000;
	}

}

/******************************************************************************
*Function	: DispArray
*Description	: Function to display elements of an array
*Input parameters:
*	int X[] - array to hold integers
*	int n	- no of elements in the array
*RETURNS	: no return value
******************************************************************************/

void fnDispArray( int X[], int n)
{
	int i;

	for(i=0;i&lt;n;i++)
		printf(" %5d \n",X[i]);

}








##AIM: 
Program to sort an array using Merge Sort

##DESCRIPTION: 
Merge sort is an O(n log n) comparison-based sorting algorithm. Most implementations produce a stable sort, meaning that the implementation preserves the input order of equal elements in the sorted output. It is a divide and conquer algorithm.


##ALGORITHM:

<pre>algorithm Mergesort(A[O .. n - 1])
//Sorts array A[O .. n - 1] by recursive mergesort
//Input: An array A[O .. n - 1] of orderable elements
//Output: Array A[O .. n - 1] sorted in nondecreasing order
ifn > 1
copy A[O .. Ln/2J -1]to B[O .. Ln/2J -1]
copy A[Ln/2J .. n -1] to C[o .. rn/21 -1]
Mergesort(B[O .. Ln/2J - 1])
Mergesort(C[O .. rn/21 -1])
Merge(B, C, A)

ALGORITHM
Merge(B[O .. p- 1], C[O .. q -1], A[O.. p + q -1])
//Merges two sorted arrays into one sorted array
//Input: Arrays B[O .. p -1] and C[O .. q -1] both sorted
//Output: Sorted array A[O .. p + q -1] of the elements of Band C
i +--0; j +--0; k +--0
while i &lt; pandj <q do
if B[i] :S C[j]
A[k] +- B[i]; i +- i
+1
+1
else A[k] +- C[j]; j +- j
k+-k+1
ifi = p
copy C[j .. q -1] to A[k .. p +q -1]
else copy B[i..p -1] to A[k .. p + q -1]</pre>


##CODE

mergesort.c:

 #include &lt;stdio.h&gt; 

 #include &lt;stdlib.h&gt; 

 #include &lt;sys/time.h&gt; 

 #include &lt;omp.h&gt; 

<pre>/******************************************************************************
*Function	: simplemerge
*Description	: Function to merge two sorted arrays
*Input parameters:
*	int a[] - iaArray to hold integers
*	int low	- start index of the subiaArray to be sorted
*	int mid	- mid index of the subiaArray to be sorted
*	int right	- end index of the subiaArray to be sorted
*RETURNS	: no value
******************************************************************************/</pre>

<pre>void simplemerge(int a[], int low, int mid, int high) 
{ 
	int i,j,k,c[20000]; 
	i=low; 
	j=mid+1; 
	k=low; 
	int tid; 
	omp_set_num_threads(10); 
	{ 
		tid=omp_get_thread_num(); 
		while(i&lt;=mid&&j&lt;=high) 
		{ 
			if(a[i] &lt; a[j]) 
			{ 
				c[k]=a[i]; 
				//printf("%d%d",tid,c[k]); 
				i++; 
				k++; 	 
			} 
			else 
			{ 
				c[k]=a[j]; 
				//printf("%d%d", tid, c[k]); 
				j++; 
				k++; 			 
			} 
		} 
	} 
	while(i&lt;=mid) 
	{ 
		c[k]=a[i]; 
		i++; 
		k++; 
	} 
	while(j&lt;=high) 
	{ 
		c[k]=a[j]; 
		j++; 
		k++; 
	} 
	for(k=low;k&lt;=high;k++) 
	a[k]=c[k]; 
} 

<pre>/******************************************************************************
*Function	: merge
*Description	: Function to sort elements in an iaArray using Quick Sort
*Input parameters:
	int a[] - iaArray to hold integers
	int low	- start index of the array to be sorted
	int high- end index of the array to be sorted
*RETURNS	: no value
******************************************************************************/</pre>

void merge(int a[],int low,int high) 
{ 
	int mid; 
	if(low &lt; high) 
	{ 
		mid=(low+high)/2; 
		merge(a,low,mid); 
		merge(a,mid+1,high); 
		simplemerge(a,low,mid,high); 
	} 
} 

void getnumber(int a[], int n) 
{ 
	int i; 
	for(i=0;i &lt; n;i++) 
		a[i]=rand()%100; 
} 

<pre>/******************************************************************************
*Function	: main
*Input parameters: no
*RETURNS	:	0 on success
******************************************************************************/</pre>
<pre>int main() 
{ 
	FILE *fp; 
	int a[2000],i; 
	struct timeval tv; 
	double start, end, elapse; 
	fp=fopen("mergesort.txt","w"); 
	for(i=10;i&lt;=1000;i+=10) 
	{ 
		getnumber(a,i); 
		gettimeofday(&tv,NULL); 
		start=tv.tv_sec+(tv.tv_usec/1000000.0); 
		merge(a,0,i-1); 
		gettimeofday(&tv,NULL); 
		end=tv.tv_sec+(tv.tv_usec/1000000.0); 
		elapse=end-start; 
		fprintf(fp,"%d\t%lf\n",i,elapse); 		 
	} 
	fclose(fp); 
	system("gnuplot"); 
	return 0; 
} </pre>


mergesort.gpl:

 # Gnuplot script file for plotting data in file "mergesort.txt"
 # This file is called       mergesort.gpl
set terminal png font arial
set title "Time Complexity for Merge Sort"
set autoscale
set xlabel "Size of Input"
set ylabel "Sorting Time (microseconds)"
set grid
set output "mergesort.png"
plot "mergesort.txt" t "Merge Sort" with lines


/**************************************************

###OUTPUT


mergesort.png






##AIM : To obtain the Topological ordering of vertices in a given digraph.
###DESCRIPTION :
<pre> Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge uv, vertex u comes before v in the ordering.Topological Sorting for a graph is not possible if the graph is not a DAG.
 Input parameters:
 int a[MAX][MAX]  - adjacency matrix of the input graph
 int n	- no of vertices in the graph</pre>
 
###ALGORITHM :

<pre>L ← Empty list that will contain the sorted elements
S ← Set of all nodes with no incoming edges
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



###CODE :

<pre>#include &lt;stdio.h>

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
	for (i=0; i&lt;n; i++) 
		for (j=0; j&lt;n; j++)
			scanf("%d",&a[i][j]);

	fnTopological(a,n);
	printf("\n");
	return 0;
}

void fnTopological(int a[MAX][MAX], int n)
{
	int in[MAX], out[MAX], stack[MAX], top=-1;
	int i,j,k=0;

	for (i=0;i&lt;n;i++)
	{
		in[i] = 0;
		for (j=0; j&lt;n; j++)
			if (a[j][i] == 1)
				in[i]++;
	}

	while(1)
	{
		for (i=0;i&lt;n;i++)
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

		for (i=0;i&lt;n;i++)
		{
			if (a[out[k]][i] == 1)
				in[i]--;
		}
		k++;
	}

	printf("Topological Sorting (JOB SEQUENCE) is:- \n");
	for (i=0;i&lt;k;i++)
		printf("%d ",out[i] + 1);
}

###OUTPUT

Input Graph : 5 vertices
    0 0 1 0 0
    0 0 1 0 0
    0 0 0 1 1
    0 0 0 0 1
    0 0 0 0 0
    
Topological Sorting (JOB SEQUENCE) is:- 
2 1 3 4 5 </pre>





##AIM : Compute the transitive closure of a given directed graph using Warshall's algorithm.

###DESCRIPTION :
<pre>Warshall's algorithm determines whether there is a path between any two nodes in the graph. It does not give the number of the paths between two nodes. 
According to Warshall's algorith,a path exists between two vertices i, j, iff there is a path from i to j or there is a path from i to j through 1,..,k intermadiate nodes.</pre>


###ALGORITHM:

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

###CODE :

<pre>#include <stdio.h>
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
	for (i=0; i&lt;numVert; i++)
		for (j=0; j&lt;numVert; j++)
			scanf("%d",&graph[i][j]);

	WarshallTransitiveClosure(graph, numVert);

	printf("\nThe transitive closure for the given graph is :-\n");
	for (i=0; i&lt;numVert; i++)
	{
		for (j=0; j&lt;numVert; j++)
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

	for (k=0; k&lt;numVert; k++)
	{
		for (i=0; i&lt;numVert; i++)
		{
			for (j=0; j&lt;numVert; j++)
			{
				if (graph[i][j] || (graph[i][k] && graph[k][j]))
					graph[i][j] = 1;
			}
		}
	}
}

###OUTPUT
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
1	1	1	1 </pre>	





#AIM: To solve 0/1 Knapsack problem using Dynamic Programming.
##Description:
<pre><b>The Knapsack problem is probably one of the most interesting and most popular in computer science, especially when we talk about dynamic programming.
The knapsack problem is a problem in combinatorial optimization. Given a set of items, each with a weight and a value,
determine the number of each item to include in a collection so that the total weight is less than or equal to a given limit and
the total value is as large as possible. 
It derives its name from the problem faced by someone who is constrained by a fixed-size knapsack and must fill it with the most valuable items.
<\pre>
###Basic Algorithm:
   <pre><b>input: 
    a set of items with weights and values
output: 
    the greatest combined value of a subset
  partition the set {1...n} into two sets A and B of approximately equal size
  compute the weights and values of all subsets of each set
  for each subset of A
    find the subset of B of greatest value such that the combined weight is less than W
  keep track of the greatest combined value seen so far
</b>
####ALGORITHM:
<pre><b>Input:
 Values (stored in array v or profit)
 Weights (stored in array w or weight)
 Number of distinct items (n)
 Knapsack capacity (W)
for j from 0 to W do
  m[0, j] = 0
end for 
for i from 1 to n do
  for j from 0 to W do
    if w[i] <= j then
      m[i, j] = max(m[i-1, j], m[i-1, j-w[i]] + v[i])
    else
      m[i, j] = m[i-1, j]
    end if
  end for
end for


###CODE:
<pre>
`#`include &lt;iostream>
`#`include &lt;cstdlib>
using namespace std;

<pre>const int MAX = 10;
inline int max(int a, int b);
void fnProfitTable(int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX]);
void fnSelectItems(int n,int c, int t[MAX][MAX], int w[MAX], int l[MAX]);<\pre>

/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/<\pre>
    int main(void)
    {
    	int i, j, totalProfit;
    	int weight[MAX];
    	int profit[MAX];
    	int capacity;
    	int num;
    	int loaded[MAX];
    	int table[MAX][MAX];
    	cout<<"Enter the maxium number of objects : ";
         cin >> num;
    
    	cout &lt;&lt; "Enter the weights : \n";
    	for (i=1; i<=num; i++)
	{
	    cout << "\nWeight " << i << ": ";
		cin >> weight[i];
    }
	cout &lt;&lt; "\nEnter the profits : \n";
	for (i=1; i&lt;=num; i++)
	{
	    cout &lt;&lt; "\nProfit " &lt;&lt; i &lt;&lt; ": ";
		cin >> profit[i];
    }
	cout &lt;&lt; "\nEnter the maximum capacity : ";
	cin >> capacity;


	totalProfit = 0;

	for( i=1; i&lt;=num; i++)
		loaded[i] = 0;

	fnProfitTable(weight,profit,num,capacity,table);
	fnSelectItems(num,capacity,table,weight,loaded);
	cout &lt;&lt; "Profit Matrix\n";
	for (i=0; i&lt;=num; i++)
	{
	    for(j=0; j&lt;=capacity; j++)
	    {
	        cout &lt;&lt;"\t"&lt;&lt;table[i][j];
	    }
	    cout &lt;&lt; endl;
	}

	cout &lt;&lt; "\nItem numbers which are loaded : \n{ ";
	for (i=1; i&lt;=num; i++)
	{
		if (loaded[i])
		{
			cout &lt;&lt;i &lt;&lt; " ";
			totalProfit += profit[i];
		}
	}
	cout &lt;&lt; "}" &lt;&lt; endl;

	cout &lt;&lt; "\nTotal Profit : " &lt;&lt; totalProfit &lt;&lt; endl;
	return 0;
}

inline int max(int a, int b)
{
	return a>b ? a : b;
}

/******************************************************************************
*Function	: fnProfitTable
*Description	: Function to construct the profit table 
*Input parameters:
*	int w[MAX]	-	weight vector
*	int p[MAX]	-	profit vector
*	int n	- no of items
*	int c	- knapsack capacity
*	int t[MAX][MAX] - profit table
*RETURNS	: no value
******************************************************************************/

void fnProfitTable(int w[MAX], int p[MAX], int n, int c, int t[MAX][MAX])
{
	int i,j;

	for (j=0; j&lt;=c; j++)
		t[0][j] = 0;

	for (i=0; i&lt;=n; i++)
		t[i][0] = 0;

	for (i=1; i&lt;=n; i++)
	{
		<pre>for (j=1; j&lt;=c; j++)
		{
			if (j-w[i] < 0)
				t[i][j] = t[i-1][j];
			else
				t[i][j] = max( t[i-1][j], p[i] + t[i-1][j-w[i]]);
		}
	}
}

/******************************************************************************
*Function	: fnSelectItems
*Description: Function to determine optimal subset that fits into the knapsack
*Input parameters:
*	int n	- no of items
*	int c	- knapsack capacity
*	int t[MAX][MAX] - profit table
*	int w[MAX]	-	weight vector
*	int l[MAX]	-	bit vector representing the optimal subset
*RETURNS	: no value
******************************************************************************/

void fnSelectItems(int n,int c, int t[MAX][MAX], int w[MAX], int l[MAX])
{
	int i,j;

	i = n;
	j = c;

	while (i >= 1 && j >= 1)
	{
			if (t[i][j] != t[i-1][j])
			{
				l[i] = 1;
				j = j - w[i];
				i--;
			}
			else
				i--;
	}
}
/******************************************************************************
Enter the maxium number of objects : 4
Enter the weights : 

Weight 1: 2

Weight 2: 1

Weight 3: 3

Weight 4: 2

Enter the profits : 

Profit 1: 12

Profit 2: 10

Profit 3: 20

Profit 4: 15

Enter the maximum capacity : 5
Profit Matrix
	0	  0	  0	  0	  0	  0
	0	  0	  12	12	12	12
	0	  10	12	22	22	22
	0	  10	12	22	30	32
	0	  10	15	25	30	37

Item numbers which are loaded : 
{ 1 2 4 }

Total Profit : 37
*****************************************************************************/





##AIM:Program 5. From a given vertex in a weighted connected graph, find shortest paths to other vertices using Dijkstra's algorithm.

###DESCRIPTION:
1. To find the shortest path between points, the weight or length of a path is calculated as the sum of the  weights of the edges in the path.
2. A path is a shortest path is there is no path from x to y with lower weight.
3. Dijkstra's algorithm finds the shortest path from x to y in order of increasing distance from x. That is, it chooses the first minimum edge, stores this value and adds the next minimum value from the next edge it selects.
4. It starts out at one vertex and branches out by selecting certain edges that lead to new vertices.
5. It is similar to the minimum spanning tree algorithm, in that it is "greedy", always choosing the closest edge in hopes of an optimal solution. 
###ALGORITHM:
<pre>
 function Dijkstra(Graph, source):
      for each vertex v in Graph:                                // Initializations
          dist[v]  := infinity ;                                  // Unknown distance function from 
                                                                 // source to v
          previous[v]  := undefined ;                             // Previous node in optimal path
      end for                                                    // from source
      
      dist[source]  := 0 ;                                        // Distance from source to source
      Q := the set of all nodes in Graph ;                       // All nodes in the graph are
                                                                 // unoptimized – thus are in Q
      while Q is not empty:                                      // The main loop
          u := vertex in Q with smallest distance in dist[] ;    // Source node in first case
          remove u from Q ;
          if dist[u] = infinity:
             break ;                                            // all remaining vertices are
          end if                                                 // inaccessible from source
          
          for each neighbor v of u:                              // where v has not yet been 
                                                                 // removed from Q.
              alt := dist[u] + dist_between(u, v) ;
              if alt < dist[v]:                                  // Relax (u,v,a)
                  dist[v]  := alt ;
                  previous[v]  := u ;
                  decrease-key v in Q;                           // Reorder v in the Queue
              end if
          end for
      end while
      return dist;
  endfunction
</pre>
###CODE:

<pre>/********************************************************************************
*File		: Dijkstra.cpp
*Description	: Program to find shortest paths to other vertices 
			  using Dijkstra's algorithm.
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: Friday 22 November 2013 

********************************************************************************/</pre>

<pre>
 #include&lt;ostream&gt;
 #include&lt;cstdio&gt;
using namespace std;

const int MAXNODES = 10,INF = 9999;

void fnDijkstra(int [][MAXNODES], int [], int [], int[], int, int, int);
</pre>
<pre>/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/</pre>
<pre>
int main(void)
{
    int n,cost[MAXNODES][MAXNODES],dist[MAXNODES],visited[MAXNODES],path[MAXNODES],i,j,source,dest;

    cout &lt;&lt; "\nEnter the number of nodes\n";
    cin >> n;
    cout &lt;&lt; "Enter the Cost Matrix\n" << endl;
    for (i=0;i&lt;n;i++)
        for (j=0;j&lt;n;j++)
            cin >> cost[i][j];

    
    for (source = 0; source &lt; n; source++)
    {
	getchar();
	cout &lt;&lt; "\n//For Source Vertex : " << source  << " shortest path to other vertices//"<< endl;
        for (dest=0; dest &lt; n; dest++)
        {
            fnDijkstra(cost,dist,path,visited,source,dest,n);


            if (dist[dest] == INF)
                cout &lt;&lt; dest &lt;&lt; " not reachable" &lt;&lt; endl;
            else
            {
                cout &lt;&lt; endl;
                i = dest;
		do
                {
                    cout &lt;&lt; i &lt;&lt; "<--";
                    i = path[i];
                }while (i!= source);
                cout &lt;&lt; i &lt;&lt; " = " &lt;&lt; dist[dest] &lt;&lt; endl;
            }
        }
	cout &lt;&lt; "Press Enter to continue...";
    }

    return 0;
}


</pre>
<pre>/******************************************************************************
*Function	: fnDijkstra
*Description	: Function to find shortest paths to other vertices 
        		  using Dijkstra's algorithm.
*Input parameters:
*	int c[][] - cost adjacency matrix of the graph
*	int d[] - distance vector
*	int p[] - path vector
*	int s[] - vector to store visited information
*	int so	- source vertex
*	int de	- destination vertex
*	int n	- no of vertices in the graph
*RETURNS	: no value
******************************************************************************/</pre>
<pre>
void fnDijkstra(int c[MAXNODES][MAXNODES], int d[MAXNODES], int p[MAXNODES], int s[MAXNODES], int so, int de, int n)
{
    int i,j,a,b,min;

    for (i=0;i&lt;n;i++)
    {
        s[i] = 0;
        d[i] = c[so][i];
        p[i] = so;
    }

    s[so] = 1;

    for (i=1;i&lt;n;i++)
    {
        min = INF;
        a = -1;
        for (j=0;j&lt;n;j++)
        {
            if (s[j] == 0)
            {
                if (d[j] &lt; min)
                {
                    min = d[j];
                    a = j;
                }
            }
        }

        if (a == -1) return;

        s[a] = 1;

        if (a == de) return;

        for (b=0;b&lt;n;b++)
        {
            if (s[b] == 0)
            {
                if (d[a] + c[a][b] &lt;d[b])
                {
                    d[b] = d[a] + c[a][b];
                    p[b] = a;
                }
            }
        }
    }
}


/******************************************************************************
</pre>
###Output
<pre>
Enter the number of nodes
5
Enter the Cost Matrix

0	3	9999	7	9999
3	0	4	2	9999
9999	4	0	5	6
7	2	5	0	4
9999	9999	6	4	0

//For Source Vertex : 0 shortest path to other vertices//

0<--0 = 0

1<--0 = 3

2<--1<--0 = 7

3<--1<--0 = 5

4<--3<--1<--0 = 9
Press Enter to continue...

//For Source Vertex : 1 shortest path to other vertices//

0<--1 = 3

1<--1 = 0

2<--1 = 4

3<--1 = 2

4<--3<--1 = 6
Press Enter to continue...

//For Source Vertex : 2 shortest path to other vertices//

0<--1<--2 = 7

1<--2 = 4

2<--2 = 0

3<--2 = 5

4<--2 = 6
Press Enter to continue...

//For Source Vertex : 3 shortest path to other vertices//

0<--1<--3 = 5

1<--3 = 2

2<--3 = 5

3<--3 = 0

4<--3 = 4
Press Enter to continue...

//For Source Vertex : 4 shortest path to other vertices//

0<--1<--3<--4 = 9

1<--3<--4 = 6

2<--4 = 6

3<--4 = 4

4<--4 = 0
Press Enter to continue...
******************************************************************************/

</pre>






##AIM: Find Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm.

###DESCRIPTION:

Kruskal's algorithm is an algorithm in graph theory that finds a minimum spanning tree for a connectedweighted graph. This means it finds a subset of the edges that forms a tree that includes every vertex, where the total weight of all the edges in the tree is minimized. If the graph is not connected, then it finds a minimum spanning forest (a minimum spanning tree for each connected component). Kruskal'salgorithm is an example of a greedy algorithm

###ALGORITHM:
<pre>
Let G = (V, E) be the given graph, with | V| = n
        {
         Start with a graph T = (V,$ \phi$) consisting of only the
         vertices of G and no edges; /* This can be viewed as n connected components, each vertex being one connected component */
       Arrange E in the order of increasing costs;
        for (i = 1, i$ \leq$n - 1, i + +)
        { 
         Select the next smallest cost edge;
         if (the edge connects two different connected components)
         add the edge to T;
        }
    } 
</pre> 

<pre>/********************************************************************************
*File          : Kruskal.cpp
*Description   : Program to find Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm.
*Author        : Prabodh C P
*Compiler      : gcc compiler 4.6.3, Ubuntu 12.04
*Date          : Friday 22 November 2013 
********************************************************************************/</pre>
`#`include &lt;iostream>

using namespace std;

const int MAXNODES = 10;

const int INF = 9999;

// Structure to represent an edge

struct edge

{

   int u, v, cost;

};

int fnFindParent(int v, int parent[]);

void fnUnion_ij(int i, int j, int parent[]);

void fnInputGraph(int m, edge e[]);

int fnGetMinEdge(edge e[], int n);

void kruskal(int n, edge e[], int m);

<pre>/******************************************************************************
*Function          : main
*Input parameters  :
    *int argc - no of commamd line arguments
    *char **argv - vector to store command line argumennts
*RETURNS           : 0 on success
******************************************************************************/</pre>
int main( int argc, char **argv)

{

    int n = 6, m = 10;
    edge e[2*MAXNODES] = {{0,1,6},{1,4,3},{4,5,6},{5,3,2},{3,0,5},{0,2,1},{1,2,5},{3,2,5},{4,2,6},{5,2,4}};

cout << "Enter the number of nodes : ";

cin >> n;

cout << "Enter the number of edges : ";

cin >> m;

fnInputGraph(m, e);

kruskal(n, e, m);

return 0;

}

<pre>/******************************************************************************
*Function         : fnFindParent
*Description      : Function to find parent of a given vertex
*Input parameters :
*	int v	- vertex for whom parent has to be found
*	int parent[] - parent vector
*RETURNS          : parent vertex
******************************************************************************/</pre>

int fnFindParent(int v, int parent[])

{

<pre>	while (parent[v] != v)
		v = parent[v];

	return v;</pre>

}

<pre>/******************************************************************************
*Function	: fnUnion_ij
*Description	: Function to merge two trees
*Input parameters:
*	int i, j - vertices to be merged
*	int parent[] - parent vector
*RETURNS	: no value
******************************************************************************/</pre>
void fnUnion_ij(int i, int j, int parent[])

{

<pre>	if(i &lt; j)
		parent[j] = i;
	else
		parent[i] = j;
</pre>
}

<pre>/******************************************************************************
*Function         : fnInputGraph
*Description      : Function to read a graph
*Input parameters :
*	int m	- no of edges in the graph
*	edge e[] - set of edges in the graph
*RETURNS          : no value
******************************************************************************/</pre>
void fnInputGraph(int m, edge e[])

{

<pre>	int i, j, k, cost;

	for(k=0; k&lt;m; k++)
	{
		cout << "Enter edge and cost in the form u, v, w : \n";
		cin >> i >> j >> cost;

		e[k].u = i;
		e[k].v = j;
		e[k].cost = cost;
	}</pre>
}

<pre>/******************************************************************************
*Function         : fnGetMinEdge(
*Description      : Function to find the least cost edge in the edge set
*Input parameters :
*	edge e[] - set of edges in the graph
*	int n	- no of vertices in the graph
*RETURNS          : index of least cost edge in the edge set
******************************************************************************/</pre>

int fnGetMinEdge(edge e[], int n)

{

<pre>	int i, small, pos;
	small = INF;
	pos = -1;

	for(i=0; i&lt;n; i++)
	{
		if(e[i].cost &lt; small)
		{
			small = e[i].cost;
			pos = i;
		}
	}

	return pos;</pre>
}

void kruskal(int n, edge e[], int m)

{

<pre>	int i, j, count, k, sum, u, v, t[MAXNODES][2], pos;
	int parent[MAXNODES];
	count = 0;
	k = 0;
	sum = 0;

	for(i=0; i&lt;n; i++)
	{
		parent[i] = i;
	}

	while(count != n-1)
	{
		pos = fnGetMinEdge(e,m);
		if(pos == -1)
		{
			break;
		}
		u = e[pos].u;
		v = e[pos].v;
		i = fnFindParent(u,parent);
		j = fnFindParent(v,parent);

		if(i != j)
		{
			t[k][0] = u;
			t[k][1] = v;
			k++;
			count++;
			sum += e[pos].cost;
			fnUnion_ij(i, j, parent);
		}
		e[pos].cost = INF;
	}

	if(count == n-1)
	{
		cout << "\nSpanning tree exists";
		cout << "\nThe Spanning tree is shown below\n";
		for(i=0; i&lt;n-1; i++)
			cout << t[i][0] << " " << t[i][1] << endl;

		cout << "\nCost of the spanning tree : " << sum;
	}
	else
		cout << "\nThe spanning tree does not exist";</pre>
}

##OUTPUT:

<pre>/******************************************************************************

Enter the number of nodes : 6
Enter the number of edges : 10
Enter edge and cost in the form u, v, w : 
0 1 6
Enter edge and cost in the form u, v, w : 
1 4 3 
Enter edge and cost in the form u, v, w : 
4 5 6 
Enter edge and cost in the form u, v, w : 
5 3 2
Enter edge and cost in the form u, v, w : 
3 0 5
Enter edge and cost in the form u, v, w : 
0 2 1  
Enter edge and cost in the form u, v, w : 
1 2 5
Enter edge and cost in the form u, v, w : 
3 2 5
Enter edge and cost in the form u, v, w : 
4 2 6
Enter edge and cost in the form u, v, w : 
5 2 4

Spanning tree exists
The Spanning tree is shown below
0 2
5 3
1 4
5 2
1 2

Cost of the spanning tree : 15
******************************************************************************/</pre>






##AIM: 
Program to find all nodes reachable from a given node using BFS

##DESCRIPTION: 
In graph theory, breadth-first search (BFS) is a strategy for searching in a graph when search is limited to essentially two operations: 

 + visit and inspect a node of a graph;

 + gain access to visit the nodes that neighbor the currently visited node. 

The BFS begins at a root node and inspects all the neighboring nodes. Then for each of those neighbor nodes in turn, it inspects their neighbor ##nodes which were unvisited, and so on.

##ALGORITHM:
<pre>Input: A graph G and a root v of G
1  procedure BFS(G,v) is
2      create a queue Q
3      create a set V
4      enqueue v onto Q
5      add v to V
6      while Q is not empty loop
7          t ← Q.dequeue()
8          if t is what we are looking for then
9              return t
10         end if
11         for all edges e in G.adjacentEdges(t) loop
12             u ← G.adjacentVertex(t,e)
13             if u is not in V then
14                  add u to V
15                  enqueue u onto Q
16             end if
17         end loop
18     end loop
19     return none
20 end BFS</pre>


##CODE
<pre>
 #include &lt;iostream&gt;
 #include &lt;cstdlib&gt;

 using namespace std;

 const int MAX = 100;
 void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n);

 class Queue

 {

	private:

		int cQueue[MAX];
		int front, rear;

	public:

		Queue();
		~Queue();
		int enqueue(int data);
		int dequeue();
		int empty() { return front == -1 ? 1 : 0;  };
 };</pre>

<pre>/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/</pre>
<pre>int main(void)
{
	int i,j;
	int graph[MAX][MAX];
	int visited[MAX];
	int numVert;
	int startVert;

	cout &lt;&lt; "Enter the number of vertices : ";
	cin &gt;&gt; numVert;

	cout &lt;&lt; "Enter the adjacency matrix :\n";
	for (i=0; i &lt; numVert; i++)
		visited[i] = 0;

	for (i=0; i&lt;numVert; i++)
		for (j=0; j&lt;numVert; j++)
			cin &gt;&gt; graph[i][j];

	cout &lt;&lt; "Enter the starting vertex : ";
	cin &gt;&gt; startVert;

	fnBreadthFirstSearchReach(startVert-1,graph,visited,numVert);

	cout &lt;&lt; "Vertices which can be reached from vertex " &lt;&lt; startVert &lt;&lt; " are :-" &lt;&lt; endl;
	for (i=0; i&lt;numVert; i++)
		if (visited[i])
			cout &lt;&lt; i+1 &lt;&lt; ", ";
	cout &lt;&lt; endl;
	return 0;
}

/*Constructor*/
Queue::Queue()
{
	front = rear = -1;
}

/*Destructor*/
Queue::~Queue()
{
}</pre>

<pre>
/******************************************************************************
*Function	: enqueue
*Description	: Function to insert an element at the rear of a Queue
*Input parameters:
*	int data	- element to be inserted into the queue
*RETURNS		: returns 1 on success and 0 if queue is full
******************************************************************************/</pre>

<pre>int Queue::enqueue(int data)

{
	if (front == (rear+1)%MAX)
		return 0;

	if (rear == -1)
		front = rear = 0;
	else
		rear = (rear+1)%MAX;

	cQueue[rear] = data;
	return 1;
}</pre>
<pre>/******************************************************************************
*Function	: dequeue
*Description	: Function to delete an element from the front of a Queue
*Input parameters	: no parameters
*RETURNS		: returns element deleted on success and -1 if queue is empty
******************************************************************************/</pre>

int Queue::dequeue()

{
	int data;

	if (front == -1)
		return -1;

	data = cQueue[front];

	if (front == rear)
		front = rear = -1;
	else
		front = (front+1)%MAX;

	return data;
}
<pre>/******************************************************************************
*Function	: fnBreadthFirstSearchReach
*Description	: Function to perform BFS traversal and mark visited vertices
*Input parameters:
*	int vertex	- source vertex
*	int g[][]	- adjacency matrix of the graph
*	int v[]		- vector to store visited information
	int n		- no of vertices
RETURNS		: void
******************************************************************************/</pre>

void fnBreadthFirstSearchReach(int vertex, int g[MAX][MAX], int v[MAX], int n)
{
	Queue verticesVisited;
	int frontVertex;
	int i;

	v[vertex] = 1;
	verticesVisited.enqueue(vertex);

	while (!verticesVisited.empty())
	{
		frontVertex = verticesVisited.dequeue();
		for (i=0; i&lt;n; i++)
		{
			if (g[frontVertex][i] && !v[i])
			{
				v[i] = 1;
				verticesVisited.enqueue(i);
			}
		}
	}
}
</pre>


/******************************************************************************

##OUTPUT
<pre>
SAMPLE 1

Enter the number of vertices : 4
Enter the adjacency matrix :
0 1 1 0
1 0 0 1
1 0 0 1
0 1 1 0
Enter the starting vertex : 1
Vertices which can be reached from vertex 1 are :-
1, 2, 3, 4, 

SAMPLE 2

Enter the number of vertices : 4
Enter the adjacency matrix :
0 1 0 0
1 0 0 0
0 0 0 1
0 0 1 0
Enter the starting vertex : 1
Vertices which can be reached from vertex 1 are :-
1, 2, 

SAMPLE 3

Enter the number of vertices : 4
Enter the adjacency matrix :
0 1 0 0
0 0 1 0
0 0 0 1
0 0 0 0
Enter the starting vertex : 2
Vertices which can be reached from vertex 2 are :-
2, 3, 4, 

SAMPLE 4

Enter the number of vertices : 4
Enter the adjacency matrix :
0 1 0 0
0 0 1 0
0 0 0 1
1 0 0 0
Enter the starting vertex : 2
Vertices which can be reached from vertex 2 are :-
1, 2, 3, 4, 

******************************************************************************/
</pre>





##AIM:Program 7.b. Check whether a given graph is connected or not using DFS method.
###DESCRIPTION:
Depth-first search is a graph traversal algorithm, which has a very wide application area. This algorithm may be used for finding out number of components of a graph, topological order of its nodes or detection of cycles.Itis an algorithm for traversing or searching a tree, tree structure, or graph. One starts at the root (selecting some node as the root in the graph case) and explores as far as possible along each branch before backtracking.

###ALGORITHM:
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

###CODE:
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

###OUTPUTS
<pre>
Enter the number of vertices : 4
Enter the adjacency matrix :
0 1 0 0
0 0 1 0
0 0 0 1
1 0 0 0

Graph is connected.
</pre>





#AIM:Program to solve Subset sum problem.
##Desrcription:
<b>In computer science, the subset sum problem is an important problem in complexity theory and cryptography. The problem is this: Given a set of integers, is there a non-empty subset whose sum is zero? For example, given the set {−7, −3, −2, 5, 8}, the answer is yes because the subset {−3, −2, 5} sums to zero. The problem is NP-complete.
<pre><b>Input: The number of elements.
       The Weights of each element.
       Total Required Weight.
Output:Subsets in which the sum of elements is equal to the given required weight(input).

###CODE:
<pre>#include &lt;iostream>
using namespace std;

<pre>// Constant definitions
const int MAX = 100;

// class definitions
class SubSet
{
	int stk[MAX], set[MAX];
	int size, top, count;
	public:
	SubSet()
	{
		top = -1;
		count = 0;
	}
	void getInfo(void);
	void push(int data);
	void pop(void);
	void display(void);
	int fnFindSubset(int pos, int sum);
};

/******************************************************************************
*Function	: getInfo
*Description: Function to read input
*Input parameters: no parameters
*RETURNS	: no value
******************************************************************************/

void SubSet :: getInfo(void)
{
	int i;
	cout &lt;&lt; "Enter the maximum number of elements : ";
	cin >> size;

	cout &lt;&lt; "Enter the weights of the elements : \n";
	for (i=1; i&lt;=size; i++)
		cin >> set[i];

}

/******************************************************************************
*Function	: push
*Description: Function to push an element on to the stack
*Input parameters: 
*int data	- value to be pushed on to the stack
*RETURNS	: no value
******************************************************************************/
void SubSet :: push(int data)
{
	stk[++top] = data;
}

/******************************************************************************
*Function	: pop
*Description: Function to pop an element from the stack
*Input parameters: no parameters
*RETURNS	: no value
******************************************************************************/

void SubSet :: pop(void)
{
	top--;
}

/******************************************************************************
*Function	: display
*Description: Function to display solution to sub set sum problem
*Input parameters: no parameters
*RETURNS	: no value
******************************************************************************/
void SubSet :: display()
{
	int i;
	cout &lt;&lt; "\nSOLUTION #"&lt;&lt; ++count &lt;&lt;" IS\n{ ";
	for (i=0; i&lt;=top; i++)
		cout &lt;&lt; stk[i] &lt;&lt; " ";

	cout &lt;&lt; "}" &lt;&lt; endl;
}

/******************************************************************************
*Function	: fnFindSubset
*Description	: Function to solve Subset sum problem.
*Input parameters:
*	int pos	- position
*	int sum	- sum of elements
*RETURNS	: returns 1 if solution exists or zero otherwise
******************************************************************************/
int SubSet :: fnFindSubset(int pos, int sum)
{
	int i;
	static int foundSoln = 0;

	if (sum>0)
	{
		for (i=pos; i&lt;=size; i++)
		{
			push(set[i]);
			fnFindSubset(i+1, sum - set[i]);
			pop();
		}
	}

	if (sum == 0)
	{
		display();
		foundSoln = 1;
	}

	return foundSoln;
}

/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{
	int i,sum;

	SubSet set1;
	
	set1.getInfo();
	cout &lt;&lt; "Enter the total required weight : ";
	cin >> sum;

	cout &lt;&lt; endl;

	if (!set1.fnFindSubset(1, sum))
		cout &lt;&lt; "\n\nThe given problem instance doesnt have any solution." &lt;&lt; endl;
	else
		cout &lt;&lt; "\n\nThe above-mentioned sets are the required solution to the given instance." &lt;&lt; endl;

	return 0;
}

/******************************************************************************
<b>OUTPUT<\b>
SAMPLE 1

Enter the maximum number of elements : 5
Enter the weights of the elements : 
1 2 3 4 5
Enter the total required weight : 5


SOLUTION #1 IS
{ 1 4 }

SOLUTION #2 IS
{ 2 3 }

SOLUTION #3 IS
{ 5 }

The above-mentioned sets are the required solution to the given instance.

SAMPLE 2

Enter the maximum number of elements : 4
Enter the weights of the elements : 
1 2 3 4 
Enter the total required weight : 11

The given problem instance doesnt have any solution.

******************************************************************************/





#AIM: 
Implement any scheme to find the optimal solution for the TRAVELLING SALESMAN PROBLEM and then solve the same problem instance using any approximation algorithm and determine the error in the approximation.

##DESCRIPTION:
The travelling salesman problem (TSP) asks the following question: Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city exactly once and returns to the origin city? It is an NP-hard problem in combinatorial optimization, important in operations research and theoretical computer science.

The TSP has several applications even in its purest formulation, such as planning, logistics, and the manufacture of microchips. Slightly modified, it appears as a sub-problem in many areas, such as DNA sequencing. In these applications, the concept city represents, for example, customers, soldering points, or DNA fragments, and the concept distance represents travelling times or cost, or a similarity measure between DNA fragments. In many applications, additional constraints such as limited resources or time windows make the problem considerably harder. TSP is a special case of the travelling purchaser problem.

In the theory of computational complexity, the decision version of the TSP (where, given a length L, the task is to decide whether the graph has any tour shorter than L) belongs to the class of NP-complete problems. Thus, it is possible that the worst-case running time for any algorithm for the TSP increases superpolynomially (or perhaps exponentially) with the number of cities.

<<<<<<< HEAD
##ALGORITHM:



=======
>>>>>>> 74d0a1aee4e4c4ebee6bb606b7c370784610b805
##CODE:
<pre>`#`include &lt;iostream>

`#`include &lt;iomanip>

using namespace std;

const int MAX = 10;
int path[MAX];
static int k=0;
int count = 0;
int perm[120][7];
int tourcost[120];</pre>

<pre>void swap (int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}</pre>

<pre>void DepthFirstSearch(int currentVertex, int v[MAX], int g[MAX][MAX], int n)
{
         int i;
         v[currentVertex]=1;
         path[k++]=currentVertex;
         for (i=0; i&lt;n; i++)
		if (g[currentVertex][i] && !v[i])
			DepthFirstSearch(i,v,g,n);
}</pre>

<pre>void permute(int *a, int i, int n)
{
   int j,k;
   if (i == n)
   {
       for(k=0;k&lt;=n;k++)
       {
           //start from 2nd column
           perm[count][k+1] = a[k];
       }
       count++;
   }
   else
   {
        for (j = i; j &lt;= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
}</pre>

<pre>int AppTSP(int n, int cost[MAX][MAX])
{
	int i, j, u, v, min,Excost=0;
	int sum, k, t[MAX][2], p[MAX], d[MAX], s[MAX],tree[MAX][MAX];
	int source, count;
	int visited[MAX];
	for (i=0; i&lt;n; i++)
		visited[i] = 0;

	min = 9999;
	source = 0;

	for(i=0; i&lt;n; i++)
	{
		for(j=0; j&lt;n; j++)
		{
			if(cost[i][j] != 0 && cost[i][j] &lt;= min)
			{
				min = cost[i][j];
				source = i;
			}
		}
	}

	for(i=0; i&lt;n; i++)
	{
		d[i] = cost[source][i];
		s[i] = 0;
		p[i] = source;
	}
	s[source] = 1;
	sum = 0;
	k = 0;
	count = 0;

	while (count != n-1)
	{
		min = 9999;
		u = -1;
		for(j=0; j&lt;n; j++)
		{
			if(s[j] == 0)
			{
				if(d[j] &lt;= min)
				{
					 min = d[j];
					 u = j;
				}
			}
		}

		t[k][0] = u;
		t[k][1] = p[u];
		k++;
		count++;
		sum += cost[u][p[u]];
		s[u] = 1;

		for(v=0; v&lt;n; v++)
		{
			if(s[v]==0 && cost[u][v]&lt;d[v])
			{
				d[v] = cost[u][v];
				p[v] = u;
			}
		}
	}

	for(i=0; i&lt;n; i++)
	{
	    for(j=0; j&lt;n; j++)
	    {
	        tree[i][j]=0;
	    }
	}

    if(sum >= 9999)
        cout &lt;&lt; "\nSpanning tree does not exist";
    else
    {
        for(i=0; i&lt;k; i++)
        {
            tree[t[i][0]][t[i][1]] = tree[t[i][1]][t[i][0]] =1;
        }
    }

    DepthFirstSearch(0,visited,tree,n);

    cout &lt;&lt; "\n The Approximate Minimum Cost tour is" &lt;&lt; endl;
    for(i=0;i&lt;=k;i++)
    {
        cout &lt;&lt; path[i] &lt;&lt; "->";
        Excost += cost[path[i]][path[i+1]];
    }
    cout &lt;&lt; path[0];
    Excost += cost[path[i]][path[0]];
    cout &lt;&lt; "\n The Approximate Minimum Cost of the tour is" &lt;&lt; Excost &lt;&lt; endl;
    return Excost;
}</pre>

<pre>int main(void)
{
	int a[MAX][MAX] = { { 0,  4,  8,  9, 12},
                    { 4,  0,  6,  8,  9},
                    { 8,  6,  0, 10, 11},
                    { 9,  8, 10,  0,  7},
                    {12,  9, 11,  7,  0}};

    int NumOfCity = 5;
	int interCities = 4,i,j;
	int mct=999,mctIndex,Appmct;

    //Source and destination is 0 remaining are intermediary cities
    int city[4] = {1,2,3,4};
    permute(city, 0, interCities-1);
    for(i=0;i&lt;24;i++)
    {
        for(j=0;j&lt;5;j++)
        {
            tourcost[i]+= a[perm[i][j]][perm[i][j+1]];
        }
        if( mct > tourcost[i])
        {
            mct = tourcost[i];
            mctIndex = i;
        }
    }

	cout << "\n The Exact Minimum Cost tour is" &lt;&lt; endl;
	for(i=0;i&lt;NumOfCity;i++)
	cout &lt;&lt; perm[mctIndex][i] &lt;&lt; "->";
	cout &lt;&lt; perm[mctIndex][i];
	cout &lt;&lt; "\n The Exact Minimum Cost of the tour is" &lt;&lt; mct &lt;&lt; endl;

	Appmct = AppTSP(NumOfCity,a);
	cout &lt;&lt; "\n The error in Approximation is " &lt;&lt; Appmct - mct &lt;&lt; " units" &lt;&lt; endl;
	cout &lt;&lt; "\n The Accuracy ratio is " &lt;&lt; (float)Appmct / mct &lt;&lt; endl;
	cout &lt;&lt; "\n The Approximate tour is "&lt;&lt;(((float)Appmct / mct) - 1)*100&lt;&lt; " percent longer than the optimal tour" &lt;&lt; endl;

	return 0;
}</pre>

##OUTPUT:
<pre> The Exact Minimum Cost tour is
  0->1->2->4->3->0
  The Exact Minimum Cost of the tour is37

  The Approximate Minimum Cost tour is
  0->1->2->3->4->0</pre>
  <pre>The Approximate Minimum Cost of the tour is39

  The error in Approximation is 2 units

  The Accuracy ratio is 1.05405

  The Approximate tour is 5.40541 percent longer than the optimal tour</pre>






##Aim:Find Minimum Cost Spanning Tree of a given undirected graph using Prim’s algorithm.
###Description:
<p>	The program uses prim's algorithm which is based on minimum spanning tree for a connected undirected graph.A predefinined cost adjecency matrix is the input.To find the minimum spanning tree, we choose the source node at random and in every step we find the node which is closest as well as having the least cost from the previously selected node.And also the cost of selected edge is being added to variable sum.Based on the value of sum, the presence of the minimum spanning tree is found.</p>

###Algorithm:

 <pre>    Input: A non-empty connected weighted graph with vertices V and edges E (the weights can be negative).
    Initialize: Vnew = {x}, where x is an arbitrary node (starting point) from V, Enew = {}
    Repeat until Vnew = V:
        Choose an edge {u, v} with minimal weight such that u is in Vnew and v is not (if there are multiple edges with the same weight, any of them may be picked)
        Add v to Vnew, and {u, v} to Enew
    Output: Vnew and Enew describe a minimal spanning tree</pre>

###Code:

<pre>/******************************************************************************
*File		: Prim.cpp
*Description	: Program to find Minimum Cost Spanning Tree of a given 
*				undirected graph using Prim's algorithm.
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: Friday 22 November 2013 
******************************************************************************/</pre>

<pre>#include&lt;iostream&gt; 
using namespace std;

const int MAXNODES = 10;
void fnPrims(int n, int cost[MAXNODES][MAXNODES]);
void fnGetMatrix(int n,int a[MAXNODES][MAXNODES]);

/******************************************************************************
*Function	: main
*Input parameters:
*	int argc - no of commamd line arguments
*	char **argv - vector to store command line argumennts
*RETURNS	:	0 on success
******************************************************************************/
int main( int argc, char **argv)

{
	int a[MAXNODES][MAXNODES] = {{0, 3, 9999, 7, 9999},
				{3, 0, 4, 2, 9999},
				{9999, 4, 0, 5, 6},
				{7, 2, 5, 0, 4},
				{9999, 9999, 6, 4, 0}};

	int n = 5;

	cout &lt;&lt; "Enter the number of vertices : ";
	cin >> n;

	fnGetMatrix(n,a);
	fnPrims(n,a);

	return 0;
}

/******************************************************************************
*Function	: fnPrims
*Description	: Function to find Minimum Cost Spanning Tree of a given 
*				undirected graph using Prims algorithm.
*Input parameters:
*	int n	- no of vertices in the graph
*	int cost[][] - cost adjacency matrix of the graph
*RETURNS	: no value
******************************************************************************/
void fnPrims(int n, int cost[MAXNODES][MAXNODES])
{
	int i, j, u, v, min;
	int sum, k, t[MAXNODES][2], p[MAXNODES], d[MAXNODES], s[MAXNODES];
	int source, count;

	min = 9999;
	source = 0;

	for(i=0; i&lt;n; i++)  //finding the node with minimum cost
	{
		for(j=0; j&lt;n; j++)
		{
			if(cost[i][j] != 0 && cost[i][j] &lt;= min) 
			{
				min = cost[i][j];
				source = i;
			}
		}
	}

	for(i=0; i&lt;n; i++)
	{
		d[i] = cost[source][i]; //initializing the array with th cost of all the nodes from source.
		s[i] = 0;
		p[i] = source;
	}
	s[source] = 1;
	sum = 0;
	k = 0;
	count = 0;

	while (count != n-1)
	{
		min = 9999;
		u = -1;
		for(j=0; j&lt;n; j++)
		{
			if(s[j] == 0)
			{
				if(d[j] &lt;= min)
				{
					 min = d[j];
					 u = j;
				}
			}
		}

		t[k][0] = u;
		t[k][1] = p[u];
		k++;
		count++;
		sum += cost[u][p[u]];
		s[u] = 1;

		for(v=0; v&lt;n; v++)
		{
			if(s[v]==0 && cost[u][v]&lt;d[v])
			{
				d[v] = cost[u][v];
				p[v] = u;
			}
		}
	}

	if(sum >= 9999)
		cout &lt;&lt; "\nSpanning tree does not exist\n";
	else
	{
		cout &lt;&lt; "\nThe spanning tree exists and minimum cost spanning tree is \n";
		for(i=0; i&lt;k; i++)
			cout &lt;&lt; t[i][1] &lt;&lt; " " &lt;&lt; t[i][0] &lt;&lt; endl;

		cout &lt;&lt; "\nThe cost of the minimum cost spanning tree is " &lt;&lt; sum &lt;&lt; endl;
	}
}

/******************************************************************************
*Function	: fnGetMatrix
*Description	: Function to read cost adjacency matrix of the graph
*Input parameters:
*	int n	- no of vertices in the graph
*	int a[][] - cost adjacency matrix of the graph
*RETURNS	: no value
******************************************************************************/
void fnGetMatrix(int n,int a[MAXNODES][MAXNODES])
{
	int i, j;

    cout &lt;&lt; "Enter the Cost Adjacency Matrix" &lt;&lt; endl;
	for(i=0; i&lt;n; i++)
		for(j=0; j&lt;n; j++)
			cin >> a[i][j];
}

/******************************************************************************
Output Sample 2:
Enter the number of vertices : 5
Enter the Cost Adjacency Matrix

0	3	9999	7	9999
3	0	4	2	9999
9999	4	0	5	6
7	2	5	0	4
9999	9999	6	4	0

The spanning tree exists and minimum cost spanning tree is 
3 1
1 0
3 4
1 2

The cost of the minimum cost spanning tree is 13

Output Sample 2:
Enter the number of vertices : 5
Enter the Cost Adjacency Matrix

0	3	9999	7	9999
3	0	9999	2	9999
9999	9999	0	9999	9999
7	2	9999	0	4
9999	9999	9999	4	0

Spanning tree does not exist
******************************************************************************/</pre>





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






#AIM: Program to solve N Queens problem using backtracking.

##DESCRIPTION:
Given a CHESS BOARD of size N*N,we are supposed to place N QUEEN's such that no QUEEN is in an attacking position.

BACKTRACKING:Backtracking is a general algorithm for finding all (or some) solutions to some computational problem, that incrementally builds candidates to the solutions, and abandons each partial candidate c ("backtracks") as soon as it determines that c cannot possibly be completed to a valid solution.
##ALGORITHM:
<pre>1) Start in the leftmost column
2) If all queens are placed
    return true
3) Try all rows in the current column.  Do following for every tried row.
    a) If the queen can be placed safely in this row then mark this [row, 
        column] as part of the solution and recursively check if placing  
        queen here leads to a solution.
    b) If placing queen in [row, column] leads to a solution then return 
        true.
    c) If placing queen doesn't lead to a solution then umark this [row, 
        column] (Backtrack) and go to step (a) to try other rows.
3) If all rows have been tried and nothing worked, return false to trigger 
    backtracking.</pre>
##CODE
`#`include &lt;iostream>

`#`include &lt;cstdlib>

using namespace std;

const int MAX = 10;

int SolnCount =0;

void fnChessBoardShow(int n, int row[MAX]);
bool fnCheckPlace(int KthQueen, int ColNum, int row[MAX]);
int NQueen(int k,int n, int row[MAX]);

<pre>/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/</pre>
int main(void)

{

	int n;
	int row[MAX];
	cout << "Enter the number of queens : ";
	cin >> n;
         if (!NQueen(0,n,row))
		cout << "No solution exists for the given problem instance." << endl;
	else
		cout << "Number of solution for the given problem instance is : " << SolnCount << endl;
         return 0;
}
<pre>/******************************************************************************
*Function	: NQueen
*Description	: Function to place n queens on a nxn chess board without any 
*					queen attacking any other queen 
*Input parameters:
*	int k	-	kth queen
*	int n	- no of queens
*	int row[MAX] - vector containing column numbers of each queen
*RETURNS	: returns 1 if solution exists or zero otherwise
******************************************************************************/</pre>

<pre>int NQueen(int k,int n, int row[MAX])

{
	static int flag;
	for(int i=0;i&lt;n;i++)
	{
		if(fnCheckPlace(k,i,row) == true)
		{
			row[k] = i;
			if(k == n-1)
			{
				fnChessBoardShow(n,row);
				SolnCount++;
				flag = 1;
				return flag;
			}
			NQueen(k+1, n, row);
		}
	}
	return flag;
}</pre>
<pre>/******************************************************************************
*Function	: fnCheckPlace
*Description: Function to check whether a kth queen can be palced in a specific 
*					column or not
*Input parameters:
*	int KthQueen	-	kth queen
*	int ColNum		- columnn number
*	int row[MAX] 	- vector containing column numbers of each queen
*RETURNS	: returns true if the queen can be palced or false otherwise
******************************************************************************/</pre>
bool fnCheckPlace(int KthQueen, int ColNum, int row[MAX])

{

	for(int i=0; i<KthQueen; i++)
	{
		if(row[i] == ColNum || abs(row[i]-ColNum) == abs(i-KthQueen))
			return false;
	}

	return true;
}

<pre>/******************************************************************************
*Function	: fnChessBoardShow
*Description: Function to graphically display solution to n queens problem
*Input parameters:
*	int n	- no of queens
*	int row[MAX] 	- vector containing column numbers of each queen
*RETURNS	: no value
******************************************************************************/</pre>

void fnChessBoardShow(int n, int row[MAX])

{
	cout << "\nSolution #" << SolnCount+1 << endl << endl;

	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (j == row[i])
				cout << "Q ";
		   else
				cout << "# ";
		}
		cout << endl;
	}
	cout << endl;

}
<pre>/******************************************************************************
OUTPUT
SAMPLE 1</pre>

Enter the number of queens : 4

Solution #1

<pre># Q # # 
# # # Q 
Q # # # 
# # Q # </pre>


Solution #2

<pre># # Q # 
Q # # # 
# # # Q 
# Q # # </pre>

Number of solution for the given problem instance is : 2

SAMPLE 2

<pre>Enter the number of queens : 3
No solution exists for the given problem instance.</pre>

******************************************************************************/