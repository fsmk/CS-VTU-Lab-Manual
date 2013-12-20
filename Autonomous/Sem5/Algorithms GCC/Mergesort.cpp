/******************************************************************************
* File                : Mergesort.c
* Description        : Program to sort an array using Merge Sort
* Author                : Manas Jayanth (prometheansacrifice)
* Compiler        : g++ (gcc compiler 4.6.3, Ubuntu 12.04)
* Date                : 20 December 2013
******************************************************************************/
#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <ctime>

using namespace std;

/**
 * Merges two sorted arrays
 */
void merge(int a[], int l, int m, int h)
{
	int i, j, k, c[10000]; //temporary array c[]
	i = k = l;
	j = m + 1;
	while(i <= m && j <= h)
	{
        // Picking the smallest of the first elements from the two arrays
        if(a[i] < a[j])
            c[k++] = a[i++];
		else
            c[k++] = a[j++];

	}

    // If array a[] is not empty yet, simply append all its elements
	while(i <= m)
        c[k++] = a[i++];

    // Similarly, with array b[]
	while(j <= h)
        c[k++] = a[j++];

    // Copy all the contents of c[] back to a[]
	for(i = l; i < k; i++)
        a[i] = c[i];
}


/**
 * The Mergesort algorithm
 */
void mergesort(int a[],int l,int h)
{
	int m;
	if(l < h)
	{
		m = (l+h) / 2;
		mergesort(a, l, m);
		mergesort(a, m + 1, h);
		merge(a, l, m, h);
	}
}

int main()
{
	int a[10000], i, j, n;
    struct timeval tv;
    double dStart,dEnd;

	cout << "MERGE SORT\n";
	cout << "\nEnter the size of array:";
	cin >> n;
	cout << "\nEnter the elements one by one\n";
	for(i = 0; i < n; i++)
	   cin >> a[i];

    gettimeofday(&tv,NULL);
    dStart = tv.tv_sec + (tv.tv_usec/1000000.0);

	mergesort(a, 0, n-1);

    gettimeofday(&tv,NULL);
    dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);

	cout << "\nArray after sorting: ";
	for(i = 0;i < n; i++)
	cout << a[i] << "   ";
	cout<<"\nTime = "<< dEnd-dStart << '\n';

	// Generate Random array
	for(i = 16; i < 10000; i*=2)
	{
        for(j = 0;j < i; j++)
            a[j] = rand() % 1000;

        gettimeofday(&tv,NULL);
        dStart = tv.tv_sec + (tv.tv_usec/1000000.0);

        mergesort(a, 0, i-1);

        gettimeofday(&tv,NULL);
        dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);

        
        cout<<"\nSize = " << i << "    " << "Time = "<< dEnd-dStart << '\n';
    }
	cout << endl;
    return 0;
}
