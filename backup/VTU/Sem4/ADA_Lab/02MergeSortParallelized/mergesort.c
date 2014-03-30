#include<stdio.h> 
#include<stdlib.h> 
#include<sys/time.h> 
#include<omp.h> 

void simplemerge(int a[], int low, int mid, int high) 
{ 
	int i,j,k,c[20000]; 
	i=low; 
	j=mid+1; 
	k=low; 
	int tid; 
	omp_set_num_threads(10); 
	{ 
		tid=omp_get_thread_num(); 
		while(i<=mid&&j<=high) 
		{ 
			if(a[i]<a[j]) 
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
	while(i<=mid) 
	{ 
		c[k]=a[i]; 
		i++; 
		k++; 
	} 
	while(j<=high) 
	{ 
		c[k]=a[j]; 
		j++; 
		k++; 
	} 
	for(k=low;k<=high;k++) 
	a[k]=c[k]; 
} 

void merge(int a[],int low,int high) 
{ 
	int mid; 
	if(low<high) 
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
	for(i=0;i<n;i++) 
		a[i]=rand()%100; 
} 
int main() 
{ 
	FILE *fp; 
	int a[2000],i; 
	struct timeval tv; 
	double start, end, elapse; 
	fp=fopen("mergesort.txt","w"); 
	for(i=10;i<=1000;i+=10) 
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
} 
