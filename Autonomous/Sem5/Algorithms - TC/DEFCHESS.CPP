//3.Defective Chess board Problem
#include <iostream.h>
#include <iomanip.h>
#include <conio.h>

int board[10][10],tile=1;

void tileboard(int trow,int tcol,int drow,int dcol,int size)
{
	int tile_to_use,qsize;
	if (size==1)
		return;

	tile_to_use=tile++;
	qsize=size/2;
	
	//tile first Quadrant
	if (drow<trow+qsize && dcol<tcol+qsize)
	tileboard(trow,tcol,drow,dcol,qsize);//defect in this quardrant
	else
	{
		// place tile in bottom rt corner
		board[trow+qsize-1][tcol+qsize-1]=tile_to_use;
		tileboard(trow,tcol,trow+qsize-1,tcol+qsize-1,qsize);
	}

	//tile second Quadrant
	if (drow<trow+qsize && dcol>=tcol+qsize)
		tileboard(trow,tcol+qsize,drow,dcol,qsize);//defect in this quardrant
	else
	{
		// place tile in bottom left corner
		board[trow+qsize-1][tcol+qsize]=tile_to_use;
		// tile the rest
		tileboard(trow,tcol+qsize,trow+qsize-1,tcol+qsize,qsize);
	}
	
	//tile third Quadrant
	if (drow>=trow+qsize && dcol<tcol+qsize)
		tileboard(trow+qsize,tcol,drow,dcol,qsize);//defect in this quardrant
	else
	{
		// place tile in top right corner
		board[trow+qsize][tcol+qsize-1]=tile_to_use;
		// tile the rest
		tileboard(trow+qsize,tcol,trow+qsize,tcol+qsize-1,qsize);
	}

	//tile fourth Quadrant
	if (drow>=trow+qsize && dcol>=tcol+qsize)
		tileboard(trow+qsize,tcol+qsize,drow,dcol,qsize);//defect in this quardrant
	else
	{
		// place tile in top  left corner
		board[trow+qsize][tcol+qsize]=tile_to_use;
		// tile the rest
		tileboard(trow+qsize,tcol+qsize,trow+qsize,tcol+qsize,qsize);
	}

}

void main()
{
	int n ,drow,dcol,i,j;
	clrscr();
	cout<<"Enter the value of n\n";
	cin>>n;

	cout<<"Enter the valueof defective row(0 to n-1),col(0 to n-1) \n";
	cin>>drow>>dcol;
	tileboard(0,0,drow,dcol,n);
	cout <<"Solution of Defective Chess board Problem\n";
	for(i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
		cout<<setw(3)<<board[i][j];
		}
		cout<<"\n";
	}
	getch();
}

