## Program 10: heap.c
## AIM: 
## Design, develop, and execute a program in C to create a max heap of integers by
##accepting one element at a time and by inserting it immediately in to the heap. Use the
##array representation for the heap. Display the array at the end of insertion phase.
## THEORY:
 A heap is a specialized tree-based data structure that satisfies the heap property: If A is a parent node of B then the key of node A is ordered with respect to the key of node B with the same ordering applying across the heap. Either the keys of parent nodes are always greater than or equal to those of the children and the highest key is in the root node (this kind of heap is called max heap) or the keys of parent nodes are less than or equal to those of the children and the lowest key is in the root node (min heap).

 Heaps are crucial in several efficient graph algorithms such as Dijkstra's algorithm, and in the sorting algorithm heapsort.
A min-max heap is a complete binary tree containing alternating min and max levels

Example of Min-max heap
: If it is not empty, each element has a data member called key. The root is always present at min level. Let x be any node in a min-max heap. If x is on a min (max) level then the element in x has the minimum (maximum) key from among all elements in the subtree with root x. A node on a min (max) level is called a min (max) node.

## ALGORITHM:

Max-Heapify(A, i)

// Input: A: an array where the left and right children of i root heaps (but i may not), i: an array index

// Output: A modified so that i roots a heap

//Running Time: O(log n) where n = heap-size[A] - i

1. l ← Left(i)
2. r ← Right(i)
3. if l ≤ heap-size[A] and A[l] > A[i]
4. largest ← l
5. else largest ← i
6. if r ≤ heap-size[A] and A[r] < A[largest]
7. largest ← r
8. if largest = i
9. exchange A[i] and A[largest]
10. Max-Heapify(A, largest)

Max-Heap-Insert(A, key)

//Input: A: an array representing a heap, key: a key to insert

//Output: A modified to include key

//Running Time: O(log n) where n =heap-size[A]

1 .heap-size[A] ←heap-size[A] + 1
2 .A[heap-size[A]] ← -∞
3 .Heap-Increase-Key(A[heap-size[A]], key)

## CODE: heap.c
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


    //ins function inserts the accepted input to the heap array.

    void ins(int n)
    {
     int i=0;
     for(;i<n;i++)
     {
         printf("Enter the element: ");
         scanf("%d",&h[i]);
     }
    }

    // disp funtion is used display the contents of the array after insertion.

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

    // heap fuction is used to insert the accepted input to the heap.

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

## OUTPUT:
## Compilation command : cc heap.c
## Output command: ./a.out
Enter the size of array: 7

Enter the element: 10

Enter the element: 2

Enter the element: 5

Enter the element: 15

Enter the element: 30

Enter the element: 1

Enter the element: 40

40 30 10 15 2 1 5

