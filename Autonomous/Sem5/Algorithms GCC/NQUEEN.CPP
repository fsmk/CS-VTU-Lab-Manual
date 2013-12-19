// 12. N QUEEN PROBLEM  BY BACKTRACKING
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int x[10], count=0;
/*
x[10] contains the positions of the queens already placed on the chessboard.
Eg.
Say a Queen is placed at (2,3). Then,
	x[2] = 3
*/

int place(int row,int col)
{
	for (int j=1;j<row;j++)
	/*
	This for loop checks if (row,col) clashes with any of the queens
	already placed on the chess board. x[10] keeps track of all the
	previously placed queens. Hence the positions (row,col) and (i,x[i])
	are compared.
	*/

	/*
	Note :
	Whenever place() is called, k-1 queens would already have been placed
	on the board. Hence the loop counter 'j' takes values from 1 to k-1.
	When place() is called, k is copied to row. Hence in the for loop
	j takes values from 1 to row.
	*/
	if ( x[j]==col || (abs(x[j]-col)==abs(j-row)) )
	return 0;
	/*
	x[j] == i checks if the two Queens are in the same column.
	(abs(x[j]-i)==abs(j-k)) checks if the two Queens are in the same
	diagonal.
	*/


	/*
	Else eventually return 1
	*/
	return 1;
}

void nqueen(int k,int n)
{
	/*
	k contains the current row under consideration.
	k also denotes the kth Queen being placed.
	*/
	for (int i=1;i<=n;i++)
	{
		/*
		This loop checks if a Queen can be placed in any of the
		possible cells in the kth row.
		Its tries all the cells in the row from first cell to
		nth cell
		*/

		if (place(k,i))
		{
			x[k] = i; //place the queen
			if (k==n)
			{
				count++;
				for (int j=1;j<=n;j++)
				{
					for (int k=1;k<x[j];k++)
					cout<<"X ";

					cout<<"Q " ;
					for( k=x[j]+1;k<=n;k++)

					cout<<"X ";
					cout<<endl<<endl;
				}
				cout<<endl<<endl;
			}
			else
			nqueen(k+1,n);
		}
	}
}

int main()
{
	int n;
	cout<<"\n Enter no of Queens:";
	cin>>n;
	cout<<"\nSolution of "<<n<<" Queen Problem"<<endl<<endl;
	nqueen(1,n);
	cout<<" \nTotal number of Solutions="<<count;
	for (int i=1;i<=n;i++)
	if (x[i]==0)
	cout<<"\nQueens can not be placed without being attacked !  Hence no solution";
	return 0;
}
