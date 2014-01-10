/******************************************************************************
* File                : Dfs.cpp
* Description         : Check for graph connectivity using DFS  method
* Author              : Manas Jayanth (prometheansacrifice)
* Compiler            : g++ (gcc compiler 4.6.3, Ubuntu 12.04)
* Date                : 22 December 2013
******************************************************************************/
#include <iostream>
#define MAX 10

using namespace std;

int a[MAX][MAX],n,s[MAX];//a adjacency matrix and
//s is status array of node visited or not

void dfs(int u)
{
	s[u] = 1;
	for (int v = 1;v < n; v++)
	{
		if (s[v] == 0 && a[u][v] == 1)
		{
			cout << v<< "  ";
			dfs(v);
		}
	}
}


void graph_connectivity()
{
	int count = 0; //counter for total num of connected components

	for (int i = 0;i < n; i++)
	{
		if (s[i] == 0)
		{
            count++;
            cout<< "\n" <<"Connected comp " << count << " = " << i << " ";
            dfs(i);
		}
	}
	if(count > 1)
        cout << "\nGraph is not connected\n";
	else
        cout << "\nGraph is connected\n";
}


int main()
{
	cout << "Enter Number of nodes" << endl;
	cin >> n;
	cout << "Enter Adjacency Matrix"<<endl;
	for (int i = 0;i < n; i++)
	{
		for (int j = 0;j < n; j++)
		{
			cin >> a[i][j];
		}
		cout << endl;
	}
	graph_connectivity();
	return 0;
}
