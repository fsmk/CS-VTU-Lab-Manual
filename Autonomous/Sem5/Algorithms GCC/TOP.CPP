// 8 TOPOLOGICAL SORTING
#include <iostream>

using namespace std;

class topsort
{
	private:
	int n;
	int a[10][10];
	int indegree[10];

	public:
	void read_data();
	void find_indegree();
	void topological_sort();
};

void topsort::read_data()
{
	cout<<"Enter the number of jobs\n";
	cin>>n;
	cout<<"Enter the adjacency matrix\n";

	for (int i=0; i<n; i++)
	{
		for ( int j=0; j<n; j++)
		{
			cin>>a[i][j];
		}
	}
}

void topsort::find_indegree()
{
	/*
	Indegree is nothing but the sum of all the 1's in a column
	*/
	for (int j=0;j<n;j++)
	{
		int sum=0;
		for (int i=0;i<n;i++)
		{
			sum=sum+a[i][j];
		}
		indegree[j]=sum;
	}
}

void topsort::topological_sort()
{
	/*
	Source Removal Method
	*/
	int u,v,t[10],s[10];
	find_indegree();
	int top=-1;
	int k=0;
	for (int i=0; i<n;i++)
	{
		if (indegree[i]==0)
		{
			/*
			indegree==0 => i'th node is a source.
			Hence push it in the stack.
			*/
			s[++top]=i;
		}
	}
	while (top!=-1)
	{
		u=s[top--];
		t[k++]=u;
		for (v=0;v<n;v++)
		{
		/*
		For every node v that suceeds u, reduce the indegree.
		This means its source i.e. u has been detached.
		*/
			if (a[u][v]==1)
			{
				indegree[v]--;
				if (indegree[v]==0)
				{
					/*
					If the indegree of this node is zero
					then, it is now a source and has to
					be pushed onto the stack
					*/
					s[++top]=v;
				}
			}
		}
	}
	cout<<"The topological sequence is :\n";
 	for (int i=0;i<n;i++)
	cout<<t[i]<<"   ";
}

int main()
{
	topsort t;
	t.read_data();
	t.topological_sort();
	return 0;
}

