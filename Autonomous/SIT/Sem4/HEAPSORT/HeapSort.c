/******************************************************************************
*File		: HeapSort.c
*Description	: Program to sort an array using Heap Sort
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: Friday 22 November 2013 
******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void fnGenRandInput(int [], int);
void fnDispArray( int [], int);
void fnMaxHeapify(int[],int,int);
void fnBuildMaxHeap(int[],int);
void fnHeapSort(int[],int);

/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{

	FILE *fp;
	struct timeval tv;
	double dStart,dEnd;
	int iaArr[500000],iNum,iPos,iKey,i,iChoice;

    for(;;)
    {
        printf("\n1.Plot the Graph\n2.HeapSort\n3.Exit");
        printf("\nEnter your choice\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                fp = fopen("HeapPlot.dat","w");

                for(i=100;i<100000;i+=100)
                {
                    fnGenRandInput(iaArr,i);

                    gettimeofday(&tv,NULL);
                    dStart = tv.tv_sec + (tv.tv_usec/1000000.0);
		    
		    fnHeapSort(iaArr,i);

                    gettimeofday(&tv,NULL);
                    dEnd = tv.tv_sec + (tv.tv_usec/1000000.0);

                    fprintf(fp,"%d\t%lf\n",i,dEnd-dStart);

                }
                fclose(fp);

                printf("\nData File generated and stored in file < HeapPlot.dat >.\n Use a plotting utility\n");
            break;

            case 2:
                printf("\nEnter the number of elements to sort\n");
                scanf("%d",&iNum);
                printf("\nUnsorted Array\n");
                fnGenRandInput(iaArr,iNum);
                fnDispArray(iaArr,iNum);
		fnHeapSort(iaArr,iNum);
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
*Function	: fnMaxHeapify
*Description	: Function to recreate a max heap
*Input parameters:
*	int a[] - Array to hold integers
*	int i	- start index of the Array 
*	int n	- end index of the Array 
*RETURNS	: no value
******************************************************************************/

void fnMaxHeapify(int a[],int i,int n)
{
	int l,r,largest,temp;
	l=2*i;
	r=(2*i)+1;
	if((l<=n)&& (a[l]>a[i]))
	{
		largest=l;
	}
	else
	largest=i;
	if((r<=n)&&(a[r]>a[largest]))
	largest=r;
	if(largest!=i)
	{
		temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		fnMaxHeapify(a,largest,n);
	}
}
/******************************************************************************
*Function	: fnBuildMaxHeap
*Description	: Function to create a max heap
*Input parameters:
*	int a[] - Array to hold integers
*	int n	- number of elements in the Array 
*RETURNS	: no value
******************************************************************************/

void fnBuildMaxHeap(int a[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	fnMaxHeapify(a,i,n);
}

/******************************************************************************
*Function	: fnHeapSort
*Description	: Function to sort an array using Heap Sort
*Input parameters:
*	int a[] - Array to hold integers
*	int n	- number of elements in the Array 
*RETURNS	: no value
******************************************************************************/
void fnHeapSort(int a[],int n)
{
	int temp,i;
	fnBuildMaxHeap(a,n);
	for(i=n;i>=2;i--)
	{
		temp=a[1];
		a[1]=a[i];
		a[i]=temp;
		fnMaxHeapify(a,1,i-1);
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
	for(i=1;i<=n;i++)
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

	for(i=1;i<=n;i++)
		printf(" %5d \n",X[i]);

}

