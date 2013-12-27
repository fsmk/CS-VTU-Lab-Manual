//This code is written by Abhiram at the labs of PESIT, BSC. Feel free to use it for educational purposes.
/*Design, develop, and execute a program in C to create a max heap of integers by
accepting one element at a time and by inserting it immediately in to the heap. Use the
array representation for the heap. Display the array at the end of insertion phase.*/

#include <stdio.h>
#include <stdlib.h>
#define max 20

void ins(int);
void heap(int);
void disp(int);
int f=0,t=1,h[max];

int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    ins(n);
    heap(n);
    disp(n);
    return 0;
}
void ins(int n)
{
    int i=0;
    for(;i<n;i++)
    {
        printf("Enter the element: ");
        scanf("%d",&h[i]);
    }
}
void disp(int n)
{
	printf("Displaying elements in heap \n \n");
    int i=0;
    for(;i<n;i++)
    {
        printf("%d ",h[i]);
    }
printf("\n\n");
}
void heap(int n)
{
    int i,v,k=0,j=0,he;
    for(i=n/2;i>=0;i--)
    {
        j=i;
        k=j-1;
        v=h[k];
        he=f;
        while(he==f && (2*k)<=n)
        {
            j=2*k+1;
            if(j<n)
            {
                if(h[j]<h[j+1])
                    j++;
            }
            if(v>=h[j])
                he=t;
            else
            {
                h[k]=h[j];
                k=j;
            }
        }
        h[k]=v;
    }
}
/*
OUTPUT:
Enter the size of array: 7
Enter the element: 10
Enter the element: 2
Enter the element: 5
Enter the element: 15
Enter the element: 30
Enter the element: 1
Enter the element: 40
40 30 10 15 2 1 5
*/
