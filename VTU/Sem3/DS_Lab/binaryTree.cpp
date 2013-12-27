//This code is written by Abhiram at the labs of PESIT, BSC. Feel free to use it for educational purposes.

/*Design, develop, and execute a program in C++ to create a class called BIN_TREE that
represents a Binary Tree, with member functions to perform inorder, preorder and
postorder traversals. Create a BIN_TREE object and demonstrate the traversals.*/

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


void bintree::Inorder(NODE *p)
{
	if(p!=NULL)
	{
		Inorder(p->left);
		cout<<p->info<<" ";
		Inorder(p->right);
	}
}
void bintree::Preorder(NODE *p)
{
	if(p!=NULL)
	{
		cout<<p->info<<" ";
		Preorder(p->left);
		Preorder(p->right);
	}
}
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
                                cout<<"\n\n\tPreorder Traversal  :";
                                Preorder(root);
                                break;
                    case 2:
                                cout<<"\n\n\tInorder Traversal   :";
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
/*
OUTPUT:
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

        Inorder Traversal   :2 10 15 30 39 40 45 52 60
        Enter your choice: 1

        Preorder Traversal  :40 30 15 10 2 39 45 60 52
        Enter your choice: 3

        Postorder Traversal :2 10 15 39 30 52 60 45 40
        Enter your choice: 4

*/
