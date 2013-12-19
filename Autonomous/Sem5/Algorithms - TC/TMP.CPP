#include <iostream.h>
#include <conio.h>

int x[10],w[10],count=0,d;

void sumofsubset(int cs,int k,int r)
{
	int i;
	x[k] = 1;
	cout << "cs = " << cs <<endl;
	if(cs+w[k] == d)
	{
		count++;
		cout << "Subset Soln :\n";
		cout << "{ ";
		for(i = 1; i <= k; ++i)
		{
			if(x[i] == 1)
			cout << w[i] << " ";
		}
		cout << "}\n";
	}
	else
	if(cs+w[k]+w[k+1] <= d)
	sumofsubset(cs+w[k],k+1,r-w[k]);


	if(cs+r-w[k] >=d && cs+w[k+1]<=d)
	{
		x[k] = 0;
		sumofsubset(cs,k+1,r-w[k]);
	}
}

void main()
{
	int n,sum=0;
	clrscr();
	cout << "Enter no : ";
	cin >> n;
	cout << "Enter the array : ";
	for(int i=1; i <= n; ++i)
	{
		cin >> w[i];
		sum += w[i];
	}
	cout << "Enter desired sum : ";
	cin >> d;
	if(d < w[1] || sum < d)
	cout << "Not possible\n";

	else
	{
		cout <<"Solution :\n";
		sumofsubset(0,1,sum);
		if(count == 0)
		cout << "Not possible";
	}
	getch();
}

