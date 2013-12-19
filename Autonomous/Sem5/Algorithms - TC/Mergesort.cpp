//1. MERGE SORT
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<iomanip.h>
#include <dos.h>
#include<time.h>

void merge(int a[],int l,int m,int h)
{
	int i,j,k,c[10000];
	i=k=l;
	j=m+1;
	while(i<=m && j<=h)
	{

		if(a[i]<a[j])
		c[k++]=a[i++];
		else
		c[k++]=a[j++];

	}
	while(i<=m)
	c[k++]=a[i++];
	while(j<=h)
	c[k++]=a[j++];
	for(i=l;i<k;i++)
	a[i]=c[i];
}

void mergesort(int a[],int l,int h)
{
	int m;
	if(l<h)
	{
		m=(l+h)/2;
		mergesort(a,l,m);
		mergesort(a,m+1,h);
		merge(a,l,m,h);
	}
}

void main()
{
	int a[10000],i,j,n;
	clock_t st,end;
	cout<<"MERGE SORT\n";
	cout<<"\nEnter the size of array:";
	cin>>n;
	cout<<"\nEnter the elements one by one\n";
	for(i=0;i<n;i++)
	   cin>>a[i];
	st=clock();
	delay(1000);
	mergesort(a,0,n-1);
	end=clock();
	cout<<"\nArray after sorting : ";
	for(i=0;i<n;i++)
	cout<<a[i]<<"   ";
	cout<<"\nTime= "<<(end-st)/CLK_TCK;
	// Generate Random array
	for(i=16;i<10000;i*=2)
	{
	for(j=0;j<i;j++)
	    a[j]=rand()%1000;
	st=clock();
	delay(1000);
	mergesort(a,0,n-1);
	end=clock();

	cout<<"\nsize="<<setw(7)<<i<<"   Time= "<<(end-st)/CLK_TCK;
	 }
	cout<<endl;
	getch();
}
