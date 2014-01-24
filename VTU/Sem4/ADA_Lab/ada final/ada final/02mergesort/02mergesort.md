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
