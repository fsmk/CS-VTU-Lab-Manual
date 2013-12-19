// 12. N QUEEN PROBLEM  BY BACKTRACKING
#include <iostream.h>
#include <conio.h>
#include <iomanip.h>
#include <math.h>

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
	{
		///*
		cout << "(" <<row<<","<<col<<") rejected.\n";
		//*/
		return 0;
	}
	/*
	x[j] == i checks if the two Queens are in the same column.
	(abs(x[j]-i)==abs(j-k)) checks if the two Queens are in the same
	diagonal.
	*/


	/*
	Else eventually return 1
	*/

	///*
	cout << "(" <<row<<","<<col<<") accepted. The Queen can be placed at ";
	cout << "at this position.\n";
	//*/
	return 1;
}

void nqueen(int k,int n)
{
	cout << "\n";
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

		///*
		cout << "Trying row no : " << k << " cell no : " << i <<endl;
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
			/*
			Note that if k+1 fails, i.e. 'k+1'th row cannot be
			occupied with a queen, consequently the remaining
			rows are ignored - i.e. rest of the state space tree's
			branch is ignored. This is because the this function
			is designed in such a way that 'k+1' is checked only if
		       'k' position is a success. If 'k'th position is a failure
		       there's no function to check 'k+1' and therefore 'k+2'...
		       */
		}
	}
}

void main()
{ 
	int n;
	clrscr();
	cout<<"\n Enter no of Queens:";
	cin>>n;
	cout<<"\nSolution of "<<n<<" Queen Problem"<<endl<<endl;
	nqueen(1,n);
	cout<<" \nTotal number of Solutions="<<count;
	for (int i=1;i<=n;i++)
	if (x[i]==0)
	cout<<"\nQueens can not be placed without being attacked!  Hence no solution";
	getch();
}
