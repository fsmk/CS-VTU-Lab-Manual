## Program 11 : doublelinkedlist.c
## Write a C program to support the following opearations on a doubly linked list where each node consists of integers.
##a. Create a doubly linked list by adding each node at the front.
##b. Insert a new node to the left of the node whose key value is read as an input
##c. Delete the node of a given data,if it is found,otherwise display appropriate message.
##d. Display the contents of the list.

## THEORY:
A doubly linked list is a linked data structure that consists of a set of data records, each having two special
link fields that contain references to the previous and to the next record in the sequence .It can be viewed as
two singly-linked lists formed from the same data items, in two opposi orders.
linked
opposite
A doubly-linked list whose nodes contain three fields: an integer value (data), the link to the next node (rlink),
linked
,
and the link to the previous node (llink). The two links allow walking along the list in either direction with
.
equal ease. Compared to a singly-linked list, modifying a doubly-linked list usually requires changing more
linked
linked
pointers, but is sometimes simpler because there is no need to keep track of the address of the previous node.

## ALGORITHM:

Algorithm for adding each node at the front

1. create a new node using malloc function; .it returns address of the node to temp.
2. temp->info=info;
3. temp->llink=NULL
4. temp->rlink=NULL;
5. If first=NULL then first=temp .
6. temp-.>rlink=first
7. first->llink=temp; first=temp;

Algorithm for inserting a node to the left of the node

1. Create a new node using malloc function. It returns address of the node to temp.
2. temp->info=info
3. temp->llink=NULL
4. temp->rlink=NULL
5. Get the left node key value from user
6. if first= NULL print doubly linked list is empty.
7. if lvalue=first->info, call the function insert_front
8. start from the first node and traverse the node until the key is found; store that node
address in cur
9.temp->llink=cur->llink 35
10. (temp->llink)->rlink=temp
11. cur->llink=temp;
12. temp->rlink=cur

Algorithm for delete a node

1. set temp=first
2. if first=NULL print doubly linked list is empty.
3. Get node to be deleted from the user
4. if date=first ->info then first=temp->rlink and free the temp node, then first->llink=NULL.
5. start from the first node and traverse until delete key is found; then temp=temp->rlink
6. print the deleted node
7. (temp->rlink)->llink=temp->llink
8. (temp->llink)->rlink=temp->rlink

Algorithm for display

1. set temp=first
2. if first=NULL print list is empty
3. while(temp!=NULL) print temp->info and then temp=temp->rlink


## CODE: 
    #include <stdio.h>
    #include <stdlib.h>

    struct abb
    {
        int info;
        struct abb *p, *n;
     };
    typedef struct abb *node;

    node header=NULL;

    node getnode();
    void ins();
    void insl();
    void del();
    void disp();

    int main()
    {
         int ch;
         while(1)
         {
                 printf("\nChoices:");
                 printf("\n\t1-Insert");
                 printf("\n\t2-Insert left");
                 printf("\n\t3-Delete node");
                 printf("\n\t4-Display");
                 printf("\n\t5-Exit");
                 printf("\nEnter your choice: ");
                 scanf("%d",&ch);
                 switch(ch)
                 {
                         case 1: ins();
                                 break;
                         case 2: insl();
                                 break;
                         case 3: del();
                                 break;
                         case 4: disp();
                                 break;
                         default:return 0;
                 }
         }
    }

    node getnode()
    {
         node x;
         x=(node) malloc(sizeof(struct abb));
         return x;
    }

    void ins()
    {
         node temp;
         int x;
         temp=getnode();
         printf("\nEnter the element to be inserted: ");
         scanf("%d",&x);
         temp->info=x;
         temp->p=NULL;
         temp->n=NULL;
         if(header==NULL)
                 header=temp;
         else
         {
                 temp->n=header;
                 header->p=temp;
                 header=temp;
         }
    }

    // function insl performs insertion to the left of the left of the node.
    void insl()
    {
         node temp,ele;
         int x, y;
         if(header==NULL)
         {
                 printf("\nEmpty list\n");
                 return;
         } 
         printf("\nEnter the element to be inserted: ");
         scanf("%d",&y);
         printf("\nTo left of which element should %d be inserted? Enter: ",y);
         scanf("%d",&x);
         temp=getnode();
         ele=header;
         temp->info=y;
         temp->p=NULL;
         temp->n=NULL;
         if(header->info==x)
         {
                 temp->n=header;
                 header->p=temp;
                 header=temp;
         } 
         else
         {
                 while(ele!=NULL)
                 {
                         if(ele->info==x)
                                 break;
                         ele=ele->n;
                 }
                 if(ele!=NULL)
                 {
                         temp->p=ele->p;
                         (ele->p)->n=temp;
                         temp->n=ele;
                         ele->p=temp;
                 } 
                 else
                         printf("\nNo element found");

         }
    }
    
    // del function is used to delete the node
    void del()
    {
         node temp;
         int x;
         temp=header;
         if(header==NULL)
         {
                 printf("\nNo element deleted.\n");
                 return;
         } 
         printf("Enter the node to be deleted: ");
         scanf("%d",&x);
         if(header->info==x)
         {
                 temp=header;
                 header=header->n;
                 header->p=NULL;
                 free(temp);
         } 
         else
         {
                 while(temp!=NULL)
                 {
                         if(temp->info==x)
                                 break;
                         temp=temp->n;
                 }
                 if(temp!=NULL)
                 {
                         if(temp->n!=NULL)
                         {
                                 (temp->n)->p=temp->p;
                                 (temp->p)->n=temp->n;
                                 free(temp);
                         }
                         else
                         {
                                 (temp->p)->n=NULL;
                                 free(temp);
                         } 

                 }
                 else
                 {
                         printf("Element not found");
                 }
         }
    }

    // disp fuction displays the content of the list.
    void disp()
    {
         node temp;
         if(header==NULL)
                 printf("Absent");
         else
         {
                 for(temp=header;temp!=NULL;temp=temp->n)
                         printf("%d ",temp->info);
         } 
    }

## OUTPUT:
## compilation command:cc doublelinkedlist.c
## output command: ./a.out
Choices:
1-Insert
2-Insert left
3-Delete node
4-Display
5-Exit
Enter your choice: 1

Enter the element to be inserted: 10

Enter your choice: 1

Enter the element to be inserted: 20

Enter your choice: 2

Enter the element to be inserted: 11

To left of which element should 11 be inserted? Enter: 10

Enter your choice: 2

Enter the element to be inserted: 21

To left of which element should 21 be inserted? Enter: 20

Enter your choice: 4
21 20 11 10

Enter your choice: 2

Enter the element to be inserted: 19

To left of which element should 19 be inserted? Enter: 11

Enter your choice: 4
21 20 19 11 10

Enter your choice: 3
Enter the node to be deleted: 19

Enter your choice: 3
Enter the node to be deleted: 21

Enter your choice: 3
Enter the node to be deleted: 10

Enter your choice: 4
20 11

Enter your choice: 5


