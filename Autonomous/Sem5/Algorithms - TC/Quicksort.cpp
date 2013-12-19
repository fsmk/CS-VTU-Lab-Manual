 //2   Quick sort
#include <iostream.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <iomanip.h>
#include<stdlib.h>
#include<dos.h>

int partition(int a[],int low,int high)
{
	int i,j,temp,key;
	key=a[low];
	i=low;
	j=high+1;
	while(i<=j)
	{
	   do
	      i++;
	   while(key>a[i]);
	   do
	     j--;
	   while(key<a[j]);
	   if (i<j)
	   {temp=a[i];
	    a[i]=a[j];
	    a[j]=temp;
	    }
	}
	temp=a[low];
	a[low]=a[j];
	a[j]=temp;
	return j ;
}

void   quicksort(int a[],int low,int high )
{
	int p;

	if (low<high)
	{
		p=partition(a,low,high);
		quicksort(a,0,p);
		quicksort(a,p+1,high);
	}
}




void main()
{
	int a[100],n,i,j;
	clock_t st,end;

	/*  User INPUT    code 
	cout<<"\nEnter size of array--->";
	cin>>n;
	cout<<"\nEnter array Elements:";
	for ( i=0;i<n;i++)
		cin>>a[i];
	st=clock();
	delay(1000);
	quicksort(a,0,n-1);
	end=clock();
	cout<<"\n size="<< n<<" time ="<<(end-st)/CLK_TCK;
	cout<<"\nAfter Quick_sorting:";
	for ( i=0;i<n;i++)
	       cout<<a[i]<<"  ";    */
		                // Random Array
	clrscr();
	cout<<"\nEnter size of random array--->";
	cin>>n;
	for (i=0;i<n;i++)
		a[i]=rand()%100;
	cout<<"\nBefore Quick_sorting:\n";
	for ( i=0;i<n;i++)
		cout<<a[i]<<"  ";
	st=clock();
	delay(1000);
	quicksort(a,0,n-1);
	end=clock();
	cout<<"\nAfter Quick_sorting:\n";
	for ( i=0;i<n;i++)
		cout<<a[i]<<"  ";
	cout<<"\n size="<<n<<" time ="<<(end-st)/CLK_TCK;
	getch();
}
