//This code is written by Abhiram at the labs of PESIT, BSC. Feel free to use it for educational purposes.


/*PROGRAM 9
Design, develop, and execute a program in C to read a sparse matrix of integer values and 
to search the sparse matrix for an element specified by the user. Print the result of the search 
appropriately. Use the triple <row, column, value> to represent an element in the sparse 
matrix. */

#include <stdio.h>
struct sparse
	{
		int row,coloumn,value;
	} sp[15];
void main()
{
	int i, j,k,l;
	int m,n,key;
	printf("Enter the no. of coloumns\n");
	scanf("%d",&n);
	printf("Enter the no. of rows\n");
	scanf("%d",&m);
	int a[m][n];
	printf("Enter the elements of the matrix\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}	
	k=0;
	for(i=0; i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]!=0)
			{	
				sp[k].row=i;
				sp[k].coloumn=j;
				sp[k].value=a[i][j];
				k++;				
			}	
			
		}
	}
	printf("Enter the key element to be searched\n");
	scanf("%d",&key);
	printf("%d\n",k);
	for(i=0;i<k;i++)
	{
		if(sp[i].value == key)
		printf("Element %d found at position\n",sp[i].value);
		printf("%d\n %d\n ",(sp[i].row+1),(sp[i].coloumn+1));
	}
}
