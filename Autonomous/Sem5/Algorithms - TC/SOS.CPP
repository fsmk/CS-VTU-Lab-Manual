#include <iostream.h>
#include <conio.h>
#define  MAX 10

int w[MAX],x[MAX],d,count=0;

void sumofsubset(int cs,int k,int r)
{
	int i;
	x[k]=1;// include kth element
	/*
	First we check if the new item itself leads to the solution
	*/
	if (cs+w[k]==d)
	{
		count++;
		cout<< "Subset Solution=";
		cout<<"{ ";
		for(i=1;i<=k;i++)
		if (x[i]==1)
		cout<< w[i]<<" " ;
		cout<<"}\n";
	}
	/*
	If it doesn't then we check if the next item can be considered.
	If yes then we sos() is called again which temporarily accepts this
	item and repeats the proces all over again.
	*/
	else
	if (cs+w[k]+w[k+1]<=d)
	{      
		sumofsubset(cs+w[k],k+1,r-w[k]);
	}
	else
	{
		//Nothing
		/*
		Because if 'k+1'th item doesnot fit in, k+2 clearly cant
		as the array w[] is sorted in ascending order.
		'k'th item fits because when 'k'th item is passed to the 
		function, it is seen to it beforehand that 'k'th item fits.
		Before every call to sos(), this checking can be seen.
		*/
	}

	/*
	This is the second half where we reject the item and carry on further
	with the rest of the items in the array. We start with the 'k+1' th item
	i.e. the next item.
	*/
	if ((cs+r-w[k]>=d) && (cs+w[k+1]<=d))
	/*
	Note :
	This is an if condition and NOT else if.
	This is because this condition has to be executed regardless
	of the failure of the previous if(cs+w[k]==d).
	Donot make it an 'else if'
	*/
	{
		/*
		The addditional condition (cs+r-w[k]>=d) only checks if
		the rest of items can really add up to the desired sum.
		*/
		x[k]=0; // exclude kth element
		sumofsubset(cs,k+1,r-w[k]);
	}
}

void main()
{
	int i,sum=0,n;
	clrscr();
	/*cout<<"Enter No of elements:";
	cin>>n;
	cout<<"\nEnter  "<< n <<" elements in ascending order"<<endl;
	for (i=1;i<=n;i++)
	cin>>w[i];
	cout<<"Enter the desired sum ";
	cin>>d;*/

	///*
	n = 5;

	w[1] = 1;
	w[2] = 3;
	w[3] = 5;
	w[4] = 7;
	w[5] = 8;

	d = 8;

	//*/
	for (i=1;i<=n;i++)
	sum=sum+w[i];
	if ((sum<d) || (w[1]>d))
	cout<<"No Subset possible ";
	else
	{
		cout<<"SUBSET SOLUTION"<<endl;
		sumofsubset(0,1,sum);
		if (count==0)
		cout<<"NO SUBSET SOLUTION EXISTS"<<endl;
	}
	getch();


}
