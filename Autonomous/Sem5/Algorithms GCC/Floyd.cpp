/******************************************************************************
* File                : Floyd.cpp
* Description         : Program to illustrate Floyd's Algorithm
* Author              : Manas Jayanth (prometheansacrifice)
* Compiler            : g++ (gcc compiler 4.6.3, Ubuntu 12.04)
* Date                : 22 December 2013
******************************************************************************/
#include <iostream>
#include <iomanip>
#define MAX 10

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

void floyd(int n, int cost[MAX][MAX])
{
	int i,j,k,d[MAX][MAX]; //d Holds the shortest Distance
	// Make copy of Adjacency Matrix
	for (i = 0;i < n; i++)
	{
		for (j = 0;j < n; j++)
		d[i][j] = cost[i][j];
	}

   	cout << "Distance matrix before applying the algorithm " << endl;
	for(i = 0;i < n; i++)
	{
		for(int j = 0;j < n; j++)
		cout << setw(5) << d[i][j];
		cout << endl;
	}

	//Find Soln to all pairs shortest paths problem
	for (k = 0;k < n; k++)
	{
		for (i = 0;i < n; i++)
			for(j = 0;j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	}

	cout << "\nDistance matrix after applying the algorithm\n";
	for(i = 0;i < n; i++)
	{
		for(int j = 0;j < n; j++)
		cout << setw(5) << d[i][j];
		cout << endl;
	}
}

int main()
{
	int cost[MAX][MAX], n, i, j;
	cout << "Enter Number of nodes" << endl;
	cin >> n;
	cout << "Enter Cost Adjacency Matrix" << endl;
	for(i = 0;i < n; i++)
	{
		for (j = 0;j < n; j++)
		{
			cin >> cost[i][j];
		}
		cout << endl;
	}
	floyd(n, cost);
	return 0;
}
