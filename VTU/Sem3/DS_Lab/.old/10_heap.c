/*Design, develop, and execute a program in C to create a max heap of integers by
accepting one element at a time and by inserting it immediately in to the heap. Use the
array representation for the heap. Display the array at the end of insertion phase.*/

#include <stdio.h>
#define MAX_ELEMENTS 200
#define HEAP_FULL(n)(n==MAX_ELEMENTS-1)
typedef struct{
	int key;
}element;
element heap[MAX_ELEMENTS];
void push(int, int *);
int k=0;
int main()
{
	int n,i=1,j;
	if(HEAP_FULL(k))
		printf("The heap is full.\n");
	while(i==1)
	{
		printf("Enter the element to be inserted into the heap.\n");
		scanf("%d",&n);
		push(n,&k);
		printf("Enter 1 to continue insertion or any other number to display the heap.\n");
		scanf("%d",&i);
	}
	printf("The elements of the heap are \n");
	for(j=1;j<=k;j++)
		printf("%d\t",heap[j].key);
	printf("\n");
	return 0;
}
void push(int n, int *k)
{
	int i;
	i = ++(*k);
	while((i!=1)&&(n>heap[i/2].key))
	{
		heap[i]=heap[i/2];
		i/=2;
	}
	heap[i].key=n;
}
