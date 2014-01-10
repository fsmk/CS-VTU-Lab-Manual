//This code is written by Abhiram at the labs of PESIT, BSC. Feel free to use it for educational purposes.

/*PROGRAM 4
Design, develop, and execute a program in C to simulate the working of a queue o
integers using an array. Provide the following operations: 
1.Insert
2.Delete
3.Display
*/

#include<stdio.h>
#include<process.h>
void add(int,int[]);                                                               
void del(int[]);                                                                       
void display(int[]);                                                                   
int q[10];
int front=-1,rear=-1;
void main()
{
    int ch,el;
    do{

   		printf("\t\tMENU:\n\t\t1.Add an element\n\t\t2.Delete an element\n\t\t3.Display Queue\n\t\tAnother to Exit\n");
   		scanf("%d",&ch);
   		switch(ch)
		{
			case 1:	printf("\nEnter the element to be added\n");
                        scanf("%d",&el);
                        add(el,q);
                        break;
			case 2: del(q);
                        break;
			case 3: display(q);
                        break;
			default:exit(0);
		}
 }while(ch);
}
void add(int a,int q[10])
{
    if(rear<10)
		q[++rear]=a;
    else
		printf("\nQueue Overflow");
}
void del(int q[10])
{

    if(front<rear)
	{
		printf("\nElement deleted is %d",q[++front]);
            q[front]=NULL;
	}
    else
		printf("\nQueue underflow");
}
void display(int q[10])
{

    int temp=front;
    printf("QUEUE: ");
    while(temp<rear)
		printf("%d ",q[++temp]);
}
