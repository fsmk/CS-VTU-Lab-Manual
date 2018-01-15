## Program 14: bintree.cpp
## AIM: Design, develop, and execute a program in C++ to create a class called BIN_TREE that
##represents a Binary Tree, with member functions to perform inorder, preorder and
##postorder traversals. Create a BIN_TREE object and demonstrate the traversals.*/

## THEORY:
Each of the objects in a binary tree contains two pointers, typically called left and right. In addition to these pointers, of course, the nodes can contain other types of data.A node that points to another node is said to be the parent of that node, and the node it points to is called a child.

A binary tree must have the following properties: There is exactly one node in the tree which has no parent. This node is called the root of the tree. Every other node in the tree has exactly one parent. Finally, there can be no loops in a binary tree. That is, it is not possible to follow a chain of pointers starting at some node and arriving back at the same node.

A node that has no children is called a leaf. A leaf node can be recognized by the fact that both the left and right pointers in the node are NULL. 
	

Pre-order = outputting the values of a binary tree in the order of the current node, then the left subtree, then the right subtree.

Post-order = outputting the values of a binary tree in the order of the left subtree, then the right subtree, the the current node.

Pre-order:

    1. Visit the root.
    2. Traverse the left subtree.
    3. Traverse the right subtree.

In-order(symmetric):

    1. Traverse the left subtree.
    2. Visit the root.
    3. Traverse the right subtree.

Post-order:

    1.Traverse the left subtree.
    2.Traverse the right subtree.
    3.Visit the root.



## ALGORITHM:

Preorder: The first type of traversal is pre-order whose code looks like the following:

sub P(TreeNode)
   Output(TreeNode.value)
   If LeftPointer(TreeNode) != NULL Then
      P(TreeNode.LeftNode)
   If RightPointer(TreeNode) != NULL Then
      P(TreeNode.RightNode)
end sub

This can be summed up as

    1. Visit the root node (generally output this)
    2. Traverse to left subtree
    3. Traverse to right subtree

Inorder: The second(middle) type of traversal is in-order whose code looks like the following:

sub P(TreeNode)
   If LeftPointer(TreeNode) != NULL Then
      P(TreeNode.LeftNode)
   Output(TreeNode.value)
   If RightPointer(TreeNode) != NULL Then
      P(TreeNode.RightNode)
end sub

This can be summed up as

    Traverse to left subtree
    Visit root node (generally output this)
    Traverse to right subtree


Post-order: The last type of traversal is post-order whose code looks like the following:

sub P(TreeNode)
   If LeftPointer(TreeNode) != NULL Then
      P(TreeNode.LeftNode)
   If RightPointer(TreeNode) != NULL Then
      P(TreeNode.RightNode)
   Output(TreeNode.value)
end sub

This can be summed up as

    Traverse to left subtree
    Traverse to right subtree
    Visit root node (generally output this)




## CODE:bintree.cpp   
    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>

    using namespace std;

    class NODE
    {
        public:
        int info;
        class NODE *left;
        class NODE *right;
    };

    class bintree
    {
       NODE *root;
        public:
                bintree()
                {
                    root=NULL;
                }
                void Inorder(NODE* );
                void Preorder(NODE* );
                void Postorder(NODE* );
                NODE* Insert();
                void Display();
    };

     /* To traverse a non-empty binary search tree in in-order (symmetric), perform the following operations recursively at each node:
        1. Traverse the left sub-tree.
        2. Visit the root.
        3. Traverse the right sub-tree. */

 
    void bintree::Inorder(NODE *p)
    {
         if(p!=NULL)
         {
                 Inorder(p->left);
                 cout<<p->info<<" ";
                 Inorder(p->right);
         } 
    }

    /*To traverse a non-empty binary search tree in pre-order, perform the following operations recursively at each node  
     1. Visit the root.
     2. Traverse the left sub-tree.
     3. Traverse the right sub-tree. */

    void bintree::Preorder(NODE *p)
    {
         if(p!=NULL)
         {
                 cout<<p->info<<" ";
                 Preorder(p->left);
                 Preorder(p->right);
         } 
    }

    /*To traverse a non-empty binary search tree in post-order, perform the following operations recursively at each node:
     1. Traverse the left sub-tree.
     2. Traverse the right sub-tree.
     3. Visit the root. */

    void bintree::Postorder(NODE *p)
    {
         if(p!=NULL)
         {
                 Postorder(p->left);
                 Postorder(p->right);
                 cout<<p->info<<" ";
         } 
    }
    NODE* bintree::Insert()
    {

    NODE *newnode;
         newnode=(NODE *)malloc(sizeof(NODE));
         newnode->left=newnode->right=NULL;
         cout<<"\n\n\tEnter an Element to Insert: ";
         cin>>newnode->info;
         if(root==NULL)
                 root=newnode;
         else
         {
                 NODE *p,*q;
                 p=root;
                 while(p!=NULL)
                 {
                         q=p;
                         if(newnode->info>p->info)
                                 p=p->right;
                         else
                                 p=p->left;
                 } 
                 if(newnode->info>q->info)
                         q->right=newnode;
                  else
                         q->left=newnode;
            }
    }
    void bintree::Display()
    {
     int x;
     if(root==NULL)
                        cout<<"\n\n\tNo Nodes in the Tree";
         else
             {
              while(1){
              cout<<"\n\tEnter your choice:\n\t1.Preorder\n\t2.Inorder\n\t3.Postorder\n\t4.Exit: ";
              cin>>x;
              switch(x)
              {
                     case 1:
                                 cout<<"\n\n\tPreorder Traversal :";
                                 Preorder(root);
                                 break;
                     case 2:
                                 cout<<"\n\n\tInorder Traversal :";
                                 Inorder(root);
                                 break;
                     case 3:
                                 cout<<"\n\n\tPostorder Traversal :";
                                 Postorder(root);
                                 break;
                     case 4:
                                 exit(0);
                     default:cout<<"Enter proper choice:";
              }
         }
         }
    }

    int main()
    {
         int choice;
     bintree obj;

         while(1)
         {
         cout<<"\n\n\n\t1.Insert\n\t2.Display\n\t3.Exit";
                 cout<<"\n\tEnter Your Choice: ";
                 cin>>choice;
                 switch(choice)
                 {
                         case 1: obj.Insert(); break;
                         case 2: obj.Display(); break;
                         case 3: exit(0);
                         default: cout<<"\n\n\tEnter Proper Choice:";
                  }
         } 
     return 0;
    }



## OUTPUT:
##compilation command: g++ bintree.cpp
##output command : ./a.out
1.Insert
2.Display
3.Exit
Enter Your Choice: 1
Enter an Element to Insert: 40

Enter Your Choice: 1
Enter an Element to Insert: 30

Enter Your Choice: 1
Enter an Element to Insert: 15

Enter Your Choice: 1
Enter an Element to Insert: 45

Enter Your Choice: 1
Enter an Element to Insert: 60

Enter Your Choice: 1
Enter an Element to Insert: 52

Enter Your Choice: 1
Enter an Element to Insert: 39

Enter Your Choice: 1
Enter an Element to Insert: 10

Enter Your Choice: 1
Enter an Element to Insert: 2

1.Insert
2.Display
3.Exit
Enter Your Choice: 2

Enter your choice:
1.Preorder
2.Inoreder
3.Postorder
4.Exit: 2

Inorder Traversal :2 10 15 30 39 40 45 52 60
Enter your choice: 1

Preorder Traversal :40 30 15 10 2 39 45 60 52
Enter your choice: 3

Postorder Traversal :2 10 15 39 30 52 60 45 40
Enter your choice: 4


