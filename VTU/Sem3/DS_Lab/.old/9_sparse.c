/*Design, develop, and execute a program in C to read a sparse matrix of integer values and 
to search the sparse matrix for an element specified by the user. Print the result of the search 
appropriately. Use the triple <row, column, value> to represent an element in the sparse 
matrix. */

#include<stdio.h>
int sparsemat[6][6];
int i,j;
typedef struct
{
	int row,col,value;
}term;
term a[100];
void main()
{
	int m,n,ele,k=0,p=0;
	printf("Enter the number of rows and columns of sparse matrix: ");
	scanf("%d%d",&m,&n);
	printf("Enter %d elements of sparsematrix\n",m*n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&sparsemat[i][j]);
			a[k].row=m;
			a[k].col=n;
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(sparsemat[i][j]!=0)
			{
				p++;
				a[k].value=p;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(sparsemat[i][j]!=0)
			{
				k++;
				a[k].row=i;
				a[k].col=j;
				a[k].value=sparsemat[i][j];
			}
		}
	}	
	printf("The triple form of sparsematrix is\nrow no  column no  value\n");
	for(k=0;k<=p;k++)
		printf("%d\t%d\t%d\n",a[k].row,a[k].col,a[k].value);
	printf("Enter the element to be searched\n");
	scanf("%d",&ele);
	for(k=1;k<=p;k++)
	{
		if(a[k].value==ele)
			printf("The element %d is found in %d row and %d column\n",a[k].value,a[k].row,a[k].col);
		else
			printf("Element not found!\n");
	}
}
