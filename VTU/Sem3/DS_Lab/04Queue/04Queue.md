##PROGRAM 4 : queue.c
##Aim:
##Design, develop, and execute a program in C to simulate the working of a queue of integers using an array. Provide the following operations:
##1.Insert
##2.Delete
##3.Display

##Theory:
Queue is a perticular kind of collection in which the entities in collection are kept in order and the principal operations on the collection are the addition of the entities to the rear terminal position and removal of entities from the front terminal position. Thus queue works in First In First Out(FIFO) order.

##Algorithm:
1. Start
2. To insert an element to the queue first check if queue is full. If it is full display a message saying 'queue overflow', else insert the element from rear end of the queue.
3. To delete an element from the queue check if there are elements in queue which has to be deleted. If there is no elements in the queue print a message saying 'queue underflow', else delete the element from front end of the queue.
4. Display the contents of the queue.
5. Stop.

##Code:

    #include<stdio.h>
    #include<stdlib.h>
    
    void add(int,int[]);               //declare functions required to perform neccessary operations.
    void del(int[]);
    void display(int[]);
    int q[10];
    int front=-1,rear=-1;

    void main()
    {
     int ch,el;
    
     // provide options to select specific operation.
     do{

                   printf("\n\t\tMENU:\n\t\t1.Add an element\n\t\t2.Delete an element\n\t\t3.Display Queue\n\t\tAnother to Exit\n");
                   scanf("%d",&ch);
                   switch(ch)
                {
                        case 1:        printf("\nEnter the element to be added\n");
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

    // add fuction performs insertion of an element to the queue.

    void add(int a,int q[10])
    {
     if(rear<10)
                q[++rear]=a;
     else
                printf("\nQueue Overflow");
    }
    
    //del function performs deletion of an element from the queue.

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
    
    // display function displays the elements in the queue
    void display(int q[10])
    {

    int temp=front;
    if(front==rear)
    printf("queue is empty\n");
    else
     {
      printf("QUEUE: ");
      while(temp<rear)
                printf("%d ",q[++temp]);
     }
    }

##OUTPUT
compilation command:cc queue.c
Output command: ./a.out

		MENU:
		1.Add an element
		2.Delete an element
		3.Display Queue
		Another to Exit
1

Enter the element to be added
3

		MENU:
		1.Add an element
		2.Delete an element
		3.Display Queue
		Another to Exit
3
QUEUE: 3 
		MENU:
		1.Add an element
		2.Delete an element
		3.Display Queue
		Another to Exit
2

Element deleted is 3
		MENU:
		1.Add an element
		2.Delete an element
		3.Display Queue
		Another to Exit
3
queue is empty

		MENU:
		1.Add an element
		2.Delete an element
		3.Display Queue
		Another to Exit



