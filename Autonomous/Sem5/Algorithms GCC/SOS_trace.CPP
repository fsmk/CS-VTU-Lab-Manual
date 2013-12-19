#include <iostream>
#define  MAX 10

using namespace std;

int w[MAX],x[MAX],d,count=0;

void sumofsubset(int cs,int k,int r)
{
	int i;
	///*
	cout <<"Entering sumofsubset() with k = " <<k<<" element : "<< w[k] << endl;
	cout << w[k] << " temporarily added.\n";
	cout << "Currently accepted elements :\n";
	for(i=1;i<=k;i++)
	if (x[i]==1)
	cout<< w[i]<<" " ;
	cout << endl;
	//*/

	x[k]=1;// include kth element
	///*
	cout <<"Accepting new element...\n";
	cout << w[k] <<endl;
	//*/

	/*
	First we check if the new item itself leads to the solution
	*/
	if (cs+w[k]==d)
	{
		///*
		for(i = 0; i <= k; ++i)
		{
			if(x[i] == 1)
			cout << w[i] <<" ";
		}
		cout << " is equal to the desired sum d =  ";
		cout << d << endl;
		cout << "Hence solution is complete.\n Now displaying it...\n";
		//*/
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
	{       ///*
		for(i = 0; i <= k; ++i)
		{
			if(x[i] == 1)
			cout << w[i] <<" ";
		}
		cout << " is NOT equal to the desired sum d =  ";
		cout << d << endl;
		cout << "Possibly the rest of the items may add up to the ";
		cout << "desired sum.\n";
		cout << "Calling sos() with k+1...\n";
		//*/
		sumofsubset(cs+w[k],k+1,r-w[k]);
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
		///*
		cout << "Rejecting our assumption the 'k'th item.\n";
		//*/
		x[k]=0; // exclude kth element
		///*
		cout << "Calling sos() to see if rest of items ";
		cout << "can add up to the desired sum.\n";
		//*/
		sumofsubset(cs,k+1,r-w[k]);
	}
}

int main()
{
	int i,sum=0,n;
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
	return 0;
}
