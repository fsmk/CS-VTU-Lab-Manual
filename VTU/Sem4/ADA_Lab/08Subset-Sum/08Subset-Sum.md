#AIM:Program to solve Subset sum problem.
##Desrcription:
<b>In computer science, the subset sum problem is an important problem in complexity theory and cryptography. The problem is this: Given a set of integers, is there a non-empty subset whose sum is zero? For example, given the set {−7, −3, −2, 5, 8}, the answer is yes because the subset {−3, −2, 5} sums to zero. The problem is NP-complete.
<pre><b>Input: The number of elements.
       The Weights of each element.
       Total Required Weight.
Output:Subsets in which the sum of elements is equal to the given required weight(input).

###CODE:
<pre>#include &lt;iostream>
using namespace std;

<pre>// Constant definitions
const int MAX = 100;

// class definitions
class SubSet
{
	int stk[MAX], set[MAX];
	int size, top, count;
	public:
	SubSet()
	{
		top = -1;
		count = 0;
	}
	void getInfo(void);
	void push(int data);
	void pop(void);
	void display(void);
	int fnFindSubset(int pos, int sum);
};

/******************************************************************************
*Function	: getInfo
*Description: Function to read input
*Input parameters: no parameters
*RETURNS	: no value
******************************************************************************/

void SubSet :: getInfo(void)
{
	int i;
	cout &lt;&lt; "Enter the maximum number of elements : ";
	cin >> size;

	cout &lt;&lt; "Enter the weights of the elements : \n";
	for (i=1; i&lt;=size; i++)
		cin >> set[i];

}

/******************************************************************************
*Function	: push
*Description: Function to push an element on to the stack
*Input parameters: 
*int data	- value to be pushed on to the stack
*RETURNS	: no value
******************************************************************************/
void SubSet :: push(int data)
{
	stk[++top] = data;
}

/******************************************************************************
*Function	: pop
*Description: Function to pop an element from the stack
*Input parameters: no parameters
*RETURNS	: no value
******************************************************************************/

void SubSet :: pop(void)
{
	top--;
}

/******************************************************************************
*Function	: display
*Description: Function to display solution to sub set sum problem
*Input parameters: no parameters
*RETURNS	: no value
******************************************************************************/
void SubSet :: display()
{
	int i;
	cout &lt;&lt; "\nSOLUTION #"&lt;&lt; ++count &lt;&lt;" IS\n{ ";
	for (i=0; i&lt;=top; i++)
		cout &lt;&lt; stk[i] &lt;&lt; " ";

	cout &lt;&lt; "}" &lt;&lt; endl;
}

/******************************************************************************
*Function	: fnFindSubset
*Description	: Function to solve Subset sum problem.
*Input parameters:
*	int pos	- position
*	int sum	- sum of elements
*RETURNS	: returns 1 if solution exists or zero otherwise
******************************************************************************/
int SubSet :: fnFindSubset(int pos, int sum)
{
	int i;
	static int foundSoln = 0;

	if (sum>0)
	{
		for (i=pos; i&lt;=size; i++)
		{
			push(set[i]);
			fnFindSubset(i+1, sum - set[i]);
			pop();
		}
	}

	if (sum == 0)
	{
		display();
		foundSoln = 1;
	}

	return foundSoln;
}

/******************************************************************************
*Function	: main
*Input parameters: no parameters
*RETURNS	:	0 on success
******************************************************************************/
int main(void)
{
	int i,sum;

	SubSet set1;
	
	set1.getInfo();
	cout &lt;&lt; "Enter the total required weight : ";
	cin >> sum;

	cout &lt;&lt; endl;

	if (!set1.fnFindSubset(1, sum))
		cout &lt;&lt; "\n\nThe given problem instance doesnt have any solution." &lt;&lt; endl;
	else
		cout &lt;&lt; "\n\nThe above-mentioned sets are the required solution to the given instance." &lt;&lt; endl;

	return 0;
}

/******************************************************************************
<b>OUTPUT<\b>
SAMPLE 1

Enter the maximum number of elements : 5
Enter the weights of the elements : 
1 2 3 4 5
Enter the total required weight : 5


SOLUTION #1 IS
{ 1 4 }

SOLUTION #2 IS
{ 2 3 }

SOLUTION #3 IS
{ 5 }

The above-mentioned sets are the required solution to the given instance.

SAMPLE 2

Enter the maximum number of elements : 4
Enter the weights of the elements : 
1 2 3 4 
Enter the total required weight : 11

The given problem instance doesnt have any solution.

******************************************************************************/