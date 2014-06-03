/********************************************************************************
*File		: BinomialCoeff.cpp
*Description	: Program to find Binomial Coefficient
*Author		: Prabodh C P
*Compiler	: gcc compiler 4.6.3, Ubuntu 12.04
*Date		: Friday 22 November 2013 
********************************************************************************/
#include <iostream>
using namespace std;

const int MAXSIZE = 10;

int fnBinomialCoefficient(int n, int k);

/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{
	int n, k;

	cout << "Binomial Coefficients\n";
	cout << "Calculates the value of nCk\n";
	cout << "Enter the value of n : ";
	cin >> n;
	cout << "Enter the value of k : ";
	cin >> k;

	if (n<k)
		cout << "\nInvalid Input n should be larger than k!\n";
	else
		cout << "\nThe value of " << n << "C" << k << " is " << fnBinomialCoefficient(n, k) << endl;

    return 0;
}
/******************************************************************************
*Function	: fnBinomialCoefficient
*Description	: Function to find Binomial Coefficient
*Input parameters:
*	int n	- no of elements
*	int k	- no of elements chosen out of n elements
*RETURNS	: value of nCk
******************************************************************************/
int fnBinomialCoefficient(int n, int k)
{
	int c[MAXSIZE][MAXSIZE];
	int i,j;

	for (i=0; i<=n; i++)
	{
		c[i][0] = 1;
		c[i][i] = 1;
	}

	for (i=1; i<=n; i++)
		for (j=1; j<i; j++)
			c[i][j] = c[i-1][j-1] + c[i-1][j];

	cout << "\nThe Binomial matrix is :" << endl << "\t";
	for (i=0; i<=n; i++)
		cout << i << "\t";
	cout << endl;

	for (i=0; i<=n+1; i++)
		cout<<"========";
	cout << endl;
	for (i=0; i<=n; i++)
	{
		cout << "i=" << i << "\t";
		for (j=0; j<=i; j++)
		{
			cout << c[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	return c[n][k];
}
/******************************************************************************
Sample 1:
Binomial Coefficients
Calculates the value of nCk
Enter the value of n : 4 
Enter the value of k : 6

Invalid Input n should be larger than k!

Sample 2:
Binomial Coefficients
Calculates the value of nCk
Enter the value of n : 6
Enter the value of k : 2

The Binomial matrix is :
	0	1	2	3	4	5	6	
================================================================
i=0	1	
i=1	1	1	
i=2	1	2	1	
i=3	1	3	3	1	
i=4	1	4	6	4	1	
i=5	1	5	10	10	5	1	
i=6	1	6	15	20	15	6	1	


The value of 6C2 is 15

******************************************************************************/

